#include "ergodox.hpp"

// TODO: Format below examples into functions that take std::ostringstream& for applying escape codes.

// TODO: Also work in background color with ANSI codes!

// ie: setForeground(); setBackground(); drawShape(label); resetColors();

// Console class manages its own ostringstream for the duration of use.
//  (Is this wise? Do we need to be careful? flush regularly, etc?)

// console class has stream << operator overloaded for operation. maybe extends a stream class?
//  create own modifiers (like std::endl) for creating the squares with label, colors, etc.

void testRenderer() {
  ergodox::Preview preview;
  preview.start();
}

int main() {
  testRenderer();
  std::cout << std::endl;
  return 0;
}
