#ifndef PASSENGERS_H
#define PASSENGERS_H

#include <QWidget>
#include <QAbstractTableModel>
#include "Models/passengersortfilterproxymodel.h"
#include "structs.h"

namespace Ui {
class Passengers;
}

class Passengers : public QWidget
{
    Q_OBJECT
public:
    explicit Passengers(QWidget *parent = 0);

    void setPassengersModel(QAbstractTableModel *model);

    ~Passengers();
signals:
    void sigUpdateFilterParams(const PassengerSortFilterProxyModel::FilterParams &params);
    void sigRemovePassenger(const QModelIndex &passangerIndex);

private:
    void initLineEdit();
    void setPassengerParams(Passenger passenger);
    Passenger getPassengerParams() const;
private slots:
    void handleDeletePassengerButtonClicked();
    void handleAddPassengerButtonClicked();
    bool handleAddPassengerButtonActivated();
    void handleUpdateFilterParams();
    void handleClearFilterParams();
    void handleChangePassengerButtonClicked();
    void handleCurrentSelectedIndexChanged();

private:
    Ui::Passengers *ui;
};

#endif // PASSENGERS_H
