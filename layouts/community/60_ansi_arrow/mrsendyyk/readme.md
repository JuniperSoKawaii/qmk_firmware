# Sendy YK's 60% ANSI Arrow Layout and Keymap

[https://mr.sendyyk.com](https://mr.sendyyk.com)

## 60% ANSI Arrow Layout

![LAYOUT_60_ansi_arrow](https://raw.githubusercontent.com/mrsendyyk/my_qmk/master/dz60/assets/layout-60-ansi-arrow-with-gmk-metropolis.png)

## Keymap

### Default Layer [0]

![Default Layer [0]](https://raw.githubusercontent.com/mrsendyyk/my_qmk/master/dz60/assets/keymap-with-gmk-metropolis---layer-0.png)

### Fn Layer [1]

Press and hold **Ctrl** key.

![Fn Layer [1]](https://raw.githubusercontent.com/mrsendyyk/my_qmk/master/dz60/assets/keymap-with-gmk-metropolis---layer-1.png)

### Fn Layer [2]

Press and hold *right* **Alt** key.

![Fn Layer [2]](https://raw.githubusercontent.com/mrsendyyk/my_qmk/master/dz60/assets/keymap-with-gmk-metropolis---layer-2.png)

### RGB Lighting/LED/Underglow as Caps Lock, Num Lock, Scroll Lock, and Layer Indicator

#### Caps Lock Indicator

```c
    // Caps Lock Indicator
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(B2);
        rgblight_setrgb(100, 255, 100);
    }
```

#### Num Lock Indicator

```c
    // Num Lock Indicator
    if (host_keyboard_led_state().num_lock) {
        rgblight_setrgb(225, 8, 0);
    }
```

#### Scroll Lock Indicator
```c
    // Scroll Lock Indicator
    if (host_keyboard_led_state().scroll_lock) {
        rgblight_setrgb(255, 110, 0);
    }
```

#### Layer Indicator

```c
    // Layer Indicator
    else {          
        switch (get_highest_layer(layer_state)) {
            // Fn Layer [1] Indicator
            case 1:
                rgblight_setrgb(100, 255, 100);
                break;
            // Fn Layer [2] Indicator
            case 2:
                rgblight_setrgb(100, 255, 100);
                break;
            // Default Layer [0] Indicator
            default:
                rgblight_setrgb(0, 0, 0);
                break;
        }
        update_led();
    }
```

## Build The Firmware

You will need to build the firmware. To do so go to your terminal window and run the compile command:

    qmk compile -kb dz60 -km mrsendyyk

See [The Complete Newbs Guide To QMK](https://docs.qmk.fm/#/newbs).
