/*
Copyright 2020 Gondolindrim

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

#define MATRIX_ROWS 6
#define MATRIX_COLS 17

#define MATRIX_COL_PINS { C7 , C6 , B14, B12, B10, B1 , C4 , A7 , A6 , A5 , A4 , A3 , A2 , C5 , A10, A8 , C9 }
#define MATRIX_ROW_PINS { C11, C12, C10, A15, C0 , A1 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define BACKLIGHT_PIN           B0
#define BACKLIGHT_PWM_DRIVER    PWMD3
#define BACKLIGHT_PWM_CHANNEL   3
#define BACKLIGHT_PAL_MODE      2
#define BACKLIGHT_LEVELS 20
#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 5

#define RGB_DI_PIN B15
#define RGBLED_NUM 34
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+5

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

#define LED_CAPS_LOCK_PIN C8

// If this is defined, the caps lock LED will turn on and off according to the state of caps lock. If not, the LED will shine like all other LEDs despite the caps lock state.
#define CAPSLOCK_INDICATOR
