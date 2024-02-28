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

// clang-format off

const snled27351_led_t PROGMEM g_snled27351_leds[SNLED27351_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, CB3_CA1,    CB1_CA1,    CB2_CA1},
    {0, CB3_CA2,    CB1_CA2,    CB2_CA2},
    {0, CB3_CA3,    CB1_CA3,    CB2_CA3},
    {0, CB3_CA4,    CB1_CA4,    CB2_CA4},
    {0, CB3_CA5,    CB1_CA5,    CB2_CA5},
    {0, CB3_CA6,    CB1_CA6,    CB2_CA6},
    {0, CB3_CA7,    CB1_CA7,    CB2_CA7},
    {0, CB3_CA8,    CB1_CA8,    CB2_CA8},
    {0, CB3_CA9,    CB1_CA9,    CB2_CA9},
    {0, CB3_CA10,   CB1_CA10,   CB2_CA10},
    {0, CB3_CA11,   CB1_CA11,   CB2_CA11},
    {0, CB3_CA12,   CB1_CA12,   CB2_CA12},
    {0, CB3_CA13,   CB1_CA13,   CB2_CA13},
    {0, CB3_CA14,   CB1_CA14,   CB2_CA14},
    {0, CB3_CA16,   CB1_CA16,   CB2_CA16},

    {0, CB9_CA1,    CB7_CA1,    CB8_CA1},
    {0, CB9_CA2,    CB7_CA2,    CB8_CA2},
    {0, CB9_CA3,    CB7_CA3,    CB8_CA3},
    {0, CB9_CA4,    CB7_CA4,    CB8_CA4},
    {0, CB9_CA5,    CB7_CA5,    CB8_CA5},
    {0, CB9_CA6,    CB7_CA6,    CB8_CA6},
    {0, CB9_CA7,    CB7_CA7,    CB8_CA7},
    {0, CB9_CA8,    CB7_CA8,    CB8_CA8},
    {0, CB9_CA9,    CB7_CA9,    CB8_CA9},
    {0, CB9_CA10,   CB7_CA10,   CB8_CA10},
    {0, CB9_CA11,   CB7_CA11,   CB8_CA11},
    {0, CB9_CA12,   CB7_CA12,   CB8_CA12},
    {0, CB9_CA13,   CB7_CA13,   CB8_CA13},
    {0, CB9_CA14,   CB7_CA14,   CB8_CA14},
    {0, CB9_CA15,   CB7_CA15,   CB8_CA15},
    {0, CB9_CA16,   CB7_CA16,   CB8_CA16},

    {0, CB6_CA1,    CB4_CA1,    CB5_CA1},
    {0, CB6_CA2,    CB4_CA2,    CB5_CA2},
    {0, CB6_CA3,    CB4_CA3,    CB5_CA3},
    {0, CB6_CA4,    CB4_CA4,    CB5_CA4},
    {0, CB6_CA5,    CB4_CA5,    CB5_CA5},
    {0, CB6_CA6,    CB4_CA6,    CB5_CA6},
    {0, CB6_CA7,    CB4_CA7,    CB5_CA7},
    {0, CB6_CA8,    CB4_CA8,    CB5_CA8},
    {0, CB6_CA9,    CB4_CA9,    CB5_CA9},
    {0, CB6_CA10,   CB4_CA10,   CB5_CA10},
    {0, CB6_CA11,   CB4_CA11,   CB5_CA11},
    {0, CB6_CA12,   CB4_CA12,   CB5_CA12},
    {0, CB6_CA13,   CB4_CA13,   CB5_CA13},
    {0, CB6_CA16,   CB4_CA16,   CB5_CA16},

    {1, CB9_CA1,    CB7_CA1,    CB8_CA1},
    {1, CB9_CA2,    CB7_CA2,    CB8_CA2},
    {1, CB9_CA3,    CB7_CA3,    CB8_CA3},
    {1, CB9_CA4,    CB7_CA4,    CB8_CA4},
    {1, CB9_CA5,    CB7_CA5,    CB8_CA5},
    {1, CB9_CA6,    CB7_CA6,    CB8_CA6},
    {1, CB9_CA7,    CB7_CA7,    CB8_CA7},
    {1, CB9_CA8,    CB7_CA8,    CB8_CA8},
    {1, CB9_CA9,    CB7_CA9,    CB8_CA9},
    {1, CB9_CA10,   CB7_CA10,   CB8_CA10},
    {1, CB9_CA11,   CB7_CA11,   CB8_CA11},
    {1, CB9_CA12,   CB7_CA12,   CB8_CA12},
    {1, CB9_CA14,   CB7_CA14,   CB8_CA14},
    {0, CB6_CA14,   CB4_CA14,   CB5_CA14},
    {1, CB9_CA16,   CB7_CA16,   CB8_CA16},

    {1, CB6_CA1,    CB4_CA1,    CB5_CA1},
    {1, CB6_CA3,    CB4_CA3,    CB5_CA3},
    {1, CB6_CA4,    CB4_CA4,    CB5_CA4},
    {1, CB6_CA5,    CB4_CA5,    CB5_CA5},
    {1, CB6_CA6,    CB4_CA6,    CB5_CA6},
    {1, CB6_CA7,    CB4_CA7,    CB5_CA7},
    {1, CB6_CA8,    CB4_CA8,    CB5_CA8},
    {1, CB6_CA9,    CB4_CA9,    CB5_CA9},
    {1, CB6_CA10,   CB4_CA10,   CB5_CA10},
    {1, CB6_CA11,   CB4_CA11,   CB5_CA11},
    {1, CB6_CA12,   CB4_CA12,   CB5_CA12},
    {1, CB6_CA13,   CB4_CA13,   CB5_CA13},
    {1, CB6_CA14,   CB4_CA14,   CB5_CA14},
    {1, CB6_CA15,   CB4_CA15,   CB5_CA15},

    {1, CB3_CA1,    CB1_CA1,    CB2_CA1},
    {1, CB3_CA2,    CB1_CA2,    CB2_CA2},
    {1, CB3_CA3,    CB1_CA3,    CB2_CA3},
    {1, CB3_CA4,    CB1_CA4,    CB2_CA4},
    {1, CB3_CA7,    CB1_CA7,    CB2_CA7},
    {1, CB3_CA10,   CB1_CA10,   CB2_CA10},
    {1, CB3_CA11,   CB1_CA11,   CB2_CA11},
    {1, CB3_CA12,   CB1_CA12,   CB2_CA12},
    {1, CB3_CA13,   CB1_CA13,   CB2_CA13},
    {1, CB3_CA14,   CB1_CA14,   CB2_CA14},
    {1, CB3_CA15,   CB1_CA15,   CB2_CA15},
    {1, CB3_CA16,   CB1_CA16,   CB2_CA16},
};

