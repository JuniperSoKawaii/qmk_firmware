/*
Copyright 2021 Alabahuy

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414C 
#define PRODUCT_ID      0x4040
#define DEVICE_VER      0x0001
#define MANUFACTURER    Alabahuy
#define PRODUCT         RARTLITE

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, D2, B2, B4, B6, B5, D0, D1 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B3, F7, D3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
