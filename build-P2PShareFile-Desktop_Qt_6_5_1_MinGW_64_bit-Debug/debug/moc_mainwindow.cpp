/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../P2PShareFile/scence/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "connectServer",
    "",
    "haveconnected",
    "displayError",
    "QAbstractSocket::SocketError",
    "openFile",
    "startTransferFile",
    "updateClientProgress",
    "updateServerProgress",
    "on_openButton_clicked",
    "on_connectButton_clicked",
    "on_disconnectButton_clicked",
    "on_sendFileButton_clicked",
    "on_openFolderButton_clicked",
    "on_textBrowser_textChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[13];
    char stringdata5[29];
    char stringdata6[9];
    char stringdata7[18];
    char stringdata8[21];
    char stringdata9[21];
    char stringdata10[22];
    char stringdata11[25];
    char stringdata12[28];
    char stringdata13[26];
    char stringdata14[28];
    char stringdata15[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "connectServer"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 13),  // "haveconnected"
        QT_MOC_LITERAL(40, 12),  // "displayError"
        QT_MOC_LITERAL(53, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(82, 8),  // "openFile"
        QT_MOC_LITERAL(91, 17),  // "startTransferFile"
        QT_MOC_LITERAL(109, 20),  // "updateClientProgress"
        QT_MOC_LITERAL(130, 20),  // "updateServerProgress"
        QT_MOC_LITERAL(151, 21),  // "on_openButton_clicked"
        QT_MOC_LITERAL(173, 24),  // "on_connectButton_clicked"
        QT_MOC_LITERAL(198, 27),  // "on_disconnectButton_clicked"
        QT_MOC_LITERAL(226, 25),  // "on_sendFileButton_clicked"
        QT_MOC_LITERAL(252, 27),  // "on_openFolderButton_clicked"
        QT_MOC_LITERAL(280, 26)   // "on_textBrowser_textChanged"
    },
    "MainWindow",
    "connectServer",
    "",
    "haveconnected",
    "displayError",
    "QAbstractSocket::SocketError",
    "openFile",
    "startTransferFile",
    "updateClientProgress",
    "updateServerProgress",
    "on_openButton_clicked",
    "on_connectButton_clicked",
    "on_disconnectButton_clicked",
    "on_sendFileButton_clicked",
    "on_openFolderButton_clicked",
    "on_textBrowser_textChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    1,   94,    2, 0x08,    3 /* Private */,
       6,    0,   97,    2, 0x08,    5 /* Private */,
       7,    0,   98,    2, 0x08,    6 /* Private */,
       8,    1,   99,    2, 0x08,    7 /* Private */,
       9,    0,  102,    2, 0x08,    9 /* Private */,
      10,    0,  103,    2, 0x08,   10 /* Private */,
      11,    0,  104,    2, 0x08,   11 /* Private */,
      12,    0,  105,    2, 0x08,   12 /* Private */,
      13,    0,  106,    2, 0x08,   13 /* Private */,
      14,    0,  107,    2, 0x08,   14 /* Private */,
      15,    0,  108,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'connectServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'haveconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'openFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startTransferFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateClientProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'updateServerProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_connectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_disconnectButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sendFileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openFolderButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_textBrowser_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectServer(); break;
        case 1: _t->haveconnected(); break;
        case 2: _t->displayError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 3: _t->openFile(); break;
        case 4: _t->startTransferFile(); break;
        case 5: _t->updateClientProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 6: _t->updateServerProgress(); break;
        case 7: _t->on_openButton_clicked(); break;
        case 8: _t->on_connectButton_clicked(); break;
        case 9: _t->on_disconnectButton_clicked(); break;
        case 10: _t->on_sendFileButton_clicked(); break;
        case 11: _t->on_openFolderButton_clicked(); break;
        case 12: _t->on_textBrowser_textChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
