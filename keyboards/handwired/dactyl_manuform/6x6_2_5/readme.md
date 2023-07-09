# Dactyl Manuform 6x6_2_5

![Dactyl Manufrom 6x6_2_5](https://i.imgur.com/C7FRiwd.jpeg)

## Description

This variant of the 6x6_5 (Dactyl Manuform Mini) has a 4 key bottom row, like the 5x7 variant, instead of the default 2.

`6x6`*(Base variant)*`_2`*(Two extra keys on bottom row)*`_5`*(Five key thumb cluster)*

* Keyboard Maintainer: dmik
* Hardware Supported: 2x [Arduino Pro Micro](https://www.sparkfun.com/products/12640) controller
* Hardware Availability: [Dactyl Manuform](https://github.com/tshort/dactyl-keyboard#wiring) github for Bill of Materials and build guide

Make example for this keyboard (after setting up your build environment):
```
    make handwired/dactyl_manuform/6x6_2_5:default
```
Flashing example for this keyboard:
```
    make handwired/dactyl_manuform/6x6_2_5:default:flash
```
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Build

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
After setting up your build environment you can try to build it with those commands.


## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at F1 for left side, and F7 for right side.
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
