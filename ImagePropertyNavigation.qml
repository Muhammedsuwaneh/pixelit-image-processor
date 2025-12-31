import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    width: 50
    anchors.horizontalCenter: parent.horizontalCenter

    ColumnLayout {
        spacing: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 60

        Repeater {
            model: NavigationController.pages.length

            NavigationButton {
                width: 50
                imageSource: "assets/" + NavigationController.pages[index] + ".png"
                currentButtonIndex: index

                onClicked: NavigationController.currentActivePage = index
            }
        }
    }
}
