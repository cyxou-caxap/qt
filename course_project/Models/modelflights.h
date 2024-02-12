#ifndef MODELFLIGHTS_H
#define MODELFLIGHTS_H

#include <QAbstractTableModel>
#include <QMap>
#include "structs.h"

class ModelFlights : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum class ColumnIndex : int
    {
        Unknown = -1,
        Number,
        Airline,
        Arrival,
        Departure,
        Date,
        Total_places,
        Free_places,

        count ///< must be last item
    };

    explicit ModelFlights(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addFlight(const Flight &flight);
    void removeFlight(const QModelIndex &index);
    Flight getFlight(const QModelIndex &index);
    void addPassenger(const QString &flightNumber);
    void removePassengerFromFlight(const QStringList &flightList);
    void changeFlight(const QModelIndex &index, Flight flight);

private:
    bool isFlightParamsValid(const Flight &flight);

signals:
    void sigRemoveFlight(const QString &number);

private:
    QVector<QString /*number*/> _flightIndexes;
    QMap<QString /*number*/, Flight> _flightMap;
};

#endif // MODELFLIGHTS_H
