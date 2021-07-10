/**
 * Copyright (C) 2021 Jerrell, Jacob <@jjerrell>
 * 
 * This file is part of qmk_firmware.
 * 
 * qmk_firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * qmk_firmware is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jjerrell.h"

__attribute__((weak)) void matrix_scan_keymap(void) {}
void matrix_scan_user(void) {
    matrix_scan_keymap();
}


__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    state = layer_state_set_keymap(state);
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#if defined(RGBLIGHT_ENABLE)
    state = layer_state_set_rgb_light(state);
#endif  // RGBLIGHT_ENABLE
    return state;
}

__attribute__((weak)) void dip_switch_update_keymap(uint8_t index, bool active) {}
void dip_switch_update_user(uint8_t index, bool active) {
    dip_switch_update_keymap(index, active);
}

__attribute__((weak)) bool music_mask_keymap(uint16_t keycode) { return true; }
bool music_mask_user(uint16_t keycode) {
    switch (keycode){
        default:
            return music_mask_keymap(keycode);
            break;
    }
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

// Runs state check and changes underglow color and animation
layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    state = default_layer_state_set_keymap(state);
#if 0
#    if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
  state = default_layer_state_set_rgb(state);
#    endif  // RGBLIGHT_ENABLE
#endif
    return state;
}

#ifdef AUDIO_ENABLE

__attribute__((weak)) void startup_keymap(void) {}
void startup_user(void)
{
    _delay_ms(20); // gets rid of tick
    startup_keymap();
}

__attribute__((weak))  void shutdown_keymap(void) {}
void shutdown_user(void)
{
    _delay_ms(150);
    stop_all_notes();
    shutdown_keymap();
}

__attribute__((weak)) void music_on_keymap(void) {}
void music_on_user(void)
{
    music_scale_user();
    music_on_keymap();
}

__attribute__((weak)) void music_scale_keymap(void) {}
void music_scale_user(void)
{
    PLAY_SONG(music_scale);
    music_scale_keymap();
}

#endif