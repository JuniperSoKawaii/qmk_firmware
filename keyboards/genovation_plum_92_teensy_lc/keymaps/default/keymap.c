#include "action_layer.h"
#include "genovation_plum_92_teensy_lc.h"
#include "keycode.h"
#include "util.h"
#include "quantum_keycodes.h"
#include "hal.h"
#define  OOOOOOO KC_TRNS
static uint16_t led_toggle = 0;

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* 0: qerty */
[0] = KEYMAP(
KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_PSCR,KC_F14, KC_F15,
KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,    KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_INS, KC_PGUP,
KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL, KC_PGDN,
KC_BSPC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_DEL, KC_HOME,KC_X,   KC_VOLU,
KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_END, KC_X,   KC_VOLD,
KC_LCTL,KC_LALT,KC_LGUI,        KC_SPC,                 KC_ENT,         KC_FN2, KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT,TG(1),  KC_MUTE),

 /* 1: FN 1 */
[1] = KEYMAP(
KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_PSCR,KC_F14, KC_SLEP,
KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,    KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_INS, KC_PGUP,
KC_TAB, M(0),   KC_W,   KC_E,   KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL, KC_PGDN,
KC_BSPC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,    KC_H,  KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_DEL, KC_HOME,KC_X,   KC_VOLU,
KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    KC_N,  KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_END, KC_X,   KC_VOLD,
KC_LCTL,KC_LALT,KC_LGUI,        KC_SPC,                 KC_ENT,         KC_FN2, KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT,OOOOOOO,KC_MUTE),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    switch(id) {
        case 0: {
            return MACRO( T(5), END  );
        }
            
    }
    return MACRO_NONE;
};

void matrix_scan_user(void) {
    if (biton32(layer_state) == 1) {
        if ((led_toggle++ > 35)) {
            led_toggle = 0;
            // output high
            palSetPad(TEENSY_PIN17_IOPORT, TEENSY_PIN17);
        } else {
            // output low
            palSetPadMode(TEENSY_PIN17_IOPORT, TEENSY_PIN17, PAL_MODE_OUTPUT_PUSHPULL);
            palClearPad(TEENSY_PIN17_IOPORT, TEENSY_PIN17);
        }
    } else {
        // output low
        palSetPadMode(TEENSY_PIN17_IOPORT, TEENSY_PIN17, PAL_MODE_OUTPUT_PUSHPULL);
        palClearPad(TEENSY_PIN17_IOPORT, TEENSY_PIN17);
    }
}