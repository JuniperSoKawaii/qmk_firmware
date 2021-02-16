#pragma once

#include "quantum.h"

#define LAYOUT_60_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K4C, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K3C, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2C, \
    K30,      K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,      K3B, \
    K40, K41, K42,                K45,                K46, K47, K48, K49  \
    ) { \
  {  K00,  K01,  K02,  K03,    K04,    K05,  K06,    K07,    K08,    K09,    K0A,    K0B,    K0C }, \
  {  K10,  K11,  K12,  K13,    K14,    K15,  K16,    K17,    K18,    K19,    K1A,    K1B,    K1C }, \
  {  K20,  K21,  K22,  K23,    K24,    K25,  K26,    K27,    K28,    K29,    K2A,    K2B,    K2C }, \
  {  K30,  K31,  K32,  K33,    K34,    K35,  K36,    K37,    K38,    K39,    K3A,    K3B,    K3C }, \
  {  K40,  K41,  K42,  KC_NO,  KC_NO,  K45,  K46,    K47,    K48,    K49,    KC_NO,  KC_NO,  K4C }  \
}
