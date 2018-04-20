/*
Copyright 2018 Kenneth Aloysius

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
#include "action_layer.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0
     * ,-----------.
     * |   |Up |Fn0|
     * |---+---+---|
     * |Lef|Dow|Rig|
     * `-----------'
     */
    KEYMAP( UP,  FN0, LEFT,DOWN,RGHT ),
    /* Keymap 1
     * ,-----------.
     * |   |PgU|Fn1|
     * |---+---+---|
     * |Hom|PgD|End|
     * `-----------'
     */
    KEYMAP( PGUP,FN1, HOME,PGDN,END  ),
    /* Keymap 2
     * ,-----------.
     * |   |Sel|Fn2|
     * |---+---+---|
     * |Pre|Pla|Nex|
     * `-----------'
     */
    KEYMAP( MSEL,FN2, MPRV,MPLY,MNXT ),
    /* Keymap 3
     * ,-----------.
     * |   |MsU|Fn3|
     * |---+---+---|
     * |MsL|MsD|MsR|
     * `-----------'
     */
    KEYMAP( MS_U,FN3, MS_L,MS_D,MS_R ),
    /* Keymap 4
     * ,-----------.
     * |   |Fn6|Fn4|
     * |---+---+---|
     * |Fn7|Fn5|Fn8|
     * `-----------'
     */
    KEYMAP( FN6, FN4, FN7, FN5, FN8  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
