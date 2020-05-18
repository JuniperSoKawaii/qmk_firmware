/*
Copyright 2020 Ckat <ckat@teknik.io>

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

/* DEBUG
   default map is strictly for debugging shorts
   flash either the left or right keymap accordingly */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_0, KC_5, KC_0, KC_5, KC_0, KC_5, KC_0, KC_5, \
        KC_1, KC_4, KC_1, KC_4, KC_1, KC_4, KC_1, KC_4, \
        KC_2, KC_3, KC_2, KC_3, KC_2, KC_3, KC_2, KC_3, \
        KC_3, KC_2, KC_3, KC_2, KC_3, KC_2, KC_3, KC_2, \
        KC_4, KC_1, KC_4, KC_1, KC_4, KC_1, KC_4, KC_1, \
        KC_5, KC_0, KC_5, KC_0, KC_5, KC_0, KC_5, KC_0 
    )
};
