/* Copyright 2020 Team Mechlovin
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

#include "chrisgve.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [0] = LAYOUT_all(
    //  KC_SPC, KC_ESC,  KC_1, KC_2,    KC_3, KC_4,   KC_5, KC_6,            KC_7, KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    //  KC_SPC, KC_TAB,  KC_Q, KC_W,    KC_E, KC_R,   KC_T,                  KC_Y, KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_SLSH,
    //  KC_SPC, KC_CAPS, KC_A, KC_S,    KC_D, KC_F,   KC_G,                  KC_H, KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    //          KC_LSFT,       KC_Z,    KC_X, KC_C,   KC_V, KC_B,            KC_N, KC_M,   KC_COMM, KC_DOT,  KC_BSLS, MO(1),   KC_RSFT, KC_UP,
    //          KC_LCTL,       KC_LALT,       KC_SPC,       MO(2),                 KC_SPC,          KC_RALT,                            KC_RCTL ),
    [_QWERTY_MAC] = LAYOUT_all(
     KC_PGUP, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
     KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     ADJ_M,   KC_LCTL, KC_A,    KC_S,    M_NAV_1, KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT, R_SHIFT, ADJ_M,
              KC_LALT,          KC_LGUI,          SPC_RSE,          SPC_RSE,                  SPC_RSE,          KC_RGUI,                            KC_RALT
    ),

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}

  #endif
