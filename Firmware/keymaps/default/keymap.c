// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ├───┼───┼───┼
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┼
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┼
     */
    [0] = LAYOUT(
        KC_P4,   KC_P5,   KC_P6
        KC_P1,   KC_P2,   KC_P3
    )
};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Hello World"), false);

    return false;
}
#endif
