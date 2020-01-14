#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_preonic_2x2u(KC_GRV, LT(1,KC_1), LT(1,KC_2), LT(1,KC_3), LT(1,KC_4), LT(1,KC_5), LT(1,KC_6), LT(1,KC_7), LT(1,KC_8), LT(1,KC_9), LT(1,KC_0), KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_E, KC_R, KC_T, KC_Y, KC_U, LT(1,KC_O), LT(1,KC_P), LT(1,KC_MINS), KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, LT(1,KC_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, KC_NO, LT(1,KC_ESC), KC_LGUI, KC_LALT, LT(1,KC_SPC), LT(1,KC_DEL), LT(1,KC_LEFT), LT(1,KC_DOWN), LT(1,KC_UP), LT(1,KC_RGHT)),
	[1] = LAYOUT_preonic_2x2u(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_EQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_NO, KC_NO, KC_MPLY, TO(1), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT)
};
