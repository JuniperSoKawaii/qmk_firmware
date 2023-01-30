// Copyright 2023 a_marmot
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see &lt;http://www.gnu.org/licenses/&gt;.
//
// SPDX-License-Identifier: GPL-2.0-or-later


#pragma once

#define DRIVER_COUNT 1
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_LED_TOTAL 60
#define RGB_MATRIX_LED_COUNT 20
#define ISSI_TIMEOUT 100
#define ISSI_PERSISTENCE 0
#define I2C1_CLOCK_SPEED 100000
#define I2C1_DUTY_CYCLE  STD_DUTY_CYCLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
