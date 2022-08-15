/*
Copyright 2022 AliceH

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6168
#define PRODUCT_ID      0x7068
#define DEVICE_VER      0x0001
#define MANUFACTURER    AliceH 
#define PRODUCT         pianoforte_hotswap

#define MATRIX_ROWS 12
#define MATRIX_COLS 9

#define MATRIX_COL_PINS { D6, D7, B4, B5, B6, F6, F5, E6, D4 }
#define MATRIX_ROW_PINS { D2, D1, D3, D0, D5, B0, F0, F1, F7, F4, C7, C6 }
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5
#define VIAL_KEYBOARD_UID {0xF3, 0xC1, 0x73, 0xB5, 0x52, 0xD4, 0x0E, 0x99}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 6 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 6 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 2

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


