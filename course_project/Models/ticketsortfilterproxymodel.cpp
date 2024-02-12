#include "ticketsortfilterproxymodel.h"
#include "modeltickets.h"

void TicketSortFilterProxyModel::handleUpdateFilterParams(const TicketSortFilterProxyModel::FilterParams &params)
{
    _currentFilterParams = params;
    invalidateFilter();
}

bool TicketSortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!sourceModel())
        return false;

    if (!_currentFilterParams.isFilterEnabled)
        return true;

    QModelIndex ticketIndex = sourceModel()->index(sourceRow,
                                                   static_cast<int>(ModelTickets::ColumnIndex::TicketNumber),
                                                   sourceParent);
    QModelIndex passportIndex = sourceModel()->index(sourceRow,
                                                     static_cast<int>(ModelTickets::ColumnIndex::Passport),
                                                     sourceParent);
    QModelIndex flightIndex = sourceModel()->index(sourceRow,
                                                   static_cast<int>(ModelTickets::ColumnIndex::Flight),
                                                   sourceParent);
    bool ticketChecked = sourceModel()->data(ticketIndex).toString().contains(_currentFilterParams.ticket,
                                                                              Qt::CaseInsensitive);

    bool passportChecked = sourceModel()->data(passportIndex).toString().contains(_currentFilterParams.passport,
                                                                                  Qt::CaseInsensitive);
    bool flightChecked = sourceModel()->data(flightIndex).toString().contains(_currentFilterParams.flight,
                                                                              Qt::CaseInsensitive);
    return ticketChecked && passportChecked && flightChecked;
}
