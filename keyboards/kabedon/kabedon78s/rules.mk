# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = lite   # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes    # Mouse keys
EXTRAKEY_ENABLE = yes    # Audio control and System control
CONSOLE_ENABLE = no     # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
#SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = no       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE = NO  # Enable keyboard backlight functionality
# AUDIO_ENABLE = no
UNICODE_ENABLE = yes 		# Unicode
RGBLIGHT_ENABLE = yes
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

