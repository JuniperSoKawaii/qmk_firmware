#include QMK_KEYBOARD_H

/*
* Each layer gets a name for readability. The underscores don't mean anything - you can
* have a layer called STUFF or any other name. Layer names don't all need to be of the same
* length, and you can also skip them entirely and just use numbers.
*
* Based on `dz60/zvecr`
*
*/
#define BASE    0    // Layer: Base
#define ACTN    1    // Layer: Action
#define FUNC    2    // Layer: Function
#define KEYB    3    // Layer: Keyboard


/* Bonfire's Keyboard
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │  0e   │        14
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │        14
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │        13
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3b │3d    │3e │        13
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┴───┤
 * │40  │41  │43  │46                      │4a  │4b  │4d  │4e  │        8
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT__bonfire(
		KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,    KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,   KC_BSPC,
		KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,
		MO(ACTN), KC_A,    KC_S,    KC_D,   KC_F,    KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, FN0,     MO(FUNC),
		KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, KC_RALT, FN2,  FN1,  FN3,
    ),

    [ACTN] = LAYOUT__bonfire(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, FN4,     _______,
        _______, _______, _______, _______, _______, _______, FN5,     FN6,     FN7
    ),

	[FUNC] = LAYOUT__bonfire(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,  _______, _______,
		KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP,  _______,
		_______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, KC_DEL,  KC_END,  KC_PGDN, MO(KEYB), _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

	[KEYB] = LAYOUT__bonfire(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, 
		_______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______
    )

};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_UP),
    [1] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_DOWN),
    [2] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_LEFT),
    [3] = ACTION_MODS_TAP_KEY(MOD_APP, KC_RIGHT),
    [4] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_PGUP),
    [6] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_PGDN),
    [7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_HOME),
    [8] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_END),
};
