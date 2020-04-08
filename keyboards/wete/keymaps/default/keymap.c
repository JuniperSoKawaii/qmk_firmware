/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi_rhnp(
    KC_INSERT, KC_PSCREEN, KC_PAUSE, KC_SLCK,               KC_ESC,     KC_F1, KC_F2, KC_F3, KC_F4,     KC_F5, KC_F6, KC_F7, KC_F8,     KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,
    KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,   KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,       KC_BSPC,         KC_HOME,
    KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,                  KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,      KC_BSLS,      KC_END,
    KC_KP_4, KC_KP_5, KC_KP_6,                              KC_CAPS,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,           KC_ENTER,     KC_PGUP,
    KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,                 KC_LSFT,       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,   KC_UP,    KC_PGDN,
          KC_KP_0,    KC_KP_DOT,                            KC_LCTL,  KC_LGUI,  KC_LALT,                KC_SPC,            KC_RALT, MO(1),          KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [1] = LAYOUT_ansi_rhnp(
      KC_NO, KC_NO, KC_NO, KC_NO,   BL_TOGG, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,   KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
      KC_NO, KC_NO, KC_NO,          KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,     KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,     BL_INC, KC_NO,
         KC_NO,     KC_NO,          KC_NO,  KC_NO,  KC_NO,                      KC_NO,                     KC_NO, KC_TRNS,      BL_OFF, BL_DEC, BL_ON
  )
};
