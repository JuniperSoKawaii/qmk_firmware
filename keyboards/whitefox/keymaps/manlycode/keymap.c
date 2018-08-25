/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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
#include "whitefox.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Qwerty Windows Programming
     * ,---------------------------------------------------------------.
     * |Esc/`| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| `|Bac|Del|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| \ |PgD/U|
     * |---------------------------------------------------------------|
     * |Ctrl(Bac)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter|Hme|
     * |---------------------------------------------------------------|
     * |Shift/(|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift/)|Up |End|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space        |Alt |Fn |    |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = LAYOUT_truefox( \
        KC_GESC,        KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,          LGUI(KC_BSLS), \
        KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC__MUTE, \
        KC_LCTL,        KC_A,    KC_S,    KC_D,   KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  TO(0), \
        KC_LSFT,        KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,   TO(1),  \
        KC_LCTL,        KC_LALT, KC_LGUI,                  KC_SPC,                   KC_RGUI, KC_FN0,           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
  [1] = LAYOUT_truefox( \
        KC_GESC,         KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS,  KC_GRV,          LGUI(KC_BSLS), \
        KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL, \
        KC_LCTL,        KC_A,    KC_S,    KC_D,   KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC__VOLUP, \
        KC_LSPO,        KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP,   KC__VOLDOWN,  \
        KC_LCTL,        KC_LALT, KC_LGUI,                  KC_SPC,                   KC_RGUI, KC_FN0,           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
