#include "quantum.h"
#include "action.h"
#include "version.h"

// #define KC_SFT_CPS MT(MOD_LSFT, KC_CAPS) // Act as Shift on hold and as CapsLock on tap
#define SPC_LOW LT(_LOWER, KC_ENT) // Left space on tap, LOWER on hold
#define SPC_UPR LT(_RAISE, KC_SPC) // Left space on tap, UPPER on hold

extern keymap_config_t keymap_config;

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROW,
    _FKEY
};

enum custom_keycodes {
    KC_EMAIL = 0,
    TD_SFT_CPS,
    KC_BEPIS,
    KC_BBB,
    BASE,
    LOWER,
    RAISE,
    ADJUST,
    ARROW,
    FKEY,
    KC_LFT_NUM_F
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_ARROW MO(4)
#define KC_RST   RESET
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB) // Tab on tap, ctrl on hold
#define KC_SFT_CPS TD(TD_SFT_CPS) // Hold for shift, double tap for caps
#define KC_ENT_LOW LT(_LOWER, KC_ENT) // Return on tap, Lower on hold
#define KC_SPC_RSE LT(_RAISE, KC_SPC) // Space on tap, raise on hold
#define KC_EML TD(KC_EMAIL) // Double tap @ for email macro
#define KC_FKEY LT(_FKEY, KC_ENT) // Return on tap, Fkey on hold
#define KC_NUMF TD(KC_LFT_NUM_F)

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

void          matrix_init_keymap(void);
void          matrix_scan_keymap(void);
