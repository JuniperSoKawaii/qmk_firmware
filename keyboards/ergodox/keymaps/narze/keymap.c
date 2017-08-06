#include "ergodox.h"
// #include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"
#include "eeprom.h"
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

enum ergodox_layers {
  _QWERTY,
  _COLEMAK,
  _QWOC,
  _LOWER,
  _RAISE,
  _PLOVER,
  _SUPERDUPER,
  _MOUSE,
  _ADJUST,
  _MDIA,
  _SYMB,
};

enum ergodox_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  QWOC,
  PLOVER,
  SUPERDUPER,
  MOUSE,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  SDTOGG, // Toggle SuperDuper
  EPRM,
  VRSN,
  RGB_SLD
};

enum functions {
  M_GUI_UNDS, // Simulate GUI_T(KC_UNDS)
  M_SFT_PO, // SFT_T(KC_LPRN)
  M_SFT_PC, // SFT_T(KC_RPRN)
};

// Timer for custom mod tap
static uint16_t m_gui_unds_timer;
static uint16_t m_sft_po_timer;
static uint16_t m_sft_pc_timer;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Narze : Custom Macros
#define HPR_ESC ALL_T(KC_ESC)
#define SFT_ENT SFT_T(KC_ENT)
#define SFT_PO F(M_SFT_PO)
#define SFT_PC F(M_SFT_PC)
#define GUI_MINS GUI_T(KC_MINS)
#define GUI_UNDS F(M_GUI_UNDS)

// Combo : SuperDuper layer from S+D (R+S in Colemak)
#define COMBO_COUNT 1
#define SUPERDUPER_COMBO_COUNT 3
#define EECONFIG_SUPERDUPER_INDEX (uint8_t *) 19

enum process_combo_event {
  CB_SUPERDUPER,
};

const uint16_t PROGMEM superduper_combos[SUPERDUPER_COMBO_COUNT][3] = {
  [_QWERTY] = {KC_S, KC_D, COMBO_END},
  [_COLEMAK] = {KC_R, KC_S, COMBO_END},
  [_QWOC] = {CM_S, CM_D, COMBO_END},
};

combo_t PROGMEM key_combos[COMBO_COUNT] = {
  [CB_SUPERDUPER] = COMBO_ACTION(superduper_combos[_QWERTY]),
};

volatile bool superduper_enabled = true;

const uint16_t empty_combo[] = {COMBO_END};

