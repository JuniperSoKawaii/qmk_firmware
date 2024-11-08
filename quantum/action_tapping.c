#include <stdint.h>
#include <stdbool.h>

#include "action.h"
#include "action_layer.h"
#include "action_tapping.h"
#include "keycode.h"
#include "timer.h"

#ifndef NO_ACTION_TAPPING

#    if defined(IGNORE_MOD_TAP_INTERRUPT_PER_KEY)
#        error "IGNORE_MOD_TAP_INTERRUPT_PER_KEY has been removed; the code needs to be ported to use HOLD_ON_OTHER_KEY_PRESS_PER_KEY instead."
#    elif defined(IGNORE_MOD_TAP_INTERRUPT)
#        error "IGNORE_MOD_TAP_INTERRUPT is no longer necessary as it is now the default behavior of mod-tap keys. Please remove it from your config."
#    endif

#    ifndef COMBO_ENABLE
#        define IS_TAPPING_RECORD(r) (KEYEQ(tapping_key.event.key, (r->event.key)))
#    else
#        define IS_TAPPING_RECORD(r) (KEYEQ(tapping_key.event.key, (r->event.key)) && tapping_key.keycode == r->keycode)
#    endif
#    define WITHIN_TAPPING_TERM(e) (TIMER_DIFF_16(e.time, tapping_key.event.time) < GET_TAPPING_TERM(get_record_keycode(&tapping_key, false), &tapping_key))
#    define WITHIN_QUICK_TAP_TERM(e) (TIMER_DIFF_16(e.time, tapping_key.event.time) < GET_QUICK_TAP_TERM(get_record_keycode(&tapping_key, false), &tapping_key))

#    ifdef DYNAMIC_TAPPING_TERM_ENABLE
uint16_t g_tapping_term = TAPPING_TERM;
#    endif

#    ifdef TAPPING_TERM_PER_KEY
__attribute__((weak)) uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
#        ifdef DYNAMIC_TAPPING_TERM_ENABLE
    return g_tapping_term;
#        else
    return TAPPING_TERM;
#        endif
}
#    endif

#    ifdef QUICK_TAP_TERM_PER_KEY
__attribute__((weak)) uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    return QUICK_TAP_TERM;
}
#    endif

#    ifdef PERMISSIVE_HOLD_PER_KEY
__attribute__((weak)) bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return false;
}
#    endif

#    ifdef CHORDAL_HOLD
// Tracks whether multiple tap-hold keys are simultaenously unsettled.
static bool multi_tap_sequence = false;

static bool is_one_shot(uint16_t keycode) {
    return IS_QK_ONE_SHOT_MOD(keycode) || IS_QK_ONE_SHOT_LAYER(keycode);
}
static uint8_t waiting_buffer_find_chordal_hold_tap(void);
static void    waiting_buffer_process_until(uint8_t new_tail);
static void    waiting_buffer_process_regular(void);
#    else
#        define multi_tap_sequence false
#    endif // CHORDAL_HOLD

