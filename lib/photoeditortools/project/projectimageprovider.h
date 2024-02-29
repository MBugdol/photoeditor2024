#pragma once

#include <QQuickImageProvider>
#include <photoeditortools/backend.h>

namespace photoeditor {

class ProjectImageProvider : public QQuickImageProvider {
  Q_OBJECT
 public:
  ProjectImageProvider(const Backend* backend);

  QImage requestImage(const QString &id, QSize *size,
                      const QSize &requestedSize) override;

 private:
  const Backend* m_backend;
};

}  // namespace photoeditor
