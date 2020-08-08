#include "boboysdadda.h"

#define LAYOUT_nyquist_base( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
    ) \
    LAYOUT_wrapper( \
        KC_GRV,          K01,     K02,     K03,     K04,     K05,   K06,    K07,    K08,   K09,     K0A,     KC_BSPC,  \
        KC_TAB,          K11,     K12,     K13,     K14,     K15,   K16,    K17,    K18,   K19,     K1A,     KC_DEL, \
        LSFT_T(KC_ESC),  K21,     K22,     K23,     K24,     K25,   K26,    K27,    K28,   K29,     K2A,     KC_QUOT, \
        KC_LCTRL,        K31,     K32,     K33,     K34,     K35,   K36,    K37,    K38,   K39,     K3A,     KC_ENT, \
        CP_PST,          KC_LEAD, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_ENT, RAISE, DM_PLY1, DM_PLY2, _______, _______ \
    )
#define LAYOUT_nyquist_base_wrapper(...) LAYOUT_nyquist_base(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_nyquist_base_wrapper(
          ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
          _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
          _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
          _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
      ),

    [_DVORAK] = LAYOUT_nyquist_base_wrapper(
          ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
          _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
          _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
          _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
      ),
    [_LOWER] = LAYOUT_wrapper( \
          _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
          _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______,
          _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, KC_PIPE,
          _______, _________________LOWER_L4__________________, _________________LOWER_R4__________________, _______,
          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

      [_RAISE] = LAYOUT_wrapper( \
          XXXXXXX, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
          _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
          _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, KC_BSLS,
          _______, _________________RAISE_L4__________________, _________________RAISE_R3__________________, _______,
          _______, _______, _______, _______, _______, _______, DM_RSTP, _______, DM_REC1, DM_REC2, _______, _______
      ),
      [_ADJUST] = LAYOUT_wrapper( \
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
        KC_MAKE, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, KC_RST,
        VRSN,    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, EEP_RST,
        MG_NKRO, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, RGB_IDL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
