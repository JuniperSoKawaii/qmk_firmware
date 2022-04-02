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

/******************************************************************/
/* This is where I put my Keyboard layouts, Everything on the     */
/* edges, the functions on keys like LT() and SFT_T()             */
/* can be applied here. The physical shape of the keyboard is     */
/* also accounted for here. This makes it very simple to add a    */
/* new keyboard and reuse all of my layouts and layers            */
/*                                                                */
/* The particular pieces we define here (as needed) are:          */
/*     * Edge pinky keys, */
/*     * Middle section keys */
/*     * Bottom/5th row */
/*     * Thumbkeys */
/*     * Any functional additions to wrap the keys. ie. LT()      */
/*                                                                */
/* With all of that in hand, we then create a LAYOUT wrapper      */
/* macro that takes a list of keys, to create a keyboard matrix   */
/* that fits the keyboard. Simple.                                */
/*                                                                */
/* The thumb keys, the bottom rows, etc.                          */
/*                                                                */
/* An attempt has been made to adapt the kinesis and ergodox      */
/* Thumb keys to the rectangular shapes of the xd75 and viterbi.  */
/* which are 15x and 14x matrices respectively.                   */
/* The Corne was a perfect fit                                    */
/******************************************************************/

/******************************************************************/
/* * The XD75 is a 5x15 Ortholinear matrix which means it has 3   */
/*       keys inbetween the usual left and right hand keys        */
/* * The Viterbi is a split 5x14 Ortholinear with 2 middle keys.  */
/* * The Ergodox is a split 5x14 Ortholinear with 2 middle keys,  */
/*       thumbkeys. It is missing middle keys on (home) row 3.    */
/* * The Corne is a split 3x12 with 6 thumb keys. It has no       */
/*       extra middle keys                                        */
/*                                                                */
/******************************************************************/


/******************************************************************/
/*   In all cases these keyboards are defined in a matrix which is */
/*   a set of rows. Maybe like so, or not.                         */
/*                                                                 */
/*   -------------------------|------------------------ */
/*   | Left0 | Numbers L | mid|dle0 | numbers R | Right0 | */
/*   | Left1 | keys0-5   | mid|dle1 | Keys6-10  | Right1 | */
/*   | Left2 | keys11-15 | mid|dle2 | Keys16-20 | Right2 | */
/*   | Left3 | keys20-25 | mid|dle3 | Keys25-30 | Right3 | */
/*   | Row5L                  |                    Row5R | */
/*   |               ThumbsL  | ThumbsR                  | */
/*   -------------------------|------------------------ */

/* Generally speaking, the keys on the right and left don't change. */
/* Neither does the bottom row or the thumbs. Frequently the numbers */
/* row is identical across layers. Mostly, we want our Base layers to */
/* be predctable.                                                     */

// Edge columns. N rows by 6 columns per side.
// Outside pinky keys are 'yes'
// Should be undef/def'd by the keyboard's keymap if no.
//#define EDGE_COLS yes

// BEPO or EN. Used in map.h
//#define LANG_IS EN


// EDGES
// outside pinky keys row 0-3.
// Qwerty and Bepo, - Applies
// to foreign layouts on bepo. dvorak_bp, beakl_bp.
// Use by Wrapping the root like so. LANG_N(LEFT0)
// Add more languages by adding more definitions.
#define LEFT0_EN KC_GRV
//#define LEFT1_EN KC_GRV
#define LEFT1_EN SML_NAV
#define LEFT2_EN KC_TAB
//#define LEFT3_EN KC_BSLASH
#define LEFT3_EN SML_NAV
//#define LEFT3_EN OSL(_ACCENTS_MORTE_EN)

#define LEFT0_BP BP_GRV
 //#define LEFT1_BP BP_GRV
#define LEFT1_BP SML_NAV
#define LEFT2_BP KC_TAB
#define LEFT3_BP BP_BSLS
//#define LEFT3_BP OSL(_ACCENTS_MORTE_BP)

