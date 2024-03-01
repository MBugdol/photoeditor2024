#include "editorapplication.h"

#include <QQmlContext>

int main(int argc, char** argv) {
  photoeditor::EditorApplication app(argc, argv);
  return app.exec();
}
