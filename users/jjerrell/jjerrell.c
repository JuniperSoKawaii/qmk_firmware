/**
 * Copyright (C) 2021 Jerrell, Jacob <@jjerrell>
 * 
 * This file is part of qmk_firmware.
 * 
 * qmk_firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * qmk_firmware is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jjerrell.h"

#ifdef ENABLE_USERSPACE_CONFIG
userspace_config_t userspace_config;

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}
void keyboard_pre_init_user(void) {
    userspace_config.raw = eeconfig_read_user();
    keyboard_pre_init_keymap();
}

__attribute__((weak)) void eeconfig_init_keymap(void) {}
void eeconfig_init_user(void) {
    userspace_config.raw              = 0;
    userspace_config.rgb_layer_change = RGB_MATRIX_ENABLE;
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();
    keyboard_init();
}
#endif // ENABLE_USERSPACE_CONFIG

#ifdef RGB_MATRIX_ENABLE

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void keyboard_post_init_user(void) {
    keyboard_post_init_rgb_matrix();
    keyboard_post_init_keymap();
}

void rgb_matrix_update_pwm_buffers(void);
__attribute__((weak)) void shutdown_keymap(void) {}
void shutdown_user(void) {
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
    shutdown_keymap();
}
#endif // RGB_MATRIX_ENABLE


// Custom Shared LED Configuration when/if applicable
__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}
void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void matrix_init_keymap(void) {}
void matrix_init_user(void) {
    matrix_init_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

// Matrix Scan

__attribute__((weak)) void matrix_scan_secrets(void) {}
__attribute__((weak)) void matrix_scan_keymap(void) {}
__attribute__((weak)) void matrix_scan_rgb_matrix(void) {}

LEADER_EXTERNS();
void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Website Refresh / XCode "Run"
        SEQ_ONE_KEY(KC_R) {
            SEND_STRING(SS_LGUI("r"));
        } else

        SEQ_TWO_KEYS(KC_B, KC_D) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE);
        }

        #ifndef NO_SECRETS
        matrix_scan_secrets();
        #endif // !NO_SECRETS
    }
}

void matrix_scan_user(void) {
    static bool ran_once;
    if (ran_once == false) {
        ran_once = true;
        startup_user();
    }

    matrix_scan_leader();
    matrix_scan_rgb_matrix();
    matrix_scan_keymap();
}