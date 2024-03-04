/* Copyright 2024 albert-zheng
 *
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




#define DRIVER_COUNT 1

#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#define RGB_MATRIX_KEYRELEASES         // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED // USB待机时候停止灯效
#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
//#define RGB_MATRIX_TYPING_HEATMAP_SLIM
//#define RGBLIGHT_SLEEP
#define RGB_MATRIX_TIMEOUT 0 //#define RGBLIGHT_DISABLE_KEYCODES


/* UART Config  */
#define SERIAL_DRIVER SD1
#define SD1_TX_PAL_MODE PAL_MODE_ALTERNATE_OPENDRAIN

/*DEBUG CONFIG*/
#define DEBUG_MATRIX_SCAN_RATE

#define MOUSEKEY_INTERVAL 5

#define WEAR_LEVELING_LOGICAL_SIZE 4096
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)

/*Force NKRO*/
#define FORCE_NKRO // Force NKRO on by default

/*DEBOUNCE TIME ms, default 5*/
//#define DEBOUNCE 10
#define ENCODER_RESOLUTION 4

//#define WS2812_EXTERNAL_PULLUP


//#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
