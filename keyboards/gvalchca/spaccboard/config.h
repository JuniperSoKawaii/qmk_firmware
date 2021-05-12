#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6776
#define PRODUCT_ID      0x5342
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gvalchca
#define PRODUCT         SpaccBoard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {B1,B2,B3,C7,F0}
#define MATRIX_COL_PINS {E6,B7,D5,D6,D7,B4,B5,B6,C6,F7,F6,F5,F4,F1,D3}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define QMK_ESC_OUTPUT E6 // usually COL
#define QMK_ESC_INPUT B1 // usually ROW
