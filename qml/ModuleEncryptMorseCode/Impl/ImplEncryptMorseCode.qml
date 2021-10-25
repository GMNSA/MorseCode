import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.12
import ModuleMorseCode.Impl 1.0
import ModuleMorseCode.ButtonsPanel.Impl 1.0

import ModuleStyle 1.0

ImplMorseCode {
    id: _root

    ImplButtonsPanel {
        id: _btnsPanel

        fbtnEncrypt.onClicked: {
          if (foriginalText.text != "")
          {
            fencryptText.text = fmorseCode.encryption(foriginalText.text)
            foriginalText.text = fmorseCode.lastOriginalCode()
          }
        }

        fbtnCopy.onClicked: {
          fencryptText.selectAll()
          fencryptText.copy()
        }

        fbtnClear.onClicked: {
          fencryptText.clear()
          foriginalText.clear()
        }
    }
}
