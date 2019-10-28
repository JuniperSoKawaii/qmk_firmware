#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layer_names {
  _COLEMAKDHM,
  _GAMING,
  _GAMING_EXT,
  _NUM,
  _FN,
  _NAV,
  _UTIL
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  RGB_IDL, // RGB Idling animations
  RGB_UND // Toggle RGB underglow as layer indicator
};

typedef union {
  uint32_t raw;
  struct {
    bool    rgb_layer_change :1;
    bool    rgb_matrix_idle_anim :1;
  };
} user_config_t;

user_config_t user_config;

// Base layers
#define COLEMAK DF(_COLEMAKDHM)
#define GAMING DF(_GAMING)

// Layer toggle and switch
#define T_NAV TT(_NAV)
#define S_NAV MO(_NAV)

#define T_NUM TT(_NUM)
#define S_NUM MO(_NUM)

// Layer keys with functionality on tap
#define FN_TAB LT(_FN, KC_TAB)
#define NAV_0 LT(_NAV, KC_0)

#define EXT_SF LT(_GAMING_EXT, KC_LSHIFT)

// Tap/mod keys
#define RCTBR RCTL_T(KC_RBRACKET)
#define LCTBR LCTL_T(KC_LBRACKET)

#define SFSPC LSFT_T(KC_SPACE)
#define SFENT LSFT_T(KC_ENTER)

// Global tab forward and backward
#define TBFWD LCTL(KC_TAB)
#define TBBCK LCTL(LSFT(KC_TAB))

// Custom key for NUM layer
#define CT_ASTR KC_RCPC

// €
#define KC_EUR ALGR(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       FN_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        LCTBR,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM, KC_DOT, KC_SLSH,    RCTBR,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   T_NUM,   SFSPC,      SFENT,   T_NAV, KC_RGUI \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, KC_RCTL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  EXT_SF,  KC_SPC,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING_EXT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2, _______,    KC_3,    KC_4,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LBRC, KC_RBRC, _______, _______, _______, KC_BSLS,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       KC_F11,  KC_F12, KC_MINS,  KC_EQL, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     KC_ENT, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_NLCK,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PIPE, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_PAUS, KC_SLCK, KC_PSCR,  KC_INS,                       KC_EQL, KC_MINS,   KC_LT,   KC_GT, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD,  KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_UNDS,    KC_4,    KC_5,    KC_6, KC_MINS, KC_PLUS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CIRC, KC_AMPR,  KC_EUR, KC_LPRN, KC_RPRN,                       KC_EQL,    KC_1,    KC_2,    KC_3, _______, CT_ASTR,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   S_NUM, _______,    _______, NAV_0, KC_DOT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_WH_U,   TBBCK, KC_MS_U,   TBFWD, KC_BTN2,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PIPE,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,                      KC_ACL2, KC_ACL0, XXXXXXX, XXXXXXX, KC_BSLS, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-------+---------|
                                          _______, _______, _______,    _______, S_NAV, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_UTIL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, KC_MSTP, KC_VOLU, KC_MNXT, XXXXXXX,                      COLEMAK,  GAMING, XXXXXXX, XXXXXXX, RGB_UND, RGB_IDL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_RST, XXXXXXX, KC_MPRV, KC_VOLD, KC_MPLY, XXXXXXX,                      XXXXXXX, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLEP, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      RGB_TOG,RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(default_layer_state)) {
    case _COLEMAKDHM:
      state = update_tri_layer_state(state, _NUM, _NAV, _UTIL);
      break;
    case _GAMING:
      state = update_tri_layer_state(state, _GAMING_EXT, _NAV, _UTIL);
      break;
  }
  return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_180;
  }
}

void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}

void render_status(void) {
  // oled_write_P(PSTR("Layout: "), false);
  switch (get_highest_layer(default_layer_state)) {
    case _COLEMAKDHM:
      oled_write_P(PSTR("TYPE "), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("GAME "), false);
      break;
  }

  oled_write_P(PSTR("\n"), false);

  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_P(PSTR("     "), false);
      break;
    case _NUM:
      oled_write_P(PSTR("Comm "), false);
      break;
    case _FN:
      oled_write_P(PSTR("Stage"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("Fuel "), false);
      break;
    case _GAMING_EXT:
      oled_write_P(PSTR("Ext  "), false);
      break;
    case _UTIL:
      oled_write_P(PSTR("Util "), false);
      break;
    default:
      oled_write_P(PSTR("Unkn "), false);
      break;
  }
  oled_write_P(PSTR("\n"), false);

  uint8_t modifiers = get_mods();

  oled_write_P( (modifiers & MOD_MASK_CTRL)  ? PSTR("PROG ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_SHIFT) ? PSTR("PULSE") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_ALT)   ? PSTR("STBY ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_GUI)   ? PSTR("GYRO ") : PSTR("     "), false);

  oled_write_P(PSTR("\n"), false);

  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("Mode:\n"), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);
}

