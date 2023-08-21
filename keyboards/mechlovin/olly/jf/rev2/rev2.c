/* Copyright 2022 Team Mechlovin
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

void board_init(void) {
    AFIO->MAPR |= AFIO_MAPR_SPI1_REMAP;
}

const is31_led PROGMEM g_is31_leds[LED_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *    driver
 *    |  LED address
 *    |  | */
    { 0, C1_8  },                { 0, C3_8 },  { 0, C4_8  },  { 0, C5_8 },  { 0, C6_8  },  { 0, C7_8 },  { 0, C8_8  },  { 0, C9_8 },  { 0, C1_9  },  { 0, C2_9  },  { 0, C3_9   },  { 0, C4_9  },  { 0, C5_9   },  { 0, C6_9  },  { 0, C7_9   },  { 0, C8_9  },  { 0, C9_9  },  { 0, C1_16 },
    { 0, C1_7  },  { 0, C2_7 },  { 0, C3_7 },  { 0, C4_7  },  { 0, C5_7 },  { 0, C6_7  },  { 0, C7_7 },  { 0, C8_7  },  { 0, C9_7 },  { 0, C1_10 },  { 0, C2_10 },  { 0, C3_10  },  { 0, C4_10 },  { 0, C5_10  },  { 0, C6_10 },  { 0, C7_10  },  { 0, C8_10 },  { 0, C9_10 },  { 0, C2_16 },
    { 0, C1_6  },  { 0, C2_6 },  { 0, C3_6 },  { 0, C4_6  },  { 0, C5_6 },  { 0, C6_6  },  { 0, C7_6 },  { 0, C8_6  },  { 0, C9_6 },  { 0, C1_11 },  { 0, C2_11 },  { 0, C3_11  },  { 0, C4_11 },  { 0, C5_11  },  { 0, C6_11 },  { 0, C7_11  },  { 0, C8_11 },  { 0, C9_11 },  { 0, C3_16 },
    { 0, C1_5  },  { 0, C2_5 },  { 0, C3_5 },  { 0, C4_5  },  { 0, C5_5 },  { 0, C6_5  },  { 0, C7_5 },  { 0, C8_5  },  { 0, C9_5 },  { 0, C1_12 },  { 0, C2_12 },  { 0, C3_12  },  { 0, C4_12 },  { 0, C5_12  },                 { 0, C7_12  },  { 0, C8_12 },  { 0, C9_12 },  { 0, C4_16 },
    { 0, C1_4  },  { 0, C2_4 },  { 0, C3_4 },  { 0, C4_4  },  { 0, C5_4 },  { 0, C6_4  },  { 0, C7_4 },  { 0, C8_4  },  { 0, C9_4 },  { 0, C1_13 },  { 0, C2_13 },  { 0, C3_13  },  { 0, C4_13 },  { 0, C5_13  },  { 0, C6_13 },  { 0, C7_13  },  { 0, C8_13 },  { 0, C9_13 },  { 0, C5_16 },
    { 0, C1_3  },  { 0, C2_3 },                { 0, C4_3  },                               { 0, C7_3 },                                              { 0, C2_14 },  { 0, C3_14  },  { 0, C4_14 },  { 0, C5_14  },  { 0, C6_14 },  { 0, C7_14  },  { 0, C8_15 },  { 0, C9_15 },  { 0, C7_16 },
    { 0, C2_1  },  { 0, C1_1 },  { 0, C9_1 },  // Lock LED Indicator
    { 0, C7_15 },  { 0, C6_15 }, { 0, C9_16 }, { 0, C8_16 }, { 0, C1_15 }, // Layer LED Indicator
};

