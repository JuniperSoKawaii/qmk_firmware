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

#include QMK_KEYBOARD_H

enum layers {
_QWERTY=0,
_CDH,
_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
      1,    2,    3,    4,    5,    6,    7,    8,    9,    0,   MINS, EQL, BACK,       APP0,
    TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,   P,    LBRC,  RBRC, BSLS,  APP1,  
    CAPS, A,    S,    D,    F,    G,    H,    J,    K,    L,   SCLN, QUOT,  ENT,         APP2,  
    LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT, SLSH, RSFT,  UP,          APP3, 
    LCTL, FN,   LALT, CMD,  SPACE,SPACE,GRAVE,DONE, DEL, LEFT, DOWN, RIGHT     

*/
  [_QWERTY] = LAYOUT( /* Base */
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC,           KC_ESC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  TG(_CDH),  
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,            KC_PGUP,  
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,             KC_PGDN, 
      KC_LCTL, MO(_FN),   KC_LALT, KC_LGUI, KC_SPACE,KC_SPACE,KC_GRAVE,KC_RGUI, KC_DEL,  KC_LEFT,KC_DOWN, KC_RIGHT  
      ),

  [_CDH] = LAYOUT( /* Base */
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC,           KC_ESC,
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,  _______,  
      KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT, KC_ENT,            KC_PGUP,  
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,             KC_PGDN, 
      KC_LCTL, MO(_FN), KC_LALT, KC_LGUI, KC_SPACE,KC_SPACE,KC_GRAVE,KC_RGUI, KC_DEL,  KC_LEFT,KC_DOWN, KC_RIGHT  
      ),

  [_FN] = LAYOUT( // FN Key 
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,    
      _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______, _______, _______     
      ),

};
