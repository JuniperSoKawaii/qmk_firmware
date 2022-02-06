[DZ65RGB/v3 Yuannan's Layout Imgur Album](https://imgur.com/a/BI2RjgE)

![Alpha](https://i.imgur.com/ikqvrtF.png)
![Vim Editing Layer](https://i.imgur.com/hoBvSRR.png)
![Mouse and Autoclicker](https://i.imgur.com/QWmWaWY.png)
![Hyper functions and RGB Layer](https://i.imgur.com/Zm6Tf6p.png)

# Yuannan's DZ65 Custom Profile. Autoclicker, Vim, and more!

## Features

1. Much better mouse support. Now able to:
	- Move mouse around with 3 levels of acceleration
	- Click and nav using mouse buttons 1-5
	- Mouse scroll in all 4 directions, autoclick with 5 different levels of speed!
	- Increase or Decrease the autoclick speed from the preset array of {500, 50, 20, 10, 1} clicks per second \*(Read Notes). Press Shift while using the Increase or Decrease button to do the opposite. Designed to work with other keymaps and keyboards!
2. Ctrl and Caps swapped. The new indicator is dynamically colored and has been moved to the CTRL key to reflect the keymap.
3. Improved navigation via Vim like keys.
4. Dynamic Macros now enabled!
5. Custom Editing Macros such as:
	- Deleting entire line
	- Deleting from cursor to start of line
	- Deleting form cursor to end of line
6. VIA support.
7. Improved granularity of the RGB Matrix now with steps of 8/256 (32 steps!)
8. The default toggle for RGB now sets the matrix to be on low brightness. Why? If the matrix is completely toggled off then the indicators for Caps Locks and FN are also completely off. You can completely turn it off by pressing shift while processing the "RGB_TOG" keycode. (It is {FN1+FN2+Shift+Space} on this keymap, also read "Note Autoclick".)
9. Disabled some effects to free up more space.

### Notes

#### Note Autoclick
The RGB animation on the board actually eats a lot of CPU cycles. Enough to actually put a massive dent in the clicks per second output. So if you wish for optimal CPS then disable the RGB. Even you set the brightness all the way down to 0 the animation code will still run. This is true as of (2022/01/02), I hope someone may fix this so if the brightness is set to 0 it will not run the animations. In the meantime I have created a second array of delays for the autoclicker while RGB mode is active. Users should note there is yet another caveat to this. Because of  the FN layer indicator setting it's own colour the animation does not compute it for that key. When your FN layers are mostly populated like it is on this keymap it actually speeds up the animation compute time by a lot because the animation does not need to compute the static colors for that layer. I could compensate for this once again but it'll be a chase into oblivion.

TL;DR: The CPS is not accurate and it **CANNOT** be while the RGB lighting is on! Setting brightness to 0 is not the same, it needs to be off COMPLETELY. It is {FN1+FN2+Shift+Space} on this keymap. (Read Feature #8)

#### Note Autoclick Linux libinput (Linux autoclicker not working)

Linux's input driver (libinput) has a debounce feature. This is useful in normal usage as a person cannot feasibly click more than 20CPS. However when the keyboard tries to input 50+CPS and sometimes up to 500~1000CPS this is a problem.

Create a file at "/etc/libinput/local-overrides.quirks" with the content:

	[Never Debounce]
	MatchUdevType=mouse
	ModelBouncingKeys=1

This disables the debounce feature for libnput. This maybe be different if you use evdev, On Arch Linux the driver packages are {"libinput", "xf86-input-libinput"} compared to {"libevdev", "xf86-input-evdev"}. I have {"libinput", "xf86-input-libinput"} installed. In addition I have {"libevdev"} installed as a dependency of other packages. You maybe need to change the driver for your device if you have both installed. For me it was working just fine. Check what driver your xsession currently is utilizing with: 

	$cat /var/log/Xorg.0.log | grep libinput

If it is using libinput then it will show contents. Otherwise search for "evdev".

#### Still not working? (Linux)

Check if the events are reaching your OS with either:

	$cat /dev/input/by-id/YOUR_KEYBOARD
or

	$evtest /dev/input/by-id/YOUR_KEYBOARD

It should end in `event-mouse`. In my case it was `/dev/input/by-id/usb-DZTECH_DZ65RGBV3-if02-event-mouse` which was a symlink to `/dev/input/event12`. It **WILL** vary on your setup.

The output will appear "garbled" as it's trying to interoperate binary into text. The underlying data is actually a struct of the form

	struct input_event {
		struct timeval time;
		unsigned short type;
		unsigned short code;
		unsigned int value;
	};

You can read more about it here (https://www.kernel.org/doc/Documentation/input/input.txt)

If it has an output when you autoclick but do not receive it in your desktop then it's a driver issue.

View libinput with:

	$libinput debug-events --device  /dev/input/by-id/usb-DZTECH_DZ65RGBV3-if02-event-mouse --verbose

If you experience "DEBOUNCE" events then it's a driver issue and should be able to be disabled with the above method, restart your display manager or just reboot afterwards.
If you have any issues feel free to make bug report or pull request to me, QMK, or libinput.
