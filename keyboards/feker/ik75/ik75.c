/* Copyright 2022 Feker
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ik75.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  G location
 *   |  |     B location
 *   |  |     |     R location
 *   |  |     |     | */
    {0, A_1,  C_1,  B_1},  // 0,   `~,              K10
    {0, A_2,  C_2,  B_2},  // 1,   1!,              K11
    {0, A_3,  C_3,  B_3},  // 2,   2@,              K12
    {0, A_4,  C_4,  B_4},  // 3,   3#,              K13
    {0, A_5,  C_5,  B_5},  // 4,   4$,              K14
    {0, A_6,  C_6,  B_6},  // 5,   5%,              K15
    {0, A_7,  C_7,  B_7},  // 6,   6^,              K16
    {0, A_8,  C_8,  B_8},  // 7,   7&,              K17
    {0, A_9,  C_9,  B_9},  // 8,   8*,              K18
    {0, A_10, C_10, B_10}, // 9,   9(,              K19
    {0, A_11, C_11, B_11}, // 10,  0),              K1A
    {0, A_12, C_12, B_12}, // 11,  -_,              K1B
    {0, A_13, C_13, B_13}, // 12,  =+,              K1C
    {0, A_14, C_14, B_14}, // 13,  Backspace,       K1D
    {0, A_15, C_15, B_15}, // 14,  Left Alt,        K52
    {0, A_16, C_16, B_16}, // 15,  Space,           K56

    {0, D_1,  F_1,  E_1},  // 16,  Tab,             K20
    {0, D_2,  F_2,  E_2},  // 17,  Q,               K21
    {0, D_3,  F_3,  E_3},  // 18,  W,               K22
    {0, D_4,  F_4,  E_4},  // 19,  E,               K23
    {0, D_5,  F_5,  E_5},  // 20,  R,               K24
    {0, D_6,  F_6,  E_6},  // 21,  T,               K25
    {0, D_7,  F_7,  E_7},  // 22,  Y,               K26
    {0, D_8,  F_8,  E_8},  // 23,  U,               K27
    {0, D_9,  F_9,  E_9},  // 24,  I,               K28
    {0, D_10, F_10, E_10}, // 25,  O,               K29
    {0, D_11, F_11, E_11}, // 26,  P,               K2A
    {0, D_12, F_12, E_12}, // 27,  [{,              K2B
    {0, D_13, F_13, E_13}, // 28,  ]},              K2C
    {0, D_14, F_14, E_14}, // 29,  \|,              K2D
    {0, D_15, F_15, E_15}, // 30,  Right Ctrl,      K5C
    {0, D_16, F_16, E_16}, // 31,  Function,        K5A

    {0, G_1,  I_1,  H_1},  // 32,  Caps Lock,       K30
    {0, G_2,  I_2,  H_2},  // 33,  A,               K31
    {0, G_3,  I_3,  H_3},  // 34,  S,               K32
    {0, G_4,  I_4,  H_4},  // 35,  D,               K33
    {0, G_5,  I_5,  H_5},  // 36,  F,               K34
    {0, G_6,  I_6,  H_6},  // 37,  G,               K35
    {0, G_7,  I_7,  H_7},  // 38,  H,               K36
    {0, G_8,  I_8,  H_8},  // 39,  J,               K37
    {0, G_9,  I_9,  H_9},  // 40,  K,               K38
    {0, G_10, I_10, H_10}, // 41,  L,               K39
    {0, G_11, I_11, H_11}, // 42,  ;:,              K3A
    {0, G_12, I_12, H_12}, // 43,  '",              K3B
    {0, G_13, I_13, H_13}, // 44,  Enter,           K3D
    {0, G_14, I_14, H_14}, // 45,  Up,              K4E
    {0, G_15, I_15, H_15}, // 46,  Num Lock LED
    {0, G_16, I_16, H_16}, // 47,  Right Alt,       K59

    {0, J_1,  L_1,  K_1},  // 48,  Left Shift,      K40
