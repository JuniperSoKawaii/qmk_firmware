/*
©2021 Everywhere Defense Industries / Fate Everywhere <fate@7storm.org>
 
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
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
    _MAIN,
    _RAISE,
    _LOWER,
    _SET,
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define SET     MO(_SET)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Backsp | Delete |   7    |   8    |   9    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Esc    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | Pause  |   4    |   5    |   6    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LShift | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | Up     | Enter  |   1    |   2    |   3    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCtrl  |  Lock  |   GUI  |   Alt  | Lower  | Space  |  Space | Raise  | PrtScr | RShift | Left   | Down   | Right  |   0    |   .    |  Enter |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_MAIN] = LAYOUT_ortho_4x16(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,  KC_KP_7, KC_KP_8,   KC_KP_9,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PAUS, KC_KP_4, KC_KP_5,   KC_KP_6,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_ENT,  KC_KP_1, KC_KP_2,   KC_KP_3,
  KC_LCTL, KC_LOCK, KC_LGUI, KC_LALT, LOWER,   KC_SPC, KC_SPC, RAISE, KC_PSCR, KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_KP_0, KC_KP_DOT, KC_PENT
  ),

/* RAISE
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    `   |  1     |  2     |  3     |  4     |  5     |  6     |  7     |  8     |  9     |  0     |        | Insert |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | -      | =      | [      | ]      |   \    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  PgUp  |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |  Vol-  |  PgDn  |  Vol+  |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_4x16(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_INS,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_PGDN, KC_VOLU, _______, _______, _______
  ),

/* LOWER
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |    _   |    +   |    {   |    }   |   |    |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |        |        |        |        |  Home  |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |  Mute  |  End   |  Play  |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_4x16(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, 
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_HOME, _______, _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_END,  KC_MPLY, _______, _______, _______
  ),

 /* SETTINGS
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |        | CapLok | ScrLok | NumLok | VK I/O |        |        | RGB IO | Mode+  | Mode-  | Plain  |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |  Hue+  |  Sat+  |  Val+  | Larsen |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |  Hue-  |  Sat-  |  Val-  | Rswirl |        | Reset  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SET] = LAYOUT_ortho_4x16(
  _______, KC_CAPS, KC_SCRL, KC_NLCK, VLK_TOG, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_M_P, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_SW,_______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_K, _______, QK_BOOT,   _______, _______, _______, 
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SET);
}