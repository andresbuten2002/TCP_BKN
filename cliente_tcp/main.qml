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

    //property bool nickRequested: false // Bandera para rastrear si el servidor ha solicitado el nick

    Button {
        id: button_send
        x: 432
        y: 412
        width: 152
        height: 40
        text: qsTr("Send")
        onClicked: {
            var message = text_send.text;
            console.log("Enviando mensaje:", message);
            tcpSocket.write(message + "\n");
            //updateChat("Yo:" + message)
            text_send.text = "" // Limpiar el campo de texto después de enviar el mensaje
        }
        //enabled: nickRequested // El botón solo está habilitado cuando se solicita el nick
    }

    function updateChat(message) {
        // Agrega el mensaje al recuadro de chat
        text_chat.text += message + "\n";
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

        Text {
            id: text_chat
            x: 8
            y: 8
            text: qsTr("")
            font.pixelSize: 12
        }
    }

    TextField {
        id: text_send
        x: 54
        y: 412
        visible: false
        width: 335
        height: 40
        placeholderText: qsTr("Write here...")
        //enabled: nickRequested // Habilita el TextField cuando se solicita el nick
    }

    Text {
        id: element
        x: 466
        y: 104
        text: qsTr("List of Connect")
        font.pixelSize: 12
    }

    // Propiedad para almacenar el nick ingresado por el usuario
    property string nickInput: ""

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
        // Función de manejo de eventos cuando la conexión se establece correctamente
        onConnected: {
            // Habilitar el campo de texto text_mensaje
            text_send.visible = true
            console.log("Conectado al Servidor");
            // Agregar el nick del cliente recién conectado a la lista
            connectedClients.push(text_send.text);
            // Actualizar la interfaz de usuario
            updateConnectedClients();
        }
        onRead: {
            var receivedMessage = message.toString().trim();
            console.log("Mensaje recibido:", receivedMessage);

            text_chat.text += receivedMessage + "\n";
            //window.nickRequested = true;
        }
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

    Rectangle {
        id: marco_conectados
        x: 432
        y: 127
        width: 152
        height: 259
        color: "#d7eef1"
        radius: 6
        border.color: "#599899"
        border.width: 2
        Text {
            id: conectados
            x: 8
            y: 8
            text: qsTr("")
            font.pixelSize: 12
        }
    }
}
