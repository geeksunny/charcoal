#include "console.hpp"

namespace console {

std::ostream& move(std::ostream &out, int x, int y) {
  return out << "\x1b[" << unsigned(y) << ";" << unsigned(x) << "H";
}

std::ostream& textColor(std::ostream &out, Rgb rgb) {
  // TODO: Constant values for rgb color_id ?
  //  https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
  return out << "\x1b[38;5;" << unsigned(rgb) << "m";
}

std::ostream& textColor(std::ostream &out, Rgb24 rgb_24) {
  return out << "\x1b[38;2;" << unsigned(rgb_24.r) << ";" <<  unsigned(rgb_24.g) << ";" << unsigned(rgb_24.b) << "m";
}

std::ostream& bgColor(std::ostream &out, Rgb rgb) {
  return out << "\x1b[48;5;" << unsigned(rgb) << "m";
}

std::ostream& bgColor(std::ostream &out, Rgb24 rgb_24) {
  return out << "\x1b[48;2;" << unsigned(rgb_24.r) << ";" <<  unsigned(rgb_24.g) << ";" << unsigned(rgb_24.b) << "m";
}

}
