#pragma once

//5x5 powered by Adafruit Feather 32u4 Bluefruit LE
#if defined(KEYBOARD_5x5) && defined(BLUEFRUIT)
/*
// set top left key as bootloader mode escape key on 5x5 75key layout, for QMK_DFU bootloader boards
#define QMK_LED B0
#define QMK_ESC_OUTPUT C6 // usually COL
#define QMK_ESC_INPUT F7 // usually ROW
*/

//need to undefine standard 5x5 array before defining alternate Bluefruit array
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { F7, F6, F5, D1, D0 }
//last 5 elements not tested
#define MATRIX_COL_PINS { C6, D7, B5, B6, B7, D6, C7, F0, F1, F4, B1, B2, B3, D2, D3 }

//get rid of description - too long to show properly in Windows
#undef DESCRIPTION
#define DESCRIPTION 
#endif