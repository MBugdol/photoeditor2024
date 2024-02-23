#include "projectimageprovider.h"

#include <QDebug>

#include "project/project.h"

namespace photoeditor {

ProjectImageProvider::ProjectImageProvider(const Backend &backend)
    : QQuickImageProvider{QQuickImageProvider::Image}, m_backend{backend} {}

QImage ProjectImageProvider::requestImage(const QString &id, QSize *size,
                                          const QSize &requestedSize) {
  return QImage{};
  const QStringList tokens = id.split("/");
  if (tokens.size() < 1 || tokens.size() > 2) {
    qWarning() << "Invalid ID format";
    return QImage{};
  }

  const QString project_id = tokens[0];
  Project project = m_backend.getProject(project_id);

  if(tokens.size() == 2) {
    bool ok = true;
    quint64 layer_id = tokens[1].toULongLong(&ok);
    Q_ASSERT(ok);
    return project.getLayer(layer_id);
  }

  return project.getPreview();
}

}  // namespace photoeditor
