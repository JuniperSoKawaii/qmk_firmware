#include "dz60.h"
#include <stdarg.h>
/* DZ60 layout using following options (from layouts diagram on KBDfans):
 *  - plate B (2.25u lshift)
 *  - opt 4 (1.75, 1, 1 on rshift)
 *  - opt 10 (2.75, 1.25, 2.25 on space, 5x1u bottom right keys)
 * http://www.keyboard-layout-editor.com/#/gists/225f0f4dcf6671405f744fabe314627c
 */

/* Features TODO:
 * Dynamic macros
 * Leader functions
 * Use a as CTRL+A+(kc) when held, a when tapped for ultimate integration with tmux
 *  - need to make inter-operable
 * Unicode leader commands??? (symbolic unicode)
 * Mac mode vs not: -probably bootmagic or use default with dynamic swap out here *    KC_MFFD(KC_MEDIA_FAST_FORWARD) and KC_MRWD(KC_MEDIA_REWIND) instead of KC_MNXT and KC_MPRV
 */

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#undef KEYMAP
#define KEYMAP( \
        K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, \
        K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
        K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
        K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310,       K312, K313, K314, \
        K400, K401,       K403,       K404, K406,       K408,       K410, K411, K412, K413, K414  \
        ) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, K014 }, \
    { K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
    { K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO }, \
    { K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  KC_NO, K312,  K313,  K314 }, \
    { K400,  K401,  KC_NO, K403,  K404,  KC_NO, K406,  KC_NO, K408,  KC_NO, K410,  K411,  K412,  K413,  K414 }  \
}

#define _______ KC_TRNS

// https://docs.qmk.fm/features/mouse-keys#configuring-the-behavior-of-mousekeys
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_INTERVAL     10
#define MOUSEKEY_MAX_SPEED    7
#define MOUSEKEY_TIME_TO_MAX  10
#define MOUSEKEY_WHEEL_DELAY  0

// TODO make this work because it doesn't seem to be redefining the symbol
#define TAPPING_TOGGLE  2

#define IS_MAC 1
#ifdef IS_MAC
#define MEDIA_FWD KC_MFFD
#define MEDIA_RWD KC_MRWD
#elif
#define MEDIA_FWD KC_MNXT
#define MEDIA_RWD KC_MPRV
#define
#endif

enum DZ60_B_4_10_Layers {
    L_Base,
    L_Fn,
    L_Nav,
    L_Num,
    L_RGB,
    L_None
};

enum function_id {
    SHIFT_ESC,
};

enum extra_keycodes {
    CTRL_A = SAFE_RANGE,
    CTRL_B,
    EN_CTRL_SHORTCUTS,
    TG_LAYER_RGB, // Toggle between standard RGB underglow, and RGB underglow to do layer indication
    TG_L0_RGB, // Toggle color on or off of layer0

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: basic qwerty */
    KEYMAP(
       // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------2.0-------|
            KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,      KC_BSPC,
       // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||----------------|
       //
       // |----1.5-----||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|----1.5-----|
             KC_TAB,      KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC,   KC_BSLS,
       // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
       //
       // |----1.75------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------2.25--------||
             KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,     KC_ENT,
       // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
       //
       // |------2.25--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||----1.75------|--------|--------||
               KC_LSHIFT,      KC_Z,    KC_X,    KC_C,    KC_V,    CTRL_B,  KC_N,    KC_M,   KC_COMM, KC_DOT,   SFT_T(KC_SLSH), KC_UP,  KC_HYPR,
       // |------------------|--------|--------|--------|--------|--------|--------|--------|--------|--------||--------------|--------|--------||
       //
       // |---1.25---|---1.25---||---1.25---||--------2.75----------||---1.25---|------2.25--------||--------|--------|--------|--------|--------|
             KC_MEH,    KC_LALT,    KC_LGUI,         KC_SPC,             TT(2),       MO(1),          TG(3),   MO(4),  KC_LEFT, KC_DOWN, KC_RGHT
       // |----------|----------||----------||----------------------||----------|------------------||--------|--------|--------|--------|--------|
          ),

    /* Layer 1: primary fn layer */
    KEYMAP(
            KC_GRV,   KC_F1,      KC_F2,          KC_F3,                KC_F4,            KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_DEL,
            KC_TAB,   KC_NO,      KC_HOME,        KC_UP,                KC_END,           KC_NO,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
            KC_CAPS,  KC_NO,      KC_LEFT,        KC_DOWN,              KC_RIGHT,         KC_NO,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_NO,    KC_NO,    KC_ENT,
            KC_LSFT,  MEDIA_RWD,  KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,    KC_AUDIO_VOL_UP,  MEDIA_FWD,  KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_LOCK,  KC_PGUP,  KC_INS,
            KC_MEH,   KC_LALT,    KC_LGUI,        KC_MEDIA_PLAY_PAUSE,  KC_TRNS,          KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_HOME,   KC_PGDN,    KC_END
          ),

