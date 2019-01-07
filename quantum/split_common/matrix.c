/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "split_util.h"
#include "config.h"
#include "timer.h"
#include "split_flags.h"
#include "quantum.h"

#ifdef BACKLIGHT_ENABLE
# include "backlight.h"
  extern backlight_config_t backlight_config;
#endif

#if defined(USE_I2C) || defined(EH)
#  include "i2c.h"
#  define SLAVE_I2C_ADDRESS           0x32
#else // USE_SERIAL
#  include "serial.h"
#endif

#ifndef DEBOUNCING_DELAY
#  define DEBOUNCING_DELAY 5
#endif

#if (DEBOUNCING_DELAY > 0)
  static uint16_t debouncing_time;
  static bool debouncing = false;
#endif

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop32(matrix[i])
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

#define ERROR_DISCONNECT_COUNT 5

#define ROWS_PER_HAND (MATRIX_ROWS/2)

static uint8_t error_count = 0;

#ifdef DIRECT_PINS
static pin_t direct_pins[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;
#else
static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t raw_matrix[ROWS_PER_HAND];

// row offsets for each hand
uint8_t thisHand, thatHand;

#ifdef DIRECT_PINS

static void init_pins(void)
{
  for(int row = 0; row < MATRIX_ROWS; row++) {
    for(int col = 0; col < MATRIX_COLS; col++) {
      pin_t pin = direct_pins[row][col];
      if(pin != NO_PIN) {
        setPinInputHigh(pin);
      }
    }
  }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row)
{
  matrix_row_t last_row_value = current_matrix[current_row];
  current_matrix[current_row] = 0;

  for(uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
    pin_t pin = direct_pins[current_row][col_index];
    if(pin != NO_PIN) {
      current_matrix[current_row] |= readPin(pin) ? 0 : (ROW_SHIFTER << col_index);
    }
  }

  return (last_row_value != current_matrix[current_row]);
}

#elif (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row)
{
  writePinLow(row_pins[row]);
  setPinOutput(row_pins[row]);
}

static void unselect_row(uint8_t row)
{
  setPinInputHigh(row_pins[row]);
}

static void unselect_rows(void)
{
  for(uint8_t x = 0; x < ROWS_PER_HAND; x++) {
    setPinInputHigh(row_pins[x]);
  }
}

static void init_pins(void)
{
  unselect_rows();
  for(uint8_t x = 0; x < MATRIX_COLS; x++) {
    setPinInputHigh(col_pins[x]);
  }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row)
{
  // Store last value of row prior to reading
  matrix_row_t last_row_value = current_matrix[current_row];

  // Clear data in matrix row
  current_matrix[current_row] = 0;

  // Select row and wait for row selecton to stabilize
  select_row(current_row);
  wait_us(30);

  // For each col...
  for(uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
    // Populate the matrix row with the state of the col pin
    current_matrix[current_row] |=  readPin(col_pins[col_index]) ? 0 : (ROW_SHIFTER << col_index);
  }

  // Unselect row
  unselect_row(current_row);

  return (last_row_value != current_matrix[current_row]);
}

#elif (DIODE_DIRECTION == ROW2COL)

static void init_pins(void)
{
  unselect_cols();
  for(uint8_t x = 0; x < ROWS_PER_HAND; x++) {
    setPinInputHigh(row_pins[x]);
  }
}

static void select_col(uint8_t col)
{
  writePinLow(col_pins[col]);
  setPinOutput(col_pins[col]);
}

static void unselect_col(uint8_t col)
{
  setPinInputHigh(col_pins[col]);
}

static void unselect_cols(void)
{
  for(uint8_t x = 0; x < MATRIX_COLS; x++) {
    setPinInputHigh(col_pins[x]);
  }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col)
{
  bool matrix_changed = false;

  // Select col and wait for col selecton to stabilize
  select_col(current_col);
  wait_us(30);

  // For each row...
  for(uint8_t row_index = 0; row_index < ROWS_PER_HAND; row_index++)
  {

    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[row_index];

    // Check row pin state
    if (readPin(row_pins[row_index]))
    {
      // Pin HI, clear col bit
      current_matrix[row_index] &= ~(ROW_SHIFTER << current_col);
    }
    else
    {
      // Pin LO, set col bit
      current_matrix[row_index] |= (ROW_SHIFTER << current_col);
    }

    // Determine if the matrix changed state
    if ((last_row_value != current_matrix[row_index]) && !(matrix_changed))
    {
      matrix_changed = true;
    }
  }

  // Unselect col
  unselect_col(current_col);

  return matrix_changed;
}

#endif

inline
uint8_t matrix_rows(void)
{
  return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
  return MATRIX_COLS;
}

void matrix_init(void)
{
  debug_enable = true;
  debug_matrix = true;
  debug_mouse = true;

  // Set pinout for right half if pinout for that half is defined
  if (!isLeftHand) {
#ifdef MATRIX_ROW_PINS_RIGHT
    const uint8_t row_pins_right[MATRIX_ROWS] = MATRIX_ROW_PINS_RIGHT;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
      row_pins[i] = row_pins_right[i];
    }
#endif
#ifdef MATRIX_COL_PINS_RIGHT
    const uint8_t col_pins_right[MATRIX_COLS] = MATRIX_COL_PINS_RIGHT;
    for (uint8_t i = 0; i < MATRIX_COLS; i++) {
      col_pins[i] = col_pins_right[i];
    }
#endif
  }

  thisHand = isLeftHand ? 0 : (ROWS_PER_HAND);
  thatHand = ROWS_PER_HAND - thisHand;

  // initialize key pins
  init_pins();

  // initialize matrix state: all keys off
  for (uint8_t i=0; i < MATRIX_ROWS; i++) {
    matrix[i] = 0;
  }

  matrix_init_quantum();
}

