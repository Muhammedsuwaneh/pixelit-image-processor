import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts

Window {
    id: root
    width: 1080
    height: 800
    visible: true
    flags: Qt.FramelessWindowHint
    color: "transparent"

    Rectangle {
        id: appFrame
        anchors.fill: parent
        color: "#f8fafc"
        radius: 12
        clip: true

        GridLayout {
            anchors.fill: parent
            rows: 2
            columns: 2
            rowSpacing: 0
            columnSpacing: 0

            TitleBar {
                id: titleBar
                Layout.row: 0
                Layout.column: 0
                Layout.columnSpan: 2
                Layout.fillWidth: true
                Layout.preferredHeight: 48
                z: 10
            }

            Rectangle {
                id: editorNavigation
                Layout.row: 1
                Layout.column: 0
                Layout.preferredWidth: 250
                Layout.fillHeight: true
                color: "#1d293d"

                ImagePropertyNavigation { }
            }

            Rectangle {
                id: imageView
                Layout.row: 1
                Layout.column: 1
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "#F8FAFC"

                Text {
                    anchors.centerIn: parent
                    text: NavigationController.pages[
                        NavigationController.currentActivePage
                    ]
                }
            }
        }
    }
}
