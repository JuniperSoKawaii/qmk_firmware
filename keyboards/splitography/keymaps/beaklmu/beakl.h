
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ................................................................... BEAKL 8MU

  // ,-----------------------------------------------------------------------------------.
  // |   Q  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   K  |   H  |   E  |   A  |   .  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   ;  |   "  |   I  |   ,  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  Esc | Space|  Ent | Bksp |                           |
  // `-----------------------------------------------------------------------------------'

  [_BASE] = {
    {KC_Q,    KC_Y,    KC_O,    KC_U,    KC_Z,    CNTR_TL, CNTR_TR, KC_G,    KC_D,    KC_N,    KC_M,    KC_X   },
    {HOME_K,  HOME_H,  HOME_E,  HOME_A,  KC_DOT,  CNTR_HL, CNTR_HR, KC_C,    HOME_T,  HOME_R,  HOME_S,  HOME_W },
    {KC_J,    KC_SCLN, TD_QUOT, KC_I,    KC_COMM, CNTR_BL, CNTR_BR, KC_B,    KC_P,    KC_L,    KC_F,    KC_V   },
    {_______, _______, _______, _______, LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC, _______, _______, _______, _______},
  },

  [_SHIFT] = {
    {S(KC_Q), S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X)},
    {S(KC_K), S(KC_H), S(KC_E), S(KC_A), KC_DOT,  CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W)},
    {S(KC_J), KC_SCLN, TD_QUOT, S(KC_I), KC_COMM, CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V)},
    {_______, _______, _______, _______, LT_ESC,  TD_SPC,  TD_ENT,  LT_BSPC, _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |   Q  |   Y  |   [  |   ]  |   Z  |  Fn  | Caps |   G  |   D  |   N  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   K  |   ^  |   <  |   >  |   ~  |Cursor| Mouse|   C  |   T  |   R  |   S  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   :  |   !  |   =  |   `  |  Num | Regex|   B  |   P  |   L  |   F  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           | ↑Tab |  f() |   _  |  Del |                           |
  // `-----------------------------------------------------------------------------------'

  [_LSHIFT] = {
    {S(KC_Q), S(KC_Y), KC_LBRC, KC_RBRC, S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), S(KC_D), S(KC_N), S(KC_M), S(KC_X)},
    {S(KC_K), KC_CIRC, TD_LT,   TD_GT,   TD_TILD, CNTR_HL, CNTR_HR, S(KC_C), S(KC_T), S(KC_R), S(KC_S), S(KC_W)},
    {S(KC_J), KC_COLN, KC_EXLM, KC_EQL,  TD_GRV,  CNTR_BL, CNTR_BR, S(KC_B), S(KC_P), S(KC_L), S(KC_F), S(KC_V)},
    {_______, _______, _______, _______, S_TAB,   ___fn__, KC_UNDS, KC_DEL,  _______, _______, _______, _______},
  },

  // ,-----------------------------------------------------------------------------------.
  // |   Q  |   Y  |   O  |   U  |   Z  |  Fn  | Caps |   G  |   {  |   }  |   M  |   X  |
  // |------+------+------+------+------+-------------+------+------+------+------+------|
  // |   K  |   H  |   E  |   A  |   ?  |Cursor| Mouse|   |  |   (  |   )  |   $  |   W  |
  // |------+------+------+------+------+------|------+------+------+------+------+------|
  // |   J  |   :  |   "  |   I  |   /  |  Num | Regex|   \  |   *  |   .  |   P  |   V  |
  // |------+------+------+------+------+------+------+------+------+------+------+------|
  // |                           |  Tab |   -  |  f() | Bksp |                           |
  // `-----------------------------------------------------------------------------------'

  [_RSHIFT] = {
    {S(KC_Q), S(KC_Y), S(KC_O), S(KC_U), S(KC_Z), CNTR_TL, CNTR_TR, S(KC_G), KC_LCBR, KC_RCBR, S(KC_M), S(KC_X)},
    {S(KC_K), S(KC_H), S(KC_E), S(KC_A), KC_QUES, CNTR_HL, CNTR_HR, KC_PIPE, KC_LPRN, KC_RPRN, KC_DLR,  S(KC_W)},
    {S(KC_J), TD_COLN, TD_DQOT, S(KC_I), KC_SLSH, CNTR_BL, CNTR_BR, KC_BSLS, KC_ASTR, KC_DOT,  S(KC_P), S(KC_V)},
    {_______, _______, _______, _______, KC_TAB,  KC_MINS, ___fn__, LT_BSPC, _______, _______, _______, _______},
  },