#    ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
__attribute__((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return false;
}
#    endif

#    if defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)
#        include "process_auto_shift.h"
#    endif

static keyrecord_t tapping_key                         = {};
static keyrecord_t waiting_buffer[WAITING_BUFFER_SIZE] = {};
static uint8_t     waiting_buffer_head                 = 0;
static uint8_t     waiting_buffer_tail                 = 0;

static bool process_tapping(keyrecord_t *record);
static bool waiting_buffer_enq(keyrecord_t record);
static void waiting_buffer_clear(void);
static bool waiting_buffer_typed(keyevent_t event);
static bool waiting_buffer_has_anykey_pressed(void);
static void waiting_buffer_scan_tap(void);
static void debug_tapping_key(void);
static void debug_waiting_buffer(void);

/** \brief Action Tapping Process
 *
 * FIXME: Needs doc
 */
void action_tapping_process(keyrecord_t record) {
    if (process_tapping(&record)) {
        if (IS_EVENT(record.event)) {
            ac_dprintf("processed: ");
            debug_record(record);
            ac_dprintf("\n");
        }
    } else {
        if (!waiting_buffer_enq(record)) {
            // clear all in case of overflow.
            ac_dprintf("OVERFLOW: CLEAR ALL STATES\n");
            clear_keyboard();
            waiting_buffer_clear();
            tapping_key = (keyrecord_t){0};
        }
    }

    // process waiting_buffer
    if (IS_EVENT(record.event) && waiting_buffer_head != waiting_buffer_tail) {
        ac_dprintf("---- action_exec: process waiting_buffer -----\n");
    }
    for (; waiting_buffer_tail != waiting_buffer_head; waiting_buffer_tail = (waiting_buffer_tail + 1) % WAITING_BUFFER_SIZE) {
        if (process_tapping(&waiting_buffer[waiting_buffer_tail])) {
            ac_dprintf("processed: waiting_buffer[%u] =", waiting_buffer_tail);
            debug_record(waiting_buffer[waiting_buffer_tail]);
            ac_dprintf("\n\n");
        } else {
            break;
        }
    }
    if (IS_EVENT(record.event)) {
        ac_dprintf("\n");
    }
#    ifdef CHORDAL_HOLD
    if (waiting_buffer_tail == waiting_buffer_head) {
        multi_tap_sequence = false;
    }
#    endif
}

/* Some conditionally defined helper macros to keep process_tapping more
 * readable. The conditional definition of tapping_keycode and all the
 * conditional uses of it are hidden inside macros named TAP_...
 */
#    define TAP_DEFINE_KEYCODE const uint16_t tapping_keycode = get_record_keycode(&tapping_key, false)

#    if defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)
#        ifdef RETRO_TAPPING_PER_KEY
#            define TAP_GET_RETRO_TAPPING(keyp) get_auto_shifted_key(tapping_keycode, keyp) && get_retro_tapping(tapping_keycode, &tapping_key)
#        else
#            define TAP_GET_RETRO_TAPPING(keyp) get_auto_shifted_key(tapping_keycode, keyp)
#        endif
/* Used to extend TAPPING_TERM:
 *     indefinitely if RETRO_SHIFT does not have a value
 *     to RETRO_SHIFT if RETRO_SHIFT is set
 * for possibly retro shifted keys.
 */
#        define MAYBE_RETRO_SHIFTING(ev, keyp) (get_auto_shifted_key(tapping_keycode, keyp) && TAP_GET_RETRO_TAPPING(keyp) && ((RETRO_SHIFT + 0) == 0 || TIMER_DIFF_16((ev).time, tapping_key.event.time) < (RETRO_SHIFT + 0)))
#        define TAP_IS_LT IS_QK_LAYER_TAP(tapping_keycode)
#        define TAP_IS_MT IS_QK_MOD_TAP(tapping_keycode)
#        define TAP_IS_RETRO IS_RETRO(tapping_keycode)
#    else
#        define TAP_GET_RETRO_TAPPING(keyp) false
#        define MAYBE_RETRO_SHIFTING(ev, kp) false
#        define TAP_IS_LT false
#        define TAP_IS_MT false
#        define TAP_IS_RETRO false
#    endif

#    ifdef PERMISSIVE_HOLD_PER_KEY
#        define TAP_GET_PERMISSIVE_HOLD get_permissive_hold(tapping_keycode, &tapping_key)
#    elif defined(PERMISSIVE_HOLD)
#        define TAP_GET_PERMISSIVE_HOLD true
#    else
#        define TAP_GET_PERMISSIVE_HOLD false
#    endif

#    ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#        define TAP_GET_HOLD_ON_OTHER_KEY_PRESS get_hold_on_other_key_press(tapping_keycode, &tapping_key)
#    elif defined(HOLD_ON_OTHER_KEY_PRESS)
#        define TAP_GET_HOLD_ON_OTHER_KEY_PRESS true
#    else
#        define TAP_GET_HOLD_ON_OTHER_KEY_PRESS false
#    endif

/** \brief Tapping
 *
 * Rule: Tap key is typed(pressed and released) within TAPPING_TERM.
 *       (without interfering by typing other key)
 */
/* return true when key event is processed or consumed. */
bool process_tapping(keyrecord_t *keyp) {
    const keyevent_t event = keyp->event;

    // state machine is in the "reset" state, no tapping key is to be
    // processed
    if (IS_NOEVENT(tapping_key.event)) {
        if (!IS_EVENT(event)) {
            // early return for tick events
        } else if (event.pressed && is_tap_record(keyp)) {
            // the currently pressed key is a tapping key, therefore transition
            // into the "pressed" tapping key state
            ac_dprintf("Tapping: Start(Press tap key).\n");
            tapping_key = *keyp;
            process_record_tap_hint(&tapping_key);
            waiting_buffer_scan_tap();
            debug_tapping_key();
        } else {
#    if defined(CHORDAL_HOLD)
            // If keyp is a tap-hold key release, and the tail waiting buffer
            // is the corresponding press, settle the key as tapped.
            if (waiting_buffer_tail != waiting_buffer_head && is_tap_record(keyp)) {
                keyrecord_t *tail = &waiting_buffer[waiting_buffer_tail];
                if (IS_EVENT(tail->event) && KEYEQ(tail->event.key, keyp->event.key) && tail->event.pressed) {
                    tail->tap.count = 1;
                    keyp->tap.count = 1;
                    process_record(tail);
                    // Pop tail from the queue.
                    waiting_buffer_tail = (waiting_buffer_tail + 1) % WAITING_BUFFER_SIZE;
                }
            }
#    endif
            // the current key is just a regular key, pass it on for regular
            // processing
            process_record(keyp);
        }

        return true;
    }

#    if (defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)) || defined(PERMISSIVE_HOLD_PER_KEY) || defined(CHORDAL_HOLD) || defined(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)
    TAP_DEFINE_KEYCODE;
#    endif

    // process "pressed" tapping key state
    if (tapping_key.event.pressed) {
        if (WITHIN_TAPPING_TERM(event) || MAYBE_RETRO_SHIFTING(event, keyp)) {
            if (IS_NOEVENT(event)) {
                // early return for tick events
                return true;
            }
#    ifdef CHORDAL_HOLD
            if (!event.pressed && multi_tap_sequence && waiting_buffer_typed(event)) {
                const uint8_t first_tap = waiting_buffer_find_chordal_hold_tap();

                // Settle and process the tapping key and waiting events
                // preceding first_tap as *held*.
                if (first_tap < WAITING_BUFFER_SIZE) {
                    ac_dprintf("Tapping: End. No tap. Interfered by typing key\n");
                    process_record(&tapping_key);
                    tapping_key = (keyrecord_t){0};
                    debug_tapping_key();

                    waiting_buffer_process_until(first_tap);
                }
                // enqueue
                return false;
            } else
#    endif
                if (tapping_key.tap.count == 0) {
                if (IS_TAPPING_RECORD(keyp) && !event.pressed) {
                    // first tap!
                    ac_dprintf("Tapping: First tap(0->1).\n");
                    tapping_key.tap.count = 1;
                    debug_tapping_key();
                    process_record(&tapping_key);

                    // copy tapping state
                    keyp->tap = tapping_key.tap;
                    // enqueue
                    return false;
                }
                /* Process a key typed within TAPPING_TERM
                 * This can register the key before settlement of tapping,
                 * useful for long TAPPING_TERM but may prevent fast typing.
                 */
                // clang-format off
                else if (
                    !event.pressed && waiting_buffer_typed(event) &&
                    (
                        TAP_GET_PERMISSIVE_HOLD ||
                        // Causes nested taps to not wait past TAPPING_TERM/RETRO_SHIFT
                        // unnecessarily and fixes them for Layer Taps.
                        TAP_GET_RETRO_TAPPING(keyp)
                    )
                ) {
                    // clang-format on
                    ac_dprintf("Tapping: End. No tap. Interfered by typing key\n");
                    process_record(&tapping_key);
                    tapping_key = (keyrecord_t){0};
                    debug_tapping_key();
                    // enqueue
                    return false;
                }
                /* Process release event of a key pressed before tapping starts
                 * Without this unexpected repeating will occur with having fast repeating setting
                 * https://github.com/tmk/tmk_keyboard/issues/60
                 */
                else if (!multi_tap_sequence && !event.pressed && !waiting_buffer_typed(event)) {
                    // Modifier/Layer should be retained till end of this tapping.
                    action_t action = layer_switch_get_action(event.key);
                    switch (action.kind.id) {
                        case ACT_LMODS:
                        case ACT_RMODS:
                            if (action.key.mods && !action.key.code) return false;
                            if (IS_MODIFIER_KEYCODE(action.key.code)) return false;
                            break;
                        case ACT_LMODS_TAP:
                        case ACT_RMODS_TAP:
                            if (action.key.mods && keyp->tap.count == 0) return false;
                            if (IS_MODIFIER_KEYCODE(action.key.code)) return false;
                            break;
                        case ACT_LAYER_TAP:
                        case ACT_LAYER_TAP_EXT:
                            switch (action.layer_tap.code) {
                                case 0 ...(OP_TAP_TOGGLE - 1):
                                case OP_ON_OFF:
                                case OP_OFF_ON:
                                case OP_SET_CLEAR:
                                    return false;
                            }
                            break;
                    }
                    // Release of key should be process immediately.
                    ac_dprintf("Tapping: release event of a key pressed before tapping\n");
                    process_record(keyp);
                    return true;
                } else {
                    // set interrupted flag when other key pressed during tapping
                    if (event.pressed) {
                        tapping_key.tap.interrupted = true;

#    if defined(CHORDAL_HOLD)
                        if (!is_one_shot(tapping_keycode) && !get_chordal_hold(tapping_keycode, &tapping_key, get_record_keycode(keyp, false), keyp)) {
                            // In process_action(), HOLD_ON_OTHER_KEY_PRESS
                            // will revert interrupted events to holds, so
                            // this needs to be set false.
                            tapping_key.tap.interrupted = false;

                            if (is_tap_record(keyp)) {
                                // Multiple tap-hold keys are unsettled.
                                multi_tap_sequence = true;
                            } else {
                                // Settle the tapping key as *tapped*, since it
                                // is not considered a held chord with keyp.
                                ac_dprintf("Tapping: End. Chord considered a tap\n");
                                tapping_key.tap.count = 1;
                                process_record(&tapping_key);
                                debug_tapping_key();

                                // Process regular keys in the waiting buffer.
                                waiting_buffer_process_regular();
                            }
                        } else
#    endif
                            if (TAP_GET_HOLD_ON_OTHER_KEY_PRESS
#    if defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)
                                // Auto Shift cannot evaluate this early
                                // Retro Shift uses the hold action for all nested taps even without HOLD_ON_OTHER_KEY_PRESS, so this is fine to skip
                                && !(MAYBE_RETRO_SHIFTING(event, keyp) && get_auto_shifted_key(get_record_keycode(keyp, false), keyp))
#    endif
                            ) {
                            // Settle the tapping key as *held*, since
                            // HOLD_ON_OTHER_KEY_PRESS is enabled for this key.
                            ac_dprintf("Tapping: End. No tap. Interfered by pressed key\n");
                            process_record(&tapping_key);
                            tapping_key = (keyrecord_t){0};
                            debug_tapping_key();
                        }
                    }
                    // enqueue
                    return false;
                }
            }
            // tap_count > 0
            else {
                if (IS_TAPPING_RECORD(keyp) && !event.pressed) {
                    ac_dprintf("Tapping: Tap release(%u)\n", tapping_key.tap.count);
                    keyp->tap = tapping_key.tap;
                    process_record(keyp);
                    tapping_key = *keyp;
                    debug_tapping_key();
                    return true;
                } else if (is_tap_record(keyp) && event.pressed) {
                    if (tapping_key.tap.count > 1) {
                        ac_dprintf("Tapping: Start new tap with releasing last tap(>1).\n");
                        // unregister key
                        process_record(&(keyrecord_t){
                            .tap           = tapping_key.tap,
                            .event.key     = tapping_key.event.key,
                            .event.time    = event.time,
                            .event.pressed = false,
                            .event.type    = tapping_key.event.type,
#    ifdef COMBO_ENABLE
                            .keycode = tapping_key.keycode,
#    endif
                        });
                    } else {
                        ac_dprintf("Tapping: Start while last tap(1).\n");
                    }
                    tapping_key = *keyp;
                    waiting_buffer_scan_tap();
                    debug_tapping_key();
                    return true;
                } else {
                    ac_dprintf("Tapping: key event while last tap(>0).\n");
#    if defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT)
                    retroshift_swap_times();
#    endif
                    process_record(keyp);
                    return true;
                }
            }
        }
        // after TAPPING_TERM
        else {
            if (tapping_key.tap.count == 0) {
                ac_dprintf("Tapping: End. Timeout. Not tap(0): ");
                debug_event(event);
                ac_dprintf("\n");
                process_record(&tapping_key);
                tapping_key = (keyrecord_t){0};
                debug_tapping_key();
                return false;
            } else {
                if (IS_NOEVENT(event)) {
                    return true;
                }
                if (IS_TAPPING_RECORD(keyp) && !event.pressed) {
                    ac_dprintf("Tapping: End. last timeout tap release(>0).");
                    keyp->tap = tapping_key.tap;
                    process_record(keyp);
                    tapping_key = (keyrecord_t){0};
                    return true;
                } else if (is_tap_record(keyp) && event.pressed) {
                    if (tapping_key.tap.count > 1) {
                        ac_dprintf("Tapping: Start new tap with releasing last timeout tap(>1).\n");
                        // unregister key
                        process_record(&(keyrecord_t){
                            .tap           = tapping_key.tap,
                            .event.key     = tapping_key.event.key,
                            .event.time    = event.time,
                            .event.pressed = false,
                            .event.type    = tapping_key.event.type,
#    ifdef COMBO_ENABLE
                            .keycode = tapping_key.keycode,
#    endif
                        });
                    } else {
                        ac_dprintf("Tapping: Start while last timeout tap(1).\n");
                    }
                    tapping_key = *keyp;
                    waiting_buffer_scan_tap();
                    debug_tapping_key();
                    return true;
                } else {
                    ac_dprintf("Tapping: key event while last timeout tap(>0).\n");
                    process_record(keyp);
                    return true;
                }
            }
        }
    }
    // process "released" tapping key state
    else {
        if (WITHIN_TAPPING_TERM(event) || MAYBE_RETRO_SHIFTING(event, keyp)) {
            if (IS_NOEVENT(event)) {
                // early return for tick events
                return true;
            }
            if (event.pressed) {
                if (IS_TAPPING_RECORD(keyp)) {
                    if (WITHIN_QUICK_TAP_TERM(event) && !tapping_key.tap.interrupted && tapping_key.tap.count > 0) {
                        // sequential tap.
                        keyp->tap = tapping_key.tap;
                        if (keyp->tap.count < 15) keyp->tap.count += 1;
                        ac_dprintf("Tapping: Tap press(%u)\n", keyp->tap.count);
                        process_record(keyp);
                        tapping_key = *keyp;
                        debug_tapping_key();
                        return true;
                    }
                    // FIX: start new tap again
                    tapping_key = *keyp;
                    return true;
                } else if (is_tap_record(keyp)) {
                    // Sequential tap can be interfered with other tap key.
                    ac_dprintf("Tapping: Start with interfering other tap.\n");
                    tapping_key = *keyp;
                    waiting_buffer_scan_tap();
                    debug_tapping_key();
                    return true;
                } else {
                    // should none in buffer
                    // FIX: interrupted when other key is pressed
                    tapping_key.tap.interrupted = true;
                    process_record(keyp);
                    return true;
                }
            } else {
                ac_dprintf("Tapping: other key just after tap.\n");
                process_record(keyp);
                return true;
            }
        } else {
            // Timeout - reset state machine.
            ac_dprintf("Tapping: End(Timeout after releasing last tap): ");
            debug_event(event);
            ac_dprintf("\n");
            tapping_key = (keyrecord_t){0};
            debug_tapping_key();
            return false;
        }
    }
}

/** \brief Waiting buffer enq
 *
 * FIXME: Needs docs
 */
bool waiting_buffer_enq(keyrecord_t record) {
    if (IS_NOEVENT(record.event)) {
        return true;
    }

    if ((waiting_buffer_head + 1) % WAITING_BUFFER_SIZE == waiting_buffer_tail) {
        ac_dprintf("waiting_buffer_enq: Over flow.\n");
        return false;
    }

    waiting_buffer[waiting_buffer_head] = record;
    waiting_buffer_head                 = (waiting_buffer_head + 1) % WAITING_BUFFER_SIZE;

    ac_dprintf("waiting_buffer_enq: ");
    debug_waiting_buffer();
    return true;
}

/** \brief Waiting buffer clear
 *
 * FIXME: Needs docs
 */
void waiting_buffer_clear(void) {
    waiting_buffer_head = 0;
    waiting_buffer_tail = 0;
}

/** \brief Waiting buffer typed
 *
 * FIXME: Needs docs
 */
bool waiting_buffer_typed(keyevent_t event) {
    for (uint8_t i = waiting_buffer_tail; i != waiting_buffer_head; i = (i + 1) % WAITING_BUFFER_SIZE) {
        if (KEYEQ(event.key, waiting_buffer[i].event.key) && event.pressed != waiting_buffer[i].event.pressed) {
            return true;
        }
    }
    return false;
}

/** \brief Waiting buffer has anykey pressed
 *
 * FIXME: Needs docs
 */
__attribute__((unused)) bool waiting_buffer_has_anykey_pressed(void) {
    for (uint8_t i = waiting_buffer_tail; i != waiting_buffer_head; i = (i + 1) % WAITING_BUFFER_SIZE) {
        if (waiting_buffer[i].event.pressed) return true;
    }
    return false;
}

/** \brief Scan buffer for tapping
 *
 * FIXME: Needs docs
 */
void waiting_buffer_scan_tap(void) {
    // early return if:
    // - tapping already is settled
    // - invalid state: tapping_key released && tap.count == 0
    if ((tapping_key.tap.count > 0) || !tapping_key.event.pressed) {
        return;
    }

#    if (defined(AUTO_SHIFT_ENABLE) && defined(RETRO_SHIFT))
    TAP_DEFINE_KEYCODE;
#    endif
    for (uint8_t i = waiting_buffer_tail; i != waiting_buffer_head; i = (i + 1) % WAITING_BUFFER_SIZE) {
        keyrecord_t *candidate = &waiting_buffer[i];
        // clang-format off
        if (IS_EVENT(candidate->event) && KEYEQ(candidate->event.key, tapping_key.event.key) && !candidate->event.pressed && (
            WITHIN_TAPPING_TERM(waiting_buffer[i].event) || MAYBE_RETRO_SHIFTING(waiting_buffer[i].event, &tapping_key)
        )) {
            // clang-format on
            tapping_key.tap.count = 1;
            candidate->tap.count  = 1;
            process_record(&tapping_key);

            ac_dprintf("waiting_buffer_scan_tap: found at [%u]\n", i);
            debug_waiting_buffer();
            return;
        }
    }
}

#    ifdef CHORDAL_HOLD
__attribute__((weak)) bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_chordal_hold_default(keyrecord_t *tap_hold_record, keyrecord_t *other_record) {
    if (tap_hold_record->event.type != KEY_EVENT || other_record->event.type != KEY_EVENT) {
        return true; // Return true on combos or other non-key events.
    }

    char tap_hold_hand = chordal_hold_handedness_user(tap_hold_record->event.key);
    if (tap_hold_hand == '*') {
        return true;
    }
    char other_hand = chordal_hold_handedness_user(other_record->event.key);
    return other_hand == '*' || tap_hold_hand != other_hand;
}

__attribute__((weak)) char chordal_hold_handedness_kb(keypos_t key) {
#        if defined(SPLIT_KEYBOARD) || ((MATRIX_ROWS) > (MATRIX_COLS))
    // If the keyboard is split or if MATRIX_ROWS > MATRIX_COLS, assume that the
    // first half of the rows are left and the latter half are right.
    return (key.row < (MATRIX_ROWS) / 2) ? /*left*/ 'L' : /*right*/ 'R';
#        else
    // Otherwise, assume the first half of the cols are left, others are right.
    return (key.col < (MATRIX_COLS) / 2) ? /*left*/ 'L' : /*right*/ 'R';
#        endif
}

__attribute__((weak)) char chordal_hold_handedness_user(keypos_t key) {
#        if defined(CHORDAL_HOLD_LAYOUT)
    // If given, read handedness from `chordal_hold_layout` array.
    return (char)pgm_read_byte(&chordal_hold_layout[key.row][key.col]);
#        else
    return chordal_hold_handedness_kb(key);
#        endif
}

/** \brief Finds which queued events should be held according to Chordal Hold.
 *
 * In a situation with multiple unsettled tap-hold key presses, scan the queue
 * up until the first release, non-tap-hold, or one-shot event and find the
 * lastest event in the queue that settles as held according to
 * get_chordal_hold().
 *
 * \return Index of the first tap, or equivalently, one past the latest hold.
 */
static uint8_t waiting_buffer_find_chordal_hold_tap(void) {
    keyrecord_t *prev         = &tapping_key;
    uint16_t     prev_keycode = get_record_keycode(&tapping_key, false);
    uint8_t      first_tap    = WAITING_BUFFER_SIZE;

    for (uint8_t i = waiting_buffer_tail; i != waiting_buffer_head; i = (i + 1) % WAITING_BUFFER_SIZE) {
        keyrecord_t *  cur         = &waiting_buffer[i];
        const uint16_t cur_keycode = get_record_keycode(cur, false);

        if (!cur->event.pressed || !is_tap_record(prev) || is_one_shot(prev_keycode)) {
            break;
        } else if (get_chordal_hold(prev_keycode, prev, cur_keycode, cur)) {
            first_tap = i; // Track one index past the latest hold.
        }

        prev         = cur;
        prev_keycode = cur_keycode;
    }

    return first_tap;
}

/** \brief Processes and pops buffered events preceding `new_tail`. */
static void waiting_buffer_process_until(uint8_t new_tail) {
    for (; waiting_buffer_tail != new_tail; waiting_buffer_tail = (waiting_buffer_tail + 1) % WAITING_BUFFER_SIZE) {
        ac_dprintf("waiting_buffer_process_until: processing [%u]\n", waiting_buffer_tail);
        process_record(&waiting_buffer[waiting_buffer_tail]);
    }

    debug_waiting_buffer();
}

/** \brief Processes and pops buffered events until the first tap-hold event. */
static void waiting_buffer_process_regular(void) {
    for (; waiting_buffer_tail != waiting_buffer_head; waiting_buffer_tail = (waiting_buffer_tail + 1) % WAITING_BUFFER_SIZE) {
        if (is_tap_record(&waiting_buffer[waiting_buffer_tail])) {
            break; // Stop once a tap-hold key event is reached.
        }
        ac_dprintf("waiting_buffer_process_regular: processing [%u]\n", waiting_buffer_tail);
        process_record(&waiting_buffer[waiting_buffer_tail]);
    }

    debug_waiting_buffer();
}
#    endif // CHORDAL_HOLD

/** \brief Logs tapping key if ACTION_DEBUG is enabled. */
static void debug_tapping_key(void) {
    ac_dprintf("TAPPING_KEY=");
    debug_record(tapping_key);
    ac_dprintf("\n");
}

/** \brief Logs waiting buffer if ACTION_DEBUG is enabled. */
static void debug_waiting_buffer(void) {
    ac_dprintf("{");
    for (uint8_t i = waiting_buffer_tail; i != waiting_buffer_head; i = (i + 1) % WAITING_BUFFER_SIZE) {
        ac_dprintf(" [%u]=", i);
        debug_record(waiting_buffer[i]);
    }
    ac_dprintf("}\n");
}

#endif
