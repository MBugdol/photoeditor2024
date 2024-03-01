#include "projectimageprovider.h"

#include <QDebug>

#include <project/project.h>

namespace photoeditor {

ProjectImageProvider::ProjectImageProvider(const Backend* backend)
    : QQuickImageProvider{QQuickImageProvider::Image}, m_backend{backend} {
  Q_ASSERT(m_backend);
}

QImage ProjectImageProvider::requestImage(const QString &id, QSize *size,
                                          const QSize &requestedSize) {
  const QStringList tokens = id.split("/");
  if (tokens.size() < 1 || tokens.size() > 2) {
    qWarning() << "Invalid ID format";
    return QImage{};
  }

  const QString project_id = tokens[0];
  Project project = m_backend->getProject(project_id);

  QImage result;
  if(tokens.size() == 2) {
    bool ok = true;
    quint64 layer_id = tokens[1].toULongLong(&ok);
    Q_ASSERT(ok);
    result = project.getLayer(layer_id);
  } else {
    result = project.getPreview();
  }

  if(requestedSize.width() > 0 && requestedSize.height() > 0) {
    result = result.scaled(requestedSize.width(), requestedSize.height());
    *size = requestedSize;
  } else {
    *size = result.size();
  }

  return result;
}

}  // namespace photoeditor
