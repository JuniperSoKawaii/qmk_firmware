"""Functions that help you work with QMK keymaps.
"""
import os
from pathlib import Path

import qmk.path
import qmk.makefile

# The `keymap.c` template to use when a keyboard doesn't have its own
DEFAULT_KEYMAP_C = """#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk-compile-json. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
__KEYMAP_GOES_HERE__
};
"""


def template(keyboard):
    """Returns the `keymap.c` template for a keyboard.

    If a template exists in `keyboards/<keyboard>/templates/keymap.c` that
    text will be used instead of `DEFAULT_KEYMAP_C`.

    Args:
        keyboard
            The keyboard to return a template for.
    """
    template_name = 'keyboards/%s/templates/keymap.c' % keyboard

    if os.path.exists(template_name):
        with open(template_name, 'r') as fd:
            return fd.read()

    return DEFAULT_KEYMAP_C


def generate(keyboard, layout, layers):
    """Returns a keymap.c for the specified keyboard, layout, and layers.

    Args:
        keyboard
            The name of the keyboard

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    layer_txt = []
    for layer_num, layer in enumerate(layers):
        if layer_num != 0:
            layer_txt[-1] = layer_txt[-1] + ','
        layer_keys = ', '.join(layer)
        layer_txt.append('\t[%s] = %s(%s)' % (layer_num, layout, layer_keys))

    keymap = '\n'.join(layer_txt)
    keymap_c = template(keyboard)

    return keymap_c.replace('__KEYMAP_GOES_HERE__', keymap)


def write(keyboard, keymap, layout, layers):
    """Generate the `keymap.c` and write it to disk.

    Returns the filename written to.

    Args:
        keyboard
            The name of the keyboard

        keymap
            The name of the keymap

        layout
            The LAYOUT macro this keymap uses.

        layers
            An array of arrays describing the keymap. Each item in the inner array should be a string that is a valid QMK keycode.
    """
    keymap_c = generate(keyboard, layout, layers)
    keymap_path = qmk.path.keymap(keyboard)
    keymap_dir = os.path.join(keymap_path, keymap)
    keymap_file = os.path.join(keymap_dir, 'keymap.c')

    if not os.path.exists(keymap_dir):
        os.makedirs(keymap_dir)

    with open(keymap_file, 'w') as keymap_fd:
        keymap_fd.write(keymap_c)

    return keymap_file


def list_keymaps(keyboard_name):
    """ List the available keymaps for a keyboard.

    Args:
        keyboard_name: the keyboards full name with vendor and revision if necessary, example: clueboard/66/rev3

    Returns:
        a set with the names of the available keymaps
    """
    # parse all the rules.mk files for the keyboard
    rules_mk = qmk.makefile.get_rules_mk(keyboard_name)
    names = set()

    if rules_mk:
        # qmk_firmware/keyboards
        keyboards_dir = Path.cwd() / "keyboards"
        # path to the keyboard's directory
        kb_path = keyboards_dir / keyboard_name
        # walk up the directory tree until keyboards_dir
        # and collect all directories' name with keymap.c file in it
        while kb_path != keyboards_dir:
            keymaps_dir = kb_path / "keymaps"
            if keymaps_dir.exists():
                names = names.union([keymap for keymap in os.listdir(keymaps_dir) if (keymaps_dir / keymap / "keymap.c").is_file()])
            kb_path = kb_path.parent

        # if community layouts are supported, get them
        if "LAYOUTS" in rules_mk:
            for layout in rules_mk["LAYOUTS"].split():
                cl_path = Path.cwd() / "layouts" / "community" / layout
                if cl_path.exists():
                    names = names.union([keymap for keymap in os.listdir(cl_path) if (cl_path / keymap / "keymap.c").is_file()])

    return sorted(names)
