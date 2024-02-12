// Copyright 2024 spacehangover (@spacehangover)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define POT1_PIN F7
#define POT2_PIN F6
#define POT3_PIN F5
#define POT4_PIN F4
#define POT5_PIN B6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

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
