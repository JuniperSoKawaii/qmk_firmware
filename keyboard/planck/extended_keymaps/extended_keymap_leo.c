#include "extended_keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* BASE */
  {KC_ESC,  KC_LBRC, KC_QUOT, KC_SCLN, KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT},
  {KC_LSFT, KC_DOT,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_COMM},
  {KC_LCTL, KC_LALT, KC_LGUI, FUNC(3), FUNC(2), KC_SPC,  KC_SPC,  FUNC(1), FUNC(3), KC_RGUI, KC_RALT, KC_RCTL}
},
[2] = { /* RAISE */
  {RALT(KC_RBRC),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  S(KC_RBRC)},
  {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11, KC_F12},
  {KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[3] = { /* LOWER */
  {S(KC_EQL),S(KC_1),S(KC_2),S(KC_3),RALT(KC_5),S(KC_5),   S(KC_6),  S(KC_7),RALT(KC_7),RALT(KC_0),S(KC_0), KC_MINS},
  {KC_TRNS,RALT(KC_2),S(KC_SLSH),KC_NUBS,S(KC_NUBS),RALT(KC_MINS),RALT(KC_NUBS), KC_NUHS, S(KC_8),  S(KC_9), S(KC_MINS), KC_SLSH},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, RALT(KC_8),   RALT(KC_9),   KC_TRNS,  KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[4] = { /* META */
  {KC_TRNS,  KC_HOME,  KC_UP,    KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_UP,    KC_END,   KC_TRNS,  KC_DEL},
  {KC_TRNS,  KC_RGHT,  KC_DOWN,  KC_LEFT,  KC_PGUP,  KC_TRNS,  KC_PGUP,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_PGDN,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(2),  // to RAISE
    [2] = ACTION_LAYER_MOMENTARY(3),  // to LOWER
    [3] = ACTION_LAYER_MOMENTARY(4),  // to META

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
        return MACRODOWN(T(CM_T), END);
      break;
    } 
    return MACRO_NONE;
};
