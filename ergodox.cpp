#include "ergodox.hpp"
#include <chrono>
#include <thread>

namespace ergodox {

Preview::Preview() : vm_(std::cout) {
  setup();
}

void Preview::start() {
  // Calculate layout
  vm_.layout();
  // Draw layout
  vm_.refresh();
  // loop
  for (int i = 0; i < 20; ++i) { //while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    for (console::View &view : vm_.GetViews()) {
      view.bgColor_.invert();
      view.textColor_.invert();
    }
    vm_.refresh();
  }
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

}