import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string content: ""
    property string iconName: ""
    property int currentButtonIndex: 0

    implicitHeight: 40
    implicitWidth: 150
    hoverEnabled: true

    focusPolicy: Qt.NoFocus
    palette.button: "transparent"
    palette.highlight: "transparent"
    palette.light: "transparent"
    palette.midlight: "transparent"
    palette.dark: "transparent"
    palette.shadow: "transparent"

    background: Rectangle {
        color: NavigationController.currentActivePage === root.currentButtonIndex
               ? "#030712"
               : buttonMouseArea.containsMouse
                 ? "#111827"
                 : "transparent"
    }

    contentItem: Row {
        anchors.fill: parent
        spacing: 10

        Rectangle
        {
            color: NavigationController.currentActivePage === root.currentButtonIndex
                   ? "#2B7FFF" : "transparent";
            width: 5
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height - 2
        }

        Image {
            width: 17
            height: 17
            anchors.verticalCenter: parent.verticalCenter
            source: (root.iconName === "Gray Scale")
                    ? "../assets/gray.png"
                    : "../assets/" + root.iconName.toLowerCase() + ".png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            text: root.content
            color: "#ffffff"
            font.pixelSize: 13
            font.bold: true
            anchors.verticalCenter: parent.verticalCenter
            elide: Text.ElideRight
        }
    }


    MouseArea
    {
        id: buttonMouseArea
        hoverEnabled: true
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        onClicked: NavigationController.currentActivePage = root.currentButtonIndex;
    }
}
