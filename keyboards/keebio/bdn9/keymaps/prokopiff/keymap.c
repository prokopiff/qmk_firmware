#include QMK_KEYBOARD_H

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |             | Knob 2: Brightness Dn/Up |
        | Press: Mute       | RGB Mode    | Press: Prtscr         |
        | Hold: Layer 2     | Scroll Down | Scroll Up            |
        | Previous Track    | Pause       | Next Track           |
     */
    [0] = LAYOUT(
        KC_MUTE, MO(2),   KC_PSCR,
        MO(1)  , _______ /*TODO*/, LGUI(KC_SPC),
        KC_MPRV, KC_MPLY, KC_MNXT
    ),
    /*
        | RGB toggle | BAcklight step | N/A         |
        | N/A        | Mouse Up       | Left click  |
        | Mouse Left | Mouse Down     | Mouse Right |
     */
    [1] = LAYOUT(
        RGB_TOG, BL_STEP, _______,
        _______, KC_MS_U, KC_BTN1,
        KC_MS_L, KC_MS_D, KC_MS_R
    ),
    [2] = LAYOUT(
        RGB_M_P, _______, RGB_MOD,
        RGB_HUD, RGB_SAD, RGB_VAD,
        RGB_HUI, RGB_SAI, RGB_VAI
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
}
