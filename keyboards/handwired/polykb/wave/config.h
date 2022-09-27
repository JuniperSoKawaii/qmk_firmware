/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 8

#define DIODE_DIRECTION ROW2COL

#define LAYOUT(\
    kc0r0, kc1r0 ,kc2r0, kc3r0, kc4r0, kc5r0 ,kc6r0, kc7r0,\
    kc0r1, kc1r1 ,kc2r1, kc3r1, kc4r1, kc5r1 ,kc6r1, kc7r1,\
    kc0r2, kc1r2 ,kc2r2, kc3r2, kc4r2, kc5r2 ,kc6r2, kc7r2,\
    kc0r3, kc1r3 ,kc2r3, kc3r3, kc4r3, kc5r3 ,kc6r3, kc7r3,\
    kc0r4, kc1r4 ,kc2r4, kc3r4, kc4r4, kc5r4 ,kc6r4, kc7r4 \
  ) { \
    { kc0r0, kc1r0 ,kc2r0, kc3r0, kc4r0, kc5r0 ,kc6r0, kc7r0 }, \
    { kc0r1, kc1r1 ,kc2r1, kc3r1, kc4r1, kc5r1 ,kc6r1, kc7r1 }, \
    { kc0r2, kc1r2 ,kc2r2, kc3r2, kc4r2, kc5r2 ,kc6r2, kc7r2 }, \
    { kc0r3, kc1r3 ,kc2r3, kc3r3, kc4r3, kc5r3 ,kc6r3, kc7r3 }, \
    { kc0r4, kc1r4 ,kc2r4, kc3r4, kc4r4, kc5r4 ,kc6r4, kc7r4 }  \
}

#define LAYOUT_TO_INDEX(row, col) ((row)*MATRIX_COLS+(col))

#define DRIVER_LED_TOTAL 36
#define RGBLED_NUM 36

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DISABLE_TIMEOUT 62000

#define NUM_SHIFT_REGISTERS 5
