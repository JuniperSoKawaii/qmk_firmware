# MCU name
MCU = atmega32u4
F_CPU = 8000000

BOOTMAGIC_ENABLE = no         # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes         # Mouse keys(+4700)
# EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no           # Console for debug(+400)
COMMAND_ENABLE = no           # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
# SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# NKRO_ENABLE = yes           # USB Nkey Rollover
# BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
# RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
# MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = yes          # Unicode

BLUETOOTH_ENABLE = yes
BLUETOOTH = AdafruitBLE
OUTPUT_AUTO_ENABLE = yes

# AUDIO_ENABLE = no           # Audio output on port C6
# FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
# HD44780_ENABLE = no 		# Enable support for HD44780 based LCDs (+400)

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina
