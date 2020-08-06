#ifndef CHARCOAL__CONSOLE_HPP_
#define CHARCOAL__CONSOLE_HPP_

#include <iostream>
#include <sstream>

namespace console {

class ConsoleStream;

typedef uint8_t Rgb;

struct Rgb24 {
  uint8_t r;
  uint8_t g;
  uint8_t b;

  void invert() {
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  }
};

// TODO: base escape sequence method, similar to DEBUG() approach?
//  int code, ...vals, closing_sequence( if needed? does it change?)

// TODO: Refactor these into proper stream manipulators...
//  ? https://stdcxx.apache.org/doc/stdlibug/33-3.html
// TODO: MORE ANSI ESCAPE CODES?
//  https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
std::ostream &move(std::ostream &out, int x, int y);
std::ostream &textColor(std::ostream &out, Rgb rgb);
std::ostream &textColor(std::ostream &out, Rgb24 rgb_24);
std::ostream &bgColor(std::ostream &out, Rgb rgb);
std::ostream &bgColor(std::ostream &out, Rgb24 rgb_24);

}

#endif //CHARCOAL__CONSOLE_HPP_
