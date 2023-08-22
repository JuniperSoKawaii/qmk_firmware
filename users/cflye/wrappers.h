#pragma once

#include "cflye.h"

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define ___________________BLANK___________________     _______,           _______,           _______,           _______,           _______
#define ________________CLIPBOARD_L________________     U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO
#define ________________CLIPBOARD_R________________     U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND

#define _________________COLEMAK_L1_________________    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B
#define _________________COLEMAK_L2_________________    HOME_A,            HOME_R,            HOME_S,            HOME_T,            KC_G
#define _______________COLEMAK_L2_NO_HOME___________    KC_A,              KC_R,              KC_S,              KC_T,              KC_G
#define _________________COLEMAK_L3_________________    KC_Z,              KC_X,              KC_C,              KC_D,              KC_V

#define _________________COLEMAK_R1_________________    KC_J,              KC_L,              KC_U,              KC_Y,              KC_SCLN
#define _________________COLEMAK_R2_________________    KC_M,              HOME_N,            HOME_E,            HOME_I,            HOME_O
#define _______________COLEMAK_R2_NO_HOME___________    KC_M,              KC_N,              KC_E,              KC_I,              KC_O
#define _________________COLEMAK_R3_________________    KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLASH

#define _________________QWERTY_L1__________________    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T
#define _________________QWERTY_L2__________________    HOME_A,            HOME_QS,           HOME_D,            HOME_F,            KC_G
#define _________________QWERTY_L2_NO_HOME__________    KC_A,              KC_S,              KC_D,              KC_F,              KC_G
#define _________________QWERTY_L3__________________    KC_Z,              KC_X,              KC_C,              KC_V,              KC_B

#define _________________QWERTY_R1__________________    KC_Y,              KC_U,              KC_I,              KC_O,              KC_P
#define _________________QWERTY_R2__________________    KC_H,              HOME_J,            HOME_K,            HOME_L,            HOME_SCLN
#define _________________QWERTY_R2_NO_HOME__________    KC_H,              KC_J,              KC_K,              KC_L,              KC_SCLN
#define _________________QWERTY_R3__________________    KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLASH

#define _________________GAMING_L1__________________    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B
#define _________________GAMING_L2__________________    KC_A,              KC_R,              KC_S,              KC_T,              KC_G
#define _________________GAMING_L3__________________    KC_Z,              KC_X,              KC_C,              KC_D,              KC_V

#define _________________GAMING_R1__________________    KC_J,              KC_L,              KC_U,              KC_Y,              KC_SCLN
#define _________________GAMING_R2__________________    KC_M,              KC_N,              KC_E,              KC_I,              KC_O
#define _________________GAMING_R3__________________    KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLASH

#define ___________________SYM_L1___________________    KC_QUOT,           KC_LABK,           KC_RABK,           KC_DQUO,           KC_GRV
#define ___________________SYM_L2___________________    KC_EXLM,           KC_MINS,           KC_PLUS,           KC_EQL,            KC_HASH
#define ___________________SYM_L3___________________    KC_CIRC,           KC_SLSH,           KC_ASTR,           KC_BSLS,           _______

#define ___________________SYM_R1___________________    KC_AMPR,           KC_LBRC,           KC_RBRC,           KC_PERC,           KC_COLN
#define ___________________SYM_R2___________________    KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_DLR
#define ___________________SYM_R3___________________    KC_TILD,           KC_LCBR,           KC_RCBR,           KC_QUES,           KC_AT

#define ___________________SYM_LM2__________________    KC_EXLM,           KC_MINS,           KC_PLUS,           KC_EQL,            KC_HASH
#define ___________________SYM_RM2__________________    KC_PIPE,           KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_QUES

#define ___________________NUM_L1___________________    KC_SLSH,           KC_7,              KC_8,              KC_9,              KC_ASTR
#define ___________________NUM_L2___________________    KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_MINS
#define ___________________NUM_L3___________________    KC_0,              KC_1,              KC_2,              KC_3,              KC_PLUS
#define ___________________NUM_L4___________________    _______,           _______,           _______,           _______,           _______

