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

std::deque<View> &ViewManager::GetViews() {
  return views_;
}

}
