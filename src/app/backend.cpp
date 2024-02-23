#include "backend.h"

namespace photoeditor {

Backend::Backend(QObject *parent) : QObject{parent} {}

void Backend::openAsNewProject(const QUrl &file_url) {
  Q_UNUSED(file_url);
  // Project new_project;
  // 1. Open the file to a QImage
  // 2. add new layer to project: new_project.addLayer();
  // 3. add the new project to open projects as the file name without extension:
  // -- 3.1 if there is hash collision, add 1, 2, 3... to name
}

}  // namespace photoeditor
