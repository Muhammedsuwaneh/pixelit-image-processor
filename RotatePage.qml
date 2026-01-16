import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root
    property real angle: 0

    ColumnLayout
    {
        spacing: 20

        RowLayout {
            anchors.top: parent.top
            spacing: 10

            // Rotate clockwise
            Rectangle {
                id: rotateRightButton
                color: "#CAD5E2"
                border.color: "#333"
                border.width: 1
                radius: 10

                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Image {
                    id: rotateRightIcon
                    anchors.centerIn: parent
                    width: 20
                    height: 20
                    source: "assets/rotate-right.png"
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {
                       if(angle > -270)
                       {
                           angle -= 1.0
                           ImageRotationController.rotateImage(angle)
                       }
                    }

                    onPressed: rotateRightButton.opacity = 0.6
                    onReleased: rotateRightButton.opacity = 1.0
                }
            }

            // Rotate anti-clockwise
            Rectangle {
                id: rotateLeftButton
                color: "#CAD5E2"
                border.color: "#333"
                border.width: 1
                radius: 10

                Layout.preferredWidth: 50
                Layout.preferredHeight: 50

                Image {
                    id: rotateLeftIcon
                    anchors.centerIn: parent
                    width: 20
                    height: 20
                    source: "assets/rotate-left.png"
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor

                    onClicked: {
                        if(angle < 270)
                        {
                            angle += 1.0
                            ImageRotationController.rotateImage(angle)
                        }
                    }

                    onPressed: rotateLeftButton.opacity = 0.6
                    onReleased: rotateLeftButton.opacity = 1.0
                }
            }

            Rectangle {
                id: angleText
                color: "#CAD5E2"
                border.color: "#333"
                border.width: 1
                radius: 10

                Layout.preferredWidth: 70
                Layout.preferredHeight: 50

                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 17
                    Layout.alignment: Qt.AlignHCenter
                    smooth: true
                    text: angle + "°"
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
                            root.angle = parseInt(modelData)
                            ImageRotationController.rotateImage(root.angle)
                        }
                    }
                }
            }
        }
    }
}
