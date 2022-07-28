/* Copyright 2022 Christopher Swenson
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

enum planck_layers {
    _ENIGMA,
    _QWERTY,
    _FN,
    _LOWER,
    _RAISE
};

enum planck_normal_keycodes {
    QWERTY = SAFE_RANGE,
    ENIGMA,
    EN_A,
    EN_B,
    EN_C,
    EN_D,
    EN_E,
    EN_F,
    EN_G,
    EN_H,
    EN_I,
    EN_J,
    EN_K,
    EN_L,
    EN_M,
    EN_N,
    EN_O,
    EN_P,
    EN_Q,
    EN_R,
    EN_S,
    EN_T,
    EN_U,
    EN_V,
    EN_W,
    EN_X,
    EN_Y,
    EN_Z,
    EN_RES,
    EN_TEST,
    EN_DIAG,
    EN_BKSP,
    EN_SREF,
    EN_SROT,
    EN_SPOS,
    EN_SRIN,
    EN_SPLU
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Enigma
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |  Fn  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_ENIGMA] = LAYOUT_planck_mit(
        QK_GESC, EN_Q,    EN_W,    EN_E,    EN_R,       EN_T,    EN_Y, EN_U,       EN_I,    EN_O,    EN_P,    KC_BSPC,
        KC_TAB,  EN_A,    EN_S,    EN_D,    EN_F,       EN_G,    EN_H, EN_J,       EN_K,    EN_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, EN_Z,    EN_X,    EN_C,    EN_V,       EN_B,    EN_N, EN_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, MO(_LOWER),    KC_SPC,     MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |  Fn  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_mit(
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT, MO(_LOWER),    KC_SPC,       MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Function
    * ,-----------------------------------------------------------------------------------.
    * | Boot | Reset| Diag |      |      |      |      |      |      |      | Test |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |Reflec|Rotors|Posn.s|Rings |Plugs |      |      |Enigma|Qwerty|      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FN] = LAYOUT_planck_mit(
        QK_BOOT, EN_RES,  EN_DIAG, _______, _______, _______, _______, _______, _______, _______, EN_TEST, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, EN_SREF, EN_SROT, EN_SPOS, EN_SRIN, EN_SPLU, _______, _______, QWERTY,  ENIGMA,  _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
    ),
    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * | ~    |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |  Fn  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_mit(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, 
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
        KC_LSFT, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, 
        KC_LCTL, _______, KC_LGUI, KC_LALT, _______,       KC_SPC,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* RAISE
    * ,-----------------------------------------------------------------------------------.
    * | `    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |  Fn  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_mit(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, 
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        KC_LCTL, _______, KC_LGUI, KC_LALT, _______,      KC_SPC,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
};

void send_character(char letter) {
    char out[2];
    out[0] = letter;
    out[1] = 0;
    send_string((char *) &out);
}

char rotor_definitions[5][26] = {
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK" 
};

char reflector_definitions[3][26] = {
    "EJMZALYXVBWFCRQUONTSPIKHGD",
    "YRUHQSLDPXNGOKMIEBFZCWVJAT",
    "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};

char notch[5]="QEVJZ";

typedef struct Settings {
    char rotor_order[3];
    char rotor_rings[3];
    char rotor_positions[3];
    char plugs[25];
    int plug_count;
    char reflector;
} Settings;

int bound(int letter) {
    return ((letter % 26) + 26) % 26;
}

char to_char(int letter) {
    return 'A' + letter;
}

int to_int(char letter) {
    return letter - 'A';
}

char encipher(char letter, Settings *settings) {
    int rotor_2_step = settings->rotor_positions[2] == notch[settings->rotor_order[2] - 1];
    int rotor_1_step = settings->rotor_positions[1] == notch[settings->rotor_order[1] - 1];
      
    // Advance the third rotor
    settings->rotor_positions[2]++;
    if (settings->rotor_positions[2] > 'Z') {
      settings->rotor_positions[2] -= 26;
    }

    // Maybe advance the second rotor, including double steps
    if (rotor_2_step || rotor_1_step) {
        settings->rotor_positions[1]++;
        if (settings->rotor_positions[1] > 'Z') {
            settings->rotor_positions[1] -= 26;
        }
    }

    // Maybe advance the first rotor
    if (rotor_1_step) {
        settings->rotor_positions[0]++;
        if (settings->rotor_positions[0] > 'Z') {
            settings->rotor_positions[0] -= 26;
        }
    }

    // Swap letters on plugboard
    for (int i = 0; i < settings->plug_count * 2; i += 2) {
        if (letter == settings->plugs[i]) {
            letter = settings->plugs[i + 1];
        } else if (letter == settings->plugs[i + 1]) {
            letter = settings->plugs[i];
        }  
    }

    // Rotors (right to left)
    for (int rotor_index = 2; rotor_index >= 0; rotor_index--) {
        char *rotor_definition = rotor_definitions[settings->rotor_order[rotor_index] - 1];
        int position = to_int(settings->rotor_positions[rotor_index]);
        int ring = to_int(settings->rotor_rings[rotor_index]);
        int char_index = to_int(letter);
        letter = to_char(bound(
            to_int(rotor_definition[bound(char_index + position - ring)]) + ring - position
        ));
    }

    // Swap via reflector
    letter = reflector_definitions[to_int(settings->reflector)][to_int(letter)];

    // Rotors in reverse (left to right)
    for (int rotor_index = 0; rotor_index < 3; rotor_index++) {
        char *rotor_definition = rotor_definitions[settings->rotor_order[rotor_index] - 1];
        int position = to_int(settings->rotor_positions[rotor_index]);
        int ring = to_int(settings->rotor_rings[rotor_index]);
        int search_index;
        for (search_index = 0; search_index < 26; search_index++) {
            if (
                rotor_definition[search_index] 
                == to_char(bound(to_int(letter) - ring + position))
            ) {
                break;
            }
        }
        letter = to_char(bound(search_index - position + ring));
    }
    
    // Plugboard again
    for (int i = 0; i < settings->plug_count * 2; i += 2) {
        if (letter == settings->plugs[i]) {
            letter = settings->plugs[i + 1];
        } else if (letter == settings->plugs[i + 1]) {
            letter = settings->plugs[i];
        }
    }

    return letter;
}

void init_enigma_default(Settings *settings) {
    settings->rotor_order[0] = 1;
    settings->rotor_rings[0] = 'A';
    settings->rotor_positions[0] = 'A';

    settings->rotor_order[1] = 2;
    settings->rotor_rings[1] = 'A';
    settings->rotor_positions[1] = 'A';

    settings->rotor_order[2] =  3;
    settings->rotor_rings[2] = 'A';
    settings->rotor_positions[2] = 'A';

    strcpy(settings->plugs, "");
    settings->plug_count = 0;

    settings->reflector = 'B';
}

void copy_settings(Settings *from, Settings *to) {
    to->rotor_order[0] = from->rotor_order[0];
    to->rotor_rings[0] = from->rotor_rings[0];
    to->rotor_positions[0] = from->rotor_positions[0];

    to->rotor_order[1] = from->rotor_order[1];
    to->rotor_rings[1] = from->rotor_rings[1];
    to->rotor_positions[1] = from->rotor_positions[1];

    to->rotor_order[2] = from->rotor_order[2];
    to->rotor_rings[2] = from->rotor_rings[2];
    to->rotor_positions[2] = from->rotor_positions[2];

    strncpy(to->plugs, from->plugs, from->plug_count * 2);
    to->plug_count = from->plug_count;

    to->reflector = from->reflector;
}

Settings current_settings;
Settings default_settings;

void keyboard_pre_init_user(void) {
    init_enigma_default(&default_settings);
    init_enigma_default(&current_settings);
}

char *rotor_name(int rotor_number) {
    if (rotor_number == 1) {
      return "I";
    } else if (rotor_number == 2) {
      return "II";
    } else if (rotor_number == 3) {
      return "III";
    } else if (rotor_number == 4) {
      return "IV";
    } else if (rotor_number == 5) {
      return "V";
    }
    return "?";
}

void rotors_reverse(Settings *settings) {
    int rotor_2_step = settings->rotor_positions[2] 
        == to_char(bound(to_int(notch[settings->rotor_order[2] - 1]) + 1));
    int rotor_1_step = settings->rotor_positions[1] 
        == to_char(bound(to_int(notch[settings->rotor_order[1] - 1]) + 1));
      
    // Reverse third rotor
    settings->rotor_positions[2]--;
    if (settings->rotor_positions[2] < 'A') {
      settings->rotor_positions[2] += 26;
    }

    // Maybe reverse second rotor (including double steps)
    if (rotor_2_step || rotor_1_step) {
        settings->rotor_positions[1]--;
        if (settings->rotor_positions[1] < 'A') {
            settings->rotor_positions[1] += 26;
        }
    }

    // Maybe recerse first rotor
    if (rotor_1_step) {
        settings->rotor_positions[0]--;
        if (settings->rotor_positions[0] < 'A') {
            settings->rotor_positions[0] += 26;
        }
    }
}

bool setting_reflector = false;
bool setting_rotors = false;
bool setting_rotor_positions = false;
bool setting_rotor_rings = false;
bool setting_plugs = false;

char rotor_settings_progress[26];
char setting_rotor_n = 0;

void set_layer(uint8_t default_layer) {
    default_layer_set((layer_state_t)1 << default_layer);
}

bool cancel_setting(void) {
    setting_reflector = false;
    setting_rotors = false;
    setting_rotor_positions = false;
    setting_rotor_rings = false;
    setting_plugs = false;
    setting_rotor_n = 0;
    set_layer(_ENIGMA);
    #ifdef RGBLIGHT_ENABLE
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(HSV_RED);
    #endif
    return false;
}

bool save_setting(void) {
    copy_settings(&default_settings, &current_settings);
    return cancel_setting();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    char letter = 0;
    int normal_keycode = 0;
    if (record->event.pressed) {
        switch (keycode) {
          case QWERTY:
              set_layer(_QWERTY);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_sethsv_noeeprom(HSV_PURPLE);
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
              #endif
              break;
          case ENIGMA:
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                  rgblight_sethsv_noeeprom(HSV_RED);
              #endif
              break;
          case EN_SREF:
              copy_settings(&default_settings, &current_settings);
              setting_reflector = true;
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
                  rgblight_sethsv_noeeprom(HSV_RED);
              #endif
              break;
          case EN_SROT:
              copy_settings(&default_settings, &current_settings);
              setting_rotors = true;
              setting_rotor_n = 0;
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
                  rgblight_sethsv_noeeprom(10, 255, 255);
              #endif
              break;
          case EN_SPOS:
              copy_settings(&default_settings, &current_settings);
              setting_rotor_positions = true;
              setting_rotor_n = 0;
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
                  rgblight_sethsv_noeeprom(HSV_ORANGE);
              #endif
              break;
          case EN_SRIN:
              copy_settings(&default_settings, &current_settings);
              setting_rotor_rings = true;
              setting_rotor_n = 0;
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
                  rgblight_sethsv_noeeprom(HSV_GREEN);
              #endif
              break;
          case EN_SPLU:
              copy_settings(&default_settings, &current_settings);
              setting_plugs = true;
              setting_rotor_n = 0;
              set_layer(_ENIGMA);
              #ifdef RGBLIGHT_ENABLE
                  rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
                  rgblight_sethsv_noeeprom(HSV_BLUE);
              #endif
              break;
          case QK_GESC:
              if (
                  setting_reflector
                  || setting_rotors
                  || setting_rotor_positions
                  || setting_rotor_rings
                  || setting_plugs
              ) {
                  return cancel_setting();
              }
              break;
          case KC_ENT:
              if (setting_plugs) { 
                  default_settings.plug_count = setting_rotor_n / 2; 
                  for (int i = 0; i < default_settings.plug_count; i++) {
                      default_settings.plugs[i * 2] = rotor_settings_progress[i * 2];
                      default_settings.plugs[i * 2 + 1] = rotor_settings_progress[i * 2 + 1];
                  }
                  return save_setting();
              }
              break;
          case EN_A:
              letter = 'A';
              normal_keycode = KC_A;
              break;
          case EN_B:
              letter = 'B';
              normal_keycode = KC_B;
              break;
          case EN_C:
              letter = 'C';
              normal_keycode = KC_C;
              break;
          case EN_D:
              letter = 'D';
              normal_keycode = KC_D;
              break;
          case EN_E:
              letter = 'E';
              normal_keycode = KC_E;
              break;
          case EN_F:
              letter = 'F';
              normal_keycode = KC_F;
              break;
          case EN_G:
              letter = 'G';
              normal_keycode = KC_G;
              break;
          case EN_H:
              letter = 'H';
              normal_keycode = KC_H;
              break;
          case EN_I:
              letter = 'I';
              normal_keycode = KC_I;
              break;
          case EN_J:
              letter = 'J';
              normal_keycode = KC_J;
              break;
          case EN_K:
              letter = 'K';
              normal_keycode = KC_K;
              break;
          case EN_L:
              letter = 'L';
              normal_keycode = KC_L;
              break;
          case EN_M:
              letter = 'M';
              normal_keycode = KC_M;
              break;
          case EN_N:
              letter = 'N';
              normal_keycode = KC_N;
              break;
          case EN_O:
              letter = 'O';
              normal_keycode = KC_O;
              break;
          case EN_P:
              letter = 'P';
              normal_keycode = KC_P;
              break;
          case EN_Q:
              letter = 'Q';
              normal_keycode = KC_Q;
              break;
          case EN_R:
              letter = 'R';
              normal_keycode = KC_R;
              break;
          case EN_S:
              letter = 'S';
              normal_keycode = KC_S;
              break;
          case EN_T:
              letter = 'T';
              normal_keycode = KC_T;
              break;
          case EN_U:
              letter = 'U';
              normal_keycode = KC_U;
              break;
          case EN_V:
              letter = 'V';
              normal_keycode = KC_V;
              break;
          case EN_W:
              letter = 'W';
              normal_keycode = KC_W;
              break;
          case EN_X:
              letter = 'X';
              normal_keycode = KC_X;
              break;
          case EN_Y:
              letter = 'Y';
              normal_keycode = KC_Y;
              break;
          case EN_Z:
              letter = 'Z';
              normal_keycode = KC_Z;
              break;
          case EN_RES:
              copy_settings(&default_settings, &current_settings);
              break;
          case EN_TEST:
              for (int i = 0; i < 1000; i++) {
                  send_character(encipher('A', &current_settings) - ('A' - 'a'));
              }
              break;
          case EN_DIAG:
              send_character(current_settings.reflector);
              send_string(". ");
              send_string(rotor_name(current_settings.rotor_order[0]));
              send_character(current_settings.rotor_rings[0]);
              send_string("-");
              send_string(rotor_name(current_settings.rotor_order[1]));
              send_character(current_settings.rotor_rings[1]);
              send_string("-");
              send_string(rotor_name(current_settings.rotor_order[2]));
              send_character(current_settings.rotor_rings[2]);
              send_string(" (");
              send_character(current_settings.rotor_positions[0]);
              send_string(", ");
              send_character(current_settings.rotor_positions[1]);
              send_string(", ");
              send_character(current_settings.rotor_positions[2]);
              send_string(") ");
              for (int i = 0; i < current_settings.plug_count; i++) {
                  send_character(current_settings.plugs[i * 2]);
                  send_character(current_settings.plugs[i * 2 + 1]);
                  send_string(" ");
              }
              send_string("\n");
              break;
          case EN_BKSP:
              rotors_reverse(&current_settings);
              tap_code(KC_BSPC);
              break;
      }
    }
    int mods = get_mods();
    int any_mods = (mods & MOD_MASK_CTRL) || (mods & MOD_MASK_ALT) || (mods & MOD_MASK_GUI);
    if (letter > 0) {
      if (any_mods) {
        tap_code(normal_keycode);
      } else if (setting_reflector) {
        if (letter == 'A') {
          default_settings.reflector = 'A';
        } else if (letter == 'B') {
          default_settings.reflector = 'B';
        } else if (letter == 'C') {
          default_settings.reflector = 'C';
        }
        save_setting();
      } else if (setting_rotors) {
        if (letter >= 'A' && letter <= 'E' && setting_rotor_n < 3) {
          rotor_settings_progress[(int)setting_rotor_n] = to_int(letter) + 1;
          setting_rotor_n += 1;
          if (setting_rotor_n == 3) {
            default_settings.rotor_order[0] = rotor_settings_progress[0];
            default_settings.rotor_order[1] = rotor_settings_progress[1];
            default_settings.rotor_order[2] = rotor_settings_progress[2];
            save_setting();
          }
        } else {
          cancel_setting();
        }
      } else if (setting_rotor_positions) {
        if (setting_rotor_n < 3) {
          rotor_settings_progress[(int)setting_rotor_n] = letter;
          setting_rotor_n += 1;
          if (setting_rotor_n == 3) {
            default_settings.rotor_positions[0] = rotor_settings_progress[0];
            default_settings.rotor_positions[1] = rotor_settings_progress[1];
            default_settings.rotor_positions[2] = rotor_settings_progress[2];
            save_setting();
          }
        } else {
          cancel_setting();
        }
      } else if (setting_rotor_rings) {
        if (setting_rotor_n < 3) {
          rotor_settings_progress[(int)setting_rotor_n] = letter;
          setting_rotor_n += 1;
          if (setting_rotor_n == 3) {
            default_settings.rotor_rings[0] = rotor_settings_progress[0];
            default_settings.rotor_rings[1] = rotor_settings_progress[1];
            default_settings.rotor_rings[2] = rotor_settings_progress[2];
            save_setting();
          }
        } else {
          cancel_setting();
        }
      } else if (setting_plugs) {
        if (setting_rotor_n < 26) {
          rotor_settings_progress[(int)setting_rotor_n] = letter;
          setting_rotor_n += 1;
        } else {
          cancel_setting();
        }
      } else {
        char c2 = encipher(letter, &current_settings);
        send_character(c2 - ('A' - 'a'));
      }
    }
    return true;
}

void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom(); 
        rgblight_sethsv_noeeprom(HSV_PURPLE);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
    #endif
    set_layer(_QWERTY);
}

