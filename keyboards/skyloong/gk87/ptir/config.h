// Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define CAPS_PIN C15
#define SCR_PIN C14
#define WINLK_PIN C13

#ifdef ENCODER_ENABLE
#define ENCODER_MAP_KEY_DELAY 20
#endif

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_ADDR_2 0b0100011
#define DRIVER_COUNT 2

#define RGB_MATRIX_LED_COUNT 91
#define CAPS_LOCK_INDEX 50
#define WIN_MOD_INDEX 22
#define MAC_MOD_INDEX 23
#define WIN_LOCK_INDEX 75
#define SCR_LOCK_INDEX 14
#define SDB B5


/* RGB Matrix Animation modes. Explicitly enabled
 * For full list of effects, see:
 * https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
 */

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#endif
