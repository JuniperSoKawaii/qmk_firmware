#pragma once
/*
  Copyright 2018 Eric Gebhart <e.a.gebhart@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
#include "eeconfig.h"
#include "keymap_bepo.h"
#include "altlocal_keys.h"

//#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);

enum userspace_custom_keycodes {
  // keep the keycodes using the send_key function close to SAFE_RANGE
  // so the array of keycodes remains a reasonbale size.
  DB_1 = SAFE_RANGE,  // can always be here
  DB_2,
  DB_3,
  DB_4,
  DB_5,
  DB_6,
  DB_7,
  DB_8,
  DB_9,
  DB_0,
  DB_GRV,
  DB_SCOLON,
  DB_SLASH,
  DB_BACKSLASH,
  DB_EQL,
  DB_DOT,
  DB_COMM,
  DB_QUOT,
  DB_MINUS,
  DB_RPRN,
  DB_LPRN,
  DB_RBRC,
  DB_LBRC,
  // for symbols layer
  DB_HASH,
  DB_LCBR,
  DB_RCBR,
  DB_PIPE,
  DB_TILD,
  DB_CIRC,
  DB_LESS,
  DB_GRTR,
  // End of dvorak on bepo translation keys.
  // BEAKL on Qwerty..
  BQ_DOT,
  BQ_COMM,
  BQ_QUOT,
  // End of beakl on qwerty
  BB_DOT,
  BB_COMM,
  BB_QUOT,
  // End of beakl on Bepo

  EPRM,
  VRSN,
  // Default keyboard layouts - Same order as enum.
  KC_DVORAK,
  KC_QWERTY,
  KC_COLEMAK,
  KC_BEAKL,
  // KC_WORKMAN,
  // KC_NORMAN,
  // KC_MALTRON,
  // KC_EUCALYN,
  // KC_CARPLAX,
  KC_DVORAK_BP,
  KC_BEAKL_BP,
  KC_BEPO,
  KC_LAYERS,

  // Misc.
  KC_MAKE,
  KC_RESET,
  KC_RGB_T,
  RGB_IDL,
  KC_SECRET_1,
  KC_SECRET_2,
  KC_SECRET_3,
  KC_SECRET_4,
  KC_SECRET_5,
  KC_CCCV,      // Ctrl-C V in one key.
  BP_CCCV,
  KC_CTCN,      // Ctrl-T N in one key.
  BP_CTCN,
  KC_CWCQ,      // Ctrl-W Q in one key.
  BP_CWCQ,
  KC_XM_PORD,   // Xmonad gui-e, gui-t for the scratchpads or desktops.
  BP_XM_PORD,
  KC_OCPRN,   // Open, or open and close, cursor in the middle with hold.
  BP_OCPRN,
  KC_OCBRC,
  BP_OCBRC,
  KC_OCCBR,
  BP_OCCBR,
  KC_OCDQUO,
  BP_OCDQUO,
  KC_OCQUOT,
  BP_OCQUOT,
  KC_OCGRV,
  BP_OCGRV,
  KC_OCLTGT,
  BP_OCLTGT,
  UC_FLIP,
  UC_TABL,
  UC_SHRG,
  UC_DISA,
  KC_SPACETEST,
  NEW_SAFE_RANGE
};

<<<<<<< HEAD
#define CTLGUI_T(kc) { MT(MOD_LGUI | MOD_LCTL, kc) }
#define SFTGUI_T(kc) { MT(MOD_LGUI | MOD_LSFT, kc) }
#define ALTGUI_T(kc) { MT(MOD_LGUI | MOD_LALT, kc) }
#define ALT_GUI_PGDN ALTGUI_T(KC_PGDN)  // shift LGUI or PGDN.
#define CTL_GUI_PGDN CTLGUI_T(KC_PGDN)  // shift LGUI or PGDN.
#define SFT_GUI_PGDN SFTGUI_T(KC_PGDN)  // shift LGUI or PGDN.
#define ALT_ENT     ALT_T(KC_ENT)  // Alt or enter
#define CTL_SPC     CTL_T(KC_SPC) // ctrl or space
#define CTL_BSPC    CTL_T(KC_BSPC) // ctrl or backspace
#define ALT_DEL     ALT_T(KC_DEL)  // Alt or delete
#define GUI_ESC     GUI_T(KC_ESC)  // Gui or escape
#define ALGR_SYMB   ALGR_T(TG(SYMB))  // Alt gre or toggle symbol layer
=======
#define CTLGUI_T(kc) MT(MOD_LGUI | MOD_LCTL, kc)
#define SFTGUI_T(kc) MT(MOD_LGUI | MOD_LSFT, kc)
#define ALTGUI_T(kc) MT(MOD_LGUI | MOD_LALT, kc)
>>>>>>> d02be63000a4f5efe728f36608c33bcdaee08330

#define ALT_ENT     ALT_T(KC_ENT)       // Alt or enter
#define CTL_SPC     CTL_T(KC_SPC)       // ctrl or space
#define CTL_BSPC    CTL_T(KC_BSPC)      // ctrl or backspace
#define ALT_DEL     ALT_T(KC_DEL)       // Alt or delete
#define GUI_ESC     GUI_T(KC_ESC)       // Gui or escape
#define ALGR_SYMB   ALGR_T(TG(_SYMB))    // Alt gre or toggle symbol layer

#define ENT_NAV LT(_NAV, KC_ENT)
#define ENT_TOPR LT(_TOPROWS, KC_ENT)
#define ENT_TOPR_BP LT(_TOPROWS_BP, KC_ENT)
#define ESC_TOPR LT(_TOPROWS, KC_ESC)
#define ESC_TOPR_BP LT(_TOPROWS_BP, KC_ESC)
#define ESC_SYMB LT(_SYMB, KC_ESC)
#define ESC_SYMB_BP LT(_SYMB_BP, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define SPC_TOPR LT(_TOPROWS, KC_SPC)
#define SPC_TOPR_BP LT(_TOPROWS_BP, KC_SPC)
#define SPC_LAYR LT(_LAYERS, KC_SPC)
#define SPC_LAYR_BP LT(_LAYERS, KC_SPC)
#define SPC_ADJ LT(_ADJUST, KC_SPC)
#define SPC_ADJ_BP LT(_ADJUST, KC_SPC)
#define BSPC_SYMB LT(_SYMB, KC_BSPC)
#define BSPC_SYMB_BP LT(_SYMB_BP, KC_BSPC)
#define BSPC_TOPR LT(_TOPROWS, KC_BSPC)
#define BSPC_TOPR_BP LT(_TOPROWS_BP, KC_BSPC)
#define SPC_NUM LT(_KEYPAD, KC_SPC)
#define SPC_NUM_BP LT(_KEYPAD_BP, KC_SPC)
#define BSPC_NUM LT(_KEYPAD, KC_BSPC)
#define BSPC_NUM_BP LT(_KEYPAD_BP, KC_BSPC)

// OSM keycodes, to keep things clean and easy to change
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)


////  TAP DANCE

  typedef struct {
    bool is_press_action;
    int state;
  } tdtap;

enum {
      SINGLE_TAP = 1,
      SINGLE_HOLD = 2,
      DOUBLE_TAP = 3,
      DOUBLE_HOLD = 4,
      DOUBLE_SINGLE_TAP = 5, //send two single taps
      TRIPLE_TAP = 6,
      TRIPLE_HOLD = 7
};

//Tap Dance Declarations
enum {
      TD_ESC_CAPS = 0,
      TD_TAB_BKTAB = 1,
      TD_MDIA_SYMB = 2,
      TD_HOME_END = 3,
      TD_XMONAD_ESC = 4,
      TD_DEF_LAYER_SW = 5,
      TD_DEF_OS_LAYER_SW = 6,
      TD_MOUSE_BTNS = 7,
      TD_DVORAK_BEPO = 8,
      TD_UP_HOME = 9,
      TD_DOWN_END = 10,
      TD_RIGHT_TAB = 11,
      TD_LEFT_BACKTAB = 12
};


// Tap dance
#define KC_BKTAB       LSFT(KC_TAB)
#define TAB_BKTAB       TD(TD_TAB_BKTAB)  // Tab or backtab tapdance.
#define MDIA_SYMB_KP_LAYERS TD(TD_MDIA_SYMB)  // MDIA, symb, keypad, layouts layer tapdance toggle.
#define DEF_LAYER_SW    TD(TD_DEF_LAYER_SW)  // dvorak, dvorak_on_bepo, bepo default layer
#define DEF_OS_LAYER_SW TD(TD_DEF_OS_LAYER_SW)  // dvorak, dvorak_on_bepo, bepo default layer
#define HOME_END        TD(TD_HOME_END)  // home or end tapdance.
#define XMONAD_ESC      TD(TD_XMONAD_ESC)  // Escape, dvorak, media or symb. - tap and hold tap dance. 1-4
#define DVORAK_ET_BEPO  TD(TD_DVORAK_BEPO)  // Escape, dvorak, media or symb. - tap and hold tap dance. 1-4
#define TDMOUSE_BTNS    TD(TD_MOUSE_BTNS)  // hmmm. 1-5
<<<<<<< HEAD
#define RIGHT_TAB       TD(TD_RIGHT_TAB)
#define LEFT_BACKTAB    TD(TD_LEFT_BACKTAB)
#define UP_HOME         TD(TD_UP_HOME)
#define DOWN_END        TD(TD_DOWN_END)
=======
#define RIGHT_TAB       TD(TD_RIGHT_TAB)   // Bad idea these 4. Maybe with good timing...
#define LEFT_BACKTAB    TD(TD_LEFT_BACKTAB)
#define UP_HOME         TD(TD_UP_HOME)
#define DOWN_END        TD(TD_DOWN_END)  //  No! Down Down Not End....
>>>>>>> d02be63000a4f5efe728f36608c33bcdaee08330

// HOME ROW LAYER TOGGLE (LT) and Shift.
// both sides of the home row have  "shift, ___, media , symb, ___"  and  "___, symb, media, ___, shift".
// so pinky fingers are shift when held and the index and second fingers are symbol and
// media layers when held.

<<<<<<< HEAD
#define KC_LGUI_ESC LGUI_T(KC_ESC)
#define KC_LT_MDIA_PGDN LT(MDIA, KC_PGDN)
// Dvorak
// shift and layer switch on hold on the home row.
#define KC_SFT_T_A   SFT_T(KC_A)
#define KC_SFT_T_S   SFT_T(KC_S)

#define KC_LT_SYMB_U LT(SYMB, KC_U)
#define KC_LT_SYMB_H LT(SYMB, KC_H)

#define KC_LT_MDIA_E LT(MDIA, KC_E)
#define KC_LT_MDIA_T LT(MDIA, KC_T)

// Need to add this to the others.
#define KC_LT_KP_N LT(KEYPAD, KC_N)
#define KC_LT_KP_O LT(KEYPAD, KC_O)

// for dvorak on bepo
#define BP_SFT_T_A   SFT_T(BP_A)
#define BP_SFT_T_S   SFT_T(BP_S)

#define BP_LT_SYMB_U LT(SYMB, BP_U)
#define BP_LT_SYMB_H LT(MDIA, BP_H)

#define BP_LT_MDIA_E LT(MDIA, BP_E)
#define BP_LT_MDIA_T LT(MDIA, BP_T)

// Need to add this to the others.
#define BP_LT_KP_N LT(KEYPAD, BP_N)
#define BP_LT_KP_O LT(KEYPAD, BP_O)

// for bepo on bepo
#define BP_SFT_T_T    SFT_T(BP_T)
#define BP_SFT_T_W    SFT_T(BP_W)

#define BP_LT_SYMB_I  LT(SYMB_ON_BEPO, BP_I)
#define BP_LT_MDIA_E  LT(MDIA, BP_E)
#define BP_LT_KP_U    LT(KEYPAD, BP_U)

#define BP_LT_SYMB_S  LT(SYMB_ON_BEPO, BP_S)
#define BP_LT_MDIA_R  LT(MDIA, BP_R)
#define BP_LT_KP_N    LT(KEYPAD, BP_N)

#define BP_SFT_T_A SFT_T(BP_A)
#define BP_SFT_T_S SFT_T(BP_S)
#define BP_SFT_T_E SFT_T(BP_E)
#define BP_SFT_T_M SFT_T(BP_M)

#define BP_SFT_T_ECRC SFT_T(BP_ECIR)
#define BP_SFT_T_CCED SFT_T(BP_CCED)
#define BP_LT_SYMB_COMM LT(SYMB,BP_COMM)

//QWERTY
#define KC_SFT_T_SCLN   SFT_T(KC_SCLN)

#define KC_LT_MDIA_D LT(MDIA, KC_D)
#define KC_LT_MDIA_K LT(MDIA, KC_K)
#define KC_LT_SYMB_F LT(SYMB, KC_F)
#define KC_LT_SYMB_J LT(SYMB, KC_J)

//COLEMAK
#define KC_SFT_T_O   SFT_T(KC_O)
#define KC_LT_MDIA_S LT(MDIA, KC_S)
#define KC_LT_SYMB_T LT(SYMB, KC_T)

#define KC_LT_MDIA_E LT(MDIA, KC_E)
#define KC_LT_SYMB_N LT(SYMB, KC_N)

//WORKMAN
#define KC_SFT_T_I   SFT_T(KC_I)
#define KC_LT_MDIA_H LT(MDIA, KC_H)

//NORMAN
// For keys on the homerow.  Hold for shift, keypad,mouse,and smbol layers
#define KC_SFT_T_U   SFT_T(KC_U)
#define KC_LT_MDIA_I LT(MDIA, KC_I)

=======
>>>>>>> d02be63000a4f5efe728f36608c33bcdaee08330
// The most portable copy/paste keys (windows (mostly), linux, and some terminal emulators).
// The KC_CCCV key takes care of the last two...
#define MK_CUT    LSFT(KC_DEL)  // shift + delete
#define MK_COPY   LCTL(KC_INS)  // ctrl + insert
#define MK_PASTE  LSFT(KC_INS)  // shift + insert

#undef ___ //kint defines it as KC_NO
#define ___ KC_TRNS
#define XXX KC_NO

// Blocking keys
#define _X_ XXX
#define ___X___ XXX
#define ___X2___ XXX, XXX
#define ___X3___ ___X2___, XXX
#define ___X5___ ___X3___, XXX, XXX
#define ___X6___ ___X5___, XXX
#define ___X12___ ___X6___, ___X6___
#define ___X15___ ___X5___, ___X5___,  ___X5___

// Transparent keys
#define ___2___ ___, ___
#define ___3___ ___2___, ___
#define ___4___ ___3___, ___
#define ___5___ ___4___, ___
#define ___6___ ___5___, ___
#define ___12___ ___6___, ___6___
#define ___14___ ___5___, ___4___,  ___5___
#define ___15___ ___5___, ___5___,  ___5___
#define ___16___ ___15___, ___

int on_qwerty(void);
int get_xmonad_layer(void);

#ifdef TAP_DANCES_ENABLE
int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);
#endif
