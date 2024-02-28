import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import photoeditor

MenuBar {
    id: root

    signal openRequested()

    AppMenu {
        id: fileMenu

        title: qsTr("&File")

        AppMenuItem {
            text: qsTr("&Open")
            onTriggered: root.openRequested()
        }

        AppMenuItem {
            text: qsTr("&Save")
        }

        AppMenuItem {
            text: qsTr("Save &as")
        }

        AppMenuItem {
            text: qsTr("&Close")
        }

        MenuSeparator {
        }

        AppMenuItem {
            text: qsTr("&Quit")
            onTriggered: Qt.quit()
        }

    }
    // fileMenu

    AppMenu {
        id: viewMenu

        title: qsTr("&View")

        AppMenuItem {
            text: qsTr("Toggle &left sidebar")
            onTriggered: EditorState.toggleLeftSidebar()
        }

        AppMenuItem {
            text: qsTr("Toggle &right sidebar")
            onTriggered: EditorState.toggleRightSidebar()
        }

        AppMenuItem {
            text: qsTr("&Center image")
            onTriggered: EditorState.centerImage()
        }

        AppMenu {
            title: qsTr("Set &zoom")

            Repeater {
                model: [25, 50, 100, 200, 400]

                AppMenuItem {
                    text: modelData + "%"
                    onTriggered: EditorState.zoom = modelData
                }

            }

        }

    }
    // viewMenu

    component AppMenu: Menu {
        // no matches - pass the event
        // exact match - trigger the action
        // multiple matches - move cursor onto the next one

        function handleKeyboardEvent(event) {
            if (event.text === "" || currentIndex === -1) {
                event.accepted = false;
                return ;
            }
            // find all menu entries with this shortcut assigned
            let matches = [];
            for (let i = 0; i < count; ++i) {
                // move the whole iteration over by `currentIndex` entries
                let adjusted = (currentIndex + i + 1) % count;
                if (itemAt(adjusted).shortcut === event.text)
                    matches.push(adjusted);

            }
            if (matches.length === 0)
                event.accepted = false;
            else if (matches.length === 1)
                itemAt(matches[0]).triggered();
            else
                currentIndex = matches[0];
        }

        onOpened: currentIndex = 0
    }
    // AppMenu component

    component AppMenuItem: MenuItem {
        property string shortcut: {
            let i = text.indexOf("&");
            return (i !== -1 && i < text.length - 1) ? text.charAt(i + 1).toLowerCase() : "";
        }

        Keys.onPressed: (event) => {
            return menu.handleKeyboardEvent(event);
        }
    }
    // AppMenuItem component

}
