#include QMK_KEYBOARD_H

enum alt_keycodes {
    ALT_DEL = SAFE_RANGE   //Added to map left alt + backspace to delete
};

// Friendly layer names
enum alt_layers {
    DEF = 0,
    ALT,
    FUNC,
    SUPR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, MO(SUPR),                           KC_SPC,                             KC_RALT, MO(FUNC),KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [ALT] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, KC_LALT,                            _______,                            _______, _______, _______, _______, _______
    ),
    [FUNC] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, TG(ALT), _______, _______,          KC_PGUP, KC_VOLD,
        _______, _______, KC_LALT,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    [SUPR] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ALT_DEL, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, _______, KC_END
    )
};

// If the super alt layer is the active layer
bool super_alt_layer_active = false;

// If we need to unregister alt when leaving the super alt layer
bool need_to_unregister_alt = false;

// Taken from 'g_led_config' in config_led.c
#define CAPS_LOCK_LED_ID 30

// This runs every matrix scan (every 'frame')
void rgb_matrix_indicators_user(void) {
    led_flags_t flags = rgb_matrix_get_flags();

    // If we're in either keylight or underglow modes (but not both simultaneously)
    if (HAS_FLAGS(flags, LED_FLAG_KEYLIGHT) != HAS_FLAGS(flags, LED_FLAG_UNDERGLOW)) {

        // This fixes a bug where the caps lock LED flickers when toggled in either keylight or underglow modes
        if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(CAPS_LOCK_LED_ID, RGB_WHITE);
        } else {
            rgb_matrix_set_color(CAPS_LOCK_LED_ID, 0, 0, 0);
        }
    }
}

// This runs code every time that the layers get changed
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case DEF:
            // When returning to the default layer, check if we need to unregister the left alt key
            if (super_alt_layer_active && need_to_unregister_alt) {
                unregister_code(KC_LALT);
            }

            super_alt_layer_active = false;
            need_to_unregister_alt = false;
            break;
        case SUPR:
            super_alt_layer_active = true;
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // These are the keys we want to 'fall though' and behave as usual when pressed with the alt modifier
        case KC_A ... KC_Z:
        case KC_TAB:
        case KC_DEL:
        case KC_UP:
        case KC_DOWN:
        case MO(FUNC):
            if (super_alt_layer_active && record->event.pressed) {
                // Only activate the alt modifier for the first key press
                if ((get_mods() & MOD_BIT(KC_LALT)) == false) {
                    register_code(KC_LALT);
                    need_to_unregister_alt = true;
                }
            }
            // We still want to process the keycode normally
            return true;
        case ALT_DEL:
            if (record->event.pressed) {
                register_code(KC_DEL);
            } else {
                unregister_code(KC_DEL);
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}
