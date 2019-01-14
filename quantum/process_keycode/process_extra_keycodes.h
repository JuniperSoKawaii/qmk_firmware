/* Copyright 2016 Jack Humbert
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
#pragma once

#include "quantum.h"

#define IS_SYSTEM(code)   (KC_PWR       <= (code) && (code) <= KC_WAKE)
#define IS_CONSUMER(code) (KC_MUTE      <= (code) && (code) <= KC_BRID)

#ifdef EXTRAKEY_ENABLE
bool process_extra_keycodes(uint16_t keycode, keyrecord_t *record);
#endif
