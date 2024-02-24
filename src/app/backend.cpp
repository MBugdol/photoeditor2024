#include "backend.h"

#include <QDebug>
#include <QImage>
#include <QUrl>
#include <QFileInfo>

namespace photoeditor {

Backend::Backend(QObject *parent) : QObject{parent} {}

void Backend::openAsNewProject(const QUrl &file_url) {
  const QImage image{file_url.toLocalFile()};

  if (image.isNull()) {
    qWarning() << "Failed to open image" << file_url.toLocalFile();
    emit errorOccurred(tr("Failed to open the specified file!"));
    return;
  }

  Project new_project;
  new_project.addLayer(image);

  const QString file_name_no_extension = QFileInfo{file_url.fileName()}.baseName();
  addProjectAsName(new_project, file_name_no_extension);
  emit openProjectsChanged();
}

Project Backend::getProject(const QString &name) {
  Q_ASSERT(m_open_projects.contains(name));
  return m_open_projects.value(name);
}

const Project Backend::getProject(const QString &name) const {
  Q_ASSERT(m_open_projects.contains(name));
  return m_open_projects.value(name);
}

QStringList Backend::getOpenProjects() const {
  return m_open_projects.keys();
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
