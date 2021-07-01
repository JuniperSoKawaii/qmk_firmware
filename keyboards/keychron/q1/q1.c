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

#include "q1.h"


void set_target_os(bool layer)
{
	if(layer)
	{
		layer_off(2);
	}
	else
	{
		layer_on(2);
	}
}

void dip_switch_update_kb(uint8_t index, bool active) 
{ 
    if(index == 0)
	{
		set_target_os(!active);
    }
}

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */

    {0, A_1,    C_1,    B_1},
    {0, A_3,    C_3,    B_3},
    {0, A_4,    C_4,    B_4},
    {0, A_5,    C_5,    B_5},
    {0, A_6,    C_6,    B_6},
    {0, A_7,    C_7,    B_7},
    {0, A_8,    C_8,    B_8},
    {0, A_9,    C_9,    B_9},   
    {0, A_10,   C_10,   B_10},
    {0, A_11,   C_11,   B_11},
    {0, A_12,   C_12,   B_12},
    {0, A_13,   C_13,   B_13},
    {0, A_14,   C_14,   B_14},
    {0, A_15,   C_15,   B_15},
    {0, A_16,   C_16,   B_16},

    {0, D_1,    F_1,    E_1},
    {0, D_2,    F_2,    E_2},
    {0, D_3,    F_3,    E_3}, 
    {0, D_4,    F_4,    E_4},
    {0, D_5,    F_5,    E_5},
    {0, D_6,    F_6,    E_6},
    {0, D_7,    F_7,    E_7},
    {0, D_8,    F_8,    E_8},
    {0, D_9,    F_9,    E_9},
    {0, D_10,   F_10,   E_10},
    {0, D_11,   F_11,   E_11},
    {0, D_12,   F_12,   E_12},
    {0, D_13,   F_13,   E_13},
    {0, D_14,   F_14,   E_14},
    {0, D_16,   F_16,   E_16},

    {0, G_1,    I_1,    H_1},
    {0, G_2,    I_2,    H_2},
    {0, G_3,    I_3,    H_3},
    {0, G_4,    I_4,    H_4},
    {0, G_5,    I_5,    H_5},
    {0, G_6,    I_6,    H_6},
    {0, G_7,    I_7,    H_7},
    {0, G_8,    I_8,    H_8},
    {0, G_9,    I_9,    H_9},
    {0, G_10,   I_10,   H_10},
    {0, G_11,   I_11,   H_11},
    {0, G_12,   I_12,   H_12},
    {0, G_13,   I_13,   H_13},
    {0, G_14,   I_14,   H_14},
    {0, G_16,   I_16,   H_16}, 
    
    {0, J_1,    L_1,    K_1},
    {0, J_2,    L_2,    K_2},
    {0, J_3,    L_3,    K_3},
    {0, J_4,    L_4,    K_4},
    {0, J_5,    L_5,    K_5},
    {0, J_6,    L_6,    K_6},
    {0, J_7,    L_7,    K_7},
    {0, J_8,    L_8,    K_8},
    {0, J_9,    L_9,    K_9},
    {0, J_10,   L_10,   K_10},
    {0, J_11,   L_11,   K_11},
    {0, J_12,   L_12,   K_12},
    {0, J_14,   L_14,   K_14},
    {0, J_16,   L_16,   K_16},
    {1, A_1,    C_1,    B_1},

    {1, A_3,    C_3,    B_3},
    {1, A_4,    C_4,    B_4},
    {1, A_5,    C_5,    B_5},
    {1, A_6,    C_6,    B_6},
    {1, A_7,    C_7,    B_7},
    {1, A_8,    C_8,    B_8},
    {1, A_9,    C_9,    B_9},
    {1, A_10,   C_10,   B_10},
    {1, A_11,   C_11,   B_11},
    {1, A_12,   C_12,   B_12},
    {1, A_14,   C_14,   B_14},
    {1, A_15,   C_15,   B_15},
                                   
    {1, D_1,    F_1,    E_1},
    {1, D_2,    F_2,    E_2},
    {1, D_3,    F_3,    E_3},
    {1, D_7,    F_7,    E_7},
    {1, D_11,   F_11,   E_11},
    {1, D_12,   F_12,   E_12},
    {1, D_13,   F_13,   E_13}, 
    {1, D_14,   F_14,   E_14}, 
    {1, D_15,   F_15,   E_15},
    {1, D_16,   F_16,   E_16}

};

led_config_t g_led_config = {
	{
		{   0,     NO_LED,  1,      2,      3,      4,     5,      6,      7,      8,      9,     10,     11,      12,     14   },
		{  15,     16,     17,     18,     19,     20,    21,     22,     23,     24,     25,     26,     27,      28,     29   },
		{  30,     31,     32,     33,     34,     35,    36,     37,     38,     39,     40,     41,     42,      43,     44   },
		{  45,     46,     47,     48,     49,     50,    51,     52,     53,     54,     55,     56,     71,      57,     58   },
		{  59,     NO_LED, 60,     61,     62,     63,    64,     65,     66,     67,     68,     69,     80,      70,     13   },
		{  72,     73,     74,     NO_LED, NO_LED, NO_LED,75,     NO_LED, NO_LED, NO_LED, 76,     77,     78,      79,     81   }
	},
	{
		{0,0},           {30, 0}, {45, 0}, {60, 0}, {75, 0}, {90, 0}, {105, 0}, {120, 0}, {135, 0}, {150, 0}, {165, 0}, {180, 0}, {195, 0}, {210, 0}, {224, 0},
	    {0,13}, {15,13}, {30,13}, {45,13}, {60,13}, {75,13}, {90,13}, {105,13}, {120,13}, {135,13}, {150,13}, {165,13}, {180,13}, {195,13},           {224,13},
	    {0,26}, {15,26}, {30,26}, {45,26}, {60,26}, {75,26}, {90,26}, {105,26}, {120,26}, {135,26}, {150,26}, {165,26}, {180,26}, {195,26},           {224,26},
	    {0,39}, {15,39}, {30,39}, {45,39}, {60,39}, {75,39}, {90,39}, {105,39}, {120,39}, {135,39}, {150,39}, {165,39},           {195,39},           {224,39},
	    {0,52},          {30,52}, {45,52}, {60,52}, {75,52}, {90,52}, {105,52}, {120,52}, {135,52}, {150,52}, {165,52},           {195,52}, {210,52}, 
	    {0,64}, {15,64}, {30,64},                            {90,64},                               {150,64}, {165,64}, {180,64}, {195,64}, {210,64}, {224,64},
	},
	{
		4,			4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,
		4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,		  4,
		4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,		  4,
		4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,		  4,		  4,
		4,			4,	  4,	4,	  4,	4,	  4,	4,	  4,	4,	  4,		  4,	4,	  
		4,	  4,	4,						4,						4,	  4,	4,	  4,	4,	  4

	}
};

