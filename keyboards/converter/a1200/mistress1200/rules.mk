# MCU name
MCU = atmega16u4

# Bootloader selection
BOOTLOADER = atmel-dfu
EXTRAFLAGS        += -flto

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
COMMAND_ENABLE   = no
UNICODE_ENABLE   = no
