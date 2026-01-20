import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root

    Rectangle {
        width: parent.width - 20
        height: parent.height - 20
        radius: 10
        color: "#F8FAFC"
        border.color: "#CAD5E2"
        border.width: 1
        clip: true

        Image {
            id: previewer
            anchors.fill: parent
            source: "image://controller/current"
            fillMode: root.getFillMode()
            smooth: true

            transform: Scale {
                origin.x: previewer.width / 2
                origin.y: previewer.height / 2
                xScale: ImageScaleController.zoomFactor
                yScale: ImageScaleController.zoomFactor
            }

            Connections {
                target: imageController
                function onImageChanged() {
                    previewer.source = ""
                    previewer.source = "image://controller/current"
                }
            }
        }
    }

    function getFillMode()
    {
        switch(ImageScaleController.imageFitType)
        {
            case "Stretch":
                return Image.Stretch;
            case "Aspect Fit":
                return Image.PreserveAspectFit;
            case "Aspect Crop":
                return Image.PreserveAspectCrop;
            case "Tile":
                return Image.Tile;
            case "Vertical Tile":
                return Image.TileVertically;
            case "Horizontal Tile":
                return Image.TileHorizontally;
            case "Pad":
                return Image.Pad;
            default:
                return Image.PreserveAspectFit;
        }
    }
}