uint8_t _matrix_scan(void)
{
#if defined(DIRECT_PINS) || (DIODE_DIRECTION == COL2ROW)
  // Set row, read cols
  for (uint8_t current_row = 0; current_row < ROWS_PER_HAND; current_row++) {
#if (DEBOUNCING_DELAY > 0)
    bool matrix_changed = read_cols_on_row(raw_matrix, current_row);

    if (matrix_changed) {
      debouncing = true;
      debouncing_time = timer_read();
    }
#else
    read_cols_on_row(matrix+thisHand, current_row);
#endif
  }

#elif (DIODE_DIRECTION == ROW2COL)
  // Set col, read rows
  for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
#if (DEBOUNCING_DELAY > 0)
    bool matrix_changed = read_rows_on_col(raw_matrix, current_col);
    if (matrix_changed) {
        debouncing = true;
        debouncing_time = timer_read();
    }
#else
    read_rows_on_col(matrix+thisHand, current_col);
#endif
  }
#endif

#if (DEBOUNCING_DELAY > 0)
  if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCING_DELAY)) {
    for (uint8_t i = 0; i < ROWS_PER_HAND; i++) {
      matrix[thisHand+i] = raw_matrix[i];
    }
    debouncing = false;
  }
#endif

  return 1;
}

#if defined(USE_I2C) || defined(EH)

#if (MATRIX_COLS > 8)
#  error "Currently only supports 8 COLS"
#endif

// Get rows from other half over i2c
bool do_transaction(void) {
  int err = 0;

  // write backlight info
#ifdef BACKLIGHT_ENABLE
  if (BACKLIT_DIRTY) {
    err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
    if (err) { goto i2c_error; }

    // Backlight location
    err = i2c_master_write(I2C_BACKLIT_START);
    if (err) { goto i2c_error; }

    // Write backlight
    i2c_master_write(get_backlight_level());

    BACKLIT_DIRTY = false;
  }
#endif

  err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
  if (err) { goto i2c_error; }

  // start of matrix stored at I2C_KEYMAP_START
  err = i2c_master_write(I2C_KEYMAP_START);
  if (err) { goto i2c_error; }

  // Start read
  err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_READ);
  if (err) { goto i2c_error; }

  if (!err) {
    int i;
    for (i = 0; i < ROWS_PER_HAND-1; ++i) {
      matrix[thatHand+i] = i2c_master_read(I2C_ACK);
    }
    matrix[thatHand+i] = i2c_master_read(I2C_NACK);
    i2c_master_stop();
  } else {
i2c_error: // the cable is disconnceted, or something else went wrong
    i2c_reset_state();
    return false;
  }

#ifdef RGBLIGHT_ENABLE
  if (RGB_DIRTY) {
    err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
    if (err) { goto i2c_error; }

    // RGB Location
    err = i2c_master_write(I2C_RGB_START);
    if (err) { goto i2c_error; }

    uint32_t dword = eeconfig_read_rgblight();

    // Write RGB
    err = i2c_master_write_data(&dword, 4);
    if (err) { goto i2c_error; }

    RGB_DIRTY = false;
    i2c_master_stop();
  }
#endif

  return true;
}

void transport_master_init(void) {
  i2c_master_init();
}

