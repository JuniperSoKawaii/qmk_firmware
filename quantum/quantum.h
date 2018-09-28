/* Copyright 2016-2018 Erez Zukerman, Jack Humbert, Yiancar
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
#ifndef QUANTUM_H
#define QUANTUM_H

#if defined(__AVR__)
    #include <avr/pgmspace.h>
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#if defined(PROTOCOL_CHIBIOS)
    #include "hal.h"
#endif
#include "wait.h"
#include "matrix.h"
#include "keymap.h"
#ifdef BACKLIGHT_ENABLE
    #include "backlight.h"
#endif
#if !defined(RGBLIGHT_ENABLE) && !defined(RGB_MATRIX_ENABLE)
    #include "rgb.h"
#endif
#ifdef RGBLIGHT_ENABLE
  #include "rgblight.h"
#else
    #ifdef RGB_MATRIX_ENABLE
        /* dummy define RGBLIGHT_MODE_xxxx */
        #define RGBLIGHT_H_DUMMY_DEFINE
        #include "rgblight.h"
    #endif
#endif

#ifdef SPLIT_KEYBOARD
    #include "split_flags.h"
#endif

#ifdef RGB_MATRIX_ENABLE
    #include "rgb_matrix.h"
#endif

#include "action_layer.h"
#include "eeconfig.h"
#include <stddef.h>
#include "bootloader.h"
#include "timer.h"
#include "config_common.h"
#include "led.h"
#include "action_util.h"
#include <stdlib.h>
#include "print.h"
#include "send_string_keycodes.h"
#include "suspend.h"

extern uint32_t default_layer_state;

#ifndef NO_ACTION_LAYER
    extern uint32_t layer_state;
#endif

#ifdef MIDI_ENABLE
#ifdef MIDI_ADVANCED
    #include "process_midi.h"
#endif
#endif // MIDI_ENABLE

#ifdef AUDIO_ENABLE
    #include "audio.h"
    #include "process_audio.h"
    #ifdef AUDIO_CLICKY
        #include "process_clicky.h"
    #endif // AUDIO_CLICKY
#endif

#ifdef STENO_ENABLE
    #include "process_steno.h"
#endif

#if defined(AUDIO_ENABLE) || (defined(MIDI_ENABLE) && defined(MIDI_BASIC))
    #include "process_music.h"
#endif

#ifdef LEADER_ENABLE
    #include "process_leader.h"
#endif

#ifdef UNICODE_ENABLE
    #include "process_unicode.h"
#endif

#ifdef UCIS_ENABLE
    #include "process_ucis.h"
#endif

#ifdef UNICODEMAP_ENABLE
    #include "process_unicodemap.h"
#endif

#include "process_tap_dance.h"

#ifdef PRINTING_ENABLE
    #include "process_printer.h"
#endif

#ifdef AUTO_SHIFT_ENABLE
    #include "process_auto_shift.h"
#endif

#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#ifdef KEY_LOCK_ENABLE
    #include "process_key_lock.h"
#endif

#ifdef TERMINAL_ENABLE
    #include "process_terminal.h"
#else
    #include "process_terminal_nop.h"
#endif

#ifdef HD44780_ENABLE
    #include "hd44780.h"
#endif

//Function substitutions to ease GPIO manipulation
#ifdef __AVR__
    #define pin_t uint8_t
    #define setPinInput(line) _SFR_IO8((line >> 4) + 1) &= ~ _BV(line & 0xF)
    #define setPinInputHigh(line) ({\
            _SFR_IO8((line >> 4) + 1) &= ~ _BV(line & 0xF);\
            _SFR_IO8((line >> 4) + 2) |=  _BV(line & 0xF);\
            })
    #define setPinInputLow(line) _Static_assert(0, "AVR Processors cannot impliment an input as pull low")
    #define setPinOutput(line) _SFR_IO8((line >> 4) + 1) |= _BV(line & 0xF)

    #define writePinHigh(line) _SFR_IO8((line >> 4) + 2) |=  _BV(line & 0xF)
    #define writePinLow(line) _SFR_IO8((line >> 4) + 2) &= ~_BV(line & 0xF)
    static inline void writePin(LINE_TYPE line, uint8_t level){
        if (level){
            _SFR_IO8((line >> 4) + 2) |=  _BV(line & 0xF);
        } else {
            _SFR_IO8((line >> 4) + 2) &= ~_BV(line & 0xF);
        }
    }

    #define readPin(line) (_SFR_IO8(line >> 4) & _BV(line & 0xF))
