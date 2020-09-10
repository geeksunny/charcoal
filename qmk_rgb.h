/**
 * Code from QMK Firmware (https://github.com/qmk/qmk_firmware)
 */

#ifndef CHARCOAL__QMK_RGB_H_
#define CHARCOAL__QMK_RGB_H_

#if defined(__GNUC__)
#    define PACKED __attribute__((__packed__))
#else
#    define PACKED
#endif

// WS2812 specific layout
typedef struct PACKED {
  uint8_t g;
  uint8_t r;
  uint8_t b;
} cRGB;

typedef cRGB RGB;

// WS2812 specific layout
typedef struct PACKED {
  uint8_t g;
  uint8_t r;
  uint8_t b;
  uint8_t w;
} cRGBW;

typedef struct PACKED {
  uint8_t h;
  uint8_t s;
  uint8_t v;
} HSV;

RGB hsv_to_rgb(HSV hsv);

#endif //CHARCOAL__QMK_RGB_H_
