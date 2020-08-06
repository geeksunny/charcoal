#include "view.hpp"

#define CH_SQ_TOP_LEFT      "\u250C"  // "┌"
#define CH_SQ_TOP_RIGHT     "\u2510"  // "┐"
#define CH_SQ_BOTTOM_LEFT   "\u2514"  // "└"
#define CH_SQ_BOTTOM_RIGHT  "\u2518"  // "┘"
#define CH_SQ_LINE_VERT     "\u2502"  // "│"
#define CH_SQ_LINE_HORIZ    "\u2500"  // "─"

namespace console {

void View::setPos(Point pos) {
  pos_ = pos;
}

void View::setX(int x) {
  pos_.x = x;
}

void View::setY(int y) {
  pos_.y = y;
}

void View::setSize(Dimentions size) {
  size_ = size;
}

void View::setWidth(int width) {
  size_.width = width;
}

void View::setHeight(int height) {
  size_.height = height;
}

void View::setTextColor(Rgb24 text_color) {
  textColor_ = text_color;
}

void View::setBgColor(Rgb24 bg_color) {
  bgColor_ = bg_color;
}

void View::draw(std::ostream &ostream) {
  console::textColor(ostream, textColor_);
  console::bgColor(ostream, bgColor_);
  for (int y = 0; y < size_.height; ++y) {
    console::move(ostream, pos_.x, pos_.y + y);
    for (int x = 0; x < size_.width; ++x) {
      if (x == size_.width / 2 && y == size_.height / 2) {
        ostream << 'c';
      } else {
        ostream << ' ';
      }
    }
    ostream.flush();
  }
}

void Square::draw(std::ostream &ostream) {
  //View::draw(ostream);
  // TODO: Add an optional alternate text/bg color for square components
  for (int y = 0; y < size_.height; ++y) {
    console::move(ostream, pos_.x, pos_.y + y);
    if (y == 0) {
      // ceiling
      drawHorizWall(ostream, y);
    } else if (y == size_.height - 1) {
      // floor
      drawHorizWall(ostream, y);
    } else {
      // walls
      drawVertWall(ostream, y);
    }
    ostream.flush();
  }
}

void Square::drawHorizWall(std::ostream &ostream, int &row) {
  bool isTop = row == 0;
  for (int x = 0; x < size_.width; ++x) {
    if (x == 0) {
      ostream << (isTop ? CH_SQ_TOP_LEFT : CH_SQ_BOTTOM_LEFT);
    } else if (x == size_.width - 1) {
      ostream << (isTop ? CH_SQ_TOP_RIGHT : CH_SQ_BOTTOM_RIGHT);
    } else {
      ostream << CH_SQ_LINE_HORIZ;
    }
  }
}

void Square::drawVertWall(std::ostream &ostream, int &row) {
  ostream << CH_SQ_LINE_VERT;
  move(ostream, size_.width - 1, row);
  ostream << CH_SQ_LINE_VERT;
}

}