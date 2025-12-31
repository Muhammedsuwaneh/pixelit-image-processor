import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string imageSource: ""
    property int currentButtonIndex: 0

    implicitHeight: 40
    implicitWidth: 100
    hoverEnabled: true

    background: Rectangle {
        radius: 8
        opacity: root.hovered ? 0.9 : 1
        color: NavigationController.currentActivePage === root.currentButtonIndex
               ? "#0C0A09"
               : "transparent"
    }

    contentItem: RowLayout {
        anchors.fill: parent

        Image {
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25
            source: root.imageSource
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignHCenter
        }
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onClicked: NavigationController.currentActivePage = index
    }
}
