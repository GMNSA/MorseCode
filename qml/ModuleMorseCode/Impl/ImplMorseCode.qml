import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import debug.morsecode 1.0

import ModuleMorseCode.ButtonsPanel.Impl 1.0
import ModuleStyle 1.0

Page {
    id: _root
    anchors.fill: parent

    property alias foriginalText: _textOriginal
    property alias fencryptText: _textEncrypt
    property alias fmorseCode: _morseCode
    property string ftextPlaceholder: "ENTER THE TEXT"

    MorseCode {
        id: _morseCode
    }

    Column {
        id: _columnMorse
        anchors.fill: parent

        Flickable {
            id: _flick
            width: parent.width
            height: parent.height * 0.5
            clip: true

            TextArea.flickable: TextArea {
              id: _textOriginal

              padding: 30
              wrapMode: TextEdit.WordWrap
              focus: true

              color: StyleConfig.colorText
              placeholderText: ftextPlaceholder

              // tap hightlight text
              onFocusChanged: {
                  if (_textOriginal.focus === true)
                  {
                      _textOriginal.selectAll()
                      console.log("ACTIVE")
                  }
              }
            }
        }

        Rectangle {
          width: parent.width
          height: parent.height * 0.5
          color: "transparent"

          Flickable {
            id: _flickable
            width: parent.width * 0.9
            height: parent.height * 0.9
            anchors.centerIn: parent
            contentHeight: _flickable.height * 4
            contentWidth: parent.width
            interactive: true
            boundsBehavior: Flickable.StopAtBounds
            clip: true

            TextEdit {
              id: _textEncrypt
              wrapMode: Text.WordWrap
              width: parent.width * 0.9
              verticalAlignment: parent.verticalCenter
              // onTextChanged: width = Math.min(_flickable.width, contentWidth)
              antialiasing: true
              color: StyleConfig.colorText
              font.pixelSize: 20
              selectionColor: "lightblue"
              readOnly: true
              clip: true
            }
          }

        }
    }
}
