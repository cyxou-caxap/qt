#include "modelflights.h"
#include <QDebug>

ModelFlights::ModelFlights(QObject *parent) : QAbstractTableModel(parent)
{
    _flightMap.insert("FI 1111",{
                          "FI 1111",
                          "S7",
                          "LED",
                          "DME",
                          QDateTime(QDate(2024, 7, 23), QTime(8, 30, 0)),
                          3,
                          3
                      });
    _flightIndexes.append("FI 1111");
    _flightMap.insert("SE 2222",{
                          "SE 2222",
                          "Aeroflot",
                          "BQS",
                          "GRV",
                          QDateTime(QDate(2024, 9, 1), QTime(17, 45, 0)),
                          5,
                          5
                      });
    _flightIndexes.append("SE 2222");
    _flightMap.insert("LI 3333",{
                          "LI 3333",
                          "Pobeda",
                          "DYU",
                          "KVX",
                          QDateTime(QDate(2024, 11, 15), QTime(2, 10, 0)),
                          4,
                          4
                      });
    _flightIndexes.append("LI 3333");
}

int ModelFlights::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _flightIndexes.size();
}

int ModelFlights::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(ColumnIndex::count);
}

QVariant ModelFlights::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    if (role != Qt::DisplayRole)
        return {};

    auto flight = _flightMap.value(_flightIndexes.at(index.row()));

    switch (static_cast<ColumnIndex>(index.column()))
    {
    case ColumnIndex::Number: return flight.number;
    case ColumnIndex::Airline: return flight.airline;
    case ColumnIndex::Arrival: return flight.arrival;
    case ColumnIndex::Departure: return flight.departure;
    case ColumnIndex::Date: return flight.date;
    case ColumnIndex::Total_places: return flight.total_places;
    case ColumnIndex::Free_places: return flight.free_places;
    default:
        break;
    }

    return {};
}

QVariant ModelFlights::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return {};

    if (orientation == Qt::Orientation::Vertical)
        return section + 1;

    switch (static_cast<ColumnIndex>(section))
    {
    case ColumnIndex::Number: return QString("Номер авиарейса");
    case ColumnIndex::Airline: return QString("Авиакомпания");
    case ColumnIndex::Arrival: return QString("Аэропорт прибытия");
    case ColumnIndex::Departure: return QString("Аэропорт отправления");
    case ColumnIndex::Date: return QString("Дата и время");
    case ColumnIndex::Total_places: return QString("Всего мест");
    case ColumnIndex::Free_places: return QString("Свободных мест");
    default:
        return {};
    }
}

Qt::ItemFlags ModelFlights::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable;
}

void ModelFlights::addFlight(const Flight &flight)
{
    if (!isFlightParamsValid(flight))
        return;

    beginInsertRows({}, _flightIndexes.size(), _flightIndexes.size());
    _flightMap.insert(flight.number, flight);
    _flightIndexes.append(flight.number);
    endInsertRows();
}

void ModelFlights::removeFlight(const QModelIndex &index)
{
    if (!index.isValid())
        return;
    beginRemoveRows({}, index.row(), index.row());
    _flightMap.remove(_flightIndexes.at(index.row()));
    auto number = _flightIndexes.takeAt(index.row());
    endRemoveRows();

    emit sigRemoveFlight(number);
}

Flight ModelFlights::getFlight(const QModelIndex &index)
{
    return _flightMap.value(_flightIndexes.at(index.row()));
}

void ModelFlights::addPassenger(const QString &flightNumber)
{
    _flightMap[flightNumber].free_places--;
    emit dataChanged(createIndex(_flightIndexes.indexOf(flightNumber),
                                 static_cast<int>(ColumnIndex::Free_places)),
                     createIndex(_flightIndexes.indexOf(flightNumber),
                                 static_cast<int>(ColumnIndex::Free_places)));
}

void ModelFlights::removePassengerFromFlight(const QStringList &flightList)
{
    for (const auto &flight : flightList)
    {
        _flightMap[flight].free_places++;
        emit dataChanged(createIndex(_flightIndexes.indexOf(flight),
                                     static_cast<int>(ColumnIndex::Free_places)),
                         createIndex(_flightIndexes.indexOf(flight),
                                     static_cast<int>(ColumnIndex::Free_places)));
    }
}

void ModelFlights::changeFlight(const QModelIndex &index, Flight flight)
{
    if (_flightMap.contains(flight.number) &&
            _flightIndexes.at(index.row()) != flight.number)
    {
        qDebug() << QString("Авиакомпания %1 уже осуществляет данный перелёт %2 - %3 ,"
                            "авиарейсы должны быть уникальны").
                    arg(flight.airline, flight.departure,flight.arrival);
        return;
    }
    else if (flight.arrival == flight.departure)
    {
        qDebug() << QString("Аэропорты прибытия и отправления должны различаться");
        return;
    }
    else if (flight.date.secsTo(QDateTime::currentDateTime()) > 0)
    {
        qDebug() << QString("Время рейса не может быть в прошлом");
        return;
    }

    auto oldFlight = _flightMap.value(_flightIndexes.at(index.row()));
    flight.free_places = flight.total_places - (oldFlight.total_places
                                                - oldFlight.free_places);
    _flightMap.insert(_flightIndexes.at(index.row()), flight);
    emit dataChanged(createIndex(index.row(),
                                 static_cast<int>(ColumnIndex::Number)),
                     createIndex(index.row(),
                                 static_cast<int>(ColumnIndex::Free_places)));
}

bool ModelFlights::isFlightParamsValid(const Flight &flight)
{
    if (_flightMap.contains(flight.number))
    {
        qDebug() << QString("Авиакомпания %1 уже осуществляет данный перелёт %2 - %3,"
                            "авиарейсы должны быть уникальны").
                    arg(flight.airline, flight.departure,flight.arrival);
        return false;
    }
    else if (flight.arrival == flight.departure)
    {
        qDebug() << QString("Аэропорты прибытия и отправления долsжны различаться");
        return false;
    }
    else if (flight.date.secsTo(QDateTime::currentDateTime()) > 0)
    {
        qDebug() << QString("Время рейса не может быть в прошлом");
        return false;
    }

    return true;
}
