#include QMK_KEYBOARD_H
#include "version.h"
#include <sendstring_dvorak.h>
//#include <sendstring_colemak.h>
#include <print.h>


/**********************
** LAYER DEFINITIONS **
**********************/
enum layer_names {
    // BASE LAYERS
        // SHORT CODES
    _QWERTY = 0,
        _QW = _QWERTY,
    _DVORAK,
        _DV = _DVORAK,
    _COLEMAK,
        _CM = _COLEMAK,
    _QUAKE2,
        _Q2 = _QUAKE2,
    _QUAKE2_DVORAK,
        _QD = _QUAKE2_DVORAK,
    _QUAKE2_CONSOLE,
        _QC = _QUAKE2_CONSOLE,
    // FUNCTION LAYERS
    _FUNC,
        _FN = _FUNC,
    _FUNCQ2,
        _FQ = _FUNCQ2,
    // OTHER LAYERS
    _NUMPAD,
        _NP = _NUMPAD,
    _MACROS,
        _MA = _MACROS,
    _SYSTEM,
        _SY = _SYSTEM,
};


// KEYCODE DEFINITIONS
#define NO_CHNG KC_TRNS // Note for me for keys I need to leave as Pass-through

#define FN_CAPS LT(_FUNC, KC_CAPS)    // _FUNC when held, Caps Lock when tapped
#define Q2_CAPS LT(_FUNCQ2, KC_CAPS)  // _FUNCQ2 when held, Caps Lock when tapped

#define CTL_GRV MT(MOD_LCTL, KC_GRV)  // Left Control when held, Grave accent when tapped


// MACRO DEFINITIONS
enum custom_keycodes {
    F_CAPS = SAFE_RANGE,
    T_L3DED,
    G_PUSH,
    G_FTCH,
    G_COMM,
    G_RST,
    G_C10R,
    G_BRCH,
    SIGNA,
    GO_Q2,
    Q2_ON,
    Q2_OFF,
    Q2_ESC,
    Q2_GRV,
    M_SALL,
    M_UNDO,
    M_CUT,
    M_COPY,
    M_PASTE,
    VRSN,
    M_MDSWP
};


/*******************
** MODIFIER MASKS **
*******************/
#define MOD_MASK_RALT   (MOD_BIT(KC_RALT))
bool macroMode = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        // these are our macros!
        case T_L3DED:
            if (record->event.pressed) {
                SEND_STRING("lavak3DED ");
            };
            return false;
        case G_PUSH:
            if (record->event.pressed) {
                SEND_STRING("git push origin ");
            };
            return false;
        case G_FTCH:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_SHIFT ) {
                    clear_mods();
                    SEND_STRING("git pull upstream ");
                } else {
                    SEND_STRING("git fetch upstream ");
                }
            };
            return false;
        case G_COMM:
            if (record->event.pressed) {
                SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
            };
            return false;
        case G_BRCH:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_SHIFT ) {
                    clear_mods();
                    SEND_STRING("master");
                } else {
                    SEND_STRING("$(git branch-name)");
                }
            };
            return false;
        case SIGNA:
            if (record->event.pressed) {
                SEND_STRING("\\- @noroadsleft" SS_TAP(X_ENTER));
            };
            return false;
        case GO_Q2:
            if (record->event.pressed) {
                //default_layer_set(_QWERTY);
                layer_move(_QWERTY); // TO(_QWERTY);
                layer_on(_QUAKE2);
                //layer_off(_SYSTEM);
            };
            return false;
        case Q2_ON:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER));
                layer_on(_DVORAK);
                layer_on(_QUAKE2_DVORAK);
            };
            return false;
        case Q2_OFF:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER));
                layer_move(_QWERTY); // TO(_QWERTY);
                layer_on(_QUAKE2);
            };
            return false;
        case Q2_ESC:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE));
                layer_move(_QWERTY); // TO(_QWERTY);
                layer_on(_QUAKE2);
            };
            return false;
        case Q2_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_GRAVE));
                layer_on(_DVORAK);
                layer_on(_QUAKE2_DVORAK);
                layer_on(_QUAKE2_CONSOLE);
            };
            return false;
        case M_SALL:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    tap_code16(G(KC_A));
                } else {
                    tap_code16(C(KC_A));
                }
            }
            return false;
        case M_UNDO:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    if ( get_mods() & MOD_MASK_SHIFT ) {
                        tap_code16( S(G(KC_Z)) );
                    } else {
                        tap_code16( G(KC_Z) );
                    }
                } else {
                    tap_code16(C(KC_Z));
                }
            }
            return false;
        case M_CUT:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    tap_code16(G(KC_X));
                } else {
                    tap_code16(C(KC_X));
                }
            }
            return false;
        case M_COPY:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code16(C(KC_C));
                }
            }
            return false;
        case M_PASTE:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    if ( get_mods() & MOD_MASK_SHIFT ) {
                        tap_code16( S(A(G(KC_V))) );
                    } else {
                        tap_code16( G(KC_V) );
                    }
                } else {
                    tap_code16(C(KC_V));
                }
            }
            return false;
        case KC_HOME:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    register_code16(G(KC_LEFT));
                } else {
                    register_code(keycode);
                }
            } else {
                if ( macroMode == 1 ) {
                    unregister_code16(G(KC_LEFT));
                } else {
                    unregister_code(keycode);
                }
            };
            return false;
        case KC_END:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    register_code16(G(KC_RGHT));
                } else {
                    register_code(keycode);
                }
            } else {
                if ( macroMode == 1 ) {
                    unregister_code16(G(KC_RGHT));
                } else {
                    unregister_code(keycode);
                }
            };
            return false;
        case KC_PSCR:
            if (record->event.pressed) {
                if ( macroMode == 1 ) {
                    register_code16(LGUI(LSFT(KC_3)));
                } else {
                    register_code(keycode);
                }
            } else {
                if ( macroMode == 1 ) {
                    unregister_code16(LGUI(LSFT(KC_3)));
                } else {
                    unregister_code(keycode);
                }
            };
            return false;
        case KC_Z:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_RALT ) {
                    register_code(KC_NUBS);
                } else {
                    register_code(KC_Z);
                }
            } else {
                if ( get_mods() & MOD_MASK_RALT ) {
                    unregister_code(KC_NUBS);
                } else {
                    unregister_code(KC_Z);
                }
            };
            return false;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING( QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION );
            }
            return false;
        case M_MDSWP:
            if (record->event.pressed) {
                macroMode ^= 1;
            }
            return false;
        case KC_1 ... KC_0:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_RALT ) {
                    register_code( keycode + 0x3B );
                } else {
                    register_code( keycode );
                }
            } else {
                if ( get_mods() & MOD_MASK_RALT ) {
                    unregister_code( keycode + 0x3B );
                } else {
                    unregister_code( keycode );
                }
            }
            return false;
        case KC_F1 ... KC_F12:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_RALT ) {
                    register_code( keycode + 0x2E );
                } else {
                    register_code( keycode );
                }
            } else {
                if ( get_mods() & MOD_MASK_RALT ) {
                    unregister_code( keycode + 0x2E );
                } else {
                    unregister_code( keycode );
                }
            }
            return false;
    } // switch()
    return true;
};


// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /****************
    ** BASE LAYERS **
    ****************/

    /* QWERTY */
    [_QWERTY] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    /* Dvorak */
    [_DVORAK] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,
        FN_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,          KC_ENT,
        KC_LSFT,          KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,             KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    /* Colemak */
    [_COLEMAK] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        FN_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        CTL_GRV, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_MA), MO(_FN), KC_RCTL
    ),

    /*********************
    ** QUAKE 2 OVERLAYS **
    *********************/

    /* Quake 2 */
    [_QUAKE2] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        Q2_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          Q2_ON,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, MO(_FQ), _______
    ),

    [_QUAKE2_DVORAK] = LAYOUT_60_ansi(
        Q2_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        Q2_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          Q2_OFF,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, MO(_FQ), _______
    ),

    [_QUAKE2_CONSOLE] = LAYOUT_60_ansi(
        Q2_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        Q2_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_ENT,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, MO(_FQ), _______
    ),

    /********************
    ** FUNCTION LAYERS **
    ********************/

    /* Fn layer */
    [_FUNC] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_CALC, KC_APP,  _______, _______, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,
        NO_CHNG, M_SALL,  _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          KC_PENT,
        _______,          M_UNDO,  M_CUT,   M_COPY,  M_PASTE, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, TG(_SY),          _______,
        _______, _______, _______,                            TG(_NP),                            _______, _______, NO_CHNG, _______
    ),

    /* Quake 2 Fn layer */
    [_FUNCQ2] = LAYOUT_60_ansi(
        Q2_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SLCK, KC_PAUS,
        NO_CHNG, _______, _______, _______, _______, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,          KC_ENT,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(_SY),          _______,
        _______, _______, _______,                            _______,                            _______, _______, NO_CHNG, _______
    ),

    /*****************
    ** OTHER LAYERS **
    *****************/

    /* Numpad layer */
    [_NUMPAD] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,
        _______, _______, _______, _______, KC_E,    KC_F,    _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PSLS, KC_PEQL, _______,
        _______, _______, _______, _______, KC_C,    KC_D,    _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, KC_PMNS,          KC_PENT,
        _______,          _______, _______, _______, KC_A,    KC_B,    _______, KC_P0,   _______, KC_PDOT, _______,          _______,
        _______, _______, _______,                            TG(_NP),                            _______, _______, NO_CHNG, _______
    ),

    /* Macro layer */
    [_MACROS] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2, _______,
        _______, _______, _______, G_PUSH,  _______, _______, _______, _______, _______, _______, _______, DM_PLY1, DM_PLY2, DM_RSTP,
        _______, _______, _______, G_FTCH,  G_COMM,  _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, G_BRCH,  SIGNA,   _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, NO_CHNG, _______
    ),

    /* System layer */
    [_SYSTEM] = LAYOUT_60_ansi(
        TG(_SY), TO(_QW), TO(_DV), TO(_CM), GO_Q2,   XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, DEBUG,   XXXXXXX, VRSN,    XXXXXXX,
        XXXXXXX, XXXXXXX, M_MDSWP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, NO_CHNG, XXXXXXX
    ),

};
