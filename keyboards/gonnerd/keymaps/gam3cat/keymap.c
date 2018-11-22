#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _BL = 0,    // Base Layer
    _WL,        // Workman Layer
    _NL,        // Norman Layer
    _DL,        // Dvorak Layer
    _CL,        // Base Layer
    _FL,        // Function Layer
    _AL,        // Adjust Layer
};

<<<<<<< HEAD
enum custom_keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE,
    QMK_REV,
    KC_WEB,
    KC_SP4
};

static uint8_t current_layer;

=======
enum gonnerd_keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};

>>>>>>> upstream/master
#include "dynamic_macro.h"
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FN_CAPS LT(_FL, KC_CAPS)
#define KC_DMR1 DYN_REC_START1
#define KC_DMR2 DYN_REC_START2
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2
#define KC_DMRS DYN_REC_STOP

<<<<<<< HEAD
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*#### _BL: Base Layer - Standard TKL QWERTY layout.
    *    .-----------------------------------------------------------------------.
    *    |Esc|||||F1 |F2 |F3 |F4 |||F5 |F6 |F7 |F8 |||F9 |F10|F11|F12|PSc|SLk|Pau|
    *    |-----------------------------------------------------------|-----------|
    *    |~  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backsp |Ins|Hom|PgU|
    *    |-----------------------------------------------------------|-----------|
    *    |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    |Del|End|PgD|
    *    |-----------------------------------------------------------|-----------|
    *    |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |           |
    *    |-----------------------------------------------------------|-----------|
    *    |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift |Fn |   | Up|   |
    *    |-----------------------------------------------------------|-----------|
    *    |Ctrl |Win|Alt  |      Space                |RAlt |Fn |Ctrl |Lft|Dwn|Rgt|
    *    *-----------------------------------------------------------------------*
=======
static uint8_t current_layer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BL: Base Layer, mostly standard TKL QWERTY layout.
    *  .-----------------------------------------------------------------------.
    *  |Esc||||| F1| F2| F3| F4||| F5| F6| F7| F8||| F9|F10|F11|F12|PSc|SLk|Pau|
    *  |-----------------------------------------------------------|-----------|
    *  |  ~|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Ins|Hom|PgU|
    *  |-----------------------------------------------------------|-----------|
    *  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del|End|PgD|
    *  |-----------------------------------------------------------|-----------|
    *  |FnCaps|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |           |
    *  |-----------------------------------------------------------|-----------|
    *  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |   | Up|   |
    *  |-----------------------------------------------------------|-----------|
    *  |Ctrl |||||Win  |      Space                |RAlt |||||Ctrl |Lft|Dwn|Rgt|
    *  *-----------------------------------------------------------------------*
>>>>>>> upstream/master
    */
    [_BL] = LAYOUT_tkl( \
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, \
<<<<<<< HEAD
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,                             \
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FL),          KC_UP,            \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    /*#### _WL: Workman Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |Q  |D  |R  |W  |B  |J  |F  |U  |P  |;  |[  |]  |\    |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |A  |S  |H  |T  |G  |Y  |N  |E  |O  |I  |'  |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |Z  |X  |M  |C  |V  |K  |L  |,  |.  |/  |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
=======
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,                             \
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FL),          KC_UP,            \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT \
    ),

    /* _WL: Workman Layer.
    *  .-----------------------------------------------------------------------.
    *  |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  |   |   |   |   |   |   |   |   |   |   |   |  -|  =|       |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |  Q|  D|  R|  W|  B|  J|  F|  U|  P|  ;|  [|  ]|    \|   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |      |  A|  S|  H|  T|  G|  Y|  N|  E|  O|  I|  '|        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |  Z|  X|  M|  C|  V|  K|  L|  ,|  .|  /|      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |   |   |   |
    *  *-----------------------------------------------------------------------*
>>>>>>> upstream/master
    */
    [_WL] = LAYOUT_tkl( \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN, _______, _______, _______, _______, _______, _______, \
        _______, KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , _______, _______, _______,                            \
        _______, _______, KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   , KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH, _______, _______,          _______,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______ \
    ),
