#include "ergodox.hpp"
#include <chrono>
#include <thread>

namespace ergodox {

void RgbEffect::rgb_matrix_set_color(int index, uint8_t red, uint8_t green, uint8_t blue) {
  preview_->setRgb(index, {red, green, blue});
}

void RgbEffect::rgb_matrix_set_color_all(uint8_t red, uint8_t green, uint8_t blue) {
  preview_->setAllRgb({red, green, blue});
}

void RgbEffect::start(Preview *preview) {
  preview_ = preview;
}

void RgbEffect::stop() {
  preview_ = nullptr;
}

Preview::Preview() : vm_(std::cout) {
  setup();
}

Preview &Preview::setTicks(int ticks) {
  ticks_ = ticks;
  return *this;
}
Preview &Preview::setDelay(unsigned long delay) {
  delay_ = delay;
  return *this;
}

void Preview::start(RgbEffect *effect, RgbEffectRunner *runner) {
  effect->start(this);
  // Calculate layout
  vm_.layout();
  // Draw layout
  vm_.refresh();
  // loop
  effect_params_t params;
  for (int i = 0; i < ticks_; ++i) { //while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_));
    if (runner != nullptr) {
      // TODO: use the runner here
    } else {
      effect->execEffect(&params);
    }
    vm_.refresh();
  }
  effect->stop();
}

void Preview::setup() {
  // Populate views
  console::View view;
  vm_.setCellDimentions({10, 5});
  vm_.setCellMargin({1, 0, 0, 1});

  // Create grid in order matching ErgoDox-EZ LED Matrix hardware
  // col, 5-9; row 0-4; (5,4) SKIP!!
  // Right side first
  int col = 5;
  int row = 0;
  uint8_t blue = 105;
  while (col < 10 && row < 5) {
    if (col == 5 && row == 4) {
      // empty spot, skip
      ++col;
      continue;
    }
    view.setBgColor({uint8_t(row * 50), uint8_t(col * 50), blue});
    vm_.addView(view, row, col++);
    if (col == 10) {
      ++row;
      col = 5;
    }
  }
  // col, 4-0; row 0-4; (4,4) SKIP!!
  // Left side second
  col = 4;
  row = 0;
  blue = 235;
  while (col > -1 && row < 5) {
    if (col == 4 && row == 4) {
      // empty spot, skip
      col--;
      continue;
    }
    view.setBgColor({uint8_t(col * 50), uint8_t(row * 50), blue});
    vm_.addView(view, row, col--);
    if (col == -1) {
      ++row;
      col = 4;
    }
  }
}

void Preview::setRgb(int index, console::Rgb24 color) {
  vm_.getView(index)->setBgColor(color);
}

void Preview::setAllRgb(console::Rgb24 color) {
  for (console::View &view : vm_.getViews()) {
    view.setBgColor(color);
  }
}

}