void set_superduper_key_combos(void);
void clear_superduper_key_combos(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Mdia |           | Mdia |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Symb |           | Symb |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hp/Esc |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | Sft/(  | Z/Mo |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | SD-/ | Sft/)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Rse/[ | Ctrl |  Alt | Gui/_| Lwr/␠|                                       | Rse/␠| GUI/-|  Alt | Ctrl | Low/]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Enter| LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| Back |------|       |------| Back   |Enter |
 *                                 |      | Space| End  |       | PgDn | Space  |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(_MDIA),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(_SYMB),
        HPR_ESC,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        SFT_PO,         LT(_MOUSE, KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(RAISE, KC_LBRC),KC_LCTL,   KC_LALT,  GUI_UNDS, LT(LOWER, KC_SPC),
                                              KC_ENT,  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             TG(_MDIA),   KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(_SYMB),   KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM,KC_DOT, LT(_SUPERDUPER, KC_SLSH),   SFT_PC,
                                  LT(RAISE, KC_SPC), GUI_MINS,KC_RALT,KC_RCTL, LT(_LOWER, KC_RBRC),
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_ENT
    ),
/* Colemak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Mdia |           | Mdia |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  | Symb |           | Symb |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hp/Esc |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | Sft/(  | Z/Mo |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  | SD-/ | Sft/)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Rse/[ | Ctrl |  Alt | Gui/_| Lwr/␠|                                       | Rse/␠| GUI/-|  Alt | Ctrl | Low/]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Enter| LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| Back |------|       |------| Back   |Enter |
 *                                 |      | Space| End  |       | PgDn | Space  |      |
 *                                 `--------------------'       `----------------------'
 */
[_COLEMAK] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(_MDIA),
        KC_TAB,         KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(_SYMB),
        HPR_ESC,        KC_A,         KC_R,   KC_S,   KC_T,   KC_D,
        SFT_PO,         LT(_MOUSE, KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(RAISE, KC_LBRC),KC_LCTL,   KC_LALT,  GUI_UNDS, LT(LOWER, KC_SPC),
                                              KC_ENT,  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             TG(_MDIA),   KC_6,   KC_7,  KC_8,   KC_9,   KC_0,          KC_MINS,
             TG(_SYMB),   KC_J,   KC_L,  KC_U,   KC_Y,   KC_SCLN,       KC_BSLS,
                          KC_H,   KC_N,  KC_E,   KC_I,   KC_O,          KC_QUOT,
             MEH_T(KC_NO),KC_K,   KC_M,  KC_COMM,KC_DOT, LT(_SUPERDUPER, KC_SLSH),   SFT_PC,
                                  LT(RAISE, KC_SPC), GUI_MINS,KC_RALT,KC_RCTL, LT(_LOWER, KC_RBRC),
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_ENT
    ),
/* Qwerty on software Colemak : Useful for gaming with qwerty keymaps! */
[_QWOC] = KEYMAP(
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(_MDIA),
        KC_TAB,         CM_Q,         CM_W,   CM_E,   CM_R,   CM_T,   TG(_SYMB),
        HPR_ESC,        CM_A,         CM_S,   CM_D,   CM_F,   CM_G,
        SFT_PO,         LT(_MOUSE, CM_Z),  CM_X,   CM_C,   CM_V,   CM_B,   ALL_T(KC_NO),
        LT(RAISE, KC_LBRC),KC_LCTL,   KC_LALT,  GUI_UNDS, LT(LOWER, KC_SPC),
                                              KC_ENT,  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             TG(_MDIA),   KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(_SYMB),   CM_Y,   CM_U,  CM_I,   CM_O,   CM_P,             KC_BSLS,
                          CM_H,   CM_J,  CM_K,   CM_L,   CM_SCLN,          KC_QUOT,
             MEH_T(KC_NO),CM_N,   CM_M,  CM_COMM,CM_DOT, LT(_SUPERDUPER, KC_SLSH),   SFT_PC,
                                  LT(RAISE, KC_SPC), GUI_MINS,KC_RALT,KC_RCTL, LT(_LOWER, KC_RBRC),
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_ENT
    ),
/* Lower
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |  ^   |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   _  |   +  |   {  |   }  |   |    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |ISO ~ |ISO | |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                 KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
       _______,  KC_F12,S(KC_NUHS),S(KC_NUBS), _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |  6   |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   -  |   =  |   [  |   ]  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |ISO ~ |ISO | |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                 KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
       _______,  KC_F12,S(KC_NUHS),S(KC_NUBS), _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Plover
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   #    |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Hp/Esc |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Sft/(  |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Exit |      |      |   A  |   O  |                                       |   E  |   U  |      |      |        |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Enter| LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| Back |------|       |------| Back   |Enter |
 *                                 |      | Space| End  |       | PgDn | Space  |      |
 *                                 `--------------------'       `----------------------'
 */
[_PLOVER] = KEYMAP(
        // left hand
        KC_1,           KC_1,         KC_1,   KC_1,   KC_1,   KC_1,   XXXXXXX,
        XXXXXXX,        KC_1,         KC_1,   KC_1,   KC_1,   KC_1,   XXXXXXX,
        XXXXXXX,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,
        XXXXXXX,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   XXXXXXX,
        EXT_PLV,        XXXXXXX,      XXXXXXX,KC_C,   KC_V,
                                                      KC_ENT, KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             XXXXXXX,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,             XXXXXXX,
             XXXXXXX,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,             XXXXXXX,
                        KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
             XXXXXXX,   KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
                                  KC_N,    KC_M,XXXXXXX,XXXXXXX,         XXXXXXX,
             KC_LALT, CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_BSPC, KC_ENT
    ),

/* SuperDuper : https://gist.github.com/narze/861e2167784842d38771
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  T←  |  T→  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  | [SuperDuper]| Bksp | Gui  |------|           |------|   ←  |  ↓   |   ↑  |  →   | Del  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Shift|      |------|       |------|        |Shift |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_SUPERDUPER] = KEYMAP(
        // left hand
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, KC_LALT,  _______,   _______,   KC_BSPC,   KC_LGUI,
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, _______,  _______,   _______,   _______,
                                                    _______,  _______,
                                                              _______,
                                               KC_LSFT,_______,_______,
        // right hand
             _______, _______,  _______,   _______,  _______,   _______,   _______,
             _______, _______,  _______,   S(LGUI(KC_LBRC)), S(LGUI(KC_RBRC)),   _______,   _______,
                      KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT,   KC_DEL,    _______,
             _______, _______,  _______,   _______,  _______,   _______,   _______,
                                _______,   _______,  _______,   _______,   _______,
             _______,        _______,
             _______,
             _______,_______, KC_LSFT
    ),

/* Mouse
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  S↑  |  M↑  |  S↓  |      |      |           |      |      |      |  S↑  |  S↓  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  M←  |  M↓  |  M→  |      |------|           |------|  M←  |  M↓  |  M↑  |  M→  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |[Mouse|      |      |      |  M3  |      |           |      |  M3  |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  M2  |                                       |  M2  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Left |      |------|       |------|        | Left |
 *                                 | Click|      |      |       |      |        | Click|
 *                                 `--------------------'       `----------------------'
 */
[_MOUSE] = KEYMAP(
        // left hand
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, _______,  KC_WH_U,   KC_MS_U,   KC_WH_D,   _______,   _______,
        _______, _______,  KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,
        _______, _______,  _______,   _______,   _______,   KC_BTN3,   _______,
        _______, _______,  _______,   _______,   KC_BTN2,
                                                    _______,  _______,
                                                              _______,
                                               KC_BTN1,_______,_______,
        // right hand
             _______, _______,  _______,   _______,  _______,   _______,   _______,
             _______, _______,  _______,   KC_WH_U,  KC_WH_D,   _______,   _______,
                      KC_MS_L,  KC_MS_D,   KC_MS_U,  KC_MS_R,   _______,    _______,
             _______, KC_BTN3,  _______,   _______,  _______,   _______,   _______,
                                KC_BTN2,   _______,  _______,   _______,   _______,
             _______,        _______,
             _______,
             _______,_______, KC_BTN1
    ),

/* Adjust (Lower + Raise)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |Reset |      |      |      |      |      |           |      |      |      |      |      |      |  Del   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |AGnorm|------|           |------|AGswap|Qwerty|Colemk|QwOnCo|Plover|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |SDTogg|      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_ADJUST] = KEYMAP(
        // left hand
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, RESET,    _______,   _______,   _______,   _______,   _______,
        _______, _______,  _______,   _______,   _______,   AG_NORM,
        _______, _______,  _______,   _______,   _______,   _______,   _______,
        _______, _______,  _______,   _______,   _______,
                                                    _______,  _______,
                                                              _______,
                                               _______,_______,_______,
        // right hand
             _______, _______,  _______,   _______,  _______,   _______,   _______,
             _______, _______,  _______,   _______,  _______,   _______,   KC_DEL,
                      AG_SWAP,  QWERTY,    COLEMAK,  QWOC,      PLOVER,    _______,
             _______, SDTOGG,   _______,   _______,  _______,   _______,   _______,
                                _______,   _______,  _______,   _______,   _______,
             _______,        _______,
             _______,
             _______,_______, _______
    ),

/* Layers below are not actively used but kept for future reference */

/* Symbol
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_SYMB] = KEYMAP(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       _______,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,_______,
       _______,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,_______,
          EPRM,_______,_______,_______,_______,
                                       RGB_MOD,_______,
                                               _______,
                               RGB_VAD,RGB_VAI,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, _______,
                         _______,KC_DOT,  KC_0,    KC_EQL,  _______,
       RGB_TOG, RGB_SLD,
       _______,
       _______, RGB_HUD, RGB_HUI
),
/* Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_MDIA] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_setup(void) {
  set_superduper_key_combos();
}

void set_superduper_key_combos(void) {
  uint8_t layer = eeprom_read_byte(EECONFIG_SUPERDUPER_INDEX);

  switch (layer) {
    case _QWERTY:
    case _COLEMAK:
    case _QWOC:
      key_combos[CB_SUPERDUPER].keys = superduper_combos[layer];
      break;
  }
}

void clear_superduper_key_combos(void) {
  key_combos[CB_SUPERDUPER].keys = empty_combo;
}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
}

// Combos

void process_combo_event(uint8_t combo_index, bool pressed) {
  if (pressed) {
    switch(combo_index) {
      case CB_SUPERDUPER:
        layer_on(_SUPERDUPER);
        break;
    }
  } else {
    layer_off(_SUPERDUPER);
    unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); // Sometimes mods are held, unregister them
  }
}

// Macros

const uint16_t PROGMEM fn_actions[] = {
  [M_GUI_UNDS] = ACTION_MACRO_TAP(M_GUI_UNDS),
  [M_SFT_PO] = ACTION_MACRO_TAP(M_SFT_PO),
  [M_SFT_PC] = ACTION_MACRO_TAP(M_SFT_PC),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  bool tap_not_interrupted = record->tap.count > 0 && !record->tap.interrupted;

  switch(id) {
    // Hold for LGUI, tap for Underscore
    case M_GUI_UNDS:
      if (record->event.pressed) {
        m_gui_unds_timer = timer_read();

        if (!tap_not_interrupted) {
          register_mods(MOD_BIT(KC_LGUI));
        }
      } else {
        if (tap_not_interrupted && timer_elapsed(m_gui_unds_timer) < TAPPING_TERM) {

          add_weak_mods(MOD_BIT(KC_LSFT));
          send_keyboard_report();
          register_code(KC_MINS);
          unregister_code(KC_MINS);
          del_weak_mods(MOD_BIT(KC_LSFT));
          send_keyboard_report();
          record->tap.count = 0;  // ad hoc: cancel tap
        } else {
          unregister_mods(MOD_BIT(KC_LGUI));
        }
      }
      break;
    // Hold for LSHIFT, tap for Parens open
    case M_SFT_PO:
      if (record->event.pressed) {
        m_sft_po_timer = timer_read();

        if (!tap_not_interrupted) {
          register_mods(MOD_BIT(KC_LSFT));
        }
      } else {
        if (tap_not_interrupted && timer_elapsed(m_sft_po_timer) < TAPPING_TERM) {
          record->tap.count = 0;
          return MACRO(D(RSFT), T(9), U(RSFT), END);
        } else {
          unregister_mods(MOD_BIT(KC_LSFT));
        }
      }
      break;
    // Hold for RSHIFT, tap for Parens close
    case M_SFT_PC:
      if (record->event.pressed) {
        m_sft_pc_timer = timer_read();

        if (!tap_not_interrupted) {
          register_mods(MOD_BIT(KC_RSFT));
        }
      } else {
        if (tap_not_interrupted && timer_elapsed(m_sft_pc_timer) < TAPPING_TERM) {
          record->tap.count = 0;
          return MACRO(D(LSFT), T(0), U(LSFT), END);
        } else {
          unregister_mods(MOD_BIT(KC_RSFT));
        }
      }
      break;
  }
  return MACRO_NONE;
};