<<<<<<< HEAD
    /*#### _NL: Norman Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |Q  |W  |D  |F  |K  |J  |U  |R  |L  |;  |[  |]  |\    |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |A  |S  |E  |T  |G  |Y  |N  |I  |O  |H  |'  |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |Z  |X  |C  |V  |B  |P  |M  |,  |.  |/  |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
=======

    /* _NL: Norman Layer.
    *  .-----------------------------------------------------------------------.
    *  |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  |   |   |   |   |   |   |   |   |   |   |   |  -|  =|       |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |  Q|  W|  D|  F|  K|  J|  U|  R|  L|  ;|  [|  ]|    \|   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |      |  A|  S|  E|  T|  G|  Y|  N|  I|  O|  H|  '|        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |  Z|  X|  C|  V|  B|  P|  M|  ,|  .|  /|      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |   |   |   |
    *  *-----------------------------------------------------------------------*
>>>>>>> upstream/master
    */
    [_NL] = LAYOUT_tkl( \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_Q   , KC_W   , KC_D   , KC_F   , KC_K   , KC_J   , KC_U   , KC_R   , KC_L   , KC_SCLN, _______, _______, _______, _______, _______, _______, \
        _______, KC_A   , KC_S   , KC_E   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_I   , KC_O   , KC_H   , _______, _______, _______,                            \
        _______, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_P   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______, _______,          _______,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______ \
    ),
<<<<<<< HEAD
    /*#### _DL: Dvorak Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |[  |]  |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |'  |,  |.  |P  |Y  |F  |G  |C  |R  |L  |/  |=  |\    |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |A  |O  |E  |U  |I  |D  |H  |T  |N  |S  |-  |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |;  |Q  |J  |K  |X  |B  |M  |W  |V  |Z  |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
=======

    /* _DL: Dvorak Layer.
    *  .-----------------------------------------------------------------------.
    *  |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  |   |   |   |   |   |   |   |   |   |   |   |  [|  ]|       |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|    \|   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |      |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |   |   |   |
    *  *-----------------------------------------------------------------------*
>>>>>>> upstream/master
    */
    [_DL] = LAYOUT_tkl( \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, \
        _______, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_EQL , _______, _______, _______, _______, \
        _______, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS, _______, _______,                            \
        _______, _______, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , _______, _______,          _______,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______ \
    ),
<<<<<<< HEAD
    /*#### _CL: Colmak Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |Q  |W  |F  |P  |G  |J  |L  |U  |Y  |;  |[  |]  |\    |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |A  |R  |S  |T  |D  |H  |N  |E  |I  |O  |'  |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |Z  |X  |C  |V  |B  |K  |M  |,  |.  |/  |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
=======

    /* _CL: Colmak Layer.
    *  .-----------------------------------------------------------------------.
    *  |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  |   |   |   |   |   |   |   |   |   |   |   |  -|  =|       |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|    \|   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |      |  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '|        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |   |   |   |
    *  *-----------------------------------------------------------------------*
>>>>>>> upstream/master
    */
    [_CL] = LAYOUT_tkl( \
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______, _______, _______, _______, _______, _______, \
        _______, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , _______, _______, _______,                            \
        _______, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______, _______,          _______,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______ \
    ),