#define ___________________NUM_R1___________________    KC_NO,             TD(TD_BASE),       TD(TD_GAMING),     TD(TD_EECLEAR),    TD(TD_BOOT)
#define ___________________NUM_R2___________________    KC_NO,             KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI
#define ___________________NUM_R3___________________    KC_NO,             KC_AE,             KC_OE,             KC_AA,             XXXXXXX
#define ___________________NUM_R4___________________    _______,           _______,           _______,           _______,           _______

#define ___________________FUN_L1___________________    KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR
#define ___________________FUN_L2___________________    KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL
#define ___________________FUN_L3___________________    KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS
#define ___________________FUN_L4___________________    _______,           _______,           _______,           _______,           _______
// TODO: kc_app 

#define ___________________FUN_R1___________________    TD(TD_QWERTY),     TD(TD_BASE),       TD(TD_GAMING),     TD(TD_EECLEAR),    TD(TD_BOOT)
#define ___________________FUN_R2___________________    XXXXXXX,           KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI
#define ___________________FUN_R3___________________    SHRUG,             _______,           _______,           _______,           _______
#define ___________________FUN_R4___________________    _______,           _______,           _______,           _______,           _______

#define __________________MEDIA_L1__________________    TD(TD_BOOT),       TD(TD_EECLEAR),    TD(TD_GAMING),     TD(TD_BASE),       XXXXXXX
#define __________________MEDIA_L2__________________    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA
#define __________________MEDIA_L3__________________    _______,           _______,           _______,           _______,           _______
#define __________________MEDIA_L4__________________    _______,           _______,           _______,           _______,           _______

#define __________________MEDIA_R1__________________    RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI
#define __________________MEDIA_R2__________________    U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT
#define __________________MEDIA_R3__________________    OU_AUTO,           U_NU,              KC_MPLY,              U_NU,              U_NU
#define __________________MEDIA_R4__________________    KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP

#define ___________________NAV_L1___________________    ________________CLIPBOARD_L________________
#define ___________________NAV_L2___________________    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           XXXXXXX
#define ___________________NAV_L3___________________    _______,           _______,           _______,           _______,           _______
#define ___________________NAV_L4___________________    _______,           _______,           _______,           _______,           _______

#define ___________________NAV_R1___________________    ________________CLIPBOARD_R________________
#define ___________________NAV_R2___________________    CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT
#define ___________________NAV_R3___________________    KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END
#define ___________________NAV_R4___________________    _______,           _______,           _______,           _______,           _______


#define __________________MOUSE_L1__________________    TD(TD_BOOT),       XXXXXXX,           XXXXXXX,           XXXXXXX,        XXXXXXX
#define __________________MOUSE_L2__________________    KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA
#define __________________MOUSE_L3__________________    _______,           _______,           _______,           _______,           _______
#define __________________MOUSE_L4__________________    _______,           _______,           _______,           _______,           _______

#define __________________MOUSE_R1__________________    ________________CLIPBOARD_R________________
#define __________________MOUSE_R2__________________    U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R
#define __________________MOUSE_R3__________________    U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R
#define __________________MOUSE_R4__________________    KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________THUMB_LEFT________________     KC_NO,             KC_NO,             LT(_MEDIA,KC_ESC), LT(_NAV,KC_SPC),   LT(_MOUSE,KC_BSPC)
#define _________________THUMB_RIGHT_______________     LT(_FUN,KC_DEL),   LT(_SYM,KC_ENT),   LT(_NUM,KC_TAB),   KC_NO,             KC_NO


// VI Versions

#define ___________________NAV_VI_R2________________    KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG
#define ___________________NAV_VI_R3________________    KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_INS

#define __________________MEDIA_VI_R2_______________    KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU
#define __________________MEDIA_VI_R3_______________    U_NU,              KC_MPLY,           U_NU,              U_NU,              OU_AUTO

#define __________________MOUSE_VI_R2_______________    KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           U_NU
#define __________________MOUSE_VI_R3_______________    KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           U_NU