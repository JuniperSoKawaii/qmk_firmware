/* Copyright 2020 Takeshi Nishio
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _MAC = 0,
    _WIN,
    _NUM,
    _MIDI,
    _LOWER,
    _RAISE,
    _NUM_RAISE,
    _ADJUST,
    _CAPS, // This is not a "REAL" layer. Define here to use for RGB light layer.
};

// Tap Dance
enum tap_dances{
    TD_LSFT_CAPS = 0,
    TD_ESC_NUM,
};

// Tap Dance state
enum {
    SINGLE_TAP = 1,
    DOUBLE_TAP,
    TRIPLE_TAP,
    TAP_HOLD,
};

// Declare the functions to be used with your tap dance key(s)
// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);
// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ESC_NUM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275),
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  M_PSCR,
};

// Key Macro
#define ESC_NUM TD(TD_ESC_NUM)
#define S_CAP   TD(TD_LSFT_CAPS)
#define SP_LOW  LT(_LOWER, KC_SPC)
#define SP_RAI  LT(_RAISE, KC_SPC)
#define SP_NRAI LT(_NUM_RAISE, KC_SPC)
#define SP_SFT  MT(MOD_LSFT, KC_SPC)
#define SLS_LOW LT(_LOWER, KC_SLSH)
#define SFT_SLS RSFT_T(KC_SLSH)
#define C_SLSH  RCTL_T(KC_SLSH)
#define CT_E    LCTL(KC_E)
#define CT_A    LCTL(KC_A)
#define ALT_GRV LALT(KC_GRV)
#define LOWER   MO(_LOWER)
#define NUM     TG(_NUM)
#define HENKAN  LGUI(KC_GRV)
#define MIDI    TG(_MIDI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT(
        XXXXXXX,XXXXXXX,KC_MUTE,XXXXXXX,KC_P1,  KC_P2,  KC_P3,  KC_P4,  XXXXXXX,KC_MUTE,XXXXXXX,KC_MUTE,XXXXXXX,KC_MUTE,XXXXXXX,KC_MUTE,XXXXXXX,
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,KC_GRV, KC_BSLS,KC_RBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,       KC_BSPC,
        KC_LCTL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_SCLN,KC_NLCK,KC_ESC, KC_QUOT,KC_H,   KC_J,   KC_K,   KC_L,   KC_MINS,    KC_ENT,
        KC_LSFT,KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   M_PSCR,KC_INS, KC_HOME,XXXXXXX,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_UP,  SFT_SLS,
        KC_CAPS,KC_CAPS,KC_LALT,XXXXXXX,KC_LGUI,SP_LOW, SP_LOW, KC_P0,  KC_DEL, KC_END, KC_PENT,SP_RAI, SP_RAI, KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT
    ),
    [_WIN] = LAYOUT(
        XXXXXXX,_______,_______,XXXXXXX,_______,_______,_______,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,
        _______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,
        _______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______,_______,KC_LGUI,_______,KC_LALT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    // [_NUM] = LAYOUT(
    //     _______,_______,_______,_______,_______,_______,_______,XXXXXXX,KC_PSLS,KC_PSLS,KC_PAST,_______,_______,_______,_______,
    //     _______,    _______,_______,_______,_______,_______,_______,KC_P7,  KC_P8,  KC_P9,  KC_PPLS,_______,    _______,_______,
    //     _______,    _______,_______,_______,_______,_______,_______,KC_P4,  KC_P5,  KC_P6,  XXXXXXX,_______,    _______,_______,
    //     _______,        _______,_______,_______,_______,_______,_______,KC_P1,  KC_P2,  KC_P3,  KC_PENT,_______,_______,_______,
    //     _______,_______,_______,_______,        _______,        SP_NRAI,        KC_P0,  KC_PDOT,_______,_______,_______,_______
    // ),
    [_MIDI] = LAYOUT(
        XXXXXXX,_______,_______,XXXXXXX,_______,_______,_______,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,
        _______,_______,MI_F_3, MI_G_3, MI_A_3, MI_B_3, MI_C_4, MI_D_4, MI_E_4, MI_F_4, MI_G_4, MI_A_4, MI_B_4, MI_C_5, MI_D_5,     MI_E_5,
        _______,_______,_______,MI_Fs_2,MI_Gs_2,MI_As_2,XXXXXXX,MI_Cs_3,MI_Ds_3,XXXXXXX,MI_Fs_3,MI_Gs_3,MI_As_3,XXXXXXX,MI_Cs_4,   MI_Ds_4,
        _______,_______,MI_F_2,_______,MI_G_2, MI_A_2, MI_B_2, MI_C_3, MI_D_3, MI_E_3, MI_F_3, MI_G_3, MI_A_3, MI_B_3, MI_C_4, XXXXXXX,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    ),
    [_LOWER] = LAYOUT(
        XXXXXXX,_______,_______,XXXXXXX,_______,_______,_______,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,
        KC_1,       KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   _______,_______,_______,_______,KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL,
        KC_F1,      KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  _______,_______,_______,_______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_LBRC,KC_RBRC,KC_PGUP,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_END
        ),
    [_RAISE] = LAYOUT(
        XXXXXXX,_______,_______,XXXXXXX,_______,_______,_______,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,
        KC_EXLM,    KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,_______,_______,_______,_______,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_UNDS,    KC_PLUS,
        _______,    _______,_______,_______,_______,KC_ESC, _______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_SCLN,    KC_DEL,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_LCBR,KC_RCBR,KC_PGUP,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_END
    ),
    // [_NUM_RAISE] = LAYOUT(
    //     KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,KC_GRV,
    //     KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,    KC_LBRC,KC_RBRC,
    //     KC_LCTL,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_ENT,    KC_QUOT,KC_RCTL,
    //     S_CAP,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,_______,_______,
    //     _______,_______,_______,_______,        _______,        _______,        _______,_______,_______,_______,_______,_______
    // ),
    [_ADJUST] = LAYOUT(
        XXXXXXX,_______,_______,XXXXXXX,_______,_______,_______,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,_______,XXXXXXX,
        _______,    MIDI,   WIN,    _______,RESET,  _______,_______,_______,_______,_______,RGB_HUI,RGB_SAI,RGB_VAI,_______,RGB_RMOD,   _______,
        _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_HUD,RGB_SAD,RGB_VAD,RGB_TOG,RGB_MOD,    _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,NUM,     MAC,   _______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAC: // Change default ayer --> Write to EEPROM
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
            break;
        case WIN: // Change default ayer --> Write to EEPROM
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
            break;
        case M_PSCR: // Mac's advanced screen capture
            if (record->event.pressed) {
                tap_code16(LSFT(LGUI(KC_5)));
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}

//------------------------------------------------------------------------------
// RGB Light settings
#ifdef RGBLIGHT_LAYERS

// Indicator LED settings
#define INDICATOR_INDEX 1        // where to start indicator
#define INDICATOR_COUNT 3         // how many leds for indicator
#define INDICATOR_CHANGE_COUNT 2  // how meny leds to change color for temporally layer
#define DIMMER_LEVEL 0          // brightness dimmer

// for Default layer (= Base layer)
const rgblight_segment_t PROGMEM my_mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_COUNT, HSV_WHITE - DIMMER_LEVEL}
);
const rgblight_segment_t PROGMEM my_win_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_COUNT, HSV_BLUE - DIMMER_LEVEL}
);
const rgblight_segment_t PROGMEM my_num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_COUNT, HSV_YELLOW - DIMMER_LEVEL}
);
const rgblight_segment_t PROGMEM my_midi_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_COUNT, HSV_PINK - DIMMER_LEVEL}
);

// for temporal layer
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_CHANGE_COUNT, HSV_GREEN - DIMMER_LEVEL}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_CHANGE_COUNT, HSV_CYAN - DIMMER_LEVEL}
);

const rgblight_segment_t PROGMEM my_num_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_CHANGE_COUNT, HSV_GOLD - DIMMER_LEVEL}
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX , INDICATOR_CHANGE_COUNT, HSV_RED - DIMMER_LEVEL}
);

// for Lock indicator
const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {INDICATOR_INDEX + 1 , INDICATOR_CHANGE_COUNT, HSV_MAGENTA - DIMMER_LEVEL}
);

// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_mac_layer,
    my_win_layer,
    my_num_layer,
    my_midi_layer,
    my_lower_layer,
    my_raise_layer,
    my_num_raise_layer,
    my_adjust_layer,
    my_caps_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Set effect range to non-indicator led range.
    // rgblight_set_effect_range(3, 8);
}

// Enabling and disabling lighting layers
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

    rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(_MIDI, layer_state_cmp(state, _MIDI));
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_NUM_RAISE, layer_state_cmp(state, _NUM_RAISE));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));

    return state;
}

// Enabling and disabling lighting layers for default layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    // rgblight_set_layer_state(_MAC, layer_state_cmp(state, _MAC));
    // rgblight_set_layer_state(_WIN, layer_state_cmp(state, _WIN));
    // rgblight_set_layer_state(_NUM, layer_state_cmp(state, _NUM));

    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(_CAPS, led_state.caps_lock);
    return true;
}
#endif


//------------------------------------------------------------------------------
// Rotary Encoder
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder, Right side */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Second encoder, Left side */
        if (clockwise) {
            rgblight_increase_val();
        } else {
            rgblight_decrease_val();
        }
    } else if (index == 2) {
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
    } else if (index == 3) {
        if (clockwise) {
            rgblight_increase_sat();
        } else {
            rgblight_decrease_sat();
        }
    } else if (index == 4) {
        if (clockwise) {
            // rgblight_step();
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_MS_WH_DOWN);
            // rgblight_step_reverse();
        }
    }
}
#endif

        // switch(biton32(layer_state)) {
        //     case _LOWER:
        //         if (clockwise) {
        //             rgblight_decrease_hue();
        //         } else {
        //             rgblight_increase_hue();
        //         }
        //         break;
        //     case _RAISE:
        //         if (clockwise) {
        //             rgblight_decrease_val();
        //         } else {
        //             rgblight_increase_val();
        //         }
        //         break;
        //     case _ADJUST:
        //         if (clockwise) {
        //             rgblight_step_reverse();
        //         } else {
        //             rgblight_step();
        //         }
        //         break;
        //     default:
        //         if (clockwise) {
        //             tap_code(KC_VOLD);
        //         } else {
        //             tap_code(KC_VOLU);
        //         }
        //         break;
        // }

