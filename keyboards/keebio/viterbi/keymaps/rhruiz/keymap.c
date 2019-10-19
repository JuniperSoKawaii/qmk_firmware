#include QMK_KEYBOARD_H

#include "rhruiz.h"

#define KC__FN1 MO(_FN1)
#define KC__FN2 MO(_FN2)
#define KC__DCF LT(_CFG, KC_DEL)
#define KC_RFN1 LT(_FN1, KC_RGHT)
#define KC_SFN1 SPCFN1
#define KC_BFN2 BKSFN2
#define KC__CFG MO(_CFG)
#define KC_RST RESET
#define KC__VUP KC__VOLUP
#define KC__VDN KC__VOLDOWN
#define KC_____ KC_TRNS
#define KC_CESC CTRLESC
#define KC_MISS MISCTRL

#ifdef RGBLIGHT_ENABLE
#    define KC_RVAD RGB_VAD
#    define KC_RVAI RGB_VAI
#else
#    define KC_RVAD KC_TRNS
#    define KC_RVAI KC_TRNS
#endif

// clang-format off

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},

    {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc(
    GRV , 1   , 2   , 3   , 4   , 5   , 6   ,   6   , 7   , 8   , 9   , 0   , MINS, EQL,
    TAB , Q   , W   , E   , R   , T   , LBRC,   RBRC, Y   , U   , I   , O   , P   , QUOT,
    CESC, A   , S   , D   , F   , G   , PGUP,   BSLS, H   , J   , K   , L   , SCLN, ENT,
    LSFT, Z   , X   , C   , V   , B   , PGDN,   ENT , N   , M   , COMM, DOT , SLSH, RSFT,
    _FN2, LCTL, LALT, LALT, LGUI, SFN1, SFN1,   BFN2, BFN2, RGUI, LEFT, DOWN, UP  , RFN1
  ),

  [_VIM_EMACS] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, UP  , ____,
    ____, ____, ____, ____, RGHT, ____, ____,   ____, LEFT, DOWN, UP  , RGHT, ____, ____,
    ____, ____, ____, ____, ____, LEFT, ____,   ____, DOWN, ENT , ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____
  ),

  [_MOUSE] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc(
    TILD, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, UNDS, PLUS,
    ____, ____, ____, ____, ____, ____, LCBR,   RCBR, ____, ____, ____, ____, ____, DQUO,
    ____, ____, ____, ____, ____, ____, ____,   PIPE, ____, ____, ____, ____, SCLN, PENT,
    ____, ____, ____, ____, ____, ____, ____,   PENT, ____, ____, LT  , GT  , QUES, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, MRWD, MPLY, MFFD, ____
  ),

  [_FN1] = LAYOUT_kc(
    ____, F1  , F2  , F3  , F4  , F5  , ____,   F6  , F7  , F8  , F9  , F10 , F11 , F12 ,
    ____, ____, ____, ____, LBRC, RBRC, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    _CFG, ____, ____, ____, ____, ____, ____,   _DCF, _DCF, ____, ____, ____, ____, ____
  ),

  [_FN2] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, BTN1, MS_U, BTN2, LCBR, RCBR, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, MS_L, MS_D, MS_R, ____, ____, WH_D,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, WH_U,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, _CFG, ____,   ____, ____, ____, ____, ____, ____, ____
  ),

  [_CFG] = LAYOUT_kc(
    ____, SLCK, PAUS, MISS, RVAD, RVAI, RST ,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, RST ,
    ____, _VUP, _VDN, MUTE, EJCT, ____, ____,   ____, HOME, PGDN, PGUP, END,  ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,   ____, ____, ____, ____, ____, ____, ____
  )
};

// clang-format on

void keyoard_post_init_user(void) { rhruiz_disable_promicro_leds(); }

uint32_t layer_state_set_user(uint32_t state) { return rhruiz_layer_state_set_user(state); }
