#include "ergodox.hpp"

#include "ergodox_ez_values.h"

// TODO: Format below examples into functions that take std::ostringstream& for applying escape codes.

// TODO: Also work in background color with ANSI codes!

// ie: setForeground(); setBackground(); drawShape(label); resetColors();

// Console class manages its own ostringstream for the duration of use.
//  (Is this wise? Do we need to be careful? flush regularly, etc?)

// console class has stream << operator overloaded for operation. maybe extends a stream class?
//  create own modifiers (like std::endl) for creating the squares with label, colors, etc.

class EffectWithRunner : public ergodox::RgbEffect, public ergodox::RgbEffectRunner {
 private:
  bool execEffect(effect_params_t *params) override {
    //
    return false;
  }

  bool execRunner(effect_params_t *params, i_f effect_func) override {
    //
    return false;
  }
};

class EffectOnly : public ergodox::RgbEffect {
 private:
  bool execEffect(effect_params_t *params) override {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t led_mid = (led_max / 2) + (((led_max % 2) != 0) ? 1 : 0);

    HSV hsv = rgb_matrix_config.hsv;
    uint8_t scale = scale8(64, rgb_matrix_config.speed);
    uint8_t ii = led_max - 1;
    for (uint8_t i = led_min; i < led_mid; ++i) {
      RGB_MATRIX_TEST_LED_FLAGS();
      // The x range will be 0..224, map this to 0..7
      // Relies on hue being 8-bit and wrapping
      hsv.h   = rgb_matrix_config.hsv.h + (scale * g_led_config.point[i].x >> 5);
      RGB rgb = hsv_to_rgb(hsv);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      if (i < ii) {
        rgb_matrix_set_color(ii, rgb.r, rgb.g, rgb.b);
        // Decrement outer iterator
        --ii;
      }
    }
    return led_max < DRIVER_LED_TOTAL;
  }
};

void testRenderer() {
  ergodox::Preview preview;
  EffectOnly effect_only;
  preview.start(&effect_only, nullptr);
//  EffectWithRunner effect;
//  preview.start(&effect, &effect);
}

int main() {
  testRenderer();
  std::cout << std::endl;
  return 0;
}
