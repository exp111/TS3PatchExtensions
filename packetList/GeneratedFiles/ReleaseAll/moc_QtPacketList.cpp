/****************************************************************************
** Meta object code from reading C++ file 'QtPacketList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtPacketList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtPacketList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtPacketList_t {
    QByteArrayData data[9];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtPacketList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtPacketList_t qt_meta_stringdata_QtPacketList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QtPacketList"
QT_MOC_LITERAL(1, 13, 11), // "updateLists"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "copyTextToClipboard"
QT_MOC_LITERAL(4, 46, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(5, 63, 11), // "sendCommand"
QT_MOC_LITERAL(6, 75, 15), // "checkSendButton"
QT_MOC_LITERAL(7, 91, 22), // "checkParseFieldsButton"
QT_MOC_LITERAL(8, 114, 11) // "parseFields"

    },
    "QtPacketList\0updateLists\0\0copyTextToClipboard\0"
    "QTreeWidgetItem*\0sendCommand\0"
    "checkSendButton\0checkParseFieldsButton\0"
    "parseFields"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtPacketList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtPacketList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtPacketList *_t = static_cast<QtPacketList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateLists(); break;
        case 1: _t->copyTextToClipboard((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->sendCommand(); break;
        case 3: _t->checkSendButton(); break;
        case 4: _t->checkParseFieldsButton(); break;
        case 5: _t->parseFields(); break;
        default: ;
        }
    }
}

const QMetaObject QtPacketList::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtPacketList.data,
      qt_meta_data_QtPacketList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtPacketList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtPacketList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtPacketList.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtPacketList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
