#ifndef CHARCOAL__VIEW_HPP_
#define CHARCOAL__VIEW_HPP_

#include <string>
#include "console.hpp"

namespace console {

struct Point {
  int x;
  int y;
};

struct Dimentions {
  int width;
  int height;
};

struct Rect {
  int left;
  int top;
  int right;
  int bottom;
};

typedef Rect Padding;
typedef Rect Margin;

class ViewInterface {
 public:
  virtual void setPos(Point pos)= 0;
  virtual void setX(int x)= 0;
  virtual void setY(int y)= 0;
  virtual void setSize(Dimentions size)= 0;
  virtual void setWidth(int width)= 0;
  virtual void setHeight(int height)= 0;
  virtual void setTextColor(Rgb24 text_color)= 0;
  virtual void setBgColor(Rgb24 bg_color)= 0;
  virtual void draw(std::ostream &ostream) = 0;
};

class View : public ViewInterface {
 public:
  View() = default;
  void setPos(Point pos) override;
  void setX(int x) override;
  void setY(int y) override;
  void setSize(Dimentions size) override;
  void setWidth(int width) override;
  void setHeight(int height) override;
  void setTextColor(Rgb24 text_color) override;
  void setBgColor(Rgb24 bg_color) override;

  // TODO: implement margin/padding
  void draw(std::ostream &ostream) override;
// protected:
  Point pos_ = {1, 1};
  Dimentions size_ = {0, 0};
  Rgb24 textColor_ = {255, 255, 255};
  Rgb24 bgColor_ = {0, 0, 0};
};

class Square : public View {
 public:
  Square() = default;
  void draw(std::ostream &ostream) override;
 private:
  std::string label_;

  void drawHorizWall(std::ostream &ostream, int &row);
  void drawVertWall(std::ostream &ostream, int &row);
};

}

#endif //CHARCOAL__VIEW_HPP_
