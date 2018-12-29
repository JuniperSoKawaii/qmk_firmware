#pragma once

enum rhruiz_layers {
  _BL,
  _VIM_EMACS,
  _MOUSE,
  _KEY_OVERRIDE,
  _FN1,
  _FN2,
  _CFG
};


/* mission control */
#define MISCTRL LCTL(KC_UP)

/* tap to esc, hold to ctrl */
#define CTRLESC LCTL_T(KC_ESC)

/* space or fn2 */
#define SPCFN2 LT(_FN2, KC_SPC)

/* arrow cluster */
#define CLLEFT MT(MOD_LGUI, KC_LEFT)
#define CLDOWN MT(MOD_LALT, KC_DOWN)
#define CLUP MT(MOD_RCTL, KC_UP)
#define CLRIGHT LT(_FN1, KC_RIGHT)

/* raw hid */
#ifdef RAW_ENABLE
#include "rhruiz_api.h"
#include "raw_hid.h"
#endif

void rhruiz_update_layer_colors(void);
uint32_t rhruiz_layer_state_set_user(uint32_t state);

/* underglow control */
#ifdef RGBLIGHT_ENABLE
void rhruiz_rgblight_reset(void);
void rhruiz_change_leds_to(uint16_t, uint8_t);

typedef struct {
  uint16_t hue;
  uint8_t sat;
} hue_sat_pair;

#endif
