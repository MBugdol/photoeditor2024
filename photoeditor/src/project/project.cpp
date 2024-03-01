#include "project.h"

#include <QDebug>

namespace photoeditor {

Project::Project(QObject *parent) : QObject{parent} {}

Project::Project(const Project &other) : m_layers{other.m_layers} {}

Project &Project::operator=(const Project &other) {
  *this = Project{other};
  return *this;
}

QImage Project::getPreview() const {
  if (m_layers.isEmpty()) {
    return QImage{};
  }
  // TODO(MBugdol): Compose all layers into one image
  return m_layers[0];
}

QImage Project::getLayer(quint64 id) const {
  if (id < 0 || id >= m_layers.size()) {
    qWarning() << "There is no layer with index" << id;
    return QImage{};
  }
  return m_layers[id];
}

void Project::addLayer(QImage img) { m_layers.push_back(img); }

}  // namespace photoeditor
