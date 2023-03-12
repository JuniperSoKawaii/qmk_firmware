
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LA_BASE Level: Default Layer
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     |Win|
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | LGUI  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |   x   | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |   x   | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

        |------+------+-----------------------+------+------|
        | LAlt | Cont | ******* Space ******* | RGUI | RAlt |
        |------+------+-----------------------+------+------|
    */
    [LA_BASE] = LAYOUT(
        MA_LMOUSE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, DRAG_SCROLL, KC_DEL, KC_LGUI,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, MA_REBOOT, MA_CAPSLOCK,
        MA_LPINKY, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RCTL,
        KC_LALT, MA_LTHUMB, KC_SPC, MO(LA_RTHUMB), KC_RALT
    ),
    [LA_MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_MS_BTN1_UNREG, MA_MS_BTN1_REG, MA_MS_BTN1_TAP, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, MA_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MA_MS_WH_UP, MA_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFT, MA_DOWN, MA_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_LTHUMBMS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_CAPSLOCK] = LAYOUT(
        KC_TRNS, KC_TRNS, S(KC_E), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_E), KC_TRNS, KC_TRNS, S(KC_Q), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), MA_CIRC, KC_TRNS, KC_TRNS,
        KC_TRNS, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_SCLN), S(KC_U), KC_TRNS,
        KC_TRNS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_LPINKY] = LAYOUT(
        KC_TRNS, MA_LGUI, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_Q, MA_W, MA_E, MA_R, MA_T, KC_TRNS, MA_7, MA_8, MA_9, MA_EQL, MA_ASTR, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_A, MA_S, MA_D, MA_F, MA_G, MA_DOT, MA_4, MA_5, MA_6, MA_MINS, MA_PLUS, MA_ENT,
        KC_TRNS, MA_Z, MA_X, MA_C, MA_V, KC_TRNS, MA_0, MA_1, MA_2, MA_3, MA_SLSH, KC_TRNS, KC_TRNS,
        MA_CAPSLOCK, KC_TRNS, MA_SPC, KC_TRNS, KC_TRNS
    ),
    [LA_RTHUMB] = LAYOUT(
        KC_TRNS, FR_EURO, MA_TILD, FR_HASH, MA_BACKTICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_LBRC, FR_RBRC, FR_LCBR, FR_RCBR, FR_AT, FR_MICR, KC_TRNS, KC_PSCR, KC_SCRL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_LABK, FR_RABK, FR_LPRN, FR_RPRN, FR_PIPE, FR_SECT, KC_PSLS, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_DEG, FR_SUP2, FR_DLR, FR_PERC, FR_PND, KC_PPLS, KC_PMNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB] = LAYOUT(
        MA_LMOUSE, MA_LTHUMB1, MA_LTHUMB2, MA_LTHUMB3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        MA_TAB, MA_LTHUMBQ, MA_LTHUMBW, MA_LTHUMBE, G(KC_E), KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, MA_DOUBLEARROW, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, MA_ESC, KC_LGUI, MA_LTHUMBD, G(KC_D), KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, MA_SIMPLEARROW, KC_TRNS, KC_PENT,
        KC_TRNS, C(KC_A), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBEMO] = LAYOUT(
        LSG(KC_ESC), C(KC_Q), MA_SELLINE, LSG(KC_3), LSG(KC_4), LSG(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        LSG(KC_TAB), C(KC_V), C(KC_X), C(KC_C), LSG(KC_R), LSG(KC_T), LSG(KC_Y), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, C(KC_F), C(KC_R), KC_TRNS, LSG(KC_F), LSG(KC_G), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LSG(KC_Z), LSG(KC_X), LSG(KC_C), LSG(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBDMO] = LAYOUT(
        RSG(KC_ESC), C(KC_W), S(C(KC_W)), KC_UP, RSG(KC_4), RSG(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        C(KC_Z), KC_BSPC, KC_DEL, KC_TRNS, RSG(KC_R), RSG(KC_T), RSG(KC_Y), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_DELLINE, KC_ENT, C(KC_S), KC_SPC, RSG(KC_G), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RSG(KC_Z), MA_JUMPDETAB, MA_JUMPTAB, RSG(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBEOSL] = LAYOUT(
        LAG(KC_ESC), LAG(KC_1), LAG(KC_2), LAG(KC_3), LAG(KC_4), LAG(KC_5), LAG(KC_6), LAG(KC_7), LAG(KC_8), LAG(KC_9), LAG(KC_0), LAG(KC_MINS), LAG(KC_EQL), LAG(KC_BSLS), KC_TRNS,
        LAG(KC_TAB), LAG(KC_Q), LAG(KC_W), LAG(KC_E), LAG(KC_R), LAG(KC_T), LAG(KC_Y), LAG(KC_U), LAG(KC_I), LAG(KC_O), LAG(KC_P), LAG(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LAG(KC_A), LAG(KC_S), LAG(KC_D), LAG(KC_F), LAG(KC_G), LAG(KC_H), LAG(KC_J), LAG(KC_K), LAG(KC_L), LAG(KC_SCLN), LAG(KC_QUOT), LAG(KC_ENT),
        KC_TRNS, LAG(KC_Z), LAG(KC_X), LAG(KC_C), LAG(KC_V), LAG(KC_B), LAG(KC_N), LAG(KC_M), LAG(KC_COMM), LAG(KC_DOT), LAG(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBDOSL] = LAYOUT(
        LSA(KC_ESC), LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5), LSA(KC_6), LSA(KC_7), LSA(KC_8), LSA(KC_9), LSA(KC_0), LSA(KC_MINS), LSA(KC_EQL), LSA(KC_BSLS), KC_TRNS,
        LSA(KC_TAB), LSA(KC_Q), LSA(KC_W), LSA(KC_E), LSA(KC_R), LSA(KC_T), LSA(KC_Y), LSA(KC_U), LSA(KC_I), LSA(KC_O), LSA(KC_P), LSA(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LSA(KC_A), LSA(KC_S), LSA(KC_D), LSA(KC_F), LSA(KC_G), LSA(KC_H), LSA(KC_J), LSA(KC_K), LSA(KC_L), LSA(KC_SCLN), LSA(KC_QUOT), LSA(KC_ENT),
        KC_TRNS, LSA(KC_Z), LSA(KC_X), LSA(KC_C), LSA(KC_V), LSA(KC_B), LSA(KC_N), LSA(KC_M), LSA(KC_COMM), LSA(KC_DOT), LSA(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB1MO] = LAYOUT(
        LALT(KC_ESC), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), LALT(KC_MINS), LALT(KC_EQL), LALT(KC_BSLS), KC_TRNS,
        LALT(KC_TAB), LALT(KC_Q), LALT(KC_W), LALT(KC_E), LALT(KC_R), LALT(KC_T), LALT(KC_Y), LALT(KC_U), LALT(KC_I), LALT(KC_O), LALT(KC_P), LALT(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LALT(KC_A), LALT(KC_S), LALT(KC_D), LALT(KC_F), LALT(KC_G), LALT(KC_H), LALT(KC_J), LALT(KC_K), LALT(KC_L), LALT(KC_SCLN), LALT(KC_QUOT), LALT(KC_ENT),
        KC_TRNS, LALT(KC_Z), LALT(KC_X), LALT(KC_C), LALT(KC_V), LALT(KC_B), LALT(KC_N), LALT(KC_M), LALT(KC_COMM), LALT(KC_DOT), LALT(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, LALT(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB2MO] = LAYOUT(
        RCS(KC_ESC), RCS(KC_1), RCS(KC_2), RCS(KC_3), RCS(KC_4), RCS(KC_5), RCS(KC_6), RCS(KC_7), RCS(KC_8), RCS(KC_9), RCS(KC_0), RCS(KC_MINS), RCS(KC_EQL), RCS(KC_BSLS), KC_TRNS,
        RCS(KC_TAB), RCS(KC_Q), RCS(KC_W), RCS(KC_E), RCS(KC_R), RCS(KC_T), RCS(KC_Y), RCS(KC_U), RCS(KC_I), RCS(KC_O), RCS(KC_P), RCS(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, RCS(KC_A), RCS(KC_S), RCS(KC_D), RCS(KC_F), RCS(KC_G), RCS(KC_H), RCS(KC_J), RCS(KC_K), RCS(KC_L), RCS(KC_SCLN), RCS(KC_QUOT), RCS(KC_ENT),
        KC_TRNS, RCS(KC_Z), RCS(KC_X), RCS(KC_C), RCS(KC_V), RCS(KC_B), RCS(KC_N), RCS(KC_M), RCS(KC_COMM), RCS(KC_DOT), RCS(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RCS(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB3MO] = LAYOUT(
        C(G(KC_ESC)), C(G(KC_1)), C(G(KC_2)), C(G(KC_3)), C(G(KC_4)), C(G(KC_5)), C(G(KC_6)), C(G(KC_7)), C(G(KC_8)), C(G(KC_9)), C(G(KC_0)), C(G(KC_MINS)), C(G(KC_EQL)), C(G(KC_BSLS)), KC_TRNS,
        C(G(KC_TAB)), C(G(KC_Q)), C(G(KC_W)), C(G(KC_E)), C(G(KC_R)), C(G(KC_T)), C(G(KC_Y)), C(G(KC_U)), C(G(KC_I)), C(G(KC_O)), C(G(KC_P)), C(G(KC_LBRC)), KC_TRNS, KC_TRNS,
        KC_TRNS, C(G(KC_A)), C(G(KC_S)), C(G(KC_D)), C(G(KC_F)), C(G(KC_G)), C(G(KC_H)), C(G(KC_J)), C(G(KC_K)), C(G(KC_L)), C(G(KC_SCLN)), C(G(KC_QUOT)), C(G(KC_ENT)),
        KC_TRNS, C(G(KC_Z)), C(G(KC_X)), C(G(KC_C)), C(G(KC_V)), C(G(KC_B)), C(G(KC_N)), C(G(KC_M)), C(G(KC_COMM)), C(G(KC_DOT)), C(G(KC_SLSH)), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, C(G(KC_SPC)), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBQ] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MA_DELX2, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, MA_UPX2, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ESC, MA_UPX2, MA_ENTX2, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFTX2, MA_DOWNX2, MA_RIGHTX2, KC_TRNS, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCTL, MA_BSPCX2, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBW] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MA_DELX4, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, MA_UPX4, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ESC, MA_UPX4, MA_ENTX4, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFTX4, MA_DOWNX4, MA_RIGHTX4, KC_TRNS, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCTL, MA_BSPCX4, KC_TRNS, KC_TRNS
    ),
};
