#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | Ctrl | LOWER| Space|    |BckSpc| RAISE| Shift|
 *                  `--------------------'    `--------------------.
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    KC_LCTL, LOWER, KC_SPC,         KC_BSPC, RAISE, OSM(MOD_LSFT)                 \
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down |  Up  | Right|           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_TAB,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,      _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS,  KC_QUOT, \
                    _______, _______, _______,      _______, _______, _______                    \
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |      |      |           |      |      |      |   |  |   "  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER|      |    |      | RAISE|  Del |
 *                  `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, \
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, \
                    _______, _______, _______,      KC_ENT,  _______, KC_DEL                    \
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |      |           |      |      |      |Taskmg|caltde|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Reset|      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | LOWER|      |    |      | RAISE|      |
 *                  `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  _______, _______, _______,      _______, _______, _______, TSKMGR, CALTDEL, \
  RESET,   _______, _______, _______, _______,      _______, _______, _______, _______,  _______, \
                    _______, _______, _______,      _______,  _______, _______                    \
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint16_t rgb_edit_timer = 0;
uint16_t last_rgb_char = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case RGB_TOG:
    case RGB_MOD:
    case RGB_HUD:
    case RGB_HUI:
    case RGB_SAD:
    case RGB_SAI:
    case RGB_VAI:
    case RGB_VAD:
      rgb_edit_timer = timer_read();
      last_rgb_char = keycode;
      return true;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
    }
}

#ifdef RGBLIGHT_ENABLE
bool cleared = false;
void render_rgb_state(void) {
    if(!rgblight_get_mode()) {
        if(!cleared) {
            oled_clear();
            cleared = true;
        }
        return;
    }
    cleared = false;
    uint8_t width = (OLED_DISPLAY_WIDTH/OLED_FONT_WIDTH)-10;
    uint8_t hue = (rgblight_get_hue()*width/255),
        sat = (rgblight_get_sat()*width/255),
        val = (rgblight_get_val()*width/255);
    bool changing_hue = timer_elapsed(rgb_edit_timer) < 1000 && (last_rgb_char == RGB_HUI || last_rgb_char == RGB_HUD);
    bool changing_sat =  timer_elapsed(rgb_edit_timer) < 1000 && (last_rgb_char == RGB_SAI || last_rgb_char == RGB_SAD);
    bool changing_val =  timer_elapsed(rgb_edit_timer) < 1000 && (last_rgb_char == RGB_VAI || last_rgb_char == RGB_VAD);

    uint8_t i;

    oled_write_ln_P(PSTR(""), false);

    oled_write_P(PSTR("Hue:    ["), changing_hue);
    for(i = 0; i < width; ++i) {
        oled_write_P(i<hue?PSTR("-"):i==hue?PSTR("|"):PSTR(" "), changing_hue);
    }
    oled_write_P(PSTR("]"), changing_hue);
    oled_write_P(PSTR("Sat:    ["), changing_sat);
    for(i = 0; i < width; ++i) {
        oled_write_P(i<sat?PSTR("-"):i==sat?PSTR("|"):PSTR(" "), changing_sat);
    }
    oled_write_P(PSTR("]"), changing_sat);
    oled_write_P(PSTR("Bri:    ["), changing_val);
    for(i = 0; i < width; ++i) {
        oled_write_P(i<val?PSTR("-"):i==val?PSTR("|"):PSTR(" "), changing_val);
    }
    oled_write_P(PSTR("]"), changing_val);
}
#endif // RGBLIGHT_ENABLE

void render_layer_state(void) {
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
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
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
    }
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:   "), false);
    oled_write_P(PSTR("123"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(led_usb_state & (1 << USB_LED_CAPS_LOCK)?PSTR("ABC"):PSTR("abc"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:   "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("W"), (modifiers & MOD_MASK_GUI));
}

static void render_status(void) {
    // Host Keyboard Layer Status
    render_default_layer_state();
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods() | get_oneshot_mods());
#ifdef RGBLIGHT_ENABLE
    render_rgb_state();
#endif // RGBLIGHT_ENABLE
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x1c, 0x1c, 0x38, 0xf8, 
        0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
        0x03, 0x1f, 0x7f, 0xfe, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x87, 0x9f, 0x3f, 0xfc, 0xf0, 
        0xe0, 0xc0, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x3f, 0x7f, 0xfe, 0xfe, 0xee, 0xce, 0xfe, 0x8e, 0x0e, 
        0xfe, 0x8e, 0x0e, 0xfe, 0x8e, 0x0e, 0xfe, 0xfe, 0x7e, 0xee, 0xdc, 0x9c, 0x38, 0x78, 0xf0, 0xe0, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf7, 0xe3, 0xc3, 0xc7, 0x8f, 0x0e, 0x1f, 
        0x1f, 0x3f, 0x7f, 0x7f, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 
        0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1, 0xe7, 0xff, 0xdb, 0xff, 0xff, 0x00, 0x00, 0x00, 0x03, 
        0x1f, 0xff, 0xfe, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xfc, 0xff, 0xff, 0x8f, 0x8f, 0x0f, 0x0f, 0x0f, 0x0f, 
        0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x0f, 0x0f, 0x0c, 0x08, 0x0f, 0x0c, 0x08, 
        0x0f, 0x0c, 0x08, 0x0f, 0x0c, 0x08, 0x0f, 0x0f, 0x0e, 0x07, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0x40, 
        0x01, 0x03, 0x07, 0x1f, 0xfe, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
        0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf3, 0xf3, 0xf3, 0x03, 0x03, 0x03, 0x03, 
        0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xf3, 0xff, 0xff, 0x9f, 0x8f, 0x80, 0x80, 0xc0, 0xf0, 0xfc, 
        0x7e, 0x1e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0xce, 0xce, 0xef, 0x67, 0x67, 0x6f, 0x6f, 0xef, 0xee, 
        0xce, 0x8e, 0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0x60, 
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 
        0xbf, 0x83, 0x8f, 0xff, 0xff, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 
        0x1c, 0x0c, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0x1c, 0x0e, 0x06, 
        0x06, 0x06, 0x06, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0c, 0x06, 0x06, 0x06, 
        0x0e, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 
        0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0xff, 
        0xef, 0xc7, 0x80, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x1b, 0x39, 0x70, 0xf0, 
        0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x3f, 0x3f, 0x1f, 0x01, 
        0x01, 0x01, 0x01, 0x01, 0x07, 0x3f, 0x3f, 0x3c, 0x20, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1f, 0x1c, 0x38, 0x30, 
        0x30, 0x30, 0x30, 0x38, 0x18, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x3f, 
        0x1f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x1f, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x3c, 0x1f, 
        0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(logo, 1024);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    else {
        render_logo();
    }
}
#endif