<<<<<<< HEAD
    /*#### _FL: Function Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |VlM|VlD|VlU|   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |Web|   |   |   |   |   |   |   |   |   |   |   |   |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |Fn_AL|   |   |   |   |   |   |   |   |   |   |   |   |     |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |   |   |   |   |   |   |Lft|Dwn|Up |Rgt|   |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |   |   |   |   |   |   |   |   |   |   |      |Fn |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |      SP4                  |     |Fn |     |WBk|   |WFw|
    *    *-----------------------------------------------------------------------*
    */
    [_FL] = LAYOUT_tkl( \
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_WEB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        MO(_AL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,          \
        XXXXXXX, XXXXXXX, KC_MENU,                            KC_SP4,                             XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_WBAK, XXXXXXX, KC_WFWD \
    ),
    /*#### _AL: Adjust Layer - Keymap select, LED backlight, and Dynamic Macro settings.
    *    .-----------------------------------------------------------------------.
    *    |Rst|||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |Rev|Tog|Mod|H- |H+ |S- |S+ |V- |V+ |   |BLT|BL-|BL+|       |   |MR1|MP1|
    *    |-----------------------------------------------------------|-----------|
    *    |Fn_AL|_BL|_WL|   |   |   |   |   |   |   |   |   |   |     | MS|MR2|MP2|
    *    |-----------------------------------------------------------|-----------|
    *    |      |   |   |_DL|   |   |   |   |   |   |   |   |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |   |   |_CL|   |_BL|_NL|   |   |   |   |      |Fn |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |Fn |     |   |   |   |
    *    *-----------------------------------------------------------------------*
    */
    [_AL] = LAYOUT_tkl( \
        RESET,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        QMK_REV, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, KC_DMR1, KC_DMP1, \
        _______, DF(_BL), DF(_WL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DMRS, KC_DMR2, KC_DMP2, \
        XXXXXXX, XXXXXXX, XXXXXXX, DF(_DL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_CL), XXXXXXX, DF(_BL), DF(_NL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,          \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMK_REV:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION ":" QMK_BUILDDATE);
            }
            return false;
            break;
        case KC_WEB:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                _delay_ms(100);
                SEND_STRING("chrome.exe\n");
            }
            return false;
            break;
        case KC_SP4:
            if (record->event.pressed) {
                SEND_STRING ("    ");
            }
            return false;
            break;
    }
    // Dynamic Macros.
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
=======

    /* _FL: Function Layer.
    *  M0 opens Chrome
    *  .-----------------------------------------------------------------------.
    *  |   |||||   |   |   |   |||   |   |   |   |||   |VlM|VlD|VlU|   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  | M0|   |   |   |   |   |   |   |   |   |   |   |   |       |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |Fn_AL|   |   |   |   |   |   |   |   |   |   |   |   |     |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |FnCaps|   |   |   |   |   |   |Lft|Dwn|Up |Rgt|   |        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |   |   |   |   |   |   |   |   |   |   |      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |WBk|   |WFw|
    *  *-----------------------------------------------------------------------*
    */
    [_FL] = LAYOUT_tkl( \
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, \
        M(0),    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        MO(_AL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,          \
        XXXXXXX, XXXXXXX, KC_MENU,                            M(1),                               XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_WBAK, XXXXXXX, KC_WFWD \
    ),

    /* _AL: Adjust Layer.
    *  Default keymap, RGB Underglow, LED backlight, and Dynamic Macro settings.
    *  .-----------------------------------------------------------------------.
    *  |Rst|||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *  .-----------------------------------------------------------|-----------|
    *  |Ver|Tog|Mod|H- |H+ |S- |S+ |V- |V+ |   |BLT|BL-|BL+|       |   |MR1|MP1|
    *  |-----------------------------------------------------------|-----------|
    *  |Fn_AL|_BL|_WL|   |   |   |   |   |   |   |   |   |   |     | MS|MR2|MP2|
    *  |-----------------------------------------------------------|-----------|
    *  |FnCaps|   |   |_DL|   |   |   |   |   |   |   |   |        |           |
    *  |-----------------------------------------------------------|-----------|
    *  |        |   |   |_CL|   |_BL|_NL|   |   |   |   |      |   |   |   |   |
    *  |-----------------------------------------------------------|-----------|
    *  |     |||||     |                           |     |||||     |   |   |   |
    *  *-----------------------------------------------------------------------*
    */
    [_AL] = LAYOUT_tkl( \
        RESET,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        F(0),    RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, KC_DMR1, KC_DMP1, \
        _______, DF(_BL), DF(_WL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DMRS, KC_DMR2, KC_DMP2, \
        _______, XXXXXXX, XXXXXXX, DF(_DL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_CL), XXXXXXX, DF(_BL), DF(_NL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,          \
        _______, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch(id) {
        case 0:
            if (record->event.pressed) {
                return MACRO(I(0), D(LGUI), T(R), U(LGUI), END);
            }
            else {
                SEND_STRING("chrome.exe\n");
                return false;
            }
        break;
        case 1:
            if (record->event.pressed) {
                return MACRO(I(0), T(SPC), T(SPC), T(SPC), T(SPC), END);
            }
            else {
                return false;
            }
        break;
    }
    return MACRO_NONE;
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(0),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING ("[QMK:" QMK_KEYBOARD ":" QMK_KEYMAP ":" QMK_VERSION "]");
            }
        break;
    }
>>>>>>> upstream/master
}

void matrix_init_user(void) {
    #ifdef BACKLIGHT_ENABLE
        backlight_level(0);
    #endif
}

<<<<<<< HEAD
=======
// Runs constantly in the background, in a loop.
>>>>>>> upstream/master
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    if (current_layer == layer) {
    }
    else {
        current_layer = layer;
<<<<<<< HEAD
        switch (current_layer) {
            case _BL:
                backlight_level(0);
                break;
            case _WL:
            case _NL:
            case _DL:
            case _CL:
                backlight_level(1);
                break;
            case _FL:
                backlight_level(2);
                break;
            case _AL:
=======
        switch (layer) {
            case 0:
                backlight_level(0);
                break;
            case 1:
                backlight_level(1);
                break;
            case 2:
                backlight_level(1);
                break;
            case 3:
                backlight_level(1);
                break;
            case 4:
                backlight_level(1);
                break;
            case 5:
                backlight_level(2);
                break;
            case 6:
>>>>>>> upstream/master
                backlight_level(3);
                break;
            default:
                backlight_level(0);
                break;
        }
    }
}

<<<<<<< HEAD
void led_set_user(uint8_t usb_led) {

=======
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Enable Dynamic Macros.
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
>>>>>>> upstream/master
}
