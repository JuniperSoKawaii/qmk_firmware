/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x15(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,         KC_5,   KC_MINS,       KC_EQL,        KC_6,   KC_7,         KC_8,    KC_9,    KC_0,    LGUI(KC_0), KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,   KC_LCBR,       KC_RCBR,       KC_Y,   KC_U,         KC_I,    KC_O,    KC_P,    KC_GRV,     KC_BSLS,
        KC_QUOT, KC_A,    KC_S,    KC_D,    KC_F,         KC_G,   KC_LBRC,       KC_RBRC,       KC_H,   KC_J,         KC_K,    KC_L,    KC_SCLN, KC_PENT,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,   KC_QUES,       KC_SLSH,       KC_N,   KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_UP,      KC_RSFT,
        MO(2),  KC_LCTL, KC_LALT, KC_LGUI, LT(1,KC_SPC),  KC_SPC, MO(1),         MO(1),         KC_SPC, LT(1,KC_SPC), KC_RGUI, MO(2),   KC_LEFT, KC_DOWN,    KC_RGHT
    ),


    [1] = LAYOUT_ortho_5x15(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, LGUI(KC_MINS), LGUI(KC_EQL),  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,       LGUI(KC_0),    KC_DEL,
        KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   LGUI(KC_LCBR), LGUI(KC_RCBR), KC_NO,   KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,       KC_NO,         KC_NO,
        KC_GRV,  KC_TILD, KC_AT,   KC_PERC, KC_AMPR, KC_ASTR, LGUI(KC_LBRC), LGUI(KC_RBRC), KC_HASH, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,       KC_NO,         KC_NO,
        KC_TRNS, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  KC_EXLM, LGUI(KC_QUES), LGUI(KC_SLSH), KC_CIRC, KC_DLR,  KC_QUES, KC_SLSH, KC_NO,         LCAG(KC_UP),   KC_TRNS,
        MO(15),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,       KC_TRNS,       KC_NO,   KC_TRNS, KC_TRNS, MO(15),  LGUI(KC_LBRC), LCAG(KC_DOWN), LGUI(KC_RBRC)
    ),

    [2] = LAYOUT_ortho_5x15(
        DB_TOGG,    KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  LGUI(KC_0), LGUI(KC_0), KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_NO,   KC_DEL,
        KC_NO,      KC_F11,  KC_F12,  KC_F13,  KC_F14, KC_F15, KC_NO,      KC_NO,      KC_F16, KC_F17, KC_F18,  KC_F19,  KC_F20,  KC_NO,   KC_NO,
        HYPR(KC_H), KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_F21, KC_F22, KC_F23,  KC_F24,  KC_NO,   KC_NO,   KC_NO,
        KC_TRNS,    KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, MO(15), KC_NO,  KC_NO,      KC_NO,      KC_NO,  MO(15), KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END
    ),


    // Musical keys



    [7] = LAYOUT_ortho_5x15(

        // Chromatic Scale       Vertical
        //      1,        2,        3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_C,     MI_E,     MI_Gs,    MI_C_2,   MI_E_2,   MI_Gs_2,  MI_C_3,   MI_E_3,   MI_Gs_3,  MI_C_4,   MI_E_4,   MI_Gs_4,  KC_NO,   MI_TRNS_0,
        KC_TAB, MI_Cs,    MI_F,     MI_A,     MI_Cs_2,  MI_F_2,   MI_A_2,   MI_Cs_3,  MI_F_3,   MI_A_3,   MI_Cs_4,  MI_F_4,   MI_A_4,   KC_NO,   MI_TRNSU,
        KC_SPC, MI_D,     MI_Fs,    MI_As,    MI_D_2,   MI_Fs_2,  MI_As_2,  MI_D_3,   MI_Fs_3,  MI_As_3,  MI_D_4,   MI_Fs_4,  MI_As_4,  KC_NO,   MI_TRNSD,
        MI_SUS, MI_Ds,    MI_G,     MI_B,     MI_Ds_2,  MI_G_2,   MI_B_2,   MI_Ds_3,  MI_G_3,   MI_B_3,   MI_Ds_4,  MI_G_4,   MI_B_4,   KC_NO,   MI_OCTU,
        MO(15), KC_LCTL,  KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,    MI_MODSD, MI_MODSU, MI_OCTD
    ),


    [8] = LAYOUT_ortho_5x15(
        // Pocket Operator Scale Vertical
        //      1,      2,      3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_C,    MI_G,    MI_C_2,   MI_G_2,   MI_C_3,   MI_G_3,   MI_C_4,   MI_G_4,   MI_C_5,   MI_G_5,   MI_C_6,   MI_G_6,   KC_NO,   MI_TRNS_0,
        KC_TAB, MI_D,    MI_Gs,   MI_D_2,   MI_Gs_2,  MI_D_3,   MI_Gs_3,  MI_D_4,   MI_Gs_4,  MI_D_5,   MI_Gs_5,  MI_D_6,   MI_Gs_6,  KC_NO,   MI_TRNSU,
        KC_SPC, MI_Ds,   MI_As,   MI_Ds_2,  MI_As_2,  MI_Ds_3,  MI_As_3,  MI_Ds_4,  MI_As_4,  MI_Ds_5,  MI_As_5,  MI_Ds_6,  MI_As_6,  KC_NO,   MI_TRNSD,
        MI_SUS, MI_F,    MI_B,    MI_F_2,   MI_B_2,   MI_F_3,   MI_B_3,   MI_F_4,   MI_B_4,   MI_F_5,   MI_B_5,   MI_F_6,   MI_B_6,   KC_NO,   MI_OCTU,
        MO(15), KC_LCTL, KC_LALT, KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,    MI_MODSD, MI_MODSU, MI_OCTD
    ),

    [9] = LAYOUT_ortho_5x15(
        // Major scale           Vertical
        //      1,       2,       3,       4,        5,       6,       7,       8,       9,        10,       11,     12,
        KC_ESC, MI_C,    MI_G,    MI_D_2,  MI_A_2,   MI_E_3,  MI_B_3,  MI_F_4,  MI_C_5,  MI_G_5,   MI_D_6,   MI_A_6, KC_NO,    KC_NO,    MI_TRNS_0,
        KC_TAB, MI_D,    MI_A,    MI_E_2,  MI_B_2,   MI_F_3,  MI_C_4,  MI_G_4,  MI_D_5,  MI_A_5,   MI_E_6,   MI_B_6, KC_NO,    KC_NO,    MI_TRNSU,
        KC_SPC, MI_E,    MI_B,    MI_F_2,  MI_C_3,   MI_G_3,  MI_D_4,  MI_A_4,  MI_E_5,  MI_B_5,   MI_F_6,   KC_NO,  KC_NO,    KC_NO,    MI_TRNSD,
        MI_SUS, MI_F,    MI_C_2,  MI_G_2,  MI_D_3,   MI_A_3,  MI_E_4,  MI_B_4,  MI_F_5,  MI_C_6,   MI_G_6,   KC_NO,  KC_NO,    KC_NO,    MI_OCTU,
        MO(15), KC_LCTL, KC_LALT, KC_LGUI, MI_BENDD, MI_SUS,  MI_SUS,  MI_SUS,  MI_SUS,  MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),

    [10] = LAYOUT_ortho_5x15(
        // Black Keys            Vertical
        //      1,       2,        3,        4,        5,        6,        7,        8,        9,        10,       11,     12,
        KC_ESC, MI_Cs,   MI_As,    MI_Gs_2,  MI_Fs_3,  MI_Ds_4,  MI_Cs_5,  MI_As_5,  MI_Gs_6,  KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    MI_TRNS_0,
        KC_TAB, MI_Ds,   MI_Cs_2,  MI_As_2,  MI_Gs_3,  MI_Fs_4,  MI_Ds_5,  MI_Cs_6,  MI_As_6,  KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    MI_TRNSU,
        KC_SPC, MI_Fs,   MI_Ds_2,  MI_Cs_3,  MI_As_3,  MI_Gs_4,  MI_Fs_5,  MI_Ds_6,  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    MI_TRNSD,
        MI_SUS, MI_Gs,   MI_Fs_2,  MI_Ds_3,  MI_Cs_4,  MI_As_4,  MI_Gs_5,  MI_Fs_6,  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    MI_OCTU,
        MO(15), KC_LCTL, KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),


    [11] = LAYOUT_ortho_5x15(
        // Chromatic Scale       Horizontal
        //      1,    2,        3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_C,   MI_Cs,    MI_D,     MI_Ds,    MI_E,     MI_F,     MI_Fs,    MI_G,     MI_Gs,    MI_A,     MI_As,    MI_B,     KC_NO,   MI_TRNS_0,
        KC_TAB, MI_C_2, MI_Cs_2,  MI_D_2,   MI_Ds_2,  MI_E_2,   MI_F_2,   MI_Fs_2,  MI_G_2,   MI_Gs_2,  MI_A_2,   MI_As_2,  MI_B_2,   KC_NO,   MI_TRNSU,
        KC_SPC, MI_C_3, MI_Cs_3,  MI_D_3,   MI_Ds_3,  MI_E_3,   MI_F_3,   MI_Fs_3,  MI_G_3,   MI_Gs_3,  MI_A_3,   MI_As_3,  MI_B_3,   KC_NO,   MI_TRNSD,
        MI_SUS, MI_C_4, MI_Cs_4,  MI_D_4,   MI_Ds_4,  MI_E_4,   MI_F_4,   MI_Fs_4,  MI_G_4,   MI_Gs_4,  MI_A_4,   MI_As_4,  MI_B_4,   KC_NO,   MI_OCTU,
        MO(15), KC_LCTL, KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),
    [12] = LAYOUT_ortho_5x15(
        // Pocket Operator Scale Horizontal
        //      1,      2,      3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_C,    MI_D,    MI_Ds,   MI_F,    MI_G,    MI_Gs,   MI_As,   MI_B,    MI_C_2,   MI_D_2,   MI_Ds_2,  MI_F_2,   KC_NO,   MI_TRNS_0,
        KC_TAB, MI_G_2,   MI_Gs_2,  MI_As_2,  MI_B_2,   MI_C_3,   MI_D_3,   MI_Ds_3,  MI_F_3,   MI_G_3,   MI_Gs_3,  MI_As_3,  MI_B_3,   KC_NO,   MI_TRNSU,
        KC_SPC, MI_C_4,   MI_D_4,   MI_Ds_4,  MI_F_4,   MI_G_4,   MI_Gs_4,  MI_As_4,  MI_B_4,   MI_C_5,   MI_D_5,   MI_Ds_5,  MI_F_5,   KC_NO,   MI_TRNSD,
        MI_SUS, MI_G_5,   MI_Gs_5,  MI_As_5,  MI_B_5,   MI_C_6,   MI_D_6,   MI_Ds_6,  MI_F_6,   MI_G_6,   MI_Gs_6,  MI_As_6,  MI_B_6,   KC_NO,   MI_OCTU,
        MO(15), KC_LCTL, KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),


    [13] = LAYOUT_ortho_5x15(
        // Major scale           Horizontal
        //      1,       2,        3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_C,      MI_D,     MI_E,     MI_F,     MI_G,     MI_A,     MI_B,     MI_C_2,   MI_D_2,   MI_E_2,   MI_F_2,   MI_G_2,   KC_NO,    MI_TRNS_0,
        KC_TAB, MI_A_2,    MI_B_2,   MI_C_3,   MI_D_3,   MI_E_3,   MI_F_3,   MI_G_3,   MI_A_3,   MI_B_3,   MI_C_4,   MI_D_4,   MI_E_4,   KC_NO,    MI_TRNSU,
        KC_SPC, MI_F_4,    MI_G_4,   MI_A_4,   MI_B_4,   MI_C_5,   MI_D_5,   MI_E_5,   MI_F_5,   MI_G_5,   MI_A_5,   MI_B_5,   MI_C_6,   KC_NO,    MI_TRNSD,
        MI_SUS, MI_D_6,    MI_E_6,   MI_F_6,   MI_G_6,   MI_A_6,   MI_B_6,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MI_OCTU,
        MO(15), KC_LCTL, KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),
    [14] = LAYOUT_ortho_5x15(
        // Black Keys            Horizontal
        //      1,       2,        3,        4,        5,        6,        7,        8,        9,        10,       11,       12,
        KC_ESC, MI_Cs,     MI_Ds,    MI_Fs,    MI_Gs,    MI_As,    MI_Cs_2,  MI_Ds_2,  MI_Fs_2,  MI_Gs_2,  MI_As_2,  MI_Cs_3,  MI_Ds_3,  KC_NO,    MI_TRNS_0,
        KC_TAB, MI_Fs_3,   MI_Gs_3,  MI_As_3,  MI_Cs_4,  MI_Ds_4,  MI_Fs_4,  MI_Gs_4,  MI_As_4,  MI_Cs_5,  MI_Ds_5,  MI_Fs_5,  MI_Gs_5,  KC_NO,    MI_TRNSU,
        KC_SPC, MI_As_5,   MI_Cs_6,  MI_Ds_6,  MI_Fs_6,  MI_Gs_6,  MI_As_6,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MI_TRNSD,
        MI_SUS, KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MI_OCTU,
        MO(15), KC_LCTL, KC_LALT,  KC_LGUI,  MI_BENDD, MI_SUS,   MI_SUS,   MI_SUS,   MI_SUS,   MI_BENDU, KC_NO,    KC_NO,  MI_MODSD, MI_MODSU, MI_OCTD
    ),






    // Settings
    [15] = LAYOUT_ortho_5x15(
        DB_TOGG, MI_CH1,  MI_CH2, MI_CH3, MI_CH4,   MI_CH5,   RGB_RMOD, RGB_MOD, MI_CH6,  MI_CH7,  MI_CH8, KC_NO,  KC_NO,  KC_NO, QK_BOOT,
        KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,    RGB_HUD,  RGB_HUI, KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,    RGB_SAD,  RGB_SAI, KC_NO,   DF(11),  DF(12), DF(13), DF(14), KC_NO,  DEBUG,
        KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI, KC_NO,   DF(7),   DF(8),  DF(9),  DF(10), KC_NO,  KC_NO,
        KC_TRNS, KC_NO,   KC_NO,  KC_NO,  KC_TRNS,  RGB_SPD,  DF(0),    DF(0),   RGB_SPI, KC_TRNS, KC_NO,  KC_TRNS,KC_NO,  KC_NO,  KC_NO
    )
};


