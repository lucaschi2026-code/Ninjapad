#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Fusion 360
    [0] = LAYOUT(
        LCS(KC_M),      KC_E,           KC_S,
        KC_F,           KC_Q,           LCTL(KC_Z),
        LCTL(KC_S),     KC_M,           KC_V
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}

void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(GP4);
}

void matrix_scan_user(void) {
    if (!gpio_read_pin(GP4)) {
        tap_code(KC_MUTE);
        wait_ms(200);
    }
}