#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_4x12(
     KC_TAB       , KC_Q    , KC_W     , KC_E    , KC_R    , KC_T        ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC  ,
     KC_ESC       , KC_A    , KC_S     , KC_D    , KC_F    , KC_G        ,      KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT  ,
     KC_LSFT      , KC_Z    , KC_X     , KC_C    , KC_V    , KC_B        ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT   ,
     KC_LCTL      , KC_LGUI , MO(3)    , KC_LALT , MO(2)   , KC_SPC      ,      KC_SPC  , MO(1)   , KC_LALT , MO(3)   , KC_RGUI , KC_RCTL
   ),
	[1] = LAYOUT_ortho_4x12(
     KC_GRV       , KC_1    , KC_2     , KC_3    , KC_4    , KC_TRNS     ,      KC_TRNS , KC_PGUP , KC_UP   , KC_PGDN , KC_LPRN , KC_RPRN  ,
     KC_TRNS      , KC_5    , KC_6     , KC_7    , KC_8    , KC_TRNS     ,      KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_LBRC , KC_RBRC  ,
     KC_TRNS      , KC_9    , KC_0     , KC_MINS , KC_EQL  , KC_TRNS     ,      KC_END  , KC_TRNS , KC_TRNS , KC_TRNS , KC_BSLS , KC_PIPE  ,
     KC_TRNS      , KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
   ),
	[2] = LAYOUT_ortho_4x12(
     KC_CAPS      , KC_TRNS , KC_PSCR  , KC_SLCK , KC_PAUS , KC_TRNS     ,      KC_TRNS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_DEL   ,
     KC_TRNS      , KC_TRNS , KC_INS   , KC_HOME , KC_PGUP , KC_TRNS     ,      KC_TRNS , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_TRNS  ,
     KC_TRNS      , KC_TRNS , KC_DEL   , KC_END  , KC_PGDN , KC_TRNS     ,      KC_TRNS , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_TRNS  ,
     KC_TRNS      , KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
   ),
	[3] = LAYOUT_ortho_4x12(
     RGB_TOG      , RGB_MOD , RGB_RMOD , KC_TRNS , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , RESET    ,
     RGB_HUI      , RGB_SAI , RGB_VAI  , RGB_SPI , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_MPRV , KC_MPLY , KC_MNXT , KC_TRNS , KC_TRNS  ,
     RGB_HUD      , RGB_SAD , RGB_VAD  , RGB_SPD , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_MUTE , KC_VOLD , KC_VOLU , KC_TRNS , KC_TRNS  ,
     KC_TRNS      , KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS     ,      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
   )
};

