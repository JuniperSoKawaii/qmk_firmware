# dfu-programmer atmega32u4 erase --force
# dfu-programmer atmega32u4 flash /path/to/firmware.hex
# dfu-programmer atmega32u4 reset

# run this in the qmk_firmware directory
make dz60:chrisae9
dfu-programmer atmega32u4 erase --force && \
dfu-programmer atmega32u4 flash dz60_chrisae9.hex && \
dfu-programmer atmega32u4 reset