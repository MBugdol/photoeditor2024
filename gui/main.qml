import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

ApplicationWindow {
    id: root

    title: qsTr('Photo editor')
    width: 400
    height: 400
    visible: true

    Flickable {
        id: mainFlickable

        anchors.fill: parent
        clip: true
        contentWidth: workspace.width
        contentHeight: workspace.height

        Item {
            id: workspace

            width: 2 * mainFlickable.width
            height: 2 * mainFlickable.height

            Rectangle {
                id: image

                color: "red"
                anchors.centerIn: parent
                width: 300
                height: width
            }

        }

        WheelHandler {
            id: workspaceZoom

            acceptedModifiers: Qt.ControlModifier
            target: image
            property: "width"
        }

        WheelHandler {
            id: workspaceScroll

            acceptedModifiers: Qt.NoModifier
            blocking: false
        }

    }

}