/* #define RIGHT0_EN KC_EQL */
#define RIGHT0_EN SML_NAV
/* #define RIGHT1_EN KC_SLASH */
#define RIGHT1_EN SML_NAV
#define RIGHT2_EN KC_MINS
#define RIGHT3_EN KC_SCLN
//#define RIGHT3_EN SML_KEYPAD

#define RIGHT0_BP BP_EQL
/* #define RIGHT1_BP BP_SLSH */
#define RIGHT1_BP SML_NAV
#define RIGHT2_BP BP_DV_MINS
/* #define RIGHT3_BP BP_SCLN */
#define RIGHT3_BP TG(_COMBO_REF)

// Edges for the combo reference layers.
#define LEFT0_CB L0_CB
#define LEFT1_CB L1_CB
#define LEFT2_CB L2_CB
#define LEFT3_CB L3_CB

#define RIGHT0_CB R0_CB
#define RIGHT1_CB R1_CB
#define RIGHT2_CB R2_CB
#define RIGHT3_CB R3_CB

#define LEFT0_CB2 L0_CB2
#define LEFT1_CB2 L1_CB2
#define LEFT2_CB2 L2_CB2
#define LEFT3_CB2 L3_CB2

#define RIGHT0_CB2 R0_CB2
#define RIGHT1_CB2 R1_CB2
#define RIGHT2_CB2 R2_CB2
#define RIGHT3_CB2 R3_CB2
/******************************************************************/
/* Middle Keysets for various keyboards                           */
// MIDDLES
/// Middle left and right keys.
/******************************************************************/
#define ___MIDDLE_LT___ OSL(_LAYERS)
#define ___MIDDLE_L1___ LANG_KC(_CCCV)
#define ___MIDDLE_L2___ TO(LN_SYMB)
#define ___MIDDLE_L3___ TO(_NAV)

#define ___MIDDLE_RT___ _X_
#define ___MIDDLE_R1___ LANG_KC(_CCCV)
#define ___MIDDLE_R2___ TO(LN_TOPROWS)
#define ___MIDDLE_R3___ ___

// 3 keys in the middle of a 15x matrix
#define ___3_MIDDLE_T___ ___MIDDLE_LT___,    LCTL(LANG_KC(_A)), ___MIDDLE_RT___
#define ___3_MIDDLE_1___ ___MIDDLE_L1___,    LCTL(LANG_KC(_X)), ___MIDDLE_R1___
#define ___3_MIDDLE_2___ ___MIDDLE_L2___,    TO_RGB,            ___MIDDLE_R2___
#define ___3_MIDDLE_3___ ___MIDDLE_L3___,    TO(LN_SYMB),       ___MIDDLE_R3___

// 2 keys in the middle of a 14x matrix  - For viterbi and ergodox.
#define ___2_MIDDLE_T___ ___MIDDLE_LT___,    ___MIDDLE_RT___
#define ___2_MIDDLE_1___ ___MIDDLE_L1___,    ___MIDDLE_R1___
#define ___2_MIDDLE_2___ ___MIDDLE_L2___,    ___MIDDLE_R2___
#define ___2_MIDDLE_3___ ___MIDDLE_L3___,    ___MIDDLE_R3___

/********************************************************************/
/* THUMBS  */
/* Define the thumb clusters for all the keyboards.                 */
/********************************************************************/

// for xd75 or other layouts with a center column.
// #define ___5_MIDDLE_THUMBS___ CTL_BSPC,    ALT_DEL,     XMONAD_ESC,  ALT_ENT,   CTL_SPC
#define ___5_MIDDLE_THUMBS___ ALT_DEL, BSPC_TOPR, ESC_SYMB, ENT_NAV, SPC_TOPR

// for a last, 4th thumb row. for rebound.
// backtab, home end, ----, pgup, pgdn, tab ?
#define ___13_BOTTOM___                                           \
  KC_BKTAB, HOME_END, KC_TAB, TT(_NAV), BSPC_SYMB, ESC_TOPR,      \
    OSL(_LAYERS),                                               \
    ENT_NAV, SPC_TOPR, KC_LEFT, KC_PGUP, KC_PGDN, KC_RIGHT

