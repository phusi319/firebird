/****************************************************************************
** Meta object code from reading C++ file 'usblinktreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../usblinktreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usblinktreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_USBLinkTreeWidget_t {
    QByteArrayData data[19];
    char stringdata0[243];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_USBLinkTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_USBLinkTreeWidget_t qt_meta_stringdata_USBLinkTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "USBLinkTreeWidget"
QT_MOC_LITERAL(1, 18, 16), // "downloadProgress"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "progress"
QT_MOC_LITERAL(4, 45, 14), // "uploadProgress"
QT_MOC_LITERAL(5, 60, 17), // "wantToAddTreeItem"
QT_MOC_LITERAL(6, 78, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 95, 4), // "item"
QT_MOC_LITERAL(8, 100, 6), // "parent"
QT_MOC_LITERAL(9, 107, 12), // "wantToReload"
QT_MOC_LITERAL(10, 120, 17), // "reloadFilebrowser"
QT_MOC_LITERAL(11, 138, 26), // "customContextMenuRequested"
QT_MOC_LITERAL(12, 165, 3), // "pos"
QT_MOC_LITERAL(13, 169, 18), // "dataChangedHandler"
QT_MOC_LITERAL(14, 188, 6), // "column"
QT_MOC_LITERAL(15, 195, 13), // "downloadEntry"
QT_MOC_LITERAL(16, 209, 11), // "deleteEntry"
QT_MOC_LITERAL(17, 221, 9), // "newFolder"
QT_MOC_LITERAL(18, 231, 11) // "addTreeItem"

    },
    "USBLinkTreeWidget\0downloadProgress\0\0"
    "progress\0uploadProgress\0wantToAddTreeItem\0"
    "QTreeWidgetItem*\0item\0parent\0wantToReload\0"
    "reloadFilebrowser\0customContextMenuRequested\0"
    "pos\0dataChangedHandler\0column\0"
    "downloadEntry\0deleteEntry\0newFolder\0"
    "addTreeItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_USBLinkTreeWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    2,   75,    2, 0x06 /* Public */,
       9,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   81,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    0,   92,    2, 0x08 /* Private */,
      18,    2,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int,    7,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,

       0        // eod
};

void USBLinkTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<USBLinkTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->uploadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->wantToAddTreeItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 3: _t->wantToReload(); break;
        case 4: _t->reloadFilebrowser(); break;
        case 5: _t->customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->dataChangedHandler((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->downloadEntry(); break;
        case 8: _t->deleteEntry(); break;
        case 9: _t->newFolder(); break;
        case 10: _t->addTreeItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (USBLinkTreeWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLinkTreeWidget::downloadProgress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (USBLinkTreeWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLinkTreeWidget::uploadProgress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (USBLinkTreeWidget::*)(QTreeWidgetItem * , QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLinkTreeWidget::wantToAddTreeItem)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (USBLinkTreeWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLinkTreeWidget::wantToReload)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject USBLinkTreeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_meta_stringdata_USBLinkTreeWidget.data,
    qt_meta_data_USBLinkTreeWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *USBLinkTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *USBLinkTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_USBLinkTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int USBLinkTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void USBLinkTreeWidget::downloadProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void USBLinkTreeWidget::uploadProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void USBLinkTreeWidget::wantToAddTreeItem(QTreeWidgetItem * _t1, QTreeWidgetItem * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void USBLinkTreeWidget::wantToReload()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
