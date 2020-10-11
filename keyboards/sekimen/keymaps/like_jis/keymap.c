/* Copyright 2020 n2
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
#include "keymap_jp.h"
#include <stdio.h>
#include "keycode.h"

// If you are using Sekimen's trackball.
// And if you want to use mousekey feature.
// Please define SEKIMEN_MOUSEKEY_ENABLE(don't use qmk's MOUSEKEY_ENABLE.).
//#define SEKIMEN_MOUSEKEY_ENABLE

// Script for the trackball start.
#ifdef POINTING_DEVICE_ENABLE
#include "paw3204.h"
#include "pointing_device.h"
report_mouse_t mouse_rep;
static int  mouse_wheel_count = 0;
static bool mouse_key_flag = 0;
static bool mouse_wheel_flag = 0;
#ifdef SEKIMEN_MOUSEKEY_ENABLE
#include "mousekey.h"
static int w_offset = 1;
static int mouse_wheel_interval = 10;
#else
static int  mouse_wheel_interval = 1;
#endif
#endif
// Script for the trackball end.

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEFAULT = 0,
    _RAISE,
    _LOWER
/*    _FN */
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
  if (!is_keyboard_master()) {
      render_logo();
  } else {
      // Host Keyboard Layer Status
      oled_write_P(PSTR("Layer: "), false);
      switch (biton32(layer_state)) {
          case _DEFAULT:
              oled_write_P(PSTR("DEFAULT\n"), false);
              break;
          case _RAISE:
              oled_write_P(PSTR("RAISE\n"), false);
              break;
          case _LOWER:
              oled_write_P(PSTR("LOWER\n"), false);
          break;
          default:
              // Or use the write_ln shortcut over adding '\n' to the end of your string
          oled_write_ln_P(PSTR("Undefined"), false);
      };
      // Host Keyboard LED Status
      uint8_t led_usb_state = host_keyboard_leds();
      oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
      oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
      oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK\n") : PSTR("      \n"), false);
    }
}
#endif

