import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string content: ""
    property string iconName: ""
    property int currentButtonIndex: 0

    implicitHeight: 50
    implicitWidth: 250
    hoverEnabled: true

    // disabled default button props
    focusPolicy: Qt.NoFocus
    palette.button: "transparent"
    palette.highlight: "transparent"
    palette.light: "transparent"
    palette.midlight: "transparent"
    palette.dark: "transparent"
    palette.shadow: "transparent"

    background: Rectangle {
        radius: 8
        color: NavigationController.currentActivePage === root.currentButtonIndex
               ? "#030712"
               : buttonMouseArea.containsMouse
                 ? "#111827"
                 : "transparent"
    }

    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 10

        // pushes content to the left
        Item { Layout.preferredWidth: 30 }

        Image {
            Layout.preferredHeight: 25
            Layout.preferredWidth: 25
            source: (root.iconName === "Gray Scale") ? "assets/gray.png" : "assets/" + root.iconName.toLowerCase() + ".png"
            fillMode: Image.PreserveAspectFit
            Layout.alignment: Qt.AlignVCenter
        }

        Text {
            text: root.content
            color: "#ffffff"
            font.pixelSize: 15
            font.bold: true
            Layout.alignment: Qt.AlignVCenter
            elide: Text.ElideRight
        }

        Item { Layout.fillWidth: true }
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
