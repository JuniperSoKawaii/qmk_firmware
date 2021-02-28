#include <ctype.h>

#include "quantum.h"

#include "send_string.h"
#include "send_string_keycodes.h"

// clang-format off

/* Bit-Packed look-up table to convert an ASCII character to whether
 * [Shift] needs to be sent with the keycode.
 */
__attribute__((weak)) const uint8_t ascii_to_shift_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 1, 1, 1, 1, 1, 1, 0),
    KCLUT_ENTRY(1, 1, 1, 1, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 1, 0, 1, 0, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 0, 0, 0, 1, 1),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 1, 1, 1, 1, 0)
};

/* Bit-Packed look-up table to convert an ASCII character to whether
 * [AltGr] needs to be sent with the keycode.
 */
__attribute__((weak)) const uint8_t ascii_to_altgr_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0)
};

/* Bit-Packed look-up table to convert an ASCII character to whether
 * [Space] needs to be sent after the keycode
 */
__attribute__((weak)) const uint8_t ascii_to_dead_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0)
};

/* Look-up table to convert an ASCII character to a keycode.
 */
__attribute__((weak)) const uint8_t ascii_to_keycode_lut[128] PROGMEM = {
    // NUL   SOH      STX      ETX      EOT      ENQ      ACK      BEL
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // BS    TAB      LF       VT       FF       CR       SO       SI
    KC_BSPC, KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // DLE   DC1      DC2      DC3      DC4      NAK      SYN      ETB
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // CAN   EM       SUB      ESC      FS       GS       RS       US
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    //       !        "        #        $        %        &        '
    KC_SPC,  KC_1,    KC_QUOT, KC_3,    KC_4,    KC_5,    KC_7,    KC_QUOT,
    // (     )        *        +        ,        -        .        /
    KC_9,    KC_0,    KC_8,    KC_EQL,  KC_COMM, KC_MINS, KC_DOT,  KC_SLSH,
    // 0     1        2        3        4        5        6        7
    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,
    // 8     9        :        ;        <        =        >        ?
    KC_8,    KC_9,    KC_SCLN, KC_SCLN, KC_COMM, KC_EQL,  KC_DOT,  KC_SLSH,
    // @     A        B        C        D        E        F        G
    KC_2,    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
    // H     I        J        K        L        M        N        O
    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,
    // P     Q        R        S        T        U        V        W
    KC_P,    KC_Q,    KC_R,    KC_S,    KC_T,    KC_U,    KC_V,    KC_W,
    // X     Y        Z        [        \        ]        ^        _
    KC_X,    KC_Y,    KC_Z,    KC_LBRC, KC_BSLS, KC_RBRC, KC_6,    KC_MINS,
    // `     a        b        c        d        e        f        g
    KC_GRV,  KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
    // h     i        j        k        l        m        n        o
    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,
    // p     q        r        s        t        u        v        w
    KC_P,    KC_Q,    KC_R,    KC_S,    KC_T,    KC_U,    KC_V,    KC_W,
    // x     y        z        {        |        }        ~        DEL
    KC_X,    KC_Y,    KC_Z,    KC_LBRC, KC_BSLS, KC_RBRC, KC_GRV,  KC_DEL
};

// clang-format on

// Note: we bit-pack in "reverse" order to optimize loading
#define PGM_LOADBIT(mem, pos) ((pgm_read_byte(&((mem)[(pos) / 8])) >> ((pos) % 8)) & 0x01)

void send_string(const char *str) { send_string_with_delay(str, 0); }

void send_string_P(const char *str) { send_string_with_delay_P(str, 0); }

void send_string_with_delay(const char *str, uint8_t interval) {
    while (1) {
        char ascii_code = *str;
        if (!ascii_code) break;
        if (ascii_code == SS_QMK_PREFIX) {
            ascii_code = *(++str);
            if (ascii_code == SS_TAP_CODE) {
                // tap
                uint8_t keycode = *(++str);
                tap_code(keycode);
            } else if (ascii_code == SS_DOWN_CODE) {
                // down
                uint8_t keycode = *(++str);
                register_code(keycode);
            } else if (ascii_code == SS_UP_CODE) {
                // up
                uint8_t keycode = *(++str);
                unregister_code(keycode);
            } else if (ascii_code == SS_DELAY_CODE) {
                // delay
                int     ms      = 0;
                uint8_t keycode = *(++str);
                while (isdigit(keycode)) {
                    ms *= 10;
                    ms += keycode - '0';
                    keycode = *(++str);
                }
                while (ms--) wait_ms(1);
            }
        } else {
            send_char(ascii_code);
        }
        ++str;
        // interval
        {
            uint8_t ms = interval;
            while (ms--) wait_ms(1);
        }
    }
}

void send_string_with_delay_P(const char *str, uint8_t interval) {
    while (1) {
        char ascii_code = pgm_read_byte(str);
        if (!ascii_code) break;
        if (ascii_code == SS_QMK_PREFIX) {
            ascii_code = pgm_read_byte(++str);
            if (ascii_code == SS_TAP_CODE) {
                // tap
                uint8_t keycode = pgm_read_byte(++str);
                tap_code(keycode);
            } else if (ascii_code == SS_DOWN_CODE) {
                // down
                uint8_t keycode = pgm_read_byte(++str);
                register_code(keycode);
            } else if (ascii_code == SS_UP_CODE) {
                // up
                uint8_t keycode = pgm_read_byte(++str);
                unregister_code(keycode);
            } else if (ascii_code == SS_DELAY_CODE) {
                // delay
                int     ms      = 0;
                uint8_t keycode = pgm_read_byte(++str);
                while (isdigit(keycode)) {
                    ms *= 10;
                    ms += keycode - '0';
                    keycode = pgm_read_byte(++str);
                }
                while (ms--) wait_ms(1);
            }
        } else {
            send_char(ascii_code);
        }
        ++str;
        // interval
        {
            uint8_t ms = interval;
            while (ms--) wait_ms(1);
        }
    }
}

void send_char(char ascii_code) {
#if defined(AUDIO_ENABLE) && defined(SENDSTRING_BELL)
    if (ascii_code == '\a') {  // BEL
        PLAY_SONG(bell_song);
        return;
    }
#endif

    uint8_t keycode    = pgm_read_byte(&ascii_to_keycode_lut[(uint8_t)ascii_code]);
    bool    is_shifted = PGM_LOADBIT(ascii_to_shift_lut, (uint8_t)ascii_code);
    bool    is_altgred = PGM_LOADBIT(ascii_to_altgr_lut, (uint8_t)ascii_code);
    bool    is_dead    = PGM_LOADBIT(ascii_to_dead_lut, (uint8_t)ascii_code);

    if (is_shifted) {
        register_code(KC_LSFT);
    }
    if (is_altgred) {
        register_code(KC_RALT);
    }
    tap_code(keycode);
    if (is_altgred) {
        unregister_code(KC_RALT);
    }
    if (is_shifted) {
        unregister_code(KC_LSFT);
    }
    if (is_dead) {
        tap_code(KC_SPACE);
    }
}