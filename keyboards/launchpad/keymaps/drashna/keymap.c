// Below layout is based upon /u/That-Canadian's planck layout
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _RGB 1
#define _FUNC 2

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-------------.
     * |   1  |  2   |
     * |------+------|
     * |   3  |  4   |
     * |------+------|
     * |   5  |  6   |
     * |------+------|
     * | FUNC | RGB  |
     * `-------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_1,      KC_2, \
        KC_3,      KC_4, \
        KC_5,      KC_6, \
        MO(_FUNC), TG(_RGB) \
      ),

    /* RGB
     * ,-------------.
     * | Mode-| Mode+|
     * |------+------|
     * | HUE- | HUE+ |
     * |------+------|
     * | SAT- | SAT+ |
     * |------+------|
     * |RGBTOG|      |
     * `-------------'
     */
    [_RGB] = LAYOUT( \
        RGB_RMOD, RGB_MOD, \
        RGB_HUD,  RGB_HUI, \
        RGB_SAD,  RGB_SAI, \
        RGB_TOG,  KC_TRNS \
      ),

    /* Function
     * ,-------------.
     * |   Q  |CALDEL|
     * |------+------|
     * |   A  |TSKMGR|
     * |------+------|
     * |   Z  |  X   |
     * |------+------|
     * |      |  C   |
     * `-------------'
     */
    [_FUNC] = LAYOUT( \
        KC_Q,    CALTDEL, \
        KC_A,    TSKMGR, \
        KC_Z,    KC_X, \
        _______, RESET \
      )

};
