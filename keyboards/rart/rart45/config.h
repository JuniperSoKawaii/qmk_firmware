/* Copyright 2020 Alabahuy
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x414C
#define PRODUCT_ID      0x0045
#define DEVICE_VER      0x0001
#define MANUFACTURER    Alabahuy
#define PRODUCT         Rart45

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D1, C3, C1, B1, D0, C2, C0, D7, B0 }
#define MATRIX_COL_PINS { D6, D4, B2, B5, B4, B3 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define USB_MAX_POWER_CONSUMPTION 100

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
