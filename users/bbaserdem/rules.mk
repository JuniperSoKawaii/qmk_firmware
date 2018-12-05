EXTRAFLAGS += -flto     # Used to make code smaller

# Use the userspace code unless disabled
ifndef DISABLE_USERSPACE
    SRC += bbaserdem.c
endif

# MANUALLY CONFIGURE;
# BACKLIGHT_ENABLE        # Switch LEDs
# RGBLIGHT_ENABLE         # LED strip
# AUDIO_ENABLE            # Audio stuff
# BLUETOOTH_ENABLE        # Bluetooth

# ENABLE
EXTRAKEY_ENABLE = yes   # OS signals like volume control
MOUSEKEY_ENABLE = yes   # Mouse emulation keys
TAP_DANCE_ENABLE = yes  # Tap dance keys

# DISABLE
UNICODE_ENABLE = no     # Used for unicode character emulation
COMMAND_ENABLE = no     # Some bootmagic thing i dont use
BOOTMAGIC_ENABLE = no   # Access to EEPROM settings, not needed
CONSOLE_ENABLE = no     # Allows console output with a command
SLEEP_LED_ENABLE = no   # Breathes LED's when computer is asleep. Untested.
NKRO_ENABLE = no        # Default is 6KRO which is plenty
MIDI_ENABLE = no        # Untested feature
FAUXCLICKY_ENABLE = no  # Emulates clicks using speaker
KEY_LOCK_ENABLE = no    # Allows locking any key. Not used
API_SYSEX_ENABLE = no   # Allows OS to send signals.

# Disabling this makes it compile, i dont know why
# VARIABLE_TRACE = no     # Allows debugging variables
