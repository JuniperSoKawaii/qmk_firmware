#include QMK_KEYBOARD_H

#include "polykybd.h"
#include "split72/split72.h"
#include "print.h"
#include "base/disp_array.h"
#include "base/helpers.h"
#include "base/spi_helper.h"
#include "base/shift_reg.h"
#include "base/fonts/gfx_used_fonts.h"

#include "quantum/quantum_keycodes.h"
#include "version.h"
#include "print.h"

#include <transactions.h>

#include "lang/lang_lut.h"

#define FULL_BRIGHT 49
#define MIN_BRIGHT 1
#define DISP_OFF 0
#define BRIGHT_STEP 4

//6 sec
#define FADE_TRANSITION_TIME 6000
//1 min
#define FADE_OUT_TIME 60000
//20 min
#define TURN_OFF_TIME 1200000

/*[[[cog
import cog
import os
from openpyxl import load_workbook
wb = load_workbook(filename = os.path.join(os.path.abspath(os.path.dirname(cog.inFile)), "lang", "lang_lut.xlsx"))
sheet = wb['key_lut']

languages = []
lang_index = 0
lang_key = sheet["B1"].value
while lang_key:
    languages.append(lang_key)
    if lang_index==0:
        cog.outl(f"static enum lang_layer g_lang = {lang_key};")
    lang_index = lang_index + 1
    lang_key = sheet.cell(row = 1, column = 2 + lang_index*3).value
]]]*/
static enum lang_layer g_lang = LANG_EN;
//[[[end]]]

enum kb_layers { _L0 = 0x00, _BL=_L0, _L1 = 0x01, _L2 = 0x02, _FL0 = 0x03, _FL1 = 0x04, _NL = 0x05, _UL = 0x06, _LS = 0x07, _ADDLANG1 = 0x08};

enum my_keycodes {
    KC_LANG = SAFE_RANGE, KC_DECC, KC_INCC, KC_TOGBASE, KC_BASE, KC_L0, KC_L1, KC_L2, //KC_ADDLANG1,
    /*[[[cog
      for lang in languages:
          cog.out(f"KC_{lang}, ")
    ]]]*/
    KC_LANG_EN, KC_LANG_DE, KC_LANG_FR, KC_LANG_ES, KC_LANG_PT, KC_LANG_IT, KC_LANG_TR, KC_LANG_KO, KC_LANG_JA, KC_LANG_AR, KC_LANG_GR,
    //[[[end]]]
};

struct display_info {
    uint8_t bitmask[NUM_SHIFT_REGISTERS];
};

#define BITMASK1(x) .bitmask = {~0, ~0, ~0, ~0, (uint8_t)(~(1<<x))}
#define BITMASK2(x) .bitmask = {~0, ~0, ~0, (uint8_t)(~(1<<x)), ~0}
#define BITMASK3(x) .bitmask = {~0, ~0, (uint8_t)(~(1<<x)), ~0, ~0}
#define BITMASK4(x) .bitmask = {~0, (uint8_t)(~(1<<x)), ~0, ~0, ~0}
#define BITMASK5(x) .bitmask = {(uint8_t)(~(1<<x)), ~0, ~0, ~0, ~0}

struct display_info key_display[] = {
        {BITMASK1(0)}, {BITMASK1(1)}, {BITMASK1(2)}, {BITMASK1(3)}, {BITMASK1(4)}, {BITMASK1(5)}, {BITMASK1(6)}, {BITMASK1(7)},
        {BITMASK2(0)}, {BITMASK2(1)}, {BITMASK2(2)}, {BITMASK2(3)}, {BITMASK2(4)}, {BITMASK2(5)}, {BITMASK2(6)}, {BITMASK2(7)},
        {BITMASK3(0)}, {BITMASK3(1)}, {BITMASK3(2)}, {BITMASK3(3)}, {BITMASK3(4)}, {BITMASK3(5)}, {BITMASK3(6)}, {BITMASK3(7)},
        {BITMASK4(0)}, {BITMASK4(1)}, {BITMASK4(2)}, {BITMASK4(3)}, {BITMASK4(4)}, {BITMASK4(5)}, {BITMASK4(6)}, {BITMASK4(7)},
        {BITMASK5(0)}, {BITMASK5(1)}, {BITMASK5(2)}, {BITMASK5(3)}, {BITMASK5(4)}, {BITMASK5(5)}, {BITMASK5(6)}, {BITMASK5(7)}
};

struct display_info disp_row_0 = { BITMASK1(0) };
struct display_info disp_row_3 = { BITMASK4(0) };

enum refresh_mode { START_FIRST_HALF, START_SECOND_HALF, DONE_ALL, ALL_AT_ONCE };
static enum refresh_mode g_refresh = DONE_ALL;
static int8_t g_contrast = FULL_BRIGHT;
static layer_state_t g_default_ls = 0;
static uint16_t last_key = 0;
typedef struct _poly_sync_t {
    uint8_t lang;
    int8_t contrast;
    layer_state_t default_ls;
} poly_sync_t;

typedef struct _poly_state_t {
    led_t led_state;
    uint8_t mod_state;
    layer_state_t layer_state;
    poly_sync_t s;
} poly_state_t;

poly_state_t g_state;

static int32_t last_update;
static bool g_first_sync = false;

bool display_wakeup(keyrecord_t* record);
void update_displays(enum refresh_mode mode);
bool set_displays(int8_t contrast);
static int8_t old_contrast = 0;

void inc_brightness(void) {
    if (g_contrast < FULL_BRIGHT) {
        g_contrast += BRIGHT_STEP;
    }
    if (g_contrast > FULL_BRIGHT) {
        g_contrast = FULL_BRIGHT;
    }
}

void dec_brightness(void) {
    if (g_contrast > (MIN_BRIGHT+BRIGHT_STEP)) {
        g_contrast -= BRIGHT_STEP;
    } else {
        g_contrast = MIN_BRIGHT;
    }
}

void select_all_displays(void) {
    // make sure we are talking to all shift registers
    sr_shift_out_0_latch(NUM_SHIFT_REGISTERS);
}

void clear_all_displays(void) {
    select_all_displays();

    kdisp_set_buffer(0x00);
    kdisp_send_buffer();
}

void early_hardware_init_post(void) {
    spi_hw_setup();

}

void set_last_key(uint16_t keycode) {
    last_key = keycode;
}

void update_performed(void) {
    last_update = timer_read32();
}

