/****************************************************************************
** Meta object code from reading C++ file 'emuthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../emuthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emuthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EmuThread_t {
    QByteArrayData data[35];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmuThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmuThread_t qt_meta_stringdata_EmuThread = {
    {
QT_MOC_LITERAL(0, 0, 9), // "EmuThread"
QT_MOC_LITERAL(1, 10, 7), // "started"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "success"
QT_MOC_LITERAL(4, 27, 7), // "resumed"
QT_MOC_LITERAL(5, 35, 9), // "suspended"
QT_MOC_LITERAL(6, 45, 7), // "stopped"
QT_MOC_LITERAL(7, 53, 6), // "paused"
QT_MOC_LITERAL(8, 60, 1), // "b"
QT_MOC_LITERAL(9, 62, 10), // "serialChar"
QT_MOC_LITERAL(10, 73, 1), // "c"
QT_MOC_LITERAL(11, 75, 6), // "isBusy"
QT_MOC_LITERAL(12, 82, 4), // "busy"
QT_MOC_LITERAL(13, 87, 9), // "statusMsg"
QT_MOC_LITERAL(14, 97, 3), // "str"
QT_MOC_LITERAL(15, 101, 12), // "speedChanged"
QT_MOC_LITERAL(16, 114, 5), // "value"
QT_MOC_LITERAL(17, 120, 14), // "usblinkChanged"
QT_MOC_LITERAL(18, 135, 5), // "state"
QT_MOC_LITERAL(19, 141, 16), // "turboModeChanged"
QT_MOC_LITERAL(20, 158, 8), // "debugStr"
QT_MOC_LITERAL(21, 167, 15), // "debuggerEntered"
QT_MOC_LITERAL(22, 183, 19), // "debugInputRequested"
QT_MOC_LITERAL(23, 203, 3), // "run"
QT_MOC_LITERAL(24, 207, 9), // "setPaused"
QT_MOC_LITERAL(25, 217, 9), // "is_paused"
QT_MOC_LITERAL(26, 227, 4), // "stop"
QT_MOC_LITERAL(27, 232, 5), // "reset"
QT_MOC_LITERAL(28, 238, 6), // "resume"
QT_MOC_LITERAL(29, 245, 4), // "path"
QT_MOC_LITERAL(30, 250, 7), // "suspend"
QT_MOC_LITERAL(31, 258, 12), // "setTurboMode"
QT_MOC_LITERAL(32, 271, 11), // "toggleTurbo"
QT_MOC_LITERAL(33, 283, 13), // "enterDebugger"
QT_MOC_LITERAL(34, 297, 13) // "debuggerInput"

    },
    "EmuThread\0started\0\0success\0resumed\0"
    "suspended\0stopped\0paused\0b\0serialChar\0"
    "c\0isBusy\0busy\0statusMsg\0str\0speedChanged\0"
    "value\0usblinkChanged\0state\0turboModeChanged\0"
    "debugStr\0debuggerEntered\0debugInputRequested\0"
    "run\0setPaused\0is_paused\0stop\0reset\0"
    "resume\0path\0suspend\0setTurboMode\0"
    "toggleTurbo\0enterDebugger\0debuggerInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmuThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       4,    1,  137,    2, 0x06 /* Public */,
       5,    1,  140,    2, 0x06 /* Public */,
       6,    0,  143,    2, 0x06 /* Public */,
       7,    1,  144,    2, 0x06 /* Public */,
       9,    1,  147,    2, 0x06 /* Public */,
      11,    1,  150,    2, 0x06 /* Public */,
      13,    1,  153,    2, 0x06 /* Public */,
      15,    1,  156,    2, 0x06 /* Public */,
      17,    1,  159,    2, 0x06 /* Public */,
      19,    1,  162,    2, 0x06 /* Public */,
      20,    1,  165,    2, 0x06 /* Public */,
      21,    1,  168,    2, 0x06 /* Public */,
      22,    1,  171,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  174,    2, 0x0a /* Public */,
      24,    1,  175,    2, 0x0a /* Public */,
      26,    0,  178,    2, 0x0a /* Public */,
      27,    0,  179,    2, 0x0a /* Public */,
      28,    1,  180,    2, 0x0a /* Public */,
      30,    1,  183,    2, 0x0a /* Public */,
      31,    1,  186,    2, 0x0a /* Public */,
      32,    0,  189,    2, 0x0a /* Public */,
      33,    0,  190,    2, 0x0a /* Public */,
      34,    1,  191,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Char,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

void EmuThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmuThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->started((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->resumed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->suspended((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->stopped(); break;
        case 4: _t->paused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->serialChar((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 6: _t->isBusy((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->statusMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->speedChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->usblinkChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->turboModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->debugStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->debuggerEntered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->debugInputRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->run(); break;
        case 15: _t->setPaused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: { bool _r = _t->stop();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->reset(); break;
        case 18: { bool _r = _t->resume((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->suspend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->setTurboMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->toggleTurbo(); break;
        case 22: _t->enterDebugger(); break;
        case 23: _t->debuggerInput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::started)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::resumed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::suspended)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::stopped)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::paused)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::serialChar)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::isBusy)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::statusMsg)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::speedChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::usblinkChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::turboModeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::debugStr)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::debuggerEntered)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (EmuThread::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EmuThread::debugInputRequested)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EmuThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_EmuThread.data,
    qt_meta_data_EmuThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EmuThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmuThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmuThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int EmuThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void EmuThread::started(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EmuThread::resumed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EmuThread::suspended(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EmuThread::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void EmuThread::paused(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void EmuThread::serialChar(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void EmuThread::isBusy(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EmuThread::statusMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void EmuThread::speedChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void EmuThread::usblinkChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void EmuThread::turboModeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void EmuThread::debugStr(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void EmuThread::debuggerEntered(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void EmuThread::debugInputRequested(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
