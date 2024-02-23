#pragma once
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <memory>

#include "backend.h"

namespace photoeditor {

/**
 * @brief The `EditorApplication` class encapsulates the main application logic.
 *
 * This class is responsible for initializing and launching of the GUI
 * application.
 *
 * The class inherits `QGuiApplication` instead of containing it due to the
 * reccomendation of initializing `QCoreApplication` inside the `main` function
 * (see
 * https://doc.qt.io/qt-6/qcoreapplication.html#the-event-loop-and-event-handling).
 */
class EditorApplication : public QGuiApplication {
  Q_OBJECT
 public:
  /**
   * @brief Constructs an EditorApplication.
   *
   * Calls superclass' constructor & the `initializeEngine` method.
   *
   * @param argc main's argc
   * @param argv main's argv
   */
  EditorApplication(int& argc, char** argv);

 private:
  void initializeEngine();  //< initializes and loads app's qml engine

  std::unique_ptr<QQmlApplicationEngine> m_engine;  //< app's qml engine
  Backend m_backend;
};

}  // namespace photoeditor
