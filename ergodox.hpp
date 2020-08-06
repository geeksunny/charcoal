#ifndef CHARCOAL__ERGODOX_HPP_
#define CHARCOAL__ERGODOX_HPP_

#include "render.hpp"

namespace ergodox {

class Preview {
 public:
  explicit Preview();
  void start();
 private:
  console::GridLayoutManager<10, 5> vm_;

  void setup();
};

}

#endif //CHARCOAL__ERGODOX_HPP_