void transport_slave_init(void) {
  i2c_slave_init(SLAVE_I2C_ADDRESS);
}

#else // USE_SERIAL

typedef struct _Serial_s2m_buffer_t {
  // TODO: if MATRIX_COLS > 8 change to uint8_t packed_matrix[] for pack/unpack
  matrix_row_t smatrix[ROWS_PER_HAND];
} Serial_s2m_buffer_t;

volatile Serial_s2m_buffer_t serial_s2m_buffer = {};
volatile Serial_m2s_buffer_t serial_m2s_buffer = {};
uint8_t volatile status0 = 0;

SSTD_t transactions[] = {
  { (uint8_t *)&status0,
    sizeof(serial_m2s_buffer), (uint8_t *)&serial_m2s_buffer,
    sizeof(serial_s2m_buffer), (uint8_t *)&serial_s2m_buffer
  }
};

void transport_master_init(void)
{ soft_serial_initiator_init(transactions, TID_LIMIT(transactions)); }

void transport_slave_init(void)
{ soft_serial_target_init(transactions, TID_LIMIT(transactions)); }

bool do_transaction(void) {

  if (soft_serial_transaction()) {
    return false;
  }

  // TODO:  if MATRIX_COLS > 8 change to unpack()
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    matrix[thatHand+i] = serial_s2m_buffer.smatrix[i];
  }

  #if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
    // Code to send RGB over serial goes here (not implemented yet)
  #endif

  #ifdef BACKLIGHT_ENABLE
    // Write backlight level for slave to read
    serial_m2s_buffer.backlight_level = backlight_config.enable ? backlight_config.level : 0;
  #endif

  return true;
}
#endif

static void master_transport(void)
{
  if (!do_transaction()) {
    error_count++;

    if (error_count > ERROR_DISCONNECT_COUNT)
    {
      // reset other half if disconnected
      for (int i = 0; i < ROWS_PER_HAND; ++i)
      {
        matrix[thatHand + i] = 0;
      }
    }
  }
  else
  {
    error_count = 0;
  }
}

static void slave_transport(void) {

#if defined(USE_I2C) || defined(EH)
  for (int i = 0; i < ROWS_PER_HAND; ++i)
  {
    i2c_slave_buffer[I2C_KEYMAP_START + i] = matrix[thisHand + i];
  }
  // Read Backlight Info
  #ifdef BACKLIGHT_ENABLE
  if (BACKLIT_DIRTY)
  {
    backlight_set(i2c_slave_buffer[I2C_BACKLIT_START]);
    BACKLIT_DIRTY = false;
  }
  #endif
  #ifdef RGBLIGHT_ENABLE
  if (RGB_DIRTY)
  {
    // Disable interupts (RGB data is big)
    cli();
    // Create new DWORD for RGB data
    uint32_t dword;

    // Fill the new DWORD with the data that was sent over
    uint8_t * dword_dat = (uint8_t *)(&dword);
    for (int i = 0; i < 4; i++)
    {
      dword_dat[i] = i2c_slave_buffer[I2C_RGB_START + i];
    }

    // Update the RGB now with the new data and set RGB_DIRTY to false
    rgblight_update_dword(dword);
    RGB_DIRTY = false;
    // Re-enable interupts now that RGB is set
    sei();
  }
  #endif

#else  // USE_SERIAL
  // TODO: if MATRIX_COLS > 8 change to pack()
  for (int i = 0; i < ROWS_PER_HAND; ++i)
  {
    serial_s2m_buffer.smatrix[i] = matrix[thisHand + i];
  }
  #ifdef BACKLIGHT_ENABLE
    backlight_set(serial_m2s_buffer.backlight_level);
  #endif
  #if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
  // Add serial implementation for RGB here
  #endif
#endif
}

uint8_t matrix_scan(void)
{
  uint8_t ret = _matrix_scan();

  if (is_keyboard_master())
  {
    master_transport();
    matrix_scan_quantum();
  }
  else
  {
    slave_transport();
    matrix_slave_scan_user();
  }

  return ret;
}

bool matrix_is_modified(void)
{
  if (debouncing) return false;
  return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
  return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
  return matrix[row];
}

void matrix_print(void)
{
  print("\nr/c 0123456789ABCDEF\n");
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    phex(row); print(": ");
    pbin_reverse16(matrix_get_row(row));
    print("\n");
  }
}

uint8_t matrix_key_count(void)
{
  uint8_t count = 0;
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    count += bitpop16(matrix[i]);
  }
  return count;
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

__attribute__ ((weak))
void matrix_slave_scan_user(void) {
}
