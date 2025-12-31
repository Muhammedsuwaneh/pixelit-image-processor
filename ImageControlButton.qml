import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string content: ""
    property string iconName: ""

    implicitHeight: 35
    implicitWidth: 100
    hoverEnabled: true

    signal clicked()

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
        color: "#0F172B";
    }

    contentItem: RowLayout {
        anchors.fill: parent
        spacing: 10

        // pushes content to the left
        Item { Layout.preferredWidth: 10 }

        Image {
            Layout.preferredHeight: 17
            Layout.preferredWidth: 17
            source: "assets/" + root.iconName + ".png"
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

        Item { Layout.fillWidth: true }
    }

    MouseArea
    {
        id: buttonMouseArea
        hoverEnabled: true
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor

        onClicked: root.clicked()
    }
}
