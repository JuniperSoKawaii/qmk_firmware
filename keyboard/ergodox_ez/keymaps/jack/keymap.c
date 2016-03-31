#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

// TODO: Define layer names that make sense for the ErgoDox EZ.
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,          KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_NO,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        KC_ESC,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,          KC_LCTL,      KC_LALT,KC_LGUI, MO(2),
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_SPC,KC_END,
        // right hand
             KC_NO,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_NO,
             KC_NO,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSPC,
                        KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_NO,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_ENT,
                                  MO(1), KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,  
             KC_NO,        KC_NO,
             KC_PGUP,
             KC_PGDN, KC_SPC,KC_SPC
    ),
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, 
       KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
       KC_TRNS, KC_F12,  KC_NO,   KC_NO, KC_NO, RESET,   KC_TRNS,
                         KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, 
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  
       KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                 KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
       KC_TRNS,  KC_F12,  KC_NO,   KC_NO, KC_NO, RESET,   KC_TRNS,
                          KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, 
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
