pragma Singleton
import QtQuick 2.12
import QtQuick.Controls 2.15

QtObject {
    id: _root

    property bool isDarkTheme: true
    readonly property int smalMargin: 5
    readonly property int middleMargin: 10
    property string blueGrey: isDarkTheme ? "#B0BEC5" :
                                            "#607D8B"
    property string colorText: isDarkTheme ? "lightBlue" :
                                             "#2E2F30"

}