#elif defined(PROTOCOL_CHIBIOS)
    #define pin_t ioline_t
    #define setPinInput(line) palSetLineMode(line, PAL_MODE_INPUT)
    #define setPinInputHigh(line) palSetLineMode(line, PAL_MODE_INPUT_PULLUP)
    #define setPinInputLow(line) palSetLineMode(line, PAL_MODE_INPUT_PULLDOWN)
    #define setPinOutput(line) palSetLineMode(line, PAL_MODE_OUTPUT_PUSHPULL)

    #define writePinHigh(line) palSetLine(line)
    #define writePinLow(line) palClearLine(line)
    static inline void writePin(pin_t line, uint8_t level){
        if (level){
            palSetLine(line);
        } else {
            palClearLine(line);
        }
    }

    #define readPin(line) palReadLine(line)
#endif

#define STRINGIZE(z) #z
#define ADD_SLASH_X(y) STRINGIZE(\x ## y)
#define SYMBOL_STR(x) ADD_SLASH_X(x)

#define SS_TAP(keycode) "\1" SYMBOL_STR(keycode)
#define SS_DOWN(keycode) "\2" SYMBOL_STR(keycode)
#define SS_UP(keycode) "\3" SYMBOL_STR(keycode)

#define SS_LCTRL(string) SS_DOWN(X_LCTRL) string SS_UP(X_LCTRL)
#define SS_LGUI(string) SS_DOWN(X_LGUI) string SS_UP(X_LGUI)
#define SS_LCMD(string) SS_LGUI(string)
#define SS_LWIN(string) SS_LGUI(string)
#define SS_LALT(string) SS_DOWN(X_LALT) string SS_UP(X_LALT)
#define SS_LSFT(string) SS_DOWN(X_LSHIFT) string SS_UP(X_LSHIFT)
#define SS_RALT(string) SS_DOWN(X_RALT) string SS_UP(X_RALT)

#define SEND_STRING(str) send_string_P(PSTR(str))
extern const bool ascii_to_shift_lut[0x80];
extern const uint8_t ascii_to_keycode_lut[0x80];
void send_string(const char *str);
void send_string_with_delay(const char *str, uint8_t interval);
void send_string_P(const char *str);
void send_string_with_delay_P(const char *str, uint8_t interval);
void send_char(char ascii_code);

// For tri-layer
void update_tri_layer(uint8_t layer1, uint8_t layer2, uint8_t layer3);
uint32_t update_tri_layer_state(uint32_t state, uint8_t layer1, uint8_t layer2, uint8_t layer3);

void set_single_persistent_default_layer(uint8_t default_layer);

void tap_random_base64(void);

#define IS_LAYER_ON(layer)  (layer_state & (1UL << (layer)))
#define IS_LAYER_OFF(layer) (~layer_state & (1UL << (layer)))

void matrix_init_kb(void);
void matrix_scan_kb(void);
void matrix_init_user(void);
void matrix_scan_user(void);
bool process_action_kb(keyrecord_t *record);
bool process_record_kb(uint16_t keycode, keyrecord_t *record);
bool process_record_user(uint16_t keycode, keyrecord_t *record);

void reset_keyboard(void);

void startup_user(void);
void shutdown_user(void);

void register_code16 (uint16_t code);
void unregister_code16 (uint16_t code);

#ifdef BACKLIGHT_ENABLE
void backlight_init_ports(void);
void backlight_task(void);

#ifdef BACKLIGHT_BREATHING
void breathing_enable(void);
void breathing_pulse(void);
void breathing_disable(void);
void breathing_self_disable(void);
void breathing_toggle(void);
bool is_breathing(void);

void breathing_intensity_default(void);
void breathing_period_default(void);
void breathing_period_set(uint8_t value);
void breathing_period_inc(void);
void breathing_period_dec(void);
#endif

#endif
void send_dword(uint32_t number);
void send_word(uint16_t number);
void send_byte(uint8_t number);
void send_nibble(uint8_t number);
uint16_t hex_to_keycode(uint8_t hex);

void led_set_user(uint8_t usb_led);
void led_set_kb(uint8_t usb_led);

void api_send_unicode(uint32_t unicode);

#endif
