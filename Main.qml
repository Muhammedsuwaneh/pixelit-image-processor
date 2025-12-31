import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts

Window {
    id: root
    width: 1300
    height: 880
    visible: true
    flags: Qt.FramelessWindowHint
    color: "transparent"

    property string currentPage:
        NavigationController.pages[NavigationController.currentActivePage]


    Rectangle {
        id: appFrame
        anchors.fill: parent
        color: "#f8fafc"
        radius: 12
        clip: true

        GridLayout {
            anchors.fill: parent
            rows: 2
            columns: 3
            rowSpacing: 0
            columnSpacing: 0

            // TITLE BAR
            TitleBar {
                id: titleBar
                Layout.row: 0
                Layout.column: 0
                Layout.columnSpan: 3
                Layout.fillWidth: true
                Layout.preferredHeight: 48
                z: 10
            }

            // LEFT NAVIGATION
            Rectangle {
                id: editorNavigation
                Layout.row: 1
                Layout.column: 0
                Layout.preferredWidth: 150
                Layout.fillHeight: true
                color: "#1d293d"

                ImagePropertyNavigation { }
            }


            // SELECTED PROPERTY PAGE
            Rectangle
            {
                id: propertyPage
                Layout.row: 1
                Layout.column: 1
                Layout.preferredWidth: 200
                Layout.fillHeight: true
                color: "#F8FAFC"
                border.color: "#E2E8F0"
                border.width: 0.5

                ColumnLayout
                {
                    id: propertyLayout
                    spacing: 10


                    Item {
                        Layout.preferredHeight: 20
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                    // title
                    RowLayout {
                           anchors.fill: parent
                           spacing: 10

                           // pushes content to the left
                           Item { Layout.preferredWidth: 10 }

                           Image {
                               Layout.preferredHeight: 17
                               Layout.preferredWidth: 17
                               source: "assets/adjust.png"
                               fillMode: Image.PreserveAspectFit
                               Layout.alignment: Qt.AlignVCenter
                           }

                           Text {
                               text: "Adjust Properties"
                               color: "#0F172B"
                               font.pixelSize: 15
                               font.bold: true
                               Layout.alignment: Qt.AlignVCenter
                               elide: Text.ElideRight
                           }

                           Item { Layout.fillWidth: true }
                    }

                    // property pages
                    Loader
                    {
                        id: propertyPageLoader
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.leftMargin: 20
                        Layout.rightMargin: 10

                        source: (root.currentPage === "Gray Scale") ? "GrayScalePage.qml" : root.currentPage + "Page.qml"
                    }
                }
            }

            // RIGHT SECTION - MAIN
            Rectangle {
                id: imageView
                Layout.row: 1
                Layout.column: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: "#E2E8F0"

                GridLayout
                {
                    anchors.fill: parent
                    rows: 2
                    columns: 2
                    rowSpacing: 10
                    columnSpacing: 0

                    // spacing
                    Item {
                        Layout.preferredWidth: 20
                        Layout.row: 1
                        Layout.column: 0
                    }

                    // IMAGE CONTROL
                    ImageController {
                        Layout.row: 0
                        Layout.column:0
                        Layout.columnSpan: 2
                        Layout.fillWidth: true
                        Layout.preferredHeight: 50
                    }

                    // IMAGE VIEWER
                    ImageViewer
                    {
                        id: imageViewPage
                        Layout.row: 2
                        Layout.column:1
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }
        }
    }
}
