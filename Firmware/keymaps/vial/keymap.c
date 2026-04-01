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
    // Vypíše slovo "Layer "
    oled_write_P(PSTR("Layer "), false);

    // Zjistí číslo aktuální vrstvy a převede ho na text
    oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);

    return false;
}


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP) },
    [_LAYER1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LAYER2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LAYER3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_P7, KC_P8, KC_P9,
        KC_P4, KC_P5, KC_P6
    ),
    [_LAYER1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_P1,   KC_P2,   KC_P3
    ),
    [_LAYER2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_A,    KC_B,    KC_C
    ),
    [_LAYER3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_D,    KC_E,    KC_F
    )
};
