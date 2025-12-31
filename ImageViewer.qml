import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    Rectangle {
        width: 850
        height: 750
        radius: 10
        color: "#F8FAFC"
        border.color: "#CAD5E2"
        border.width: 1
        clip: true

        Image
        {
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: imageController.imageSource || ""
            smooth: true
        }
    }
}
