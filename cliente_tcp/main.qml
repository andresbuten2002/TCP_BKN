import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import CustomTypes 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Chat Grupal")

    Button {
        id: button
        x: 432
        y: 412
        width: 152
        height: 40
        text: qsTr("Send")
    }

    Rectangle {
        id: rectangle
        x: 54
        y: 127
        width: 335
        height: 259
        color: "#d7eef1"
        radius: 6
        border.width: 2
        border.color: "#599899"
    }

    Rectangle {
        id: rectangle1
        x: 432
        y: 127
        width: 152
        height: 259
        color: "#d7eef1"
        radius: 6
        border.color: "#599899"
        border.width: 2
    }

    TextField {
        id: textField
        x: 54
        y: 412
        width: 335
        height: 40
        placeholderText: qsTr("Write here...")
    }

    Text {
        id: element
        x: 466
        y: 104
        text: qsTr("List of Connect")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 208
        y: 104
        text: qsTr("Chat")
        font.pixelSize: 12
    }

    TextField {
        id: text_ip
        x: 54
        y: 39
        width: 181
        height: 40
        placeholderText: qsTr("IP")
    }

    TextField {
        id: text_puerto
        x: 237
        y: 39
        width: 152
        height: 40
        placeholderText: qsTr("port")
    }

    // Crear una instancia de TCPSocket
    TCPSocket {
        id: tcpSocket // asignamos un ID para referenciarlo
    }

    Button {
        id: button_connect
        x: 432
        y: 39
        width: 152
        height: 40
        text: qsTr("Connect")

        //Conectar al servidor
        onClicked: {
            // Obtener el host y el puerto de los campos de texto
            console.log("IP recibida:", text_ip.text);
            console.log("Puerto Recibido: ", text_puerto.text);
            tcpSocket.host = text_ip.text
            tcpSocket.port = parseInt(text_puerto.text)
            tcpSocket.connect()
        }
    }
}
