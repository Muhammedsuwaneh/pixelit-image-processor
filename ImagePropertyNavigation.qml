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

        Item {
            Layout.preferredHeight: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Repeater {
            model: NavigationController.pages.length

            NavigationButton {
                width: 150
                content: NavigationController.pages[index]
                iconName: NavigationController.pages[index]
                currentButtonIndex: index
            }
        }
    }
}