layer_state_t persistent_default_layer_get(void) {
    return (layer_state_t)eeconfig_read_default_layer();
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void request_disp_refresh(void) {
    g_refresh = ALL_AT_ONCE;
    //use the following for partial update (during housekeeping)
    // g_refresh = START_FIRST_HALF;
}

void user_sync_poly_data_handler(uint8_t in_len, const void* in_data, uint8_t out_len, void* out_data) {
    if (in_len != 0 && in_data != NULL) {
        g_lang = ((poly_sync_t*)in_data)->lang;
        g_contrast = ((poly_sync_t*)in_data)->contrast;
        g_default_ls = ((poly_sync_t*)in_data)->default_ls;
    }
}

void sync_and_refresh_displays(void) {
    if (is_keyboard_master()) {
        //master syncs data
        if (!g_first_sync || g_lang != g_state.s.lang || g_contrast != g_state.s.contrast || g_default_ls != g_state.s.default_ls ){
            poly_sync_t send = { g_lang, g_contrast, g_default_ls};
            if (transaction_rpc_send(USER_SYNC_POLY_DATA, sizeof(send), &send)) {
                g_state.s.lang = g_lang;
                g_first_sync = true;
            }
        }
    }

    if (g_state.s.contrast != g_contrast && g_refresh == DONE_ALL) {
        bool need_refresh = set_displays(g_contrast);
        g_state.s.contrast = g_contrast;
        if (!is_keyboard_master() && need_refresh) {
            request_disp_refresh();
        }
    }

    led_t led_state = host_keyboard_led_state();
    uint8_t mod_state = get_mods();

    if (led_state.raw != g_state.led_state.raw ||
        mod_state != g_state.mod_state ||
        layer_state != g_state.layer_state ||
        g_state.s.lang != g_lang ||
        g_state.s.default_ls != g_default_ls) {

        g_state.led_state = host_keyboard_led_state();
        g_state.mod_state = get_mods();
        g_state.layer_state = layer_state;
        g_state.s.lang = g_lang;
        g_state.s.default_ls = g_default_ls;
        request_disp_refresh();
    }

    //split the update cycle
    if (g_refresh == START_FIRST_HALF) {
        update_displays(START_FIRST_HALF);
        g_refresh = START_SECOND_HALF;
    }
    else if (g_refresh == START_SECOND_HALF || g_refresh == ALL_AT_ONCE) {
        update_displays(g_refresh);
        g_refresh = DONE_ALL;
    }
}

void housekeeping_task_user(void) {
    sync_and_refresh_displays();

    //turn off displays
    uint32_t elapsed_time_since_update = timer_elapsed32(last_update);

    if (is_keyboard_master()) {
        if(elapsed_time_since_update > FADE_OUT_TIME && g_contrast >= MIN_BRIGHT) {
            int32_t time_after = elapsed_time_since_update - FADE_OUT_TIME;
            g_contrast = ((FADE_TRANSITION_TIME - time_after) * FULL_BRIGHT) / FADE_TRANSITION_TIME;

            //transition to pulsing mode
            if(g_contrast<=MIN_BRIGHT) {
                g_contrast = -MIN_BRIGHT;
            }
        } else if(elapsed_time_since_update > TURN_OFF_TIME) {
            g_contrast = DISP_OFF;
        } else if(g_contrast < MIN_BRIGHT) {
            int32_t time_after = PK_MAX(elapsed_time_since_update - FADE_OUT_TIME - FADE_TRANSITION_TIME, 0)/300;
            int8_t amplitude = time_after%14;
            if(amplitude>7) amplitude = 14-amplitude;

            if(amplitude>2) amplitude = amplitude-2;
            else if(amplitude==2) amplitude = 1;
            else amplitude = 0;

            g_contrast = -amplitude;
        }
    }
}
enum unicode_names {
    UM_A,
    UM_AC,
    UM_O,
    UM_OC,
    UM_U,
    UM_UC,
    SZ,
    SZC
};

const uint32_t unicode_map[] PROGMEM = {
    [UM_A]  = UMLAUT_A_SMALL[0],
    [UM_AC] = UMLAUT_A[0],
    [UM_O]  = UMLAUT_O_SMALL[0],
    [UM_OC] = UMLAUT_O[0],
    [UM_U]  = UMLAUT_U_SMALL[0],
    [UM_UC] = UMLAUT_U[0],
    [SZ]  = ESZETT[0],
    [SZC] = 0x1E9E
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //Base Layers
    [_L0] = LAYOUT_left_right_stacked(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_NUBS,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_GRAVE,
        MO(_FL0),   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_QUOTE,   KC_MS_BTN1,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NUHS,    MO(_NL),
        KC_LCTL,    KC_LWIN,    KC_LALT,    KC_APP,                 KC_SPACE,   KC_DEL,     KC_ENTER,

                    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL,
                    KC_HYPR,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,
        KC_NO,      KC_MEH,     KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_RBRC,
        KC_LANG,    KC_BSLS,    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSFT,
        KC_ENTER,   KC_BSPC,    KC_SPC,                 KC_LEFT,    KC_UP,      KC_DOWN,    KC_RIGHT
        ),
    [_L1] = LAYOUT_left_right_stacked(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_GRAVE,
        MO(_FL1),   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_QUOTE,   KC_MS_BTN1,
        KC_LSFT,    KC_NUHS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       MO(_NL),
        KC_LCTL,    KC_LWIN,    KC_LALT,    MO(_ADDLANG1),          KC_SPACE,   KC_DEL,     KC_ENTER,

                    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL,   KC_HYPR,
                    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_NUBS,
        KC_NO,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_RBRC,    KC_BSLS,
        KC_LANG,    KC_APP,     KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSFT,
        KC_ENTER,   KC_BSPC,    KC_SPC,                 KC_LEFT,    KC_UP,      KC_DOWN,    KC_RIGHT
        ),
    [_L2] = LAYOUT_left_right_stacked(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_NUBS,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_GRAVE,
        MO(_FL1),   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_QUOTE,   KC_MS_BTN1,
        KC_LSFT,    KC_NUHS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       MO(_NL),
        KC_LCTL,    KC_LWIN,    KC_LALT,    KC_APP,                 KC_SPACE,   KC_DEL,     KC_ENTER,

                    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL,
                    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    MO(_ADDLANG1),
        KC_NO,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_RBRC,    KC_BSLS,
        KC_LANG,    KC_HYPR,    KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_RSFT,
        KC_ENTER,   KC_BSPC,    KC_SPC,                 KC_LEFT,    KC_UP,      KC_DOWN,    KC_RIGHT
        ),
    //Function Layer (Fn)
    [_FL0] = LAYOUT_left_right_stacked(
        OSL(_UL),   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,     TO(_UL),
        KC_MS_BTN1, _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    KC_MS_BTN2,             _______,    _______,    _______,

                    KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,     KC_F12,
                    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        TO(_NL),    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,                KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END
        ),
    [_FL1] = LAYOUT_left_right_stacked(
        OSL(_UL),   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        KC_MS_BTN1, _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    KC_MS_BTN2,             _______,    _______,    _______,

                    KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,     KC_F12,    TO(_UL),
                    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_CAPS,
        TO(_NL),    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,                KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END
        ),
     //Num Layer
    [_NL] = LAYOUT_left_right_stacked(
        KC_NO,      KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,    KC_NO,      KC_NO,
        KC_MS_BTN1, KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,    KC_INS,     KC_NO,
        KC_NO,      KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PPLS,    KC_DEL,     KC_NO,     _______,
        KC_NO,      KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PENT,    KC_NO,      KC_NO,     _______,
        KC_BASE,    KC_KP_0,    KC_PDOT,    KC_PENT,                KC_MS_BTN2, KC_NO,     KC_NO,

                    KC_NO,      KC_NO,      KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,   KC_NO,
                    KC_NO,      KC_INS,     KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,   KC_NO,
        _______,    KC_NO,      KC_DEL,     KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PPLS,   KC_NO,
        _______,    _______,    KC_NO,      KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PENT,   KC_NO,
        _______,    KC_NO,      KC_NO,                  KC_KP_0,    KC_PDOT,    KC_PENT,   KC_BASE
        ),
    //Util Layer
    [_UL] = LAYOUT_left_right_stacked(
        KC_NO,      KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,
        KC_MYCM,    KC_CALC,    KC_PSCR,    KC_SCRL,    KC_BRK,     KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     _______,
        KC_NO,      KC_NO,      SH_TOGG,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     QK_DEBUG_TOGGLE,
        KC_BASE,    KC_INCC,    KC_NO,      KC_DECC,                QK_RBT,     QK_MAKE,   QK_BOOT,

                    KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,    KC_NO,
                    KC_MPRV,    KC_MPLY,    KC_MSTP,    KC_MNXT,    KC_MUTE,    KC_VOLD,   KC_VOLU,
        _______,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,     KC_NO,
        KC_NO,      KC_NO,      KC_TOGBASE, KC_L0,      KC_L1,      KC_L2,      KC_NO,     KC_NO,
        KC_NO,      KC_NO,      KC_NO,                  RGB_RMOD,   RGB_TOG,    RGB_MOD,   KC_BASE
        ),
    //Language Selection Layer
    [_LS] = LAYOUT_left_right_stacked(
                        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                        KC_NO,      KC_LANG_PT, KC_LANG_ES, KC_LANG_AR, KC_LANG_GR, KC_NO,      KC_NO,
        QK_UNICODE_MODE_WINCOMPOSE, KC_LANG_FR, KC_LANG_DE, KC_LANG_JA, KC_LANG_TR, KC_NO,      KC_NO,      KC_MS_BTN1,
        QK_UNICODE_MODE_EMACS,      KC_LANG_IT, KC_LANG_EN, KC_LANG_KO, KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_BASE,                    KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,

                    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      QK_UNICODE_MODE_MACOS,
                    KC_NO,      KC_LANG_GR, KC_LANG_AR, KC_LANG_ES, KC_LANG_PT, KC_NO,      QK_UNICODE_MODE_LINUX,
        _______,    KC_NO,      KC_LANG_TR, KC_LANG_JA, KC_LANG_DE, KC_LANG_FR, KC_NO,      QK_UNICODE_MODE_WINDOWS,
        KC_NO,      KC_NO,      KC_NO,      KC_LANG_KO, KC_LANG_EN, KC_LANG_IT, KC_NO,      QK_UNICODE_MODE_BSD,
        KC_NO,      KC_NO,      KC_NO,                  KC_NO,      KC_NO,      KC_NO,      KC_BASE
        ),
    [_ADDLANG1] = LAYOUT_left_right_stacked(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    XP(UM_A,UM_AC),   XP(SZ,SZC),    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,                _______,    _______,    _______,

                    _______,    _______,    _______,    _______,    _______,    _______,     _______,
                    _______,    XP(UM_U,UM_UC),    _______,    XP(UM_O,UM_OC),    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,                _______,    _______,    _______,    _______
        )
};


#define LX(x,y) ((x)/2),y
led_config_t g_led_config = { {// Key Matrix to LED Index
                              {6, 5, 4, 3, 2, 1, 0, NO_LED},
                              {13, 12, 11, 10, 9, 8, 7, NO_LED},
                              {20, 19, 18, 17, 16, 15, 14, NO_LED},
                              {27, 26, 25, 24, 23, 22, 21, NO_LED},
                              {35, 34, 33, 32, 31, 30, 29, 28},

                              {NO_LED, 42, 41, 40, 39, 38, 37, 36},
                              {NO_LED, 49, 48, 47, 46, 45, 44, 43},
                              {NO_LED, 56, 55, 54, 53, 52, 51, 50},
                              {NO_LED, 63, 62, 61, 60, 59, 58, 57},
                              {71, 70, 69, 68, 67, 66, 65, 64}
                             },
                             {
                                // LED Index to Physical Position
                                                {LX(144, 9)},   {LX(129, 9)},   {LX(104, 5)},   {LX(79, 1)},    {LX(55, 5)},    {LX(30, 9)},    {LX(0, 9)},
                                                {LX(144, 33)},  {LX(129, 33)},  {LX(104, 19)},  {LX(79, 25)},   {LX(55, 29)},   {LX(30, 33)},   {LX(0, 33)},
                                                {LX(144, 58)},  {LX(129, 58)},  {LX(104, 54)},  {LX(79, 50)},   {LX(55, 54)},   {LX(30, 58)},   {LX(0, 58)},
                                                {LX(144, 83)},  {LX(129, 83)},  {LX(104, 79)},  {LX(79, 75)},   {LX(55, 79)},   {LX(30, 83)},   {LX(0, 83)},
                {LX(170, 99)},  {LX(170, 127)}, {LX(144, 118)}, {LX(129, 113)},                 {LX(79, 99)},   {LX(55, 103)},  {LX(30, 107)},  {LX(6, 107)},

                                                {LX(446, 9)},   {LX(415, 9)},   {LX(390, 5)},   {LX(365, 1)},   {LX(341, 5)},   {LX(316, 9)},   {LX(286, 9)},
                                                {LX(446, 33)},  {LX(415, 33)},  {LX(390, 19)},  {LX(365, 25)},  {LX(341, 29)},  {LX(316, 33)},  {LX(286, 33)},
                                                {LX(446, 58)},  {LX(415, 58)},  {LX(390, 54)},  {LX(365, 50)},  {LX(341, 54)},  {LX(316, 58)},  {LX(286, 58)},
                                                {LX(446, 83)},  {LX(415, 83)},  {LX(390, 79)},  {LX(365, 75)},  {LX(341, 79)},  {LX(316, 83)},  {LX(286, 83)},
                                                {LX(440, 107)}, {LX(415, 107)}, {LX(390, 103)}, {LX(365, 99)},                  {LX(324, 113)}, {LX(290, 118)}, {LX(264, 127)},  {LX(264, 99)}
                             },
                             {
                                 // LED Index to Flag
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4, 4,

                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4, 4
                             } };

const uint16_t* get_led_matrix_text(void) {
    switch(rgb_matrix_get_mode()) {
        case RGB_MATRIX_SPLASH:
            return u"Sp";
        case RGB_MATRIX_MULTISPLASH:
            return u"SpMu";
        case RGB_MATRIX_SOLID_SPLASH:
            return u"SpSo";
        case RGB_MATRIX_SOLID_MULTISPLASH:
            return u"SpSM";
        case RGB_MATRIX_RAINBOW_MOVING_CHEVRON:
            return u"Rnbw";
        case RGB_MATRIX_BREATHING:
            return u"Brth";
        case RGB_MATRIX_SOLID_REACTIVE_SIMPLE:
            return u"Smpl";
        case RGB_MATRIX_SOLID_REACTIVE_CROSS:
            return u"Crss";
        case RGB_MATRIX_SOLID_REACTIVE:
            return u"Rctv";
        case RGB_MATRIX_SOLID_REACTIVE_WIDE:
            return u"RtWd";
        case RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE:
            return u"RtMW";
        case RGB_MATRIX_SOLID_REACTIVE_MULTICROSS:
            return u"RtMC";
        case RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS:
            return u"RtMN";
        case RGB_MATRIX_SOLID_REACTIVE_NEXUS:
            return u"RtNe";
        case RGB_MATRIX_ALPHAS_MODS:
            return u"AlpM";
        case RGB_MATRIX_GRADIENT_UP_DOWN:
            return u"GrUD";
        case RGB_MATRIX_GRADIENT_LEFT_RIGHT:
            return u"GrLR";
        case RGB_MATRIX_BAND_SAT:
            return u"BndS";
        case RGB_MATRIX_BAND_VAL:
            return u"BndV";
        case RGB_MATRIX_BAND_PINWHEEL_SAT:
            return u"BPwS";
        case RGB_MATRIX_BAND_PINWHEEL_VAL:
            return u"BPwV";
        case RGB_MATRIX_BAND_SPIRAL_SAT:
            return u"BSpS";
        case RGB_MATRIX_CYCLE_ALL:
            return u"All";
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:
            return u"CyLR";
        case RGB_MATRIX_CYCLE_UP_DOWN:
            return u"CyUD";
        case RGB_MATRIX_CYCLE_OUT_IN:
            return u"CyOI";
        case RGB_MATRIX_CYCLE_OUT_IN_DUAL:
            return u"CyDu";
        case RGB_MATRIX_CYCLE_PINWHEEL:
            return u"CyPw";
        case RGB_MATRIX_CYCLE_SPIRAL:
            return u"CySp";
        case RGB_MATRIX_DUAL_BEACON:
            return u"DuBc";
        case RGB_MATRIX_RAINBOW_BEACON:
            return u"RnBc";
        case RGB_MATRIX_RAINBOW_PINWHEELS:
            return u"RnPw";
        case RGB_MATRIX_RAINDROPS:
            return u"Rndp";
        case RGB_MATRIX_JELLYBEAN_RAINDROPS:
            return u"JRnp";
        case RGB_MATRIX_HUE_BREATHING:
            return u"HueB";
        case RGB_MATRIX_HUE_PENDULUM:
            return u"HueP";
        case RGB_MATRIX_HUE_WAVE:
            return u"HueW";
        case RGB_MATRIX_PIXEL_FRACTAL:
            return u"PxlF";
        case RGB_MATRIX_PIXEL_FLOW:
            return u"PxlF";
        case RGB_MATRIX_PIXEL_RAIN:
            return u"PxlR";
        default:
            return u"Unkn";
    }
}


const uint16_t* keycode_to_disp_text(uint16_t keycode, led_t state) {
    switch (keycode) {
    case QK_UNICODE_MODE_MACOS: return u"Mac";
    case QK_UNICODE_MODE_LINUX: return u"Lnx";
    case QK_UNICODE_MODE_WINDOWS: return u"Win";
    case QK_UNICODE_MODE_BSD: return u"BSD";
    case QK_UNICODE_MODE_WINCOMPOSE: return u"WCmp";
    case QK_UNICODE_MODE_EMACS: return u"Emcs";
    case QK_LEAD:
        return u"Lead";
    case KC_HYPR:
        return u"Hypr";
    case KC_MEH:
        return u"Meh";
    case KC_EXEC:
        return u"Exec";
    case KC_NUM_LOCK:
        return !state.num_lock ? u"Nm" ICON_NUMLOCK_OFF : u"Nm" ICON_NUMLOCK_ON;
    case KC_KP_SLASH:
        return u"/";
    case KC_KP_ASTERISK:
    case KC_KP_MINUS:
        return u"-";
    case KC_KP_7:
        return !state.num_lock ? ARROWS_LEFTSTOP : u"7";
    case KC_KP_8:
        return !state.num_lock ? u"   " ICON_UP : u"8";
    case KC_KP_9:
        return !state.num_lock ? ARROWS_UPSTOP : u"9";
    case KC_KP_PLUS:
        return u"+";
    case KC_KP_4:
        return !state.num_lock ? u"  " ICON_LEFT : u"4";
    case KC_KP_5:
        return !state.num_lock ? u"" : u"5";
    case KC_KP_6:
        return !state.num_lock ? u"  " ICON_RIGHT : u"6";
    case KC_KP_EQUAL:
        return u"=";
    case KC_KP_1:
        return !state.num_lock ? ARROWS_RIGHTSTOP : u"1";
    case KC_KP_2:
        return !state.num_lock ? u"   " ICON_DOWN : u"2";
    case KC_KP_3:
        return !state.num_lock ? ARROWS_DOWNSTOP : u"3";
    case KC_CALCULATOR:
        return u"   " PRIVATE_CALC;
    case KC_KP_0:
        return !state.num_lock ? u"Ins" : u"0";
    case KC_KP_DOT:
        return !state.num_lock ? u"Del" : u".";
    case KC_KP_ENTER:
        return u"Enter";
    case QK_BOOTLOADER:
        return u"Boot";
    case QK_DEBUG_TOGGLE:
        return debug_enable==0? u"Dbg\r\v" ICON_SWITCH_OFF : u"Dbg\r\v" ICON_SWITCH_ON;
    case RGB_RMOD:
        return u"RGB\v" ICON_LEFT;
    case RGB_TOG:
        return get_led_matrix_text();
    case RGB_MOD:
        return u"RGB\v" ICON_RIGHT;
    case KC_MEDIA_NEXT_TRACK:
        return ICON_RIGHT ICON_RIGHT;
    case KC_MEDIA_PLAY_PAUSE:
        return u"  " ICON_RIGHT;
    case KC_MEDIA_STOP:
        return u"Stop";
    case KC_MEDIA_PREV_TRACK:
        return ICON_LEFT ICON_LEFT;
    case KC_MS_ACCEL0:
        return u">>";
    case KC_MS_ACCEL1:
        return u">>>";
    case KC_MS_ACCEL2:
        return u">>>>";
    case KC_MS_BTN1:
        return u"  " ICON_LMB;
    case KC_MS_BTN2:
        return u"  " ICON_RMB;
    case KC_MS_BTN3:
        return u"  " ICON_MMB;
    case KC_MS_UP:
        return u"  " ICON_UP;
    case KC_MS_DOWN:
        return u"  " ICON_DOWN;
    case KC_MS_LEFT:
        return u"  " ICON_LEFT;
    case KC_MS_RIGHT:
        return u"  " ICON_RIGHT;
    case KC_AUDIO_MUTE:
        return u"  " PRIVATE_MUTE;
    case KC_AUDIO_VOL_DOWN:
        return u"  " PRIVATE_VOL_DOWN;
    case KC_AUDIO_VOL_UP:
        return u"  " PRIVATE_VOL_UP;
    case KC_PRINT_SCREEN:
        return u"  " PRIVATE_SCREEN;
    case KC_SCROLL_LOCK:
        return u"ScLk";
    case KC_PAUSE:
        return u"Paus";
    case KC_INSERT:
        return u"Ins";
    case KC_HOME:
        return ARROWS_LEFTSTOP;
    case KC_END:
        return u"   " ARROWS_RIGHTSTOP;
    case KC_PAGE_UP:
        return u"  " ARROWS_UPSTOP;
    case KC_PAGE_DOWN:
        return u"  " ARROWS_DOWNSTOP;
    case KC_DELETE:
        return TECHNICAL_ERASERIGHT;
    case KC_MYCM:
        return u"  " PRIVATE_PC;
    case MO(_FL0):
    case MO(_FL1):
        return u"Fn\r\v\t" ICON_LAYER;
    case TO(_NL):
        return u"Nm\r\v\t" ICON_LAYER;
    case MO(_NL):
        return u"Nm!\r\v\t" ICON_LAYER;
    case KC_BASE:
        return u"Base\r\v\t" ICON_LAYER;
    case KC_TOGBASE:
        return u"TgBL\r\v\t" ICON_LAYER;
    case KC_L0:
        return g_default_ls==_L0 ? u"BL 0" ICON_LAYER u"\r\v" ICON_SWITCH_ON : u"BL 0" ICON_LAYER u"\r\v" ICON_SWITCH_OFF;
    case KC_L1:
        return g_default_ls==_L1 ? u"BL 1" ICON_LAYER u"\r\v" ICON_SWITCH_ON : u"BL 0" ICON_LAYER u"\r\v" ICON_SWITCH_OFF;
    case KC_L2:
        return g_default_ls==_L2 ? u"BL 2" ICON_LAYER u"\r\v" ICON_SWITCH_ON : u"BL 0" ICON_LAYER u"\r\v" ICON_SWITCH_OFF;
    case OSL(_UL):
        return u"Util*\r\v\t" ICON_LAYER;
    case TO(_UL):
        return u"Util\r\v\t" ICON_LAYER;
    case MO(_ADDLANG1):
        return u"Intl";
    case KC_F1: return u" F1";
    case KC_F2: return u" F2";
    case KC_F3: return u" F3";
    case KC_F4: return u" F4";
    case KC_F5: return u" F5";
    case KC_F6: return u" F6";
    case KC_F7: return u" F7";
    case KC_F8: return u" F8";
    case KC_F9: return u" F9";
    case KC_F10:return u" F10";
    case KC_F11:return u" F11";
    case KC_F12:return u" F12";
    case KC_F13:return u" F13";
    case KC_F14:return u" F14";
    case KC_F15:return u" F15";
    case KC_F16:return u" F16";
    case KC_F17:return u" F17";
    case KC_F18:return u" F18";
    case KC_F19:return u" F19";
    case KC_F20:return u" F20";
    case KC_F21:return u" F21";
    case KC_F22:return u" F22";
    case KC_F23:return u" F23";
    case KC_F24:return u" F24";
    case KC_LEFT_CTRL:
    case KC_RIGHT_CTRL:
        return TECHNICAL_COMMAND;
    case KC_LEFT_ALT:
        return TECHNICAL_OPTION;
    case KC_RIGHT_ALT:
        return u"AltGr";
    case KC_LWIN:
    case KC_RWIN:
        return  DINGBAT_BLACK_DIA_X;
    case KC_LEFT:
        return u"  " ICON_LEFT;
    case KC_RIGHT:
        return u"  " ICON_RIGHT;
    case KC_UP:
        return u"  " ICON_UP;
    case KC_DOWN:
        return u"  " ICON_DOWN;
    case KC_CAPS_LOCK:
        return state.caps_lock ? u"Cap" ICON_CAPSLOCK_ON : u"Cap" ICON_CAPSLOCK_OFF;
    case KC_LSFT:
    case KC_RSFT:
        return u" " ICON_SHIFT;
    case KC_NO:
        return u"";
    case KC_DECC:
        return u" -";
    case KC_INCC:
        return u" +";
    case KC_LANG:
        return PRIVATE_WORLD;
    case SH_TOGG:
        return u"SwpH";
    case QK_MAKE:
        return u"Make";
    case QK_REBOOT:
        return u"Rst";
        /*[[[cog
            for lang in languages:
                short = lang.split("_")[1]
                cog.outl(f'case KC_{lang}: return g_lang == {lang} ? u"[{short}]" : u" {short}";')
        ]]]*/
        case KC_LANG_EN: return g_lang == LANG_EN ? u"[EN]" : u" EN";
        case KC_LANG_DE: return g_lang == LANG_DE ? u"[DE]" : u" DE";
        case KC_LANG_FR: return g_lang == LANG_FR ? u"[FR]" : u" FR";
        case KC_LANG_ES: return g_lang == LANG_ES ? u"[ES]" : u" ES";
        case KC_LANG_PT: return g_lang == LANG_PT ? u"[PT]" : u" PT";
        case KC_LANG_IT: return g_lang == LANG_IT ? u"[IT]" : u" IT";
        case KC_LANG_TR: return g_lang == LANG_TR ? u"[TR]" : u" TR";
        case KC_LANG_KO: return g_lang == LANG_KO ? u"[KO]" : u" KO";
        case KC_LANG_JA: return g_lang == LANG_JA ? u"[JA]" : u" JA";
        case KC_LANG_AR: return g_lang == LANG_AR ? u"[AR]" : u" AR";
        case KC_LANG_GR: return g_lang == LANG_GR ? u"[GR]" : u" GR";
        //[[[end]]]
    case KC_LNG1:
        return u"Han/Y";
    case KC_APP:
        return u" Ctx";
    default:
    {
        bool shift = ((get_mods() & MOD_MASK_SHIFT) != 0);
        const uint16_t* text = translate_keycode(g_lang, keycode, shift, state.caps_lock);
        if (text != NULL) {
            return text;
        }
    }
    break;
    }
    return NULL;
}

const uint16_t* keycode_to_disp_overlay(uint16_t keycode, led_t state) {
    switch (keycode)
    {
        case KC_F2: return u"      " PRIVATE_NOTE;
        case KC_F5: return u"     " ARROWS_CIRCLE;
        case QK_DEBUG_TOGGLE: return debug_enable==0 ? u"\v" ICON_SWITCH_OFF : u"\v" ICON_SWITCH_ON;
        case RGB_TOG: return rgb_matrix_is_enabled() ? u"\v" ICON_SWITCH_ON : u"\v" ICON_SWITCH_OFF;
        default: break;
    }

    if( (get_mods() & MOD_MASK_CTRL) != 0) {
        switch(keycode) {
            case KC_A: return u"    " BOX_WITH_CHECK_MARK;
            case KC_C: return u"   " CLIPBOARD_COPY;
            case KC_D: return u"    " PRIVATE_DELETE;
            case KC_F: return u"   " PRIVATE_FIND;
            case KC_X: return u"    " CLIPBOARD_CUT;
            case KC_V: return u"    " CLIPBOARD_PASTE;
            case KC_S: return u"    " PRIVATE_FLOPPY;
            case KC_O: return u"     " FILE_OPEN;
            case KC_P: return u"    " PRIVATE_PRINTER;
            case KC_Z: return u"    " ARROWS_UNDO;
            case KC_Y: return u"    " ARROWS_REDO;
            default: break;
        }
    } else if((get_mods() & MOD_MASK_GUI) != 0) {
        switch(keycode) {
            case KC_D:      return u"    " PRIVATE_SCREEN;
            case KC_L:      return u"    " PRIVATE_LOCK;
            case KC_UP:     return u"     " PRIVATE_MAXIMIZE;
            case KC_DOWN:   return u"     " PRIVATE_WINDOW;
            default: break;
        }
    }
    return NULL;
}


void update_displays(enum refresh_mode mode) {
    uint8_t layer = get_highest_layer(layer_state);
    /*if (layer > _LS) {
        layer = g_default_ls;
    }*/

    led_t state = host_keyboard_led_state();
    bool capital_case = ((get_mods() & MOD_MASK_SHIFT) != 0) || state.caps_lock;
    //the left side has an offset of 0, the right side an offset of MATRIX_ROWS_PER_SIDE
    uint8_t offset = is_keyboard_left() ? 0 : MATRIX_ROWS_PER_SIDE;
    uint8_t start_row = 0;

    //select first display (and later on shift that 0 till the end)
    if (mode == START_SECOND_HALF) {
        sr_shift_out_buffer_latch(disp_row_3.bitmask, sizeof(struct display_info));
        start_row = 3;
    }
    else {
        sr_shift_out_buffer_latch(disp_row_0.bitmask, sizeof(struct display_info));
    }

    uint8_t max_rows = mode == START_FIRST_HALF ? 3 : MATRIX_ROWS_PER_SIDE;

    uint8_t skip = 0;
    for (uint8_t r = start_row; r < max_rows; ++r) {
        for (uint8_t c = 0; c < MATRIX_COLS; ++c) {
            uint8_t  disp_idx = LAYOUT_TO_INDEX(r, c);

            //since MATRIX_COLS==8 we don't need to shift multiple times at the end of the row
            //except there was a leading and missing physical key (KC_NO on base layer)
            uint16_t keycode = keymaps[_BL][r + offset][c];
            if (keycode == KC_NO) {
                skip++;
            }
            else {
                if (disp_idx != 255) {
                    keycode = keymaps[layer][r + offset][c];
                    if(keycode!=KC_TRNS) {
                        const uint16_t* text = keycode_to_disp_text(keycode, state);
                        kdisp_set_buffer(0x00);
                        if(text==NULL){
                            if((keycode&QK_UNICODEMAP_PAIR)!=0){
                                uint16_t chr = capital_case ? QK_UNICODEMAP_PAIR_GET_SHIFTED_INDEX(keycode) : QK_UNICODEMAP_PAIR_GET_UNSHIFTED_INDEX(keycode);
                                kdisp_write_gfx_char(ALL_FONTS, sizeof(ALL_FONTS) / sizeof(GFXfont*), 28, 22, unicode_map[chr]);
                            }
                        } else {
                            kdisp_write_gfx_text(ALL_FONTS, sizeof(ALL_FONTS) / sizeof(GFXfont*), 28, 22, text);
                        }
                        text = keycode_to_disp_overlay(keycode, state);
                        if(text!=NULL) {
                            kdisp_write_gfx_text(ALL_FONTS, sizeof(ALL_FONTS) / sizeof(GFXfont*), 28, 22, text);
                        }
                        kdisp_send_buffer();
                    }
                }
                sr_shift_once_latch();
            }

        }
        for (;skip > 0;skip--) {
            sr_shift_once_latch();
        }
    }
}

void display_message(uint8_t row, uint8_t col, const uint16_t* message, const GFXfont* font) {

    const GFXfont* displayFont[] = { font };
    uint8_t index = 0;
    for (uint8_t c = 0; c < MATRIX_COLS; ++c) {

        uint8_t disp_idx = LAYOUT_TO_INDEX(row, c);

        if (disp_idx != 255) {

            sr_shift_out_buffer_latch(key_display[disp_idx].bitmask, sizeof(key_display->bitmask));
            kdisp_set_buffer(0x00);

            if (c >= col && message[index] != 0) {
                const uint16_t text[2] = { message[index], 0 };
                kdisp_write_gfx_text(displayFont, 1, 49, 38, text);
                index++;
            }
            kdisp_send_buffer();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
        case QK_BOOTLOADER:
            //uprintf("Enter Bootloader...");
            clear_all_displays();
            display_message(1, 1, u"BOOT-", &FreeSansBold24pt7b);
            display_message(3, 0, u"LOADER!", &FreeSansBold24pt7b);
            break;
        }
    }

    return display_wakeup(record);
}




void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode == KC_CAPS_LOCK) {
        request_disp_refresh();
    }

    if (!record->event.pressed) {
        switch (keycode) {
        case KC_L0:
            g_default_ls = _L0;
            persistent_default_layer_set(g_default_ls);
            request_disp_refresh();
            break;
        case KC_L1:
            g_default_ls = _L1;
            persistent_default_layer_set(g_default_ls);
            request_disp_refresh();
            break;
        case KC_L2:
            g_default_ls = _L2;
            persistent_default_layer_set(g_default_ls);
            request_disp_refresh();
            break;
        case KC_TOGBASE:
            g_default_ls = (g_default_ls==_L0) ? _L1 : (g_default_ls==_L1) ? _L2 : _L0;
            persistent_default_layer_set(g_default_ls);
            request_disp_refresh();
            break;
        case KC_BASE:
            layer_clear();
            layer_on(g_default_ls);
            break;
        case KC_RIGHT_SHIFT:
        case KC_LEFT_SHIFT:
            request_disp_refresh();
            break;
        case KC_DECC:
            dec_brightness();
            break;
        case KC_INCC:
            inc_brightness();
            break;
            /*[[[cog
            for lang in languages:
                cog.outl(f'case KC_{lang}: g_lang = {lang}; layer_off(_LS); break;')
            ]]]*/
            case KC_LANG_EN: g_lang = LANG_EN; layer_off(_LS); break;
            case KC_LANG_DE: g_lang = LANG_DE; layer_off(_LS); break;
            case KC_LANG_FR: g_lang = LANG_FR; layer_off(_LS); break;
            case KC_LANG_ES: g_lang = LANG_ES; layer_off(_LS); break;
            case KC_LANG_PT: g_lang = LANG_PT; layer_off(_LS); break;
            case KC_LANG_IT: g_lang = LANG_IT; layer_off(_LS); break;
            case KC_LANG_TR: g_lang = LANG_TR; layer_off(_LS); break;
            case KC_LANG_KO: g_lang = LANG_KO; layer_off(_LS); break;
            case KC_LANG_JA: g_lang = LANG_JA; layer_off(_LS); break;
            case KC_LANG_AR: g_lang = LANG_AR; layer_off(_LS); break;
            case KC_LANG_GR: g_lang = LANG_GR; layer_off(_LS); break;
            //[[[end]]]
        case KC_F1:case KC_F2:case KC_F3:case KC_F4:case KC_F5:case KC_F6:
        case KC_F7:case KC_F8:case KC_F9:case KC_F10:case KC_F11:case KC_F12:
            layer_off(_LS);
            break;
        default:
            break;
        }
    }
    else {
        switch (keycode)
        {
        case KC_RIGHT_SHIFT:
        case KC_LEFT_SHIFT:
            request_disp_refresh();
            break;
        case KC_LANG:
            if (IS_LAYER_ON(_LS)) {
                g_lang = (g_lang + 1) % NUM_LANG;
                layer_off(_LS);
            }
            else {
                layer_on(_LS);
            }
            break;
        case RGB_TOG:
        case RGB_MOD:
        case RGB_RMOD:
            request_disp_refresh();
            break;
        case QK_DEBUG_TOGGLE:
            if (!debug_enable) {
                debug_enable = 1;
            } else if (!debug_keyboard) {
                debug_keyboard = 1;
            } else if (!debug_matrix) {
                debug_matrix = 1;
            } else {
                debug_enable   = 0;
                debug_keyboard = 0;
                debug_matrix   = 0;
            }
            dprintf("DEBUG: enable=%u, keyboard=%u, matrix=%u\n", debug_enable, debug_keyboard, debug_matrix);
            dprint(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE "\n");
            eeconfig_update_debug(debug_config.raw);
            break;
        default:
            break;
        }
    }

    //uprintf("Key 0x%04X, col/row: %u/%u, %s, time: %u, int: %d, cnt: %u disp#: %d 0x%02X%02X%02X%02X%02X\n",
     //   keycode, record->event.key.col, record->event.key.row, record->event.pressed ? "DN" : "UP",
     //   record->event.time, record->tap.interrupted ? 1 : 0, record->tap.count, disp_idx, bitmask[4], bitmask[3], bitmask[2], bitmask[1], bitmask[0]);

    update_performed();
};

