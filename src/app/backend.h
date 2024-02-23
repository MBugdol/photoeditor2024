#pragma once

#include <QHash>
#include <QObject>

#include "project/project.h"

namespace photoeditor {

/**
 * @brief The Backend class exposes main application functionality to QML.
 */
class Backend : public QObject {
  Q_OBJECT
 public:
  explicit Backend(QObject* parent = nullptr);

  /**
   * @brief Creates a new project based on the specified file.
   * @param file_url URL of the file to base project on
   */
  void openAsNewProject(const QUrl& file_url);

 private:
  QHash<QString, Project>
      m_open_projects;  //< contains open projects mapped by their names
};

}  // namespace photoeditor
