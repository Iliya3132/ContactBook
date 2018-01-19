import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.3
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.0


ApplicationWindow{
id: mainWindow
visible: true
width: 640
height: 480
title: qsTr("Contact Book")

ColumnLayout {
       id: colLayout
       anchors.top: parent.top
       anchors.right: parent.right
       anchors.margins: 20

       spacing: 10

       Label {
           id: labelName
           text: qsTr("Имя")
           font.pixelSize: 16
       }
       TextField {
           anchors.top: labelName.bottom

           id: nameField

           font.pixelSize: 16
       }
       Label {
           id: labelPhone
           anchors.top: nameField.bottom
           anchors.leftMargin: 5
           font.pixelSize: 16
           text: qsTr("Телефон")
           }
       TextField {
           id: phoneField
           anchors.top: labelPhone.bottom

           font.pixelSize: 16
           anchors.leftMargin: 5
       }
       Label{
           id: corrMass
           visible: false
           anchors.top: phoneField.bottom
           anchors.left: phoneField.left
           anchors.leftMargin: 5
           color: "red"
           text: qsTr("Введите все данные")
       }
       Button {
           anchors.top: corrMass.bottom
           anchors.right: parent.right
           anchors.left: parent.left
           implicitHeight: 50
           Text {
               text: "Добавить"
               anchors.centerIn: parent
               font.pixelSize: 20
               style: Text.Sunken
               color: "black"

           }
           onClicked: {

               if(!myModel.createNewContact(nameField.text,phoneField.text)){
                   corrMass.visible = true;
               }else{
                   corrMass.visible = false;
                   nameField.text = ""
                   phoneField.text = ""
               }

           }
       }
   }

TableView {
        id: tableView
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: colLayout.left
        anchors.bottom: parent.bottom
        anchors.margins: 5
        model: myModel
        TableViewColumn {
            role: "NameRole"
            title: "Имя"

        }
        TableViewColumn {
            role: "PhoneRole"
            title: "Телефон"
        }
        rowDelegate: Rectangle {
            anchors.fill: parent
            color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white');

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.RightButton | Qt.LeftButton

                onClicked: {
                tableView.selection.clear()
                tableView.selection.select(styleData.row)
                tableView.currentRow = styleData.row
                tableView.focus = true
                    switch(mouse.button) {
                        case Qt.RightButton:
                            contextMenu.popup() // Вызов контекстного меню
                            break
                        default:
                            break
                        }
                }

            }
        }

}

Menu {
       id: contextMenu
       MenuItem {
           text: qsTr("Удалить")
           onTriggered: {
               myModel.delateContact(tableView.currentRow)
           }
       }
       MenuItem {
           text: qsTr("Изменить")
           onTriggered: {
             dialogChange.show()
           }
       }
   }
Window{
   id: dialogChange

   width: 300
   height: 400
   title: qsTr("Изминение записи")

   ColumnLayout {
          id: colLay
          anchors.top: parent.top
          anchors.left: parent.left
          anchors.right: parent.right
          spacing: 10
        Column{
          id: colLayCol
          anchors.centerIn: parent
          width: 450
          Label {
              font.pixelSize: 16
              text: qsTr("Имя")
          }
          TextField {

            id: changeNameField
            font.pixelSize: 16
            width: 170

          }
          Label {
              id: changeLabelPhone

              font.pixelSize: 16
              text: qsTr("Телефон")
              }
          TextField {
              id: changePhoneField
              width: 170
              font.pixelSize: 16

          }
      }
        Button{
           id:ok
           anchors.top: colLay.bottom
           anchors.right: colLayCol.right
           anchors.left: colLayCol.left
           implicitHeight: 50

           Text {
               text: "Изменить"
               anchors.centerIn: parent
               font.pixelSize: 20
               style: Text.Sunken
               color: "black"

           }
           onClicked:{
               myModel.changeContact(changeNameField.text,changePhoneField.text,tableView.currentRow)
               changeNameField.text = ""
               changePhoneField.text = ""
               dialogChange.close()
           }

      }
 }
}







}




