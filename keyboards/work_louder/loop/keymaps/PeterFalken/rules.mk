# Enable VIAL support when merged into QMK
# ENABLE_VIAL = yes

# Setup QMK features
BOOTMAGIC_ENABLE = yes	# Enable QMK_Boot on plug-in
DIP_SWITCH_ENABLE = no	# Won't use for now
COMMAND_ENABLE = no		# Won't use for now
CONSOLE_ENABLE = no		# Won't use for now
ENCODER_ENABLE = yes	# Enable both encoders
GRAVE_ESC_ENABLE = no	# Not needed
MAGIC_ENABLE = no		# Won't use for now
MOUSEKEY_ENABLE = no	# Won't use for now
RAW_ENABLE = no			# Disable raw HID commands
RGBLIGHT_ENABLE = no	# Disable RGB underglow
RGB_MATRIX_ENABLE = yes	# Disable RGB key matrix
SPACE_CADET_ENABLE = no	# Free up space

# Enable Link Time Optimizations
LTO_ENABLE = yes

SRC += rgb_functions.c

DEFAULT_FOLDER = work_louder/loop/rev3
