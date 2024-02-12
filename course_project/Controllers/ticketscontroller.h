#pragma once

#include <QObject>
#include <QWeakPointer>
#include "structs.h"

class ModelFlights;
class ModelPassengers;
class ModelTickets;

class TicketsController : public QObject
{
    Q_OBJECT
public:
    explicit TicketsController(QWeakPointer<ModelPassengers> passengerModel,
                               QWeakPointer<ModelTickets> ticketModel,
                               QWeakPointer<ModelFlights> flightModel,
                               QObject *parent = nullptr);
public slots:
    void handleShowTickets();
    void handleFlightParamsChanged(const QModelIndex &indexFlight,
                                   const Flight &newFlightParams);
    void handleRemovePassenger(const QModelIndex &index);

private slots:
    void handleAddTicket(const QModelIndex &flightIndex,
                         const QModelIndex &passengerIndex);
    void handleRemoveFlight(const QString &flight);
    void handleRemoveTicket(const Ticket &ticket);

private:
    QWeakPointer<ModelPassengers> _passengerModel;
    QWeakPointer<ModelTickets> _ticketModel;
    QWeakPointer<ModelFlights> _flightModel;
};
