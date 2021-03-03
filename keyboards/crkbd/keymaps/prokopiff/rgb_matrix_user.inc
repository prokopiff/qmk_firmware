RGB_MATRIX_EFFECT(SPECIMEN)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t is_master;


void set_color_scaled(int i, uint8_t r, uint8_t g, uint8_t b, float scale) {
    rgb_matrix_set_color(i, (uint8_t)(r * scale), (uint8_t)(g * scale), (uint8_t)(b * scale));
}

bool SPECIMEN(effect_params_t* params) {

    int v = rgb_matrix_config.hsv.v;
    float scale = v * 1. / RGB_MATRIX_MAXIMUM_BRIGHTNESS;

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (is_master) {
            if (i == 23 || i == 24 || i == 25) { // Purple
                set_color_scaled(i, 13, 0, 40, scale);
            } else if (i == 18 || i == 22 || i == 26) {  // Pink
                set_color_scaled(i, 69, 0, 11, scale);
            } else if (i == 17 || i == 19 || i == 21) { // Orange
                set_color_scaled(i, 69, 13, 0, scale);
            } else {
                set_color_scaled(i, 15, 69, 19, scale);
            }
        } else {
            set_color_scaled(i, 15, 69, 19, scale);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
