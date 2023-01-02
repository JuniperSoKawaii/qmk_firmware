// Copyright 2022 Dane Skalski (@Daneski13)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "junco.h"

// New default bootmagic lite, adds ability to manually set the handedness
// and won't clear it. Mostly copied from the Core bootmagic_lite.
__attribute__((weak)) void bootmagic_lite(void) {
    // Multiple scans because debouncing can't be turned off.
    matrix_scan();
#if defined(DEBOUNCE) && DEBOUNCE > 0
    wait_ms(DEBOUNCE * 2);
#else
    wait_ms(30);
#endif
    matrix_scan();

    uint8_t row = BOOTMAGIC_LITE_ROW;
    uint8_t col = BOOTMAGIC_LITE_COLUMN;

#if defined(BOOTMAGIC_LITE_ROW_RIGHT) && defined(BOOTMAGIC_LITE_COLUMN_RIGHT)
    if (!is_keyboard_left()) {
        row = BOOTMAGIC_LITE_ROW_RIGHT;
        col = BOOTMAGIC_LITE_COLUMN_RIGHT;
    }
#endif

    if (is_keyboard_master()) {
        // If key next to bootmagic is pressed
        if (matrix_get_row(row) & (1 << (col + 1))) {
            // Set left side
            eeconfig_update_handedness(true);
            soft_reset_keyboard();
        }

        // If key 2 over from bootmagic is pressed
        if (matrix_get_row(row) & (1 << (col + 2))) {
            // Set right side
            eeconfig_update_handedness(false);
            soft_reset_keyboard();
        }
    }

    // Normal bootmagic
    if (matrix_get_row(row) & (1 << col)) {
        // Clear EEPROM
#ifdef EE_HANDS
        eeconfig_init_persist_handedness();
#else
        eeconfig_disable();
#endif
        // Jump to bootloader.
        bootloader_jump();
    }
}

// Hand swap
#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},
    // Right
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}}
};
#endif

/* RGB LED matrix */
#ifdef RGB_MATRIX_ENABLE
/*
    Key Matrix Physical
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,
    L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35,
              L40, L41, L42, L43, L44, R42, R41, R43, R44, R45

    Key Electrical
    Left:
    { L00, L01, L02, L03, L04, L05 },
    { L10, L11, L12, L13, L14, L15 },
    { L20, L21, L22, L23, L24, L25 },
    { L30, L31, L32, L33, L34, L35 },
    { L40, L41, L42, L43, L44, L45 },
    Right:
    { R05, R04, R03, R02, R01, R00 },
    { R15, R14, R13, R12, R11, R10 },
    { R25, R24, R23, R22, R21, R20 },
    { R35, R34, R33, R32, R31, R30 },
    { R45, R44, R43, R42, R41, R40 }

    Key matrix physical filled with LED electrical indexes, count starting at 1

    Col
    0  1  2  3  4  5  6     7  8  9  10 11 12 13    Row

    14 13 12 11 10 9           46 47 48 49 50 51    0
      6      7     8           45    44      43
    15 16 17 18 19 20          57 56 55 54 53 52    1

    26 25 24 23 22 21          58 59 60 61 62 63    2
      5      4     3           40    41      42
    27 28 29 30 31 32 NO    NO 69 68 67 66 65 64    3

          37 36 35 34 33    70 71 72 73 74          4
             2       1        38     39
*/

// clang-format off
led_config_t g_led_config = {
    {	// Key Electrical Matrix to LED Index (count start at 0, so 8 is the first non-underglow key)

        // Left Half
        { 13, 12, 11, 10,  9,      8 },
        { 14, 15, 16, 17, 18,     19 },
        { 25, 24, 23, 22, 21,     20 },
        { 26, 27, 28, 29, 30,     31 },
        { 36, 35, 34, 33, 32, NO_LED },

        // Right Half
        { 50, 49, 48, 47, 46,     45 },
        { 51, 52, 53, 54, 55,     56 },
        { 62, 61, 60, 59, 58,     57 },
        { 63, 64, 65, 66, 67,     68 },
        { 73, 72, 71, 70, 69, NO_LED }
    },
    {	// LED Index to LED Physical Position (mirrored on right half)

        // Left Underglow (indicies 1 - 8)
        { 95, 72 }, { 52, 72 }, { 86, 40 }, { 52, 40 }, { 9, 40 }, { 9, 8 }, { 52, 8 }, { 86, 8 },
        // Left Matrix (indicies 9 - 37)
        { 86,  0 }, { 69,  0 }, {  52,  0 }, { 34,  0 }, { 17,  0 }, {  0,  0 },
        {  0, 16 }, { 17, 16 }, {  34, 16 }, { 52, 16 }, { 69, 16 }, { 86, 16 },
        { 86, 32 }, { 69, 32 }, {  52, 32 }, { 34, 32 }, { 17, 32 }, {  0, 32 },
        {  0, 48 }, { 17, 48 }, {  34, 48 }, { 52, 48 }, { 69, 48 }, { 86, 48 }, /* No Led */
                                { 103, 64 }, { 86, 64 }, { 69, 64 }, { 52, 64 }, { 34, 64 },

        // Right Underglow (indicies 38 - 45)
        { 129, 72 }, { 172, 72 }, { 138, 40 }, { 172, 40 }, { 215, 40 }, { 215, 8 }, { 172, 8 }, { 138, 8 },
        // Right Matrix (indicies 46 - 74)
                     { 138,  0 }, { 155,  0 }, { 172,  0 }, { 190,  0 }, { 207,  0 }, { 224,  0 },
                     { 224, 16 }, { 207, 16 }, { 190, 16 }, { 172, 16 }, { 155, 16 }, { 138, 16 },
                     { 138, 32 }, { 155, 32 }, { 172, 32 }, { 190, 32 }, { 207, 32 }, { 224, 32 },
        /* No Led */ { 224, 48 }, { 207, 48 }, { 190, 48 }, { 172, 48 }, { 155, 48 }, { 138, 48 },
        { 121, 64 }, { 138, 64 }, { 155, 64 }, { 172, 64 }, { 190, 64 }
    },
    {	// LED Index to Flag (2 - Underglow, 4 - Key Backlight)

        // Left Underglow
        2, 2, 2, 2, 2, 2, 2, 2,
        // Left Matrix
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4,
              4, 4, 4, 4, 4,

        // Right Underglow
        2, 2, 2, 2, 2, 2, 2, 2,
        // Right Matrix
           4, 4, 4, 4, 4, 4,
           4, 4, 4, 4, 4, 4,
           4, 4, 4, 4, 4, 4,
           4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4
    }
};

#endif
