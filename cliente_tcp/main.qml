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
        id: button_send
        x: 432
        y: 412
        width: 152
        height: 40
        text: qsTr("Send")
        onClicked: {
            var messagesend = text_send.text;
            console.log("Enviando mensaje:", messagesend);
            tcpSocket.write(messagesend + "\n");
            text_send.text = "" // Limpiar el campo de texto después de enviar el mensaje
        }
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

        ScrollView {
                        id: scrollView
                        anchors.fill: parent
                        clip: true // Asegura que el contenido no se extienda más allá del ScrollView
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn // Muestra la barra de desplazamiento vertical
                        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff // No muestra la barra de desplazamiento horizontal

                        TextArea {
                            id: text_chat
                            wrapMode: TextArea.Wrap
                            text: qsTr("")
                            font.pixelSize: 12
                            readOnly: true // El usuario no puede editar el texto
                        }
                        property int maxLines: 5 // Máximo número de líneas permitidas en el área de chat
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
        // Función de manejo de eventos cuando la conexión se establece correctamente
        onConnected: {
            // Habilitar el campo de texto text_mensaje
            text_send.visible = true
            console.log("Conectado al Servidor");
        }

        onRead: {
                    var receivedMessage = message.toString().trim();
                    console.log("Mensaje recibido:", receivedMessage);

                    if (receivedMessage.startsWith("USERS:")) {
                        // Mensaje de lista de usuarios conectados
                        var userList = receivedMessage.substring("USERS:".length).trim(); // Eliminar "USERS:" del inicio
                        conectados.text = userList + "\n";
                        // Aquí puedes procesar userList para actualizar la lista de usuarios conectados
                        console.log("Lista de usuarios conectados:", userList);
                    } else {
                        // Mensaje de chat normal
                        text_chat.text += receivedMessage + "\n";
                    }
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

        ScrollView {
                        id: scrollView_lista
                        anchors.fill: parent
                        clip: true // Asegura que el contenido no se extienda más allá del ScrollView
                        ScrollBar.vertical.policy: ScrollBar.AlwaysOn // Muestra la barra de desplazamiento vertical
                        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff // No muestra la barra de desplazamiento horizontal

                        TextArea {
                            id: conectados
                            wrapMode: TextArea.Wrap
                            text: qsTr("")
                            font.pixelSize: 12
                            readOnly: true // El usuario no puede editar el texto
                        }
                        property int maxLines: 5 // Máximo número de líneas permitidas en el área de chat
                    }
        }
}
