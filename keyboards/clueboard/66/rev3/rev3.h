#ifndef REV3_H
#define REV3_H

#include "66.h"

/* Clueboard matrix layout
 * ,-----------------------------------------------------------.  ,---.
 * | 00| 01| 02| 03| 04| 05| 06| 07| 50| 51| 52| 53| 54| 55| 56|  | 57|
 * |-----------------------------------------------------------|  |---|
 * |   10| 11| 12| 13| 14| 15| 16| 17| 60| 61| 62| 63| 64|   65|  | 67|
 * |-----------------------------------------------------------|  `---'
 * |    20| 21| 22| 23| 24| 25| 26| 27| 70| 71| 72| 73| 74|  75|
 * |------------------------------------------------------------.
 * |  30| 31| 32| 33| 34| 35| 36| 37| 80| 81| 82| 83| 84|  85|86|
 * |------------------------------------------------------------------.
 * |  40| 41|  42|  43|   45|       46|   90|  92|  93| 94| 95| 96| 97|
 * `------------------------------------------------------------------'
 * ,-----------------------------------------------------------.  ,---.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Yen| BS|  |Ins|
 * |-----------------------------------------------------------|  |---|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|  |Del|
 * |-----------------------------------------------------------|  `---'
 * |Caps  |  A|  S|  D|  F|  G|  H|  J|  k|  L|  ;|  '| # | Ent|
 * |--------------------------------------------------------------.
 * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  \|Shift| Up|
 * |------------------------------------------------------------------.
 * |Ctrl|Alt|Gui |MHen| Space| Space|Henk|Gui |Ctrl|  Fn|Left|Down|Rgt|
 * `------------------------------------------------------------------'
 */
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array

#define KEYMAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k50, k51, k52, k53, k54, k55, k56, k57, \
    k10, k11, k12, k13, k14, k15, k16, k17, k60, k61, k62, k63, k64, k65,      k67, \
    k20, k21, k22, k23, k24, k25, k26, k27, k70, k71, k72, k73, k74, k75, \
    k30, k31, k32, k33, k34, k35, k36, k37, k80, k81, k82, k83, k84, k85, k86, \
    k40, k41, k42, k43,      k45, k46,      k90,      k92, k93, k94, k95, k96, k97 \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, k37 }, \
    { k40, k41, k42, k43, KC_NO, k45, k46, KC_NO }, \
    { k50, k51, k52, k53, k54, k55, k56, k57 }, \
    { k60, k61, k62, k63, k64, k65, KC_NO, k67 }, \
    { k70, k71, k72, k73, k74, k75, KC_NO, KC_NO }, \
    { k80, k81, k82, k83, k84, k85, k86, KC_NO }, \
    { k90, KC_NO, k92, k93, k94, k95, k96, k97 }  \
}

#endif
