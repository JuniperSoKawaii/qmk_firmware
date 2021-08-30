# MCU name
MCU = atmega32u4

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
#   change yes to no to disable
#
<<<<<<< HEAD
VIA_ENABLE = yes
BOOTMAGIC_ENABLE = lite        # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no           # Mouse keys
=======
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes          # Mouse keys
>>>>>>> f87cd8e8a02bf89d05737a19fd54e8ec6f63f90f
EXTRAKEY_ENABLE = yes          # Audio control and System control
CONSOLE_ENABLE = no            # Console for debug
COMMAND_ENABLE = no            # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = yes         # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes              # USB Nkey Rollover
BACKLIGHT_ENABLE = no          # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no           # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no          # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no              # Audio output on port C6
RGB_MATRIX_ENABLE = yes        # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3733
NO_USB_STARTUP_CHECK = no      # Disable initialization only when usb is plugged in
