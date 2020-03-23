#include "spidey3.h"

#define CH_MENU A(S(KC_S))
#define OSX_PSC G(S(KC_4))
#define FN_MENU LT(_FN,KC_APP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Linux / Win layout
    [_BASE] = LAYOUT_75_ansi(
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_INS,     KC_DEL,
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,                 KC_BSPC,    KC_HOME,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,                KC_BSLS,    KC_PGUP,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                            KC_ENT,     KC_PGDN,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                            KC_RSFT,    KC_UP,      KC_END,
        KC_LCTL,    KC_LGUI,    KC_LALT,                                    KC_SPC,                                             KC_RALT,    FN_MENU,    KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),
    // OSX layout
    [_OSX] = LAYOUT_75_ansi(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    OSX_PSC,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,
        _______,    KC_LALT,    KC_LGUI,                                    _______,                                            _______,    _______,    _______,    _______,    _______,    _______
    ),
    // Numpad
    [_NUMPAD] = LAYOUT_75_ansi(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_NUMLOCK, KC_PEQL,    KC_PSLS,    KC_PAST,    XXXXXXX,    XXXXXXX,    _______,    _______,    _______,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PSLS,    XXXXXXX,    XXXXXXX,                _______,    _______,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PAST,    _______,    _______,                _______,    _______,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PMNS,    KC_SCLN,                            KC_PENT,    _______,
        _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_KP_0,    KC_PDOT,    KC_PCMM,    KC_PPLS,                            _______,    _______,    _______,
        _______,    _______,    _______,                                    _______,                                            _______,    _______,    _______,    _______,    _______,    _______
    ),
    // FN
    [_FN] = LAYOUT_75_ansi(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_SLEP,    KC_WAKE,    KC_PWR,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    X_BUL,      _______,    _______,    X_DASH,     _______,                RESET,      EEP_RST,
        _______,    RGB_TOG,    RGB_MOD,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_VAD,    RGB_VAI,    RGB_SPD,    RGB_SPI,    VLK_TOG,    _______,                KC_PAUS,    KC_VOLU,
        _______,    RGB_M_P,    RGB_M_B,    RGB_M_R,    RGB_M_SW,   RGB_M_SN,   RGB_M_K,    RGB_M_G,    RGB_M_T,    SPI_LNX,    _______,    _______,                            _______,    KC_VOLD,
        _______,    SPI_GLO,    _______,    SPI_WIN,    _______,    _______,    TG(_NUMPAD),SPI_OSX,    X(LARR),    X(RARR),    DEBUG,      _______,                            KC_BRIU,    KC_MUTE,
        _______,    _______,    _______,                                    _______,                                            KC_APP,     _______,    CH_MENU,    _______,    KC_BRID,    KC_SLCK
    )
};
