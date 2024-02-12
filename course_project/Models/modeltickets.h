#pragma once

#include <QAbstractTableModel>
#include <QMap>
#include "structs.h"

class ModelTickets : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum class ColumnIndex : int
    {
        Unknown = -1,
        TicketNumber,
        Passport,
        Flight,

        count ///< must be last item
    };

    explicit ModelTickets(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QStringList getFlightsByPassenger(const QString &passenger) const;
    bool addTicket(const Ticket &ticket);
    void removeTicket(const QModelIndex &index);
    void removePassenger(const QString &passenger);
    void removeFlight(const QString &flight);
    bool isChangedFlightParamsValid(const Flight &newParams,
                                    const Flight &oldFlight,
                                    QString *error = nullptr);
    bool doesPassengerHasTicket(const QString &passengerPassport);

signals:
    void sigRemoveTicket(const Ticket &ticket);

private:
    QVector<QString /*ticket*/> _ticketIndexes;
    QMap<QString /*ticket*/, Ticket> _ticketMap;
    QMultiMap<QString /*flight*/, QString /*passenger*/> _flightPassengerMap;
    int number = 1;
};
