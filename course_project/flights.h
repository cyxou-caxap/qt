#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <QWidget>
#include <QAbstractTableModel>
#include "Models/flightsortfilterproxymodel.h"
#include "structs.h"

namespace Ui {
class Flights;
}

class Flights : public QWidget
{
    Q_OBJECT
public:
    explicit Flights(QWidget *parent = 0);

    void setFlightsModel(QAbstractTableModel *model);

    ~Flights();
signals:
    void sigUpdateFilterParams(const FlightSortFilterProxyModel::FilterParams &params);
    void sigChangeFlight(const QModelIndex &flightIndex, const Flight &newFlightParams);

private:
    void initLineEdit();
    Flight getFlightParams() const;
    void setFlightParams(const Flight &flight);

private slots:
    void handleClearFilterParams();
    void handleDeleteFlightButtonClicked();
    void handleAddFlightButtonClicked();
    bool handleAddFlightButtonActivated();
    void handleUpdateFilterParams();
    void handleChangeFlightButtonClicked();
    void handleCurrentSelectedIndexChanged();

private:
    Ui::Flights *ui;
};

#endif // FLIGHTS_H
