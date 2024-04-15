# zed65rgb

![Zed65RGB](https://i.imgur.com/IbsSLb6h.jpeg)

A replace PCB for the Space65 R1&R2 keyboard.

* Keyboard Maintainer: [Mechlovin](https://github.com/mechlovin)
* Hardware Supported: Space65 R1&R2
* Hardware Availability: [Mechlovin' Studio](https://mechlovin.studio/)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/zed65/rev1

Flashing example for this keyboard:

    make mechlovin/zed65/rev1:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 4 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Bootloader reset**: Hold down the key at (0,13) in the matrix (usually the Back Space) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
