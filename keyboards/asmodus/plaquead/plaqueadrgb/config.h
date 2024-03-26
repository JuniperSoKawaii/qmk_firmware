/*
Copyright 2024 Asmodus
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

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RP2040_FLASH_GENERIC_03H

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_CENTER { 127, 32 }
#define DRIVER_LED_TOTAL 134
#define RGB_MATRIX_LED_COUNT 134

#define CAPS_LOCK_LED_INDEX 54
#define SCROLL_LOCK_LED_INDEX 1
#endif