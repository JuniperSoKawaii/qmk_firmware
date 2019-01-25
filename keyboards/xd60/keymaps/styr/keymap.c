#include QMK_KEYBOARD_H
#include "action_layer.h"

#define _BL 0
#define _FL 1
#define _LL 2
// #define _RS 3

#define _______ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // 0: Base Layer
  [_BL] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_GRV,  KC_BSPC,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,          KC_BSLS,   \
      MO(_LL), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,            KC_ENT,    \
      KC_LSFT, XXXXX,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,   KC_DEL, \
      KC_LCTL, KC_LALT, KC_LGUI,                          KC_SPC,                          MO(_FL), KC_RALT, KC_LEFT,  KC_DOWN, KC_RIGHT),

  // 1: Function Layer
  [_FL] = LAYOUT_all(
      XXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,    \
      XXXXX,   RGB_TOG, RGB_MOD, RGB_RMOD,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  RGB_HUI,  RGB_HUD,   XXXXX,   RGB_VAI,    RGB_VAD,   XXXXX,    \
      XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,   XXXXX,    XXXXX,   \
      XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,    XXXXX,   KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, \
      XXXXX,   XXXXX,   XXXXX,                    XXXXX,                                            XXXXX,    F(0),    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT),

  [_LL] = LAYOUT_all(
      XXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,   KC_F14,    \
      XXXXX,   RGB_TOG, XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,   XXXXX,    XXXXX,   XXXXX,    \
      XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,   XXXXX,    KC__MUTE,   \
      XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX,    XXXXX,   XXXXX, KC_VOLU, KC_MPLY, \
      XXXXX,   XXXXX,   XXXXX,                    XXXXX,                                            XXXXX,    F(0),    KC_MRWD, KC_VOLD, KC_MFFD),


};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
