#ifndef REV1_H
#define REV1_H

#include "zygomorph.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

//void promicro_bootloader_jmp(bool program);
// LEL/LER/REL/RER are
//   LeftEncoderLeft, LeftEncoderRight, RightEncoderLeft, and RightEncoderRight

#define LAYOUT( \
  L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
  L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
            LEL, LER,                     REL, RER \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, LEL }, \
    { L10, L11, L12, L13, L14, L15, LER }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, KC_NO }, \
    { L40, L41, L42, L43, L44, L45, KC_NO }, \
    { R00, R01, R02, R03, R04, R05, REL }, \
    { R10, R11, R12, R13, R14, R15, RER }, \
    { R20, R21, R22, R23, R24, R25, KC_NO }, \
    { R30, R31, R32, R33, R34, R35, KC_NO }, \
    { R40, R41, R42, R43, R44, R45, KC_NO } \
  }

#define KC________ KC_TRNS
#define KC_RGB_MOD RGB_MOD
#define KC_FN FN
#define KC_ADJ ADJ
#define LAYOUT_kc( \
  L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
  L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
  L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
            LEL, LER,                     REL, RER \
  ) \
  LAYOUT( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, \
    KC_##L40, KC_##L41, KC_##L42, KC_##L43, KC_##L44, KC_##L45, KC_##R40, KC_##R41, KC_##R42, KC_##R43, KC_##R44, KC_##R45, \
                        KC_##LEL, KC_##LER,                                         KC_##REL, KC_##RER \
  )

#endif
