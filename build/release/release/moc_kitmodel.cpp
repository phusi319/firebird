/****************************************************************************
** Meta object code from reading C++ file 'kitmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../kitmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kitmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KitModel_t {
    QByteArrayData data[32];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KitModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KitModel_t qt_meta_stringdata_KitModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "KitModel"
QT_MOC_LITERAL(1, 9, 15), // "anythingChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "rowCount"
QT_MOC_LITERAL(4, 35, 11), // "QModelIndex"
QT_MOC_LITERAL(5, 47, 6), // "parent"
QT_MOC_LITERAL(6, 54, 9), // "roleNames"
QT_MOC_LITERAL(7, 64, 21), // "QHash<int,QByteArray>"
QT_MOC_LITERAL(8, 86, 4), // "data"
QT_MOC_LITERAL(9, 91, 5), // "index"
QT_MOC_LITERAL(10, 97, 4), // "role"
QT_MOC_LITERAL(11, 102, 10), // "getDataRow"
QT_MOC_LITERAL(12, 113, 3), // "row"
QT_MOC_LITERAL(13, 117, 10), // "setDataRow"
QT_MOC_LITERAL(14, 128, 5), // "value"
QT_MOC_LITERAL(15, 134, 4), // "copy"
QT_MOC_LITERAL(16, 139, 6), // "remove"
QT_MOC_LITERAL(17, 146, 6), // "addKit"
QT_MOC_LITERAL(18, 153, 4), // "name"
QT_MOC_LITERAL(19, 158, 5), // "boot1"
QT_MOC_LITERAL(20, 164, 5), // "flash"
QT_MOC_LITERAL(21, 170, 13), // "snapshot_path"
QT_MOC_LITERAL(22, 184, 10), // "indexForID"
QT_MOC_LITERAL(23, 195, 2), // "id"
QT_MOC_LITERAL(24, 198, 12), // "allKitsEmpty"
QT_MOC_LITERAL(25, 211, 4), // "Role"
QT_MOC_LITERAL(26, 216, 6), // "IDRole"
QT_MOC_LITERAL(27, 223, 8), // "NameRole"
QT_MOC_LITERAL(28, 232, 8), // "TypeRole"
QT_MOC_LITERAL(29, 241, 9), // "FlashRole"
QT_MOC_LITERAL(30, 251, 9), // "Boot1Role"
QT_MOC_LITERAL(31, 261, 12) // "SnapshotRole"

    },
    "KitModel\0anythingChanged\0\0rowCount\0"
    "QModelIndex\0parent\0roleNames\0"
    "QHash<int,QByteArray>\0data\0index\0role\0"
    "getDataRow\0row\0setDataRow\0value\0copy\0"
    "remove\0addKit\0name\0boot1\0flash\0"
    "snapshot_path\0indexForID\0id\0allKitsEmpty\0"
    "Role\0IDRole\0NameRole\0TypeRole\0FlashRole\0"
    "Boot1Role\0SnapshotRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KitModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       1,  142, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    1,   90,    2, 0x02 /* Public */,
       3,    0,   93,    2, 0x22 /* Public | MethodCloned */,
       6,    0,   94,    2, 0x02 /* Public */,
       8,    2,   95,    2, 0x02 /* Public */,
       8,    1,  100,    2, 0x22 /* Public | MethodCloned */,
      11,    2,  103,    2, 0x02 /* Public */,
      11,    1,  108,    2, 0x22 /* Public | MethodCloned */,
      13,    3,  111,    2, 0x02 /* Public */,
      13,    2,  118,    2, 0x22 /* Public | MethodCloned */,
      15,    1,  123,    2, 0x02 /* Public */,
      16,    1,  126,    2, 0x02 /* Public */,
      17,    4,  129,    2, 0x02 /* Public */,
      22,    1,  138,    2, 0x02 /* Public */,
      24,    0,  141,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, 0x80000000 | 4,    5,
    QMetaType::Int,
    0x80000000 | 7,
    QMetaType::QVariant, 0x80000000 | 4, QMetaType::Int,    9,   10,
    QMetaType::QVariant, 0x80000000 | 4,    9,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int,   12,   10,
    QMetaType::QVariant, QMetaType::Int,   12,
    QMetaType::Bool, QMetaType::Int, QMetaType::QVariant, QMetaType::Int,   12,   14,   10,
    QMetaType::Bool, QMetaType::Int, QMetaType::QVariant,   12,   14,
    QMetaType::Bool, QMetaType::Int,   12,
    QMetaType::Bool, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,   21,
    QMetaType::Int, QMetaType::UInt,   23,
    QMetaType::Bool,

 // enums: name, alias, flags, count, data
      25,   25, 0x0,    6,  147,

 // enum data: key, value
      26, uint(KitModel::IDRole),
      27, uint(KitModel::NameRole),
      28, uint(KitModel::TypeRole),
      29, uint(KitModel::FlashRole),
      30, uint(KitModel::Boot1Role),
      31, uint(KitModel::SnapshotRole),

       0        // eod
};

void KitModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KitModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->anythingChanged(); break;
        case 1: { int _r = _t->rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->rowCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QHash<int,QByteArray> _r = _t->roleNames();
            if (_a[0]) *reinterpret_cast< QHash<int,QByteArray>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 5: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->getDataRow((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 7: { QVariant _r = _t->getDataRow((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->setDataRow((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->setDataRow((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->copy((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->remove((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->addKit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 13: { int _r = _t->indexForID((*reinterpret_cast< const uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->allKitsEmpty();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KitModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KitModel::anythingChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KitModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_KitModel.data,
    qt_meta_data_KitModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KitModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KitModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KitModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int KitModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void KitModel::anythingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
