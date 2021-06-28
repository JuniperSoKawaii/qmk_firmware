/*
Copyright 2021 Shiftux <shiftux@gmail.com>

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

#include QMK_KEYBOARD_H

enum layers {
    _QWERTZ, // standard layer
    _SYMB,   // symbols layer
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
};

enum custom_keycodes {
  QWERTZ = SAFE_RANGE,
  SYMB,
};

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
#define SYM_L   MO(_SYMB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTZ] = LAYOUT(
  //                               ┌────────┐                                                            ┌────────┬────────┐
                                    KC_MUTE,                                                              KC_MPLY, KC_MNXT,
  //┌────────┬────────┬────────┬───┼────┬───┼────┬────────┐                                           ┌──┼─────┬──┼─────┬──┼─────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5,                                                 KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_NUBS,                            KC_MINS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_EQL,                            KC_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_PGDN,  KC_PGUP,        KC_HOME, KC_END,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  SYM_L,   KC_LALT, KC_GRV,      KC_DEL,     KC_LGUI,   KC_SPC,         KC_ENT,   KC_SPC,     KC_RALT,       KC_LEFT,  KC_UP,  KC_DOWN,  KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),


  [_SYMB] = LAYOUT(
   //                              ┌────────┐                                                            ┌────────┬────────┐
                                    KC_MPRV,                                                              XXXXXXX, XXXXXXX,
  //┌────────┬────────┬────────┬───┼────┬───┼────┬────────┐                                           ┌──┼─────┬──┼─────┬──┼─────┬────────┬────────┬────────┐
     RESET    ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5,                                               KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F12 ,                           XXXXXXX ,XXXXXXX ,XXXXXXX, KC_UP ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_BSLS  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX,        XXXXXXX ,XXXXXXX ,KC_TILD ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) { /* First encoder */
      if (clockwise) {
         tap_code(KC_VOLD);
      } else {
         tap_code(KC_VOLU);
      }
   } else if (index == 1) { /* Second encoder */
      if (clockwise) {
         tap_code(KC_WH_D);
      } else {
         tap_code(KC_WH_U);
      }
   }
   return false;
}
