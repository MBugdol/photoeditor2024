#include "editorstate.h"

EditorState::EditorState(QObject *parent) : QObject{parent} {}

void EditorState::setZoom(const int zoom) {
  constexpr int kMinZoom = 25;
  constexpr int kMaxZoom = 400;
  if(zoom < kMinZoom || zoom > kMaxZoom) {
    return;
  }
  _zoom = zoom;
  emit zoomChanged();
}

int EditorState::getZoom() const { return _zoom; }
