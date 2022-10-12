/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,\~^`````
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers{
	_QWERTY,
	_NAV,
	_SYMBOL,
	_NUMPAD,
	_CONFIG
};

// Tap Dance acentos
enum tapDance{
//	TD_A,
//	TD_E,
//	TD_I,
//	TD_O,
//	TD_U,
	TD_CTRALT,
	TD_MAYUS
};

//Macros
//enum custom_keycodes {
//	MC_A,
//	MC_E,
//	MC_I,
//	MC_O,
//	MC_U
//};


// Macro Definitions acentos
//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch(keycode) {
//
//    // for basic strings
//    case MC_A: 
//        if (record->event.pressed)
//            SEND_STRING("á"); 
//			break;
//	case MC_E:
//        if (record->event.pressed)
//            SEND_STRING("é");
//            break;
//	case MC_I:
//        if (record->event.pressed)
//            SEND_STRING("í"); 
//            break;
//	case MC_O:
//        if (record->event.pressed)
//            SEND_STRING("ó");
//            break;
//	case MC_U:
//        if (record->event.pressed)
//            SEND_STRING("ú");
//            break;
//  }
//  return true;
//};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    //[TD_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, MC_A),
	//[TD_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, MC_E),
	//[TD_I] = ACTION_TAP_DANCE_DOUBLE(KC_I, MC_I),
	//[TD_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, MC_O),
	//[TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, MC_U),
	[TD_CTRALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_LALT),
	[TD_MAYUS] = ACTION_TAP_DANCE_DOUBLE(KC_LSHIFT, KC_CAPSLOCK)
};

// Base
//  ,-----------------------------------------------------.                    ,-----------------------------------------------------.
//  |Tab/LGui|   Q    |   W    |   E    |   R    |   T    |                    |   Y    |   U    |   I    |   O    |   P    | Bksp   |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | CtrlSc |   A    |   S    |   D    |   F    |   G    |                    |   H    |   J    |   K    |   L    | ;/Mous | '/Rctl |
//  |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//  | Shift  |   Z    |   X    |   C    |   V    |   B    |                    |   N    |   M    |   ,    |   .    |   /    | SftEnT |
//  `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
//                                      |  LALT  | LOWER  |Spc/FUN |  | Spc/NAV| RAISE  |ACCENTS |
//                                      `--------------------------'  `--------------------------'
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESCAPE,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LBRACKET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TD(TD_MAYUS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLASH,  KC_MINUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          TD(TD_CTRALT),   LT(1,KC_LGUI),  LT(3,KC_SPC),     KC_SPACE,   LT(2,KC_ENTER), KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESCAPE,    RALT(KC_Q),    XXXXXXX,    XXXXXXX,    LCTL(KC_ENTER),    KC_NONUS_BSLASH,                         KC_PSCREEN,    KC_HOME,    KC_UP,    KC_END,    XXXXXXX, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, XXXXXXX, XXXXXXX, KC_LSHIFT, LSFT(KC_LCTRL), KC_KP_ASTERISK,                      XXXXXXX, KC_LEFT,   KC_DOWN,KC_RIGHT, XXXXXXX, KC_INSERT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LCTRL, KC_LALT, LCTL(KC_INSERT), LSFT(KC_INSERT), LSFT(KC_0),                      XXXXXXX, KC_LSHIFT, XXXXXXX, KC_LCTRL, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_LCTRL
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRAVE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6,  KC_LBRACKET, KC_QUOTE, KC_NONUS_HASH, KC_RBRACKET,  KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,                      KC_F12, RALT(KC_MINUS), LSFT(KC_QUOTE), LSFT(KC_NONUS_HASH), RALT(KC_NONUS_HASH), KC_NONUS_BSLASH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(4),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_BRIU, XXXXXXX,                      KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_BSPACE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_BRID, KC_LALT,                      KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, KC_NUMLOCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RALT, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
 [_CONFIG] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_SN, RGB_M_B,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_K, RGB_M_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE

static const char PROGMEM windows_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xbc, 0xbe, 0xbe, 0x00, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x00, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const char PROGMEM mac_logo[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0xf6, 0xfb, 0xfb, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }else if (is_keyboard_master()){
    return OLED_ROTATION_270;
  }
  return rotation;
}

//#define L_BASE 0
//#define L_NAV 2
//#define L_SIMBOLOS 4
//#define L_NUMPAD 8
//#define L_ADJUST 16

void oled_render_layer_state(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 4);
    oled_write_P(PSTR("Capa: \n"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("Symb"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NumP"), false);
            break;
        case _CONFIG:
        //case _CONFIG|_NAV:
        //case _CONFIG|_SYMBOL:
        //case _CONFIG|_NAV|_SYMBOL:
            oled_write_ln_P(PSTR("Conf"), false);
            break; 
    }
    oled_write_P(PSTR("\n"), false);
    oled_set_cursor(0, 10);
    oled_write_P(host_keyboard_led_state().num_lock ? PSTR("NUM") : PSTR("       "), false);
    oled_set_cursor(0, 11);
    oled_write_P(host_keyboard_led_state().caps_lock ? PSTR("CAPS") : PSTR("       "), false);

    
}    


//char keylog_str[24] = {};
//
//const char code_to_name[60] = {
//    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
//
//void set_keylog(uint16_t keycode, keyrecord_t *record) {
//  char name = ' ';
//    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//  if (keycode < 60) {
//    name = code_to_name[keycode];
//  }
//
//  // update keylog
//  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//           record->event.key.row, record->event.key.col,
//           keycode, name);
//}
//
//void oled_render_keylog(void) {
//    oled_write(keylog_str, false);
//}

//void render_bootmagic_status(bool status) {
//    /* Show Ctrl-Gui Swap options */
//    static const char PROGMEM logo[][2][3] = {
//        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//    };
//    if (status) {
//        oled_write_ln_P(logo[0][0], false);
//        oled_write_ln_P(logo[0][1], false);
//    } else {
//        oled_write_ln_P(logo[1][0], false);
//        oled_write_ln_P(logo[1][1], false);
//    }
//}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
	//oled_set_cursor(0, 13);
    //oled_write_P(PSTR("\nIknoyV1.0"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
		oled_render_layer_state();

    } else {
        oled_render_logo();
    }
    return false;
}



//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//  return true;
//}
#endif // OLED_ENABLE

#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_user(void){
	rgb_matrix_set_suspend_state(true);
}

void suspend_wake_init_user(void){
	rgb_matrix_set_suspend_state(false);
}

#endif