//  {0, J_2,  L_2,  K_2},  //      Unused LED
    {0, J_3,  L_3,  K_3},  // 49,  Z,               K42
    {0, J_4,  L_4,  K_4},  // 50,  X,               K43
    {0, J_5,  L_5,  K_5},  // 51,  C,               K44
    {0, J_6,  L_6,  K_6},  // 52,  V,               K45
    {0, J_7,  L_7,  K_7},  // 53,  B,               K46
    {0, J_8,  L_8,  K_8},  // 54,  N,               K47
    {0, J_9,  L_9,  K_9},  // 55,  M,               K48
    {0, J_10, L_10, K_10}, // 56,  ,<,              K49
    {0, J_11, L_11, K_11}, // 57,  .>,              K4A
    {0, J_12, L_12, K_12}, // 58,  /?,              K4B
    {0, J_13, L_13, K_13}, // 59,  Right Shift,     K4D
    {0, J_14, L_14, K_14}, // 60,  Left,            K5D
    {0, J_15, L_15, K_15}, // 61,  Down,            K5E
    {0, J_16, L_16, K_16}, // 62,  Right,           K5F

    {1, A_1,  C_1,  B_1},  // 63,  Underglow 20
    {1, A_2,  C_2,  B_2},  // 64,  Underglow 19
    {1, A_3,  C_3,  B_3},  // 65,  Underglow 18
    {1, A_4,  C_4,  B_4},  // 66,  Underglow 17
    {1, A_5,  C_5,  B_5},  // 67,  Underglow 16
    {1, A_6,  C_6,  B_6},  // 68,  Underglow 15
    {1, A_7,  C_7,  B_7},  // 69,  Underglow 14
    {1, A_8,  C_8,  B_8},  // 70,  Underglow 13
    {1, A_9,  C_9,  B_9},  // 71,  Underglow 12
    {1, A_10, C_10, B_10}, // 72,  Underglow 11
    {1, A_11, C_11, B_11}, // 73,  Underglow 10
    {1, A_12, C_12, B_12}, // 74,  Underglow 9
    {1, A_13, C_13, B_13}, // 75,  Underglow 8
    {1, A_14, C_14, B_14}, // 76,  Underglow 7
    {1, A_15, C_15, B_15}, // 77,  Underglow 6
    {1, A_16, C_16, B_16}, // 78,  Underglow 5

    {1, D_1,  F_1,  E_1},  // 79,  Esc,             K00
    {1, D_2,  F_2,  E_2},  // 80,  F1,              K01
    {1, D_3,  F_3,  E_3},  // 81,  F2,              K02
    {1, D_4,  F_4,  E_4},  // 82,  F3,              K03
    {1, D_5,  F_5,  E_5},  // 83,  F4,              K04
    {1, D_6,  F_6,  E_6},  // 84,  F5,              K05
    {1, D_7,  F_7,  E_7},  // 85,  F6,              K06
    {1, D_8,  F_8,  E_8},  // 86,  F7,              K07
    {1, D_9,  F_9,  E_9},  // 87,  F8,              K08
    {1, D_10, F_10, E_10}, // 88,  F9,              K09
    {1, D_11, F_11, E_11}, // 89,  F10,             K0A
    {1, D_12, F_12, E_12}, // 90,  F11,             K0B
    {1, D_13, F_13, E_13}, // 91,  F12,             K0C
    {1, D_14, F_14, E_14}, // 92,  Delete,          K0D
    {1, D_15, F_15, E_15}, // 93,  Left Ctrl,       K50
    {1, D_16, F_16, E_16}, // 94,  Left Windows,    K51

    {1, G_1,  I_1,  H_1},  // 95,  Underglow 21
    {1, G_2,  I_2,  H_2},  // 96,  Underglow 22
    {1, G_3,  I_3,  H_3},  // 97,  Underglow 23
    {1, G_4,  I_4,  H_4},  // 98,  Underglow 24
    {1, G_5,  I_5,  H_5},  // 99,  Knob LED 3,      K53
    {1, G_6,  I_6,  H_6},  // 100, Knob LED 2,      K54
    {1, G_7,  I_7,  H_7},  // 101, Knob LED 1,      K4F
    {1, G_8,  I_8,  H_8},  // 102, Insert,          K1F
    {1, G_9,  I_9,  H_9},  // 103, Page Up,         K3E
    {1, G_10, I_10, H_10}, // 104, Caps/Win/Scr LED
    {1, G_11, I_11, H_11}, // 105, End,             K2F
    {1, G_12, I_12, H_12}, // 106, Page Down,       K3F
    {1, G_13, I_13, H_13}, // 107, Underglow 1
    {1, G_14, I_14, H_14}, // 108, Underglow 2
    {1, G_15, I_15, H_15}, // 109, Underglow 3
    {1, G_16, I_16, H_16}, // 110, Underglow 4

    {1, J_1,  L_1,  K_1},  // 111, Underglow 25
    {1, J_2,  L_2,  K_2},  // 112, Underglow 26
    {1, J_3,  L_3,  K_3},  // 113, Underglow 27
    {1, J_4,  L_4,  K_4},  // 114, Underglow 28
    {1, J_5,  L_5,  K_5},  // 115, Underglow 29
    {1, J_6,  L_6,  K_6},  // 116, Underglow 30
    {1, J_7,  L_7,  K_7},  // 117, Underglow 31
    {1, J_8,  L_8,  K_8},  // 118, Underglow 32
    {1, J_9,  L_9,  K_9},  // 119, Underglow 33
    {1, J_10, L_10, K_10}, // 120, Underglow 34
    {1, J_11, L_11, K_11}, // 121, Underglow 35
    {1, J_12, L_12, K_12}, // 122, Underglow 36
    {1, J_13, L_13, K_13}, // 123, Underglow 37
    {1, J_14, L_14, K_14}, // 124, Underglow 38
    {1, J_15, L_15, K_15}, // 125, Underglow 39
    {1, J_16, L_16, K_16}, // 126, Underglow 40
};

