/* Copyright 2019 Brandon Schlack
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
#include "brandonschlack.h"

/**
 * Layer Names
 *
 * Layers mostly used for macro keys
 */
#define _REEDER   _M1
#define _NAV      _M2
#define _MOUSE    _M3

/**
 * Keycodes & Macros
 */
#define TG_BASE   TO(_BASE)
#define TG_REDR   TO(_REEDER)
#define TG_NAV    TO(_NAV)
#define TG_MOUS   TO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/**
 * Base
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Hom│││Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│Bck│
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │PgU│││Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter│
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │PgD│││Shift │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│Shft│ Fn│
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │End││││││││Opt│Cmd │                           │ Cmd│Ctl││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_BASE] = LAYOUT_default( \
    KC_HOME,   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_PGUP,   HY_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_PGDN,            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, PLY_FN1, \
    KC_END,                      KC_LOPT, KC_LCMD,                            SPC_RAI,                            KC_RCMD, KC_RCTL  \
),

/**
 * Reeder
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ P │││   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │ K │││    │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │ J │││      │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │ N ││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */

[_REEDER] = LAYOUT_default( \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Nav
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ → │││   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │ ↑ │││    │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │ ↓ │││      │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │ ← ││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_NAV] = LAYOUT_default( \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Mouse
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │WhU│││   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │ ↑ │││    │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │ ↓ │││      │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │WhD││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_MOUSE] = LAYOUT_default( \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Lower
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Nxt│││Del│BrD│BrU│Msn│LHP│   │   │   │   │   │   │ ↑ │Mut│SlD│
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │VlU│││    │   │   │NxW│PvT│Bck│Fwd│NxT│   │   │ ← │ → │ Play │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │VlD│││SftCap│   │   │   │1PX│1Ps│   │   │   │   │ ↓ │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │Prv││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_LOWER] = LAYOUT_default( \
    KC_MNXT,   KC_DELT, KC_BRMD, KC_BRMU, MC_MSSN, MC_LHPD, _______, _______, _______, _______, _______, _______, KC_UP,   KC_MUTE, MC_SLPD, \
    KC_VOLU,   _______, _______, _______, NXT_WIN, PRV_TAB, MC_BACK, MC_FWRD, NXT_TAB, _______, _______, KC_LEFT, KC_RGHT,          KC_MPLY, \
    KC_VOLD,            SF_CAPS, _______, _______, _______, PX_AFLL, OP_AFLL, _______, _______, _______, _______, KC_DOWN, _______, _______, \
    KC_MPRV,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Raise
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Nxt│││~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │VlU│││    │ F1│ F2│ F3│ F4│ F5│ F6│_ -│+ =│   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │VlD│││      │ F7│ F8│ F9│F10│F11│F12│   │   │   │| \│    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │Prv││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_RAISE] = LAYOUT_default( \
    KC_MNXT,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, \
    KC_VOLU,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  _______, _______, _______,          _______, \
    KC_VOLD,            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_BSLS, _______, _______, \
    KC_MPRV,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Adjust
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │Bse│││Mke│   │   │EEP│RST│   │   │   │   │   │   │   │   │   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │Rdr│││    │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │Nav│││      │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │Mse││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
[_ADJUST] = LAYOUT_default( \
    TG_BASE,   QM_MAKE, _______, _______, EEP_RST, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    TG_REDR,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    TG_NAV,             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    TG_MOUS,                     _______, _______,                            _______,                            _______, _______  \
),

/**
 * Blank
 * ┌───┬┬┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │││   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┼┼┼───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │   │││    │   │   │   │   │   │   │   │   │   │   │   │      │
 * ├───┼┼┼────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬───┤
 * │   │││      │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├───┼┼┼┬┬┬┬┬─┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┼───┬┼┬┬┬┤
 * │   ││││││││   │    │                           │    │   ││││││
 * └───┴┴┴┴┴┴┴┴───┴────┴───────────────────────────┴────┴───┴┴┴┴┴┘
 */
/*
[] = LAYOUT_default( \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,                     _______, _______,                            _______,                            _______, _______  \
),
*/
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
