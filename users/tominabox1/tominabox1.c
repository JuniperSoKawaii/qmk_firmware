#include "tominabox1.h"

void dance_esc_tab (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return register_code16(KC_ESC);
    else return register_code16(KC_TAB);
  }
}

void dance_esc_tab_reset (qk_tap_dance_state_t *state, void *user_data) {
        unregister_code16(KC_ESC);
        unregister_code16(KC_TAB);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_ESC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_esc_tab, dance_esc_tab_reset),
};

uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
        case RSFT_T(KC_DOT):
            return 150;
        case KC_ENT_LOW:
            return 150;
        case LT(_LOWER, KC_SPC):
            return 270;
        case LCTL_T(KC_TAB):
            return 120;
        default:
            return TAPPING_TERM;
    }
};

__attribute__ ((weak))
layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user (layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return layer_state_set_keymap (state);
}

enum combo_events {
  EMAIL,
  COMBO_RESET,
  CAPS_COMBO,
  CRET,
  COMBOPP,
  COMBO_NEXT,
  COMBO_PREV
};

const uint16_t PROGMEM email[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_reset[] = {KC_W, KC_ESC, COMBO_END};
#ifdef KEYBOARD_crkbd_rev1
const uint16_t PROGMEM caps_combo[] = {KC_M, KC_V, COMBO_END};
#endif
#ifndef KEYBOARD_crkbd_rev1
const uint16_t PROGMEM caps_combo[] = {KC_K, KC_V, COMBO_END};
#endif
const uint16_t PROGMEM cret[] = {KC_QUOT, KC_O, COMBO_END};
const uint16_t PROGMEM combo_pp[] = {KC_7, KC_9, COMBO_END};
const uint16_t PROGMEM combo_next[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_prev[] = {KC_7, KC_8, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [EMAIL] = COMBO_ACTION(email),
  [COMBO_RESET] = COMBO_ACTION(combo_reset),
  [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
  [CRET] = COMBO(cret, KC_ENT),
  [COMBOPP] = COMBO(combo_pp,KC_MPLY),
  [COMBO_NEXT] = COMBO(combo_next,KC_MNXT),
  [COMBO_PREV] = COMBO(combo_prev,KC_MPRV),
};

__attribute__ ((weak))
void process_combo_keymap(uint8_t combo_index, bool pressed) {
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case EMAIL:
    if (pressed) {
      SEND_STRING("tom.campie@gmail.com");
    }
break;
    case COMBO_RESET:
    if (pressed) {
      reset_keyboard();
    }
    break;
  }
}
__attribute__ ((weak))
void process_record_keymap(uint8_t combo_index, bool pressed) {
}

bool spongebob_mode = false;
bool spongebob_case = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (spongebob_mode) {
    switch(keycode) {
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          (spongebob_case ^= 1) == 0 ? tap_code16(S(keycode)) : tap_code(keycode);
          return false; break;
        }
    }
  }
  switch(keycode) {
    case SPONGEBOB:
      if (record->event.pressed) {
        spongebob_mode ^= 1;
      }
      return false; break;
    // OTHER NORMAL process_record_user CASES GO HERE
  }
  return true;
}
