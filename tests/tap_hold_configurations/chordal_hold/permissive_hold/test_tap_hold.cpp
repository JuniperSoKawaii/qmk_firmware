// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "test_common.hpp"
#include "action_tapping.h"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"

using testing::_;
using testing::InSequence;

class ChordalHoldPermissiveHold : public TestFixture {};

TEST_F(ChordalHoldPermissiveHold, chordal_hold_handedness) {
    EXPECT_EQ(chordal_hold_handedness({.col = 0, .row = 0}), 'L');
    EXPECT_EQ(chordal_hold_handedness({.col = MATRIX_COLS - 1, .row = 0}), 'R');
    EXPECT_EQ(chordal_hold_handedness({.col = 0, .row = 2}), '*');
}

TEST_F(ChordalHoldPermissiveHold, get_chordal_hold_default) {
    auto make_record = [](uint8_t row, uint8_t col, keyevent_type_t type = KEY_EVENT) {
        return keyrecord_t{
            .event =
                {
                    .key     = {.col = col, .row = row},
                    .type    = type,
                    .pressed = true,
                },
        };
    };
    // Create two records on the left hand.
    keyrecord_t record_l0 = make_record(0, 0);
    keyrecord_t record_l1 = make_record(1, 0);
    // Create a record on the right hand.
    keyrecord_t record_r = make_record(0, MATRIX_COLS - 1);

    // Function should return true when records are on opposite hands.
    EXPECT_TRUE(get_chordal_hold_default(&record_l0, &record_r));
    EXPECT_TRUE(get_chordal_hold_default(&record_r, &record_l0));
    // ... and false when on the same hand.
    EXPECT_FALSE(get_chordal_hold_default(&record_l0, &record_l1));
    EXPECT_FALSE(get_chordal_hold_default(&record_l1, &record_l0));
    // But (2, 0) has handedness '*', for which true is returned for chords
    // with either hand.
    keyrecord_t record_l2 = make_record(2, 0);
    EXPECT_TRUE(get_chordal_hold_default(&record_l2, &record_l0));
    EXPECT_TRUE(get_chordal_hold_default(&record_l2, &record_r));

    // Create a record resulting from a combo.
    keyrecord_t record_combo = make_record(0, 0, COMBO_EVENT);
    // Function returns true in all cases.
    EXPECT_TRUE(get_chordal_hold_default(&record_l0, &record_combo));
    EXPECT_TRUE(get_chordal_hold_default(&record_r, &record_combo));
    EXPECT_TRUE(get_chordal_hold_default(&record_combo, &record_l0));
    EXPECT_TRUE(get_chordal_hold_default(&record_combo, &record_r));
}

