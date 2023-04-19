# Mode M256-WH PCB QMK Firmware

![m256wh](https://imgur.com/97KRZCr.jpg)

The M256-WH is the hotswap version PCB support for the Mode Envoy.

* Keyboard Maintainer: [Gondolindrim](https://github.com/Gondolindrim)
* Hardware Supported: proprietary PCBs using the STM32F401 microcontroller;
* Hardware Availability: as of april 18, these PCBs are on the verge of being sold with the first kits of the Mode Envoy.

## How to flash

In order to flash this PCB, first build the default layout (after setting up your build environment):

    make mode/m256wh:default

After building or downloading the firmware, put the PCB into DFU mode by holding the reset button for at least five seconds and upload the firmware onto the microcontroller through a utility like `dfu-util` or QMK Toolbox. Alternatively, you can build and flash using:

    make mode/m256wh:via

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
