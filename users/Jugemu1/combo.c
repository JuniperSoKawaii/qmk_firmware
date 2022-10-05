#include "jugemu.h"

enum combos{
    //left
    CMB_JK,
    CMB_JL,
    CMB_KL,
    CMB_JI,

    //right
    CMB_DF,
    CMB_EF,
    CMB_SF,
    CMB_AF,
    CMB_AR,
    CMB_AW,
    CMB_IO,
    CMB_CMDT,
};

const uint16_t PROGMEM cmb_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_jl[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_kl[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM cmb_uk[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_ji[] = {KC_J, KC_I, COMBO_END};

const uint16_t PROGMEM cmb_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ef[] = {KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_sf[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_af[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ar[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_aw[] = {KC_A, KC_W, COMBO_END};
const uint16_t PROGMEM cmb_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_cmdt[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  //right
  [CMB_JK] = COMBO(cmb_jk, KC_RCTL),
  [CMB_JL] = COMBO(cmb_jl, KC_SPC),
  [CMB_KL] = COMBO(cmb_kl, KC_LALT),
  [CMB_JI] = COMBO(cmb_ji, KC_RSFT),

  //left
  [CMB_DF] = COMBO(cmb_df, KC_LCTL),
  [CMB_EF] = COMBO(cmb_ef, KC_LSFT),
  [CMB_SF] = COMBO(cmb_sf, KC_SPC),
  [CMB_AF] = COMBO(cmb_af, KC_TAB),
  [CMB_AR] = COMBO_ACTION(cmb_ar),      // LSFT + TAB
  [CMB_AW] = COMBO(cmb_aw, KC_ESC),
  [CMB_IO] = COMBO(cmb_io, KC_BSPC),
  [CMB_CMDT] = COMBO(cmb_cmdt, KC_ENT),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_AR:
      if (pressed) {
        // LSFT + TAB
        register_code16(KC_LSFT);
        register_code16(KC_TAB);
        unregister_code16(KC_TAB);
        unregister_code16(KC_LSFT);
      }
      break;
  }
}
