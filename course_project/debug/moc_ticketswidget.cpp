/****************************************************************************
** Meta object code from reading C++ file 'ticketswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ticketswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ticketswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TicketWidget_t {
    QByteArrayData data[11];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TicketWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TicketWidget_t qt_meta_stringdata_TicketWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TicketWidget"
QT_MOC_LITERAL(1, 13, 12), // "sigAddTicket"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "flightIndex"
QT_MOC_LITERAL(4, 39, 14), // "passengerIndex"
QT_MOC_LITERAL(5, 54, 21), // "sigUpdateFilterParams"
QT_MOC_LITERAL(6, 76, 40), // "TicketSortFilterProxyModel::F..."
QT_MOC_LITERAL(7, 117, 6), // "params"
QT_MOC_LITERAL(8, 124, 28), // "handleAddTicketButtonClicked"
QT_MOC_LITERAL(9, 153, 31), // "handleDeleteTicketButtonClicked"
QT_MOC_LITERAL(10, 185, 24) // "handleUpdateFilterParams"

    },
    "TicketWidget\0sigAddTicket\0\0flightIndex\0"
    "passengerIndex\0sigUpdateFilterParams\0"
    "TicketSortFilterProxyModel::FilterParams\0"
    "params\0handleAddTicketButtonClicked\0"
    "handleDeleteTicketButtonClicked\0"
    "handleUpdateFilterParams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TicketWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   47,    2, 0x08 /* Private */,
       9,    0,   48,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TicketWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TicketWidget *_t = static_cast<TicketWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigAddTicket((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->sigUpdateFilterParams((*reinterpret_cast< const TicketSortFilterProxyModel::FilterParams(*)>(_a[1]))); break;
        case 2: _t->handleAddTicketButtonClicked(); break;
        case 3: _t->handleDeleteTicketButtonClicked(); break;
        case 4: _t->handleUpdateFilterParams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TicketWidget::*_t)(const QModelIndex & , const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TicketWidget::sigAddTicket)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TicketWidget::*_t)(const TicketSortFilterProxyModel::FilterParams & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TicketWidget::sigUpdateFilterParams)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TicketWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TicketWidget.data,
      qt_meta_data_TicketWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TicketWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TicketWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TicketWidget.stringdata0))
        return static_cast<void*>(const_cast< TicketWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TicketWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TicketWidget::sigAddTicket(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TicketWidget::sigUpdateFilterParams(const TicketSortFilterProxyModel::FilterParams & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
