import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Dialogs
import Qt.labs.platform as QtLabs
import QtCore

ApplicationWindow {
    id: root

    // TODO: convert to type-safe declaration when QTBUG-122702 is resolved
    required property var backend

    title: qsTr("Photo editor")
    width: 400
    height: 400
    visible: true
    Material.theme: Material.System

    Flickable {
        id: mainFlickable

        function center() {
            contentX = (contentWidth - width) / 2;
            contentY = (contentHeight - height) / 2;
        }

        anchors.fill: parent
        clip: true
        contentWidth: workspace.width
        contentHeight: workspace.height
        boundsBehavior: Flickable.StopAtBounds
        Component.onCompleted: center()

        Connections {
            function onImageCenteringRequested() {
                mainFlickable.center();
            }

            target: EditorState
        }

        Item {
            id: workspace

            width: 2 * mainFlickable.width
            height: 2 * mainFlickable.height

            Image {
                id: image

                source: "qrc:/editor/gui/img/qt_logo.svg"
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

        QtLabs.FileDialog {
            id: fileDialog

            title: qsTr("Select the image to open")
            fileMode: FileDialog.OpenFile
            folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            onAccepted: backend.openAsNewProject(fileDialog.selectedFile)
        }

    }

    header: AppMenuBar {
        onOpenRequested: fileDialog.open()
    }

}
