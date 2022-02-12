/* Copyright 2017 Jason Williams (Wilba)
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
#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config =  { {
	{  0+17,  0+16,  0+15,  0+14,  0+13,  0+12,  0+11,  0+10,   0+9,  18+0,  18+1,  18+2,  18+3,  18+4 },
		{   0+7,   0+6,   0+5,   0+4,   0+3,   0+2,   0+1,   0+0,  18+9, 18+10, 18+11, 18+12, 18+13, 18+14 },
		{   0+8, 36+14, 36+13, 36+12, 36+11, 36+10,  36+9,  54+0,  54+1,  54+2,  54+3,  54+4,  54+5,  18+5 },
		{ 36+16, 36+15,  36+5,  36+4,  36+3,  36+2,  36+1,  54+9, 54+10, 54+11, 54+12,  54+6,  54+7,  54+8 },
		{ 36+17,  36+8,  36+7,  36+6,   255,   255,   255,  36+0,  255,  54+13, 54+14, 54+15, 54+16, 54+17 }
}, { 
	// LA0..LA17
	{120,16}, {104,16}, {88,16}, {72,16}, {56,16}, {40,16}, {24,16}, {4,16}, {4,32},
		{128,0}, {112,0}, {96,0}, {80,0}, {64,0}, {48,0}, {32,0}, {16,0}, {0,0},
		// LB0..LB17
		{144,0}, {160,0}, {176,0}, {192,0}, {216,0}, {224,0}, {255,255}, {255,255}, {255,255},
		{136,16}, {152,16}, {168,16}, {184,16}, {200,16}, {220,16}, {255,255}, {255,255}, {255,255},
		// LC0..LC17
		{102,64}, {100,48}, {84,48}, {68,48}, {52,48}, {36,48}, {60,64}, {43,64}, {23,64},
		{108,32}, {92,32}, {76,32}, {60,32}, {44,32}, {28,32}, {20,48}, {2,48}, {3,64},
		// LD0..LD17
		{124,32}, {140,32}, {156,32}, {172,32}, {188,32}, {214,32}, {180,48}, {210,48}, {224,48},
		{116,48}, {132,48}, {148,48}, {164,48}, {144,64}, {161,64}, {181,64}, {201,64}, {221,64}
}, {  
	1, 1, 1, 1, 1, 1, 1, 1,  1,  1,  1,  1,  1,  1,
		1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1 ,
		1, 1, 1, 1, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1,
		1, 1,  1,  1,  1,  1,  1,  1, 1, 1, 1,  1,  1,  1,
		1,  1,  1,  1,   1,   1,   1,  1,  1,  1, 1, 1, 1, 1 
}
};
#endif
// This is a 7-bit address, that gets left-shifted and bit 0
// set to 0 for write, 1 for read (as per I2C protocol)
#define ISSI_ADDR_1 0x74
#define ISSI_ADDR_2 0x76
const is31_led PROGMEM g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */

    {0, C2_1,  C3_1,  C4_1},  // LA0
    {0, C1_1,  C3_2, C4_2},   // LA1
    {0, C1_2,  C2_2, C4_3},   // LA2
    {0, C1_3,  C2_3, C3_3},   // LA3
    {0, C1_4,  C2_4, C3_4},   // LA4
    {0, C1_5,  C2_5, C3_5},   // LA5
    {0, C1_6,  C2_6, C3_6},   // LA6
    {0, C1_7,  C2_7, C3_7},   // LA7
    {0, C1_8,  C2_8, C3_8},   // LA8
    {0, C9_1,  C8_1, C7_1},   // LA9
    {0, C9_2,  C8_2, C7_2},   // LA10
    {0, C9_3,  C8_3, C7_3},   // LA11
    {0, C9_4,  C8_4, C7_4},   // LA12
    {0, C9_5,  C8_5, C7_5},   // LA13
    {0, C9_6,  C8_6, C7_6},   // LA14
    {0, C9_7,  C8_7, C6_6},   // LA15
    {0, C9_8,  C7_7, C6_7},   // LA16
    {0, C8_8,  C7_8, C6_8},   // LA17

    {0, C2_9,  C3_9,  C4_9},  // LB0
    {0, C1_9,  C3_10, C4_10}, // LB1
    {0, C1_10, C2_10, C4_11}, // LB2
    {0, C1_11, C2_11, C3_11}, // LB3
    {0, C1_12, C2_12, C3_12}, // LB4
    {0, C1_13, C2_13, C3_13}, // LB5
    {0, C1_14, C2_14, C3_14}, // LB6
    {0, C1_15, C2_15, C3_15}, // LB7
    {0, C1_16, C2_16, C3_16}, // LB8
    {0, C9_9,  C8_9,  C7_9},  // LB9
    {0, C9_10, C8_10, C7_10}, // LB10
    {0, C9_11, C8_11, C7_11}, // LB11
    {0, C9_12, C8_12, C7_12}, // LB12
    {0, C9_13, C8_13, C7_13}, // LB13
    {0, C9_14, C8_14, C7_14}, // LB14
    {0, C9_15, C8_15, C6_14}, // LB15
    {0, C9_16, C7_15, C6_15}, // LB16
    {0, C8_16, C7_16, C6_16}, // LB17

    {1, C2_1,  C3_1,  C4_1},  // LC0
    {1, C1_1,  C3_2, C4_2},   // LC1
    {1, C1_2,  C2_2, C4_3},   // LC2
    {1, C1_3,  C2_3, C3_3},   // LC3
    {1, C1_4,  C2_4, C3_4},   // LC4
    {1, C1_5,  C2_5, C3_5},   // LC5
    {1, C1_6,  C2_6, C3_6},   // LC6
    {1, C1_7,  C2_7, C3_7},   // LC7
    {1, C1_8,  C2_8, C3_8},   // LC8
    {1, C9_1,  C8_1,  C7_1},  // LC9
    {1, C9_2,  C8_2, C7_2},   // LC10
    {1, C9_3,  C8_3, C7_3},   // LC11
    {1, C9_4,  C8_4, C7_4},   // LC12
    {1, C9_5,  C8_5, C7_5},   // LC13
    {1, C9_6,  C8_6, C7_6},   // LC14
    {1, C9_7,  C8_7, C6_6},   // LC15
    {1, C9_8,  C7_7, C6_7},   // LC16
    {1, C8_8,  C7_8, C6_8},   // LC17

    {1, C2_9,  C3_9,  C4_9},  // LD0
    {1, C1_9,  C3_10, C4_10}, // LD1
    {1, C1_10, C2_10, C4_11}, // LD2
    {1, C1_11, C2_11, C3_11}, // LD3
    {1, C1_12, C2_12, C3_12}, // LD4
    {1, C1_13, C2_13, C3_13}, // LD5
    {1, C1_14, C2_14, C3_14}, // LD6
    {1, C1_15, C2_15, C3_15}, // LD7
    {1, C1_16, C2_16, C3_16}, // LD8
    {1, C9_9,  C8_9,  C7_9},  // LD9
    {1, C9_10, C8_10, C7_10}, // LD10
    {1, C9_11, C8_11, C7_11}, // LD11
    {1, C9_12, C8_12, C7_12}, // LD12
    {1, C9_13, C8_13, C7_13}, // LD13
    {1, C9_14, C8_14, C7_14}, // LD14
    {1, C9_15, C8_15, C6_14}, // LD15
    {1, C9_16, C7_15, C6_15}, // LD16
    {1, C8_16, C7_16, C6_16}, // LD17
};
