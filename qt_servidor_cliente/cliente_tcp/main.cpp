#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tcp.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Crear instancia de TCPSocket
    TCPSocket tcpSocket;

    // Registrar TCPSocket como tipo QML
    qmlRegisterType<TCPSocket>("CustomTypes", 1, 0, "TCPSocket");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
