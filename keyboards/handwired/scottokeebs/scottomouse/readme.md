# ScottoMouse

![ScottoMouse](https://i.imgur.com/yjnhyXWh.jpeg)

A 6 key mouse using [QMK mouse keys](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md), case files available [here](https://github.com/joe-scotto/scottokeebs.git).

-   Keyboard Maintainer: [Joe Scotto](https://github.com/joe-scotto)
-   Hardware Supported: Raspberry Pi Pico
-   Hardware Availability: [ScottoKeebs](https://scottokeebs.com), [Amazon](https://amazon.com), [Ali](https://amazon.com)

# Compiling

Make example for this keyboard (after setting up your build environment):

    make handwired/scottokeebs/scottomouse:default

Flashing example for this keyboard:

    make handwired/scottokeebs/scottomouse:default:flash

# Bootloader

Uses [bootmagic](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_bootmagic.md) allowing you to hold the left most key (0, 0) when plugging the board in to enter bootloader mode.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
