#ifndef CHARCOAL__ERGODOX_HPP_
#define CHARCOAL__ERGODOX_HPP_

#include "render.hpp"
#include "qmk.h"
#include "qmk_rgb_matrix_types.h"

namespace ergodox {

class Preview;

class RgbEffect {
  friend class Preview;
 protected:
  void rgb_matrix_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
  void rgb_matrix_set_color_all(uint8_t red, uint8_t green, uint8_t blue);
 private:
  Preview *preview_;

  void start(Preview *preview);
  void stop();

  virtual bool execEffect(effect_params_t* params) = 0;
};

class RgbEffectRunner {
  friend class Preview;
 private:
  virtual bool execRunner(effect_params_t* params, i_f effect_func) = 0;
};

class Preview {
  friend class RgbEffect;
 public:
  explicit Preview();
  Preview &setTicks(int ticks);
  Preview &setDelay(unsigned long delay);
  void start(RgbEffect *effect, RgbEffectRunner *runner = nullptr);
 private:
  console::GridLayoutManager<10, 5> vm_;
  int ticks_ = 20;
  unsigned long delay_ = 250;

  void setup();
  void setRgb(int index, console::Rgb24 color);
  void setAllRgb(console::Rgb24 color);
};

}

#endif //CHARCOAL__ERGODOX_HPP_
