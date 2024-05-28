#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYMBOL   MO(_SYMBOL)
#define NUMPAD   MO(_NUMPAD)
#define MAGIC    MO(_MAGIC)
#define WINDOW   MO(_WINDOW)
#define SHIFT    MO(_SHIFT)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Tmux
#define TMUX_LEADER LCTL(KC_A)

// Tabs
#define CLOSE_TAB LCTL(KC_W)
#define REOPEN_TAB LCTL(LSFT(KC_T))

// General Linux
#define LINUX_COPY LCTL(LSFT(KC_C))
#define LINUX_PASTE LCTL(LSFT(KC_V))

// General Windows
#define TASK_MANAGER LCTL(LSFT(KC_ESC))
#define SOUNDSWITCH LALT(LSFT(LGUI(KC_DOT)))

// Window Management
#define WMGMT_BASE LSFT(LALT(LCTL(KC_0)))
#define WMGMT_MONITOR_1 LALT(LGUI(LCTL(KC_1)))
#define WMGMT_MONITOR_2 LALT(LGUI(LCTL(KC_2)))
#define WMGMT_MONITOR_3 LALT(LGUI(LCTL(KC_3)))
#define WMGMT_MONITOR_4 LALT(LGUI(LCTL(KC_4)))
#define WMGMT_LEFT_50 LSFT(LALT(LCTL(KC_H)))
#define WMGMT_DOWN_50 LSFT(LALT(LCTL(KC_J)))
#define WMGMT_UP_50 LSFT(LALT(LCTL(KC_K)))
#define WMGMT_RIGHT_50 LSFT(LALT(LCTL(KC_L)))
#define WMGMT_PREV_MONITOR LSFT(LALT(LCTL(KC_M)))
#define WMGMT_NEXT_MONITOR LSFT(LALT(LCTL(KC_N)))
#define WMGMT_TOPLEFT LSFT(LALT(LCTL(KC_P)))
#define WMGMT_TOPRIGHT LSFT(LALT(LCTL(KC_MINUS)))
#define WMGMT_BOTTOMLEFT LSFT(LALT(LCTL(KC_SCLN)))
#define WMGMT_BOTTOMRIGHT LSFT(LALT(LCTL(KC_QUOTE)))
#define WMGMT_FULLSCREEN LSFT(LALT(LCTL(KC_F)))
#define WMGMT_NEXT_WALLPAPER LSFT(LALT(LCTL(KC_R)))
#define WMGMT_LEFT_33 LSFT(LALT(LCTL(KC_1)))
#define WMGMT_HCENTER_33 LSFT(LALT(LCTL(KC_2)))
#define WMGMT_RIGHT_33 LSFT(LALT(LCTL(KC_3)))
#define WMGMT_TOP_33 LSFT(LALT(LCTL(KC_4)))
#define WMGMT_VCENTER_33 LSFT(LALT(LCTL(KC_5)))
#define WMGMT_BOTTOM_33 LSFT(LALT(LCTL(KC_6)))
#define WMGMT_LEFT_66 LSFT(LALT(LCTL(KC_7)))
#define WMGMT_RIGHT_66 LSFT(LALT(LCTL(KC_8)))
#define WMGMT_CENTER LALT(LGUI(LCTL(KC_C)))

enum tap_dance_codes {
    TMUX_SCROLL,
    WIN_TAPDANCE,
    ALT_TAPDANCE,
    AUTOTAB,
    PLAYPAUSE_MUTE,
};

enum macro_codes {
    MACRO_UP_DIR = SAFE_RANGE,
    MACRO_BRACES_PAIR,
    MACRO_BRACKETS_PAIR,
    MACRO_PARENS_PAIR,
    MACRO_LT_GT_PAIR,
    MACRO_HELM_FUNC,
    MACRO_HELM_SINGLE_LINE_COMMENT,
    MACRO_HELM_MULTI_LINE_COMMENT,
};
