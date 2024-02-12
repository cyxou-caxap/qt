#ifndef TICKETSORTFILTERPROXYMODEL_H
#define TICKETSORTFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

class TicketSortFilterProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    struct FilterParams
    {
        QString ticket;
        QString passport;
        QString flight;
        bool isFilterEnabled;
    };

   explicit  TicketSortFilterProxyModel(QObject *parent = nullptr) : QSortFilterProxyModel(parent) {}
    virtual ~TicketSortFilterProxyModel(){}
public slots:
    void handleUpdateFilterParams(const FilterParams &params);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    FilterParams _currentFilterParams;
};

#endif // TICKETSORTFILTERPROXYMODEL_H
