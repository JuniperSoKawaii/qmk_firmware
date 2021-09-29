#include <art.h>
#include <sendstring_workman_zxcvm.h>
#include "user_config.c"

enum custom_keycodes {
  keyboardSpecificKeyCode = NEW_SAFE_RANGE //not used atm
};

bool led_update_user(led_t led_state) {
  writePin(LED_CAPS_LOCK_PIN, led_state.caps_lock);
  return false;
}

void led_show_variable_status(bool value) {
  if (value) {
    writePinHigh(LED_NUM_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_NUM_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinHigh(LED_NUM_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_NUM_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinHigh(LED_NUM_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_NUM_LOCK_PIN);
  } else {
    writePinHigh(LED_SCROLL_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_SCROLL_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_SCROLL_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    wait_ms(BLINKING_INTERVAL);
    writePinLow(LED_SCROLL_LOCK_PIN);
  }
}

void blink_all_leds(void) {
  writePinHigh(LED_NUM_LOCK_PIN);
  writePinHigh(LED_SCROLL_LOCK_PIN);
  wait_ms(BLINKING_INTERVAL);
  writePinLow(LED_NUM_LOCK_PIN);
  writePinLow(LED_SCROLL_LOCK_PIN);
  wait_ms(BLINKING_INTERVAL);
  writePinHigh(LED_NUM_LOCK_PIN);
  writePinHigh(LED_SCROLL_LOCK_PIN);
  wait_ms(BLINKING_INTERVAL);
  writePinLow(LED_NUM_LOCK_PIN);
  writePinLow(LED_SCROLL_LOCK_PIN);
  wait_ms(BLINKING_INTERVAL);
  writePinHigh(LED_NUM_LOCK_PIN);
  writePinHigh(LED_SCROLL_LOCK_PIN);
  wait_ms(BLINKING_INTERVAL);
  writePinLow(LED_NUM_LOCK_PIN);
  writePinLow(LED_SCROLL_LOCK_PIN);
  
  layer_state_set_user(layer_state);
}

void keyboard_pre_init_user(void) {
  led_show_variable_status(is_win);
  layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  writePinLow(LED_NUM_LOCK_PIN);
  writePinLow(LED_SCROLL_LOCK_PIN);
  switch (get_highest_layer(state)) {
    case MEDIA:
    case WORKMAN:
      writePinHigh(LED_SCROLL_LOCK_PIN);
    case BASE:
      writePinHigh(LED_NUM_LOCK_PIN);
      break;
    case NUMPAD:
      writePinHigh(LED_SCROLL_LOCK_PIN);
      break;
  }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY        ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Home|
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspac  | Del |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | End |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgUp|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | PgDn|
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |Spac/MEDIA | BSPC|     |      NAV      |  Alt  | NAV | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [QWERTY] = LAYOUT(
//--------------------------------Left Hand------------------------------------| |--------------------------------Right Hand------------------------------------------------
                 KC_ESC,   KC_MPLY, KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   LT(CONFIG, KC_PSCR),  KC_INS,  KC_HOME,
KC_VOLD,KC_VOLU, KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,          KC_DEL,
KC_MPRV,KC_MNXT, KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_HOME,KC_END,  KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT,KC_ENTER,         KC_PGUP,
DYN_MACRO_PLAY1,KC_MUTE,KC_LSFT,KC_Z,KC_X,KC_C,  KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, LT(GIT,KC_SLSH),                     KC_RSFT,  KC_UP,   KC_PGDN,
DYN_REC_STOP,DYN_REC_START1,KC_LCTL, KC_LGUI, KC_LALT, LT(MEDIA,KC_SPC), LT(COMBOS,KC_BSPC),       LT(NAV,KC_APP), LT(LAYOUT_CHG, KC_ENTER),KC_RALT,KC_RCTL,   KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  /* Base          ,-----------------------------------------.     ,-----------------------------------------------------.
  *                | ESC | F1  | F2  | F3  | F4  | F5  | F6  |     | F7  | F8  | F9  | F10 | F11 | F12 |Print| Ins | Home|
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |  8  |  9  |  |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |     |  7  |  8  |  9  |  0  |  -  |  =  | Backspac  | Del |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |  6  |  7  |  | Tab   |  Q  |  W  |  E  |  R  |  T  |     |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    | End |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |  4  |  5  |  | Caps    |  A  |  S  |  D  |  F  |  G  |     |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | PgUp|
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |  2  |  3  |  | Shift     |  Z  |  X  |  C  |  V  |  B  |     |  N  |  M  |  ,  |  .  |   /   |  Shift  | Up  | PgDn|
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |   Space   |Space|     | Space         |  Alt  |QW_ON| Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [BASE] = LAYOUT(
//--------------------------------Left Hand-----------------------------------| |--------------------------------Right Hand------------------------------------------------
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   LT(CONFIG, KC_PSCR),  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                 KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENTER,                    KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    OS_CTRL,  OS_WIN,  KC_LALT, KC_SPC, KC_SPC,                       KC_SPC,      MO(QWERTY_MOD), KC_RALT, KC_RCTL,           KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [WORKMAN] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_Q,     KC_D,     KC_R,     KC_W,     KC_B,                 KC_J,     KC_F,      KC_U,     KC_P,     KC_SCLN,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_A,     KC_S,     KC_H,     KC_T,     KC_G,                 KC_Y,     KC_N,      KC_E,     KC_O,     KC_I,     _______,  _______,           _______,
_______,  _______,    _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_M,                 KC_K,     KC_L,      KC_COMM,  KC_DOT,   _______,                      _______, _______,  _______,
_______,  _______,    _______, _______,   _______,  _______,  LT(COMBOS,KC_BSPC),       LT(NAV,KC_APP), LT(LAYOUT_CHG, KC_ENTER), TO(QWERTY), _______,               _______,  _______, _______
  ),
  
  [NAV] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
KC_8,  KC_9,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
KC_6,  KC_7,    _______,  KC_ESC,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,              XXXXXXX, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, XXXXXXX,  _______,  _______,  _______,           _______,
KC_4,  KC_5,    _______,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDOWN,            KC_APP,  CTR_ALT, KC_RSFT, CTR_ALT_SHIFT, _______, _______, _______,          _______,
KC_2,  KC_3,    _______,  XXXXXXX, LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), XXXXXXX,           XXXXXXX,  XXXXXXX,   _______,  _______,  _______,                      _______,  _______, _______,
KC_0,  KC_1,    _______,  _______,  _______,  KC_DEL,   _______,                        _______,             _______,  _______,  _______,            _______,  _______,  _______
  ),
  
  [MEDIA] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  ),
  
  [COMBOS] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______, _______,  TILD_BLOCK,  _______, QUOTES_RU, _______, _______, SM_READPNT, _______,          _______,   STARS,    PARENTHS, _______,  DASHES,   _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______, NEUTRAL_COPY, _______, BEAT_BROWSER,      _______,  _______,   _______,  _______,  _______,  BRACES,   TOG_OS,   _______,           _______,
_______,  _______,    _______,  ADMINS,   SARCASM,  ALL_BEST,CTRL_CTV, _______,              _______,  _______,   _______,  _______,  _______,  QUOTES,   _______,                     _______,
_______,  _______,    _______,  _______,  _______,  CTRL_CAV, _______,  XXXXXXX,              _______,  CTRL_LCTV, _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  ),
  
//   [STRINGS] = LAYOUT(
// //--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
//                       _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
// _______,  _______,    TILD_BLOCK, _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  ADMINS,   _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
//   ),  

  [QWERTY_MOD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,   TO(QWERTY),_______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  ),
  
  [LAYOUT_CHG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  KC_F1,    _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  CTL_ALT(KC_HOME),  CTL_ALT(KC_UP),    CTL_ALT(KC_END),   CTL_ALT(KC_PGUP),              _______,  _______,_______, _______,_______,_______,_______,  _______,           _______,
_______,  _______,    _______,  _______,  CTL_ALT(KC_LEFT),  CTL_ALT(KC_DOWN),  CTL_ALT(KC_RIGHT), CTL_ALT(KC_PGDOWN),              _______,_______,_______,_______,_______,  _______,  _______,           _______,
_______,  _______,   TO(WORKMAN), _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
TO(NUMPAD), TO(NUMPAD), TO(BASE),  _______,  _______,  _______,  CTL_ALT(KC_BSPC),                KC_LSFT,             _______, _______, _______,                      _______, _______,  _______
  ),  
  
  [CONFIG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
RGB_VAD,  RGB_VAI,    RGB_MODE_PLAIN,  RGB_MODE_BREATHE,  RGB_MODE_RAINBOW,  RGB_MODE_SWIRL,  RGB_MODE_SNAKE,  RGB_MODE_KNIGHT,  RGB_MODE_XMAS,  RGB_MODE_GRADIENT,   RGB_MODE_RGBTEST,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,           _______,
RGB_SAD,  RGB_SAI,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  XXXXXXX,  _______,  _______,  _______,  _______,           _______,
RGB_HUD,  RGB_HUI,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
RGB_RMOD, RGB_MOD,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
RGB_TOG,  XXXXXXX,    _______,  _______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  ),

  [NUMPAD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
KC_8,  KC_9,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
KC_6,  KC_7,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
KC_4,  KC_5,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
KC_2,  KC_3,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
KC_0,  KC_1,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, TO(QWERTY),_______,                      _______, _______,  _______
  ),
  
  [GIT] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  G_DIFF,   G_R,      _______,  G_BRCH,               _______,   G_FTCH,   G_PULL,   G_PUSH,   _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  G_ADD,    G_S,      _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  G_DEV,    _______,  G_C,      _______,  G_MERG,               _______,   G_LOG,    _______,  XXXXXXX,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  ),
  
  [GIT_C] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  G_CHER,   XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  G_CHEC,   XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_COMM,   XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,                        XXXXXXX,             XXXXXXX,  XXXXXXX,  _______,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),

  [GIT_R] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_RBASE,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_RST,    XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_RVERT,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,                        XXXXXXX,             XXXXXXX,  XXXXXXX,  _______,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ), 
  
  [GIT_S] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_STSH,   G_SHOW,   G_STAT,   XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC,                        XXXXXXX,             XXXXXXX,  XXXXXXX,  _______,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),   
  
 /*                ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |     |     |     |     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     |     |     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |    |     |      |     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  |       |      |      |           |     |     |               |       |     |       |     |     |     |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  // [] = LAYOUT(
// //--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      // _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
// _______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______,  _______,  _______,                      _______, _______,  _______
  // ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}