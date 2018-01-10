// An Ergodox EZ keymap mostly following the programmer's dvorak layout.
// There is a standard QWERTY layer as well
//
// See the README.md file for an image of this keymap.

#include QMK_KEYBOARD_H

// The layers that we are defining for this keyboards.
#define BASE 0
#define FN 1
#define QWERTY 2

// The Tap Dance identifiers, used in the TD keycode and tap_dance_actions array.
#define TAP_MACRO 0

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRANSPARENT

// A 'blocking' key code. Does nothing but prevent falling back to another layer.
#define XXX KC_NO

// Some combined keys (one normal keycode when tapped and one modifier or layer
// toggle when held).
#define SPC_RALT  MT(MOD_RALT, KC_SPC)  // SPACE key and right alt modifier.

// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert

// Custom keycodes
enum {
  // SAFE_RANGE must be used to tag the first element of the enum.
  // DYNAMIC_MACRO_RANGE must always be the last element of the enum if other
  // values are added (as its value is used to create a couple of other keycodes
  // after it).
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};

// This file must be included after DYNAMIC_MACRO_RANGE is defined...
#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Layer 0: basic keys.
  [BASE] = KEYMAP(
    /* left hand */
    KC_DLR,   KC_AMPR,  KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_CIRC,
    KC_LGUI,  KC_SCOLON,KC_COMMA,KC_DOT,  KC_P,    KC_Y,    KC_PERC,
    MO(FN),  KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
    KC_LSPO,  KC_QUOTE, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LALT,
    KC_AT,    KC_HASH,  KC_GRAVE,KC_LEFT, KC_RIGHT,
                                             ALT_T(KC_APPLICATION), KC_LABK,
                                                                    KC_RABK,
                                          KC_ENTER, KC_TAB, CTL_T(KC_ESCAPE),
    /* right hand */
        KC_F4,        KC_EQUAL,KC_ASTR,  KC_RPRN, KC_PLUS,     KC_RBRACKET, KC_EXLM,
        KC_DELETE,    KC_F,    KC_G,     KC_C,    KC_R,        KC_L,        KC_SLASH,
                      KC_D,    KC_H,     KC_T,    KC_N,        KC_S,        KC_MINUS,
        TD(TAP_MACRO),KC_B,    KC_M,     KC_W,    KC_V,        KC_Z,        KC_RSPC,
                               KC_UP,    KC_DOWN, KC_HOME,     KC_END,      TO(QWERTY),
    KC_PGUP, KC_LGUI,
    KC_PGDOWN,
    CTL_T(KC_ESCAPE),   KC_BSPACE,   KC_SPACE),

  // Layer 1: function and numpad keys.
  [FN] = KEYMAP(
    /* left hand */
    ___,     KC_F1,   KC_F2,    KC_F3,       KC_F4,       KC_F5,      ___,
    ___,     KC_EXLM, KC_COMMA, KC_DOT,      KC_MS_BTN1,  KC_MS_BTN2, ___,
    XXX,     KC_HASH, KC_DLR,   KC_LPRN,     KC_RPRN,     KC_GRAVE,
    ___,     KC_PERC, KC_CIRC,  KC_LBRACKET, KC_RBRACKET, KC_TILD,    ___,
    ___,     ___,   ___,    ___,     ___,
                                            //TODO make first key layer 2 toggle
                                                          ___, ___,
                                                           KC_LCTL,
                               KC_KP_PLUS,  KC_KP_MINUS, KC_DLR,
    /* right hand */
        ___, KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,       KC_F11,
        ___, KC_UP,   KC_7,    KC_8,    KC_9,       KC_ASTR,      KC_F12,
             KC_DOWN, KC_4,    KC_5,    KC_6,       KC_PLUS,      KC_UNDS,
        ___, KC_0,    KC_1,    KC_2,    KC_3,       KC_KP_SLASH,  KC_BSLASH,
                      ___,     KC_0,    KC_KP_DOT,  KC_EQUAL,     ___,
    KC_KP_ASTERISK, KC_KP_SLASH,
    KC_RSHIFT,
    KC_DELETE, KC_BSPACE,  KC_SPACE),
    // Note that any change to the FN layer above must be added to
    // the QWERTY layer below (except for the arrow keys).

  // Layer 2: QWERTY control.
  [QWERTY] = KEYMAP(
    /* left hand */
    KC_EQUAL,   KC_1,     KC_2,           KC_3,     KC_4,  KC_5,    KC_LEFT,
    KC_DELETE,  KC_Q,     KC_W,           KC_E,     KC_R,  KC_T,    KC_Y,
    MO(FN),     KC_A,     KC_S,           KC_D,     KC_F,  KC_G,
    KC_LSFT,    KC_Z,     KC_X,           KC_C,     KC_V,  KC_B, ALT_T(KC_NO),
    KC_GRAVE,   KC_QUOTE, LALT(KC_TAB),   KC_LEFT,  KC_RIGHT,
                                                  ___, KC_LGUI,
                                                       KC_HOME,
                                      KC_ENTER, KC_TAB, KC_END,
    /* right hand */
        KC_RIGHT,     KC_6,   KC_7,     KC_8,         KC_9,       KC_0,     KC_MINUS,
        TO(BASE),     KC_Y,   KC_U,     KC_I,         KC_O,       KC_P,     KC_BSLASH,
                      KC_H,   KC_J,     KC_K,         KC_L,       KC_SCLN,  GUI_T(KC_QUOT),
        MEH_T(KC_NO), KC_N,   KC_M,     KC_COMMA,     KC_DOT,     KC_SLASH, KC_RSPC,
                      KC_UP,  KC_DOWN,  KC_LBRACKET,  KC_RBRACKET,TO(BASE),
    ___, KC_ESCAPE,
    KC_PGUP,
    KC_PGDOWN, KC_BSPACE, KC_SPACE),
};

