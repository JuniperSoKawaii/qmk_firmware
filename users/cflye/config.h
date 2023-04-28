// You should use the config.h for configuration options https://docs.qmk.fm/#/config_options

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 400

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#define RSPC_KEYS KC_RSFT, KC_LSFT, KC_9
#define RCPC_KEYS KC_RCTL, KC_LSFT, KC_0
#define RAPC_KEYS KC_RALT, KC_RSFT, KC_MINS