/*
Copyright 2020 Team Mechlovin

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
#define VENDOR_ID    0x4D4C // "ML"
#define DEVICE_VER   0x0001
#define MANUFACTURER Team.Mechlovin

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/*
#define LED_NUM_LOCK_PIN C15
#define LED_CAPS_LOCK_PIN B2
#define LED_SCROLL_LOCK_PIN B9
*/

#define INDICATOR_PIN_0 B2
#define INDICATOR_PIN_1 C15
#define INDICATOR_PIN_2 B9