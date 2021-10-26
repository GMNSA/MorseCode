import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.3

import ModuleStyle 1.0
import ModuleHelp.Impl 1.0
// import ModuleMorseCode.Impl 1.0
import ModuleAbout.Impl 1.0
import ModuleHeader.Impl 1.0
import ModuleEncryptMorseCode.Impl 1.0
import ModuleMorseCodeDecrypt.Impl 1.0


ApplicationWindow {
    id: _root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: StyleConfig.isDarkTheme ? Material.Dark : 
                                              Material.Light

    header: ImplHeader {
        id: _header
        property string ftitleText: "Morse Code"

    }

    StackView {
        id: _stackView
        initialItem: _morseEncryptCode
        // initialItem: _morseDecrypt
        anchors.fill: parent

    }

    ImplHelp {
        id: _help
        visible: false

    }

    ImplEncryptMorseCode {
        id: _morseEncryptCode
        visible: false
    }

    ImplMorseCodeDecrypt {
        id: _morseDecrypt
        visible: false

    }

    ImplAbout {
        id: _about
        visible: false
    }

    Drawer {
        id: _drawer
        width: _root.width * 0.66
        height: _root.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Encrypt Morse Code")
                width: parent.width
                onClicked: {
                    if (_stackView.depth > 1)
                    {
                        _stackView.pop()
                        console.log("morse code pop")
                    }
                    _stackView.push(_morseEncryptCode)
                    _drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("Morse Code decrypting")
                width: parent.width
                onClicked: {
                    if (_stackView.depth > 1)
                    {
                        _stackView.pop()
                        console.log("morse code pop")
                    }
                    _stackView.push(_morseDecrypt)
                    _drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("Help")
                width: parent.width
                onClicked: {
                    if (_stackView.depth > 1)
                    {
                        _stackView.pop()
                        console.log("help pop")
                    }
                    _stackView.push(_help)
                    _drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("About")
                width: parent.width
                onClicked: {
                    if (_stackView.depth > 1)
                    {
                        _stackView.pop()
                        console.log("about pop")
                    }
                    _stackView.push(_about)
                    _drawer.close()
                }
            }

            ItemDelegate {
                text: qsTr("Exit")
                width: parent.width
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }
}
