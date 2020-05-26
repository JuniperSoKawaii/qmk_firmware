## Keycode Migration PRs

[#8954](https://github.com/qmk/qmk_firmware/pull/8954 "Migrate `ACTION_LAYER_TOGGLE` to `TG()`"), [#8957](https://github.com/qmk/qmk_firmware/pull/8957 "Migrate `ACTION_MODS_ONESHOT` to `OSM()`"), [#8958](https://github.com/qmk/qmk_firmware/pull/8958 "Migrate `ACTION_DEFAULT_LAYER_SET` to `DF()`"), [#8959](https://github.com/qmk/qmk_firmware/pull/8959 "Migrate `ACTION_LAYER_MODS` to `LM()`"), [#8968](https://github.com/qmk/qmk_firmware/pull/8968 "Migrate `ACTION_MODS_TAP_KEY` to `MT()`"), [#8977](https://github.com/qmk/qmk_firmware/pull/8977 "Migrate miscellaneous `fn_actions` entries"), and [#8979](https://github.com/qmk/qmk_firmware/pull/8979 "Migrate `ACTION_MODS_KEY` to chained mod keycodes")

Authored by fauxpark, these pull requests remove references to deprecated TMK macros that have been superseded by native QMK keycodes.

Old `fn_actions` action | New QMK keycode
:---------------------- | :--------------
`ACTION_DEFAULT_LAYER_SET(layer)` | `DF(layer)`
`ACTION_LAYER_MODS(layer, mod)` | `LM(layer, mod)`
`ACTION_LAYER_ONESHOT(mod)` | `OSL(mod)`
`ACTION_LAYER_TOGGLE(layer)` | `TG(layer)`
`ACTION_MODS_ONESHOT(mod)` | `OSM(mod)`
`ACTION_MODS_TAP_KEY(mod, kc)` | `MT(mod, kc)`
`ACTION_MODS_KEY(mod, kc)`<br>e.g. `ACTION_MODS_KEY(MOD_LCTL, KC_0)` | `MOD(kc)`<br>e.g. `LCTL(KC_0)`
