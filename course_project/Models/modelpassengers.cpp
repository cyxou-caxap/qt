#include "modelpassengers.h"
#include <QDebug>

ModelPassengers::ModelPassengers(QObject *parent) : QAbstractTableModel(parent)
{
    _passengerMap.insert("4370 111111",{
                             "Ivanov Ivan Ivanovich",
                             "4370 111111",
                             QDate (2000,12,01)
                         });
    _passengerIndexes.append("4370 111111");

    _passengerMap.insert("1111 123456",{
                             "Petrov Petr Petrovich",
                             "1111 123456",
                             QDate (1980,8,16)
                         });
    _passengerIndexes.append("1111 123456");

    _passengerMap.insert("1523 333333",{
                             "Smirnov Kirill Antonovich",
                             "1523 333333",
                             QDate (1992,9,07)
                         });
    _passengerIndexes.append("1523 333333");
}

int ModelPassengers::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _passengerIndexes.size();
}

int ModelPassengers::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(ColumnIndex::count);
}

QVariant ModelPassengers::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    if (role != Qt::DisplayRole)
        return {};

    auto passenger = _passengerMap.value(_passengerIndexes.at(index.row()));

    switch (static_cast<ColumnIndex>(index.column()))
    {
    case ColumnIndex::Name: return passenger.name;
    case ColumnIndex::Passport: return passenger.passport;
    case ColumnIndex::BirthDay: return passenger.birthday;
    default:
        break;
    }

    return {};
}

QVariant ModelPassengers::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return {};

    if (orientation == Qt::Orientation::Vertical)
        return section + 1;

    switch (static_cast<ColumnIndex>(section))
    {
    case ColumnIndex::Name: return QString("ФИО");
    case ColumnIndex::Passport: return QString("№ паспорта");
    case ColumnIndex::BirthDay: return QString("Дата рождения");
    default:
        return {};
    }
}

Qt::ItemFlags ModelPassengers::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable;
}

void ModelPassengers::addPassenger(const Passenger &passenger)
{
    if (_passengerMap.contains(passenger.passport))
    {
        qDebug() << QString("Пассажир %1 с паспортом %2 присутствует, "
                            "номер паспорта должен быть уникален").
                    arg(passenger.name, passenger.passport);
        return;
    }

    beginInsertRows({}, _passengerIndexes.size(), _passengerIndexes.size());
    _passengerMap.insert(passenger.passport, passenger);
    _passengerIndexes.append(passenger.passport);
    endInsertRows();
}

void ModelPassengers::removePassenger(const QModelIndex &index)
{
    if (!index.isValid())
        return;
    beginRemoveRows({}, index.row(), index.row());
    _passengerMap.remove(_passengerIndexes.at(index.row()));
    _passengerIndexes.remove(index.row());
    endRemoveRows();
}

Passenger ModelPassengers::getPassenger(const QModelIndex &index)
{
    return _passengerMap.value(_passengerIndexes.at(index.row()));
}

void ModelPassengers::changePassenger(const QModelIndex &index, const Passenger &passenger)
{
    if (_passengerIndexes.at(index.row()) != passenger.passport)
    {
        qDebug() << QString("Паспорт пассажира изменить нельзя");
        return;
    }

    _passengerMap.insert(passenger.passport, passenger);
    emit dataChanged(createIndex(_passengerIndexes.indexOf(passenger.passport),
                                 static_cast<int>(ColumnIndex::Unknown) + 1),
                     createIndex(_passengerIndexes.indexOf(passenger.passport),
                                 static_cast<int>(ColumnIndex::count) - 1));
}
