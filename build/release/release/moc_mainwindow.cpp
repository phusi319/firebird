/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QQuickWidgetLessBroken_t {
    QByteArrayData data[1];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QQuickWidgetLessBroken_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QQuickWidgetLessBroken_t qt_meta_stringdata_QQuickWidgetLessBroken = {
    {
QT_MOC_LITERAL(0, 0, 22) // "QQuickWidgetLessBroken"

    },
    "QQuickWidgetLessBroken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QQuickWidgetLessBroken[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QQuickWidgetLessBroken::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QQuickWidgetLessBroken::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickWidget::staticMetaObject>(),
    qt_meta_stringdata_QQuickWidgetLessBroken.data,
    qt_meta_data_QQuickWidgetLessBroken,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QQuickWidgetLessBroken::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QQuickWidgetLessBroken::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QQuickWidgetLessBroken.stringdata0))
        return static_cast<void*>(this);
    return QQuickWidget::qt_metacast(_clname);
}

int QQuickWidgetLessBroken::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[65];
    char stringdata0[690];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "debuggerCommand"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "input"
QT_MOC_LITERAL(4, 34, 24), // "usblink_progress_changed"
QT_MOC_LITERAL(5, 59, 8), // "progress"
QT_MOC_LITERAL(6, 68, 11), // "changeEvent"
QT_MOC_LITERAL(7, 80, 7), // "QEvent*"
QT_MOC_LITERAL(8, 88, 5), // "event"
QT_MOC_LITERAL(9, 94, 10), // "closeEvent"
QT_MOC_LITERAL(10, 105, 12), // "QCloseEvent*"
QT_MOC_LITERAL(11, 118, 13), // "showStatusMsg"
QT_MOC_LITERAL(12, 132, 3), // "str"
QT_MOC_LITERAL(13, 136, 14), // "kitDataChanged"
QT_MOC_LITERAL(14, 151, 11), // "QModelIndex"
QT_MOC_LITERAL(15, 163, 12), // "QVector<int>"
QT_MOC_LITERAL(16, 176, 5), // "roles"
QT_MOC_LITERAL(17, 182, 18), // "kitAnythingChanged"
QT_MOC_LITERAL(18, 201, 17), // "currentKitChanged"
QT_MOC_LITERAL(19, 219, 3), // "Kit"
QT_MOC_LITERAL(20, 223, 3), // "kit"
QT_MOC_LITERAL(21, 227, 9), // "dropEvent"
QT_MOC_LITERAL(22, 237, 11), // "QDropEvent*"
QT_MOC_LITERAL(23, 249, 14), // "dragEnterEvent"
QT_MOC_LITERAL(24, 264, 16), // "QDragEnterEvent*"
QT_MOC_LITERAL(25, 281, 2), // "ev"
QT_MOC_LITERAL(26, 284, 7), // "restart"
QT_MOC_LITERAL(27, 292, 17), // "openConfiguration"
QT_MOC_LITERAL(28, 310, 8), // "startKit"
QT_MOC_LITERAL(29, 319, 13), // "startKitDiags"
QT_MOC_LITERAL(30, 333, 10), // "screenshot"
QT_MOC_LITERAL(31, 344, 9), // "recordGIF"
QT_MOC_LITERAL(32, 354, 10), // "connectUSB"
QT_MOC_LITERAL(33, 365, 14), // "usblinkChanged"
QT_MOC_LITERAL(34, 380, 5), // "state"
QT_MOC_LITERAL(35, 386, 9), // "setExtLCD"
QT_MOC_LITERAL(36, 396, 10), // "xmodemSend"
QT_MOC_LITERAL(37, 407, 16), // "switchToMobileUI"
QT_MOC_LITERAL(38, 424, 6), // "resume"
QT_MOC_LITERAL(39, 431, 7), // "suspend"
QT_MOC_LITERAL(40, 439, 14), // "resumeFromFile"
QT_MOC_LITERAL(41, 454, 13), // "suspendToFile"
QT_MOC_LITERAL(42, 468, 9), // "saveFlash"
QT_MOC_LITERAL(43, 478, 11), // "createFlash"
QT_MOC_LITERAL(44, 490, 13), // "setUIEditMode"
QT_MOC_LITERAL(45, 504, 1), // "e"
QT_MOC_LITERAL(46, 506, 9), // "showAbout"
QT_MOC_LITERAL(47, 516, 6), // "isBusy"
QT_MOC_LITERAL(48, 523, 4), // "busy"
QT_MOC_LITERAL(49, 528, 7), // "started"
QT_MOC_LITERAL(50, 536, 7), // "success"
QT_MOC_LITERAL(51, 544, 7), // "resumed"
QT_MOC_LITERAL(52, 552, 9), // "suspended"
QT_MOC_LITERAL(53, 562, 7), // "stopped"
QT_MOC_LITERAL(54, 570, 10), // "serialChar"
QT_MOC_LITERAL(55, 581, 1), // "c"
QT_MOC_LITERAL(56, 583, 19), // "debugInputRequested"
QT_MOC_LITERAL(57, 603, 1), // "b"
QT_MOC_LITERAL(58, 605, 8), // "debugStr"
QT_MOC_LITERAL(59, 614, 12), // "debugCommand"
QT_MOC_LITERAL(60, 627, 14), // "changeProgress"
QT_MOC_LITERAL(61, 642, 5), // "value"
QT_MOC_LITERAL(62, 648, 15), // "usblinkDownload"
QT_MOC_LITERAL(63, 664, 15), // "usblinkProgress"
QT_MOC_LITERAL(64, 680, 9) // "showSpeed"

    },
    "MainWindow\0debuggerCommand\0\0input\0"
    "usblink_progress_changed\0progress\0"
    "changeEvent\0QEvent*\0event\0closeEvent\0"
    "QCloseEvent*\0showStatusMsg\0str\0"
    "kitDataChanged\0QModelIndex\0QVector<int>\0"
    "roles\0kitAnythingChanged\0currentKitChanged\0"
    "Kit\0kit\0dropEvent\0QDropEvent*\0"
    "dragEnterEvent\0QDragEnterEvent*\0ev\0"
    "restart\0openConfiguration\0startKit\0"
    "startKitDiags\0screenshot\0recordGIF\0"
    "connectUSB\0usblinkChanged\0state\0"
    "setExtLCD\0xmodemSend\0switchToMobileUI\0"
    "resume\0suspend\0resumeFromFile\0"
    "suspendToFile\0saveFlash\0createFlash\0"
    "setUIEditMode\0e\0showAbout\0isBusy\0busy\0"
    "started\0success\0resumed\0suspended\0"
    "stopped\0serialChar\0c\0debugInputRequested\0"
    "b\0debugStr\0debugCommand\0changeProgress\0"
    "value\0usblinkDownload\0usblinkProgress\0"
    "showSpeed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x06 /* Public */,
       4,    1,  227,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  230,    2, 0x0a /* Public */,
       9,    1,  233,    2, 0x0a /* Public */,
      11,    1,  236,    2, 0x0a /* Public */,
      13,    3,  239,    2, 0x0a /* Public */,
      17,    0,  246,    2, 0x0a /* Public */,
      18,    1,  247,    2, 0x0a /* Public */,
      21,    1,  250,    2, 0x0a /* Public */,
      23,    1,  253,    2, 0x0a /* Public */,
      26,    0,  256,    2, 0x0a /* Public */,
      27,    0,  257,    2, 0x0a /* Public */,
      28,    0,  258,    2, 0x0a /* Public */,
      29,    0,  259,    2, 0x0a /* Public */,
      30,    0,  260,    2, 0x0a /* Public */,
      31,    0,  261,    2, 0x0a /* Public */,
      32,    0,  262,    2, 0x0a /* Public */,
      33,    1,  263,    2, 0x0a /* Public */,
      35,    1,  266,    2, 0x0a /* Public */,
      36,    0,  269,    2, 0x0a /* Public */,
      37,    0,  270,    2, 0x0a /* Public */,
      38,    0,  271,    2, 0x0a /* Public */,
      39,    0,  272,    2, 0x0a /* Public */,
      40,    0,  273,    2, 0x0a /* Public */,
      41,    0,  274,    2, 0x0a /* Public */,
      42,    0,  275,    2, 0x0a /* Public */,
      43,    0,  276,    2, 0x0a /* Public */,
      44,    1,  277,    2, 0x0a /* Public */,
      46,    0,  280,    2, 0x0a /* Public */,
      47,    1,  281,    2, 0x0a /* Public */,
      49,    1,  284,    2, 0x0a /* Public */,
      51,    1,  287,    2, 0x0a /* Public */,
      52,    1,  290,    2, 0x0a /* Public */,
      53,    0,  293,    2, 0x0a /* Public */,
      54,    1,  294,    2, 0x0a /* Public */,
      56,    1,  297,    2, 0x0a /* Public */,
      58,    1,  300,    2, 0x0a /* Public */,
      59,    0,  303,    2, 0x0a /* Public */,
      60,    1,  304,    2, 0x0a /* Public */,
      62,    1,  307,    2, 0x0a /* Public */,
      63,    1,  310,    2, 0x0a /* Public */,
      64,    1,  313,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 15,    2,    2,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22,    8,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   48,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,   55,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Double,   61,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->debuggerCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->usblink_progress_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 3: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 4: _t->showStatusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->kitDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2])),(*reinterpret_cast< QVector<int>(*)>(_a[3]))); break;
        case 6: _t->kitAnythingChanged(); break;
        case 7: _t->currentKitChanged((*reinterpret_cast< const Kit(*)>(_a[1]))); break;
        case 8: _t->dropEvent((*reinterpret_cast< QDropEvent*(*)>(_a[1]))); break;
        case 9: _t->dragEnterEvent((*reinterpret_cast< QDragEnterEvent*(*)>(_a[1]))); break;
        case 10: _t->restart(); break;
        case 11: _t->openConfiguration(); break;
        case 12: _t->startKit(); break;
        case 13: _t->startKitDiags(); break;
        case 14: _t->screenshot(); break;
        case 15: _t->recordGIF(); break;
        case 16: _t->connectUSB(); break;
        case 17: _t->usblinkChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setExtLCD((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->xmodemSend(); break;
        case 20: _t->switchToMobileUI(); break;
        case 21: { bool _r = _t->resume();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->suspend(); break;
        case 23: _t->resumeFromFile(); break;
        case 24: _t->suspendToFile(); break;
        case 25: _t->saveFlash(); break;
        case 26: _t->createFlash(); break;
        case 27: _t->setUIEditMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->showAbout(); break;
        case 29: _t->isBusy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->started((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->resumed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->suspended((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->stopped(); break;
        case 34: _t->serialChar((*reinterpret_cast< const char(*)>(_a[1]))); break;
        case 35: _t->debugInputRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->debugStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->debugCommand(); break;
        case 38: _t->changeProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->usblinkDownload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->usblinkProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->showSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::debuggerCommand)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::usblink_progress_changed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::debuggerCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::usblink_progress_changed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
