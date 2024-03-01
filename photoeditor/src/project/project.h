#pragma once

#include <QImage>
#include <QObject>

namespace photoeditor {

/**
 * @brief The Project class contains all information about a single editor
 * project.
 */
class Project : public QObject {
  Q_OBJECT
 public:
  explicit Project(QObject* parent = nullptr);
  Project(const Project& other);
  Project& operator=(Project other);

  friend void swap(Project& l, Project& r);

  /**
   * @brief Returns a complete preview of the project's image.
   * @return All layers composed into one image.
   */
  QImage getPreview() const;

  /**
   * @brief Returns a preview of the given layer.
   * @param id Index of the layer to return
   * @return Preview image of the requested layer
   */
  QImage getLayer(quint64 id) const;

  /**
   * @brief Adds the given image as a new layer.
   *
   * @param img The image to add as a layer.
   */
  void addLayer(QImage img);

 private:
  QList<QImage> m_layers;
};

}  // namespace photoeditor