led_config_t g_led_config = { {
    { 79,     80,     81,     82,     83,     84,     85,     86,     87,     88,     89,     90,     91,     92, NO_LED, NO_LED },
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13, NO_LED,    102 },
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29, NO_LED,    105 },
    { 32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43, NO_LED,     44,    103,    106 },
    { 48, NO_LED,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58, NO_LED,     59,     45,    101 },
    { 93,     94,     14, NO_LED, NO_LED, NO_LED,     15, NO_LED, NO_LED,     30,     31, NO_LED,     47,     60,     61,     62 }
}, {
    {0  , 15}, {14 , 15}, {29 , 15}, {43 , 15}, {58 , 15}, {72 , 15}, {87 , 15}, {101, 15}, {116, 15}, {130, 15}, {145, 15}, {159, 15}, {173, 15}, {195, 15}, {38 , 61}, {92 , 61},
    {4  , 26}, {22 , 26}, {36 , 26}, {51 , 26}, {65 , 26}, {79 , 26}, {94 , 26}, {108, 26}, {123, 26}, {137, 26}, {152, 26}, {166, 26}, {181, 26}, {199, 26}, {173, 61}, {159, 61},
    {5  , 38}, {25 , 38}, {40 , 38}, {54 , 38}, {69 , 38}, {83 , 38}, {98 , 38}, {112, 38}, {126, 38}, {141, 38}, {155, 38}, {170, 38}, {193, 38}, {206, 52}, {0  , 29}, {145, 61},
    {9  , 49},            {33 , 49}, {47 , 49}, {61 , 49}, {76 , 49}, {90 , 49}, {105, 49}, {119, 49}, {134, 49}, {148, 49}, {163, 49}, {182, 49}, {191, 64}, {206, 64}, {220, 64},
    {14 ,  0}, {28 ,  0}, {53 ,  0}, {63 ,  0}, {74 ,  0}, {88 ,  0}, {102,  0}, {116,  0}, {130,  0}, {144,  0}, {158,  0}, {172,  0}, {189,  0}, {210,  0}, {224,  0}, {224, 11},
    {0  ,  0}, {18 ,  0}, {33 ,  0}, {47 ,  0}, {61 ,  0}, {79 ,  0}, {94 ,  0}, {108,  0}, {123,  0}, {141,  0}, {155,  0}, {170,  0}, {184,  0}, {202,  0}, {2  , 61}, {20 , 61},
    {0  ,  0}, {0  , 11}, {0  , 27}, {0  , 37}, {224,  5}, {210,  5}, {217,  0}, {224, 15}, {224, 38}, {0  ,  0}, {224, 26}, {224, 49}, {224, 56}, {224, 45}, {224, 35}, {224, 24},
    {0  , 48}, {0  , 56}, {0  , 64}, {14 , 64}, {28 , 64}, {49 , 64}, {67 , 64}, {84 , 64}, {98 , 64}, {112, 64}, {126, 64}, {140, 64}, {158, 64}, {172, 64}, {196, 64}, {224, 64},
}, {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 4,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 8, 1,
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    2, 2, 2, 2, 2, 2, 4, 4, 4, 8, 4, 4, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };
#endif
