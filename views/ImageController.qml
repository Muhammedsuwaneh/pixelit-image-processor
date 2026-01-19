import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    Rectangle {
        width: parent.width
        height: 50
        color: "#F8FAFC"

        // CONTENT
        RowLayout {
            width: 300
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 15
            spacing: 2

            ImageControlButton {
                width: 125
                content: "Load"
                iconName: "load"
                onClicked: imageController.loadImage()
            }

            ImageControlButton {
                width: 125
                content: "Save"
                iconName: "save"
            }

            ImageControlButton {
                width: 125
                content: "Undo"
                iconName: "undo"
            }

            ImageControlButton {
                width: 125
                content: "Redo"
                iconName: "redo"
            }
        }

        // BOTTOM BORDER ONLY
        Rectangle {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: 0.5
            color: "#E2E8F0"
        }
    }
}

