/* Copyright 2022 Clickety Split Ltd.
 *                https://clicketysplit.ca
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
#include "leeloo.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.                ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  LGUI |                | RGUI  |------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |-------|                |-------|   N  |   M  |   ,  |   .  |   /  |RSHIFT|
 * `-----------------------------------------/       /                 \      \-----------------------------------------'
 *                | LALT  | LCTL  | ENT   | / MINS  /                   \ EQL  \  | SPC   | BSPC  |  DEL  |
 *                |       |       | LOWR  |/ RAISE /                     \RAISE \ | LOWR  |       |       |
 *                `-------------------------------'                       '------''-----------------------'
 */
 [_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LGUI,         KC_RGUI, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
               KC_LALT, KC_LCTL, LT(1,KC_ENT), LT(2,KC_MINS),         LT(2,KC_EQL), LT(1,KC_SPC), KC_BSPC, KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * |      |      |      |      |      |      |                                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |   <  |   (  |   [  |   {  |--------.               ,-------|   }  |   ]  |   )  |   >  |      |      |
 * |------+------+------+------+------+------|        |               |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|               |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /                 \      \-----------------------------------------'
 *                | LALT  | LCTL  | ENT   | / MINS  /                   \ EQL  \  | SPC   | BSPC  |  DEL  |
 *                |       |       | LOWR  |/ RAISE /                     \RAISE \ | LOWR  |       |       |
 *                `-------------------------------'                       '------''-----------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  _______, _______, KC_LABK, KC_LPRN, KC_LBRC, KC_LCBR,                        KC_RCBR, KC_RBRC, KC_RPRN, KC_RABK, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,      _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                                | PGUP | HOME |  UP  |  END |      |  F12 |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.                ,-------| PGDN | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------|       |                |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|                |-------|      | LWRD |      | RWRD |      |      |
 * `-----------------------------------------/       /                 \      \-----------------------------------------'
 *                | LALT  | LCTL  | ENT   | / MINS  /                   \ EQL  \  | SPC   |  DEL  |  DEL  |
 *                |       |       | LOWR  |/ RAISE /                     \RAISE \ | LOWR  |       |       |
 *                `-------------------------------'                       '------''-----------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                        KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_F12,
  _______, _______, _______, _______, _______, _______,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, C(KC_LEFT), _______, C(KC_RGHT), _______, _______,
                             _______, _______, _______, _______,      _______, _______, KC_DEL,     _______
),
/* ADJUST
 * ,-----------------------------------------.                                ,-----------------------------------------.
 * |      |      |      |      |      |      |                                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------.               ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |               |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|               |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /                 \      \-----------------------------------------'
 *                | LALT  | LCTL  | ENT   | / MINS  /                   \ EQL  \  | SPC   | BSPC  |  DEL  |
 *                |       |       | LOWR  |/ RAISE /                     \RAISE \ | LOWR  |       |       |
 *                `-------------------------------'                       '------''-----------------------'
 */
  [_ADJUST] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,    _______, _______, _______, _______
)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;
    return rotation;
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock: "), false);
    oled_write_P(PSTR("CAPS"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("NUML"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("SCLK"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(PSTR("Sft"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Ctl"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Alt"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
}

void render_secondary_oled(void) {
    // Version Information
    oled_write_P(PSTR("Leeloo\n\n"), false);
    oled_write_P(PSTR("Firmware: "), false);
    oled_write_P(PSTR(LEELOO_VERSION), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Clickety Split Ltd."), false);
}

static void render_status(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QWERTY | "), false);
            break;
    }

    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base   \n"), false);
            break;

        case _LOWER:
            oled_write_P(PSTR("Lower   \n"), false);
            break;

        case _RAISE:
            oled_write_P(PSTR("Raise   \n"), false);
            break;

        case _ADJUST:
            oled_write_P(PSTR("Adjust  \n"), false);
            break;

        default:
            oled_write_P(PSTR("Unknown \n"), false);
    }

    oled_write_P(PSTR("\n"), false);
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods() | get_oneshot_mods());
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        render_status();
    } else {
        // Version Information
        render_secondary_oled();
    }

    return false;

}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }

    return false;

}
#endif
