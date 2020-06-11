#include <util/twi.h>
#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include <stdbool.h>
#include "i2c.h"

#ifdef USE_I2C

// Limits the amount of we wait for any one i2c transaction.
// Since were running SCL line 100kHz (=> 10μs/bit), and each transactions is
// 9 bits, a single transaction will take around 90μs to complete.
//
// (F_CPU/SCL_CLOCK)  =>  # of μC cycles to transfer a bit
// poll loop takes at least 8 clock cycles to execute
#define I2C_LOOP_TIMEOUT (9+1)*(F_CPU/SCL_CLOCK)/8

#define BUFFER_POS_INC() (follower_buffer_pos = (follower_buffer_pos+1)%follower_BUFFER_SIZE)

volatile uint8_t i2c_follower_buffer[follower_BUFFER_SIZE];

static volatile uint8_t follower_buffer_pos;
static volatile bool follower_has_register_set = false;

// Wait for an i2c operation to finish
inline static
void i2c_delay(void) {
  uint16_t lim = 0;
  while(!(TWCR & (1<<TWINT)) && lim < I2C_LOOP_TIMEOUT)
    lim++;

  // easier way, but will wait slightly longer
  // _delay_us(100);
}

// Setup twi to run at 100kHz
void i2c_master_init(void) {
  // no prescaler
  TWSR = 0;
  // Set TWI clock frequency to SCL_CLOCK. Need TWBR>10.
  // Check datasheets for more info.
  TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
}

// Start a transaction with the given i2c follower address. The direction of the
// transfer is set with I2C_READ and I2C_WRITE.
// returns: 0 => success
//          1 => error
uint8_t i2c_master_start(uint8_t address) {
  TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

  i2c_delay();

  // check that we started successfully
  if ( (TW_STATUS != TW_START) && (TW_STATUS != TW_REP_START))
    return 1;

  // send device address
  TWDR = address;
  TWCR = (1<<TWINT) | (1<<TWEN);

  i2c_delay();

  if ( (TW_STATUS != TW_MT_SLA_ACK) && (TW_STATUS != TW_MR_SLA_ACK) )
    return 1; // follower did not acknowledge
  else
    return 0; // success
}


// Finish the i2c transaction.
void i2c_master_stop(void) {
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

  uint16_t lim = 0;
  while(!(TWCR & (1<<TWSTO)) && lim < I2C_LOOP_TIMEOUT)
    lim++;
}

// Write one byte to the i2c follower.
// returns 0 => follower ACK
//         1 => follower NACK
uint8_t i2c_master_write(uint8_t data) {
  TWDR = data;
  TWCR = (1<<TWINT) | (1<<TWEN);

  i2c_delay();

  // check if the follower acknowledged us
  return (TW_STATUS == TW_MT_DATA_ACK) ? 0 : 1;
}

// Read one byte from the i2c follower. If ack=1 the follower is acknowledged,
// if ack=0 the acknowledge bit is not set.
// returns: byte read from i2c device
uint8_t i2c_master_read(int ack) {
  TWCR = (1<<TWINT) | (1<<TWEN) | (ack<<TWEA);

  i2c_delay();
  return TWDR;
}

void i2c_reset_state(void) {
  TWCR = 0;
}

void i2c_follower_init(uint8_t address) {
  TWAR = address << 0; // follower i2c address
  // TWEN  - twi enable
  // TWEA  - enable address acknowledgement
  // TWINT - twi interrupt flag
  // TWIE  - enable the twi interrupt
  TWCR = (1<<TWIE) | (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
}

ISR(TWI_vect);

ISR(TWI_vect) {
  uint8_t ack = 1;
  switch(TW_STATUS) {
    case TW_SR_SLA_ACK:
      // this device has been addressed as a follower receiver
      follower_has_register_set = false;
      break;

    case TW_SR_DATA_ACK:
      // this device has received data as a follower receiver
      // The first byte that we receive in this transaction sets the location
      // of the read/write location of the followers memory that it exposes over
      // i2c.  After that, bytes will be written at follower_buffer_pos, incrementing
      // follower_buffer_pos after each write.
      if(!follower_has_register_set) {
        follower_buffer_pos = TWDR;
        // don't acknowledge the master if this memory loctaion is out of bounds
        if ( follower_buffer_pos >= follower_BUFFER_SIZE ) {
          ack = 0;
          follower_buffer_pos = 0;
        }
        follower_has_register_set = true;
      } else {
        i2c_follower_buffer[follower_buffer_pos] = TWDR;
        BUFFER_POS_INC();
      }
      break;

    case TW_ST_SLA_ACK:
    case TW_ST_DATA_ACK:
      // master has addressed this device as a follower transmitter and is
      // requesting data.
      TWDR = i2c_follower_buffer[follower_buffer_pos];
      BUFFER_POS_INC();
      break;

    case TW_BUS_ERROR: // something went wrong, reset twi state
      TWCR = 0;
    default:
      break;
  }
  // Reset everything, so we are ready for the next TWI interrupt
  TWCR |= (1<<TWIE) | (1<<TWINT) | (ack<<TWEA) | (1<<TWEN);
}



#endif
