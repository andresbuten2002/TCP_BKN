/****************************************************************************
** Meta object code from reading C++ file 'tcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../cliente_tcp/tcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPSocket_t {
    QByteArrayData data[16];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPSocket_t qt_meta_stringdata_TCPSocket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPSocket"
QT_MOC_LITERAL(1, 10, 11), // "hostChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "portChanged"
QT_MOC_LITERAL(4, 35, 12), // "stateChanged"
QT_MOC_LITERAL(5, 48, 4), // "read"
QT_MOC_LITERAL(6, 53, 7), // "message"
QT_MOC_LITERAL(7, 61, 9), // "connected"
QT_MOC_LITERAL(8, 71, 12), // "disconnected"
QT_MOC_LITERAL(9, 84, 7), // "connect"
QT_MOC_LITERAL(10, 92, 10), // "disconnect"
QT_MOC_LITERAL(11, 103, 5), // "write"
QT_MOC_LITERAL(12, 109, 4), // "host"
QT_MOC_LITERAL(13, 114, 4), // "port"
QT_MOC_LITERAL(14, 119, 5), // "state"
QT_MOC_LITERAL(15, 125, 28) // "QAbstractSocket::SocketState"

    },
    "TCPSocket\0hostChanged\0\0portChanged\0"
    "stateChanged\0read\0message\0connected\0"
    "disconnected\0connect\0disconnect\0write\0"
    "host\0port\0state\0QAbstractSocket::SocketState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPSocket[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   72, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    0,   65,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495003,
      13, QMetaType::UInt, 0x00495003,
      14, 0x80000000 | 15, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,
       2,

 // enums: name, alias, flags, count, data

 // enum data: key, value

       0        // eod
};

void TCPSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCPSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hostChanged(); break;
        case 1: _t->portChanged(); break;
        case 2: _t->stateChanged(); break;
        case 3: _t->read((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->connected(); break;
        case 5: _t->disconnected(); break;
        case 6: _t->connect(); break;
        case 7: _t->disconnect(); break;
        case 8: _t->write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCPSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::hostChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCPSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::portChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TCPSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::stateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TCPSocket::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::read)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TCPSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::connected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TCPSocket::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPSocket::disconnected)) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TCPSocket *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_host; break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->m_port; break;
        case 2: *reinterpret_cast< QAbstractSocket::SocketState*>(_v) = _t->m_state; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TCPSocket *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_host != *reinterpret_cast< QString*>(_v)) {
                _t->m_host = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->hostChanged();
            }
            break;
        case 1:
            if (_t->m_port != *reinterpret_cast< uint*>(_v)) {
                _t->m_port = *reinterpret_cast< uint*>(_v);
                Q_EMIT _t->portChanged();
            }
            break;
        case 2:
            if (_t->m_state != *reinterpret_cast< QAbstractSocket::SocketState*>(_v)) {
                _t->m_state = *reinterpret_cast< QAbstractSocket::SocketState*>(_v);
                Q_EMIT _t->stateChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

static const QMetaObject::SuperData qt_meta_extradata_TCPSocket[] = {
    QMetaObject::SuperData::link<QAbstractSocket::staticMetaObject>(),
    nullptr
};

QT_INIT_METAOBJECT const QMetaObject TCPSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TCPSocket.data,
    qt_meta_data_TCPSocket,
    qt_static_metacall,
    qt_meta_extradata_TCPSocket,
    nullptr
} };


const QMetaObject *TCPSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TCPSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TCPSocket::hostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TCPSocket::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TCPSocket::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TCPSocket::read(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TCPSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TCPSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
