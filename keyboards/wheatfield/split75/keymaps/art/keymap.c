#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sendstring_workman_zxcvm.h>

enum layer_names {
	QWERTY, //TODO - MAKE BASE 1ST
    BASE,
    QWERTY_MOD,

    WORKMAN,
    MOD,
    MEDIA,
	LAYOUT_CHG,
	GIT,
	GIT_C,
	GIT_P,
	GIT_S
};

enum custom_keycodes {
    CTR_ALT  = SAFE_RANGE,
	G_ADD,
	G_BRCH,
	G_C,
	G_BS_C,
	G_CHEC,	
	G_COMM,
	G_DIFF,
	G_FTCH,
	G_LOG,
	G_MERG,
	G_P,
	// G_BS_P,
	// G_PULL,
	// G_PUSH,
	G_RST,
	G_S,
	G_BS_S,
	G_STAT,
	G_STSH,
	G_SHOW,
};

const char* const testt[] = {"X_LCTL"};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   KC_PSCR,  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, KC_BSPC,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                 KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENTER,                    KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC, KC_SPC,                       KC_SPC,         KC_RALT, MO(QWERTY_MOD),  KC_RCTL,            KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  /*QWERT On + Mod ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |MePrv| Vol+|MeNxt|     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     | Vol-|     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |     | Vol0|MePly|     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  | QWERTY |      |      |           |     |     |               |       |     |       |     |     |    |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [QWERTY_MOD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    TO(QWERTY),_______, _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),

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
  * |  0  |  1  |  | Ctrl  |  GUI |  Alt |Spac/MEDIA | BSPC|     |      MOD      |  Alt  | MOD | Ctrl  | Left| Down|Right|
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [QWERTY] = LAYOUT(
//--------------------------------Left Hand------------------------------------| |--------------------------------Right Hand------------------------------------------------
                KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,                KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,   KC_PSCR,  KC_INS,  KC_HOME,
KC_8,  KC_9,    KC_GRAVE, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,                 KC_7,   KC_8,    KC_9,   KC_0,    KC_MINUS, KC_EQUAL, XXXXXXX,           KC_DEL,
KC_6,  KC_7,    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                 KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END,
KC_4,  KC_5,    KC_CAPS,  KC_A,    KC_S ,KC_D ,KC_F ,KC_G,   KC_H,   KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT,XXXXXXX,         KC_PGUP,
KC_2,  KC_3,    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,                 KC_N,   KC_M,   KC_COMM, KC_DOT, LT(GIT,KC_SLSH),                     KC_RSFT,  KC_UP,   KC_PGDN,
KC_0,  KC_1,    KC_LCTL,  KC_LGUI, KC_LALT, LT(MEDIA, KC_SPC),KC_BSPC,            LT(MOD, KC_ENTER),        KC_RALT, MO(LAYOUT_CHG),KC_RCTL,                     KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  /*    WORKMAN    ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |     |     |     |     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     |     |     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |     |     |     |     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  | BASE  |      |      |           |     |     |               |       |     |       |     |     |     |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [WORKMAN] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_Q,     KC_D,		KC_R,     KC_W,     KC_B,              KC_J,   KC_F,		KC_U,   KC_P,   KC_SCLN,_______,_______,  _______,           _______,
_______,  _______,    _______,  KC_A,     KC_S,		KC_H,     KC_T,     KC_G,              KC_Y,   KC_N,		KC_E,   KC_O,   KC_I,  _______,  _______,           _______,
_______,  _______,    _______,  KC_Z,     KC_X,		KC_C,     KC_V,     KC_M,              KC_K,   KC_L,		KC_COMM,KC_DOT, _______,                      _______, _______,  _______,
_______,  _______,    _______, _______,_______,_______, _______,                        _______,             _______, TO(QWERTY),   _______,            _______, _______,  _______
  ),
  
  /*    MOD        ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |     |     |     |     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     |     |     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |     |     |     |     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  | BASE  |      |      |           |     |     |               |       |     |       |     |     |     |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [MOD] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,              _______,  _______,_______, _______,_______,_______,_______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDOWN,              CTR_ALT,KC_LCTL,KC_LSFT,_______,_______,  _______,  _______,           _______,
_______,  _______,    _______,_______,_______,  _______,  KC_DEL,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______, _______,_______,KC_DEL, _______,                        _______,             _______, _______,   _______,            _______, _______,  _______
  ),
  
  /*    MEDIA      ,-----------------------------------------.     ,-----------------------------------------------------.
  *                |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
  * ,-----------.  |-----+-----+-----+-----+-----+-----+-----|     |-----+-----+-----+-----+-----+-----+-----------+-----|
  * |     |     |  |     |     |     |     |     |     |     |     |     |     |     |     |     |     |           |     |
  * |-----+-----|  |-----------------------------------------'  ,--------------------------------------------------+-----|
  * |     |     |  |       |     |     |     |     |     |     |     |     |     |     |     |     |     |         |     |
  * |-----+-----|  |---------------------------------------.    `--------------------------------------------------+-----|
  * |     |     |  |         |     |     |     |     |     |     |     |     |     |     |     |     |             |     |
  * |-----+-----|  |-----------------------------------------.   `-------------------------------------------------+-----|
  * |     |     |  |           |     |     | Play|     |     |     |     |     |     |     |       |         |     |     |
  * |-----+-----|  |-----------------------------------------'   ,-------------------------------------------+-----+-----|
  * |     |     |  | BASE  |      |      |           |     |     |               |       |     |       |     |     |     |
  * `-----------'  `---------------------------------------'     `-------------------------------------------------------'
  */
  [MEDIA] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  KC_MPRV,  KC_VOLU,  KC_MNXT,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  KC_VOLD,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  KC_MUTE,  KC_MPLY,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
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
  [LAYOUT_CHG] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    TO(WORKMAN),  _______,  _______,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    TO(BASE),  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),  
  
 /*     git        ,-----------------------------------------.     ,-----------------------------------------------------.
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
  [GIT] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,   _______,  _______,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  _______,  G_DIFF,  G_RST,  _______,  G_BRCH,              _______,  G_FTCH,   _______,  G_P,  _______,  _______,  _______,  _______,           _______,
_______,  _______,    _______,  G_ADD,  G_S,  _______,  _______,  _______,              _______,  _______,   _______,  _______,  _______,  _______,  _______,                     _______,
_______,  _______,    _______,  _______,  _______,  G_C,  _______,  G_MERG,              _______,  G_LOG,   _______,  _______,  _______,                      _______, _______,  _______,
_______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  ),
  [GIT_C] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_C,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  G_CHEC,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_COMM,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  ),   
  // [GIT_P] = LAYOUT(
// //--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      // XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_P,           XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_PUSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  G_PULL,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
// XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
// XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
  // ), 
  [GIT_S] = LAYOUT(
//--------------------------------Left Hand-----------------------------------------------| |--------------------------------Right Hand------------------------------------------------
                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_BS_S,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  G_STSH,  G_SHOW,  G_STAT,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,
XXXXXXX,  XXXXXXX,    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,                      _______, XXXXXXX,  XXXXXXX,
XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,             XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX,  XXXXXXX
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
// _______,  _______,    _______,  _______,  _______,  _______,  _______,                        _______,             _______, _______,   _______,                      _______, _______,  _______
  // ),
};

bool led_update_user(led_t led_state) {
    writePin(CAPSLOCK_LED_PIN, led_state.caps_lock);
    return false;
}

void keyboard_pre_init_user(void) {
    writePinHigh(SCROLLLOCK_LED_PIN);
    wait_ms(50);
    writePinHigh(CAPSLOCK_LED_PIN);
    wait_ms(50);
    writePinHigh(NUMLOCK_LED_PIN);
    wait_ms(50);
    writePinLow(SCROLLLOCK_LED_PIN);
    wait_ms(50);
    writePinLow(CAPSLOCK_LED_PIN);
    wait_ms(50);
    writePinLow(NUMLOCK_LED_PIN);
	
	layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(NUMLOCK_LED_PIN);
    writePinLow(SCROLLLOCK_LED_PIN);
    switch (get_highest_layer(state)) {
    case BASE:
        writePinHigh(SCROLLLOCK_LED_PIN);
        break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTR_ALT:
		  // const char* key = testt[0];
          // if (record->event.pressed) {
              // send_string(SS_DOWN(key));
          // } else {
              // send_string(SS_UP(key));
          // }
          break;
	case G_ADD:
		if (record->event.pressed) {
			SEND_STRING("git add ");
		}
		break;
	case G_BRCH:
		if (record->event.pressed) {
			if ( get_mods() & MOD_MASK_SHIFT ) {
				clear_mods();
				SEND_STRING("master");
			} else {
				SEND_STRING("develop");
			}
		}
		break;
	case G_C:
		if (record->event.pressed) {
            SEND_STRING("git c[Heckout/Ommit]");
			layer_on(GIT_C);
		}
		break;
	case G_BS_C:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
			layer_off(GIT_C);
		}
		break;
	case G_CHEC:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"heckout ");
			layer_off(GIT_C);			
		}
		break;
	case G_COMM:
		if (!record->event.pressed) {
			if ( get_mods() & MOD_MASK_SHIFT ) {
				clear_mods();
				SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"ommit -am \"\"" SS_TAP(X_LEFT));
			} else {
				SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"ommit -m \"\"" SS_TAP(X_LEFT));
			}
			layer_off(GIT_C);
		}
		break;
	case G_DIFF:
		if (record->event.pressed) {
			SEND_STRING("git diff ");
		}
		break;	
	case G_FTCH:
		if (record->event.pressed) {
			SEND_STRING("git fetch ");
		}
		break;
	case G_LOG:
		if (record->event.pressed) {
			SEND_STRING("git log ");
		}
		break;
	case G_MERG:
		if (record->event.pressed) {
			SEND_STRING("git merge ");
		}
		break;
	case G_P:
		if (record->event.pressed) {
			SEND_STRING("git pu");
		}
		break;
	// case G_BS_P:
		// if (!record->event.pressed) {
			// SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
			// layer_off(GIT_P);
		// }
		// break;
	// case G_PULL:
		// if (!record->event.pressed) {
			// SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"ll ");
			// layer_off(GIT_P);
		// }
		// break;			
	// case G_PUSH:
		// if (!record->event.pressed) {
			// SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"sh ");
			// layer_off(GIT_P);
		// }
		// break;
	case G_RST:
		if (record->event.pressed) {
			SEND_STRING("git reset ");
		}
		break;
	case G_S:
		if (!record->event.pressed) {
			SEND_STRING("git s[How/taSh/taTus]");
			layer_on(GIT_S);			
		}
		break;
	case G_BS_S:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
			layer_off(GIT_S);
		}
		break;
	case G_SHOW:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"how ");
			layer_off(GIT_S);
		}
		break;			
	case G_STSH:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"tash ");
			layer_off(GIT_S);
		}
		break;		
	case G_STAT:
		if (!record->event.pressed) {
			SEND_STRING(SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)"tatus ");
			layer_off(GIT_S);
		}
		break;
  }
  return true;
};