void show_splash_screen(void) {
    clear_all_displays();
    display_message(1, 1, u"POLY", &FreeSansBold24pt7b);
    display_message(2, 1, u"KYBD", &FreeSansBold24pt7b);
}

bool set_displays(int8_t contrast) {
    bool need_refresh = false;
    select_all_displays();

    if (old_contrast <= DISP_OFF && contrast > DISP_OFF) {
        kdisp_scroll(false);
        kdisp_enable(true);
        need_refresh = true;
        dprint("Displays on, stop scrolling.\n");
    } else if (old_contrast > DISP_OFF && contrast <= DISP_OFF) {
        kdisp_scroll(true);
        dprint("Enable scrolling.\n");
    } else if(old_contrast == DISP_OFF && g_contrast!= DISP_OFF) {
        kdisp_enable(true);
        dprint("Displays on, keep going.\n");
    }

    int8_t corrected_contrast = PK_ABS(contrast);

    if (contrast == DISP_OFF) {
        kdisp_enable(false);
        dprint("Displays off.\n");
    } else if(old_contrast != contrast) {
        kdisp_set_contrast(corrected_contrast - 1);
    }
    old_contrast = contrast;
    return need_refresh;
}

//disable first keypress if the displays are turned off
bool display_wakeup(keyrecord_t* record) {
    bool accept_keypress = true;
    if (g_contrast < MIN_BRIGHT && record->event.pressed) {
        if(g_contrast==DISP_OFF) {
            accept_keypress = timer_elapsed32(last_update) <= TURN_OFF_TIME;
        }
        g_contrast = FULL_BRIGHT; //not always full bright, but the set value
        update_performed();
        request_disp_refresh();
    }

    return accept_keypress;
}
void keyboard_post_init_user(void) {
    //rgb_matrix_disable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_CROSS);
    rgb_matrix_enable_noeeprom();

    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = false;
    debug_keyboard = false;
    debug_mouse = false;

    //pointing_device_set_cpi(20000);
    //pointing_device_set_cpi(2000);
    //pimoroni_trackball_set_rgbw(0,0,255,100);
    g_default_ls = persistent_default_layer_get();
    layer_clear();
    layer_on(g_default_ls);
    dprintf("PolyKybd ready.");

    wait_ms(500);
    transaction_register_rpc(USER_SYNC_POLY_DATA, user_sync_poly_data_handler);
}

