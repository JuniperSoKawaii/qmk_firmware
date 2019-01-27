
#include "config.h"
#include "matrix.h"
#include "quantum.h"

#define ROWS_PER_HAND (MATRIX_ROWS / 2)

#ifdef RGBLIGHT_ENABLE
#  include "rgblight.h"
#endif

#ifdef BACKLIGHT_ENABLE
#  include "backlight.h"
extern backlight_config_t backlight_config;
#endif

#if defined(USE_I2C) || defined(EH)

#  include "i2c.h"

#  ifndef SLAVE_I2C_ADDRESS
#    define SLAVE_I2C_ADDRESS 0x32
#  endif

#  if (MATRIX_COLS > 8)
#    error "Currently only supports 8 COLS"
#  endif

// Get rows from other half over i2c
bool transport_master(matrix_row_t matrix[]) {
  int err = 0;

  // write backlight info
#  ifdef BACKLIGHT_ENABLE
  static uint8_t prev_level = ~0;
  uint8_t        level      = get_backlight_level();
  if (level != prev_level) {
    err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
    if (err) {
      goto i2c_error;
    }

    // Backlight location
    err = i2c_master_write(I2C_BACKLIT_START);
    if (err) {
      goto i2c_error;
    }

    // Write backlight
    i2c_master_write(get_backlight_level());

    prev_level = level;
  }
#  endif

  err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
  if (err) {
    goto i2c_error;
  }

  // start of matrix stored at I2C_KEYMAP_START
  err = i2c_master_write(I2C_KEYMAP_START);
  if (err) {
    goto i2c_error;
  }

  // Start read
  err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_READ);
  if (err) {
    goto i2c_error;
  }

  if (!err) {
    int i;
    for (i = 0; i < ROWS_PER_HAND - 1; ++i) {
      matrix[i] = i2c_master_read(I2C_ACK);
    }
    matrix[i] = i2c_master_read(I2C_NACK);
    i2c_master_stop();
  } else {
  i2c_error:  // the cable is disconnceted, or something else went wrong
    i2c_reset_state();
    return false;
  }

#  ifdef RGBLIGHT_ENABLE
  static uint32_t prev_rgb = ~0;
  uint32_t        rgb      = eeconfig_read_rgblight();
  if (rgb != prev_rgb) {
    err = i2c_master_start(SLAVE_I2C_ADDRESS + I2C_WRITE);
    if (err) {
      goto i2c_error;
    }

    // RGB Location
    err = i2c_master_write(I2C_RGB_START);
    if (err) {
      goto i2c_error;
    }

    uint32_t dword = eeconfig_read_rgblight();

    // Write RGB
    err = i2c_master_write_data(&dword, 4);
    if (err) {
      goto i2c_error;
    }

    prev_rgb = rgb;
    i2c_master_stop();
  }
#  endif

  return true;
}

void transport_slave(matrix_row_t matrix[]) {
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    i2c_slave_buffer[I2C_KEYMAP_START + i] = matrix[i];
  }
// Read Backlight Info
#  ifdef BACKLIGHT_ENABLE
  backlight_set(i2c_slave_buffer[I2C_BACKLIT_START]);
#  endif
#  ifdef RGBLIGHT_ENABLE
  // Disable interupts (RGB data is big)
  cli();
  // Create new DWORD for RGB data
  uint32_t dword;

  // Fill the new DWORD with the data that was sent over
  uint8_t *dword_dat = (uint8_t *)(&dword);
  for (int i = 0; i < 4; i++) {
    dword_dat[i] = i2c_slave_buffer[I2C_RGB_START + i];
  }

  // Update the RGB now with the new data
  rgblight_update_dword(dword);
  // Re-enable interupts now that RGB is set
  sei();
}
#  endif
}

void transport_master_init(void) { i2c_master_init(); }

void transport_slave_init(void) { i2c_slave_init(SLAVE_I2C_ADDRESS); }

#else  // USE_SERIAL

#  include "serial.h"

typedef struct _Serial_s2m_buffer_t {
  // TODO: if MATRIX_COLS > 8 change to uint8_t packed_matrix[] for pack/unpack
  matrix_row_t smatrix[ROWS_PER_HAND];
} Serial_s2m_buffer_t;

typedef struct _Serial_m2s_buffer_t {
#  ifdef BACKLIGHT_ENABLE
  uint8_t           backlight_level;
#  endif
#  if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
  rgblight_config_t rgblight_config;  // not yet use
  //
  // When MCUs on both sides drive their respective RGB LED chains,
  // it is necessary to synchronize, so it is necessary to communicate RGB
  // information. In that case, define the RGBLIGHT_SPLIT macro.
  //
  // Otherwise, if the master side MCU drives both sides RGB LED chains,
  // there is no need to communicate.
#  endif
} Serial_m2s_buffer_t;

volatile Serial_s2m_buffer_t serial_s2m_buffer = {};
volatile Serial_m2s_buffer_t serial_m2s_buffer = {};
uint8_t volatile status0                       = 0;

SSTD_t transactions[] = {
    {
        (uint8_t *)&status0,
        sizeof(serial_m2s_buffer),
        (uint8_t *)&serial_m2s_buffer,
        sizeof(serial_s2m_buffer),
        (uint8_t *)&serial_s2m_buffer,
    },
};

void transport_master_init(void) { soft_serial_initiator_init(transactions, TID_LIMIT(transactions)); }

void transport_slave_init(void) { soft_serial_target_init(transactions, TID_LIMIT(transactions)); }

bool transport_master(matrix_row_t matrix[]) {
  if (soft_serial_transaction()) {
    return false;
  }

  // TODO:  if MATRIX_COLS > 8 change to unpack()
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    matrix[i] = serial_s2m_buffer.smatrix[i];
  }

#  if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
  // Code to send RGB over serial goes here (not implemented yet)
#  endif

#  ifdef BACKLIGHT_ENABLE
  // Write backlight level for slave to read
  serial_m2s_buffer.backlight_level = backlight_config.enable ? backlight_config.level : 0;
#  endif

  return true;
}

void transport_slave(matrix_row_t matrix[]) {
  // TODO: if MATRIX_COLS > 8 change to pack()
  for (int i = 0; i < ROWS_PER_HAND; ++i) {
    serial_s2m_buffer.smatrix[i] = matrix[i];
  }
#  ifdef BACKLIGHT_ENABLE
  backlight_set(serial_m2s_buffer.backlight_level);
#  endif
#  if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SPLIT)
// Add serial implementation for RGB here
#  endif
}

#endif
