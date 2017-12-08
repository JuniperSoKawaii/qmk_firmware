#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers
{
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _AMYTHEST
};

enum planck_keycodes
{
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    EXT_PLV,
    AMYTHEST
};

// enum
// {
//     TD_SPC_SFT = 0
// };

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_SPC_SFT] = ACTION_TAP_DANCE_DOUBLE(KC~)
//}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/~ |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |(LShft|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |RShft)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TBC1 | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 * 
 * TBC1 - toggle Iterm
 * LShift - Shift when held / Caps when tapped
 * Enter - MOD TAP with ENTER / R.SHIFT If held
 * Esc - Esc then ~ when pressed with Shift
 */
        [_QWERTY] = {
            {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
            {KC_GESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
            {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, MT(MOD_RSFT, KC_ENTER)},
            {LCTL(KC_GRAVE), KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT}},

        /* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Mute |  F1  |  F2  |  F3  |   [  |   *  |   +  |   ]  |      |  7   |  8   |  9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ |  F4  |  F5  |  F6  |   {  |   /  |   -  |   }  |      |  4   |  5   |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |  F7  |  F8  |  F9  |   (  |   |  |   \  |   )  |   0  |  1   |  2   |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F10 |  F11 |  F12 | |||| |             | |||| | Home |PG Up |PG Dn | End  |
 * `-----------------------------------------------------------------------------------'
 *
 * Proposed Additions:
 * CMD+~ to bring up iterm
 * AMY - Amythest Layer
 */
        [_LOWER] = {
            {KC_MUTE, KC_F1, KC_F2, KC_F3, _______, KC_LCBR, KC_RCBR, KC_SLASH, KC_ASTERISK, KC_KP_7, KC_KP_8, KC_KP_9}, 
            {KC_VOLU, KC_F4, KC_F5, KC_F6, _______, KC_LPRN, KC_RPRN, KC_MINUS, KC_PLUS, KC_KP_4, KC_KP_5, KC_KP_6}, 
            {KC_VOLD, KC_F7, KC_F8, KC_F9, _______, KC_PIPE, KC_BSLASH, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3}, 
            {_______, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
        },

        /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | PgUp |PgDwn |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | Home | End  |   _  |   {  |   }  |   (  |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
        [_RAISE] = {
            {KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL}, 
            {KC_MS_ACCEL0, KC_BTN2, KC_MS_UP, KC_BTN1, KC_MS_WH_UP, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS}, 
            {KC_MS_ACCEL1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_LPRN, KC_RPRN, KC_UNDS, KC_NUBS, KC_PGUP, KC_PGDN, _______}, 
            {KC_MS_ACCEL2, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_VOLD, KC_VOLU, KC_MEDIA_NEXT_TRACK}
        },

        /* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |BL_TOG|BL_STP|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
        [_ADJUST] = {
            {_______, RESET, DEBUG, _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL}, 
            {_______, _______, MU_MOD, AU_ON, AU_OFF, AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______}, 
            {_______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, BL_TOGG, BL_STEP, _______, _______}, 
            {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
        },

        /* Amythest ()
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 * Set Focused window as main: LALT(LSFT(KC_ENTER))
 * Cycle Layout Fwd : Alt + Shift + Space : LALT(LSFT(KC_SPACE))
 * Cycle Layout Bk : Ctrl + Alt + Shift + Space : LCTL(LALT(LSFT(KC_SPACE)))
 * Shrink Main Pane : Alt + Shift + H : LALT(LSFT(KC_H))
 * Expand Main Pane : Alt + Shft + L : LALT(LSFT(KC_L))
 * Move Focus CCW : Alt + Shift + J : LALT(LSFT(KC_J))
 * Move Focus CW : Alt + Shift + K : LALT(LSFT(KC_K))
 * Increase Main Pane Count : Alt +  Shift + , : LALT(LSFT(KC_COMMA))
 * Decrease Main Pane Count : Alt + Shift + . : LALT(LSFT(KC_DOT))
 */
        [_AMYTHEST] = {{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}, {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}, {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}, {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}}

};

//#ifdef AUDIO_ENABLE
//#float plover_song[][2] = SONG(PLOVER_SOUND);
//#float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
//#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case QWERTY:
        if (record->event.pressed)
        {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed)
        {   
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else
        {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed)
        {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else
        {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    }
    return true;
}
