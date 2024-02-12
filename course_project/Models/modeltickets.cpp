#include "modeltickets.h"
#include <QDebug>

ModelTickets::ModelTickets(QObject *parent) : QAbstractTableModel(parent)
{
}

int ModelTickets::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _ticketIndexes.size();
}

int ModelTickets::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(ColumnIndex::count);
}

QVariant ModelTickets::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return {};

    if (role != Qt::DisplayRole)
        return {};

    auto ticket = _ticketMap.value(_ticketIndexes.at(index.row()));

    switch (static_cast<ColumnIndex>(index.column()))
    {
    case ColumnIndex::Flight: return ticket.flight;
    case ColumnIndex::Passport: return ticket.passport;
    case ColumnIndex::TicketNumber: return ticket.number;
    default:
        break;
    }

    return {};
}

QVariant ModelTickets::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return {};

    if (orientation == Qt::Orientation::Vertical)
        return section + 1;

    switch (static_cast<ColumnIndex>(section))
    {
    case ColumnIndex::Flight: return QString("Номер авиарейса");
    case ColumnIndex::Passport: return QString("№ паспорта");
    case ColumnIndex::TicketNumber: return QString("Номер билета");
    default:
        return {};
    }
}

Qt::ItemFlags ModelTickets::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable;
}

QStringList ModelTickets::getFlightsByPassenger(const QString &passenger) const
{
    QStringList flightList;
    for (auto it = _flightPassengerMap.cbegin();
         it != _flightPassengerMap.cend();
         ++it)
        if (it.value() == passenger)
            flightList.append(it.key());

    return flightList;
}

bool ModelTickets::addTicket(const Ticket &ticket)
{
    if (_flightPassengerMap.contains(ticket.flight))
    {
        for(const auto &passport : _flightPassengerMap.values(ticket.flight))
        {
            if (ticket.passport == passport)
            {
                qDebug() << QString("Пассажир с паспортом %1, "
                                    "зарегистрирован на рейс %2").
                            arg(passport, ticket.flight);
                return false;
            }
        }
    }

    Ticket ticketModel = ticket;
    ticketModel.number = QString::number(number++);

    beginInsertRows({}, _ticketIndexes.size(), _ticketIndexes.size());
    _ticketMap.insert(ticketModel.number, ticketModel);
    _ticketIndexes.append(ticketModel.number);
    _flightPassengerMap.insert(ticket.flight, ticket.passport);
    endInsertRows();

    return true;
}

void ModelTickets::removeTicket(const QModelIndex &index)
{
    if (!index.isValid())
        return;
    beginRemoveRows({}, index.row(), index.row());
    auto ticket = _ticketMap.take(_ticketIndexes.at(index.row()));
    _ticketIndexes.remove(index.row());
    _flightPassengerMap.remove(ticket.flight, ticket.passport);
    endRemoveRows();

    emit sigRemoveTicket(ticket);
}

void ModelTickets::removePassenger(const QString &passenger)
{

    for (auto it = _ticketMap.begin();
         it != _ticketMap.end();
         ++it)
    {
        if (it.value().passport == passenger)
        {
            beginRemoveRows({},_ticketIndexes.indexOf(it.value().number),
                            _ticketIndexes.indexOf(it.value().number));
            _ticketIndexes.removeAt(_ticketIndexes.indexOf(it.value().number));
            _ticketMap.erase(it);
            auto iter =_flightPassengerMap.find(it.value().flight, it.value().passport);
            if (iter != _flightPassengerMap.end())
                _flightPassengerMap.erase(iter);
            endRemoveRows();
        }
    }
}

void ModelTickets::removeFlight(const QString &flight)
{
    for (auto it = _ticketMap.begin();
         it != _ticketMap.end();
         ++it)
    {
        if (it.value().flight == flight)
        {
            beginRemoveRows({},_ticketIndexes.indexOf(it.value().number),
                            _ticketIndexes.indexOf(it.value().number));
            _ticketIndexes.removeAt(_ticketIndexes.indexOf(it.value().number));
            _ticketMap.erase(it);
            endRemoveRows();
        }
    }
    _flightPassengerMap.remove(flight);
}

bool ModelTickets::isChangedFlightParamsValid(const Flight &newParams, const Flight &oldFlight, QString *error)
{
    if(_flightPassengerMap.values(oldFlight.number).size() >
            newParams.total_places)
    {
        if (error)
            *error = "Количество мест меньше проданных билетов";

        return false;
    }

    return true;
}

bool ModelTickets::doesPassengerHasTicket(const QString &passengerPassport)
{
    return _flightPassengerMap.values().contains(passengerPassport);
}
