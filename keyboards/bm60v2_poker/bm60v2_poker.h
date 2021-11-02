#pragma once

#include "quantum.h"

#define LAYOUT_60_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,        \
    K10,   K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      \
    K20,    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2D,          \
    K30,       K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,        K3D,     \
    K40,  K41,  K42,              K45,                 K49,  K4A,   K4B,  K4D    \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D   }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D   }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D   }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   KC_NO, KC_NO, K3D   }, \
    { K40,   K41,   K42,   KC_NO, KC_NO, K45,   KC_NO, KC_NO, KC_NO, K49,   K4A,   K4B,   KC_NO, K4D   }, \
}

#if defined(RGB_MATRIX_DISABLE_KEYCODES)
#    ifndef RGB_MATRIX_TOGGLE
#        define RGB_MATRIX_TOGGLE   KC_F16
#    endif
#    ifndef RGB_MATRIX_STEP
#        define RGB_MATRIX_STEP     KC_F17
#    endif
#    ifndef RGB_MATRIX_INC_HUE
#        define RGB_MATRIX_INC_HUE  KC_F18
#    endif
#    ifndef RGB_MATRIX_DEC_HUE
#        define RGB_MATRIX_DEC_HUE  KC_F19
#    endif
#    ifndef RGB_MATRIX_INC_SAT
#        define RGB_MATRIX_INC_SAT  KC_F20
#    endif
#    ifndef RGB_MATRIX_DEC_SAT
#        define RGB_MATRIX_DEC_SAT  KC_F21
#    endif
#    ifndef RGB_MATRIX_INC_VAL
#        define RGB_MATRIX_INC_VAL  KC_F22
#    endif
#    ifndef RGB_MATRIX_DEC_VAL
#        define RGB_MATRIX_DEC_VAL  KC_F23
#    endif
#endif



