import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 200
    anchors.horizontalCenter: parent.horizontalCenter

    ColumnLayout {
        spacing: 12
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60

        Repeater {
            model: NavigationController.pages.length

            NavigationButton {
                width: 180
                content: NavigationController.pages[index]
                imageSource: "assets/logo.png"
                currentButtonIndex: index

                onClicked: NavigationController.currentActivePage = index
            }
        }
    }
}
