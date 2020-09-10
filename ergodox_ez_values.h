/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#ifndef CHARCOAL__ERGODOX_EZ_VALUES_H_
#define CHARCOAL__ERGODOX_EZ_VALUES_H_

#include "qmk_rgb_matrix_types.h"

static rgb_config_t rgb_matrix_config;

static led_config_t g_led_config = {{
                                 {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
                                 {28, 33, 38, 43, 47, NO_LED},
                                 {27, 32, 37, 42, 46, NO_LED},
                                 {26, 31, 36, 41, 45, NO_LED},
                                 {25, 30, 35, 40, 44, NO_LED},
                                 {24, 29, 34, 39, NO_LED, NO_LED},
                                 {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
                                 {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
                                 {0, 5, 10, 15, NO_LED, NO_LED},
                                 {1, 6, 11, 16, 20, NO_LED},
                                 {2, 7, 12, 17, 21, NO_LED},
                                 {3, 8, 13, 18, 22, NO_LED},
                                 {4, 9, 14, 19, 23, NO_LED},
                                 {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
                             }, {
                                 {137, 0}, {154, 0}, {172, 0}, {189, 0}, {206, 0}, {137, 12},
                                 {154, 12}, {172, 12}, {189, 12}, {206, 12}, {137, 25}, {154, 25},
                                 {172, 25}, {189, 25}, {206, 25}, {137, 38}, {154, 38}, {172, 38},
                                 {189, 38}, {206, 38}, {154, 51}, {172, 51}, {189, 51}, {206, 51},
                                 {86, 0}, {68, 0}, {51, 0}, {34, 0}, {17, 0}, {86, 12},
                                 {68, 12}, {51, 12}, {34, 12}, {17, 12}, {86, 25}, {68, 25},
                                 {51, 25}, {34, 25}, {17, 25}, {86, 38}, {68, 38}, {51, 38},
                                 {34, 38}, {17, 38}, {68, 51}, {51, 51}, {34, 51}, {17, 51}
                             }, {
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 1, 1, 1, 1,
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4,
                                 4, 4, 1, 1, 1, 1
                             }};

#endif //CHARCOAL__ERGODOX_EZ_VALUES_H_
