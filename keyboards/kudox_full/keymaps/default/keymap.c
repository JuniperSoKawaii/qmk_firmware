// Copyright 2021 Kumao Kobo (@kumaokobo)
// SPDX-License-Identifier: GPL-2.0+

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE,
  _FN1,
  _FN2,
  _FN3,
};

// Shortcut to make keymap more readable
#define LT_AESC LALT_T(KC_ESC)
#define LT_ALN1 LALT_T(KC_LANG1)
#define LT_ALN2 LALT_T(KC_LANG2)
#define LT_GENT LGUI_T(KC_ENT)
#define LT_GSPC LGUI_T(KC_SPC)
#define LT_F1F  LT(_FN1, KC_F)
#define LT_F2J  LT(_FN1, KC_J)
#define LT_F2DL LT(_FN2, KC_DEL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,                 KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_BSPC ,KC_DEL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                └────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_GRV  ,                          KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_A    ,KC_S    ,KC_D    ,LT_F1F  ,KC_G,                                       KC_H    ,LT_F2J  ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT  ,KC_ENT  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_UP   ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,KC_RSFT ,KC_UP   ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                         ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     LT_AESC ,MO(_FN3),LT_F2DL ,LT_ALN2 ,LT_GENT ,KC_SPC  ,                          KC_DOWN ,LT_GSPC ,LT_ALN1 ,                           KC_LEFT ,KC_DOWN ,KC_RIGHT
  //└────────┴────────┴────────┴────────┴────────┴────────┘                         └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,                 KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_UNDS ,KC_PLUS ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                └────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_DQUO ,KC_QUOT ,KC_HASH ,KC_ASTR ,KC_PLUS ,KC_TILD ,                          KC_LPRN ,KC_RPRN ,KC_PIPE ,KC_ASTR ,KC_TILD ,KC_LCBR ,KC_RCBR ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_AT   ,KC_COLN ,KC_GRV  ,_______ ,KC_MINS ,                                   KC_LBRC ,KC_RBRC ,KC_DOT  ,KC_SLSH ,KC_COLN ,KC_DQT  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     _______ ,_______ ,_______ ,KC_COMM ,KC_DOT  ,KC_SLSH ,                          KC_UNDS ,KC_LCBR ,KC_RCBR ,KC_LT   ,KC_GT   ,KC_QUES ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                         ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,                           _______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┴────────┴────────┘                         └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,                 KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                └────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_DQUO ,KC_QUOT ,KC_HASH ,KC_ASTR ,KC_PLUS ,KC_TILD ,                          KC_LPRN ,KC_RPRN ,KC_PIPE ,KC_ASTR ,KC_TILD ,KC_CIRC ,KC_SLSH ,KC_JYEN ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_AT   ,KC_COLN ,KC_GRV  ,_______ ,KC_MINS ,                                   KC_LBRC ,_______ ,KC_DOT  ,KC_SLSH ,KC_MINS ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     _______ ,_______ ,_______ ,KC_COMM ,KC_DOT  ,KC_SLSH ,                          _______ ,KC_LCBR ,KC_RCBR ,KC_SLSH ,KC_MINS ,KC_UNDS ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                         ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,                           _______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┴────────┴────────┘                         └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,RGB_VAI ,RGB_VAD ,                 RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,RGB_VAI ,RGB_VAD ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                └────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     RGB_M_X ,RGB_M_K ,RGB_M_SN,RGB_M_B ,RGB_M_R ,RGB_M_SW,                          RGB_M_SW,RGB_M_R ,RGB_M_B ,RGB_M_SN,RGB_M_K ,RGB_M_X ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                         ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,MO(_BASE),RGB_MOD ,RGB_TOG ,                         RGB_TOG ,RGB_MOD ,MO(_BASE),                          _______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┴────────┴────────┘                         └────────┴────────┴────────┘                          └────────┴────────┴────────┘
  )

};


#ifdef RGBLIGHT_ENABLE
void eeconfig_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
};
#endif

#ifdef OLED_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Kudox Keyboard"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("\n"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("\nLayer: Symbol"), false);
            break;
        case _FN2:
            oled_write_ln_P(PSTR("\nLayer: Function"), false);
            break;
        case _FN3:
            oled_write_ln_P(PSTR("\nLayer: Light"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("\nLayer: Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
