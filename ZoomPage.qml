import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root

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

            Row
            {
                anchors.centerIn: parent

                Rectangle
                {
                    id: outerSlideContainer
                    color: "#90A1B9"
                    radius: 10
                    Layout.preferredHeight: 10
                    Layout.preferredWidth: 220

                    Rectangle
                    {
                        id: innerSlideContainer
                        color: "red"
                        radius: 10
                        Layout.preferredHeight: 10
                        Layout.preferredWidth: 100
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
                model: ["Fit Screen", "Actual Size", "Fill Screen", "Fill Width", "Fill Height" ]

                Rectangle
                {
                    radius: 8
                    color: "#e5e7eb"
                    border.color: "#cad5e2"
                    border.width: 1

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
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            root.getUserClicks(modelData)
                        }
                    }
                }
            }
        }
    }

    function getUserClicks(clickedProperty)
    {
        switch(clickedProperty)
        {
            case "Fit Screen":
                break;
            case "Actual Size":
                break;
            case "Fill Screen":
                break;
            case "Fill Width":
                break;
            case "Fill Height":
                break;
        }
    }
}
