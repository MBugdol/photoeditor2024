#pragma once
#include <QApplication>
#include <QQmlApplicationEngine>
#include <memory>

#include <backend.h>
#include <project/projectimageprovider.h>
#include <appstate.h>

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
class EditorApplication : public QApplication {
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
  ProjectImageProvider m_project_img_provider; //< image provider for projects
  AppState m_app_state;
};

}  // namespace photoeditor
