import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.12

import ModuleStyle 1.0

ToolBar {
    id: _root

    property string ftitleText: "Morse Code"

    RowLayout {
      anchors.fill: parent
      ToolButton {
        text:  qsTr(":::")
        onClicked: {
          _drawer.open()
        }
      }

      Label {
        text: ftitleText
        elide: Label.ElideRight
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        Layout.fillWidth: true
      }

      ToolButton {
        text: qsTr("⋮")
        onClicked: _menu.open()
      }
    }

    Item {
        anchors.right: parent.right
        width: _menu.width
        height: _menu.height

        Menu {
          id: _menu

          MenuItem {
            text: StyleConfig.isDarkTheme ? qsTr("Light") :
                                            qsTr("Dark")
            onTriggered: {
              StyleConfig.isDarkTheme = StyleConfig.isDarkTheme ? false :
                                                                  true
            }
          }

          MenuItem {
            text: qsTr("Zoom Out")
            onTriggered: zoomOut()
          }

          MenuItem {
            text: qsTr("Exit")
            onTriggered: Qt.quit()
          }
        }
    }
}



