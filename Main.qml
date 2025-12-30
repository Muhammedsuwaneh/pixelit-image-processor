import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts

Window {
    id: root
    width: 1080
    height: 800
    visible: true
    title: qsTr("PixelIt")
    flags: Qt.FramelessWindowHint
    color: "transparent"

    Rectangle {
        anchors.fill: parent
        color: "#62748E"
        radius: 12
    }

    TitleBar {
        id: titleBar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    Item {
        anchors.top: titleBar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
