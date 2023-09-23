"""Functions for searching through QMK keyboards and keymaps.
"""
import contextlib
import functools
import fnmatch
import logging
import multiprocessing
import re
from typing import List, Tuple
from dotty_dict import dotty
from milc import cli

from qmk.info import keymap_json
import qmk.keyboard
import qmk.keymap


def _set_log_level(level):
    cli.acquire_lock()
    old = cli.log_level
    cli.log_level = level
    cli.log.setLevel(level)
    logging.root.setLevel(level)
    cli.release_lock()
    return old


@contextlib.contextmanager
def ignore_logging():
    old = _set_log_level(logging.CRITICAL)
    yield
    _set_log_level(old)


def _all_keymaps(keyboard):
    with ignore_logging():
        return (keyboard, qmk.keymap.list_keymaps(keyboard))


def _keymap_exists(keyboard, keymap):
    with ignore_logging():
        return keyboard if qmk.keymap.locate_keymap(keyboard, keymap) is not None else None


def _load_keymap_info(keyboard, keymap):
    with ignore_logging():
        return (keyboard, keymap, keymap_json(keyboard, keymap))


def expand_make_targets(targets: List[str]) -> List[Tuple[str, str]]:
    split_targets = []
    for target in targets:
        split_target = target.split(':')
        if len(split_target) != 2:
            cli.log.error(f"Invalid build target: {target}")
            return []
        split_targets.append((split_target[0], split_target[1]))
    return expand_keymap_targets(split_targets)


def _expand_keymap_target(keyboard: str, keymap: str, all_keyboards: List[str]) -> List[Tuple[str, str]]:
    with multiprocessing.Pool() as pool:
        targets = []
        if keyboard == 'all':
            if keymap == 'all':
                cli.log.info('Retrieving list of all keyboards and keymaps...')
                for keyboard, keymaps in pool.imap_unordered(_all_keymaps, all_keyboards):
                    for keymap in keymaps:
                        targets.append((keyboard, keymap))
            else:
                cli.log.info(f'Retrieving list of keyboards with keymap "{keymap}"...')
                l = functools.partial(_keymap_exists, keymap=keymap)
                for keyboard in pool.imap_unordered(l, all_keyboards):
                    if keyboard is not None:
                        targets.append((keyboard, keymap))
        else:
            if keymap == 'all':
                keyboard = qmk.keyboard.resolve_keyboard(keyboard)
                cli.log.info(f'Retrieving list of keymaps for keyboard "{keyboard}"...')
                for keymap in qmk.keymap.list_keymaps(keyboard):
                    targets.append((keyboard, keymap))
            else:
                targets.append((keyboard, keymap))
        return targets


def expand_keymap_targets(targets: List[Tuple[str, str]]) -> List[Tuple[str, str]]:
    overall_targets = []
    all_keyboards = qmk.keyboard.list_keyboards()
    for target in targets:
        overall_targets.extend(_expand_keymap_target(target[0], target[1], all_keyboards))
    return list(sorted(set(overall_targets)))


def filter_keymap_targets(target_list: List[Tuple[str, str]], filters: List[str] = [], print_vals: List[str] = []) -> List[Tuple[str, str, List[Tuple[str, str]]]]:
    target_list = list(sorted(set(target_list)))
    with multiprocessing.Pool() as pool:
        if len(filters) == 0:
            targets = [(kb, km, {}) for kb, km in target_list]
        else:
            cli.log.info('Parsing data for all matching keyboard/keymap combinations...')
            valid_keymaps = [(e[0], e[1], dotty(e[2])) for e in pool.starmap(_load_keymap_info, target_list)]

            function_re = re.compile(r'^(?P<function>[a-zA-Z]+)\((?P<key>[a-zA-Z0-9_\.]+)(,\s*(?P<value>[^#]+))?\)$')
            equals_re = re.compile(r'^(?P<key>[a-zA-Z0-9_\.]+)\s*=\s*(?P<value>[^#]+)$')

            for filter_expr in filters:
                function_match = function_re.match(filter_expr)
                equals_match = equals_re.match(filter_expr)

                if function_match is not None:
                    func_name = function_match.group('function').lower()
                    key = function_match.group('key')
                    value = function_match.group('value')

                    if value is not None:
                        if func_name == 'length':
                            valid_keymaps = filter(lambda e, key=key, value=value: key in e[2] and len(e[2].get(key)) == int(value), valid_keymaps)
                        elif func_name == 'contains':
                            valid_keymaps = filter(lambda e, key=key, value=value: key in e[2] and value in e[2].get(key), valid_keymaps)
                        else:
                            cli.log.warning(f'Unrecognized filter expression: {function_match.group(0)}')
                            continue

                        cli.log.info(f'Filtering on condition: {{fg_green}}{func_name}{{fg_reset}}({{fg_cyan}}{key}{{fg_reset}}, {{fg_cyan}}{value}{{fg_reset}})...')
                    else:
                        if func_name == 'exists':
                            valid_keymaps = filter(lambda e, key=key: key in e[2], valid_keymaps)
                        elif func_name == 'absent':
                            valid_keymaps = filter(lambda e, key=key: key not in e[2], valid_keymaps)
                        else:
                            cli.log.warning(f'Unrecognized filter expression: {function_match.group(0)}')
                            continue

                        cli.log.info(f'Filtering on condition: {{fg_green}}{func_name}{{fg_reset}}({{fg_cyan}}{key}{{fg_reset}})...')

                elif equals_match is not None:
                    key = equals_match.group('key')
                    value = equals_match.group('value')
                    cli.log.info(f'Filtering on condition: {{fg_cyan}}{key}{{fg_reset}} == {{fg_cyan}}{value}{{fg_reset}}...')

                    def _make_filter(k, v):
                        expr = fnmatch.translate(v)
                        rule = re.compile(f'^{expr}$', re.IGNORECASE)

                        def f(e):
                            lhs = e[2].get(k)
                            lhs = str(False if lhs is None else lhs)
                            return rule.search(lhs) is not None

                        return f

                    valid_keymaps = filter(_make_filter(key, value), valid_keymaps)
                else:
                    cli.log.warning(f'Unrecognized filter expression: {filter_expr}')
                    continue

            targets = [(e[0], e[1], [(p, e[2].get(p)) for p in print_vals]) for e in valid_keymaps]

    return targets


def search_keymap_targets(keymap='default', filters: List[str] = [], print_vals: List[str] = []) -> List[Tuple[str, str, List[Tuple[str, str]]]]:
    return filter_keymap_targets(expand_keymap_targets([('all', keymap)]), filters, print_vals)


def search_make_targets(targets: List[str], filters: List[str] = [], print_vals: List[str] = []) -> List[Tuple[str, str, List[Tuple[str, str]]]]:
    return filter_keymap_targets(expand_make_targets(targets), filters, print_vals)
