CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# If you want to change the display of OLED, you need to change here
SRC +=  logo_reader.c \
				layer.c

VPATH += keyboards/crkbd/lib
LIB_SRC += ssd1306.c i2c.c
