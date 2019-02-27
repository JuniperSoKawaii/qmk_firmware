/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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
#include QMK_KEYBOARD_H
#include "LUFA/Drivers/Peripheral/TWI.h"
#include "i2c_master.h"
#ifdef OLED_ENABLE
  #include "ssd1306.h"
#endif


//Layers

enum {
  BASE = 0,
  FUNCTION,
};

bool screenWorks = 0;

//13 characters max without re-writing the "Layer: " format in oled_task_user()
static char layer_lookup[][14] = {"Base","Function"};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap BASE: (Base Layer) Default Layer
   *
   * ,-----------------------------------------------------------. .-------------------.
   * | ~ | 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |NumL| /  | *  | -  |
   * |-----------------------------------------------------------| |-------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | | 7  | 8  | 9  |    |
   * |-----------------------------------------------------------| |--------------| +  |
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | | 4  | 5  | 6  |    |
   * |-----------------------------------------------------------| |-------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     | | 1  | 2  | 3  | Ent|
   * |-----------------------------------------------------------| |--------------|    |
   * |Ctrl|Gui |Alt |      Space           | Alt | Win |FN  |Ctr | |   0     | .  |    |
   * `-----------------------------------------------------------' '-------------------'
   */
  [BASE] = LAYOUT_all(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,          KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                        KC_RALT, KC_RWIN, MO(FUNCTION), KC_RCTL,                   KC_P0,   XXXXXXX, KC_PDOT, KC_PENT  \
  ),
  /* Keymap FUNCTION: (Function Layer)
   *
   * ,-----------------------------------------------------------. .-------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | RESET | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |        |Tog|Mod|Hu+|Hu-|Sa+|Sa-|Va+|Va-|Stp|   |          | |    |    |    |    |
   * |-----------------------------------------------------------| |--------------|    |
   * |    |    |    |                      |     |     |    |    | |         |    |    |
   * `-----------------------------------------------------------' '-------------------'
   */
  [FUNCTION] = LAYOUT_all(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   XXXXXXX, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_STEP, _______, _______, XXXXXXX,          _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   _______,                        _______, _______, MO(FUNCTION), _______,                  _______, XXXXXXX, _______, _______  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

void matrix_init_user(void) {
  #ifdef USE_I2C
    i2c_init();
    #ifdef OLED_ENABLE
      // calls code for the SSD1306 OLED
      _delay_ms(400);
      TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
      if ( oled_init(false) ) { // turns on the display
        screenWorks = 1;
      }
    #endif
  #endif
  #ifdef AUDIO_ENABLE
    startup_user();
  #endif
}

void matrix_scan_user(void) {
  #ifdef OLED_ENABLE
    if ( screenWorks ) {
      oled_task();  // this is what updates the display continuously
    };
  #endif
}

void oled_task_user(void) {
  oled_write_P(PSTR("TKC M0LLY"), false);

  uint8_t layer = biton32(layer_state);

  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%d", layer);
  oled_write_P(PSTR("\nLayer: "), false);
  oled_write(layer_lookup[layer], false);

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  oled_write(led, false);
}
