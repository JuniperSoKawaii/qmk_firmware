/* Copyright 2020 Kyle McCreery 
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
#pragma once

#include "quantum.h"

#define _x_ KC_NO


#define LAYOUT_ansi_split_space( \
                                                         KEN, \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,      K1B, \
  K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
  K30, K31, K32,      K34,      K36, K37,      K39, K3A, K3B  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16 }, \
	{ K20,   _x_,   K3B,   K23,   K24,   K25,   K26 }, \
	{ K30,   K32,   K3A,   K39,   K34,   K36,   K37 }, \
	{ _x_,   _x_,   KEN,   K0A,   K09,   K08,   K07 }, \
	{ _x_,   K31,   K0B,   K1B,   K19,   K18,   K17 }, \
	{ _x_,   K22,   K2B,   K2A,   K29,   K28,   K27 }  \
}