void keyboard_pre_init_user(void) {
    kdisp_hw_setup();
    kdisp_init(NUM_SHIFT_REGISTERS);
    peripherals_reset();
    kdisp_setup(true);

    select_all_displays();
    kdisp_scroll_vlines(47);
    kdisp_scroll_modehv(true, 3, 1);
    kdisp_scroll(false);


    set_displays(FULL_BRIGHT);
    show_splash_screen();

    setPinInputHigh(I2C1_SDA_PIN);
}


bool oled_task_user(void) {
    char buffer[32];

    led_t led_state = host_keyboard_led_state();
    snprintf(buffer, sizeof(buffer), "Layer: %d %s %s %s",
        get_highest_layer(layer_state),
        led_state.num_lock ? "NUM" : "[ ]",
        led_state.caps_lock ? "CAP" : "[ ]",
        led_state.scroll_lock ? "SCR" : "[ ]"
    );
    oled_write(buffer, false);

    snprintf(buffer, sizeof(buffer), "\nLast Key: 0x%04x", last_key);
    oled_write(buffer, false);

    snprintf(buffer, sizeof(buffer), "\nRGB:%2d", rgb_matrix_get_mode());
    oled_write(buffer, false);

    snprintf(buffer, sizeof(buffer), "\n%s %s", is_keyboard_master() ? "USB-Host" : "Bridge", is_keyboard_left() ? "LEFT" : "RIGHT");

    oled_write(buffer, false);

    oled_set_cursor(0, 4);
    static const char PROGMEM raw_logo[] = { 0x80, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0xff, 0xff, 0x00, 0xef, 0xef, 0xef, 0xf0, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xf8, 0xf7, 0xf7, 0x07, 0xf7, 0xf8, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
                                            0x01, 0x03, 0x02, 0x03, 0x73, 0x73, 0x63, 0x03, 0x73, 0x61, 0x30, 0x01, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x01, 0x00, 0x01, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x01, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x03, 0xff, 0xff, 0x00, 0xcf, 0xdf, 0x2f, 0xf0, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x01, 0xee, 0xee, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0x00, 0xff, 0xff, 0xf0, 0xef, 0xef, 0x0f, 0xef, 0xf0, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfe, 0xfe, 0xee, 0xce, 0x31, 0xff, 0xff, 0x00, 0xff, 0xff, 0x01, 0xfe, 0xfe, 0xfe, 0xfe, 0x01, 0xff, 0xff, 0x00, 0xff, 0xff, 0x07, 0xb9, 0xbe, 0xbe, 0xb9, 0x07, 0xff, 0xff, 0x00, 0xff, 0xff, 0x01, 0xde, 0xde, 0x9e, 0x61, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xfe, 0xfe, 0xfe, 0xfd, 0x03, 0xff, 0xff,
                                            0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x27, 0x21, 0x20, 0x27, 0x22, 0x27, 0x20, 0x27, 0x23, 0x23, 0x20, 0x27, 0x25, 0x27, 0x20, 0x27, 0x27, 0x24, 0x20, 0x27, 0x27, 0x24, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x23, 0x27, 0x24, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x23, 0x20, 0x23, 0x27, 0x26, 0x25, 0x25, 0x25, 0x25, 0x25, 0x27, 0x23, 0x20, 0x23, 0x27, 0x27, 0x27, 0x27, 0x24, 0x27, 0x27, 0x27, 0x23, 0x20, 0x23, 0x27, 0x24, 0x25, 0x25, 0x25, 0x25, 0x26, 0x27, 0x23, 0x20, 0x23, 0x27, 0x26, 0x25, 0x25, 0x25, 0x25, 0x26, 0x27, 0x23, 0x20, 0x23, 0x27, 0x24, 0x27, 0x27, 0x27, 0x27, 0x24, 0x27, 0x03, 0x20, 0x03, 0x27, 0x04, 0x27, 0x07, 0x67, 0x34, 0x77, 0x07, 0x13, 0x70, 0x13, 0x07, 0x74, 0x55, 0x75, 0x05, 0x76, 0x37, 0x77, 0x03 };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));

    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_WH_U);
    } else {
      tap_code(KC_WH_D);
    }

    return true;
}

