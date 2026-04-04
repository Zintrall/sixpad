// Copyright 2024 zin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define the layers
enum layer_names {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3
};

bool oled_task_user(void) {
    oled_write_P(PSTR("Layer "), false);

    oled_write(get_u8_str(get_highest_layer(default_layer_state), ' '), false);

    return false;
}


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN) },
    [_LAYER1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LAYER2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LAYER3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_7, KC_8, DF(3),
        KC_4, KC_5, KC_6
    ),
    [_LAYER1] = LAYOUT(
        KC_A, KC_B, DF(3),
        KC_C, KC_D, KC_E
    ),
    [_LAYER2] = LAYOUT(
        KC_X, KC_Y, DF(3),
        KC_Z, KC_R, KC_D
    ),
    [_LAYER3] = LAYOUT(
        DF(0), DF(1), DF(2),
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};