TEST_F(ChordalHoldPermissiveHold, chord_nested_press_settled_as_hold) {
    TestDriver driver;
    InSequence s;
    // Mod-tap key on the left hand.
    auto mod_tap_key = KeymapKey(0, 1, 0, SFT_T(KC_P));
    // Regular key on the right hand.
    auto regular_key = KeymapKey(0, MATRIX_COLS - 1, 0, KC_A);

    set_keymap({mod_tap_key, regular_key});

    // Press mod-tap key.
    EXPECT_NO_REPORT(driver);
    mod_tap_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Tap regular key.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_A));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    tap_key(regular_key);
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap key.
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, chord_rolled_press_settled_as_tap) {
    TestDriver driver;
    InSequence s;
    // Mod-tap key on the left hand.
    auto mod_tap_key = KeymapKey(0, 1, 0, SFT_T(KC_P));
    // Regular key on the right hand.
    auto regular_key = KeymapKey(0, MATRIX_COLS - 1, 0, KC_A);

    set_keymap({mod_tap_key, regular_key});

    // Press mod-tap key and regular key.
    EXPECT_NO_REPORT(driver);
    mod_tap_key.press();
    run_one_scan_loop();
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap key.
    EXPECT_REPORT(driver, (KC_P));
    EXPECT_REPORT(driver, (KC_P, KC_A));
    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release regular key.
    EXPECT_EMPTY_REPORT(driver);
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, non_chord_with_mod_tap_settled_as_tap) {
    TestDriver driver;
    InSequence s;
    // Mod-tap key and regular key both on the left hand.
    auto mod_tap_key = KeymapKey(0, 1, 0, SFT_T(KC_P));
    auto regular_key = KeymapKey(0, 2, 0, KC_A);

    set_keymap({mod_tap_key, regular_key});

    // Press mod-tap-hold key.
    EXPECT_NO_REPORT(driver);
    mod_tap_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press regular key.
    EXPECT_REPORT(driver, (KC_P));
    EXPECT_REPORT(driver, (KC_P, KC_A));
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release regular key.
    EXPECT_REPORT(driver, (KC_P));
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap-hold key.
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, tap_mod_tap_key) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key = KeymapKey(0, 1, 0, SFT_T(KC_P));

    set_keymap({mod_tap_key});

    EXPECT_NO_REPORT(driver);
    mod_tap_key.press();
    idle_for(TAPPING_TERM - 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_P));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, hold_mod_tap_key) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key = KeymapKey(0, 1, 0, SFT_T(KC_P));

    set_keymap({mod_tap_key});

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    mod_tap_key.press();
    idle_for(TAPPING_TERM + 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, two_mod_taps_same_hand_hold_til_timeout) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, MATRIX_COLS - 2, 0, RCTL_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, MATRIX_COLS - 1, 0, RSFT_T(KC_B));

    set_keymap({mod_tap_key1, mod_tap_key2});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Continue holding til the tapping term.
    EXPECT_REPORT(driver, (KC_A, KC_RIGHT_SHIFT));
    idle_for(TAPPING_TERM);
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap keys.
    EXPECT_REPORT(driver, (KC_RIGHT_SHIFT));
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, two_mod_taps_nested_press_opposite_hands) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, MATRIX_COLS - 1, 0, RSFT_T(KC_B));

    set_keymap({mod_tap_key1, mod_tap_key2});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap keys.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, two_mod_taps_nested_press_same_hand) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, 2, 0, RSFT_T(KC_B));

    set_keymap({mod_tap_key1, mod_tap_key2});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release mod-tap keys.
    EXPECT_REPORT(driver, (KC_A, KC_B));
    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.release();
    run_one_scan_loop();

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, three_mod_taps_same_hand_streak_roll) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, 2, 0, CTL_T(KC_B));
    auto       mod_tap_key3 = KeymapKey(0, 3, 0, RSFT_T(KC_C));

    set_keymap({mod_tap_key1, mod_tap_key2, mod_tap_key3});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_B));
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 1, 2, 3.
    //
    // NOTE: The correct order of events should be
    // EXPECT_REPORT(driver, (KC_A, KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_C));
    // EXPECT_EMPTY_REPORT(driver);
    //
    // However, due to a workaround for https://github.com/tmk/tmk_keyboard/issues/60,
    // the events are processed out of order, with the first two keys released
    // before pressing KC_C.
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_C));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    mod_tap_key3.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, three_mod_taps_same_hand_streak_orders) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, 2, 0, CTL_T(KC_B));
    auto       mod_tap_key3 = KeymapKey(0, 3, 0, RSFT_T(KC_C));

    set_keymap({mod_tap_key1, mod_tap_key2, mod_tap_key3});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_B));
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 3, 2, 1.
    EXPECT_REPORT(driver, (KC_A, KC_B, KC_C));
    EXPECT_REPORT(driver, (KC_A, KC_B));
    EXPECT_REPORT(driver, (KC_A));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key3.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_B));
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 3, 1, 2.
    EXPECT_REPORT(driver, (KC_A, KC_B, KC_C));
    EXPECT_REPORT(driver, (KC_A, KC_B));
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key3.release();
    run_one_scan_loop();
    mod_tap_key1.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A, KC_B));
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 2, 3, 1.
    //
    // NOTE: The correct order of events should be
    // EXPECT_REPORT(driver, (KC_A, KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_A, KC_C));
    // EXPECT_REPORT(driver, (KC_A));
    // EXPECT_EMPTY_REPORT(driver);
    //
    // However, due to a workaround for https://github.com/tmk/tmk_keyboard/issues/60,
    // the events are processed out of order.
    EXPECT_REPORT(driver, (KC_A));
    EXPECT_REPORT(driver, (KC_A, KC_C));
    EXPECT_REPORT(driver, (KC_A));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key2.release();
    run_one_scan_loop();
    mod_tap_key3.release();
    run_one_scan_loop();
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, three_mod_taps_opposite_hands_roll) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, 2, 0, CTL_T(KC_B));
    auto       mod_tap_key3 = KeymapKey(0, MATRIX_COLS - 1, 0, RSFT_T(KC_C));

    set_keymap({mod_tap_key1, mod_tap_key2, mod_tap_key3});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 1, 2, 3.
    //
    // NOTE: The correct order of events should be
    // EXPECT_REPORT(driver, (KC_A, KC_B));
    // EXPECT_REPORT(driver, (KC_A, KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_C));
    // EXPECT_EMPTY_REPORT(driver);
    //
    // However, due to a workaround for https://github.com/tmk/tmk_keyboard/issues/60,
    // the events are processed out of order, with the first two keys released
    // before pressing KC_C.

    // Release keys 1, 2, 3.
    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_C));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    mod_tap_key3.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, three_mod_taps_two_left_one_right) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, 2, 0, CTL_T(KC_B));
    auto       mod_tap_key3 = KeymapKey(0, MATRIX_COLS - 1, 0, RSFT_T(KC_C));

    set_keymap({mod_tap_key1, mod_tap_key2, mod_tap_key3});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release key 3.
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL));
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL, KC_C));
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL));
    mod_tap_key3.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release key 2, then key 1.
    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM);
    mod_tap_key1.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_A));
    mod_tap_key2.press();
    run_one_scan_loop();

    EXPECT_NO_REPORT(driver);
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release key 3.
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL));
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL, KC_C));
    EXPECT_REPORT(driver, (KC_A, KC_LEFT_CTRL));
    mod_tap_key3.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release key 1, then key 2.
    EXPECT_REPORT(driver, (KC_LEFT_CTRL));
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, three_mod_taps_one_held_two_tapped) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, MATRIX_COLS - 2, 0, CTL_T(KC_B));
    auto       mod_tap_key3 = KeymapKey(0, MATRIX_COLS - 1, 0, RSFT_T(KC_C));

    set_keymap({mod_tap_key1, mod_tap_key2, mod_tap_key3});

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    mod_tap_key2.press();
    run_one_scan_loop();
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 3, 2, 1.
    //
    // NOTE: The correct order of events should be
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    // EXPECT_EMPTY_REPORT(driver);
    //
    // However, due to a workaround for https://github.com/tmk/tmk_keyboard/issues/60,
    // the events are processed out of order.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_C));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key3.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM);
    mod_tap_key1.press();
    run_one_scan_loop();
    mod_tap_key2.press();
    run_one_scan_loop();
    mod_tap_key3.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys 3, 1, 2.
    //
    // NOTE: The correct order of events should be
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B, KC_C));
    // EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    // EXPECT_REPORT(driver, (KC_B));
    // EXPECT_EMPTY_REPORT(driver);
    //
    // However, due to a workaround for https://github.com/tmk/tmk_keyboard/issues/60,
    // the events are processed out of order.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_REPORT(driver, (KC_B, KC_C));
    EXPECT_REPORT(driver, (KC_B));
    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key3.release();
    run_one_scan_loop();
    mod_tap_key1.release();
    run_one_scan_loop();
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ChordalHoldPermissiveHold, two_mod_taps_one_regular_key) {
    TestDriver driver;
    InSequence s;
    auto       mod_tap_key1 = KeymapKey(0, 1, 0, SFT_T(KC_A));
    auto       mod_tap_key2 = KeymapKey(0, MATRIX_COLS - 2, 0, CTL_T(KC_B));
    auto       regular_key  = KeymapKey(0, MATRIX_COLS - 1, 0, KC_C);

    set_keymap({mod_tap_key1, mod_tap_key2, regular_key});

    // Press keys.
    EXPECT_NO_REPORT(driver);
    mod_tap_key1.press();
    run_one_scan_loop();
    mod_tap_key2.press();
    run_one_scan_loop();
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B, KC_C));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_C));
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Press mod-tap keys.
    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM);
    mod_tap_key1.press();
    run_one_scan_loop();
    mod_tap_key2.press();
    run_one_scan_loop();
    regular_key.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    // Release keys.
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B, KC_C));
    EXPECT_REPORT(driver, (KC_LEFT_SHIFT, KC_B));
    regular_key.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_B));
    mod_tap_key1.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    mod_tap_key2.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}
