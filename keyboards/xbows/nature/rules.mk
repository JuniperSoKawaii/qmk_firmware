# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu


# Build Options
#   change yes to no to disable
BOOTMAGIC_ENABLE = lite            # Virtual DIP switch configuration
BACKLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes            # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes                  # USB Nkey Rollover
AUDIO_ENABLE = no                  # Audio output
RGB_MATRIX_ENABLE = yes            # Use RGB matrix
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in


# project specific files
SRC += Peripherals.c
#       drivers/issi/is31fl3731.c
QUANTUM_LIB_SRC += i2c_master.c
QUANTUM_LIB_SRC += rgb_matrix.c
