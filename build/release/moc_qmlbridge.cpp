/****************************************************************************
** Meta object code from reading C++ file 'qmlbridge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qmlbridge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmlbridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMLBridge_t {
    QByteArrayData data[103];
    char stringdata0[1146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMLBridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMLBridge_t qt_meta_stringdata_QMLBridge = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QMLBridge"
QT_MOC_LITERAL(1, 10, 14), // "gdbPortChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "gdbEnabledChanged"
QT_MOC_LITERAL(4, 44, 14), // "rdbPortChanged"
QT_MOC_LITERAL(5, 59, 17), // "rdbEnabledChanged"
QT_MOC_LITERAL(6, 77, 18), // "debugOnWarnChanged"
QT_MOC_LITERAL(7, 96, 19), // "debugOnStartChanged"
QT_MOC_LITERAL(8, 116, 18), // "printOnWarnChanged"
QT_MOC_LITERAL(9, 135, 16), // "autostartChanged"
QT_MOC_LITERAL(10, 152, 17), // "defaultKitChanged"
QT_MOC_LITERAL(11, 170, 17), // "leftHandedChanged"
QT_MOC_LITERAL(12, 188, 21), // "suspendOnCloseChanged"
QT_MOC_LITERAL(13, 210, 13), // "usbDirChanged"
QT_MOC_LITERAL(14, 224, 16), // "isRunningChanged"
QT_MOC_LITERAL(15, 241, 12), // "speedChanged"
QT_MOC_LITERAL(16, 254, 16), // "turboModeChanged"
QT_MOC_LITERAL(17, 271, 17), // "currentKitChanged"
QT_MOC_LITERAL(18, 289, 3), // "Kit"
QT_MOC_LITERAL(19, 293, 3), // "kit"
QT_MOC_LITERAL(20, 297, 12), // "emuSuspended"
QT_MOC_LITERAL(21, 310, 7), // "success"
QT_MOC_LITERAL(22, 318, 22), // "usblinkProgressChanged"
QT_MOC_LITERAL(23, 341, 7), // "percent"
QT_MOC_LITERAL(24, 349, 12), // "toastMessage"
QT_MOC_LITERAL(25, 362, 3), // "msg"
QT_MOC_LITERAL(26, 366, 20), // "touchpadStateChanged"
QT_MOC_LITERAL(27, 387, 1), // "x"
QT_MOC_LITERAL(28, 389, 1), // "y"
QT_MOC_LITERAL(29, 391, 7), // "contact"
QT_MOC_LITERAL(30, 399, 4), // "down"
QT_MOC_LITERAL(31, 404, 18), // "buttonStateChanged"
QT_MOC_LITERAL(32, 423, 2), // "id"
QT_MOC_LITERAL(33, 426, 5), // "state"
QT_MOC_LITERAL(34, 432, 12), // "neverEmitted"
QT_MOC_LITERAL(35, 445, 8), // "saveKits"
QT_MOC_LITERAL(36, 454, 5), // "speed"
QT_MOC_LITERAL(37, 460, 7), // "started"
QT_MOC_LITERAL(38, 468, 7), // "resumed"
QT_MOC_LITERAL(39, 476, 9), // "suspended"
QT_MOC_LITERAL(40, 486, 14), // "setButtonState"
QT_MOC_LITERAL(41, 501, 16), // "setTouchpadState"
QT_MOC_LITERAL(42, 518, 8), // "isMobile"
QT_MOC_LITERAL(43, 527, 8), // "sendFile"
QT_MOC_LITERAL(44, 536, 3), // "url"
QT_MOC_LITERAL(45, 540, 3), // "dir"
QT_MOC_LITERAL(46, 544, 11), // "sendExitPTT"
QT_MOC_LITERAL(47, 556, 8), // "basename"
QT_MOC_LITERAL(48, 565, 4), // "path"
QT_MOC_LITERAL(49, 570, 11), // "toLocalFile"
QT_MOC_LITERAL(50, 582, 10), // "fileExists"
QT_MOC_LITERAL(51, 593, 13), // "kitIndexForID"
QT_MOC_LITERAL(52, 607, 13), // "setCurrentKit"
QT_MOC_LITERAL(53, 621, 15), // "getCurrentKitId"
QT_MOC_LITERAL(54, 637, 6), // "useKit"
QT_MOC_LITERAL(55, 644, 10), // "const Kit*"
QT_MOC_LITERAL(56, 655, 13), // "useDefaultKit"
QT_MOC_LITERAL(57, 669, 7), // "restart"
QT_MOC_LITERAL(58, 677, 9), // "setPaused"
QT_MOC_LITERAL(59, 687, 1), // "b"
QT_MOC_LITERAL(60, 689, 5), // "reset"
QT_MOC_LITERAL(61, 695, 7), // "suspend"
QT_MOC_LITERAL(62, 703, 6), // "resume"
QT_MOC_LITERAL(63, 710, 4), // "stop"
QT_MOC_LITERAL(64, 715, 9), // "saveFlash"
QT_MOC_LITERAL(65, 725, 12), // "getBoot1Path"
QT_MOC_LITERAL(66, 738, 12), // "getFlashPath"
QT_MOC_LITERAL(67, 751, 15), // "getSnapshotPath"
QT_MOC_LITERAL(68, 767, 12), // "switchUIMode"
QT_MOC_LITERAL(69, 780, 9), // "mobile_ui"
QT_MOC_LITERAL(70, 790, 11), // "createFlash"
QT_MOC_LITERAL(71, 802, 9), // "productID"
QT_MOC_LITERAL(72, 812, 13), // "featureValues"
QT_MOC_LITERAL(73, 826, 5), // "manuf"
QT_MOC_LITERAL(74, 832, 5), // "boot2"
QT_MOC_LITERAL(75, 838, 2), // "os"
QT_MOC_LITERAL(76, 841, 5), // "diags"
QT_MOC_LITERAL(77, 847, 20), // "componentDescription"
QT_MOC_LITERAL(78, 868, 13), // "expected_type"
QT_MOC_LITERAL(79, 882, 16), // "manufDescription"
QT_MOC_LITERAL(80, 899, 13), // "osDescription"
QT_MOC_LITERAL(81, 913, 19), // "saveDialogSupported"
QT_MOC_LITERAL(82, 933, 7), // "gdbPort"
QT_MOC_LITERAL(83, 941, 10), // "gdbEnabled"
QT_MOC_LITERAL(84, 952, 7), // "rdbPort"
QT_MOC_LITERAL(85, 960, 10), // "rdbEnabled"
QT_MOC_LITERAL(86, 971, 12), // "debugOnStart"
QT_MOC_LITERAL(87, 984, 11), // "debugOnWarn"
QT_MOC_LITERAL(88, 996, 11), // "printOnWarn"
QT_MOC_LITERAL(89, 1008, 9), // "autostart"
QT_MOC_LITERAL(90, 1018, 10), // "defaultKit"
QT_MOC_LITERAL(91, 1029, 10), // "leftHanded"
QT_MOC_LITERAL(92, 1040, 14), // "suspendOnClose"
QT_MOC_LITERAL(93, 1055, 6), // "usbdir"
QT_MOC_LITERAL(94, 1062, 7), // "version"
QT_MOC_LITERAL(95, 1070, 9), // "isRunning"
QT_MOC_LITERAL(96, 1080, 4), // "kits"
QT_MOC_LITERAL(97, 1085, 9), // "KitModel*"
QT_MOC_LITERAL(98, 1095, 9), // "turboMode"
QT_MOC_LITERAL(99, 1105, 7), // "mobileX"
QT_MOC_LITERAL(100, 1113, 7), // "mobileY"
QT_MOC_LITERAL(101, 1121, 11), // "mobileWidth"
QT_MOC_LITERAL(102, 1133, 12) // "mobileHeight"

    },
    "QMLBridge\0gdbPortChanged\0\0gdbEnabledChanged\0"
    "rdbPortChanged\0rdbEnabledChanged\0"
    "debugOnWarnChanged\0debugOnStartChanged\0"
    "printOnWarnChanged\0autostartChanged\0"
    "defaultKitChanged\0leftHandedChanged\0"
    "suspendOnCloseChanged\0usbDirChanged\0"
    "isRunningChanged\0speedChanged\0"
    "turboModeChanged\0currentKitChanged\0"
    "Kit\0kit\0emuSuspended\0success\0"
    "usblinkProgressChanged\0percent\0"
    "toastMessage\0msg\0touchpadStateChanged\0"
    "x\0y\0contact\0down\0buttonStateChanged\0"
    "id\0state\0neverEmitted\0saveKits\0speed\0"
    "started\0resumed\0suspended\0setButtonState\0"
    "setTouchpadState\0isMobile\0sendFile\0"
    "url\0dir\0sendExitPTT\0basename\0path\0"
    "toLocalFile\0fileExists\0kitIndexForID\0"
    "setCurrentKit\0getCurrentKitId\0useKit\0"
    "const Kit*\0useDefaultKit\0restart\0"
    "setPaused\0b\0reset\0suspend\0resume\0stop\0"
    "saveFlash\0getBoot1Path\0getFlashPath\0"
    "getSnapshotPath\0switchUIMode\0mobile_ui\0"
    "createFlash\0productID\0featureValues\0"
    "manuf\0boot2\0os\0diags\0componentDescription\0"
    "expected_type\0manufDescription\0"
    "osDescription\0saveDialogSupported\0"
    "gdbPort\0gdbEnabled\0rdbPort\0rdbEnabled\0"
    "debugOnStart\0debugOnWarn\0printOnWarn\0"
    "autostart\0defaultKit\0leftHanded\0"
    "suspendOnClose\0usbdir\0version\0isRunning\0"
    "kits\0KitModel*\0turboMode\0mobileX\0"
    "mobileY\0mobileWidth\0mobileHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMLBridge[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
      21,  440, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      22,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  299,    2, 0x06 /* Public */,
       3,    0,  300,    2, 0x06 /* Public */,
       4,    0,  301,    2, 0x06 /* Public */,
       5,    0,  302,    2, 0x06 /* Public */,
       6,    0,  303,    2, 0x06 /* Public */,
       7,    0,  304,    2, 0x06 /* Public */,
       8,    0,  305,    2, 0x06 /* Public */,
       9,    0,  306,    2, 0x06 /* Public */,
      10,    0,  307,    2, 0x06 /* Public */,
      11,    0,  308,    2, 0x06 /* Public */,
      12,    0,  309,    2, 0x06 /* Public */,
      13,    0,  310,    2, 0x06 /* Public */,
      14,    0,  311,    2, 0x06 /* Public */,
      15,    0,  312,    2, 0x06 /* Public */,
      16,    0,  313,    2, 0x06 /* Public */,
      17,    1,  314,    2, 0x06 /* Public */,
      20,    1,  317,    2, 0x06 /* Public */,
      22,    1,  320,    2, 0x06 /* Public */,
      24,    1,  323,    2, 0x06 /* Public */,
      26,    4,  326,    2, 0x06 /* Public */,
      31,    2,  335,    2, 0x06 /* Public */,
      34,    0,  340,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      35,    0,  341,    2, 0x0a /* Public */,
      15,    1,  342,    2, 0x0a /* Public */,
      37,    1,  345,    2, 0x0a /* Public */,
      38,    1,  348,    2, 0x0a /* Public */,
      39,    1,  351,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      40,    2,  354,    2, 0x02 /* Public */,
      41,    4,  359,    2, 0x02 /* Public */,
      42,    0,  368,    2, 0x02 /* Public */,
      43,    2,  369,    2, 0x02 /* Public */,
      46,    0,  374,    2, 0x02 /* Public */,
      47,    1,  375,    2, 0x02 /* Public */,
      45,    1,  378,    2, 0x02 /* Public */,
      49,    1,  381,    2, 0x02 /* Public */,
      50,    1,  384,    2, 0x02 /* Public */,
      51,    1,  387,    2, 0x02 /* Public */,
      52,    1,  390,    2, 0x02 /* Public */,
      53,    0,  393,    2, 0x02 /* Public */,
      54,    1,  394,    2, 0x02 /* Public */,
      56,    0,  397,    2, 0x02 /* Public */,
      57,    0,  398,    2, 0x02 /* Public */,
      58,    1,  399,    2, 0x02 /* Public */,
      60,    0,  402,    2, 0x02 /* Public */,
      61,    0,  403,    2, 0x02 /* Public */,
      62,    0,  404,    2, 0x02 /* Public */,
      63,    0,  405,    2, 0x02 /* Public */,
      64,    0,  406,    2, 0x02 /* Public */,
      65,    0,  407,    2, 0x02 /* Public */,
      66,    0,  408,    2, 0x02 /* Public */,
      67,    0,  409,    2, 0x02 /* Public */,
      68,    1,  410,    2, 0x02 /* Public */,
      70,    7,  413,    2, 0x02 /* Public */,
      77,    2,  428,    2, 0x02 /* Public */,
      79,    1,  433,    2, 0x02 /* Public */,
      80,    1,  436,    2, 0x02 /* Public */,
      81,    0,  439,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::Bool, QMetaType::Bool,   27,   28,   29,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   32,   33,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   32,   33,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::Bool, QMetaType::Bool,   27,   28,   29,   30,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,   44,   45,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,   48,
    QMetaType::QUrl, QMetaType::QString,   48,
    QMetaType::QString, QMetaType::QUrl,   44,
    QMetaType::Bool, QMetaType::QString,   48,
    QMetaType::Int, QMetaType::UInt,   32,
    QMetaType::Bool, QMetaType::UInt,   32,
    QMetaType::Int,
    0x80000000 | 55, QMetaType::UInt,   32,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,   69,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   48,   71,   72,   73,   74,   75,   76,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   48,   78,
    QMetaType::QString, QMetaType::QString,   48,
    QMetaType::QString, QMetaType::QString,   48,
    QMetaType::Bool,

 // properties: name, type, flags
      82, QMetaType::UInt, 0x00495003,
      83, QMetaType::Bool, 0x00495003,
      84, QMetaType::UInt, 0x00495003,
      85, QMetaType::Bool, 0x00495003,
      86, QMetaType::Bool, 0x00495103,
      87, QMetaType::Bool, 0x00495103,
      88, QMetaType::Bool, 0x00495103,
      89, QMetaType::Bool, 0x00495103,
      90, QMetaType::UInt, 0x00495103,
      91, QMetaType::Bool, 0x00495103,
      92, QMetaType::Bool, 0x00495103,
      93, QMetaType::QString, 0x00495003,
      94, QMetaType::QString, 0x00095401,
      95, QMetaType::Bool, 0x00495001,
      96, 0x80000000 | 97, 0x00095409,
      36, QMetaType::Double, 0x00495001,
      98, QMetaType::Bool, 0x00495103,
      99, QMetaType::Int, 0x00495103,
     100, QMetaType::Int, 0x00495103,
     101, QMetaType::Int, 0x00495103,
     102, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       5,
       4,
       6,
       7,
       8,
       9,
      10,
      11,
       0,
      12,
       0,
      13,
      14,
      21,
      21,
      21,
      21,

       0        // eod
};

void QMLBridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMLBridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gdbPortChanged(); break;
        case 1: _t->gdbEnabledChanged(); break;
        case 2: _t->rdbPortChanged(); break;
        case 3: _t->rdbEnabledChanged(); break;
        case 4: _t->debugOnWarnChanged(); break;
        case 5: _t->debugOnStartChanged(); break;
        case 6: _t->printOnWarnChanged(); break;
        case 7: _t->autostartChanged(); break;
        case 8: _t->defaultKitChanged(); break;
        case 9: _t->leftHandedChanged(); break;
        case 10: _t->suspendOnCloseChanged(); break;
        case 11: _t->usbDirChanged(); break;
        case 12: _t->isRunningChanged(); break;
        case 13: _t->speedChanged(); break;
        case 14: _t->turboModeChanged(); break;
        case 15: _t->currentKitChanged((*reinterpret_cast< const Kit(*)>(_a[1]))); break;
        case 16: _t->emuSuspended((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->usblinkProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->toastMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->touchpadStateChanged((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 20: _t->buttonStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->neverEmitted(); break;
        case 22: _t->saveKits(); break;
        case 23: _t->speedChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->started((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->resumed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->suspended((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->setButtonState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 28: _t->setTouchpadState((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 29: { bool _r = _t->isMobile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->sendFile((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 31: _t->sendExitPTT(); break;
        case 32: { QString _r = _t->basename((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QUrl _r = _t->dir((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 34: { QString _r = _t->toLocalFile((*reinterpret_cast< QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 35: { bool _r = _t->fileExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->kitIndexForID((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: { bool _r = _t->setCurrentKit((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { int _r = _t->getCurrentKitId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 39: { const Kit* _r = _t->useKit((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< const Kit**>(_a[0]) = std::move(_r); }  break;
        case 40: { bool _r = _t->useDefaultKit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 41: { bool _r = _t->restart();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->setPaused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->reset(); break;
        case 44: _t->suspend(); break;
        case 45: _t->resume(); break;
        case 46: { bool _r = _t->stop();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->saveFlash();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: { QString _r = _t->getBoot1Path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 49: { QString _r = _t->getFlashPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 50: { QString _r = _t->getSnapshotPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 51: _t->switchUIMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 52: { bool _r = _t->createFlash((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 53: { QString _r = _t->componentDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 54: { QString _r = _t->manufDescription((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 55: { QString _r = _t->osDescription((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 56: { bool _r = _t->saveDialogSupported();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::gdbPortChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::gdbEnabledChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::rdbPortChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::rdbEnabledChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::debugOnWarnChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::debugOnStartChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::printOnWarnChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::autostartChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::defaultKitChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::leftHandedChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::suspendOnCloseChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::usbDirChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::isRunningChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::speedChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::turboModeChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(const Kit & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::currentKitChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::emuSuspended)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::usblinkProgressChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::toastMessage)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(qreal , qreal , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::touchpadStateChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::buttonStateChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (QMLBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMLBridge::neverEmitted)) {
                *result = 21;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< KitModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QMLBridge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->getGDBPort(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getGDBEnabled(); break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->getRDBPort(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->getRDBEnabled(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getDebugOnStart(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->getDebugOnWarn(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getPrintOnWarn(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getAutostart(); break;
        case 8: *reinterpret_cast< uint*>(_v) = _t->getDefaultKit(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->getLeftHanded(); break;
        case 10: *reinterpret_cast< bool*>(_v) = _t->getSuspendOnClose(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->getUSBDir(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->getVersion(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->getIsRunning(); break;
        case 14: *reinterpret_cast< KitModel**>(_v) = _t->getKitModel(); break;
        case 15: *reinterpret_cast< double*>(_v) = _t->getSpeed(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->getTurboMode(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->getMobileX(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->getMobileY(); break;
        case 19: *reinterpret_cast< int*>(_v) = _t->getMobileWidth(); break;
        case 20: *reinterpret_cast< int*>(_v) = _t->getMobileHeight(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QMLBridge *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setGDBPort(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setGDBEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setRDBPort(*reinterpret_cast< uint*>(_v)); break;
        case 3: _t->setRDBEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setDebugOnStart(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setDebugOnWarn(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setPrintOnWarn(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setAutostart(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setDefaultKit(*reinterpret_cast< uint*>(_v)); break;
        case 9: _t->setLeftHanded(*reinterpret_cast< bool*>(_v)); break;
        case 10: _t->setSuspendOnClose(*reinterpret_cast< bool*>(_v)); break;
        case 11: _t->setUSBDir(*reinterpret_cast< QString*>(_v)); break;
        case 16: _t->setTurboMode(*reinterpret_cast< bool*>(_v)); break;
        case 17: _t->setMobileX(*reinterpret_cast< int*>(_v)); break;
        case 18: _t->setMobileY(*reinterpret_cast< int*>(_v)); break;
        case 19: _t->setMobileWidth(*reinterpret_cast< int*>(_v)); break;
        case 20: _t->setMobileHeight(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QMLBridge::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QMLBridge.data,
    qt_meta_data_QMLBridge,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMLBridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMLBridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMLBridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMLBridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 57;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 21;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMLBridge::gdbPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QMLBridge::gdbEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QMLBridge::rdbPortChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QMLBridge::rdbEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QMLBridge::debugOnWarnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QMLBridge::debugOnStartChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QMLBridge::printOnWarnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QMLBridge::autostartChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QMLBridge::defaultKitChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QMLBridge::leftHandedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QMLBridge::suspendOnCloseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QMLBridge::usbDirChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QMLBridge::isRunningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QMLBridge::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void QMLBridge::turboModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void QMLBridge::currentKitChanged(const Kit & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void QMLBridge::emuSuspended(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void QMLBridge::usblinkProgressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QMLBridge::toastMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void QMLBridge::touchpadStateChanged(qreal _t1, qreal _t2, bool _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void QMLBridge::buttonStateChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void QMLBridge::neverEmitted()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
