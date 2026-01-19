import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    ColumnLayout {
        spacing: 10
        anchors.fill: parent

        GridLayout {
            rows: 2
            columns: 2
            rowSpacing: 10
            columnSpacing: 10

            ColumnLayout {
                Layout.row: 0
                Layout.column: 0
                spacing: 10

                Text {
                    text: qsTr("Width")
                    font.pixelSize: 15
                }

                TextField {
                    id: widthTextField
                    implicitWidth: 90
                    font.pixelSize: 17
                    padding: 10
                    validator: IntValidator { bottom: 1 }
                }
            }

            ColumnLayout {
                Layout.row: 0
                Layout.column: 1
                spacing: 10

                Text {
                    text: qsTr("Height")
                    font.pixelSize: 15
                }

                TextField {
                    id: heightTextField
                    implicitWidth: 90
                    font.pixelSize: 17
                    padding: 10
                    validator: IntValidator { bottom: 1 }
                }
            }

            Rectangle {
                Layout.row: 1
                Layout.column: 0
                Layout.columnSpan: 2

                width: 130
                height: 40
                radius: 6
                color: "#1447E6"

                Text {
                    anchors.centerIn: parent
                    color: "#ffffff"
                    font.pixelSize: 15
                    text: qsTr("Apply Changes")
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        ImageResizeController.resizeImage(Number(widthTextField.text), Number(heightTextField.text))
                    }
                }
            }
        }
    }
}
