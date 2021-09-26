/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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


#define USE_SERIAL
#define EE_HANDS


#undef OLED_DISPLAY_ADDRESS
#define OLED_DISPLAY_ADDRESS 0x3C

#define OLED_DISPLAY_128X64

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2

//#define ENCODERS_PAD_A { F4 }
//#define ENCODERS_PAD_B { F5 }
#define MASTER_LEFT
//#define OLED_FONT_WIDTH 12
//#define OLED_FONT_HEIGHT 16
//#define OLED_FONT_END 111
// #define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up
