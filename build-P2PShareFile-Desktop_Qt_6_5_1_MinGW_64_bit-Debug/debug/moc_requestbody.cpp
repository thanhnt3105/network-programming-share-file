/****************************************************************************
** Meta object code from reading C++ file 'requestbody.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../P2PShareFile/element/requestbody.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requestbody.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSRequestBodyENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRequestBodyENDCLASS = QtMocHelpers::stringData(
    "RequestBody",
    "getRequestBody",
    "",
    "setRequestBody",
    "body",
    "createLoginBody",
    "username",
    "password",
    "host",
    "port",
    "createLogoutBody",
    "id",
    "createRegisterBody",
    "createSearchFileBody",
    "fileName",
    "createSearchAllFilesBody",
    "createUploadFileBody",
    "userId",
    "filePath",
    "createGetFileByUserIdBody"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRequestBodyENDCLASS_t {
    uint offsetsAndSizes[40];
    char stringdata0[12];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[16];
    char stringdata6[9];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[17];
    char stringdata11[3];
    char stringdata12[19];
    char stringdata13[21];
    char stringdata14[9];
    char stringdata15[25];
    char stringdata16[21];
    char stringdata17[7];
    char stringdata18[9];
    char stringdata19[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRequestBodyENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRequestBodyENDCLASS_t qt_meta_stringdata_CLASSRequestBodyENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "RequestBody"
        QT_MOC_LITERAL(12, 14),  // "getRequestBody"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 14),  // "setRequestBody"
        QT_MOC_LITERAL(43, 4),  // "body"
        QT_MOC_LITERAL(48, 15),  // "createLoginBody"
        QT_MOC_LITERAL(64, 8),  // "username"
        QT_MOC_LITERAL(73, 8),  // "password"
        QT_MOC_LITERAL(82, 4),  // "host"
        QT_MOC_LITERAL(87, 4),  // "port"
        QT_MOC_LITERAL(92, 16),  // "createLogoutBody"
        QT_MOC_LITERAL(109, 2),  // "id"
        QT_MOC_LITERAL(112, 18),  // "createRegisterBody"
        QT_MOC_LITERAL(131, 20),  // "createSearchFileBody"
        QT_MOC_LITERAL(152, 8),  // "fileName"
        QT_MOC_LITERAL(161, 24),  // "createSearchAllFilesBody"
        QT_MOC_LITERAL(186, 20),  // "createUploadFileBody"
        QT_MOC_LITERAL(207, 6),  // "userId"
        QT_MOC_LITERAL(214, 8),  // "filePath"
        QT_MOC_LITERAL(223, 25)   // "createGetFileByUserIdBody"
    },
    "RequestBody",
    "getRequestBody",
    "",
    "setRequestBody",
    "body",
    "createLoginBody",
    "username",
    "password",
    "host",
    "port",
    "createLogoutBody",
    "id",
    "createRegisterBody",
    "createSearchFileBody",
    "fileName",
    "createSearchAllFilesBody",
    "createUploadFileBody",
    "userId",
    "filePath",
    "createGetFileByUserIdBody"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRequestBodyENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    1,   69,    2, 0x0a,    2 /* Public */,
       5,    4,   72,    2, 0x0a,    4 /* Public */,
      10,    2,   81,    2, 0x0a,    9 /* Public */,
      12,    2,   86,    2, 0x0a,   12 /* Public */,
      13,    1,   91,    2, 0x0a,   15 /* Public */,
      15,    0,   94,    2, 0x0a,   17 /* Public */,
      16,    3,   95,    2, 0x0a,   18 /* Public */,
      19,    1,  102,    2, 0x0a,   22 /* Public */,

 // slots: parameters
    QMetaType::QJsonObject,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::UShort,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString,   11,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong, QMetaType::QString, QMetaType::QString,   17,   14,   18,
    QMetaType::Void, QMetaType::UShort,   17,

       0        // eod
};

Q_CONSTINIT const QMetaObject RequestBody::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSRequestBodyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRequestBodyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRequestBodyENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RequestBody, std::true_type>,
        // method 'getRequestBody'
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'setRequestBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>,
        // method 'createLoginBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'createLogoutBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createRegisterBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createSearchFileBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createSearchAllFilesBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createUploadFileBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint64, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'createGetFileByUserIdBody'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>
    >,
    nullptr
} };

void RequestBody::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RequestBody *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QJsonObject _r = _t->getRequestBody();
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setRequestBody((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 2: _t->createLoginBody((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[4]))); break;
        case 3: _t->createLogoutBody((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->createRegisterBody((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->createSearchFileBody((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->createSearchAllFilesBody(); break;
        case 7: _t->createUploadFileBody((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->createGetFileByUserIdBody((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *RequestBody::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RequestBody::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRequestBodyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RequestBody::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