    /* Layer 2: mouse navigation */
    KEYMAP(
            TO(0),      KC_MS_ACCEL0,  KC_MS_ACCEL1,  KC_MS_ACCEL2,  KC_NO,        KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,           KC_NO,   KC_NO,    KC_NO,  KC_NO,
            KC_NO,      KC_NO,         KC_MS_BTN2,    KC_MS_UP,      KC_MS_BTN1,   KC_NO,    KC_NO,          KC_NO,          KC_PGDN,      KC_PGUP,         KC_NO,   KC_NO,    KC_NO,  KC_NO,
            KC_LCTL,    KC_MS_BTN3,    KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,  KC_NO,    KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,  KC_MS_WH_RIGHT,  KC_NO,   KC_NO,    KC_NO,
            KC_LSHIFT,  KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,    KC_NO,          KC_NO,          KC_NO,        KC_NO,           KC_NO,   KC_TRNS,  KC_NO,
            KC_NO,      KC_NO,         KC_NO,         KC_MS_BTN1,    KC_TRNS,      KC_TRNS,  KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,         KC_TRNS
          ),

    /* Layer 3: numpad */
    KEYMAP(
            KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,           KC_NO,  KC_NO,  KC_NO,
            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS,  KC_KP_PLUS,      KC_NO,  KC_NO,  KC_NO,
            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_NO,  KC_NO,
            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_DOT,    KC_KP_ENTER,     KC_NO,  KC_NO,
            KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_KP_0,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,        KC_NO
          ),
    /* Layer 4: RGB lighting controls and keyboard config, reset */
    KEYMAP(
            KC_TRNS,            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    TG_L0_RGB,       KC_NO,             KC_NO,      TO(5),
            KC_NO,              KC_NO,  KC_NO,  KC_NO,  RESET,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,           KC_NO,             KC_NO,      RGB_HUD,
            EN_CTRL_SHORTCUTS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    TG_LAYER_RGB, RGB_MODE_PLAIN,  RGB_MODE_FORWARD,  KC_RSHIFT,
            KC_NO,              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    RGB_TOG,         RGB_VAI,           RGB_HUI,
            KC_NO,              KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,  RGB_SAD,  RGB_VAD,  RGB_SAI
          ),

    /* Layer 5: soft "off" state where none of the keystroke register */
    KEYMAP(
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO(0),
            KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
          ),
};

/* PP_NARG macro returns the number of arguments passed to it.
 * https://groups.google.com/forum/#!topic/comp.std.c/d-6Mj5Lko_s
 */
#define PP_NARG(...) PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_MAX_ARGS 64
#define PP_ARG_N( \
          _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
         _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
         _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
         _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
         _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
         _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
         _61,_62,_63,N,...) N
#define PP_RSEQ_N() 63,62,61,60,        \
         59,58,57,56,55,54,53,52,51,50, \
         49,48,47,46,45,44,43,42,41,40, \
         39,38,37,36,35,34,33,32,31,30, \
         29,28,27,26,25,24,23,22,21,20, \
         19,18,17,16,15,14,13,12,11,10, \
         9,8,7,6,5,4,3,2,1,0

#define send_keys(...) send_n_keys(PP_NARG(__VA_ARGS__), __VA_ARGS__)
static void send_n_keys(int n, ...) {
    uint8_t i = 0;
    uint16_t keycodes[PP_MAX_ARGS];
    va_list keys;
    va_start(keys, n);
    for (; i < n; ++i) {
        keycodes[i] = (uint16_t)va_arg(keys, int); // cast suppresses warning
        register_code(keycodes[i]);
    }
    for (; n > 0; --n) {
        unregister_code(keycodes[n-1]);
    }
    va_end(keys);
}
#define repeat_send_keys(n, ...) {for (int i=0; i < n; ++i) {send_keys(__VA_ARGS__);}}

#define _TIMEOUT_DELAY 150 // ms
static uint16_t idle_timer;
static bool timeout_is_active = false;

// state for the great state machine of custom actions!
static bool shortcuts_enabled = false;
static bool A_down = false;
static bool A_other_key = false;
static bool B_down = 0; // TODO just use top bit from count
static int8_t B_count = 0;
static bool rgb_layers_enabled = true;
static bool rgb_L0_enabled = false;

static inline void start_idle_timer(void);
static inline void clear_state_after_idle_timeout(void);

static inline void start_idle_timer(void) {
    idle_timer = timer_read();
    timeout_is_active = true;
}
static inline void clear_state_after_idle_timeout(void) {
    rgblight_sethsv_noeeprom(0x0, 0x00, 0x00);
    idle_timer = 0;
    timeout_is_active = false;
    // clear state here
    A_down = false;
    B_down = false; // TODO wait no??
    // send B
    repeat_send_keys(B_count, KC_B);
    B_count = 0;
}

inline void matrix_scan_user(void) {
    if (timeout_is_active && timer_elapsed(idle_timer) > _TIMEOUT_DELAY) {
        clear_state_after_idle_timeout();
    }
}

