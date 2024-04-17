import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
//import QtNetwork 2.14

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

    Button {
        id: button_connect
        x: 432
        y: 39
        width: 152
        height: 40
        text: qsTr("Connect")

        onClicked: {
            var ip_origen = text_ip.text
            var puerto_origen = parseInt(text_puerto.text)


            // Crear un objeto QTcpSocket para la conexión TCP
            var socket = new QtNetwork.QTcpSocket();

            // Conectar a la dirección IP y el puerto proporcionados
            socket.connectToHost(ip_origen, puerto_origen);

            // Manejar eventos de conexión
            socket.connected.connect(function() {
                console.log("Conexión establecida con éxito.");
                // Aquí puedes agregar acciones adicionales que deseas realizar cuando la conexión se establece con éxito.
            });

            socket.error.connect(function(error) {
                console.error("Error al conectar:", error);
                // Aquí puedes manejar errores de conexión, como conexión rechazada o timeout.
            });
        }
    }
}
