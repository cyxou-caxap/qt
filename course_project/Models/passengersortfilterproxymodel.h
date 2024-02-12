#ifndef PASSENGERSORTFILTERPROXYMODEL_H
#define PASSENGERSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class PassengerSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    struct FilterParams
    {
        QString name;
        QString passport;
        bool isFilterEnabled;
    };

    explicit PassengerSortFilterProxyModel(QObject *parent = nullptr);

public slots:
    void handleUpdateFilterParams(const FilterParams &params);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    FilterParams _currentFilterParams;
};

#endif // PASSENGERSORTFILTERPROXYMODEL_H
