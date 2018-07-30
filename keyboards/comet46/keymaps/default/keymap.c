// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#ifdef SSD1306OLED
  #include "ssd1306.h"
  #include "keylogger.c"
#endif


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum comet46_layers
{
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------+                    +-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Ctl  |   A  |   S  |   D  |   F  |   G  | Esc  |      | Del  |   H  |   J  |   K  |   L  |   ;  |   "  |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   {  |      |   }  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             | GUI  | Lower| Space|      | Enter| Raise| Alt  |
   *                             +--------------------/      \--------------------+
   */
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ESC,         KC_DEL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,        KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LGUI, LOWER,   KC_SPC,         KC_ENT,  RAISE,   KC_LALT
  ),

  /* Colemak
   * ,-----------------------------------------+                    +-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Ctl  |   A  |   R  |   S  |   T  |   D  | Esc  |      | Del  |   H  |   N  |   E  |   I  |   O  |   "  |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   {  |      |   }  |   K  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             | GUI  | Lower| Space|      | Enter| Raise| Alt  |
   *                             +--------------------/      \--------------------+
   */
  [_COLEMAK] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_ESC,         KC_DEL,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,        KC_RCBR, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                        KC_LGUI, LOWER,   KC_SPC,         KC_ENT,  RAISE,   KC_LALT
  ),

  /* Dvorak
   * ,-----------------------------------------+                    +-----------------------------------------.
   * | Tab  |   "  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Ctl  |   A  |   O  |   E  |   U  |   I  | Esc  |      | Del  |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   {  |      |   }  |   B  |   M  |   W  |   V  |   Z  | Shift|
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             | GUI  | Lower| Space|      | Enter| Raise| Alt  |
   *                             +--------------------/      \--------------------+
   */
  [_DVORAK] = LAYOUT(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                             KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_ESC,         KC_DEL,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LCBR,        KC_RCBR, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,
                                        KC_LGUI, LOWER,   KC_SPC,         KC_ENT,  RAISE,   KC_LALT
  ),

  /* Lower
   * ,-----------------------------------------+                    +-----------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   `  |   \  |   -  |   =  |   [  |   ]  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   ~  |   |  |   _  |   +  |   {  |   }  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             |      |      |      |      |      |      |      |
   *                             +--------------------/      \--------------------+
   */
  [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______,        KC_GRV,  KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______,        KC_TILD, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
                                        _______, _______, _______,        _______, _______, _______
  ),

  /* Raise
   * ,-----------------------------------------+                    +-----------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      | Left | Down |  Up  |Right | End  |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Home |      | PgDn | PgUp |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             |      |      |      |      |      |      |      |
   *                             +--------------------/      \--------------------+
   */
  [_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,         KC_HOME, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, _______,
                                        _______, _______, _______,        _______, _______, _______
  ),

  /* Adjust
   * ,-----------------------------------------+                    +-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |Qwerty|      |Colemk|      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |Reset |      |Dvorak|      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+      +------+------+------+------+------+-------------|
   *                             |      |      |      |      |      |      |      |
   *                             +--------------------/      \--------------------+
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, QWERTY,         COLEMAK, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RESET,          DVORAK,  _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______,        _______, _______, _______
  )
};


uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef SSD1306OLED
        iota_gfx_init(false);   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

// static void render_logo(struct CharacterMatrix *matrix) {

//   static char logo[]={
//     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
//     0};
//   matrix_write(matrix, logo);
//   //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
// }



void render_status(struct CharacterMatrix *matrix) {

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("Layer: "));
  uint8_t layer = biton32(layer_state);
    switch (layer) {
        case _QWERTY:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case _RAISE:
           matrix_write_P(matrix, PSTR("Raise"));
           break;
        case _LOWER:
           matrix_write_P(matrix, PSTR("Lower"));
           break;
        case _ADJUST:
           matrix_write_P(matrix, PSTR("Adjust"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  static char ind[3][2][3]={{{0x97,0x98,0},{0xb7,0xb8,0}},//num lock
                           {{0x99,0x9a,0},{0xb9,0xba,0}},//caps lock
                           {{0x9b,0x9c,0},{0xbb,0xbc,0}},};//scroll lock
  static char indoff[]={0};
  bool statn = (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK));
  bool statc = (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK));
  bool stats = (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK));
  matrix_write_P(matrix, PSTR("\n"));
  matrix_write(matrix, statn ? ind[0][0]:indoff);
  matrix_write(matrix, statc ? ind[1][0]:indoff);
  matrix_write(matrix, stats ? ind[2][0]:indoff);
  matrix_write_P(matrix, PSTR("\n"));
  matrix_write(matrix, statn ? ind[0][1]:indoff);
  matrix_write(matrix, statc ? ind[1][1]:indoff);
  matrix_write(matrix, stats ? ind[2][1]:indoff);
  matrix_write_P(matrix, PSTR("\n"));
  matrix_write(matrix, read_keylog());
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  render_status(&matrix);
  matrix_update(&display, &matrix);
}

#endif

