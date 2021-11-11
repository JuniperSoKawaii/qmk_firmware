#include QMK_KEYBOARD_H

// Left-hand home row mods
// #define GUI_A LGUI_T(KC_A)
// #define ALT_S LALT_T(KC_S)
// #define SFT_D LSFT_T(KC_D)
// #define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
// #define CTL_J RCTL_T(KC_J)
// #define SFT_K RSFT_T(KC_K)
// #define ALT_L LALT_T(KC_L)
// #define GUI_SCLN RGUI_T(KC_SCLN)



// Tap Dance keycodes
enum td_keycodes {
    L_BRAX, // Used in the keymap, add additional keycodes for each tapdance.
    R_BRAX,
    QUOTS,  
    TACHE   
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    DOUBLE_TAP,           // SINGLE_HOLD,
    TRIPLE_TAP            // DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void lbrax_finished(qk_tap_dance_state_t *state, void *user_data);
void lbrax_reset(qk_tap_dance_state_t *state, void *user_data);

void rbrax_finished(qk_tap_dance_state_t *state, void *user_data);
void rbrax_reset(qk_tap_dance_state_t *state, void *user_data);

void quots_finished(qk_tap_dance_state_t *state, void *user_data);
void quots_reset(qk_tap_dance_state_t *state, void *user_data);

void tache_finished(qk_tap_dance_state_t *state, void *user_data);
void tache_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NUBS, KC_SLSH, KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT, LCTL_T(KC_ESC), KC_LALT, KC_LGUI, KC_LSFT, MO(1), KC_SPC, KC_SPC, MO(2), KC_LSFT, TD(QUOTS), KC_LALT, LCTL_T(KC_TAB)),
	[1] = LAYOUT(KC_EXLM, KC_DQUO, LSFT(KC_3), KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_DEL, KC_BSPC, KC_F24, LALT(KC_F3), KC_NO, KC_NO, TD(L_BRAX), TD(R_BRAX), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LCTL(KC_F12), LALT(KC_X), KC_NO, KC_NO, KC_NO, TD(QUOTS), TD(TACHE), KC_MINS, KC_EQL, KC_COMM, KC_DOT, KC_ENT, KC_TRNS, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS),
	[2] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F24, LALT(KC_F3), KC_NO, KC_NO, TD(L_BRAX), TD(R_BRAX), KC_HOME, KC_PGDN, KC_PGUP, KC_END, LCTL(KC_F12), LALT(KC_X), KC_NO, KC_NO, KC_NO, TD(QUOTS), TD(TACHE), KC_MINS, KC_EQL, KC_COMM, KC_DOT, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_TRNS),
	[3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_ASTG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_UP), LCA(KC_RGHT), KC_LCTL, LALT(KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_LCTL, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_TRNS)
};


/* 
Notes on keys
or, why on earth do I have keymap 
lower-z is CTRL-F12 - Darkroom mode in emacs
lower-x is ALT-X - emacs
lower-a is F24 - i3 controls popup reminder
lower-s is ALT-F3 - multi-select in Sublime text
*/





/*
// tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    // case RCTL_T(KC_J):
    // return TAPPING_TERM + 500;
    // case LCTL_T(KC_F):
      // or
      //  return 500;
      //  case LALT_T(KC_TAB): 
      //  return 500; 
    default: 
      return TAPPING_TERM;
    }
}
*/

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        return SINGLE_TAP;
    } else if (state->count == 2) {
        return DOUBLE_TAP;
    } else if (state->count == 3) {
        return TRIPLE_TAP;
    } else {
        reset_tap_dance (state);
        return 3;
    }
}


