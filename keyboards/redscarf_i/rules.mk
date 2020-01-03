# MCU options
MCU = atmega32u4
BOOTLOADER = atmel-dfu

# build options
BOOTMAGIC_ENABLE = no   # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = no   # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes  # Audio control and System control(+450)
CONSOLE_ENABLE   = no   # Console for debug(+400)
COMMAND_ENABLE   = no   # Commands for debug and configuration
BACKLIGHT_ENABLE = yes  # Enable keyboard backlight functionality
UNICODE_ENABLE   = no   # Unicode