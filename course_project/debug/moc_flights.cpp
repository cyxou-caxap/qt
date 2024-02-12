/****************************************************************************
** Meta object code from reading C++ file 'flights.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../flights.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flights.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Flights_t {
    QByteArrayData data[16];
    char stringdata0[337];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Flights_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Flights_t qt_meta_stringdata_Flights = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Flights"
QT_MOC_LITERAL(1, 8, 21), // "sigUpdateFilterParams"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 40), // "FlightSortFilterProxyModel::F..."
QT_MOC_LITERAL(4, 72, 6), // "params"
QT_MOC_LITERAL(5, 79, 15), // "sigChangeFlight"
QT_MOC_LITERAL(6, 95, 11), // "flightIndex"
QT_MOC_LITERAL(7, 107, 6), // "Flight"
QT_MOC_LITERAL(8, 114, 15), // "newFlightParams"
QT_MOC_LITERAL(9, 130, 23), // "handleClearFilterParams"
QT_MOC_LITERAL(10, 154, 31), // "handleDeleteFlightButtonClicked"
QT_MOC_LITERAL(11, 186, 28), // "handleAddFlightButtonClicked"
QT_MOC_LITERAL(12, 215, 30), // "handleAddFlightButtonActivated"
QT_MOC_LITERAL(13, 246, 24), // "handleUpdateFilterParams"
QT_MOC_LITERAL(14, 271, 31), // "handleChangeFlightButtonClicked"
QT_MOC_LITERAL(15, 303, 33) // "handleCurrentSelectedIndexCha..."

    },
    "Flights\0sigUpdateFilterParams\0\0"
    "FlightSortFilterProxyModel::FilterParams\0"
    "params\0sigChangeFlight\0flightIndex\0"
    "Flight\0newFlightParams\0handleClearFilterParams\0"
    "handleDeleteFlightButtonClicked\0"
    "handleAddFlightButtonClicked\0"
    "handleAddFlightButtonActivated\0"
    "handleUpdateFilterParams\0"
    "handleChangeFlightButtonClicked\0"
    "handleCurrentSelectedIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Flights[] = {

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
       5,    2,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    0,   70,    2, 0x08 /* Private */,
      13,    0,   71,    2, 0x08 /* Private */,
      14,    0,   72,    2, 0x08 /* Private */,
      15,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 7,    6,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Flights::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Flights *_t = static_cast<Flights *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateFilterParams((*reinterpret_cast< const FlightSortFilterProxyModel::FilterParams(*)>(_a[1]))); break;
        case 1: _t->sigChangeFlight((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const Flight(*)>(_a[2]))); break;
        case 2: _t->handleClearFilterParams(); break;
        case 3: _t->handleDeleteFlightButtonClicked(); break;
        case 4: _t->handleAddFlightButtonClicked(); break;
        case 5: { bool _r = _t->handleAddFlightButtonActivated();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->handleUpdateFilterParams(); break;
        case 7: _t->handleChangeFlightButtonClicked(); break;
        case 8: _t->handleCurrentSelectedIndexChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Flights::*_t)(const FlightSortFilterProxyModel::FilterParams & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Flights::sigUpdateFilterParams)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Flights::*_t)(const QModelIndex & , const Flight & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Flights::sigChangeFlight)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Flights::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Flights.data,
      qt_meta_data_Flights,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Flights::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Flights::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Flights.stringdata0))
        return static_cast<void*>(const_cast< Flights*>(this));
    return QWidget::qt_metacast(_clname);
}

int Flights::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Flights::sigUpdateFilterParams(const FlightSortFilterProxyModel::FilterParams & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Flights::sigChangeFlight(const QModelIndex & _t1, const Flight & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