void oled_task_user(void) {
  if (is_master) {
    render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_crkbd_logo();
    // oled_scroll_left();  // Turns on scrolling
  }
}
#endif

#ifdef RGB_MATRIX_ENABLE

#define RGB_MATRIX_REST_MODE RGB_MATRIX_DUAL_BEACON

extern led_config_t g_led_config;
void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_config.hsv.v) {
        hsv.v = rgb_matrix_config.hsv.v;
    }

    RGB rgb = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

static uint32_t hypno_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t saved_mods = 0;
  uint16_t temp_keycode = keycode;
  // Filter out the actual keycode from MT and LT keys.
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
      temp_keycode &= 0xFF;
  }

  hypno_timer = timer_read32();
  if (user_config.rgb_matrix_idle_anim && rgb_matrix_get_mode() == RGB_MATRIX_REST_MODE) {
      rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
  }

  switch (temp_keycode) {
    case KC_BSPC:
      if (record->event.pressed) {
          if (get_mods() & MOD_MASK_SHIFT) {
              saved_mods = get_mods() & MOD_MASK_SHIFT; // Mask off anything that isn't Shift
              del_mods(saved_mods); // Remove any Shifts present
              register_code(KC_DEL);
          } else {
              saved_mods = 0; // Clear saved mods so the add_mods() below doesn't add Shifts back when it shouldn't
              register_code(KC_BSPC);
          }
      } else {
          add_mods(saved_mods);
          unregister_code(KC_DEL);
          unregister_code(KC_BSPC);
      }
      return false;
    case RGB_RST:
      if (record->event.pressed) {
        eeconfig_update_rgb_matrix_default();
        rgb_matrix_enable();
      }
      break;
    case RGB_UND:  // Toggle separate underglow status
      if (record->event.pressed) {
          user_config.rgb_layer_change ^= 1;
          eeconfig_update_user(user_config.raw);
          if (user_config.rgb_layer_change) {
              layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
          } else {
            rgb_matrix_layer_helper(0, 0, 0, LED_FLAG_UNDERGLOW);
          }
      }
     break;
    case RGB_IDL: // Toggle idle/heatmap animation
      if (record->event.pressed) {
          user_config.rgb_matrix_idle_anim ^= 1;
          eeconfig_update_user(user_config.raw);
          if (user_config.rgb_matrix_idle_anim) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
          }
      }
     break;
    case RGB_MOD:
    case RGB_RMOD:
      if (record->event.pressed) {
          bool is_eeprom_updated = false;
          if (user_config.rgb_matrix_idle_anim) {
              user_config.rgb_matrix_idle_anim = false;
              is_eeprom_updated = true;
          }
          if (is_eeprom_updated) { eeconfig_update_user(user_config.raw); }
      }
      break;
  }
  return true;
}

void matrix_scan_rgb(void) {
    if (user_config.rgb_matrix_idle_anim && rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP && timer_elapsed32(hypno_timer) > 15000) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
    }
}

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

void keyboard_post_init_rgb(void) {
    layer_state_set_user(layer_state);
        if (user_config.rgb_matrix_idle_anim) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
        }
}

void check_default_layer(uint8_t type) {
    switch (biton32(default_layer_state)) {
        case _COLEMAKDHM:
            rgb_matrix_layer_helper(HSV_TEAL, LED_FLAG_UNDERGLOW);
            break;
        case _GAMING:
            rgb_matrix_layer_helper(HSV_BLUE, LED_FLAG_UNDERGLOW);
            break;
    }
}

void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }
    matrix_scan_rgb();
}

void rgb_matrix_indicators_user(void) {
  if (user_config.rgb_layer_change && !g_suspend_state && rgb_matrix_config.enable)
    {
        switch (biton32(layer_state)) {
            case _GAMING_EXT:
                rgb_matrix_layer_helper(HSV_RED, LED_FLAG_UNDERGLOW);
                break;
            case _FN:
                rgb_matrix_layer_helper(HSV_CORAL, LED_FLAG_UNDERGLOW);
                break;
            case _NUM:
                rgb_matrix_layer_helper(HSV_GOLDENROD, LED_FLAG_UNDERGLOW);
                break;
            case _NAV:
                rgb_matrix_layer_helper(HSV_SPRINGGREEN, LED_FLAG_UNDERGLOW);
                break;
            case _UTIL:
                rgb_matrix_layer_helper(HSV_MAGENTA, LED_FLAG_UNDERGLOW);
                break;
            default: {
                check_default_layer(LED_FLAG_UNDERGLOW);
                break;
            }
        }
    }
}
#endif

void eeconfig_init_user(void) {
    user_config.raw                  = 0;
    user_config.rgb_layer_change     = true;
    user_config.rgb_matrix_idle_anim = true;
    eeconfig_update_user(user_config.raw);
      keyboard_init();
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();

    if (user_config.rgb_layer_change) {
      rgb_matrix_enable_noeeprom();
    }
    keyboard_post_init_rgb();
}
