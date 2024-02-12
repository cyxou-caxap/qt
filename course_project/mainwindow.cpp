#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "passengers.h"
#include "flights.h"
#include "Models/modelpassengers.h"
#include "Models/modelflights.h"
#include "Models/modeltickets.h"
#include "Controllers/ticketscontroller.h"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _modelPassenger = QSharedPointer<ModelPassengers>::create();
    _modelFlight = QSharedPointer<ModelFlights>::create();
    _modelTicket = QSharedPointer<ModelTickets>::create();

    _ticController = QSharedPointer<TicketsController>::create(_modelPassenger.toWeakRef(),
                                                               _modelTicket.toWeakRef(),
                                                               _modelFlight.toWeakRef());
    connect(ui->pushButton_passenger, &QPushButton::clicked,
            this, &MainWindow::handlePassengerButtonClicked);
    connect(ui->pushButton_flight, &QPushButton::clicked,
            this, &MainWindow::handleFlightButtonClicked);
    connect(ui->pushButton_ticket, &QPushButton::clicked,
            _ticController.data(), &TicketsController::handleShowTickets);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlePassengerButtonClicked()
{
    auto passengerWdg = new Passengers();

    connect(passengerWdg, &Passengers::sigRemovePassenger,
            _ticController.data(), &TicketsController::handleRemovePassenger);
    passengerWdg->setPassengersModel(_modelPassenger.data());
    passengerWdg->setAttribute(Qt::WA_DeleteOnClose);
    passengerWdg->show();
    passengerWdg->raise();
    passengerWdg->activateWindow();
}

void MainWindow::handleFlightButtonClicked()
{
    auto flightWdg = new Flights();
    connect(flightWdg, &Flights::sigChangeFlight,
            _ticController.data(), &TicketsController::handleFlightParamsChanged);

    flightWdg->setFlightsModel(_modelFlight.data());
    flightWdg->setAttribute(Qt::WA_DeleteOnClose);
    flightWdg->show();
    flightWdg->raise();
    flightWdg->activateWindow();
}
