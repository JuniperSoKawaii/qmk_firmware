/* Copyright 2021 jfescobar18
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

#define LAYOUT_all( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2E,      \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3E,      \
  K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4E,      \
       K51, K52,                K56,           K59, K5A                      \
) \
{ \
  { K00,   K01, K02, K03,   K04,   K05,   K06, K07,   K08,   K09,   K0A, K0B,   K0C,   K0D,   K0E   }, \
  { K10,   K11, K12, K13,   K14,   K15,   K16, K17,   K18,   K19,   K1A, K1B,   K1C,   K1D,   KC_NO }, \
  { K20,   K21, K22, K23,   K24,   K25,   K26, K27,   K28,   K29,   K2A, K2B,   K2C,   KC_NO, K2E   }, \
  { K30,   K31, K32, K33,   K34,   K35,   K36, K37,   K38,   K39,   K3A, K3B,   K3C,   KC_NO, KC_NO }, \
  { K40,   K41, K42, K43,   K44,   K45,   K46, K47,   K48,   K49,   K4A, K4B,   K4C,   KC_NO, K4E   }, \
  { KC_NO, K51, K52, KC_NO, KC_NO, KC_NO, K56, KC_NO, KC_NO, K59,   K5A, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

#define LAYOUT_ISO( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K01, K18, K19, K1A, K1B, K1C,    K1D,   \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,    K2E,   \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C,           \
  K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,   K4C,    K4E, \
       K51, K52,                K56,           K59, K5A                      \
) \
{ \
  { K00,   K01, K02, K03,   K04,   K05,   K06, K07,   K08,   K09,   K0A, K0B,   K0C,   K0D,   K0E   }, \
  { K10,   K11, K12, K13,   K14,   K15,   K16, K17,   K18,   K19,   K1A, K1B,   K1C,   K1D,   KC_NO }, \
  { K20,   K21, K22, K23,   K24,   K25,   K26, K27,   K28,   K29,   K2A, K2B,   K2C,   KC_NO, K2E   }, \
  { K30,   K31, K32, K33,   K34,   K35,   K36, K37,   K38,   K39,   K3A, K3B,   K3C,   KC_NO, KC_NO }, \
  { K40,   K41, K42, K43,   K44,   K45,   K46, K47,   K48,   K49,   K4A, K4B,   K4C,   KC_NO, K4E   }, \
  { KC_NO, K51, K52, KC_NO, KC_NO, KC_NO, K56, KC_NO, KC_NO, K59,   K5A, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

#define LAYOUT_ANSI( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,    K1D,   \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,    K2E,   \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,      \
  K40,      K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C,      K4E, \
       K51, K52,                K56,           K59, K5A                      \
) \
{ \
  { K00,   K01,   K02, K03,   K04,   K05,   K06, K07,   K08,   K09,   K0A, K0B,   K0C,   K0D,   K0E   }, \
  { K10,   K11,   K12, K13,   K14,   K15,   K16, K17,   K18,   K19,   K1A, K1B,   K1C,   K1D,   KC_NO }, \
  { K20,   K21,   K22, K23,   K24,   K25,   K26, K27,   K28,   K29,   K2A, K2B,   K2C,   KC_NO, K2E   }, \
  { K30,   K31,   K32, K33,   K34,   K35,   K36, K37,   K38,   K39,   K3A, K3B,   K3C,   KC_NO, KC_NO }, \
  { K40,   KC_NO, K42, K43,   K44,   K45,   K46, K47,   K48,   K49,   K4A, K4B,   K4C,   KC_NO, K4E   }, \
  { KC_NO, K51,   K52, KC_NO, KC_NO, KC_NO, K56, KC_NO, KC_NO, K59,   K5A, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

#define LAYOUT_ANSI_Splitted_Backspace( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,    K2E,   \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,      \
  K40,      K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C,      K4E, \
       K51, K52,                K56,           K59, K5A                      \
) \
{ \
  { K00,   K01,   K02, K03,   K04,   K05,   K06, K07,   K08,   K09,   K0A, K0B,   K0C,   K0D,   K0E   }, \
  { K10,   K11,   K12, K13,   K14,   K15,   K16, K17,   K18,   K19,   K1A, K1B,   K1C,   K1D,   K1E   }, \
  { K20,   K21,   K22, K23,   K24,   K25,   K26, K27,   K28,   K29,   K2A, K2B,   K2C,   KC_NO, K2E   }, \
  { K30,   K31,   K32, K33,   K34,   K35,   K36, K37,   K38,   K39,   K3A, K3B,   K3C,   KC_NO, KC_NO }, \
  { K40,   KC_NO, K42, K43,   K44,   K45,   K46, K47,   K48,   K49,   K4A, K4B,   K4C,   KC_NO, K4E   }, \
  { KC_NO, K51,   K52, KC_NO, KC_NO, KC_NO, K56, KC_NO, KC_NO, K59,   K5A, KC_NO, KC_NO, KC_NO, KC_NO }  \
}

#define LAYOUT_Alps_Big_Ass_Enter( \
  K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, \
  K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
  K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,           \
  K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3C,      \
  K40,      K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C,      K4E, \
       K51, K52,                K56,           K59, K5A                      \
) \
{ \
  { K00,   K01,   K02, K03,   K04,   K05,   K06, K07,   K08,   K09,   K0A, K0B,   K0C,   K0D,   K0E   }, \
  { K10,   K11,   K12, K13,   K14,   K15,   K16, K17,   K18,   K19,   K1A, K1B,   K1C,   K1D,   K1E   }, \
  { K20,   K21,   K22, K23,   K24,   K25,   K26, K27,   K28,   K29,   K2A, K2B,   K2C,   KC_NO, KC_NO }, \
  { K30,   K31,   K32, K33,   K34,   K35,   K36, K37,   K38,   K39,   K3A, K3B,   K3C,   KC_NO, KC_NO }, \
  { K40,   KC_NO, K42, K43,   K44,   K45,   K46, K47,   K48,   K49,   K4A, K4B,   K4C,   KC_NO, K4E   }, \
  { KC_NO, K51,   K52, KC_NO, KC_NO, KC_NO, K56, KC_NO, KC_NO, K59,   K5A, KC_NO, KC_NO, KC_NO, KC_NO }  \
}
