// Copyright 2023 Ross Montsinger
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_ansi(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H, KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N, KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                                     KC_RALT, KC_RGUI, MO(_FN1), KC_RCTL
  ),

  [_FN1] = LAYOUT_60_ansi(
    QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    BL_BRTG, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    BL_UP,   BL_DOWN, BL_TOGG, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    KC_GRV,  _______, _______, _______,                                                       _______, _______, _______, QK_BOOT
  )
};