void invert_display(uint8_t r, uint8_t c, bool state) {
    uint16_t keycode = keymaps[_BL][r][0];
    if (keycode == KC_NO) {
        c--;
    }

    r = r % MATRIX_ROWS_PER_SIDE;
    uint8_t disp_idx = LAYOUT_TO_INDEX(r, c);
    const uint8_t* bitmask = key_display[disp_idx].bitmask;
    sr_shift_out_buffer_latch(bitmask, sizeof(key_display->bitmask));

    if (disp_idx != 255) {
        kdisp_invert(state);
    }
}

// invert displays directly when pressed (no need to do split sync)
extern matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t last_matrix[MATRIX_ROWS_PER_SIDE];
void matrix_scan_user(void) {
    uint8_t first   = is_keyboard_master() ? 0 : MATRIX_ROWS_PER_SIDE;
    bool    changed = false;
    for (uint8_t r = first; r < first + MATRIX_ROWS_PER_SIDE; r++) {
        if (last_matrix[r - first] != matrix[r]) {
            changed = true;
            for (uint8_t c = 0; c < MATRIX_COLS; c++) {
                bool old     = ((last_matrix[r - first] >> c) & 1) == 1;
                bool current = ((matrix[r] >> c) & 1) == 1;
                if (!old && current) {
                    invert_display(r,c,true);
                } else if (old && !current) {
                    invert_display(r,c,false);
                }
            }
        }
    }
    if (changed) {
        memcpy(last_matrix, &matrix[first], sizeof(last_matrix));
    }
}

void matrix_slave_scan_user(void) {
    matrix_scan_user();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation){
    return rotation;
}

void suspend_power_down_kb(void) {
    dprint("Suspend power down\n");
    g_contrast = DISP_OFF;
    sync_and_refresh_displays();
}

void suspend_wakeup_init_kb(void) {
    dprint("Suspend wakeup\n");
    g_contrast = FULL_BRIGHT;
    sync_and_refresh_displays();
}
