// Copyright 2022 IBNobody (@IBNobody)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┌───┬───┬───┬───┐
     * │Esc│Tab│ F1│Cal│Bsp│
     * ├───┼───┼───┼───┼───┤
     * │Ctr│Num│ / │ * │ - │
     * ├───┼───┼───┼───┼───┤
     * │Gui│ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┤ + │
     * │Alt│ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤
     * │Shi│ 1 │ 2 │ 3 │   │
     * ├───┼───┴───┼───┤Ent│
     * │MO1│ 0     │ . │   │
     * └───┴───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_6x5(
        KC_GESC,   KC_TAB,   KC_F1,   KC_CALC, KC_BSPC,
        KC_LCTRL,  KC_NLCK,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_LGUI,   KC_P7,    KC_P8,   KC_P9,   KC_PPLS,
        KC_LALT,   KC_P4,    KC_P5,   KC_P6,
        KC_LSHIFT, KC_P1,    KC_P2,   KC_P3,   KC_PENT,
        MO(1),     KC_P0,             KC_PDOT
    ),

    /*
     * ┌───┌───┐───┬───┬───┐
     * │Rst│TOG│MOD│PSc│SLk│
     * ├───┼───┼───┼───┼───┤
     * │Hu+│   │Sp-│Sp+│Br-│
     * ├───┼───┼───┼───┼───┤
     * │Hu-│Hom│ ↑ │PgU│   │
     * ├───┼───┼───┼───┤Br+│
     * │St+│ ← │   │ → │   │
     * ├───┼───┼───┼───┤───┤
     * │St-│End│ ↓ │PgD│   │
     * ├───┼───┴───┼───┤Ent│
     * │mo1│Insert │Del│   │
     * └───┴───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_6x5(
        QK_BOOT, RGB_TOG, RGB_MOD, KC_PSCR, KC_SCRL,
        RGB_HUI, XXXXXXX, RGB_SPD, RGB_SPI, RGB_VAD,
        RGB_HUD, KC_HOME, KC_UP,   KC_PGUP, RGB_VAI,
        RGB_SAI, KC_LEFT, XXXXXXX, KC_RGHT,
        RGB_SAD, KC_END,  KC_DOWN, KC_PGDN, KC_ENT,
        _______, KC_INS,           KC_DEL
    )
};
