#ifndef DK60_H
#define DK60_H

#include "quantum.h"
#include "led.h"

inline void dk60_caps_led_on(void)      { DDRE |=  (1<<6); PORTE &= ~(1<<6); }
inline void dk60_esc_led_on(void)    	{ DDRF |=  (1<<0); PORTF &= ~(1<<0); }

inline void dk60_caps_led_off(void)     { DDRE &= ~(1<<6); PORTE &= ~(1<<6); }
inline void dk60_esc_led_off(void)   	{ DDRF &= ~(1<<0); PORTF &= ~(1<<0); }

#define ___ KC_TRNS

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K4B, K4A, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K4C, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, \
         K41, K42,           K45,           K48, K49  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C }, \
    { ___, K41, K42, ___, ___, K45, ___, ___, K48, K49, K4A, K4B, K4C }  \
}

#endif