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
            id: previewer
            anchors.fill: parent
            fillMode: Image.PreserveAspectCrop
            source: "image://controller/current"
            smooth: true

            Connections {
                target: imageController
                function onImageChanged()
                {
                    previewer.source = ""
                    previewer.source = "image://controller/current"
                }
            }
        }
    }
}
