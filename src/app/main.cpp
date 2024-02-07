#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char** argv) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  const QUrl url{u"qrc:/editor/gui/main.qml"_qs};

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed,
      QCoreApplication::instance(),
      []() { QCoreApplication::exit(1); }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