#define __ NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, __, 14 },
        { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 },
        { 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 58, __, 44 },
        { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, __, 57, __, 59 },
        { 60, __, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, __ },
        { 74, 75, 76, 77, __, __, 78, __, __, 79, 80, 81, 82, 83, 84, 85 },
    },
    {
        // LED Index to Physical Position
        {0,  0},           {18,  0}, {33,  0}, {48,  0}, {62,  0}, {81,  0}, {95,   0}, {110,  0}, {125,  0}, {143,  0}, {158,  0}, {173,  0}, {187,  0}, {205,  0}, {224,  0},
        {0, 15}, {15, 15}, {29, 15}, {44, 15}, {59, 15}, {73, 15}, {88, 15}, {103, 15}, {117, 15}, {132, 15}, {147, 15}, {161, 15}, {176, 15}, {191, 15}, {205, 15}, {224, 15},
        {4, 28}, {22, 28}, {37, 28}, {51, 28}, {66, 28}, {81, 28}, {95, 28}, {110, 28}, {125, 28}, {139, 28}, {154, 28}, {169, 28}, {183, 28},                       {224, 28},
        {6, 40}, {26, 40}, {40, 40}, {55, 40}, {70, 40}, {84, 40}, {99, 40}, {114, 40}, {128, 40}, {143, 40}, {158, 40}, {172, 40}, {187, 40}, {207, 36},            {224, 40},
        {9, 52},           {33, 52}, {48, 52}, {62, 52}, {77, 52}, {92, 52}, {106, 52}, {121, 52}, {136, 52}, {150, 52}, {165, 52}, {180, 52}, {194, 52}, {209, 52},
        {2, 64}, {18, 64}, {35, 64},                     {51, 64},                      { 92, 64}, {134, 64}, {150, 64}, {165, 64}, {180, 64}, {194, 64}, {209, 64}, {224, 64},
    },
    {
        // RGB LED Index to Flag
        1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,       1,
        8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,
        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
        1, 1, 1, 1,       4,       1, 1, 1, 1, 1, 1, 1,
    }
};

#endif // RGB_MATRIX_ENABLE
