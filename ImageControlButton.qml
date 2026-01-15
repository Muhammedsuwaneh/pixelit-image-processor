import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    id: root

    property string content: ""
    property string iconName: ""

    signal clicked()

    implicitHeight: 35
    implicitWidth: 100

    focusPolicy: Qt.NoFocus
    hoverEnabled: true

    background: Rectangle {
        radius: 8
        color: buttonMouseArea.hoverEnabled ? "#45556C" : "#0F172B"
    }

    contentItem: Item {
        anchors.fill: parent

        Row {
            spacing: 10
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 12

            Image {
                width: 17
                height: 17
                source: "assets/" + root.iconName + ".png"
                fillMode: Image.PreserveAspectFit
            }

            Text {
                text: root.content
                color: "#ffffff"
                font.pixelSize: 12
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }
        }
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
