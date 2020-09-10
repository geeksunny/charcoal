/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#ifndef CHARCOAL__QMK_RGB_MATRIX_TYPES_H_
#define CHARCOAL__QMK_RGB_MATRIX_TYPES_H_

#include <cstdint>
#include "ergodox_ez_config.h"
#include "qmk_rgb.h"
#include "qmk_led_types.h"

typedef struct PACKED {
  uint8_t     iter;
  led_flags_t flags;
  bool        init;
} effect_params_t;

typedef struct PACKED {
  uint8_t x;
  uint8_t y;
} point_t;

#define NO_LED 255

typedef struct PACKED {
  uint8_t matrix_co[MATRIX_ROWS][MATRIX_COLS];
  point_t point[DRIVER_LED_TOTAL];
  uint8_t flags[DRIVER_LED_TOTAL];
} led_config_t;

typedef union {
  uint32_t raw;
  struct PACKED {
    uint8_t enable : 2;
    uint8_t mode : 6;
    HSV     hsv;
    uint8_t speed;  // EECONFIG needs to be increased to support this
  };
} rgb_config_t;

typedef HSV (*i_f)(HSV hsv, uint8_t i, uint8_t time);

#endif //CHARCOAL__QMK_RGB_MATRIX_TYPES_H_
