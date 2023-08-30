# Neodox

Inspired by Redox from Mattia Dal Ben

![neodox](https://imgur.com/sA6O45J)

**Neodox** project.

- Keyboard Maintainer: [MatteoDM](https://github.com/MatteoDM)  
- Hardware Supported: 
    - Raspberry Pi Pico microcontroller
    - ws2812b
    - GC9A01 Round display
- Hardware Availability: [Case files](https://www.thingiverse.com/thing:5625196)


Make example for this keyboard (after setting up your build environment):

    make handwired/neodox:default

Flashing example for this keyboard:

    make handwired/neodox:default:flash

Enter the bootloader when prompted by doing one of the following:
* **Physical boot button**: Unplug your keyboard then press the BOOT button on the microcontroller PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if you have a layout that has one.


Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
