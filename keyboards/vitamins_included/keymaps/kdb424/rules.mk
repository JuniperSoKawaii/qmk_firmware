BACKLIGHT_ENABLE  = no    # Enable keyboard backlight functionality
NKRO_ENABLE       = no    # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE   = no   # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
TAP_DANCE_ENABLE  = yes   # Enable tap dance.
AUTO_SHIFT_ENABLE = no    # Auto hold shift on longer keypress

EXTRAFLAGS        += -flto

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
