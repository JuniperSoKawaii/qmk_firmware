# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
<<<<<<< HEAD
TAP_DANCE_ENABLE = no       # Enable TapDance functionality
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. 
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+1500)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes           # Nkey Rollover - If this doesn't work, add this to config.h: #define FORCE_NKRO
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
UNICODEMAP_ENABLE = no      # Enable extended unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Uses buzzer to emulate clicky switches.  By default, uses the C6 pin, same as AUDIO_ENABLE.
#VARIABLE_TRACE = no         # Use this to debug changes to variable values
API_SYSEX_ENABLE = no       # This enables using the Quantum SYSEX API to send strings(+5390)
KEY_LOCK_ENABLE = no        # This enables key lock(+260)
SPLIT_KEYBOARD = no         # This enables split keyboard support and includes all necessary files located at quantum/split_common
=======
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. 
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
>>>>>>> upstream/master

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
