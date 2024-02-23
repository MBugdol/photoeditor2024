#include "editorapplication.h"

namespace photoeditor {

EditorApplication::EditorApplication(int &argc, char **argv)
    : QApplication{argc, argv} {
  initializeEngine();
}

void EditorApplication::initializeEngine() {
  m_engine = std::make_unique<QQmlApplicationEngine>();
  const QUrl url{u"qrc:/editor/gui/main.qml"_qs};

  QObject::connect(
      m_engine.get(), &QQmlApplicationEngine::objectCreationFailed,
      QCoreApplication::instance(), []() { QCoreApplication::exit(1); },
      Qt::QueuedConnection);

  m_engine->addImageProvider("project", &m_project_img_provider);

  m_engine->setInitialProperties({
      {"backend", QVariant::fromValue(&m_backend)},
  });
  m_engine->load(url);
}

}  // namespace photoeditor
