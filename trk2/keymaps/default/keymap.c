/* Copyright 2022 Tvrd Rad Keyboards
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    L_BASE,
    L_FN,
    L_EXTRA
};

// RGB_TOG - On off led

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_70(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,   KC_EQUAL,   KC_KP_SLASH,    KC_KP_ASTERISK,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,        KC_HOME,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_MUTE,    KC_SCLN,    KC_QUOTE,   KC_ENTER,       KC_END,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,                 KC_SLASH,   KC_RSFT,    KC_UP,          KC_DELETE,
        KC_LCTL,    KC_LGUI,    KC_LALT,                KC_SPACE,   KC_B,       KC_BSPC,                MO(L_FN),                           KC_RCTL,    KC_LEFT,    KC_DOWN,        KC_RIGHT),
    [L_FN] = LAYOUT_70(
        QK_BOOT,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PMNS,        KC_PPLS,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        KC_PGUP,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        KC_PGDN,
        _______,    RGB_VAI,    RGB_VAD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    RGB_HUI,        _______,
        RGB_TOG,    _______,    _______,                _______,    _______,    _______,                _______,                            _______,    RGB_MOD,    RGB_HUD,        RGB_RMOD),
    [L_EXTRA] = LAYOUT_70(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,        _______,
        _______,    _______,    _______,                _______,    _______,    _______,                _______,                            _______,    _______,    _______,        _______),
};

const rgblight_segment_t PROGMEM my_0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_RED}
);

const rgblight_segment_t PROGMEM my_1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},
	{18, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE},
	{18, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 19, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_layers[] = RGBLIGHT_LAYERS_LIST(
    my_0_layer,
	my_1_layer,
    my_2_layer,
	my_caps_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_layers;
	layer_state_set_user(layer_state);
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
	rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
};

 bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.caps_lock);
    return true;
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [L_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L_FN] = {ENCODER_CCW_CW(RGB_VAD,RGB_VAI)},
    [L_EXTRA] = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
