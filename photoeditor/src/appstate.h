#pragma once

#include <QObject>
#include <QtQml>

#include <backend.h>

namespace photoeditor {

/**
 * @brief Contains the current application state.
 */
class AppState : public QObject {
  Q_OBJECT
  QML_ELEMENT
 public:
  explicit AppState(const Backend* backend, QObject* parent = nullptr);

 private:
  const Backend* m_backend;
};

}  // namespace photoeditor
