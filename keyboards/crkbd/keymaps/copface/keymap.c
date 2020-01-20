#include QMK_KEYBOARD_H

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// Aliases for keys
#define KC_PRS LGUI(LALT(LCTL(KC_4)))
#define KC_EUR LALT(KC_4)
#define KC_SBSPC LALT(KC_BSPC)
#define KC_MGRV LALT(KC_GRV)

#define M_LGTAB LGUI_T(KC_TAB)
#define M_LCENT LCTL_T(KC_ENT)
#define M_LGENT LGUI_T(KC_ENT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  M_ARROW, // ->
  M_FARROW // =>
};

enum tapdancers {
    T_BR = 0, // [, ]
    T_PA, // (, )
    T_CU, // {, }
    T_DLR // $, €
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [T_BR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [T_PA] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [T_CU] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [T_DLR] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_EUR)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, XXXXXXX, KC_LEAD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,    M_LCENT,   RAISE,  KC_RALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX, XXXXXXX, M_ARROW,M_FARROW, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   LOWER, XXXXXXX,   KC_SBSPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_MGRV, KC_MINS,  KC_EQL, KC_EXLM, KC_QUES, KC_PLUS,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,KC_SBSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PIPE,TD(T_BR),TD(T_CU),TD(T_PA),TD(T_DLR),XXXXXXX,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_VOLU,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_UNDS, KC_DQUO, KC_QUOT, KC_SLSH, KC_BSLS,                      XXXXXXX, KC_SCLN, KC_COLN, KC_MPRV, KC_MPLY, KC_MNXT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   LOWER,  KC_DEL,    XXXXXXX,   RAISE, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,   RESET,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   LOWER, XXXXXXX,    XXXXXXX,   RAISE, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

LEADER_EXTERNS();

void matrix_scan_user(void) {
    iota_gfx_task();

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_X) {
            SEND_STRING(":D");
        }
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING(":DDD");
        }
        SEQ_ONE_KEY(KC_V) {
            SEND_STRING(":DDDDDD");
        }
        SEQ_ONE_KEY(KC_S) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_4);
            unregister_code(KC_4);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_F) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_BSLS);
            unregister_code(KC_BSLS);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
        }
        SEQ_TWO_KEYS(KC_F, KC_F) {
            register_code(KC_LGUI);
            register_code(KC_BSLS);
            unregister_code(KC_BSLS);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_BSPC) {
            register_code(KC_LGUI);
            register_code(KC_SLSH);
            unregister_code(KC_SLSH);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_SPC) {
            register_code(KC_LGUI);
            register_code(KC_SPC);
            unregister_code(KC_SPC);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_ESC) {
            register_code(KC_LSFT);
            register_code(KC_GRV);
            unregister_code(KC_GRV);
            unregister_code(KC_LSFT);
        }
    }
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef SSD1306OLED
        set_keylog(keycode, record);
    #endif
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case M_ARROW:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        return false;
    case M_FARROW:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        return false;
  }
  return true;
}
