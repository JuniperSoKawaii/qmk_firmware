#include QMK_KEYBOARD_H
#include "brandonschlack.h"

enum bdn9_layers {
    _LR_NAV = KEYMAP_LAYERS,
    _LR_REVIEW,
    _LR_EDIT
};

enum bdn9_keycodes {
    TG_LNAV = KEYMAP_SAFE_RANGE,
    TG_REVW,
    TG_EDIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        Layer: Navigation
        | Knob 1: Scroll Up/Dn  |      | Knob 2: Tab Prv/Nxt   |
        | Press: Reopen Tab     | CmTb | Close Tab             |
        | PgDn                  | Up   | PgUp                  |
        | Left                  | Down | Right                 |
     */
    [_NAVI] = LAYOUT(
        REO_TAB, CMD_TAB, CLS_TAB,
        KC_PGDN, KC_UP, KC_PGUP,
        KC_LEFT, KC_DOWN, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Reeder
        | Knob 1: j/k           |      | Knob 2: n/p           |
        | Press: H              | S    | R                     |
        | CMD+TAB               | M    | L                     |
        | Cmd+1                 | Cmd+2| Cmd+3                 |
     */
    [_REEDER] = LAYOUT(
        KC_H, KC_S, KC_R,
        CMD_TAB, KC_M, KC_L,
        G(KC_1), G(KC_2), TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Media
        | Knob 1: Vol +/-       |      | Knob 2: Track Prv/Nxt |
        | Press: Mute           | Plyr | Press: Play/Pause     |
        | J                     | K    | L                     |
        | Left                  | Spce | Right                 |
     */
    [_MEDIA] = LAYOUT(
        KC_MUTE, MC_PLYR, KC_MPLY,
        KC_J, KC_K, KC_L,
        KC_LEFT, KC_SPC, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Keypad/Karabiner
        | Knob 1: +/-           |      | Knob 2: =/.           |
        | Press: 1              | 2    | 3                     |
        | 4                     | 5    | 6                     |
        | 7                     | 8    | 9                     |
     */
    [_KEYPAD] = LAYOUT(
        KC_P1, KC_P2, KC_P3,
        KC_P4, KC_P5, KC_P6,
        KC_P7, KC_P8, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Navigation
        | Knob 1: =/-           |      | Knob 2: Page Dn/Up    |
        | Press: Review         | J    | Press: Edit           |
        | Home, Hold: BD Layer  | Up   | End                   |
        | Left                  | Down | Right                 |
     */
    [_LR_NAV] = LAYOUT(
        TG_REVW, KC_J, TG_EDIT,
        KC_HOME, KC_UP, KC_END,
        KC_LEFT, KC_DOWN, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Review/Rate
        | Knob 1: ]/[           |      | Knob 2: G(Up)/G(Dn)   |
        | Press: Nav            | 7    | Press: Edit           |
        | 0                     | 8    | U                     |
        | Left                  | 9    | Right                 |
     */
    [_LR_REVIEW] = LAYOUT(
        TG_LNAV, KC_7, TG_EDIT,
        KC_0, KC_8, KC_U,
        KC_LEFT, KC_6, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Edit/Develop
        | Knob 1: ./,           |      | Knob 2: =/-           |
        | Press: Review         | \    | Press: Nav            |
        | X                     | Undo | P                     |
        | Left                  | Redo | Right                 |
     */
    [_LR_EDIT] = LAYOUT(
        TG_REVW, KC_BSLS, TG_LNAV,
        KC_X, MC_UNDO, KC_P,
        KC_LEFT, MC_REDO, TD(TD_DTAP_MAGC)
    ),
    /*
        Layer: Magic
        | MAKE                  | Nav  | RESET                 |
        | Reeder                | Meda | Keypad                |
        | Review                | LNav | Edit                  |
     */
    [_MAGIC] = LAYOUT(
        KC_MAKE, TG_NAVI, RESET,
        TG_REDR, TG_MEDA, TG_KYPD,
        TG_REVW, TG_LNAV, TG_EDIT
    ),
};

/**
 * Encoder
 */
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _NAVI:
                if (!clockwise) {
                    tap_code(MC_WH_D);
                } else {
                    tap_code(MC_WH_U);
                }
                break;
            case _REEDER:
                if (!clockwise) {
                    tap_code(KC_J);
                } else {
                    tap_code(KC_K);
                }
                break;
            case _MEDIA:
                if (!clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _KEYPAD:
                if (!clockwise) {
                    tap_code(KC_PPLS);
                } else {
                    tap_code(KC_PMNS);
                }
                break;
            case _LR_NAV:
                if (!clockwise) {
                    tap_code(KC_EQL);
                } else {
                    tap_code(KC_MINS);
                }
                break;
            case _LR_REVIEW:
                if (!clockwise) {
                    tap_code(KC_RBRC);
                } else {
                    tap_code(KC_LBRC);
                }
                break;
            case _LR_EDIT:
                if (!clockwise) {
                    tap_code(KC_DOT);
                } else {
                    tap_code(KC_COMM);
                }
                break;
        }
    }
    else if (index == 1) {
        switch (biton32(layer_state)) {
            case _NAVI:
                if (!clockwise) {
                    tap_code16(NXT_TAB);
                } else {
                    tap_code16(PRV_TAB);
                }
                break;
            case _REEDER:
                if (!clockwise) {
                    tap_code(KC_N);
                } else {
                    tap_code(KC_P);
                }
                break;
            case _MEDIA:
                if (!clockwise) {
                    tap_code(KC_MFFD);
                } else {
                    tap_code(KC_MRWD);
                }
                break;
            case _KEYPAD:
                if (!clockwise) {
                    tap_code(KC_PEQL);
                } else {
                    tap_code(KC_PDOT);
                }
                break;
            case _LR_NAV:
                if (!clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
                break;
            case _LR_REVIEW:
                if (!clockwise) {
                    tap_code16(G(KC_UP));
                } else {
                    tap_code16(G(KC_DOWN));
                }
                break;
            case _LR_EDIT:
                if (!clockwise) {
                    tap_code(KC_EQL);
                } else {
                    tap_code(KC_MINS);
                }
                break;
        }
    }
}

/**
 * Keycodes
 */
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_LNAV:
            if (!record->event.pressed) {
                tap_code(KC_G);
                layer_move(_LR_NAV);
            }
            break;
        case TG_REVW:
            if (!record->event.pressed) {
                tap_code(KC_E);
                layer_move(_LR_REVIEW);
            }
            break;
        case TG_EDIT:
            if (!record->event.pressed) {
                tap_code(KC_D);
                layer_move(_LR_EDIT);
            }
            break;
    }
    return true;
}

/**
 * Tap Dances
 */
void process_tap_dance_keycode (bool reset, uint8_t toggle_layer) {
    uint16_t keycode = 0;
    switch (toggle_layer) {
        case _MAGIC:
            switch (biton32(layer_state)) {
                case _NAVI:
                case _MEDIA:
                case _LR_NAV:
                case _LR_REVIEW:
                case _LR_EDIT:
                    keycode = KC_RGHT;
                    break;
                case _REEDER:
                    keycode = G(KC_3);
                    break;
                case _KEYPAD:
                    keycode = KC_P9;
                    break;
            }
            break;
    }
    if (!reset) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}