#define ___12_BOTTOM___                                         \
  KC_BKTAB, HOME_END, KC_TAB, TT(_NAV), BSPC_SYMB, ESC_TOPR,    \
    ENT_NAV, SPC_TOPR, KC_LEFT, KC_PGUP, KC_PGDN, KC_RIGHT

// becomes the upper thumbs, the real 4th row if we throw away
// the number row at the top.
// this is the 4th row on the viterbi above the thumbrow if the number
// row is not used for numbers.
#define ___4_MIDDLE_4___    LSFT(KC_TAB),    HOME_END,    KC_PGDN, KC_TAB
#define ___4_MIDDLE_4b___   TAB_BKTAB,       HOME_END,    KC_PGDN, KC_PGUP

/********************************************************************/
/**  The bottom row and thumbs as needed.                          **/
/********************************************************************/
// Only the 14 and 15 wide bottom rows have bepo versions.
// all others are handled through macros.


// I do not use those pinky keys. I had useful things there but there
// are better more useful ways than those pinkys.
#define ___5_BOTTOM_LEFT___  ___X2___,  KC_INS,  KC_LEFT, KC_RIGHT
#define ___5_BOTTOM_RIGHT___ KC_UP,  KC_DOWN,  KC_BSLASH, ___X2___

#define ___4_BOTTOM_LEFT___  LCTL(KC_V),  KC_INS,  KC_LEFT,   KC_RIGHT
#define ___4_BOTTOM_RIGHT___ KC_UP,       KC_DOWN, KC_BSLASH, LCTL(KC_C)

// the bottom rows  for keyboards on bepo.
// bepo on bepo - not enough space to go around....
#define ___5_BOTTOM_LEFT_BP___  _X_,    BP_EACU,  _X_,           KC_LEFT, KC_RIGHT
#define ___5_BOTTOM_RIGHT_BP___ KC_UP,  KC_DOWN,  BP_BSLS,  BP_CCED,  BP_PERC

#define ___4_BOTTOM_LEFT_BP___  LCTL(BP_C),  BP_EACU,  KC_LEFT, KC_RIGHT
#define ___4_BOTTOM_RIGHT_BP___ KC_UP,  KC_DOWN, BP_BSLS,  BP_CCED

// for dvorak and beakl on bepo
#define ___5_BOTTOM_LEFT_FR___  ___X3___,  KC_LEFT, KC_RIGHT
#define ___5_BOTTOM_RIGHT_FR___ KC_UP,  KC_DOWN,  BP_BSLS, ___X2___


// basically a 5th row in a 5x matrix. but maybe a 4th if there isnt a number row.
// need an en, because we a have a BP and we used it directly in the layout.
#define ___15_BOTTOM_EN___  ___5_BOTTOM_LEFT___,    ___5_MIDDLE_THUMBS___, ___5_BOTTOM_RIGHT___
#define ___15_BOTTOM_FR___  ___5_BOTTOM_LEFT_FR___, ___5_MIDDLE_THUMBS___, ___5_BOTTOM_RIGHT_FR___
#define ___15_BOTTOM_BP___  ___5_BOTTOM_LEFT_BP___, ___5_MIDDLE_THUMBS___, ___5_BOTTOM_RIGHT_BP___

    // need an en, because we a have a BP and we used it directly in the layout.
#define ___14_BOTTOM_EN___    ___5_BOTTOM_LEFT___,    ___4_MIDDLE_4b___, ___5_BOTTOM_RIGHT___
#define ___14_BOTTOM_FR___ ___5_BOTTOM_LEFT_FR___, ___4_MIDDLE_4b___, ___5_BOTTOM_RIGHT_FR___
#define ___14_BOTTOM_BP___ ___5_BOTTOM_LEFT_BP___, ___4_MIDDLE_4b___, ___5_BOTTOM_RIGHT_BP___
#define ___14_THUMBS_BOTTOM___   ___X4___, ___6_ERGO_THUMBS___, ___X4___
