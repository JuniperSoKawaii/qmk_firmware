MCU = atmega32u4
F_CPU = 16000000
F_USB = $(F_CPU)
ARCH = AVR8
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=512

BOOTLOADER = halfkay

BOOTMAGIC_ENABLE = lite
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes
COMMAND_ENABLE = yes
NKRO_ENABLE = yes

SLEEP_LED_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
BLUETOOTH_ENABLE = no
AUDIO_ENABLE = no
