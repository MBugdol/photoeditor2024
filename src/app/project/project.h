#pragma once

#include <QObject>

namespace photoeditor {

/**
 * @brief The Project class contains all information about a single editor
 * project.
 */
class Project : public QObject {
  Q_OBJECT
 public:
  explicit Project(QObject *parent = nullptr);
};

}  // namespace photoeditor
