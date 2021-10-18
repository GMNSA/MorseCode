import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12

Row {
  id: _root

  property alias fbtnEncrypt: _btnEncrypt
  property alias fbtnClear: _btnClear
  property alias fbtnCopy: _btnCopy

  anchors.bottom: parent.bottom
  anchors.horizontalCenter: parent.horizontalCenter
  spacing: 10

  Button {
    id: _btnClear
    text: qsTr("Clear")
 }

  Button {
    id: _btnEncrypt
    text: qsTr("Encrypt")
  }

  Button {
    id: _btnCopy
    text: qsTr("Copy")
  }
}
