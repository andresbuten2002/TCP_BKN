#include <QtNetwork>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QList>
#include <QStringList>
#include <iostream>

class Usuario : public QObject {
    Q_OBJECT
public:
    Usuario(QWebSocket* socket, QObject *parent = nullptr) : QObject(parent), socket(socket) {}

    QString obtenerNick() const {
        return nick;
    }

    void establecerNick(const QString& nuevoNick) {
        nick = nuevoNick;
    }

    QWebSocket* obtenerSocket() const {
        return socket;
    }

private:
    QString nick;
    QWebSocket* socket;
};

class Chat : public QObject {
    Q_OBJECT

public:
    Chat(QObject *parent = nullptr) : QObject(parent) {
        server = new QWebSocketServer(QStringLiteral("Chat Server"), QWebSocketServer::NonSecureMode, this);
        if (!server->listen(QHostAddress::Any, 1234)) {
            std::cerr << "Error: no se pudo iniciar el servidor." << std::endl;
            return;
        }
        connect(server, &QWebSocketServer::newConnection, this, &Chat::nuevaConexion);
        std::cout << "Servidor de chat iniciado. Esperando conexiones en el puerto 1234..." << std::endl;
    }

private slots:
    void nuevaConexion() {
        QWebSocket *clientSocket = server->nextPendingConnection();

        Usuario *user = new Usuario(clientSocket, this);
        usuarios.append(user);

        connect(clientSocket, &QWebSocket::textMessageReceived, this, [this, user](const QString &message) {
            recibirMensaje(user, message);
        });

        sendToUser(user, "Bienvenido al chat. Por favor ingresa tu nick:");

        connect(clientSocket, &QWebSocket::disconnected, this, [this, user]() {
            usuarios.removeOne(user);
            user->deleteLater();
        });
    }

    void recibirMensaje(Usuario* user, const QString& message) {
        QWebSocket *clientSocket = user->obtenerSocket();
        if (user->obtenerNick().isEmpty()) {
            // Si el usuario no tiene un nick, establecerlo
            user->establecerNick(message);
            broadcast(QString("%1 se ha unido al chat.").arg(user->obtenerNick()), user);
        } else {
            // Si tiene un nick, enviar el mensaje a todos los usuarios
            broadcast(QString("%1: %2").arg(user->obtenerNick(), message), user);
        }
    }

    void sendToUser(Usuario* user, const QString &message) {
        user->obtenerSocket()->sendTextMessage(message);
    }

    void broadcast(const QString &message, Usuario* sender) {
        for (Usuario* user : usuarios) {
            if (user != sender) {
                sendToUser(user, message);
            }
        }
    }

private:
    QWebSocketServer *server;
    QList<Usuario*> usuarios;
};

#include "main.moc"
