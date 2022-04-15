/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define TAPPING_FORCE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_TAB
#define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"yBAgx/0Yzl3"
#define RGB_MATRIX_STARTUP_SPD 60
