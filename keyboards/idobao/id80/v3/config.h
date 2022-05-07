// Copyright Sergey Vlasov <sigprof@gmail.com>
// Copyright 2022 peepeetee (@peepeetee)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6964  /* "id" */
#define PRODUCT_ID      0x0380
#define DEVICE_VER      0x0003
#define MANUFACTURER    IDOBAO
#define PRODUCT         ID80v3


/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 * The matrix description in the vendor-supplied JSON file for kbfirmware.com
 * had 9 columns:
 *     { D0, D1, D2, D3, D5, D4, D6, D7, B4 }
 * and 12 rows:
 *     { B7, B3, B2, B1, B0, E6, F0, F1, F4, F5, F6, F7 }
 * However, the row 6 was completely empty, and the pin F0 was not actually
 * routed anywhere on the PCB, therefore this row was removed to save some
 * resources (the EEPROM space for dynamic keymaps is especially scarce).
 *
 * After doing the above change, the matrix was transposed (rows and columns
 * were swapped), because a matrix with the COL2ROW layout can be scanned much
 * more efficiently than a matrix with the ROW2COL layout (depending on various
 * optimizations, the difference in scan rate can be over 2 times).  Because of
 * this, the "columns" in the matrix layout now mostly correspond to physical
 * rows, and the "rows" have mostly vertical physical orientation.
 */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D5, D4, D6, D7, B4 }
#define MATRIX_COL_PINS { B7, B3, B2, B1, B0, E6, F1, F4, F5, F6, F7 }
#define UNUSED_PINS { F0 }

#define DIODE_DIRECTION COL2ROW

/* Bootmagic Lite key configuration: use the Esc key */
#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 5

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { C7 }
    #define ENCODERS_PAD_B { C6 }
#endif

/* RGB Matrix */
#define RGB_DI_PIN B6

#if defined(RGB_DI_PIN) && defined(RGB_MATRIX_ENABLE)

    #define DRIVER_LED_TOTAL 96  // 16 Bottom 80 top
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180  // Limit to vendor-recommended value
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended

    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES

    /* RGB Matrix Animation modes. Explicitly enabled
     * For full list of effects, see:
     * https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
     */
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_HUE_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    /* enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined */
    // #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    /* enabled only if RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined */
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
