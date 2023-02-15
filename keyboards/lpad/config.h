// Copyright 2023 Laneware Peripherals
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, B7, D0}
#define MATRIX_COL_PINS { D3, D4, D6 }

/*ENCODER*/
#define ENCODERS_PAD_A { F0 }
#define ENCODERS_PAD_B { F1 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
