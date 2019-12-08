#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _GAMING 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST,
  GAMING,
  AE,
  EE,
  IE,
  VAD_NEE,
  VAI_NEE,
  SAI_NEE,
  SAD_NEE,
  HUI_NEE,
  HUD_NEE,
  TOG_NEE,
  RGB_ANM,
  RGB_PRE,
  SLIGHTLY,
  SMILE,
  JOY,
  RELAXED,
  HEART,
  SAD,
  CRY,
  NETRURAL,
  SCREAM,
  THUMBSUP
};

enum td_extra_keys {
  U = 0 ,
  O = 1,
  NEXTPREV = 2,
  SLASH = 3
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance (qk_tap_dance_state_t *state);

void u_finished (qk_tap_dance_state_t *state, void *user_data);
void o_finished (qk_tap_dance_state_t *state, void *user_data);

uint32_t rgb_mode = RGBLIGHT_MODE_BREATHING + 1;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl | ALT  |Numpad| GUI  |Lower | Space|                | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(SLASH), KC_ENT , \
   KC_LCTL, KC_LALT, NUMPAD,  KC_LGUI, LOWER,   KC_SPC,       KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |  :)  |  :D  |  :'D |  :$  |  <3  |      |                | Home | Pgup |      |   {  |   }  |  |   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |  :(  |  :'( |  :|  |  :O  |  +1  |      |                | End  |Pgdown|      |   [  |   ]  |PrntSc|
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |Insert|                |  Del |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL, \
  SLIGHTLY, SMILE, JOY, RELAXED, HEART, _______,              KC_HOME, KC_PGUP, _______, KC_LCBR, KC_RCBR, KC_PIPE, \
  SAD, CRY, NETRURAL, SCREAM, THUMBSUP, _______,              KC_END, KC_PGDOWN,_______, KC_LBRC, KC_RBRC, KC_PSCREEN, \
  _______, _______, _______, _______, _______, KC_INSERT,     KC_DEL, _______,  TD(NEXTPREV), KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Reset|EEPRST|      |  EE  |      |      |                |      |  UE  |  IE  |  OE  |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  AE  |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TGLAS|      |      |      |      |      |                |      |      |      |      |      |GAMING|
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   EEP_RST, _______, EE,      _______, _______,       _______, TD(U),   IE,      TD(O),   _______, _______, \
  _______, AE,      _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  KC_ASTG, _______, _______, _______, _______, _______,       _______, _______, _______, _______, QWERTY, GAMING   \
),

