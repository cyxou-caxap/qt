#include "ticketscontroller.h"

#include "Models/modelflights.h"
#include "Models/modelpassengers.h"
#include "Models/modeltickets.h"
#include "ticketswidget.h"
#include "structs.h"
#include <QDebug>

TicketsController::TicketsController(QWeakPointer<ModelPassengers> passengerModel,
                                     QWeakPointer<ModelTickets> ticketModel,
                                     QWeakPointer<ModelFlights> flightModel,
                                     QObject *parent)
    : QObject(parent),
      _passengerModel(passengerModel),
      _ticketModel(ticketModel),
      _flightModel(flightModel)

{
    if (auto fliModelStrongRef = _flightModel.toStrongRef())
        connect(fliModelStrongRef.data(), &ModelFlights::sigRemoveFlight,
                this, &TicketsController::handleRemoveFlight);
    if (auto ticModelStrongRef = _ticketModel.toStrongRef())
        connect(ticModelStrongRef.data(), &ModelTickets::sigRemoveTicket,
                this, &TicketsController::handleRemoveTicket);

    auto flightModRef = _flightModel.toStrongRef();
    auto ticModRef = _ticketModel.toStrongRef();
    {Ticket ticket;
    ticket.flight = "FI 1111";
    ticket.passport = "4370 111111";

    if (ticModRef->addTicket(ticket))
        flightModRef->addPassenger(ticket.flight);
    }
    {Ticket ticket;
    ticket.flight = "FI 1111";
    ticket.passport = "1111 123456";

    if (ticModRef->addTicket(ticket))
        flightModRef->addPassenger(ticket.flight);
    }
    {Ticket ticket;
    ticket.flight = "SE 2222";
    ticket.passport = "1523 333333";

    if (ticModRef->addTicket(ticket))
        flightModRef->addPassenger(ticket.flight);
    }
}

void TicketsController::handleShowTickets()
{
    auto pasModRef = _passengerModel.toStrongRef();
    auto ticModRef = _ticketModel.toStrongRef();
    auto flightModRef = _flightModel.toStrongRef();

    if (!pasModRef || !ticModRef || !flightModRef)
        return;

    auto ticketWdg = new TicketWidget();
    ticketWdg->setModels(ticModRef.data(),
                         pasModRef.data(),
                         flightModRef.data());
    connect(ticketWdg, &TicketWidget::sigAddTicket,
            this, &TicketsController::handleAddTicket);
    ticketWdg->setAttribute(Qt::WA_DeleteOnClose);
    ticketWdg->show();
    ticketWdg->raise();
    ticketWdg->activateWindow();
}

void TicketsController::handleFlightParamsChanged(const QModelIndex &indexFlight,
                                                  const Flight &newFlightParams)
{
    auto flModel = _flightModel.toStrongRef();
    auto ticModel = _ticketModel.toStrongRef();

    if (!flModel || !ticModel)
        return;

    auto oldFlightParams = flModel->getFlight(indexFlight);

    if (oldFlightParams.number != newFlightParams.number)
    {
        qDebug() << "Нельзя изменить номер авиарейса";
        return;
    }

    QString errorString;
    if (!ticModel->isChangedFlightParamsValid(newFlightParams, oldFlightParams, &errorString))
    {
        qDebug() << errorString;
        return;
    }
    flModel->changeFlight(indexFlight, newFlightParams);
}

void TicketsController::handleRemovePassenger(const QModelIndex &index)
{
    auto ticModRef = _ticketModel.toStrongRef();
    auto flightModRef = _flightModel.toStrongRef();
    auto pasModRef = _passengerModel.toStrongRef();

    if (!ticModRef || !flightModRef)
        return;

    auto passenger = pasModRef->getPassenger(index);

    if (ticModRef->doesPassengerHasTicket(passenger.passport))
    {
        qDebug() << "Нельзя удалить пассажира, "
                    "Он зарегистрирован на рейс";
        return;
    }

    pasModRef->removePassenger(index);
}

void TicketsController::handleAddTicket(const QModelIndex& flightIndex,
                                        const QModelIndex& passengerIndex)
{
    auto pasModRef = _passengerModel.toStrongRef();
    auto ticModRef = _ticketModel.toStrongRef();
    auto flightModRef = _flightModel.toStrongRef();

    if (!pasModRef || !ticModRef || !flightModRef)
        return;

    auto passenger = pasModRef->getPassenger(passengerIndex);
    auto flight = flightModRef->getFlight(flightIndex);

    if (flight.free_places == 0)
    {
        qDebug() << "Невозможно добавить пассажира на рейс, "
                    "нет свободных мест";
        return;
    }

    Ticket ticket;
    ticket.flight = flight.number;
    ticket.passport = passenger.passport;

    if (ticModRef->addTicket(ticket))
        flightModRef->addPassenger(flight.number);
}

void TicketsController::handleRemoveFlight(const QString &flight)
{
    auto ticModRef = _ticketModel.toStrongRef();

    if (!ticModRef)
        return;

    ticModRef->removeFlight(flight);
}

void TicketsController::handleRemoveTicket(const Ticket &ticket)
{
    auto flightModRef = _flightModel.toStrongRef();

    if (!flightModRef)
        return;

    QStringList flightList;
    flightList << ticket.flight;
    flightModRef->removePassengerFromFlight(flightList);
}
