# Unsplit

![boardsource/unsplit](imgur.com image replace me!)

* Keyboard Maintainer: [waffle87](https://github.com/waffle87)
* Hardware Supported: Unsplit PCB w/ Pro Micro style microcontroller
* Hardware Availability: [boardsource.xyz](https://boardsource.xyz)

Make example for this keyboard (after setting up your build environment):

    make boardsource/unsplit:default

Flashing example for this keyboard:

    make boardsource/unsplit:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (top left key)
* **Physical reset button**: Briefly press the button on the front of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT`
