/*
  Set any config.h overrides for your userspace here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#define KC_LOCKSCR  LCTL(LGUI(KC_Q)) // mac system wide Lock Screen 10.13 and later

// Disable action_get_macro and fn_actions, since we don't use these
// and it saves on space in the firmware.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
