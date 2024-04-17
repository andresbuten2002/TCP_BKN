#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QStringList>
#include <iostream>

class Usuario : public QObject {
    Q_OBJECT
public:
    Usuario(QTcpSocket* socket, QObject *parent = nullptr) : QObject(parent), socket(socket) {}

    QString obtenerNick() const {
        return nick;
    }

    void establecerNick(const QString& nuevoNick) {
        nick = nuevoNick;
    }

    QTcpSocket* obtenerSocket() const {
        return socket;
    }

private:
    QString nick;
    QTcpSocket* socket;
};

class Chat : public QTcpServer {
    Q_OBJECT

public:
    Chat(QObject *parent = nullptr) : QTcpServer(parent) {}

protected:
    void incomingConnection(qintptr socketDescriptor) override {
        QTcpSocket *clientSocket = new QTcpSocket(this);
        clientSocket->setSocketDescriptor(socketDescriptor);

        Usuario *user = new Usuario(clientSocket, this);
        usuarios.append(user);

        connect(clientSocket, &QTcpSocket::readyRead, this, [this, user]() {
            recibirMensaje(user);
        });

        sendToUser(user, "Bienvenido al chat. Por favor ingresa tu nick:");

        QObject::connect(clientSocket, &QTcpSocket::disconnected, this, [this, user]() {
            usuarios.removeOne(user);
            user->deleteLater();
        });
    }

private slots:
    void recibirMensaje(Usuario* user) {
        QTcpSocket *clientSocket = user->obtenerSocket();
        while (clientSocket->canReadLine()) {
            QString message = QString::fromUtf8(clientSocket->readLine()).trimmed();
            if (user->obtenerNick().isEmpty()) {
                // Si el usuario no tiene un nick, establecerlo
                user->establecerNick(message);
                broadcast(QString("%1 se ha unido al chat.").arg(user->obtenerNick()), user);
            } else {
                // Si tiene un nick, enviar el mensaje a todos los usuarios
                broadcast(QString("%1: %2").arg(user->obtenerNick(), message), user);
            }
        }
    }

private:
    QList<Usuario*> usuarios;

    void sendToUser(Usuario* user, const QString &message) {
        user->obtenerSocket()->write(message.toUtf8());
    }

    void broadcast(const QString &message, Usuario* sender) {
        for (Usuario* user : usuarios) {
            if (user != sender) {
                sendToUser(user, message.toUtf8());
            }
        }
    }
};

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    Chat server;
    if (!server.listen(QHostAddress::Any, 1234)) {
        std::cerr << "Error: no se pudo iniciar el servidor." << std::endl;
        return 1;
    }

    std::cout << "Servidor de chat iniciado. Esperando conexiones en el puerto 1234..." << std::endl;
    return app.exec();
}

#include "main.moc"
