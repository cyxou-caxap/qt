#include <QSortFilterProxyModel>
#include "flights.h"
#include "ui_flights.h"
#include <QHeaderView>
#include <Models/modelflights.h>
#include <QDebug>

Flights::Flights(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flights)
{
    ui->setupUi(this);
    ui->pushButton_add->setEnabled(false);

    initLineEdit();

    connect(ui->pushButton_add, &QPushButton::clicked,
            this, &Flights::handleAddFlightButtonClicked);
    connect(ui->pushButton_change, &QPushButton::clicked,
            this, &Flights::handleChangeFlightButtonClicked);
    connect(ui->lineEdit_number, &QLineEdit::textChanged,
            this, &Flights::handleAddFlightButtonActivated);
    connect(ui->lineEdit_airline, &QLineEdit::textChanged,
            this, &Flights::handleAddFlightButtonActivated);
    connect(ui->lineEdit_arrival, &QLineEdit::textChanged,
            this, &Flights::handleAddFlightButtonActivated);
    connect(ui->lineEdit_departure, &QLineEdit::textChanged,
            this, &Flights::handleAddFlightButtonActivated);
    connect(ui->lineEdit_total_places, &QLineEdit::textChanged,
            this, &Flights::handleAddFlightButtonActivated);

    connect(ui->lineEdit_number, &QLineEdit::textChanged,
            this, &Flights::handleUpdateFilterParams);
    connect(ui->lineEdit_airline, &QLineEdit::textChanged,
            this, &Flights::handleUpdateFilterParams);
    connect(ui->lineEdit_arrival, &QLineEdit::textChanged,
            this, &Flights::handleUpdateFilterParams);
    connect(ui->lineEdit_departure, &QLineEdit::textChanged,
            this, &Flights::handleUpdateFilterParams);
    connect(ui->lineEdit_total_places, &QLineEdit::textChanged,
            this, &Flights::handleUpdateFilterParams);
    connect(ui->tableView, &QTableView::clicked,
            this, &Flights::handleCurrentSelectedIndexChanged);

    connect (ui->checkBox_search, &QCheckBox::clicked,
             this, [this](bool isChecked){
        ui->pushButton_add->setEnabled(!isChecked && handleAddFlightButtonActivated());
    });
    connect (ui->checkBox_search, &QCheckBox::clicked,
             this, &Flights::handleUpdateFilterParams);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->pushButton_delete, &QPushButton::clicked,
            this, &Flights::handleDeleteFlightButtonClicked);
}

void Flights::handleClearFilterParams()
{
    ui->lineEdit_number->clear();
    ui->lineEdit_airline->clear();
    ui->lineEdit_arrival->clear();
    ui->lineEdit_departure->clear();
    ui->lineEdit_total_places->clear();
    ui->dateTimeEdit->setDateTime(QDateTime(QDate(2001, 01, 01), QTime(00, 00, 00)));
}

void Flights::setFlightsModel(QAbstractTableModel *model)
{
    auto proxyModel = new FlightSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    connect(this, &Flights::sigUpdateFilterParams,
            proxyModel, &FlightSortFilterProxyModel::handleUpdateFilterParams);
    ui->tableView->setModel(proxyModel);
}

void Flights::handleAddFlightButtonClicked()
{
    auto proxyModel = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());
    auto model = dynamic_cast<ModelFlights*>(proxyModel->sourceModel());

    if (!model)
        return;

    auto flight = getFlightParams();
    model->addFlight(flight);

    handleClearFilterParams();
}

bool Flights::handleAddFlightButtonActivated()
{
    bool result = ui->lineEdit_airline->text() != "" &&
            ui->lineEdit_arrival->text() != ""&&
            ui->lineEdit_departure->text()!=""&&
            ui->lineEdit_total_places->text() != "";
    if (result)
        ui->pushButton_add->setEnabled(true);
    else
        ui->pushButton_add->setEnabled(false);

    return result;
}



void Flights::handleUpdateFilterParams()
{
    FlightSortFilterProxyModel::FilterParams params;
    params.number = ui->lineEdit_number->text();
    params.airline = ui->lineEdit_airline->text();
    params.arrival = ui->lineEdit_arrival->text();
    params.departure = ui->lineEdit_departure->text();
    params.total_places = ui->lineEdit_total_places->text();
    params.isFilterEnabled = ui->checkBox_search->isChecked();

    emit sigUpdateFilterParams(params);
}

Flights::~Flights()
{
    delete ui;
}

void Flights::initLineEdit()
{
    {
        QRegExp regExp("[а-яА-Яa-Az-Z"" ""-""]+");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_airline->setValidator(validator);
        ui->lineEdit_arrival->setValidator(validator);
        ui->lineEdit_departure->setValidator(validator);
    }

    {
        QRegExp regExp("[A-Z][A-Z][ ]\\d{4}");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_number->setValidator(validator);
    }

    {
        QRegExp regExp("(?!0*$)\\d{2}");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_total_places->setValidator(validator);
    }
}

Flight Flights::getFlightParams() const
{
    Flight flight;
    flight.number = ui->lineEdit_number->text();
    flight.airline = ui->lineEdit_airline->text();
    flight.arrival = ui->lineEdit_arrival->text();
    flight.departure = ui->lineEdit_departure->text();
    flight.date = ui->dateTimeEdit->dateTime();
    flight.total_places = ui->lineEdit_total_places->text().toInt();
    flight.free_places = flight.total_places;

    return flight;
}

void Flights::setFlightParams(const Flight &flight)
{
    ui->lineEdit_number->setText(flight.number);
    ui->lineEdit_airline->setText(flight.airline);
    ui->lineEdit_arrival->setText(flight.arrival);
    ui->lineEdit_departure->setText(flight.departure);
    ui->dateTimeEdit->setDateTime(flight.date);
    ui->lineEdit_total_places->setText(QString::number(flight.total_places));
}

void Flights::handleDeleteFlightButtonClicked()
{
    QItemSelectionModel *selectFlights = ui->tableView->selectionModel();
    auto selectedRowsFlights = selectFlights->selectedRows();

    if (selectedRowsFlights.size() != 1)
    {
        qDebug() << "Выберите 1 рейс для удаления";
        return;
    }

    auto proxyModelFli = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());
    auto model = dynamic_cast<ModelFlights*>(proxyModelFli->sourceModel());
    if (!model)
        return;

    model->removeFlight(proxyModelFli->mapToSource(selectedRowsFlights.first()));

    handleClearFilterParams();

}

void Flights::handleChangeFlightButtonClicked()
{
    QItemSelectionModel *selectFlights = ui->tableView->selectionModel();
    auto selectedRowsFlights = selectFlights->selectedRows();

    if (selectedRowsFlights.size() != 1)
    {
        qDebug() << "Выберите 1 рейс для редактирования";
        return;
    }

    auto proxyModelFli = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());
    emit sigChangeFlight(proxyModelFli->mapToSource(selectedRowsFlights.first()),
                         getFlightParams());
    handleClearFilterParams();
}

void Flights::handleCurrentSelectedIndexChanged()
{
    QItemSelectionModel *selectFlights = ui->tableView->selectionModel();
    auto selectedRowsFlights = selectFlights->selectedRows();

    if (selectedRowsFlights.size() != 1)
        return;

    auto proxyModelFlight = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());

    auto model = dynamic_cast<ModelFlights*>(proxyModelFlight->sourceModel());

    if (!model)
        return;

    setFlightParams(model->getFlight(proxyModelFlight->mapToSource(selectedRowsFlights.first())));
}
