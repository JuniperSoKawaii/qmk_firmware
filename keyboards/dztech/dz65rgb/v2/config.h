#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x445A
#define PRODUCT_ID      0x1421
#define DEVICE_VER      0x0002
#define MANUFACTURER    DZTECH
#define PRODUCT         DZ65RGB

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { F0, F1, F4, E6, C6 }
#define MATRIX_COL_PINS { F7, F6, F5, C7, B0, B1, B2, B3, B4, D7, D6, D4, D5, D3, D2 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define DRIVER_ADDR_1 0b1110100
#    define DRIVER_ADDR_2 0b1110111
#    define DRIVER_COUNT 2
#    define DRIVER_1_LED_TOTAL 35
#    define DRIVER_2_LED_TOTAL 33
#    define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
#endif
