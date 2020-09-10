/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#include "ergodox_ez_config.h"

uint8_t scale8( uint8_t i, uint8_t scale) {
  return (((uint16_t)i) * (1+(uint16_t)(scale))) >> 8;
}
