#pragma once

enum rhruiz_layers { _BL, _VIM_EMACS, _MOUSE, _KEY_OVERRIDE, _FN1, _FN2, _CFG, _NUM };

enum custom_keycodes { KC_MAKE = SAFE_RANGE, NEW_SAFE_RANGE };

/* mission control */
#define MISCTRL LCTL(KC_UP)

/* tap to esc, hold to ctrl */
#define CTRLESC LCTL_T(KC_ESC)

/* space or fn */
#define SPCFN1 LT(_FN1, KC_SPC)
#define SPCFN2 LT(_FN2, KC_SPC)

/* backspace or fn */
#define BKSFN1 LT(_FN1, KC_BSPC)
#define BKSFN2 LT(_FN2, KC_BSPC)

/* arrow cluster */
#define CLLEFT MT(MOD_LGUI, KC_LEFT)
#define CLDOWN MT(MOD_LALT, KC_DOWN)
#define CLUP MT(MOD_RCTL, KC_UP)
#define CLRIGHT LT(_FN1, KC_RIGHT)

void          rhruiz_update_layer_colors(void);
void          rhruiz_on_default_layer(void);
void          rhruiz_update_layer_colors(void);
layer_state_t rhruiz_layer_state_set_user(layer_state_t state);
bool          rhruiz_is_layer_indicator_led(uint8_t index);
void          rhruiz_disable_promicro_leds(void);
bool          rhruiz_process_record(uint16_t keycode, keyrecord_t *record);

/* underglow control */
void rhruiz_rgblight_reset(void);
#ifdef RGBLIGHT_ENABLE
void rhruiz_change_leds_to(uint16_t, uint8_t);

typedef struct {
    uint16_t hue;
    uint8_t  sat;
} hue_sat_pair;

#endif
