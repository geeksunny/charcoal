#include "render.hpp"

namespace console {

ViewManager::ViewManager(std::ostream &ostream) : ostream_(ostream) {

}

void ViewManager::refresh() {
  for (View &view : views_) {
    view.draw(ostream_);
  }
}

void ViewManager::addView(View &view) {
  views_.push_back(view);
}

View *ViewManager::getView(int index) {
  return &views_[index];
}

std::deque<View> &ViewManager::getViews() {
  return views_;
}

}
