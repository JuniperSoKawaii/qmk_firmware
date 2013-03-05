/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdint.h>
#include <stdbool.h>
#include "action.h"


#ifdef USE_KEYMAP_V2
/* translates key to keycode
 *      layer:  0-15 for base layers
 *              16-31 for overlays
 */
uint8_t keymap_key_to_keycode(uint8_t layer, key_t key);
/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode);
#else
#warning "You are using LEGACY KEYAMP. Consider using NEW KEYMAP."
/* 
 * legacy keymap support
 */
/* keycode of key */
uint8_t keymap_get_keycode(uint8_t layer, uint8_t row, uint8_t col);
/* layer to move during press Fn key */
uint8_t keymap_fn_layer(uint8_t fn_bits);
/* keycode to send when release Fn key without using */
uint8_t keymap_fn_keycode(uint8_t fn_bits);
#endif

#endif
