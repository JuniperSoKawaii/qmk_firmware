/* Copyright 2021 csandven
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _FN
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * QWERTY
    * ,-------------------------------------------------------.                    ,-----------------------------------------.
    * |  F1  |  F2  |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
    * |------+------+------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  F3  |  F4  | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
    * |------+------+------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  F5  |  F6  | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |  F7  |  F8  |LShift|   Z  |   X  |   C  |   V  |   B  |       |    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-------------------------------------------------------/-------/     \      \-----------------------------------------'
    *                          | LGUI | LAlt | LCTR |LOWER |  Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *                          |      |      |      |      |        /         \      \ |      |      |      |      |
    *                           `----------------------------------'           '------''---------------------------'
    */

    [_QWERTY] = LAYOUT( \
        KC_F1,   KC_F2,   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, KC_7,    KC_8, \
        KC_F3,   KC_F4,   KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, KC_U,    KC_I, \
        KC_F5,   KC_F6,   KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, KC_J,    KC_K, \
        KC_F7,   KC_F8,   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, KC_M, KC_COMM, \
                                              KC_LGUI,KC_LALT, KC_LOWER, KC_ENT,              KC_SPC,  KC_RAISE, KC_RALT, KC_RGUI \
    ),
};
