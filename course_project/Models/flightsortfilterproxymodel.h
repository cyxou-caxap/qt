#ifndef FLIGHTSORTFILTERPROXYMODEL_H
#define FLIGHTSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class FlightSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    struct FilterParams
    {
        QString number;
        QString airline;
        QString arrival;
        QString departure;
        QString total_places;
        bool isFilterEnabled;
    };

    FlightSortFilterProxyModel(QObject *parent = nullptr): QSortFilterProxyModel(parent){}

public slots:
    void handleUpdateFilterParams(const FilterParams &params);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    FilterParams _currentFilterParams;
};

#endif // FLIGHTSORTFILTERPROXYMODEL_H
