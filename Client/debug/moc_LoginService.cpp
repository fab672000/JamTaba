/****************************************************************************
** Meta object code from reading C++ file 'LoginService.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/jamtaba/loginserver/LoginService.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Login__LoginService_t {
    QByteArrayData data[20];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Login__LoginService_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Login__LoginService_t qt_meta_stringdata_Login__LoginService = {
    {
QT_MOC_LITERAL(0, 0, 19), // "Login::LoginService"
QT_MOC_LITERAL(1, 20, 18), // "roomsListAvailable"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 22), // "QList<Login::RoomInfo>"
QT_MOC_LITERAL(4, 63, 11), // "publicRooms"
QT_MOC_LITERAL(5, 75, 22), // "disconnectedFromServer"
QT_MOC_LITERAL(6, 98, 33), // "incompatibilityWithServerDete..."
QT_MOC_LITERAL(7, 132, 30), // "newVersionAvailableForDownload"
QT_MOC_LITERAL(8, 163, 27), // "errorWhenConnectingToServer"
QT_MOC_LITERAL(9, 191, 13), // "connectedSlot"
QT_MOC_LITERAL(10, 205, 16), // "disconnectedSlot"
QT_MOC_LITERAL(11, 222, 21), // "roomsListReceivedSlot"
QT_MOC_LITERAL(12, 244, 9), // "errorSlot"
QT_MOC_LITERAL(13, 254, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(14, 282, 24), // "connectNetworkReplySlots"
QT_MOC_LITERAL(15, 307, 14), // "QNetworkReply*"
QT_MOC_LITERAL(16, 322, 5), // "reply"
QT_MOC_LITERAL(17, 328, 7), // "Command"
QT_MOC_LITERAL(18, 336, 7), // "command"
QT_MOC_LITERAL(19, 344, 16) // "refreshTimerSlot"

    },
    "Login::LoginService\0roomsListAvailable\0"
    "\0QList<Login::RoomInfo>\0publicRooms\0"
    "disconnectedFromServer\0"
    "incompatibilityWithServerDetected\0"
    "newVersionAvailableForDownload\0"
    "errorWhenConnectingToServer\0connectedSlot\0"
    "disconnectedSlot\0roomsListReceivedSlot\0"
    "errorSlot\0QNetworkReply::NetworkError\0"
    "connectNetworkReplySlots\0QNetworkReply*\0"
    "reply\0Command\0command\0refreshTimerSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Login__LoginService[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      14,    2,   82,    2, 0x08 /* Private */,
      19,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void,

       0        // eod
};

void Login::LoginService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginService *_t = static_cast<LoginService *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->roomsListAvailable((*reinterpret_cast< QList<Login::RoomInfo>(*)>(_a[1]))); break;
        case 1: _t->disconnectedFromServer(); break;
        case 2: _t->incompatibilityWithServerDetected(); break;
        case 3: _t->newVersionAvailableForDownload(); break;
        case 4: _t->errorWhenConnectingToServer(); break;
        case 5: _t->connectedSlot(); break;
        case 6: _t->disconnectedSlot(); break;
        case 7: _t->roomsListReceivedSlot(); break;
        case 8: _t->errorSlot((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 9: _t->connectNetworkReplySlots((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< Command(*)>(_a[2]))); break;
        case 10: _t->refreshTimerSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginService::*_t)(QList<Login::RoomInfo> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginService::roomsListAvailable)) {
                *result = 0;
            }
        }
        {
            typedef void (LoginService::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginService::disconnectedFromServer)) {
                *result = 1;
            }
        }
        {
            typedef void (LoginService::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginService::incompatibilityWithServerDetected)) {
                *result = 2;
            }
        }
        {
            typedef void (LoginService::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginService::newVersionAvailableForDownload)) {
                *result = 3;
            }
        }
        {
            typedef void (LoginService::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginService::errorWhenConnectingToServer)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Login::LoginService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Login__LoginService.data,
      qt_meta_data_Login__LoginService,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Login::LoginService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Login::LoginService::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Login__LoginService.stringdata0))
        return static_cast<void*>(const_cast< LoginService*>(this));
    return QObject::qt_metacast(_clname);
}

int Login::LoginService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Login::LoginService::roomsListAvailable(QList<Login::RoomInfo> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Login::LoginService::disconnectedFromServer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Login::LoginService::incompatibilityWithServerDetected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Login::LoginService::newVersionAvailableForDownload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Login::LoginService::errorWhenConnectingToServer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE