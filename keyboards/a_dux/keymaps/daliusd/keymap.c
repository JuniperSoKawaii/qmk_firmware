/* Copyright 2021 @daliusd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "flow.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _QWERTY,
    _SYM,
    _NAV,
    _MISC,
    _TMUX,
    _MOUSE,
    _FUNC,
};

enum custom_keycodes {
  TM_NEXT = SAFE_RANGE,
  TM_PREV,
  TM_LEFT,
  TM_RIGHT,
  TM_NEW,
  TM_SLCT,
  TM_SRCH,
  TM_URL,
  OS_MISC,
  OS_TMUX,
  OS_FUNC,
};

// Shortcut to make keymap more readable

#define L_NAV       MO(_NAV)
#define L_SYM       MO(_SYM)
#define L_MOUSE     TG(_MOUSE)

#define K_PRINT     (QK_LCTL | QK_LSFT | QK_LGUI | KC_4)
#define K_CSPC      LCTL(KC_SPC)
#define K_GUI_X     LGUI(KC_X)
#define K_GUI_C     LGUI(KC_C)
#define K_GUI_V     LGUI(KC_V)

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LALT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LCTL},
    {L_SYM, KC_LCTL},
    {L_SYM, KC_LGUI},
    {L_SYM, KC_LALT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_MISC, _MISC},
    {OS_TMUX, _TMUX},
    {OS_FUNC, _FUNC},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T,                              KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_NAV   ,    KC_SPC  ,        KC_LSFT ,    L_SYM
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_PLUS ,KC_LBRC ,KC_RBRC ,XXXXXXX ,                          KC_MINS ,KC_PIPE ,KC_LCTL ,KC_LGUI ,KC_LALT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_EQL  ,KC_LCBR ,KC_RCBR ,XXXXXXX ,                          KC_UNDS ,KC_QUOT ,KC_DQT  ,XXXXXXX ,KC_BSLS ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______ ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_LGUI ,KC_LCTL ,KC_TAB  ,KC_ENT  ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DEL  ,KC_BSPC ,OS_MISC ,KC_TILDE,OS_TMUX ,                          K_CSPC  ,XXXXXXX ,KC_COMM ,KC_DOT  ,RESET   ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MISC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     RESET   ,L_MOUSE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_BRID ,KC_BRIU ,XXXXXXX ,KC_PSCR ,K_PRINT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,DEBUG   ,OS_FUNC ,XXXXXXX ,                          KC_MPRV ,KC_MPLY ,XXXXXXX ,KC_MNXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_TMUX] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,TM_URL  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          TM_LEFT ,TM_NEXT ,TM_PREV ,TM_RIGHT,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          TM_NEW  ,TM_SLCT ,XXXXXXX ,XXXXXXX ,TM_SRCH ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,L_MOUSE ,KC_MS_U ,KC_BTN3 ,KC_WH_U ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,                          XXXXXXX ,XXXXXXX ,KC_LCTL ,KC_LGUI ,KC_LALT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ESC  ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_BTN1 ,    KC_BTN2 ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),
};

#define TMUX_PREFIX SS_DOWN(X_LCTL) "b" SS_UP(X_LCTL)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

    switch (keycode) {
        case TM_LEFT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "<");
            return false;
        case TM_RIGHT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX ">");
            return false;
        case TM_NEXT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "n");
            return false;
        case TM_PREV:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "p");
            return false;
        case TM_NEW:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "c");
            return false;
        case TM_SLCT:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "[");
            return false;
        case TM_SRCH:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX "\t");
            return false;
        case TM_URL:
            if (!record->event.pressed) return true;
            SEND_STRING(TMUX_PREFIX SS_LCTL("u"));
            return false;
    }
    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYM, _NAV, _TRI);
// }

void matrix_scan_user(void) {
    flow_matrix_scan();
}

enum combos {
  ZX_GUI_X,
  XC_GUI_C,
  CV_GUI_V,
  DF_ESC,
  SPACE_A,
  SPACE_C,
  SPACE_E,
  SPACE_R,
  SPACE_I,
  SPACE_S,
  SPACE_U,
  SPACE_Y,
  SPACE_Z,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM space_a_combo[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM space_c_combo[] = {KC_SPC, KC_C, COMBO_END};
const uint16_t PROGMEM space_e_combo[] = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM space_r_combo[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM space_i_combo[] = {KC_SPC, KC_I, COMBO_END};
const uint16_t PROGMEM space_s_combo[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM space_u_combo[] = {KC_SPC, KC_U, COMBO_END};
const uint16_t PROGMEM space_y_combo[] = {KC_SPC, KC_Y, COMBO_END};
const uint16_t PROGMEM space_z_combo[] = {KC_SPC, KC_Z, COMBO_END};

combo_t key_combos[COMBO_LENGTH] = {
  [ZX_GUI_X] = COMBO(zx_combo, K_GUI_X),
  [XC_GUI_C] = COMBO(xc_combo, K_GUI_C),
  [CV_GUI_V] = COMBO(cv_combo, K_GUI_V),
  [DF_ESC] = COMBO(df_combo, KC_ESC),
  [SPACE_A] = COMBO_ACTION(space_a_combo),
  [SPACE_C] = COMBO_ACTION(space_c_combo),
  [SPACE_E] = COMBO_ACTION(space_e_combo),
  [SPACE_I] = COMBO_ACTION(space_i_combo),
  [SPACE_R] = COMBO_ACTION(space_r_combo),
  [SPACE_S] = COMBO_ACTION(space_s_combo),
  [SPACE_U] = COMBO_ACTION(space_u_combo),
  [SPACE_Y] = COMBO_ACTION(space_y_combo),
  [SPACE_Z] = COMBO_ACTION(space_z_combo),
};


void swap_layout(void) {
    uint8_t saved_mods = get_mods();
    clear_mods();
    tap_code16(K_CSPC);
    set_mods(saved_mods);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SPACE_A:
      if (pressed) {
        swap_layout();
        tap_code16(KC_1);
        swap_layout();
      }
      break;
    case SPACE_C:
      if (pressed) {
        swap_layout();
        tap_code16(KC_2);
        swap_layout();
      }
      break;
    case SPACE_E:
      if (pressed) {
        swap_layout();
        tap_code16(KC_3);
        swap_layout();
      }
      break;
    case SPACE_R:
      if (pressed) {
        swap_layout();
        tap_code16(KC_4);
        swap_layout();
      }
      break;
    case SPACE_I:
      if (pressed) {
        swap_layout();
        tap_code16(KC_5);
        swap_layout();
      }
      break;
    case SPACE_S:
      if (pressed) {
        swap_layout();
        tap_code16(KC_6);
        swap_layout();
      }
      break;
    case SPACE_U:
      if (pressed) {
        swap_layout();
        tap_code16(KC_7);
        swap_layout();
      }
      break;
    case SPACE_Y:
      if (pressed) {
        swap_layout();
        tap_code16(KC_8);
        swap_layout();
      }
      break;
    case SPACE_Z:
      if (pressed) {
        swap_layout();
        tap_code16(KC_EQL);
        swap_layout();
      }
      break;
  }
}
