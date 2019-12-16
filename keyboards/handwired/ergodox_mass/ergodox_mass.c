/* Copyright 2018 Andrew Mass
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "ergodox_mass.h"

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  { {7,7},  {6,7},  {5,7},  {4,7},  {3,7},  {2,7},  {1,7},  {0,7} },
  { {7,6},  {6,6},  {5,6},  {4,6},  {3,6},  {2,6},  {1,6},  {0,6} },
  { {7,9},  {6,9},  {5,9},  {4,9},  {3,9},  {2,9},  {1,9},  {0,9} },
  { {7,8},  {6,8},  {5,8},  {4,8},  {3,8},  {2,8},  {1,8},  {0,8} },
  { {7,11}, {6,11}, {5,11}, {4,11}, {3,11}, {2,11}, {1,11}, {0,11} },
  { {7,10}, {6,10}, {5,10}, {4,10}, {3,10}, {2,10}, {1,10}, {0,10} },

  { {7,1},  {6,1},  {5,1},  {4,1},  {3,1},  {2,1},  {1,1},  {0,1} },
  { {7,0},  {6,0},  {5,0},  {4,0},  {3,0},  {2,0},  {1,0},  {0,0} },
  { {7,3},  {6,3},  {5,3},  {4,3},  {3,3},  {2,3},  {1,3},  {0,3} },
  { {7,2},  {6,2},  {5,2},  {4,2},  {3,2},  {2,2},  {1,2},  {0,2} },
  { {7,5},  {6,5},  {5,5},  {4,5},  {3,5},  {2,5},  {1,5},  {0,5} },
  { {7,4},  {6,4},  {5,4},  {4,4},  {3,4},  {2,4},  {1,4},  {0,4} },
};

// Pin index in PORTF for each of the LEDs
uint8_t LED_MASK[5] = { (1<<0), (1<<1), (1<<4), (1<<5), (1<<6) };

uint32_t scanCount = 0;

/**
 * Custom LED functions
 */

void mass_led_on(uint8_t idx) {
  if (idx >= 5)
    return;
  PORTF |= LED_MASK[idx];
}

void mass_led_off(uint8_t idx) {
  if (idx >= 5)
    return;
  PORTF &= ~LED_MASK[idx];
}

void mass_led_toggle(uint8_t idx) {
  if (idx >= 5)
    return;
  PORTF ^= LED_MASK[idx];
}

/**
 * QMK keyboard callback functions
 */

layer_state_t layer_state_set_kb(layer_state_t state) {
  //uprintf("LAYER %d\n", state);

  // Set layer LEDs based on new layer state
  for (uint8_t i = 0; i <= 2; ++i)
    mass_led_off(i);
  uint8_t bit = biton32(state);
  if (bit <= 2)
    mass_led_on(bit);

  return layer_state_set_user(state);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed)
    mass_led_on(3);
  else
    mass_led_off(3);

  //uprintf("RECORD %u\n", keycode);
  return process_record_user(keycode, record);
}

void matrix_init_kb(void) {
  // Set all LEDs as outputs & initialize them to off
  for (uint8_t i = 0; i <= 4; ++i) {
    DDRF |= LED_MASK[i];
    mass_led_off(i);
  }

  // Set layer LEDs based on default layer state
  layer_state_set_kb(layer_state);
  default_layer_state_set_kb(default_layer_state);

  matrix_init_user();
}

void matrix_scan_kb(void) {
  ++scanCount;

  // Blink LED4
  if (scanCount % 1000 == 0)
    mass_led_toggle(4);

  matrix_scan_user();
}