//------------------------------------------------------------------------------
// Tap Dance function
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else if (state->count == 2) {
        if (!state->pressed) {
            return DOUBLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else if (state->count == 3) {
        if (!state->pressed) {
            return TRIPLE_TAP;
        } else {
            return TAP_HOLD;
        }
    } else {
        return 8; // Magic number. At some point this method will expand to work for more presses
    }
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch(state->keycode) {
        case TD(TD_ESC_NUM): // ESC key action
            switch (ql_tap_state.state) {
                case SINGLE_TAP:
                case DOUBLE_TAP:
                    // ESC
                    tap_code(KC_ESC);
                    break;
                case TAP_HOLD:
                    // temporal layer change
                    layer_on(_NUM);
                    break;
                case TRIPLE_TAP:
                    // toggle layer
                    // Check to see if the layer is already set
                    if (layer_state_is(_NUM)) {
                        // If already set, then switch it off
                        layer_off(_NUM);
                    } else {
                        // If not already set, then switch the layer on
                        layer_on(_NUM);
                    }
                    break;
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->keycode) {
        case TD(TD_ESC_NUM):
            // If the key was held down and now is released then switch off the layer
            if (ql_tap_state.state == TAP_HOLD) {
                layer_off(_NUM);
            }
            ql_tap_state.state = 0;
            break;
    }
}


//------------------------------------------------------------------------------
// OLED
#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MAC:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case _WIN:
            oled_write_P(PSTR("Win\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
