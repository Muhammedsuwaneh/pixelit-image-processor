import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root
    property real minValue: 0
    property real maxValue: 100
    property real value: 0
    property real normalizedValue: (value - minValue) / (maxValue - minValue)

    ColumnLayout
    {
        spacing: 10

        Rectangle
        {
            id: zoomContainer
            color: "transparent"
            border.width: 1
            radius: 10
            border.color: "#CAD5E2"
            Layout.preferredHeight: 30
            Layout.preferredWidth: 230

            ColumnLayout
            {
                anchors.centerIn: parent

                Rectangle
                {
                    id: outerSlideContainer
                    color: "#CAD5E2"
                    radius: 10
                    height: 10
                    width: 200

                    Rectangle {
                        id: innerSlideContainer
                        color: "#34A6F4"
                        radius: 10
                        height: parent.height
                        width: parent.width * root.normalizedValue
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 2
                    }


                    Rectangle {
                        id: slider
                        color: "#34A6F4"
                        radius: 50
                        height: 15
                        width: 15
                        anchors.verticalCenter: parent.verticalCenter
                        x: innerSlideContainer.width - width / 2
                    }

                    MouseArea
                    {
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor

                        onPressed: updateValue(mouse.x)
                        onPositionChanged: {
                            if(pressed)
                                updateValue(mouse.x)
                        }

                        function updateValue(mouseX)
                        {
                            let clampedX = Math.max(0, Math.min(mouseX, outerSlideContainer.width)) // current slider position
                            root.value = root.minValue + (clampedX / outerSlideContainer.width) * (root.maxValue - root.minValue) // compute final value

                            ImageTextureController.adjustContrast(root.value)
                        }
                    }
                }
            }
        }

        GridLayout
        {
            columns: 2
            rowSpacing: 8
            columnSpacing: 8

            Repeater
            {
                model: ["20", "40", "60", "80", "100"]

                Rectangle
                {
                    radius: 8
                    color: "#e5e7eb"
                    border.color: "#cad5e2"
                    border.width: 1
                    opacity:  buttonMouseArea.containsMouse ? .8 : 1

                    Layout.preferredHeight: 32
                    Layout.preferredWidth: 110

                    Text {
                       anchors.centerIn: parent
                       text: modelData
                       font.pixelSize: 12
                       color: "#111827"
                    }

                    MouseArea
                    {
                        id: buttonMouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            root.value = parseInt(modelData)
                            ImageScaleController.adjustContrast(value)
                        }
                    }
                }
            }
        }
    }
}
