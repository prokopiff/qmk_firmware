/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum torn_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };

#define S_BSPC LSFT_T(KC_BSPC)
#define R_DEL LT(_RAISE, KC_DEL)
#define G_ENT LGUI_T(KC_ENT)
#define L_SPC LT(_LOWER, KC_SPC)
#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)

#define NBS_LCT MT(MOD_LCTL, KC_NUBS)
#define BSH_LAL MT(MOD_LALT, KC_BSLS)
#define APP_RAL MT(MOD_RALT, KC_APP)

#define BSP_RSH MT(MOD_RSFT, KC_BSPC)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define DEL_LWR LT(_LOWER, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ENT_RSE LT(_RAISE, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)
#define BSP_LWR LT(_LOWER, KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_split_3x6_4(
    KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,        KC_O,    KC_P,    KC_LBRC,
    LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,        KC_L,    KC_SCLN, KC_QUOT,
    KC_LALT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM,     KC_DOT,  KC_SLSH, MT(MOD_RCTL, KC_RBRC),
                             KC_LGUI, BSP_LWR, SPC_LSH, ENT_RSE,      ENT_RSE, SPC_RSH, DEL_LWR,     KC_LGUI
),

[_LOWER] = LAYOUT_split_3x6_4(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_INS,
                      _______, _______, _______, _______,      _______, _______, _______, _______
),

[_RAISE] = LAYOUT_split_3x6_4(
    KC_GRAVE, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_EQL,  KC_HOME, KC_UP,     KC_PGUP, _______,   KC_LGUI,
    _______,  KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_VOLU, KC_LEFT, KC_DOWN,   KC_RGHT, C(KC_TAB), KC_BSLS,
    KC_NLCK,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PCMM,      KC_VOLD, KC_END,  KC_PSCR,   KC_PGDN, _______,   KC_RCTL,
                       _______, _______, _______, _______,      _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_split_3x6_4(
    _______,  _______, _______, _______, RESET,   EEP_RST,     EEP_RST, RESET,    _______,  _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,     _______, _______,  _______,  _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,     _______, _______,  _______,  _______, _______, _______,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _RAISE));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _LOWER));
    return state;
}
