/* TypeMatrix-2030-like keymap
 * ---------------------------
 * Currently supported features:
 * Layer 0: default layer close to the TM with the following differences:
 *  - top row and rightmost column are removed, corresponding keys are displaced, except app-keys which are removed
 *  - bottom-left keys are reorganized on a single roz as: Ctrl, "Fn", Gui, Play, App/Alt
 *  - "shuffle" and "desktop" are not supported
 *  - right-shift is moved on ' and \
 *  - right-ctrl is moved on End
 *  - ] is moved in place of the dash (-)
 *  - dash (-) and = are moved on bottom right row
 *  - arrows and PgUp/PgDn are moved on the thumbs
 * Layer 1: numbers layer close to the TM when toggling "num" with the following differences:
 *  - numpad is displaced by 1 to the top left
 *  - arrows are displaced by 1 to the left
 *  - provides access to F1-F12, caps lock and num lock
 * Layer 2: "fn" layer ("fn" key toggles both layers 1 & 2) with the following differences:
 *  - VolUp & VolDn are only on left hand to keep access to arrows on right hand
 * Leds:
 *  - left (1st) & middle (2nd) leds are used to indicate layers 1 & 2 respectively
 *  - right (3rd) led is used to indicate caps-lock
 */
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"

#define BASE 0 // default layer
#define NMBR 1 // numbers layer
#define FNLR 2 // fn layer

#define MDBL0 1
#define MFNLR 2
#define MCUT  3
#define MCOPY 4
#define MPSTE 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Del  |           | Del  |   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Backsp|           |Backsp|   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|ace   |           |ace   |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '/Shift|
 * |--------+------+------+------+------+------|Enter |           |Enter |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | \/Shift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  fn  | LGui | Play |App/Alt|                                      | RAlt |   -  | Home |   =  |End/Ctl|
 *   `-----------------------------------'                                      `-----------------------------------'
 *                                       ,--------------.       ,-------------.
 *                                       |Esc/Alt|  L1  |       | Left |Right |
 *                                ,------+-------+------|       |------+------+------.
 *                                |      |       | PgUp |       |  Up  |      |      |
 *                                |Space |LShift |------|       |------|RShift|Space |
 *                                |      |       | PgDn |       | Down |      |      |
 *                                `---------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_DELT,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_BSPC,
        KC_LSFT,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_ENT,
        KC_LCTL,        M(MFNLR),     KC_LGUI,KC_MPLY,ALT_T(KC_APP),

                                              ALT_T(KC_ESC),  TG(1),
                                                              KC_PGUP,
                                            KC_SPC, KC_LSFT,  KC_PGDN,

        // right hand
             KC_DELT,     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     KC_RBRC,
             KC_BSPC,     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
                          KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  SFT_T(KC_QUOT),
             KC_ENT,      KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_T(KC_BSLS),
                                  KC_RALT, KC_MINS, KC_HOME, KC_EQL,   CTL_T(KC_END),

             KC_LEFT, KC_RGHT,
             KC_UP,
             KC_DOWN, KC_RSFT,  KC_SPC
    ),
/* Keymap 1: Numbers Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |      |      |  Tab |   /  |   *  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |      | Home |   7  |   8  |   9  |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |------|           |------|  Up  | End  |   4  |   5  |   6  |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Left | Down | Right|   1  |   2  |   3  |KpEnter |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   0  |  00  |   .  |Etr/Ctl|
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |n.lock|c.lock|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[NMBR] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                                               KC_TRNS, KC_TRNS,KC_TRNS,
       // right hand
       KC_INS,  KC_F6,   KC_F7,   KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
       KC_TRNS, KC_TRNS, KC_HOME, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
                KC_UP,   KC_END,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
       KC_LEFT, KC_DOWN, KC_RGHT, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
                         KC_TRNS, KC_P0,   M(MDBL0),KC_PDOT, CTL_T(KC_PENT),

       KC_NLCK, KC_CAPS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: fn layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |Insert|           |Insert|Eject |Power |Sleep | Wake |PrtScr|ScrollLk|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |VolUp |           |      |      |      |      |      |      | Pause  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | cut  | copy |paste | Mute |VolDn |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Next |      |      |
 *                                 | Mute |      |------|       |------|      |      |
 *                                 |      |      |      |       | Prev |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[FNLR] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS, KC_INS,
       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS, KC_VOLU,
       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS, M(MCUT),      M(MCOPY),    M(MPSTE),     KC_MUTE, KC_VOLD,
       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS,

                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_MUTE, KC_TRNS, KC_TRNS,
    // right hand
       KC_INS,   KC_EJCT, KC_PWR,  KC_SLEP, KC_WAKE, KC_PSCR, KC_SLCK,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_MPRV,
       KC_MNXT, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
        case MDBL0:
            if (record->event.pressed) {
              return MACRO( I(25), T(P0), T(P0), END );
            }
        break;
        case MFNLR:
            layer_state ^= (1 << NMBR) | (1 << FNLR);
            break;
        case MCUT:
            if (record->event.pressed) {
                return MACRO(D(LSFT), T(DELT), U(LSFT), END);
            }
            break;
        case MCOPY:
            if (record->event.pressed) {
                return MACRO(D(LCTL), T(INS), U(LCTL), END);
            }
            break;
        case MPSTE:
            if (record->event.pressed) {
                return MACRO(D(LSFT), T(INS), U(LSFT), END);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    // led 1: numbers layer
    if (layer_state & (1 << NMBR)) {
        ergodox_right_led_1_on();
    }
    // led 2: fn layer
    if (layer_state & (1 << FNLR)) {
        ergodox_right_led_2_on();
    }
    // led 3: caps lock
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      ergodox_right_led_3_on();
    }
};