// Whether the macro 1 is currently being recorded.
static bool is_macro1_recording = false;

// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;
uint32_t layer_state_set_user(uint32_t state);

// Method called at the end of the tap dance on the TAP_MACRO key. That key is
// used to start recording a macro (double tap or more), to stop recording (any
// number of tap), or to play the recorded macro (1 tap).
void macro_tapdance_fn(qk_tap_dance_state_t *state, void *user_data) {
  uint16_t keycode;
  keyrecord_t record;
  dprintf("macro_tap_dance_fn %d\n", state->count);
  if (is_macro1_recording) {
    keycode = DYN_REC_STOP;
    is_macro1_recording = false;
    layer_state_set_user(current_layer_state);
  } else if (state->count == 1) {
    keycode = DYN_MACRO_PLAY1;
  } else {
    keycode = DYN_REC_START1;
    is_macro1_recording = true;
    layer_state_set_user(current_layer_state);
  }

  record.event.pressed = true;
  process_record_dynamic_macro(keycode, &record);
  record.event.pressed = false;
  process_record_dynamic_macro(keycode, &record);
}

// The definition of the tap dance actions:
qk_tap_dance_action_t tap_dance_actions[] = {
  // This Tap dance plays the macro 1 on TAP and records it on double tap.
  [TAP_MACRO] = ACTION_TAP_DANCE_FN(macro_tapdance_fn),
};

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode != TD(TAP_MACRO)) {
    // That key is processed by the macro_tapdance_fn. Not ignoring it here is
    // mostly a no-op except that it is recorded in the macros (and uses space).
    // We can't just return false when the key is a tap dance, because
    // process_record_user, is called before the tap dance processing (and
    // returning false would eat the tap dance).
    if (!process_record_dynamic_macro(keycode, record)) {
      return false;
    }
  }

  return true; // Let QMK send the enter press/release events
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1<<layer))

void led_1_on(void) {
  ergodox_right_led_1_on();
  ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
  ergodox_right_led_2_on();
  ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
  ergodox_right_led_3_on();
  ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
  ergodox_right_led_1_off();
}

void led_2_off(void) {
  ergodox_right_led_2_off();
}

void led_3_off(void) {
  ergodox_right_led_3_off();
}

uint32_t layer_state_set_user(uint32_t state) {
  current_layer_state = state;

  if (is_macro1_recording) {
    led_1_on();
    led_2_on();
    led_3_on();
    return state;
  }

  if (LAYER_ON(FN)) {
    led_1_on();
  } else {
    led_1_off();
  }

  if (LAYER_ON(QWERTY)) {
    led_3_on();
  } else {
    led_3_off();
  }

  return state;
};