#if MATRIX_COLS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
   /* DEFAULT
    * ,--------------------------.                                   .--------------------------.
    * |ZEN/HAN |  TAB   |  ESC   |                                   |   -    |   ^    | BSPC   |
    * |--------+--------+--------+-----------------------------------+--------+--------+--------|
    * |   q    |   w    |   e    |   r    |   t    |   y    |   u    |   i    |   o    |   p    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |   a    |   s    |   d    |   f    |   g    |   h    |   j    |   k    |   l    |   ;    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |   z    |   x    |   c    |   v    |   b    |   n    |   m    |   ,    |   .    |   /    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | SHIFT  |  CTRL  |  ALT   | MUHEN  | SPACE  | RAISE  | LOWER  |  CTRL  | SHIFT  | ENTER  |
    * `-----------------------------------------------------------------------------------------'
    */
      KC_ZKHK, KC_TAB,  KC_ESC,                                           JP_MINS, JP_CIRC, KC_BSPC, \
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,       KC_U,       KC_I,    KC_O,    KC_P,    \
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,       KC_J,       KC_K,    KC_L,    KC_SCLN, \
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,       KC_M,       KC_COMM, KC_DOT,  KC_SLSH, \
      KC_LSFT, KC_LCTL, KC_LALT, KC_MHEN, KC_SPC, MO(_RAISE), MO(_LOWER), KC_RCTL, KC_RSFT, KC_ENT   \
    ),
   /* RAISE
    * ,--------------------------.                                   .--------------------------.
    * |        |        |        |                                   |        |        |  DEL   |
    * |--------+--------+--------+-----------------------------------+--------+--------+--------|
    * |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |  ��    |  ��    |  ��    |  ��    |
    * `-----------------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT(
      _______, _______, _______,                                     _______, _______, KC_DEL, \
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT \
    ),
   /* LOWER
    * ,--------------------------.                                   .--------------------------.
    * |        |        |        |                                   |        |        |   \    |
    * |--------+--------+--------+-----------------------------------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |   @    |   [    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |   :    |   ]    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |   \    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |RGB_TOG |RGB_VAI |RGB_HUI |RGB_SAI |        |        |        |        |        |        |
    * `-----------------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT(
      _______, _______, _______,                                     _______, _______, JP_YEN, \
      _______, _______, _______, _______, _______, _______, _______, _______, JP_AT,   JP_LBRC,\
      _______, _______, _______, _______, _______, _______, _______, _______, JP_COLN, JP_RBRC,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_BSLS,\
      RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______ \
    )
};
#else
/* MATRIX_COLS == 7 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* DEFAULT
    * ,--------------------------------------------.                                   .--------------------------------------------.
    * |ZEN/HAN |   1    |   2    |   3    |   4    |                                   |   8    |   9    |   0    |   -    | BSPC   |
    * |--------+--------+--------+--------+--------+-----------------------------------+--------+--------+--------+--------+--------|
    * |  TAB   |   q    |   w    |   e    |   r    |   t    |   5    |   y    |   u    |   i    |   o    |   p    |   @    |   [    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | CAPS   |   a    |   s    |   d    |   f    |   g    |   6    |   h    |   j    |   k    |   l    |   ;    |   :    |   ]    |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | SHIFT  |   z    |   x    |   c    |   v    |   b    |   7    |   n    |   m    |   ,    |   .    |   /    |   \    | ENTER  |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * | CTRL   |  GUI   |  ALT   |        | MUHEN  | SPACE  | LOWER  | RAISE  |   ^    |   \    |  ��    |  ��    |  ��    |  ��    |
    * `-----------------------------------------------------------------------------------------------------------------------------'
    */
    [_DEFAULT] = LAYOUT(
      KC_ZKHK, KC_1,    KC_2,    KC_3,    KC_4,                                             KC_8,    KC_9,    KC_0,    JP_MINS, KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_5,       KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    JP_AT  , JP_LBRC, \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_6,       KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, JP_RBRC, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_7,       KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, KC_ENT , \
      KC_LCTL, KC_LGUI, KC_LALT, _______, KC_MHEN, KC_SPC, MO(_LOWER), MO(_RAISE), JP_CIRC, JP_YEN,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT \
    ),
   /* RAISE
    * ,--------------------------------------------.                                   .--------------------------------------------.
    * |  ESC   |        |        |        |        |                                   |        |        |        |        |  DEL   |
    * |--------+--------+--------+--------+--------+-----------------------------------+--------+--------+--------+--------+--------|
    * |        |   1    |   2    |   3    |   4    |   5    |        |   6    |   7    |   8    |   9    |   0    |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |   �@   |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * `-----------------------------------------------------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT(
      KC_ESC,  _______, _______, _______, _______,                                     _______, _______, _______, _______, KC_DEL,  \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),
   /* LOWER
    * ,--------------------------------------------.                                   .--------------------------------------------.
    * |        |RGB_TOG |RGB_VAI |RGB_HUI |RGB_SAI |                                   |RGB_TOG |RGB_VAI |RGB_HUI |RGB_SAI |        |
    * |--------+--------+--------+--------+--------+-----------------------------------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |  �@    |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
    * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
    * `-----------------------------------------------------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT(
      _______, RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI,                                     RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    )
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
/*                SEND_STRING("QMK is the best thing ever!");*/
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
/*                SEND_STRING("https://qmk.fm/\n"); */
            } else {
                // when keycode QMKURL is released
            }
            break;
    };

