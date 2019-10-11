/*
Copyright 2019 Maarten Dekkers <maartenwut@gmail.com>

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
#define VENDOR_ID       0x4705
#define PRODUCT_ID      0x7465
#define DEVICE_VER      0x0001
#define MANUFACTURER    Maartenwut
#define PRODUCT         TA-65
#define DESCRIPTION     A universal 65% PCB with underglow.

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {B4,D7,D6,D4,B3}
#define MATRIX_COL_PINS {D2,D1,D0,D3,D5,C7,C6,B6,B5,F0,F1,F4,F5,F6,F7,B0}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Backlight configuration
 */
#define RGB_DI_PIN E6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8

#define QMK_ESC_OUTPUT D2 // usually COL
#define QMK_ESC_INPUT B4 // usually ROW
#define QMK_LED E6
