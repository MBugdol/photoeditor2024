#include "appstate.h"

namespace photoeditor {

AppState::AppState(const Backend *backend, QObject *parent)
    : QObject{parent}, m_backend{backend} {}

}  // namespace photoeditor
