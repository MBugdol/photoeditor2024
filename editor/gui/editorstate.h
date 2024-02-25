#pragma once
#include <QObject>
#include <QQmlEngine>
class EditorState : public QObject {
  Q_OBJECT
  Q_PROPERTY(int zoom READ getZoom WRITE setZoom NOTIFY zoomChanged)

  QML_ELEMENT
  QML_SINGLETON

 public:
  explicit EditorState(QObject *parent = nullptr);

  Q_INVOKABLE void setZoom(int zoom);
  Q_INVOKABLE int getZoom() const;

  Q_INVOKABLE void centerImage();

  Q_INVOKABLE void toggleLeftSidebar();
  Q_INVOKABLE void toggleRightSidebar();

 signals:
  void zoomChanged();

  void leftSidebarToggleRequested();
  void rightSidebarToggleRequested();

  void imageCenteringRequested();

 private:
  int m_zoom = 100;
};
