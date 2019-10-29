# Overview

My user-space code covers the [Minivan](../../keyboards/thevankeyboards/minivan/keymaps/tominabox1/keymap.c), [Dimple](../../keyboards/lazydesigners/dimple/keymaps/tominabox1/keymap.c), [CRKBD](../../keyboards/crkbd/keymaps/tominabox1/keymap.c), and [Teensy based HHKB converter](../../keyboards/hhkb/keymaps/tominabox1/). My code makes extensive use of @Drashna's code and much love and praise goes to him for figuring a lot of this stuff out!

My usercode utilizes the layout wrappers contained in [wrappers.h](wrappers.h). All of the keymaps are derivative of the Dimple keymap and utilize its wrappers in the definition of additional wrappers.

# Keyboards
Dimple: make lazydesigners/dimple:tominabox1
Minivan Catalyst: make thevankeyboards/minivan:tominabox1_catalyst
Minvian Low Rider: make thevankeyboards/minivan:tominabox1_low
Roadkit: make thevankeyboards/roadkit:tominabox1
CRKBD: make crkbd:tominabox1 (RGB_MATRIX_SPLIT_RIGHT=yes)
HHKB: make hhkb:tominabox1
