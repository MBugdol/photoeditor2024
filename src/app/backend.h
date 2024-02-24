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
  Q_PROPERTY(
      QStringList openProjects READ getOpenProjects NOTIFY openProjectsChanged)
 public:
  explicit Backend(QObject* parent = nullptr);

  /**
   * @brief Creates a new project based on the specified file.
   * @param file_url URL of the file to base project on
   */
  Q_INVOKABLE void openAsNewProject(const QUrl& file_url);

  /**
   * @brief Returns the project associated with the g iven name
   * @param name Name of the project
   * @return Project associated with the given name
   */
  Project getProject(const QString& name);
  /**
   * @brief Const-overload of Project::getProject.
   * @param name Name of the project
   * @return Project associated with the given name
   */
  const Project getProject(const QString& name) const;

  Q_INVOKABLE QStringList getOpenProjects() const;

 signals:
  void openProjectsChanged();
  /**
   * @brief Emitted if an error occurred.
   * @param error_message Message describing the encountered error.
   */
  void errorOccurred(const QString& error_message);

 private:
  void addProjectAsName(const Project& project, const QString& name);

  QHash<QString, Project>
      m_open_projects;  //< contains open projects mapped by their names
};

}  // namespace photoeditor
