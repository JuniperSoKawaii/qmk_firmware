#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_neo2.h"

// Layer names
#define BASE 0      // default layer


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0 (default)
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │ HOM │     │ END │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤  E  │     │     ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ TL2 │     │ TL3 ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ Mod4│                             │ Mod4│ Win │ MO1 │ Alt │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │  ─  │ │  ─  │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │ HYP │ │ MEH │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[BASE] = KEYMAP(
        // left hand
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        NEO_Y,      NEO_X,  NEO_V,  NEO_L,  NEO_C,  NEO_W,  KC_HOME,
        NEO_L1_L,   NEO_U,  NEO_I,  NEO_A,  NEO_E,  NEO_O,
        KC_LSFT,    NEO_UE, NEO_OE, NEO_AE, NEO_P,  NEO_Z,  KC_TRNS,
        KC_LCTL,    KC_LALT,KC_TRNS,KC_LGUI,NEO_L2_L,
                                                    KC_LEFT,    KC_UP,
                                                                KC_MINS,
                                            KC_SPC, KC_ENT,    ALL_T(KC_NO),
        // right hand
        DE_ACUT,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_END,     NEO_K,  NEO_H,  NEO_G,  NEO_F,  NEO_Q,  NEO_SS,
                    NEO_S,  NEO_N,  NEO_R,  NEO_T,  NEO_D,  NEO_L1_R,
        KC_TRNS,    NEO_B,  NEO_M,  KC_COMM,KC_DOT, NEO_J,  KC_RSFT,
                            NEO_L2_R,KC_RGUI,KC_TRNS,KC_RALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_MINS,
        MEH_T(KC_NO),KC_ENT,KC_SPC
    ),
};

const uint16_t PROGMEM fn_actions[] = {
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            }
            else {
                unregister_code(KC_RSFT);
            }
        break;
    }

    return MACRO_NONE;
};


// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void * matrix_scan_user(void)
{
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        default:
            ergodox_board_led_off();
        break;
    }

};
