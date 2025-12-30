import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string content: ""
    property string imageSource: ""
    property int currentButtonIndex: 0

    implicitHeight: 40
    implicitWidth: 230
    hoverEnabled: true

    background: Rectangle {
        radius: 8
        opacity: root.hovered ? 0.9 : 1
        color: NavigationController.currentActivePage === root.currentButtonIndex
               ? "#155DFC"
               : "#62748E"
    }

    contentItem: RowLayout {
        spacing: 10
        anchors.fill: parent

        Image {
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25
            source: root.imageSource
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter
        }

        Text {
            text: root.content
            color: "#ffffff"
            font.pixelSize: 15
            font.bold: true
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onClicked: NavigationController.currentActivePage = index
    }
}
