/*
Copyright 2020 DeskDaily

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
#define VENDOR_ID 0xD812
#define PRODUCT_ID 0x0014
#define DEVICE_VER 0x0002
#define MANUFACTURER DeskDaily
#define PRODUCT Octopad+

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { F6, D3, NO_PIN }
#define MATRIX_COL_PINS { E6, F5, C7, D7, F4, D2 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN F7
#ifdef RGB_DI_PIN
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS

#endif

/* Encoders */

#define ENCODERS 2

#define ENCODERS_PAD_A { D1, F0 }
#define ENCODERS_PAD_B { D0, F1 }

#define ENCODERS_CW_KEY  { { 3, 2 },{ 1, 2 } }
#define ENCODERS_CCW_KEY { { 2, 2 },{ 0, 2 } }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
