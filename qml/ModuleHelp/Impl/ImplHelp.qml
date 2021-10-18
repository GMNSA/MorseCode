import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import Qt.labs.qmlmodels 1.0

Page {
    id: _root




 TableView {
     anchors.fill: parent
     columnSpacing: 1
     rowSpacing: 1
     clip: true

     model: TableModel {
         TableModelColumn { display: "letter" }
         TableModelColumn { display: "morse" }

         rows: [
             {
                 "letter": "A",
                 "morse": "*-"
             },
             {
                 "letter": "B",
                 "morse": "-***"
             },
             {
                 "letter": "C",
                 "morse": "-*-*"
             },
             {
                 "letter": "D",
                 "morse": "-**"
             },
             {
                 "letter": "E",
                 "morse": "*"
             },
         ]
     }

     delegate: Rectangle {
         implicitWidth: 100
         implicitHeight: 50
         border.width: 1

         Text {
             text: display
             anchors.centerIn: parent
         }
     }
 }




    Text {
        anchors.centerIn: parent

        text: "HELP"
    }
}
