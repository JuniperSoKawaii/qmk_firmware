/* Copyright 2017 Balz Guenat
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

#include "bananasplit.h"

#define ______ KC_TRNS

/*
    This switch layout is ANSI with the following modifications:
        Split right shift
        225 125 275 spacebar
        Bottom right singles
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
-------------------------------------------------------------------------------------------
|Esc|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  |
-------------------------------------------------------------------------------------------
|  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
-------------------------------------------------------------------------------------------
|  Cpslock  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |   Enter   |
-------------------------------------------------------------------------------------------
|    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  Shift  | Up  |
-------------------------------------------------------------------------------------------
| Ctrl  |  GUI |  Alt | L1(Space)  | LED  |     Space     | Home | End | Left |Rght |Down |
-------------------------------------------------------------------------------------------
*/
[0] = KEYMAP( \
    KC_ESC,  KC_1,    KC_2,    KC_3, KC_4,   KC_5,  KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R,   KC_T,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS, KC_A,    KC_S,    KC_D, KC_F,   KC_G,  KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT,          KC_Z,    KC_X, KC_C,   KC_V,  KC_B,   KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,\
    KC_LCTL, KC_LGUI, KC_LALT, LT(1,KC_SPACE),      BL_TOGG,      KC_SPC,  KC_HOME, KC_END,  KC_LEFT, KC_RGHT, KC_DOWN  \
),
/*
-------------------------------------------------------------------------------------------
| ~   | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |  DEL      |
-------------------------------------------------------------------------------------------
|      |      | UP |      |     |     |     |     |    |    |      |      |      | PrtSc  |
-------------------------------------------------------------------------------------------
|      |Left | Down |Right |  |   |  |  |    | |     |     |             |  SLEEP         |
-------------------------------------------------------------------------------------------
|             |     |     |     |     |     | | |     |     |     |         |     |       |
-------------------------------------------------------------------------------------------
|       |       |       |            |  Reset  |            |       |       |       |     |
-------------------------------------------------------------------------------------------
*/
[1] = KEYMAP( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6, KC_F7,         KC_F8,          KC_F9,   KC_F10, KC_F11, KC_F12, KC_DEL, \
    ______, ______,   KC_UP,   ______, ______, ______, ______, ______, ______,   ______,  ______, ______, ______, KC_PSCR, \
    ______,  KC_LEFT, KC_DOWN, KC_RGHT, ______, ______, ______, ______,       ______,          ______, ______, ______, KC_SLEP, \
    ______,           ______,  ______,  ______,  ______, ______,  ______, ______,   ______,  ______, ______, ______, KC_PGUP, \
    ______,  ______,  ______,           ______,  RESET, ______,                 ______,         ______,  ______, ______, KC_PGDN \
),
};


const uint16_t PROGMEM fn_actions[] = {
};
