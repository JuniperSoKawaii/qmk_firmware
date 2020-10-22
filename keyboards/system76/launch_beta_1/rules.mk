# MCU name
MCU = atmega32u4

# Allow flashing with usbasp
AVRDUDE_MCU = $(MCU)

# Processor frequency
F_CPU = 16000000

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = no        # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
DYNAMIC_KEYMAP_ENABLE = yes # Reconfigurable keyboard without flashing firmware
NKRO_ENABLE = yes           # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RAW_ENABLE = yes            # Enable RAW HID commands (used by keyboard configurator)
RGBLIGHT_ENABLE = no        # Support for RGB backlight (conflicts with RGB_MATRIX)
RGB_MATRIX_ENABLE = WS2812  # Support for RGB matrix

# Add System76 EC command interface
SRC+=system76_ec.c

# Add I2C driver
SRC+=i2c.c

# Add USB mux driver
SRC+=usb_mux.c