led_config_t g_led_config = {
{
        // Key Matrix to LED Index
    { 0,        NO_LED,             1,             2,             3,             4,             5,             6,             7,             8,             9,            10,            11,            12,            13,            14,             15,             16,             17},
    {18,            19,            20,            21,            22,            23,            24,            25,            26,            27,            28,            29,            30,            31,            32,            33,             34,             35,             36},
    {37,            38,            39,            40,            41,            42,            43,            44,            45,            46,            47,            48,            49,            50,            51,            52,             53,             54,             55},
    {56,            57,            58,            59,            60,            61,            65,            63,            64,            65,            66,            67,            68,            69,        NO_LED,            70,             71,             72,             73},
    {74,            75,            76,            77,            78,            79,            80,            81,            82,            83,            84,            85,            86,            87,            88,            89,             90,             91,             92},
    {93,            94,        NO_LED,            95,        NO_LED,        NO_LED,            96,        NO_LED,        NO_LED,        NO_LED,            97,            98,            99,            100,           101,           102,            103,            104,            105},
}, {
        //LED Index to Physical Positon
  {0, 0},                    {24,  0},      {37,  0},      {49,  0},      {62,  0},      {74,  0},       {87, 0},       {99, 0},       {112, 0},      {124, 0},      {137, 0},      {149, 0},      {162, 0},      {174, 0},      {186, 0},       {199, 0},       {211, 0},       {224, 0},
  {0,13},     {12, 13},      {24, 13},      {37, 13},      {49, 13},      {62, 13},      {74, 13},       {87,13},       {99,13},       {112,13},      {124,13},      {137,13},      {149,13},      {162,13},      {174,13},      {186,13},       {199,13},       {211,13},       {224,13},
  {0,25},     {12, 25},      {24, 25},      {37, 25},      {49, 25},      {62, 25},      {74, 25},       {87,25},       {99,25},       {112,25},      {124,25},      {137,25},      {149,25},      {162,25},      {174,25},      {186,25},       {199,25},       {211,25},       {224,25},
  {0,38},     {12, 38},      {24, 38},      {37, 38},      {49, 38},      {62, 38},      {74, 38},       {87,38},       {99,38},       {112,38},      {124,38},      {137,38},      {149,38},      {162,38},                     {186,38},       {199,38},       {211,38},       {224,38},
  {0,51},     {12, 51},      {24, 51},      {37, 51},      {49, 51},      {62, 51},      {74, 51},       {87,51},       {99,51},       {112,51},      {124,51},      {137,51},      {149,51},      {162,51},      {174,51},      {186,51},       {199,51},       {211,51},       {224,51},
  {0,64},     {12, 64},                     {37, 64},                                    {74, 64},                                                    {124,64},      {137,64},      {149,64},      {162,64},      {174,64},      {186,64},       {199,64},       {211,64},       {224,64},
    }, {
       1,                           1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,
       1,            1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,
       1,            1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,
       1,            1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,                            1,             1,             1,             1,
       1,            1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,             1,
       1,            1,                            1,                                           1,                                                          1,             1,             1,             1,             1,             1,             1,             1,             1,
    } 
};


bool led_matrix_indicators_kb(void) {
    if (!led_matrix_indicators_user()) { return false; }
    if (host_keyboard_led_state().caps_lock) {
        led_matrix_set_value(106, 0xFF);
        led_matrix_set_value(56, 0xFF);
    } else {
        led_matrix_set_value(106, 0x00);
    }
    if (host_keyboard_led_state().num_lock) {
        led_matrix_set_value(107, 0xFF);
        led_matrix_set_value(33, 0xFF);
    } else {
        led_matrix_set_value(107, 0x00);
    }
    if (host_keyboard_led_state().scroll_lock) {
        led_matrix_set_value(108, 0xFF);
    } else {
        led_matrix_set_value(108, 0x00);
    }
    return true;
}


layer_state_t layer_state_set_kb(layer_state_t state) {
  // if on layer 1, turn on L1 LED, otherwise off.
    if (get_highest_layer(state) == 0) {
        led_matrix_set_value(109, 0xFF);
    } else {
        led_matrix_set_value(109, 0x00);
    }
  // if on layer 2, turn on L2 LED, otherwise off.
    if (get_highest_layer(state) == 1) {
        led_matrix_set_value(110, 0xFF);
    } else {
        led_matrix_set_value(110, 0x00);
    }

  // if on layer 3, turn on L3 LED, otherwise off.
    if (get_highest_layer(state) == 2) {
        led_matrix_set_value(111, 0xFF);
    } else {
        led_matrix_set_value(111, 0x00);
    }

  // if on layer 4, turn on L4 LED, otherwise off.
    if (get_highest_layer(state) == 3) {
        led_matrix_set_value(112, 0xFF);
    } else {
        led_matrix_set_value(112, 0x00);
    }
  // if on layer 5, turn on L5 LED, otherwise off.
    if (get_highest_layer(state) == 4) {
        led_matrix_set_value(113, 0xFF);
    } else {
        led_matrix_set_value(114, 0x00);
    }
    return layer_state_set_user(state);
}