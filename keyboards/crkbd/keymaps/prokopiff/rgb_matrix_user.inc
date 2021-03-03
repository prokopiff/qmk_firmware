RGB_MATRIX_EFFECT(SPECIMEN)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t is_master;

bool SPECIMEN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (is_master) {
            if (i == 23 || i == 24 || i == 25) { // Purple
                rgb_matrix_set_color(i, 13, 0, 40);
            } else if (i == 18 || i == 22 || i == 26) {  // Pink
                rgb_matrix_set_color(i, 69, 0, 11);
            } else if (i == 17 || i == 19 || i == 21) { // Orange
                rgb_matrix_set_color(i, 69, 13, 0);
            } else {
                rgb_matrix_set_color(i, 15, 69, 19);
            }
        } else {
            rgb_matrix_set_color(i, 15, 69, 19);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
