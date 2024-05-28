/*
Copyright 2023 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
ERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "capsword.h"
#include "keymap.h"
#include "tapdance.h"
#include "transactions.h"
#include "rgb_matrix_user.h"
#include "quantum.h"
#include "qp.h"

#ifdef QUANTUM_PAINTER_ENABLE

#include "images/nvlogo_small.qgf.c"

static painter_device_t display;
static painter_image_handle_t image;

// st7789 enable, comment out the following line if not using a st7789
painter_device_t qp_st7789_make_spi_device(uint16_t panel_width, uint16_t panel_height, pin_t chip_select_pin, pin_t dc_pin, pin_t reset_pin, uint16_t spi_divisor, int spi_mode);
// gc9a01 enable, comment out the following line if not using a gc9a01
// painter_device_t qp_gc9a01_make_spi_device(uint16_t panel_width, uint16_t panel_height, pin_t chip_select_pin, pin_t dc_pin, pin_t reset_pin, uint16_t spi_divisor, int spi_mode);

// Defined in keymap to avoid redefinition errors
uint32_t deferred_init(uint32_t trigger_time, void *cb_arg) {

    print("doing stuff\n");

// ##st7789 screen support, comment out down to "##end st7789 screen support" if not using a st7789 screen
    display = qp_st7789_make_spi_device(320, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 3);
    if (is_keyboard_left()) {
        qp_power(display, true);
        }
    if (is_keyboard_left()) {
        qp_init(display, QP_ROTATION_270);
        }
// If using pointing device on right side, comment out following 3 lines, if using dual screens, uncomment.
        else {
        qp_init(display, QP_ROTATION_90);
        }
    if (is_keyboard_left()) {
        image = qp_load_image_mem(gfx_nvlogo_small);
    }
// If using pointing device on right side, comment out following 3 lines, if using dual screens, uncomment
    else {
        image = qp_load_image_mem(gfx_nvlogo_small);
    }
    // ##end st7789 screen support

// ##gc9a01 screeen support, comment out down to "##end GC9A01 screen support" if not using a gc9a01 screen
    // display = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    // qp_power(display, true);
    // if (is_keyboard_left()) {
    //     qp_init(display, QP_ROTATION_0);
    //     }
    // If using pointing device on right side, comment out following 3 lines, if using dual screens, uncomment.
    //     else {
    //     qp_init(display, QP_ROTATION_0);
    //     }

    //     if (is_keyboard_left()) {
    //     image = qp_load_image_mem(gfx_ZodiarkPiLogoGC);
    //      }
    // If using pointing device on right side, comment out following 3 lines, if using dual screens, uncomment.
    //     else {
    //     image = qp_load_image_mem(gfx_ZodiarkPiLogoGC);
    // }
    // ##end GC9A01 screeen support

    if (image != NULL) {
        print("image was not null\n");
        if (is_keyboard_left()) {
            qp_drawimage(display, 0, 0, image);
        }
    // If using pointing device on right side, comment out following 3 lines, if using dual screens, uncomment.
        else {
            qp_drawimage(display, 0, 0, image);
        }
    }


    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable=true;
    defer_exec(3000, deferred_init, NULL);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬─────┬──────┬──────┬─────────────────┬───┐                                                                    ┌───┬─────────────────┬─────┬─────┬─────────────┬─────┐
//    │      `      │  1  │  2   │  3   │        4        │ 5 │                                                                    │ 6 │        7        │  8  │  9  │      0      │  =  │
//    ├─────────────┼─────┼──────┼──────┼─────────────────┼───┤                                                                    ├───┼─────────────────┼─────┼─────┼─────────────┼─────┤
//    │ TD(AUTOTAB) │  q  │  w   │  e   │        r        │ t │                                                                    │ y │        u        │  i  │  o  │      p      │  -  │
//    ├─────────────┼─────┼──────┼──────┼─────────────────┼───┼─────────────────┬───────────────┬────────────────────┬─────────────┼───┼─────────────────┼─────┼─────┼─────────────┼─────┤
//    │   CTL_ESC   │  a  │  s   │  d   │        f        │ g │ LCTL(LSFT(tab)) │    RGB_TOG    │ TD(PLAYPAUSE_MUTE) │  LCTL(tab)  │ h │        j        │  k  │  l  │      ;      │  '  │
//    ├─────────────┼─────┼──────┼──────┼─────────────────┼───┼─────────────────┼───────────────┼────────────────────┼─────────────┼───┼─────────────────┼─────┼─────┼─────────────┼─────┤
//    │    lsft     │  z  │  x   │  c   │        v        │ b │   OSL(NUMPAD)   │   CLOSE_TAB   │     REOPEN_TAB     │ OSL(SYMBOL) │ n │        m        │  ,  │  .  │      /      │  \  │
//    ├─────────────┼─────┼──────┼──────┼─────────────────┼───┼─────────────────┼───────────────┼────────────────────┼─────────────┼───┼─────────────────┼─────┼─────┼─────────────┼─────┤
//    │             │     │ lgui │ lalt │ TD(TMUX_SCROLL) │   │       ent       │ OSM(MOD_LSFT) │        bspc        │     spc     │   │ TD(TMUX_SCROLL) │     │     │ OSL(WINDOW) │     │
//    └─────────────┴─────┴──────┴──────┴─────────────────┘   └─────────────────┴───────────────┴────────────────────┴─────────────┘   └─────────────────┴─────┴─────┴─────────────┴─────┘
[_QWERTY] = LAYOUT(
  KC_GRV      , KC_1    , KC_2    , KC_3    , KC_4            , KC_5 ,                                                                          KC_6 , KC_7            , KC_8    , KC_9    , KC_0        , KC_EQUAL    ,
  TD(AUTOTAB) , KC_Q    , KC_W    , KC_E    , KC_R            , KC_T ,                                                                          KC_Y , KC_U            , KC_I    , KC_O    , KC_P        , KC_MINUS    ,
  CTL_ESC     , KC_A    , KC_S    , KC_D    , KC_F            , KC_G , LCTL(LSFT(KC_TAB)) , RGB_TOG       , TD(PLAYPAUSE_MUTE) , LCTL(KC_TAB) , KC_H , KC_J            , KC_K    , KC_L    , KC_SCLN     , KC_QUOTE    ,
  KC_LSFT     , KC_Z    , KC_X    , KC_C    , KC_V            , KC_B , OSL(NUMPAD)        , CLOSE_TAB     , REOPEN_TAB         , OSL(SYMBOL)  , KC_N , KC_M            , KC_COMM , KC_DOT  , KC_SLSH     , KC_BACKSLASH,
  _______     , _______ , KC_LGUI , KC_LALT , TD(TMUX_SCROLL) ,        KC_ENT             , OSM(MOD_LSFT) , KC_BSPC            , KC_SPC       ,        TD(TMUX_SCROLL) , _______ , _______ , OSL(WINDOW) , _______
),

//    ┌─────┬─────┬─────┬────────────┬─────────────┬─────┐                         ┌─────┬────┬────┬─────┬─────┬─────┐
//    │     │ f1  │ f2  │     f3     │     f4      │ f5  │                         │ f6  │ f7 │ f8 │ f9  │ f10 │     │
//    ├─────┼─────┼─────┼────────────┼─────────────┼─────┤                         ├─────┼────┼────┼─────┼─────┼─────┤
//    │     │     │     │            │             │ nUM │                         │     │ 7  │ 8  │  9  │     │  -  │
//    ├─────┼─────┼─────┼────────────┼─────────────┼─────┼───────┬─────┬─────┬─────┼─────┼────┼────┼─────┼─────┼─────┤
//    │     │     │     │            │             │     │  f11  │     │     │ f12 │     │ 4  │ 5  │  6  │  *  │  +  │
//    ├─────┼─────┼─────┼────────────┼─────────────┼─────┼───────┼─────┼─────┼─────┼─────┼────┼────┼─────┼─────┼─────┤
//    │     │     │     │ LINUX_COPY │ LINUX_PASTE │     │ TO(0) │     │     │     │     │ 1  │ 2  │  3  │  /  │ ent │
//    ├─────┼─────┼─────┼────────────┼─────────────┼─────┼───────┼─────┼─────┼─────┼─────┼────┼────┼─────┼─────┼─────┤
//    │     │     │     │            │             │     │       │     │     │     │     │ 0  │ .  │     │     │     │
//    └─────┴─────┴─────┴────────────┴─────────────┘     └───────┴─────┴─────┴─────┘     └────┴────┴─────┴─────┴─────┘
[_NUMPAD] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3      , KC_F4       , KC_F5   ,                                         KC_F6   , KC_F7 , KC_F8  , KC_F9   , KC_F10      , _______ ,
  _______ , _______ , _______ , _______    , _______     , KC_NUM  ,                                         _______ , KC_7  , KC_8   , KC_9    , _______     , KC_MINUS,
  _______ , _______ , _______ , _______    , _______     , _______ , KC_F11  , _______ , _______ , KC_F12  , _______ , KC_4  , KC_5   , KC_6    , KC_ASTERISK , KC_PLUS ,
  _______ , _______ , _______ , LINUX_COPY , LINUX_PASTE , _______ , TO(0)   , _______ , _______ , _______ , _______ , KC_1  , KC_2   , KC_3    , KC_SLASH    , KC_ENTER,
  _______ , _______ , _______ , _______    , _______     ,           _______ , _______ , _______ , _______ ,           KC_0  , KC_DOT , _______ , _______     , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬────┐                             ┌──────┬──────┬─────┬──────┬─────┬─────┐
//    │     │ f1  │ f2  │ f3  │ f4  │ f5 │                             │  f6  │  f7  │ f8  │  f9  │ f10 │     │
//    ├─────┼─────┼─────┼─────┼─────┼────┤                             ├──────┼──────┼─────┼──────┼─────┼─────┤
//    │     │  0  │  {  │  }  │  @  │ *  │                             │  !   │  :   │  (  │  )   │  ;  │     │
//    ├─────┼─────┼─────┼─────┼─────┼────┼─────┬─────────┬─────┬───────┼──────┼──────┼─────┼──────┼─────┼─────┤
//    │     │  ^  │  =  │  #  │  $  │ _  │ f11 │ LCTL(0) │     │  f12  │ left │ down │ up  │ rght │  ~  │     │
//    ├─────┼─────┼─────┼─────┼─────┼────┼─────┼─────────┼─────┼───────┼──────┼──────┼─────┼──────┼─────┼─────┤
//    │     │  -  │  <  │  >  │  %  │ |  │     │         │     │ TO(0) │  &   │  +   │  [  │  ]   │  \  │     │
//    ├─────┼─────┼─────┼─────┼─────┼────┼─────┼─────────┼─────┼───────┼──────┼──────┼─────┼──────┼─────┼─────┤
//    │     │     │     │     │     │    │     │         │     │       │      │      │     │      │     │     │
//    └─────┴─────┴─────┴─────┴─────┘    └─────┴─────────┴─────┴───────┘      └──────┴─────┴──────┴─────┴─────┘
[_SYMBOL] = LAYOUT(
  _______ , KC_F1         , KC_F2    , KC_F3   , KC_F4      , KC_F5         ,                                            KC_F6      , KC_F7    , KC_F8         , KC_F9          , KC_F10       , _______,
  _______ , KC_0          , KC_LCBR  , KC_RCBR , KC_AT      , KC_ASTR       ,                                            KC_EXCLAIM , KC_COLON , KC_LEFT_PAREN , KC_RIGHT_PAREN , KC_SCLN      , _______,
  _______ , KC_CIRCUMFLEX , KC_EQUAL , KC_HASH , KC_DLR     , KC_UNDERSCORE , KC_F11  , LCTL(KC_0) , _______ , KC_F12  , KC_LEFT    , KC_DOWN  , KC_UP         , KC_RIGHT       , KC_TILDE     , _______,
  _______ , KC_MINUS      , KC_LT    , KC_GT   , KC_PERCENT , KC_PIPE       , _______ , _______    , _______ , TO(0)   , KC_AMPR    , KC_PLUS  , KC_LBRC       , KC_RBRC        , KC_BACKSLASH , _______,
  _______ , _______       , _______  , _______ , _______    ,                 _______ , _______    , _______ , _______ ,              _______  , _______       , _______        , _______      , _______
),

//    ┌─────┬─────┬──────────────────┬──────────────────┬──────────────────────┬──────────────────┐                       ┌────────────────────┬────────────────────┬─────────────────┬─────────────────┬───────┬────────────┐
//    │     │     │                  │                  │                      │                  │                       │                    │                    │                 │                 │       │            │
//    ├─────┼─────┼──────────────────┼──────────────────┼──────────────────────┼──────────────────┤                       ├────────────────────┼────────────────────┼─────────────────┼─────────────────┼───────┼────────────┤
//    │     │     │ WMGMT_FULLSCREEN │                  │ WMGMT_NEXT_WALLPAPER │   WMGMT_TOP_33   │                       │  WMGMT_MONITOR_1   │  WMGMT_MONITOR_2   │ WMGMT_MONITOR_3 │ WMGMT_MONITOR_4 │       │            │
//    ├─────┼─────┼──────────────────┼──────────────────┼──────────────────────┼──────────────────┼─────┬─────┬─────┬─────┼────────────────────┼────────────────────┼─────────────────┼─────────────────┼───────┼────────────┤
//    │     │     │  WMGMT_LEFT_33   │ WMGMT_HCENTER_33 │    WMGMT_RIGHT_33    │ WMGMT_VCENTER_33 │     │     │     │     │   WMGMT_LEFT_50    │   WMGMT_DOWN_50    │   WMGMT_UP_50   │ WMGMT_RIGHT_50  │       │            │
//    ├─────┼─────┼──────────────────┼──────────────────┼──────────────────────┼──────────────────┼─────┼─────┼─────┼─────┼────────────────────┼────────────────────┼─────────────────┼─────────────────┼───────┼────────────┤
//    │     │     │  WMGMT_LEFT_66   │   WMGMT_CENTER   │    WMGMT_RIGHT_66    │ WMGMT_BOTTOM_33  │     │     │     │     │ WMGMT_PREV_MONITOR │ WMGMT_NEXT_MONITOR │                 │                 │       │            │
//    ├─────┼─────┼──────────────────┼──────────────────┼──────────────────────┼──────────────────┼─────┼─────┼─────┼─────┼────────────────────┼────────────────────┼─────────────────┼─────────────────┼───────┼────────────┤
//    │     │     │                  │                  │                      │                  │     │     │     │     │                    │                    │                 │                 │ TO(0) │ WMGMT_BASE │
//    └─────┴─────┴──────────────────┴──────────────────┴──────────────────────┘                  └─────┴─────┴─────┴─────┘                    └────────────────────┴─────────────────┴─────────────────┴───────┴────────────┘
[_WINDOW] = LAYOUT(
  _______ , _______ , _______          , _______          , _______              , _______          ,                                         _______            , _______            , _______         , _______         , _______ , _______   ,
  _______ , _______ , WMGMT_FULLSCREEN , _______          , WMGMT_NEXT_WALLPAPER , WMGMT_TOP_33     ,                                         WMGMT_MONITOR_1    , WMGMT_MONITOR_2    , WMGMT_MONITOR_3 , WMGMT_MONITOR_4 , _______ , _______   ,
  _______ , _______ , WMGMT_LEFT_33    , WMGMT_HCENTER_33 , WMGMT_RIGHT_33       , WMGMT_VCENTER_33 , _______ , _______ , _______ , _______ , WMGMT_LEFT_50      , WMGMT_DOWN_50      , WMGMT_UP_50     , WMGMT_RIGHT_50  , _______ , _______   ,
  _______ , _______ , WMGMT_LEFT_66    , WMGMT_CENTER     , WMGMT_RIGHT_66       , WMGMT_BOTTOM_33  , _______ , _______ , _______ , _______ , WMGMT_PREV_MONITOR , WMGMT_NEXT_MONITOR , _______         , _______         , _______ , _______   ,
  _______ , _______ , _______          , _______          , _______              ,                    _______ , _______ , _______ , _______ ,                      _______            , _______         , _______         , TO(0)   , WMGMT_BASE
),

//    ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────────────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │         │         │         │         │         │                  │                       │     │     │     │     │     │     │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ DB_TOGG │         │         │         │         │     RGB_TOG      │                       │     │     │     │     │     │     │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┼─────┬─────┬─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │ RGB_SPI │ RGB_HUI │ RGB_SAI │ RGB_VAI │ RGB_MODE_FORWARD │     │     │     │     │     │     │     │     │     │     │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │ RGB_SPD │ RGB_HUD │ RGB_SAD │ RGB_VAD │ RGB_MODE_REVERSE │     │     │     │     │     │     │     │     │     │     │
//    ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────────────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │         │         │         │         │         │                  │     │     │     │     │     │     │     │     │     │     │
//    └─────────┴─────────┴─────────┴─────────┴─────────┘                  └─────┴─────┴─────┴─────┘     └─────┴─────┴─────┴─────┴─────┘
[_MAGIC] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______          ,                                         _______ , _______ , _______ , _______ , _______ , _______,
  DB_TOGG , _______ , _______ , _______ , _______ , RGB_TOG          ,                                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , RGB_SPI , RGB_HUI , RGB_SAI , RGB_VAI , RGB_MODE_FORWARD , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , RGB_SPD , RGB_HUD , RGB_SAD , RGB_VAD , RGB_MODE_REVERSE , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ ,                    _______ , _______ , _______ , _______ ,           _______ , _______ , _______ , _______ , _______
)
};

const uint16_t PROGMEM COMBO_UP_DIR[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM COMBO_BRACES_PAIR[] = {KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM COMBO_BRACKETS_PAIR[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM COMBO_PARENS_PAIR[] = {KC_LEFT_PAREN, KC_RIGHT_PAREN, COMBO_END};
const uint16_t PROGMEM COMBO_LT_GT_PAIR[] = {KC_LT, KC_GT, COMBO_END};
const uint16_t PROGMEM COMBO_HELM_FUNC[] = {KC_H, KC_L, KC_F, COMBO_END};
const uint16_t PROGMEM COMBO_HELM_SINGLE_LINE_COMMENT[] = {KC_H, KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM COMBO_HELM_MULTI_LINE_COMMENT[] = {KC_H, KC_L, KC_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(COMBO_UP_DIR, MACRO_UP_DIR),
    COMBO(COMBO_BRACES_PAIR, MACRO_BRACES_PAIR),
    COMBO(COMBO_BRACKETS_PAIR, MACRO_BRACKETS_PAIR),
    COMBO(COMBO_PARENS_PAIR, MACRO_PARENS_PAIR),
    COMBO(COMBO_LT_GT_PAIR, MACRO_LT_GT_PAIR),
    COMBO(COMBO_HELM_FUNC, MACRO_HELM_FUNC),
    COMBO(COMBO_HELM_SINGLE_LINE_COMMENT, MACRO_HELM_SINGLE_LINE_COMMENT),
    COMBO(COMBO_HELM_MULTI_LINE_COMMENT, MACRO_HELM_MULTI_LINE_COMMENT),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    #ifdef CONSOLE_ENABLE
        uprintf("keycode: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif

    switch (keycode) {
        // tap-hold macros
        // case TD(PLAYPAUSE_MUTE):
        case TD(AUTOTAB):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        case MACRO_UP_DIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            break;
        case MACRO_BRACES_PAIR:
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            break;
        case MACRO_BRACKETS_PAIR:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            break;
        case MACRO_PARENS_PAIR:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            break;
        case MACRO_LT_GT_PAIR:
            if (record->event.pressed) {
                SEND_STRING("<>" SS_TAP(X_LEFT));
            }
            break;
        case MACRO_HELM_FUNC:
            if (record->event.pressed) {
                    SEND_STRING("{{-  -}}" \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                    );
            }
            break;
        case MACRO_HELM_SINGLE_LINE_COMMENT:
            if (record->event.pressed) {
                    SEND_STRING("{{/*  */}}" \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                        SS_TAP(X_LEFT) \
                    );
            }
            break;
        case MACRO_HELM_MULTI_LINE_COMMENT:
            if (record->event.pressed) {
                    SEND_STRING("{{- /*" \
                        SS_TAP(X_ENT) \
                        SS_TAP(X_ENT) \
                    );
                    SEND_STRING("*/ -}}" \
                        SS_TAP(X_UP) \
                    );
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;

    display = qp_st7789_make_spi_device(320, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 3);
    qp_init(display, QP_ROTATION_0);
    transaction_register_rpc(RPC_CAPSWORD_SYNC, capsword_sync_handler);
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        bool needs_sync = false;
        static uint16_t last_sync = false;
        static bool last_state = false;

        if (memcmp(&is_capsword_enabled, &last_state, sizeof(last_state))) {
            needs_sync = true;
            memcpy(&last_state, &is_capsword_enabled, sizeof(last_state));
        }

        if (timer_elapsed32(last_sync) > 250) {
            needs_sync = true;
        }

        if (needs_sync) {
            if (transaction_rpc_send(RPC_CAPSWORD_SYNC, sizeof(is_capsword_enabled), &is_capsword_enabled)) {
                last_sync = timer_read32();
            }
        }
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

// update the array size in tapdance.h when adding to or removing from this
tap_dance_action_t tap_dance_actions[] = {
    [TMUX_SCROLL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tmux_finished, tmux_reset),
    [WIN_TAPDANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_finished, win_reset),
    [ALT_TAPDANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
    [AUTOTAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, LALT(LCTL(KC_TAB))),
    [PLAYPAUSE_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, encoder_finished, encoder_reset),
    // [PLAYPAUSE_MUTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MEDIA_PLAY_PAUSE),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL, _WINDOW, _MAGIC);
    switch (get_highest_layer(state)) {
        case _WINDOW:
            if (is_keyboard_left()) {
                qp_power(display, false);
            } else {
                qp_power(display, false);
            };
            break;
        default:
            if (is_keyboard_left()) {
                qp_power(display, true);
            } else {
                qp_power(display, true);
            };
            break;
    }
    return state;
};

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if(IS_LAYER_ON(_SYMBOL)) {
            if (clockwise) {
                tap_code16(LCTL(KC_MINUS));
            } else {
                tap_code16(LCTL(KC_PLUS));
            }
        } else {
            if (clockwise) {
                tap_code(KC_MS_WH_DOWN);
            } else {
                tap_code(KC_MS_WH_UP);
            }
        }

    // } else if (index == 1) { /* Second encoder */
    //     if (clockwise) {
    //         tap_code(KC_MS_WH_DOWN);
    //     } else {
    //         tap_code(KC_MS_WH_UP);
    //     }
    } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 2);
        } else {
            tap_code_delay(KC_VOLD, 2);
        }
    }
    // } else if (index == 3) { /* Fourth encoder */
    //     if (clockwise) {
    //         tap_code(KC_MS_WH_DOWN);
    //     } else {
    //         tap_code(KC_MS_WH_UP);
    //     }
    // } else if (index == 4) { /* Fifth encoder */
    //     if (clockwise) {
    //         tap_code(KC_MS_WH_DOWN);
    //     } else {
    //         tap_code(KC_MS_WH_UP);
    //     }
    // }
    return true;
}

#endif
