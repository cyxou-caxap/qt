/****************************************************************************
** Meta object code from reading C++ file 'passengers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../passengers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passengers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Passengers_t {
    QByteArrayData data[14];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Passengers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Passengers_t qt_meta_stringdata_Passengers = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Passengers"
QT_MOC_LITERAL(1, 11, 21), // "sigUpdateFilterParams"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 43), // "PassengerSortFilterProxyModel..."
QT_MOC_LITERAL(4, 78, 6), // "params"
QT_MOC_LITERAL(5, 85, 18), // "sigRemovePassenger"
QT_MOC_LITERAL(6, 104, 14), // "passangerIndex"
QT_MOC_LITERAL(7, 119, 34), // "handleDeletePassengerButtonCl..."
QT_MOC_LITERAL(8, 154, 31), // "handleAddPassengerButtonClicked"
QT_MOC_LITERAL(9, 186, 33), // "handleAddPassengerButtonActiv..."
QT_MOC_LITERAL(10, 220, 24), // "handleUpdateFilterParams"
QT_MOC_LITERAL(11, 245, 23), // "handleClearFilterParams"
QT_MOC_LITERAL(12, 269, 34), // "handleChangePassengerButtonCl..."
QT_MOC_LITERAL(13, 304, 33) // "handleCurrentSelectedIndexCha..."

    },
    "Passengers\0sigUpdateFilterParams\0\0"
    "PassengerSortFilterProxyModel::FilterParams\0"
    "params\0sigRemovePassenger\0passangerIndex\0"
    "handleDeletePassengerButtonClicked\0"
    "handleAddPassengerButtonClicked\0"
    "handleAddPassengerButtonActivated\0"
    "handleUpdateFilterParams\0"
    "handleClearFilterParams\0"
    "handleChangePassengerButtonClicked\0"
    "handleCurrentSelectedIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Passengers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QModelIndex,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Passengers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Passengers *_t = static_cast<Passengers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateFilterParams((*reinterpret_cast< const PassengerSortFilterProxyModel::FilterParams(*)>(_a[1]))); break;
        case 1: _t->sigRemovePassenger((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->handleDeletePassengerButtonClicked(); break;
        case 3: _t->handleAddPassengerButtonClicked(); break;
        case 4: { bool _r = _t->handleAddPassengerButtonActivated();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->handleUpdateFilterParams(); break;
        case 6: _t->handleClearFilterParams(); break;
        case 7: _t->handleChangePassengerButtonClicked(); break;
        case 8: _t->handleCurrentSelectedIndexChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Passengers::*_t)(const PassengerSortFilterProxyModel::FilterParams & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Passengers::sigUpdateFilterParams)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Passengers::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Passengers::sigRemovePassenger)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Passengers::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Passengers.data,
      qt_meta_data_Passengers,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Passengers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Passengers::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Passengers.stringdata0))
        return static_cast<void*>(const_cast< Passengers*>(this));
    return QWidget::qt_metacast(_clname);
}

int Passengers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void Passengers::sigUpdateFilterParams(const PassengerSortFilterProxyModel::FilterParams & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Passengers::sigRemovePassenger(const QModelIndex & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