/* Numpad
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |      |      |      |      |      |      |               |   7  |   8  |   9  |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      |      |      |               |   4  |   5  |   6  |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |  VAI |  VAD |  SAI |  SAD | HUI  | HUD  |               |   3  |   2  |   1  |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |RGBMPR|RGBMFW|RGBTGL|               | Calc |   0  |   +  |      |      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______,       KC_7,    KC_8,   KC_9,    _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,       KC_4,    KC_5,   KC_6,    _______, _______, _______, \
  VAI_NEE, VAD_NEE, SAI_NEE, SAD_NEE, HUI_NEE, HUD_NEE,       KC_1,    KC_2,   KC_3,    _______, _______, _______, \
  _______, _______, _______, RGB_PRE, RGB_ANM, TOG_NEE,       KC_CALC, KC_0,   KC_PPLS, _______, _______, _______  \
),

/* Gaming
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      | RAISE|      |               |      | LOWER|      |      |      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_GAMING] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, RAISE,   _______,       _______, LOWER,   _______, _______, _______, _______  \
)};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
	rgb_mode = RGBLIGHT_MODE_BREATHING + 1;
	autoshift_enable();
        persistent_default_layer_set(1UL<<_QWERTY);
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
    case GAMING:
      if (record->event.pressed) {
	rgb_mode = RGBLIGHT_MODE_RAINBOW_SWIRL + 5;
        autoshift_disable();
	default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case NUMPAD:
      if(record->event.pressed){
	layer_on(_NUMPAD);
	PORTB &= ~(1<<0);
      } else {
	layer_off(_NUMPAD);
	PORTB |= (1<<0);
      }
      return false;
      break;
    case AE:           
      if(record->event.pressed) {
	SEND_STRING(SS_RALT("'"));
      }    
      break;
    case EE:            
      if(record->event.pressed) {
	SEND_STRING(SS_RALT(";"));
      }    
      break;
    case IE:            
      if(record->event.pressed) {
	SEND_STRING(SS_RALT("z"));
      }    
      break;
    case VAI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_val_noeeprom();
      }    
      break;
    case VAD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_val_noeeprom();
      }    
      break;
    case SAI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_sat_noeeprom();
      }    
      break;
    case SAD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_sat_noeeprom();
      }    
      break;
    case HUI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_hue_noeeprom();
      }    
      break;
    case HUD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_hue_noeeprom();
      }    
      break;
    case TOG_NEE:            
      if(record->event.pressed) {
	rgblight_toggle_noeeprom();
      }    
      break;
    case RGB_ANM:            
      if(record->event.pressed) {
        rgblight_step_noeeprom();
	rgb_mode = rgblight_get_mode();
      }    
      break;
    case RGB_PRE:            
      if(record->event.pressed) {
        rgblight_step_reverse_noeeprom();
	rgb_mode = rgblight_get_mode();
      }    
      break;
    case SLIGHTLY:
      if(record->event.pressed) {
	SEND_STRING(":slightly_smiling_face:");
      }    
      break;
    case SMILE:
      if(record->event.pressed) {
	SEND_STRING(":smile:");
      }    
      break;
    case JOY:
      if(record->event.pressed) {
	SEND_STRING(":joy:");
      }    
      break;
    case RELAXED:
      if(record->event.pressed) {
	SEND_STRING(":relaxed:");
      }    
      break;
    case HEART:
      if(record->event.pressed) {
	SEND_STRING(":heart:");
      }    
      break;
    case SAD:
      if(record->event.pressed) {
	SEND_STRING(":white_frowning_face:");
      }    
      break;
    case CRY:
      if(record->event.pressed) {
	SEND_STRING(":cry:");
      }    
      break;
    case NETRURAL:
      if(record->event.pressed) {
	SEND_STRING(":neutral_face:");
      }    
      break;
    case SCREAM:
      if(record->event.pressed) {
	SEND_STRING(":scream:");
      }    
      break;
    case THUMBSUP:
      if(record->event.pressed) {
	SEND_STRING(":+1:");
      }    
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _RAISE:
      rgblight_setrgb_at(255, 255, 255, RGBLED_NUM / 2);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _LOWER:
      rgblight_setrgb_at(255, 255, 255, RGBLED_NUM / 2 - 1);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _NUMPAD:
      rgblight_setrgb_at(0,255,0, 0);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    default:
      rgblight_mode_noeeprom(rgb_mode);      
      break;
  }
  return state;
}

void led_set_user(uint8_t usb_led) {
  rgblight_sethsv_noeeprom(0, 255, 255);
  rgblight_mode_noeeprom(rgb_mode);
}

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

static tap utap_state = {
  .is_press_action = true,
  .state = 0
};

static tap otap_state = {
  .is_press_action = true,
  .state = 0
};

void u_finished (qk_tap_dance_state_t *state, void *user_data) {
  utap_state.state = cur_dance(state);
  switch(utap_state.state) {
    case SINGLE_TAP: SEND_STRING(SS_RALT("]")); break;
    case DOUBLE_TAP: SEND_STRING(SS_RALT("-")); break;
    case TRIPLE_TAP: SEND_STRING(SS_RALT("\\")); break;
  }
}

void o_finished (qk_tap_dance_state_t *state, void *user_data) {
  otap_state.state = cur_dance(state);
  switch(otap_state.state) {
    case SINGLE_TAP: SEND_STRING(SS_RALT("=")); break;
    case DOUBLE_TAP: SEND_STRING(SS_RALT("0")); break;
    case TRIPLE_TAP: SEND_STRING(SS_RALT("[")); break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [U] = ACTION_TAP_DANCE_FN(u_finished),
  [O] = ACTION_TAP_DANCE_FN(o_finished),
  [NEXTPREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
  [SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLS)
 };
