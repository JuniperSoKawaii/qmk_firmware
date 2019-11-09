#define MAX 1
#include QMK_KEYBOARD_H
#include "ps2.h"
#define _BL 0
#define _FN1 2
#define _NUM 3
#define _NUMF1 4

int scroll = 0;

enum my_keycodes {
  num1 = SAFE_RANGE,
  num2,};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |Pwr|Slp|Wak|
     * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|  +|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
     * |Ctrl |Gui |Alt |         Space         |Alt |Gui |Menu|Ctrl| |Lef|Dow|Rig| |      0|  .|   |
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    LAYOUT_fullsize_ansi(
    KC_ESC, KC_BRIU,  KC_BRID,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE, KC_VOLD, KC_VOLU,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    num1,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,
    GUI_T(KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(1, KC_ENT),                         KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_P1,  KC_P2,  KC_P3,
    KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,       KC_PDOT,KC_PENT
    ),
        LAYOUT_fullsize_ansi(
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    num1,KC_PSLS,KC_PAST,KC_PMNS,
    KC_CAPS, KC_Q,   KC_W,   KC_E,   RESET,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,TO(4),     KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,
    GUI_T(KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      LT(1, KC_ENT),                         KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_P1,  KC_P2,  KC_P3,
    KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,       KC_PDOT,KC_PENT
    ),
    LAYOUT_fullsize_ansi(
    KC_ESC, KC_BRIU,  KC_BRID,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE, KC_VOLD, KC_VOLU,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    num2,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_HOME,  KC_UP,  KC_PGUP,
    GUI_T(KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(3, KC_ENT),                         KC_LEFT,  KC_NO,  KC_RIGHT,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_END,  KC_DOWN,  KC_PGDN,
    KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_INS,       KC_DEL,KC_PENT
    ),

    LAYOUT_fullsize_ansi(
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    num2,KC_PSLS,KC_PAST,KC_PMNS,
    KC_CAPS, KC_Q,   KC_W,   KC_E,   RESET,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_HOME,  KC_UP,  KC_PGUP,
     GUI_T(KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(3, KC_ENT),                         KC_LEFT,  KC_NO,  KC_RIGHT,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_END,  KC_DOWN,  KC_PGDN,
    KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,     KC_INS,       KC_DEL,KC_PENT
    ),
    //windows layouts
        LAYOUT_fullsize_ansi(
    KC_ESC, KC_BRIU,  KC_BRID,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE, KC_VOLD, KC_VOLU,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    KC_NUMLOCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,
   MT(MOD_LCTL,KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(5, KC_ENT),                         KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_P1,  KC_P2,  KC_P3,
    KC_LGUI,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,       KC_PDOT,KC_PENT
    ),
        LAYOUT_fullsize_ansi(
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    KC_NUMLOCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_CAPS, KC_Q,   KC_W,   KC_E,   RESET,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_P7,  KC_P8,  KC_P9,
    MT(MOD_LCTL,KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,      LT(5, KC_ENT),                         KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_P1,  KC_P2,  KC_P3,
    KC_LGUI,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,       KC_PDOT,KC_PENT
    ),
    LAYOUT_fullsize_ansi(
    KC_ESC, KC_BRIU,  KC_BRID,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE, KC_VOLD, KC_VOLU,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    KC_NUMLOCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_HOME,  KC_UP,  KC_PGUP,
    MT(MOD_LCTL,KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(6, KC_ENT),                         KC_LEFT,  KC_NO,  KC_RIGHT,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_END,  KC_DOWN,  KC_PGDN,
    KC_LGUI,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,    KC_INS,       KC_DEL,KC_PENT
    ),
    LAYOUT_fullsize_ansi(
    KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_BRK,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS, KC_HOME,KC_PGUP,    KC_NUMLOCK,KC_PSLS,KC_PAST,KC_PMNS,
    KC_CAPS, KC_Q,   KC_W,   KC_E,   RESET,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL, KC_END, KC_PGDN,    KC_HOME,  KC_UP,  KC_PGUP,
    MT(MOD_LCTL,KC_ESC),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     LT(6, KC_ENT),                         KC_LEFT,  KC_NO,  KC_RIGHT,  KC_PPLS,
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,          KC_UP,           KC_END,  KC_DOWN,  KC_PGDN,
    KC_LGUI,KC_LGUI,KC_LALT,          KC_SPC,                     KC_RALT,KC_RGUI,KC_APP, KC_RCTL,     KC_LEFT,KC_DOWN,KC_RGHT,     KC_INS,       KC_DEL,KC_PENT
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case num1:
            if (record->event.pressed) {
                layer_on(2);
                ps2_host_set_led(2);
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key

            return true;   // Let QMK send the enter press/release events
        default:
            return true;  // Process all other keycodes normally
        case num2:
            if (record->event.pressed) {
                layer_clear();
                layer_on(0);
                ps2_host_set_led(0x0);
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key

            return true;  // Let QMK send the enter press/release events

            return true;  // Process all other keycodes normally

        case KC_INSERT:
            if (record->event.pressed) {
                register_code(KC_INSERT);
                ps2_host_set_led(1);
                    if (scroll == MAX) {
                        // do something
                        ps2_host_set_led(0x0);  // clear the led bank.

                        scroll--; //reset counter to 0


                        } else {
                        scroll++;
                        }
            }else{
                unregister_code(KC_INSERT);
            }
            }
            return false;  // Skip all further processing of this key

            return true;   // Let QMK send the enter press/release events

            return true;  // Process all other keycodes normally
    }


