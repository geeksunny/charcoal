/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#ifndef CHARCOAL__QMK_H_
#define CHARCOAL__QMK_H_

#define RGB_MATRIX_EFFECT(name, ...)

#define HAS_FLAGS(bits, flags) ((bits & flags) == flags)
#define HAS_ANY_FLAGS(bits, flags) ((bits & flags) != 0x00)

#define LED_FLAG_ALL 0xFF
#define LED_FLAG_NONE 0x00
#define LED_FLAG_MODIFIER 0x01
#define LED_FLAG_UNDERGLOW 0x02
#define LED_FLAG_KEYLIGHT 0x04
#define LED_FLAG_INDICATOR 0x08

#define RGB_MATRIX_TEST_LED_FLAGS() \
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) continue

#endif //CHARCOAL__QMK_H_