/* Return True to continue processing keycode, false to stop further processing */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_LAYER_RGB:
            rgb_layers_enabled ^= 1;
            return false;
        case TG_L0_RGB:
            rgb_L0_enabled ^= 1;
            return false;
        case EN_CTRL_SHORTCUTS:
            if (record->event.pressed) {
                shortcuts_enabled = !shortcuts_enabled;
                start_idle_timer();
            }
            return false;
        case CTRL_A:
            if (!shortcuts_enabled) {
                if (record->event.pressed) {
                    register_code(KC_A);
                }
                else {
                    unregister_code(KC_A);
                }
                return false;
            }
            if (record->event.pressed) {
                A_down = true;
            }
            else {
                if (! A_other_key) {
                    if (get_mods() & MODS_CTRL_MASK) {
                        send_keys(KC_RSHIFT, KC_A);
                    }
                    else {
                        send_keys(KC_A);
                    }
                }
                A_down = false;
                A_other_key = false;
            }
            return false;
        case CTRL_B:
            if (!shortcuts_enabled) {
                if (record->event.pressed) {
                    register_code(KC_B);
                }
                else {
                    unregister_code(KC_B);
                }
                return false;
            }
            B_down = record->event.pressed;
            if (B_down) {
                ++B_count;
                timeout_is_active = false;
            }
            else {
                if (B_count) {
                    start_idle_timer();
                }
            }
            return false;
        default:
            if (record->event.pressed) {
                if (A_down) {
                    send_keys(KC_LCTL, KC_A);
                    register_code(keycode);
                    A_other_key = true;
                    return false;
                }
                if (B_count) {
                    if (B_down) {
                        repeat_send_keys(B_count, KC_LCTL, KC_B);
                        B_count = 0;
                    }
                    else {
                        if (get_mods() & MODS_CTRL_MASK) {
                            repeat_send_keys(B_count, KC_RSHIFT, KC_B);
                        }
                        else {
                            repeat_send_keys(B_count, KC_B);
                        }
                        B_count = 0;
                    }
                }
            }
    }
    return true;
}

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    static uint8_t shift_esc_shift_mask;
    switch (id) {
        case SHIFT_ESC:
            shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
            if (record->event.pressed) {
                if (shift_esc_shift_mask) {
                    add_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    add_key(KC_ESC);
                    send_keyboard_report();
                }
            } else {
                if (shift_esc_shift_mask) {
                    del_key(KC_GRV);
                    send_keyboard_report();
                } else {
                    del_key(KC_ESC);
                    send_keyboard_report();
                }
            }
            break;
    }
}

#define  MAXBRIGHT    180
#define  OFF          0,    0,    0
#define  WHITE        0,    0,    MAXBRIGHT
#define  RED          0,    255,  MAXBRIGHT
#define  CORAL        16,   176,  MAXBRIGHT
#define  ORANGE       39,   255,  MAXBRIGHT
#define  GOLDENROD    43,   218,  218
#define  GOLD         51,   255,  MAXBRIGHT
#define  YELLOW       60,   255,  MAXBRIGHT
#define  CHARTREUSE   90,   255,  MAXBRIGHT
#define  GREEN        120,  255,  MAXBRIGHT
#define  SPRINGGREEN  150,  255,  MAXBRIGHT
#define  TURQUOISE    174,  90,   112
#define  TEAL         180,  255,  MAXBRIGHT
#define  CYAN         180,  255,  MAXBRIGHT
#define  AZURE        186,  102,  MAXBRIGHT
#define  BLUE         240,  255,  MAXBRIGHT
#define  PURPLE       270,  255,  MAXBRIGHT
#define  MAGENTA      300,  255,  MAXBRIGHT
#define  PINK         330,  128,  MAXBRIGHT

void matrix_init_user(void) {
    // called once on board init
    rgblight_enable();
}

void suspend_power_down_user(void) {
    // TODO shut off backlighting
}

void suspend_wakeup_init_user(void) {
    // TODO turn on backlighting
}


/* Use RGB underglow to indicate layer
 * https://docs.qmk.fm/reference/customizing-functionality
 */
uint32_t layer_state_set_user(uint32_t state) {
    if (!rgb_layers_enabled) {
        return state;
    }
    switch (biton32(state)) {
    case L_Base:
        if (rgb_L0_enabled) {
            rgblight_sethsv_noeeprom(PINK);
        }
        else {
            rgblight_sethsv_noeeprom(OFF);
        }
        break;
    case L_Fn:
        rgblight_sethsv_noeeprom(GREEN);
        break;
    case L_Nav:
        rgblight_sethsv_noeeprom(AZURE);
        break;
    case L_Num:
        rgblight_sethsv_noeeprom(GOLD);
        break;
    case L_RGB:
        rgblight_sethsv_noeeprom(RED);
        break;
    case L_None:
        rgblight_sethsv_noeeprom(WHITE);
        break;
    }
    return state;
}
