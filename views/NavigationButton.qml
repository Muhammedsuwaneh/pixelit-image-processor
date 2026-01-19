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

    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 10

        Item {
            Layout.preferredWidth: 5
        }

        Image {
            Layout.preferredHeight: 17
            Layout.preferredWidth: 17
            source: (root.iconName === "Gray Scale") ? "../assets/gray.png" : "../assets/" + root.iconName.toLowerCase() + ".png"
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter
        }

        Text {
            text: root.content
            color: "#ffffff"
            font.pixelSize: 12
            font.bold: true
            Layout.alignment: Qt.AlignVCenter
            elide: Text.ElideRight
        }

        Item
        {
            Layout.fillWidth: true
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
