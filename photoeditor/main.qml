import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Dialogs
import Qt.labs.platform as QtLabs
import QtCore
import photoeditor

ApplicationWindow {
    id: root

    // TODO: convert to type-safe declaration when QTBUG-122702 is resolved
    required property var backend
    required property var appState

    title: qsTr("Photo editor")
    width: 400
    height: 400
    visible: true
    Material.theme: Material.System

    Connections {
        function onOpenProjectsChanged() {
            let open_projects = root.backend.openProjects;
            preview.source = "image://project/" + open_projects[open_projects.length - 1];
            workspaceImageFlickable.center();
        }

        function onErrorOccurred(errorMsg: string) {
            errorDialog.openWithText(errorMsg);
        }

        target: root.backend
    }

    SplitView {
        id: workspaceSidebarSplit

        anchors.fill: parent

        Rectangle {
            id: leftSidebar

            SplitView.minimumWidth: 0.1 * parent.width
            color: "blue"

            Label {
                anchors.centerIn: parent
                width: Math.min(implicitWidth, parent.width)
                elide: Text.ElideRight
                wrapMode: Text.Wrap
                horizontalAlignment: Text.AlignHCenter
                text: "Left sidebar placeholder"
            }

            Connections {
                function onLeftSidebarToggleRequested() {
                    leftSidebar.visible = !leftSidebar.visible;
                }

                target: EditorState
            }

        }

        Item {
            id: workspaceItem

            SplitView.preferredWidth: parent.width * 0.8
            SplitView.minimumWidth: parent.width * 0.3
            SplitView.fillWidth: true
            clip: true

            Image {
                id: workspaceBackground

                readonly property int targetCellWidthMm: 10
                readonly property int imagePixelSize: 8

                source: "qrc:/photoeditor/img/cm_mesh.png"
                fillMode: Image.Tile
                anchors.fill: parent
                smooth: false
                scale: (Screen.pixelDensity * targetCellWidthMm / imagePixelSize)
            }

            Flickable {
                id: workspaceImageFlickable

                function center() {
                    contentX = (contentWidth - width) / 2;
                    contentY = (contentHeight - height) / 2;
                }

                anchors.fill: parent
                clip: true
                contentWidth: previewContainerItem.width
                contentHeight: previewContainerItem.height
                boundsBehavior: Flickable.StopAtBounds

                Connections {
                    function onImageCenteringRequested() {
                        workspaceImageFlickable.center();
                    }

                    target: EditorState
                }

                Item {
                    id: previewContainerItem

                    width: 2 * workspaceImageFlickable.width
                    height: 2 * workspaceImageFlickable.height

                    Image {
                        id: preview

                        source: ""
                        cache: false
                        fillMode: Image.Pad
                        anchors.centerIn: parent
                        scale: EditorState.zoom / 100
                    }

                }

                WheelHandler {
                    id: workspaceZoom

                    acceptedModifiers: Qt.ControlModifier
                    onWheel: (event) => {
                        EditorState.zoom += Math.sign(event.angleDelta.y) * 5;
                    }
                }

            }

        }

        Rectangle {
            id: rightSidebar

            SplitView.minimumWidth: 0.1 * parent.width
            color: "red"

            Label {
                anchors.centerIn: parent
                clip: true
                width: Math.min(implicitWidth, parent.width)
                elide: Text.ElideRight
                wrapMode: Text.Wrap
                text: "Right sidebar placeholder"
                horizontalAlignment: Text.AlignHCenter
            }

            Connections {
                function onRightSidebarToggleRequested() {
                    rightSidebar.visible = !rightSidebar.visible;
                }

                target: EditorState
            }

        }

    }

    QtLabs.FileDialog {
        id: fileDialog

        title: qsTr("Select the image to open")
        fileMode: FileDialog.OpenFile
        folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted: backend.openAsNewProject(fileDialog.file)
    }

    QtLabs.MessageDialog {
        id: errorDialog

        function openWithText(new_text: string) {
            text = new_text;
            open();
        }

        buttons: QtLabs.MessageDialog.Ok
        text: ""
        title: qsTr("Error")
    }

    header: AppMenuBar {
        onOpenRequested: fileDialog.open()
    }

}
