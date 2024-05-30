
#include QMK_KEYBOARD_H

#define _MAIN 0
#define _RAISE 1
#define _LOWER 2

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* MAIN
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Backsp | Delete |   7    |   8    |   9    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ESC    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |  PgUp  |   4    |   5    |   6    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENTER  |  PgDn  |   1    |   2    |   3    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  |  PAUS  | GUI    | ALT    | Lower  | Space  |  Space | Raise  | Left   | Down   | Up     | Right  |  Shift |   0    |   .    |  ENTER |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_MAIN] = LAYOUT_ortho_4x16(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL,  KC_KP_7, KC_KP_8,   KC_KP_9,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_PGUP, KC_KP_4, KC_KP_5,   KC_KP_6,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  KC_PGDN, KC_KP_1, KC_KP_2,   KC_KP_3,
  KC_LCTL, KC_PAUS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RSFT, KC_KP_0, KC_KP_DOT, KC_PENT
  ),

/* RAISE
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    `   |  1     |  2     |  3     |  4     |  5     |  6     |  7     |  8     |  9     |  0     |        | Insert |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | -      | =      | [      | ]      |   \    |  Home  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |  PScr  |  End   |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                 |        |  Next  |  Vol-  |  Vol+  |  Play  | NumLok |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_4x16(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_INS,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_END,  _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_NUM,  _______, _______, _______
  ),

/* LOWER
 * .-----------------------------------------------------------------------------------------------------------------------------------------------.
 * |    ~   |    !   |    @   |    #   |    $   |    %   |    ^   |    &   |    *   |    (   |    )   |        |        | RGBPWR |  Mode  | Reset  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |    _   |    +   |    {   |    }   |   |    |        |  HUE+  |  SAT+  |  VAL+  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |        |        |        |        |        |        |  HUE-  |  SAT-  |  VAL-  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |                 |        |        |        |        |  Mute  |        |  Plain | Rainbo | Larsen |
 * '-----------------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_ortho_4x16(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, RGB_TOG, RGB_MOD, QK_BOOT,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, RGB_HUI, RGB_SAI, RGB_VAI,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, RGB_M_P, RGB_M_R, RGB_M_K
  ),

};
