#include "passengers.h"
#include "ui_passengers.h"
#include <QHeaderView>
#include <Models/modelpassengers.h>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QValidator>
#include <QSortFilterProxyModel>
#include <QDebug>

Passengers::Passengers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Passengers)
{
    ui->setupUi(this);
    ui->pushButton_add->setEnabled(false);

    initLineEdit();

    connect(ui->lineEdit_name, &QLineEdit::textChanged,
            this, &Passengers::handleAddPassengerButtonActivated);
    connect(ui->lineEdit_number, &QLineEdit::textChanged,
            this, &Passengers::handleAddPassengerButtonActivated);
    connect(ui->lineEdit_name, &QLineEdit::textChanged,
            this, &Passengers::handleUpdateFilterParams);
    connect(ui->lineEdit_number, &QLineEdit::textChanged,
            this, &Passengers::handleUpdateFilterParams);
    connect(ui->pushButton_add, &QPushButton::clicked,
            this, &Passengers::handleAddPassengerButtonClicked);
    connect(ui->pushButton_change, &QPushButton::clicked,
            this, &Passengers::handleChangePassengerButtonClicked);
    connect(ui->tableView, &QTableView::clicked,
            this, &Passengers::handleCurrentSelectedIndexChanged);

    connect (ui->checkBox_search, &QCheckBox::clicked,
             this, [this](bool isChecked){
        ui->pushButton_add->setEnabled(!isChecked && handleAddPassengerButtonActivated());
    });
    connect (ui->checkBox_search, &QCheckBox::clicked,
             this, &Passengers::handleUpdateFilterParams);

    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->pushButton_delete, &QPushButton::clicked,
            this, &Passengers::handleDeletePassengerButtonClicked);
}

void Passengers::handleClearFilterParams()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_number->clear();
    ui->dateEdit_date->setDate(QDate(2001, 01, 01));
}
void Passengers::setPassengersModel(QAbstractTableModel *model)
{
    auto proxyModel = new PassengerSortFilterProxyModel();
    proxyModel->setSourceModel(model);
    connect(this, &Passengers::sigUpdateFilterParams,
            proxyModel, &PassengerSortFilterProxyModel::handleUpdateFilterParams);
    ui->tableView->setModel(proxyModel);
}

void Passengers::handleAddPassengerButtonClicked()
{
    auto proxyModel = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());
    auto model = dynamic_cast<ModelPassengers*>(proxyModel->sourceModel());

    if (!model)
        return;

    auto passenger = getPassengerParams();

    if (passenger.birthday.daysTo(QDate(1890,01,01)) > 0 ||
            passenger.birthday.daysTo(QDate(2023,11,22)) < 0)
    {
        qDebug() << "Error: Дата рождения не принадлежит отрезку "
                    "от 01.01.1890 до 20.11.2023";
        return;
    }

    model->addPassenger(passenger);

    handleClearFilterParams();
}

bool Passengers::handleAddPassengerButtonActivated()
{
    bool result = ui->lineEdit_name->text() != "" &&
                ui->lineEdit_number->text().length() == 11;
    if (result)
        ui->pushButton_add->setEnabled(true);
    else
        ui->pushButton_add->setEnabled(false);

    return result;
}

void Passengers::handleUpdateFilterParams()
{
    PassengerSortFilterProxyModel::FilterParams params;
    params.name = ui->lineEdit_name->text();
    params.passport = ui->lineEdit_number->text();
    params.isFilterEnabled = ui->checkBox_search->isChecked();

    emit sigUpdateFilterParams(params);
}



Passengers::~Passengers()
{
    delete ui;
}

void Passengers::initLineEdit()
{
    {
        QRegExp regExp("[а-яА-Яa-Az-Z"" ""-""]+");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_name->setValidator(validator);
    }

    {
        QRegExp regExp("\\d{4}[ ]\\d{6}");
        QRegExpValidator *validator = new QRegExpValidator(regExp, this);
        ui->lineEdit_number->setValidator(validator);
    }
}

void Passengers::setPassengerParams(Passenger passenger)
{
    ui->lineEdit_name->setText(passenger.name);
    ui->lineEdit_number->setText(passenger.passport);
    ui->dateEdit_date->setDate(passenger.birthday);
}

Passenger Passengers::getPassengerParams() const
{
    Passenger passenger;
    passenger.birthday = ui->dateEdit_date->date();
    passenger.name = ui->lineEdit_name->text();
    passenger.passport = ui->lineEdit_number->text();
    return passenger;
}

void Passengers::handleDeletePassengerButtonClicked()
{
    QItemSelectionModel *selectPassengers = ui->tableView->selectionModel();
    auto selectedRowsPassengers = selectPassengers->selectedRows();

    if (selectedRowsPassengers.size() != 1)
    {
        qDebug() << "Выберите 1 пассажира для удаления";
        return;
    }

    auto proxyModelPas = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());

    auto model = dynamic_cast<ModelPassengers*>(proxyModelPas->sourceModel());

    if (!model)
        return;

    emit sigRemovePassenger(proxyModelPas->mapToSource(selectedRowsPassengers.first()));
    handleClearFilterParams();
}

void Passengers::handleChangePassengerButtonClicked()
{
    QItemSelectionModel *selectPassengers = ui->tableView->selectionModel();
    auto selectedRowsPassengers = selectPassengers->selectedRows();

    if (selectedRowsPassengers.size() != 1)
    {
        qDebug() << "Выберите 1 пассажира для редактирования";
        return;
    }

    auto proxyModel = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());
    auto model = dynamic_cast<ModelPassengers*>(proxyModel->sourceModel());

    if (!model)
        return;

    auto passenger = getPassengerParams();

    model->changePassenger(selectedRowsPassengers.first(), passenger);
    handleClearFilterParams();
}

void Passengers::handleCurrentSelectedIndexChanged()
{
    QItemSelectionModel *selectFlights = ui->tableView->selectionModel();
    auto selectedRows = selectFlights->selectedRows();

    if (selectedRows.size() != 1)
        return;

    auto proxyModelPassenger = dynamic_cast<QSortFilterProxyModel*>(ui->tableView->model());

    auto model = dynamic_cast<ModelPassengers*>(proxyModelPassenger->sourceModel());
    if (!model)
        return;

    setPassengerParams(model->getPassenger(proxyModelPassenger->mapToSource(selectedRows.first())));
}
