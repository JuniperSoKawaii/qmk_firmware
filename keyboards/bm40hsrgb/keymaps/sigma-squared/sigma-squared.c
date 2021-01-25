// qmk flash -kb bm40hsrgb -km sigma-squared

#include "sigma-squared.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_sigma2(
    //KC_LALT,           KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           KC_LALT,
    //KC_LSFT,           KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              KC_LSFT,
    //KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_LCTL,
    //G(KC_TAB),         (G(S(KC_S))),      KC_TAB,            LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),         LT(NSSL, KC_ENT),              LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_LGUI,           C(G(KC_LEFT)),     C(G(KC_RIGHT))
    KC_LALT,           KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              KC_LALT,
    KC_LSFT,           KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           KC_LSFT,
    KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_LCTL,
    G(KC_TAB),         (G(S(KC_S))),      KC_ESC,            LT(MEDR, KC_TAB),  LT(NAVR, KC_SPC),         LT(NSSL, KC_ENT),              LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_LGUI,           C(KC_GRV),         C(KC_TAB)
  ),

//layers
  [NAVR] = LAYOUT_sigma2(
    KC_LALT, KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   C(S(KC_Z)), C(KC_Z), C(KC_X),  C(KC_C), C(KC_V),  KC_LALT,
    KC_LSFT, G(S(C(KC_F1))), KC_LALT, KC_LCTL, G(S(C(KC_F2))), KC_NA,   KC_CLCK, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_LSFT,
    KC_LCTL, KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_LCTL,
    TG(GAME),KC_NP,   KC_NP,   KC_NA,   KC_NA,       KC_ENT,       KC_BSPC, KC_DEL,  KC_NP,   C(G(KC_LEFT)), C(G(KC_RIGHT))
  ),
  [MEDR] = LAYOUT_sigma2(
    KC_LALT, KC_RST,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,  KC_LALT,
    KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NA,   KC_NU,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_LSFT,
    KC_LCTL, KC_NA,   KC_ALGR, KC_NA,   KC_NA,   KC_NA,   KC_NU,   KC_F13,  KC_F14,  KC_F15,  RGB_VAI,   KC_LCTL,
    KC_NP,   KC_NP,   KC_NP,  KC_NA,   KC_NA,       KC_MSTP,       KC_MPLY, KC_MUTE, KC_NP,   KC_NP,   KC_NP
  ),
  [FUNL] = LAYOUT_sigma2(
    KC_LALT, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,  KC_LALT,
    KC_LSFT, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,
    KC_LCTL, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,   KC_LCTL,
    KC_NP,   KC_NP,   KC_TAB,  KC_APP,  KC_SPC,      KC_UNDS,      KC_NA,   KC_NA,   KC_NP,   KC_NP,   KC_NP
  ),
  [NSL] = LAYOUT_sigma2(
    KC_LALT, KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN, KC_LBRC, KC_AMPR,  KC_ASTR, KC_LCBR,   KC_RBRC,     KC_BSPC,
    KC_LSFT, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_LCBR, KC_DLR,   KC_PERC, KC_CIRC,   KC_RCBR,     KC_LSFT,
    KC_LCTL, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TILD, KC_EXLM,  KC_COMM, KC_DOT,    KC_SLSH,     KC_LCTL,
    KC_NP,   C((G(S(KC_S)))),   KC_NP, KC_UNDS,  KC_0,        KC_MINS,       KC_NA,    KC_NA,   KC_NA,     KC_NP,       KC_NP
  ),
  [NSSL] = LAYOUT_sigma2(
    KC_LALT, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,  KC_BSPC,
    KC_LSFT, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NA,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_LSFT,
    KC_LCTL, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NA,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_LCTL,
    KC_NP,   KC_NP,   KC_UNDS, KC_GT,   KC_RPRN,      KC_NA,       KC_BTN1, KC_BTN3, KC_BTN2, KC_NP,   KC_NP
  ),
  [GAME] = LAYOUT_sigma2(
    KC_ESC,   KC_Q,       KC_W,         KC_E,    KC_R,    KC_T,       KC_Y,       KC_U,    KC_I,    KC_O,     KC_P,    TG(GAME),
    KC_LALT,  KC_A,       KC_S,         KC_D,    KC_F,    KC_G,       KC_H,       KC_J,    KC_K,    KC_L,     KC_QUOT, KC_LSFT,
    KC_LSFT,  KC_Z,       KC_X,         KC_C,    KC_V,    KC_B,       KC_N,       KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_LCTL,
    KC_LCTL,  A(KC_TAB),  MO(SECGAME),  KC_TAB,  KC_SPC,  LT(SECGAME, KC_ENT),    KC_BSPC,  KC_DEL,  KC_MPLY,  KC_MPRV,  KC_MNXT
  ),
  [SECGAME] = LAYOUT_sigma2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NA,   KC_NA,   KC_NA,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NA,        KC_NA,       KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0
  )
};
