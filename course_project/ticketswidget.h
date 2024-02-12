#pragma once

#include <QWidget>
#include <QAbstractTableModel>
#include <QTableView>
#include "Models/ticketsortfilterproxymodel.h"


namespace Ui {
class TicketWidget;
}

class TicketWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicketWidget(QWidget *parent = 0);
    ~TicketWidget();
    void setModels(QAbstractTableModel *ticketModel,
                   QAbstractTableModel *passengerModel,
                   QAbstractTableModel *flightModel);

signals:
    void sigAddTicket(const QModelIndex& flightIndex,
                      const QModelIndex& passengerIndex);
    void sigUpdateFilterParams(const TicketSortFilterProxyModel::FilterParams &params);
private slots:
    void handleAddTicketButtonClicked();
    void handleDeleteTicketButtonClicked();
    void handleUpdateFilterParams();

private:
    void initLineEdit();
    QAbstractItemModel *createProxyModels(QAbstractItemModel* sourceModel);
    void initTableView(QTableView* tableView);

private:
    Ui::TicketWidget *ui;
};
