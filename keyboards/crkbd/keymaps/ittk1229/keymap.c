#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include <stdio.h>

// レイヤーの定義
enum layers {
  _EUCALYN = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MINECRAFT,
};

// マクロキーの定義
enum custom_keycodes {
  CTL_SPC = SAFE_RANGE,
  SFT_ENT,
  ESC_MHEN,
  LOWER,
  RAISE,
};

// 複合キーを変数に
#define W_PSCR LGUI(S(KC_S))
#define CAPTURE LGUI(KC_PSCR)
#define NV_REC LALT(KC_F9)

#define LSFT_ENT LSFT(KC_ENT)
#define LCTL_SPC LCTL(KC_SPC)

#define TO_MC TO(_MINECRAFT)
#define TO_EU TO(_EUCALYN)
#define TO_QW TO(_QWERTY)

// レイヤーごとにキーマップを定義
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_EUCALYN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ESC_MHEN,    KC_Q,   KC_W,  JP_COMM,  JP_DOT, JP_SCLN,                         KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, JP_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                         KC_G,    KC_T,    KC_N,    KC_S,    KC_B, JP_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, JP_SLSH,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, CTL_SPC,    SFT_ENT,   RAISE, KC_BSPC\
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, KC_LCTL,    KC_LSFT,   RAISE,LSFT_ENT\
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       JP_GRV, JP_TILD,   KC_NO,   JP_LT,   JP_GT, JP_COLN,                        KC_NO, JP_LPRN, JP_RPRN,   KC_NO,   KC_NO, JP_UNDS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, JP_AMPR,   JP_AT, JP_PLUS,  JP_EQL,   KC_NO,                      JP_CIRC, JP_LCBR, JP_RCBR,  JP_DLR, JP_EXLM, JP_DQUO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, JP_PIPE, JP_HASH, JP_ASTR, JP_PERC,   KC_NO,                        KC_NO, JP_LBRC, JP_RBRC, JP_BSLS, JP_QUES,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, KC_LCTL,    KC_LSFT,   RAISE,   KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,  W_PSCR,  NV_REC,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_NO,   KC_NO, JP_CAPS,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO_MC,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, KC_LCTL,     KC_LSFT,   RAISE,   KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [_MINECRAFT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,   KC_NO,    KC_Q,    KC_W,    KC_E,    KC_T,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,   KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      JP_SLSH,   KC_F1,   KC_F5,  KC_F11,   KC_NO,  CAPTURE,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  TO_EU,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT,  KC_SPC,      KC_NO,   KC_NO,   KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

};

// OLEDの設定
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _EUCALYN:
            oled_write_ln_P(PSTR("EUCALYN"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case _MINECRAFT:
            oled_write_ln_P(PSTR("Minecraft"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

static bool lower_pressed = false;
static bool raise_pressed = false;

static bool ctl_spc_pressed = false;
static bool sft_ent_pressed = false;
static uint16_t  ctl_spc_pressed_time = 0;
static uint16_t sft_ent_pressed_time = 0;

// マウス用に長押しで通常の修飾キーに
void matrix_scan_user(void) {
  if (ctl_spc_pressed && timer_elapsed(ctl_spc_pressed_time) > TAPPING_TERM) {
    register_code(KC_LCTL);
    ctl_spc_pressed = false;
  }
  if (sft_ent_pressed && timer_elapsed(sft_ent_pressed_time) > TAPPING_TERM) {
    register_code(KC_LSFT);
    sft_ent_pressed = false;
  }
};

static void user_mt(keyrecord_t *record, uint16_t modcode, uint16_t keycode, bool *modifier_pressed, uint16_t *modifier_pressed_time, bool tapping_term_disable) {
  if (record->event.pressed) {
    *modifier_pressed = true;
    *modifier_pressed_time = record->event.time;
  } else {
    if (!*modifier_pressed) unregister_code(modcode);
    if (*modifier_pressed && (tapping_term_disable || (timer_elapsed(*modifier_pressed_time) < TAPPING_TERM))) {
      register_code(keycode);
      unregister_code(keycode);
    }
    *modifier_pressed = false;
  }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    if (keycode != CTL_SPC) {
      if (ctl_spc_pressed) {
        register_code(KC_LCTL);
      }
      ctl_spc_pressed = false;
    }
    if (keycode != SFT_ENT) {
      if (sft_ent_pressed) {
        register_code(KC_LSFT);
      }
      sft_ent_pressed = false;
    }
  }

  switch (keycode) {
    case CTL_SPC:
      user_mt(record, KC_LCTL,  KC_SPC, &ctl_spc_pressed, &ctl_spc_pressed_time, true);
      return false;
    case SFT_ENT:
      user_mt(record, KC_LSFT, KC_ENT, &sft_ent_pressed, &sft_ent_pressed_time, true);
      return false;
    case ESC_MHEN:
      register_code(KC_ESC);
      register_code(KC_MHEN);
      return false;
    case LOWER:
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed) {
          register_code(KC_MHEN);
          unregister_code(KC_MHEN);
        }
        lower_pressed = false;
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        raise_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed) {
          register_code(KC_HENK);
          unregister_code(KC_HENK);
        }
        raise_pressed = false;
      }
      return false;
    default:  // case: defaultではない.。マクロキーでない他のすべてのキー
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
        if (ctl_spc_pressed) {
          register_code(KC_LCTL);
        }
        if (sft_ent_pressed) {
          register_code(KC_LSFT);
        }
        ctl_spc_pressed = false;
        sft_ent_pressed = false;
      }
      break;
  }
  return true;
};

#endif // OLED_ENABLE
