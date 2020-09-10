/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#ifndef CHARCOAL__ERGODOX_EZ_CONFIG_H_
#define CHARCOAL__ERGODOX_EZ_CONFIG_H_

#include <cstdint>

/* key matrix size */
#define MATRIX_ROWS 14
#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS 6

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 24
#define DRIVER_2_LED_TOTAL 24
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_MATRIX_LED_PROCESS_LIMIT 5
#define RGB_MATRIX_LED_FLUSH_LIMIT 26

#define RGB_MATRIX_USE_LIMITS(min, max)                        \
    uint8_t min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter; \
    uint8_t max = min + RGB_MATRIX_LED_PROCESS_LIMIT;          \
    if (max > DRIVER_LED_TOTAL) max = DRIVER_LED_TOTAL;


// Lib8tion
uint8_t scale8( uint8_t i, uint8_t scale);

#endif //CHARCOAL__ERGODOX_EZ_CONFIG_H_