// Script for the mousekey start.
#ifdef POINTING_DEVICE_ENABLE
#ifdef SEKIMEN_MOUSEKEY_ENABLE

    if (record->event.pressed){
        if (keycode == KC_MS_BTN1){
            mouse_rep.buttons |= MOUSE_BTN1;
        }else if (keycode == KC_MS_BTN2){
            mouse_rep.buttons |= MOUSE_BTN2;
        }else if (keycode == KC_MS_BTN3){
            mouse_rep.buttons |= MOUSE_BTN3;
        }else if (keycode == KC_MS_BTN4){
            mouse_rep.buttons |= MOUSE_BTN4;
        }else if (keycode == KC_MS_BTN5){
            mouse_rep.buttons |= MOUSE_BTN5;
        }else if (keycode == KC_MS_WH_UP){
            mouse_rep.v = w_offset;
            mouse_wheel_flag = 1;
        }else if (keycode == KC_MS_WH_DOWN){
            mouse_rep.v = w_offset * -1;
            mouse_wheel_flag = 1;
        }else if (keycode == KC_MS_WH_LEFT){
            mouse_rep.h = w_offset * -1;
            mouse_wheel_flag = 1;
        }else if (keycode == KC_MS_WH_RIGHT){
            mouse_rep.h = w_offset;
            mouse_wheel_flag = 1;
        }
            mouse_key_flag = 1;
    } else {
        if (keycode == KC_MS_BTN1){
            mouse_rep.buttons &= ~MOUSE_BTN1;
        }else if (keycode == KC_MS_BTN2){
            mouse_rep.buttons &= ~MOUSE_BTN2;
        }else if (keycode == KC_MS_BTN3){
            mouse_rep.buttons &= ~MOUSE_BTN3;
        }else if (keycode == KC_MS_BTN4){
            mouse_rep.buttons &= ~MOUSE_BTN4;
        }else if (keycode == KC_MS_BTN5){
            mouse_rep.buttons &= ~MOUSE_BTN5;
        } else if (keycode == KC_MS_WH_UP && mouse_rep.v > 0){
            mouse_rep.v = 0;
            mouse_wheel_flag = 0;
        } else if (keycode == KC_MS_WH_DOWN && mouse_rep.v < 0){
            mouse_rep.v = 0;
            mouse_wheel_flag = 0;
        }else if (keycode == KC_MS_WH_LEFT && mouse_rep.h < 0){
            mouse_rep.h = 0;
            mouse_wheel_flag = 0;
        }else if (keycode == KC_MS_WH_RIGHT && mouse_rep.h > 0){
            mouse_rep.h = 0;
            mouse_wheel_flag = 0;
        }
            mouse_key_flag = 0;
            pointing_device_set_report(mouse_rep);
    }
#endif
#endif
// Script for the mousekey end.

    return true;
}

// Script for the trackball start.
#ifdef POINTING_DEVICE_ENABLE

void matrix_init_user(void) {
    init_paw3204();
}

void matrix_scan_user(void) {
    static int  cnt;
    static bool paw_ready;
    if (cnt++ % 50 == 0) {
        uint8_t pid = read_pid_paw3204();
        if (pid == 0x30) {
            dprint("paw3204 OK\n");
            paw_ready = true;
        } else {
            dprintf("paw3204 NG:%d\n", pid);
            paw_ready = false;
        }
    }

    if (paw_ready) {
        uint8_t stat;
        int8_t x, y;

        read_paw3204(&stat, &x, &y);
        mouse_rep.x       = y;
        mouse_rep.y       = -x;


        if (cnt % 10 == 0) {
            dprintf("stat:%3d x:%4d y:%4d\n", stat, mouse_rep.x, mouse_rep.y);
        }
        if (stat & 0x80 || mouse_key_flag == 1) {
            if(mouse_wheel_flag == 1){
                mouse_wheel_count++;
                if(mouse_wheel_count == mouse_wheel_interval){
                    pointing_device_set_report(mouse_rep);
                    mouse_wheel_count = 0;
                }
            } else {
                pointing_device_set_report(mouse_rep);
            }
        }
    }
}
#endif
// Script for the trackball end.

/*
bool led_update_user(led_t led_state) {
    return true;
}
*/
