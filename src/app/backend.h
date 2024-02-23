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
  Q_INVOKABLE void openAsNewProject(const QUrl& file_url);

  /**
   * @brief Returns the project associated with the given name
   * @param name Name of the project
   * @return Project associated with the given name
   */
  Project getProject(const QString& name);
  /**
   * @brief Const-overload of Project::getProject.
   * @param @param name Name of the project
   * @return Project associated with the given name
   */
  const Project getProject(const QString& name) const;

 private:
  void addProjectAsName(const Project& project, const QString& name);

  QHash<QString, Project>
      m_open_projects;  //< contains open projects mapped by their names
};

}  // namespace photoeditor
