/* Copyright 2020 AAClawson (AlisGraveNil)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
    * ------------------------------------
    * |INS |HOME|PGUP|NUM | /  | *  | -  |
    * ------------------------------------
    * |DEL |END |PGDN| 7  | 8  | 9  | +  |
    * ------------------------------|    |
    * |    |    |    | 4  | 5  | 6  |    |
    * ------------------------------------
    * |    | UP |    | 1  | 2  | 3  |ENT |
    * ------------------------------|    |
    * |LEFT|DOWN|RGHT| 0       | .  |    |
    * ------------------------------------
    */
    [0] = LAYOUT(
        KC_INS,  KC_HOME, KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_DEL,  KC_END,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
                                   KC_P4,   KC_P5,   KC_P6,
                 KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,            KC_PDOT
    ),

};

