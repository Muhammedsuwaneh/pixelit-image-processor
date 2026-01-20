import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    id: root
    property string oldFilter: "";

    ColumnLayout
    {
        GridLayout
        {
            columns: 2
            rowSpacing: 8
            columnSpacing: 8

            Repeater
            {
                model: ["Gray Scale", "Sepia", "Gaussian Blur", "Sharpen", "Edge Detection"]

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
                            if(root.oldFilter != modelData)
                            {
                                FiltersController.applyFilter(modelData)
                                root.oldFilter = modelData
                                imageController.commit()
                            }
                        }
                    }
                }
            }
        }
    }
}
