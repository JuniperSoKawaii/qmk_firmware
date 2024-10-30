// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* Keymap for 3x4 Macropad
 *
 * Layer 0 (Base Layer) - Numpad layout with mute button and layer toggle:
 * ,----------------------,
 * |   7   |   8   |   9   |  MUTE  |
 * |-------+-------+-------+--------|
 * |   4   |   5   |   6   | Layer1 |
 * |-------+-------+-------+--------|
 * |   1   |   2   |   3   |   0   |
 * `-----------------------^--------'
 *
 * Layer 1 (Function Layer) - Accessed by holding MO(1):
 * ,----------------------,
 * | BKSP  |   /   |   -   |  ----  |
 * |-------+-------+-------+--------|
 * |   =   |   *   |   +   |  ----  |
 * |-------+-------+-------+--------|
 * | ENTER |  ---- |  ---- |   .    |
 * `-----------------------^--------'
 *
 * The base layer (0) provides standard numpad functionality with:
 * - Numbers 0-9 in traditional numpad layout
 * - Mute button in top right
 * - Layer 1 momentary toggle (MO1) in middle right
 *
 * The function layer (1) adds:
 * - Basic mathematical operators (+, -, *, /)
 * - Backspace, Enter, and decimal point
 * - Equal sign for calculations
 * - Empty slots marked as ---- (KC_NO)
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_3x4(
        KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_MUTE,
        KC_KP_4,    KC_KP_5,    KC_KP_6,    MO(1),
        KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_KP_0
    ),

    [1] = LAYOUT_ortho_3x4(
        KC_BACKSPACE, KC_KP_SLASH,    KC_KP_MINUS, KC_NO,
        KC_EQUAL,     KC_KP_ASTERISK, KC_KP_PLUS,  KC_NO,
        KC_ENTER,     KC_NO,          KC_NO,       KC_KP_DOT
    )
};


/*
 * Handle rotary encoder rotation events
 *
 * Maps encoder rotation to volume control:
 * - Clockwise rotation increases volume (KC_VOLU)
 * - Counter-clockwise rotation decreases volume (KC_VOLD)
 */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}


/*
 * Handle layer state changes by updating RGB matrix colors
 *
 * Sets RGB matrix colors based on active layer:
 * - Layer 0: Light green (#88FB7A)
 * - Layer 1: Red
 * - Other layers: Red (fallback)
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgb_matrix_sethsv(85, 255, 251); // #88FB7A for layer 0
        break;
    case 1:
        rgb_matrix_sethsv(0, 255, 255); // Red for layer 1
        break;
    default:
        rgb_matrix_sethsv(0, 255, 255); // Red for any other layer
        break;
    }
    return state;
}

/*
 * Initialize keyboard settings after firmware startup
 *
 * Performs initial setup operations:
 * 1. Enables the RGB matrix
 * 2. Sets initial layer state colors
 * 3. Initializes VIA support
 */
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    layer_state_set_user(layer_state);
    via_init();
}
