/****************************************************************************
** Meta object code from reading C++ file 'ticketscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Controllers/ticketscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ticketscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TicketsController_t {
    QByteArrayData data[17];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TicketsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TicketsController_t qt_meta_stringdata_TicketsController = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TicketsController"
QT_MOC_LITERAL(1, 18, 17), // "handleShowTickets"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "handleFlightParamsChanged"
QT_MOC_LITERAL(4, 63, 11), // "indexFlight"
QT_MOC_LITERAL(5, 75, 6), // "Flight"
QT_MOC_LITERAL(6, 82, 15), // "newFlightParams"
QT_MOC_LITERAL(7, 98, 21), // "handleRemovePassenger"
QT_MOC_LITERAL(8, 120, 5), // "index"
QT_MOC_LITERAL(9, 126, 15), // "handleAddTicket"
QT_MOC_LITERAL(10, 142, 11), // "flightIndex"
QT_MOC_LITERAL(11, 154, 14), // "passengerIndex"
QT_MOC_LITERAL(12, 169, 18), // "handleRemoveFlight"
QT_MOC_LITERAL(13, 188, 6), // "flight"
QT_MOC_LITERAL(14, 195, 18), // "handleRemoveTicket"
QT_MOC_LITERAL(15, 214, 6), // "Ticket"
QT_MOC_LITERAL(16, 221, 6) // "ticket"

    },
    "TicketsController\0handleShowTickets\0"
    "\0handleFlightParamsChanged\0indexFlight\0"
    "Flight\0newFlightParams\0handleRemovePassenger\0"
    "index\0handleAddTicket\0flightIndex\0"
    "passengerIndex\0handleRemoveFlight\0"
    "flight\0handleRemoveTicket\0Ticket\0"
    "ticket"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TicketsController[] = {

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
       3,    2,   45,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       9,    2,   53,    2, 0x08 /* Private */,
      12,    1,   58,    2, 0x08 /* Private */,
      14,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void TicketsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TicketsController *_t = static_cast<TicketsController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleShowTickets(); break;
        case 1: _t->handleFlightParamsChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const Flight(*)>(_a[2]))); break;
        case 2: _t->handleRemovePassenger((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->handleAddTicket((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->handleRemoveFlight((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->handleRemoveTicket((*reinterpret_cast< const Ticket(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TicketsController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TicketsController.data,
      qt_meta_data_TicketsController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TicketsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TicketsController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TicketsController.stringdata0))
        return static_cast<void*>(const_cast< TicketsController*>(this));
    return QObject::qt_metacast(_clname);
}

int TicketsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
