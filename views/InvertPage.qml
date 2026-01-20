import QtQuick
import QtQuick.Controls

Item {

    Rectangle {

        width: 130
        height: 40
        radius: 6
        color: "#1447E6"

        Text {
            anchors.centerIn: parent
            color: "#ffffff"
            font.pixelSize: 15
            text: qsTr("Invert")
        }

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                ImageTextureController.adjustInvert(true)
                imageController.commit()
            }
        }
    }
}
