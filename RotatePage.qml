import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root
    property real minValue: 0
    property real maxValue: 270
    property real value: 0

    ColumnLayout
    {
        spacing: 10

        Rectangle
        {
            id: rotateContainer
            color: "transparent"
            border.width: 1
            radius: 10
            border.color: "#CAD5E2"
            Layout.preferredHeight: 50
            Layout.preferredWidth: 230

            ColumnLayout
            {
                anchors.centerIn: parent
                // TEXT BOX
                TextField
                {
                    id: intInput
                    width: 100
                    height: 40
                    placeholderText: "0"
                    font.pixelSize: 20

                    padding: 12

                    validator: IntValidator
                    {
                        bottom: -9999
                        top: 9999
                    }

                    onTextChanged:
                    {
                        if(text === "-" || text === "") return;
                        ImageRotationController.rotateImage(parseInt(text))
                    }
                }

                // ARROW UP BUTTON
                // ARROW DOWN BUTTON
            }
        }

        GridLayout
        {
            columns: 2
            rowSpacing: 8
            columnSpacing: 8

            Repeater
            {
                model: ["90", "180", "270"]

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
                       text: modelData + "°"
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
                            ImageRotationController.rotateImage(modelData)
                        }
                    }
                }
            }
        }
    }
}
