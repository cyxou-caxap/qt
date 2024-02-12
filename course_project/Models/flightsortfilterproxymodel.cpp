#include "flightsortfilterproxymodel.h"
#include "modelflights.h"

void FlightSortFilterProxyModel::handleUpdateFilterParams(const FlightSortFilterProxyModel::FilterParams &params)
{
    _currentFilterParams = params;
    invalidateFilter();
}

bool FlightSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!sourceModel())
        return false;

    if (!_currentFilterParams.isFilterEnabled)
        return true;

    QModelIndex numberIndex = sourceModel()->index(sourceRow,
                                                   static_cast<int>(ModelFlights::ColumnIndex::Number),
                                                   sourceParent);
    QModelIndex airlineIndex = sourceModel()->index(sourceRow,
                                                    static_cast<int>(ModelFlights::ColumnIndex::Airline),
                                                    sourceParent);
    QModelIndex arrivalIndex = sourceModel()->index(sourceRow,
                                                    static_cast<int>(ModelFlights::ColumnIndex::Arrival),
                                                    sourceParent);
    QModelIndex departureIndex = sourceModel()->index(sourceRow,
                                                      static_cast<int>(ModelFlights::ColumnIndex::Departure),
                                                      sourceParent);

    bool numberChecked = sourceModel()->data(numberIndex).toString().contains(_currentFilterParams.number,
                                                                              Qt::CaseInsensitive);

    bool airlineChecked = sourceModel()->data(airlineIndex).toString().contains(_currentFilterParams.airline,
                                                                                Qt::CaseInsensitive);
    bool arrivalChecked = sourceModel()->data(arrivalIndex).toString().contains(_currentFilterParams.arrival,
                                                                                Qt::CaseInsensitive);
    bool departureChecked = sourceModel()->data(departureIndex).toString().contains(_currentFilterParams.departure,
                                                                                     Qt::CaseInsensitive);

    return numberChecked && airlineChecked && arrivalChecked && departureChecked;
}
