// Copyright 2022 ziptyze (@ziptyze)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x6F75 // OU
#define PRODUCT_ID   0x5600
#define DEVICE_VER   0x0001
#define MANUFACTURER 1upkeyboards
#define PRODUCT      pi40

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define DIODE_DIRECTION COL2ROW

#define MATRIX_ROW_PINS { GP21, GP20, GP19, GP18 }
#define MATRIX_COL_PINS { GP1, GP2, GP3, GP4, GP5, GP6, GP7, GP8, GP9, GP10, GP11, GP12 }

#define ENCODERS_PAD_A { GP14 }
#define ENCODERS_PAD_B { GP13 }

#define I2C_DRIVER I2CD2
#define I2C1_SCL_PIN GP17
#define I2C1_SDA_PIN GP16

#define NOP_FUDGE 0.4

#define RGB_DI_PIN GP0
#define DRIVER_LED_TOTAL 47
#define RGBLED_NUM 47
#ifdef RGB_DI_PIN
//#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#    define RGBLIGHT_LIMIT_VAL 150
#endif
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
//#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#    define ENABLE_RGB_MATRIX_SPLASH
//#    define ENABLE_RGB_MATRIX_MULTISPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0