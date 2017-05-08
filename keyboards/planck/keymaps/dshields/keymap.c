#include "planck.h"
#include "backlight.h"
#include "config.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum planck_layers { DEF, LWR, RSE, FUN };
enum planck_keycodes { M1 = SAFE_RANGE, M2, M3, M4 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default
     * ,-----------------------------------------------------------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  | Esc  | Bksp |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   A  |   S  |   D  |   F  |   G  | Tab  | Enter|   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  | Shift| Play |   N  |   M  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Super| Alt  | Fun  | Lower|    Space    | Raise| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [DEF] = {
        {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,        KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
        {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,        KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
        {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    OSM(MOD_LSFT), XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
        {KC_LCTL, KC_LGUI, KC_LALT, TT(FUN), TT(LWR), KC_SPC,        KC_SPC,  TT(RSE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
    },
    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   !  |   @  |   #  |   $  |   %  |      |      |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |      |      |      |      |      |      |   _  |   +  |      |   {  |   }  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |   "  |   |  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [LWR] = {
        {KC_EXLM,   KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN,    KC_RPRN},
        {S(KC_GRV), _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, _______,  S(KC_LBRC), S(KC_RBRC)},
        {_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  S(KC_QUOT), S(KC_BSLS)},
        {_______,   _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP,    KC_END}
    },
    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   `  |      |      |      |      |      |      |   -  |   =  |      |   [  |   ]  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [RSE] = {
        {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,     KC_9,    KC_0},
        {KC_GRV,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______,  KC_LBRC, KC_RBRC},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_QUOT, KC_BSLS},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP, KC_END}
    },
    /* Function
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  | Reset|Delete|  F6  |  F7  |  F8  |  F9  | F10  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | F11  | F12  | F13  | F14  | F15  |      |      | F16  | F17  | F18  | F19  | F20  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |BlTggl|BlStep|      |  M1  |  M2  |      |      |  M3  |  M4  |MsBtn1|MsBtn2|MsBtn3|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |MsLeft|MsDown| MsUp |MsRght|
     * `-----------------------------------------------------------------------------------'
     */
    [FUN] = {
        {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RESET,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10},
        {KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20},
        {BL_TOGG, BL_STEP, _______, M1,      _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R}
    },

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M1:
            if (record->event.pressed) {
                SEND_STRING(" 2>&1 > ");
            }
            return false;
            break;
    }
    return true;
}

void matrix_init_user(void) {
}

