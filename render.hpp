#ifndef CHARCOAL__RENDER_HPP_
#define CHARCOAL__RENDER_HPP_

#include "view.hpp"
#include <deque>
#include <array>

#define LAYOUT_WRAP_CONTENT 0
#define LAYOUT_MATCH_TEMINAL -1

namespace console {

class ViewManager {
  // TODO: Implement flag for needsLayout when re-layout is needed before next draw
 public:
  explicit ViewManager(std::ostream &ostream);
  void refresh();
  void addView(View &view);
  View *getView(int index);
  std::deque<View> &getViews();
 protected:
  std::ostream& ostream_;
  // TODO: Minimum screen size check / enforcement
  // TODO: Implement abstract std::unique_ptr<ViewInterface*> for views?
  std::deque<View> views_;
};

class LayoutManager : public ViewManager {
 public:
  explicit LayoutManager(std::ostream &ostream) : ViewManager(ostream) { }
  virtual void layout() = 0;
};

template <size_t W, size_t H>
class GridLayoutManager : public LayoutManager {
 public:
  explicit GridLayoutManager(std::ostream &ostream) : LayoutManager(ostream) { }
  void addView(View &view, int row, int column) {
    ViewManager::addView(view);
    cells_[row][column] = &views_.back();
  }
  void setCellDimentions(Dimentions dimentions) {
    cell_dimentions_ = dimentions;
  }
  void setCellMargin(Margin margin) {
    cell_margin_ = margin;
  }
  void layout() override {
    int x = 1;
    int y = 1;
    for (std::array<View *, 10> &row : cells_) {
      for (int i = 0; i < 10; ++i) {
        View* view = row[i];
        if (view != nullptr) {
          view->setSize(cell_dimentions_);
          view->setPos({cell_margin_.left + x, cell_margin_.top + y});
        }
        x += cell_margin_.left + cell_dimentions_.width + cell_margin_.right;
      }
      y += cell_margin_.top + cell_dimentions_.height + cell_margin_.bottom;
      x = 1;
    }
  }
 private:
  std::array<std::array<View*, 10>, 5> cells_{};
  Dimentions cell_dimentions_ = {1, 1};
  Margin cell_margin_ = {0, 0, 0, 0};
};

}

#endif //CHARCOAL__RENDER_HPP_
