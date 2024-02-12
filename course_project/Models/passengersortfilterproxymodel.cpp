#include "passengersortfilterproxymodel.h"
#include "modelpassengers.h"

PassengerSortFilterProxyModel::PassengerSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{

}

void PassengerSortFilterProxyModel::handleUpdateFilterParams(const PassengerSortFilterProxyModel::FilterParams &params)
{
    _currentFilterParams = params;
    invalidateFilter();
}

bool PassengerSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!sourceModel())
        return false;

    if (!_currentFilterParams.isFilterEnabled)
        return true;

    QModelIndex nameIndex = sourceModel()->index(sourceRow,
                                                 static_cast<int>(ModelPassengers::ColumnIndex::Name),
                                                 sourceParent);
    QModelIndex passportIndex = sourceModel()->index(sourceRow,
                                                     static_cast<int>(ModelPassengers::ColumnIndex::Passport),
                                                     sourceParent);

    bool nameChecked = sourceModel()->data(nameIndex).toString().contains(_currentFilterParams.name,
                                                                          Qt::CaseInsensitive);

    bool passportChecked = sourceModel()->data(passportIndex).toString().contains(_currentFilterParams.passport,
                                                                                  Qt::CaseInsensitive);

    return nameChecked && passportChecked;
}
