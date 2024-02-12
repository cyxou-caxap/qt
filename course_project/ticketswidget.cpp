#include "ticketswidget.h"
#include "ui_tickets.h"
#include <QHeaderView>
#include <Models/modeltickets.h>
#include <QSortFilterProxyModel>
#include "Models/ticketsortfilterproxymodel.h"
#include <QTableView>
#include <QDebug>

TicketWidget::TicketWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicketWidget)
{
    ui->setupUi(this);

    initLineEdit();

    connect(ui->pushButton_sell, &QPushButton::clicked,
            this, &TicketWidget::handleAddTicketButtonClicked);
    connect(ui->pushButton_return, &QPushButton::clicked,
            this, &TicketWidget::handleDeleteTicketButtonClicked);

    connect(ui->lineEdit_ticket, &QLineEdit::textChanged,
            this, &TicketWidget::handleUpdateFilterParams);
    connect(ui->lineEdit_passport, &QLineEdit::textChanged,
            this, &TicketWidget::handleUpdateFilterParams);
    connect(ui->lineEdit_flight, &QLineEdit::textChanged,
            this, &TicketWidget::handleUpdateFilterParams);

    connect (ui->checkBox_search, &QCheckBox::clicked,
             this, &TicketWidget::handleUpdateFilterParams);

    initTableView(ui->tableView_flights);
    initTableView(ui->tableView_passengers);
    initTableView(ui->tableView_tickets);
}

void TicketWidget::handleAddTicketButtonClicked()
{
    QItemSelectionModel *selectFlight = ui->tableView_flights->selectionModel();
    auto selectedRowsFlight = selectFlight->selectedRows();

    QItemSelectionModel *selectPassengers = ui->tableView_passengers->selectionModel();
    auto selectedRowsPassengers = selectPassengers->selectedRows();

    if (selectedRowsFlight.size() != 1 || selectedRowsPassengers.size() != 1)
    {
        qDebug() << "Выберите 1 пассажира и 1 рейс";
        return;
    }

    auto proxyModelFlight = dynamic_cast<QSortFilterProxyModel*>(ui->tableView_flights->model());
    auto proxyModelPas = dynamic_cast<QSortFilterProxyModel*>(ui->tableView_passengers->model());

    emit sigAddTicket(proxyModelFlight->mapToSource(selectedRowsFlight.first()),
                      proxyModelPas->mapToSource(selectedRowsPassengers.first()));
}

void TicketWidget::handleDeleteTicketButtonClicked()
{
    QItemSelectionModel *selectTickets = ui->tableView_tickets->selectionModel();
    auto selectedRowsTickets = selectTickets->selectedRows();

    if (selectedRowsTickets.size() != 1)
    {
        qDebug() << "Выберите 1 билет для удаления";
        return;
    }

    auto proxyModelTic = dynamic_cast<QSortFilterProxyModel*>(ui->tableView_tickets->model());

    auto model = dynamic_cast<ModelTickets*>(proxyModelTic->sourceModel());

    if (!model)
        return;

    model->removeTicket(proxyModelTic->mapToSource(selectedRowsTickets.first()));
}

QAbstractItemModel *TicketWidget::createProxyModels(QAbstractItemModel *sourceModel)
{
    auto proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(sourceModel);
    return proxyModel;
}

void TicketWidget::initTableView(QTableView *tableView)
{
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setSortingEnabled(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void TicketWidget::handleUpdateFilterParams()
{
    TicketSortFilterProxyModel::FilterParams params;
    params.ticket = ui->lineEdit_ticket->text();
    params.passport = ui->lineEdit_passport->text();
    params.flight = ui->lineEdit_flight->text();
    params.isFilterEnabled = ui->checkBox_search->isChecked();

    emit sigUpdateFilterParams(params);
}

TicketWidget::~TicketWidget()
{
    delete ui;
}

void TicketWidget::initLineEdit()
{
    {
        QRegExp regExp("[0-9]+");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_ticket->setValidator(validator);
    }

    {
        QRegExp regExp("\\d{4}[ ]\\d{6}");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_passport->setValidator(validator);
    }
    {
        QRegExp regExp("[A-Z][A-Z][ ][0-9]+");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_flight->setValidator(validator);
    }
}

void TicketWidget::setModels(QAbstractTableModel *ticketModel,
                             QAbstractTableModel *passengerModel,
                             QAbstractTableModel *flightModel)
{
    ui->tableView_passengers->setModel(createProxyModels(passengerModel));
    ui->tableView_flights->setModel(createProxyModels(flightModel));


    auto ticketProxyModel = new TicketSortFilterProxyModel();
    ticketProxyModel->setSourceModel(ticketModel);
    ui->tableView_tickets->setModel(ticketProxyModel);
    connect(this, &TicketWidget::sigUpdateFilterParams,
            ticketProxyModel, &TicketSortFilterProxyModel::handleUpdateFilterParams);
}
