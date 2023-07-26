/*
Copyright 2022 Tvrd Rad Keyboards

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* Key matrix pins */
#define MATRIX_ROW_PINS { F5, F4, F1, F0, B7 }
#define MATRIX_COL_PINS { B3, B2, D2, D3, C6, C7, D5, F6, F7, B6, B5, B4, D7, D6, D4 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* EEPROM Driver Configuration */
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

/* Encoder Configuration */
#define ENCODERS_PAD_A { B0 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

/* RGB underglow */
#define RGB_DI_PIN E6
#define RGBLED_NUM 19
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 10
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_LIMIT_VAL 127 /* 255 The maximum brightness level */
#define RGBLIGHT_SLEEP
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_LAYERS
#define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 19
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 3
#define RGBLIGHT_EFFECT_KNIGHT_OFFSET 0
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
#define RGBLIGHT_EFFECT_BREATHE_MAX 255   // 0 to 255
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 255
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 3
