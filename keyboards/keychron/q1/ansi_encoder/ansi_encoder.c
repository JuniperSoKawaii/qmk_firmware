/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, C_1,    A_1,    B_1},
    {0, C_3,    A_3,    B_3},
    {0, C_4,    A_4,    B_4},
    {0, C_5,    A_5,    B_5},
    {0, C_6,    A_6,    B_6},
    {0, C_7,    A_7,    B_7},
    {0, C_8,    A_8,    B_8},
    {0, C_9,    A_9,    B_9},
    {0, C_10,   A_10,   B_10},
    {0, C_11,   A_11,   B_11},
    {0, C_12,   A_12,   B_12},
    {0, C_13,   A_13,   B_13},
    {0, C_14,   A_14,   B_14},
    {0, C_15,   A_15,   B_15},
    {0, C_16,   A_16,   B_16},

    {0, F_1,    D_1,    E_1},
    {0, F_2,    D_2,    E_2},
    {0, F_3,    D_3,    E_3},
    {0, F_4,    D_4,    E_4},
    {0, F_5,    D_5,    E_5},
    {0, F_6,    D_6,    E_6},
    {0, F_7,    D_7,    E_7},
    {0, F_8,    D_8,    E_8},
    {0, F_9,    D_9,    E_9},
    {0, F_10,   D_10,   E_10},
    {0, F_11,   D_11,   E_11},
    {0, F_12,   D_12,   E_12},
    {0, F_13,   D_13,   E_13},
    {0, F_14,   D_14,   E_14},
    {0, F_16,   D_16,   E_16},

    {0, I_1,    G_1,    H_1},
    {0, I_2,    G_2,    H_2},
    {0, I_3,    G_3,    H_3},
    {0, I_4,    G_4,    H_4},
    {0, I_5,    G_5,    H_5},
    {0, I_6,    G_6,    H_6},
    {0, I_7,    G_7,    H_7},
    {0, I_8,    G_8,    H_8},
    {0, I_9,    G_9,    H_9},
    {0, I_10,   G_10,   H_10},
    {0, I_11,   G_11,   H_11},
    {0, I_12,   G_12,   H_12},
    {0, I_13,   G_13,   H_13},
    {0, I_14,   G_14,   H_14},
    {0, I_16,   G_16,   H_16},

    {0, L_1,    J_1,    K_1},
    {0, L_2,    J_2,    K_2},
    {0, L_3,    J_3,    K_3},
    {0, L_4,    J_4,    K_4},
    {0, L_5,    J_5,    K_5},
    {0, L_6,    J_6,    K_6},
    {0, L_7,    J_7,    K_7},
    {0, L_8,    J_8,    K_8},
    {0, L_9,    J_9,    K_9},
    {0, L_10,   J_10,   K_10},
    {0, L_11,   J_11,   K_11},
    {0, L_12,   J_12,   K_12},
    {0, L_14,   J_14,   K_14},
    {0, L_16,   J_16,   K_16},

    {1, C_1,    A_1,    B_1},
    {1, C_3,    A_3,    B_3},
    {1, C_4,    A_4,    B_4},
    {1, C_5,    A_5,    B_5},
    {1, C_6,    A_6,    B_6},
    {1, C_7,    A_7,    B_7},
    {1, C_8,    A_8,    B_8},
    {1, C_9,    A_9,    B_9},
    {1, C_10,   A_10,   B_10},
    {1, C_11,   A_11,   B_11},
    {1, C_12,   A_12,   B_12},
    {1, C_14,   A_14,   B_14},
    {1, C_15,   A_15,   B_15},

    {1, F_1,    D_1,    E_1},
    {1, F_2,    D_2,    E_2},
    {1, F_3,    D_3,    E_3},
    {1, F_7,    D_7,    E_7},
    {1, F_11,   D_11,   E_11},
    {1, F_12,   D_12,   E_12},
    {1, F_13,   D_13,   E_13},
    {1, F_14,   D_14,   E_14},
    {1, F_15,   D_15,   E_15},
    {1, F_16,   D_16,   E_16}
};

#define __ NO_LED

led_config_t g_led_config = {
	{
        // Key Matrix to LED Index
		{  0, __,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 14 },
		{ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
		{ 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44 },
		{ 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 71, 57, 58 },
		{ 59, __, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 80, 70, 13 },
		{ 72, 73, 74, __, __, __, 75, __, __, __, 76, 77, 78, 79, 81 }
	},
	{
        // LED Index to Physical Position
        {0,0},           {18,0},  {33,0},  {48,0},  {62,0},  {81,0},  {95,0},   {110,0},  {125,0},  {143,0},  {158,0},  {173,0},  {187,0},  {206,0},  {224,0},
        {0,15}, {15,15}, {29,15}, {44,15}, {59,15}, {73,15}, {88,15}, {103,15}, {118,15}, {132,15}, {147,15}, {162,15}, {176,15}, {198,15},           {224,15},
        {4,26}, {22,26}, {37,26}, {51,26}, {66,26}, {81,26}, {95,26}, {110,26}, {125,26}, {140,26}, {154,26}, {169,26}, {184,26}, {202,26},           {224,26},
        {6,38}, {26,38}, {40,38}, {55,38}, {70,38}, {84,38}, {99,38}, {114,38}, {129,38}, {143,38}, {158,38}, {173,38},           {196,38},           {224,38},
        {9,49},          {33,49}, {48,49}, {62,49}, {77,49}, {92,49}, {106,49}, {121,49}, {136,49}, {151,49}, {165,49},           {185,49}, {209,52},
        {2,61}, {20,61}, {39,61},                            {94,61},                               {147,61}, {162,61}, {176,61}, {195,64}, {209,64}, {224,64}
    },
	{
        // RGB LED Index to Flag
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,    1,
        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 1,
        1, 1, 1,          4,          1, 1, 1, 1, 1, 1
	}
};

#endif // RGB_MATRIX_ENABLE

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif
