#include "backend.h"

#include <QDebug>
#include <QImage>
#include <QUrl>
#include <QFileInfo>

namespace photoeditor {

Backend::Backend(QObject *parent) : QObject{parent} {}

void Backend::openAsNewProject(const QUrl &file_url) {
  const QImage image{file_url.path()};

  if (image.isNull()) {
    qWarning() << "Failed to open image" << file_url.path();
    // TODO(MBugdol): emit error
    return;
  }

  Project new_project;
  new_project.addLayer(image);

  const QString file_name_no_extension = QFileInfo{file_url.fileName()}.baseName();
  addProjectAsName(new_project, file_name_no_extension);
}

void Backend::addProjectAsName(const Project &project, const QString &name) {
  QString save_name = name;
  int current_try = 1;

  while(m_open_projects.contains(save_name)) {
    save_name = name + " (" + QString::number(current_try) + ")";
    ++current_try;
  }
  m_open_projects.insert(save_name, project);
}

}  // namespace photoeditor
