import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import ModuleMorseCode.Impl 1.0
import ModuleMorseCode.ButtonsPanel.Impl 1.0

import ModuleStyle 1.0

ImplMorseCode {
    id: _root

    ftextPlaceholder: "Morse Code Decrypt"

    ImplButtonsPanel {
        id: _btnsPanel

        fbtnEncrypt.text: "Decrypt"

        ComboBox {
            id: _comboBox
            editable: false
            model: ListModel {
                id: model
                ListElement { text: "En" }
                ListElement { text: "Rus" }
            }
            onAccepted: {
                if (find(editText) === -1)
                    model.append({text: editText})
            }
        }


        fbtnEncrypt.onClicked: {
            if (foriginalText.text != "")
            {
                fencryptText.text = fmorseCode.decrypt(foriginalText.text,
                                                         _comboBox.currentIndex)
            }
        }

        fbtnCopy.onClicked: {
          fencryptText.selectAll()
          fencryptText.copy()
        }

        fbtnClear.onClicked: {
          fmorseCode.clearData();
          fencryptText.clear()
          foriginalText.clear()
        }
    }
}
