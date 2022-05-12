#pragma once

/*
Copyright 2022 Andrew Kannan

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
#define VENDOR_ID       0xCA04
#define PRODUCT_ID      0x0009
#define DEVICE_VER      0x0001
#define MANUFACTURER CannonKeys
#define PRODUCT Malicious Ergo

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 17

#define MATRIX_COL_PINS { B1, B0, A7, A1, A5, A4, A3, A10, B9, B8, B7, B6, B5, B4, B3, A15, A14 }
#define MATRIX_ROW_PINS { B2, B10, B11, A2, A0 }
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN           A6
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   1
#define BACKLIGHT_PAL_MODE      1
#define BACKLIGHT_LEVELS 6
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGBLIGHT_ANIMATIONS
#define RGB_DI_PIN B15
#define RGBLED_NUM 14
#define WS2812_SPI SPID2
#define WS2812_SPI_MOSI_PAL_MODE 0
#define WS2812_SPI_SCK_PAL_MODE 0
#define WS2812_SPI_SCK_PIN B13

// Indicator LEDs
#define LED_CAPS_LOCK_PIN A8
#define LED_NUM_LOCK_PIN A9
#define LED_SCROLL_LOCK_PIN B12
#define LED_PIN_ON_STATE 0



// 2 bits for 4 layout options
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#define SLEEP_LED_GPT_DRIVER GPTD1

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



