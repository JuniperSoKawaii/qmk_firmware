#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "rgb_util.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
*/
    [_QWERTY] = LAYOUT(
      KC_TAB,       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_LSFT,      KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,  SC_QUEST,
      KC_LCTL,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_RGUI, KC_SPC,     KC_ENT, KC_RGUI, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_DOWN, KC_RGHT,
                             SC_UNDO, KC_LALT, KC_RGUI, MO(_LOWER), KC_SPC,  KC_ENT, MO(_RAISE),  KC_RALT,  KC_RSFT, KC_LEFT
    ),
/*
 * Lower Layer: Number keys, Symbols, Navigation
 */
    [_LOWER] = LAYOUT(
      KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
      KC_LSFT,  _______, SC_PERCE, SC_AT,   SC_HASH, SC_EXCLA,                                    _______, KC_PGUP, KC_HOME, _______, SC_ASTER, SC_BACKSL,
      KC_LCTL,  KC_GRV,   KC_TILD, SC_AMP,  SC_PIPE, SC_DOLL, KC_RGUI, _______, _______, TG(_NUMBERS), KC_SCLN, KC_PGDN, KC_END, _______,  _______,  _______,
                                SC_REDO, KC_LALT, KC_RGUI, KC_TRNS, KC_SPC,  KC_ENT, MO(_RAISE),  KC_RALT,  KC_RSFT, KC_LEFT

    ),
/*
 * Raise Layer: Keys, more symbols
  */
    [_RAISE] = LAYOUT(
      KC_ESC,  KC_EQL, SC_IQUEST, SC_GEMIN, SC_APROX, SC_SYM1,                                  KC_LBRC, KC_QUOT, SC_OPAR, SC_CPAR, SC_EQUA, KC_DEL,
      KC_LSFT, _______, _______, KC_NUBS, SC_DIERE, SC_CHAPE,                                   SC_ODAT, SC_CDAT, SC_OKEY, SC_CKEY, KC_RBRC, SC_SLAS,
      KC_LCTL, _______, _______, KC_NUHS, _______, _______, TG(_NUMBERS),KC_SPC, KC_ENT, KC_TRNS,KC_MINS, SC_DQUO, SC_COLO, SC_SCOL, KC_SLSH, SC_UNSC,
                             SC_REDO, KC_LALT, KC_RGUI, MO(_LOWER), KC_SPC,        KC_ENT, KC_TRNS,  KC_RALT,  KC_CAPS, KC_LEFT
    ),
/*
 * Number pad and maths
 */
    [_NUMBERS] = LAYOUT(
      KC_ESC,   _______, _______, _______, _______, _______,                                     SC_SLAS,  KC_7, KC_8, KC_9, KC_SLSH, KC_BSPC,
      _______,  _______, _______, _______, _______, _______,                                     SC_ASTER, KC_4, KC_5, KC_6, KC_RBRC, _______,
      _______,  _______, _______, _______, _______, _______, TG(_NUMBERS), KC_SPC, KC_ENT, TG(_NUMBERS), KC_COMM,  KC_1, KC_2, KC_3, SC_EQUA, _______,
                                 _______, _______, _______, _______, KC_SPC,        KC_ENT, _______, _______, KC_0, KC_DOT
    ),
/*
 * Adjust Layer: Function keys, RGB
  */
    [_ADJUST] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, KC_TRNS, _______, _______, KC_TRNS, _______, KC_WAKE, _______
    ),
};
// clang-format on

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgb_layers_init();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    rgb_set_layer_state(state);
#endif
    return state;
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
    rgb_set_led_state(led_state);
#endif
    return true;
}

