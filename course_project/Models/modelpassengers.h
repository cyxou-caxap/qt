#ifndef MODELPASSENGERS_H
#define MODELPASSENGERS_H

#include <QAbstractTableModel>
#include <QMap>
#include "structs.h"

class ModelPassengers : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum class ColumnIndex : int
    {
        Unknown = -1,
        Name,
        Passport,
        BirthDay,

        count ///< must be last item
    };

    explicit ModelPassengers(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void addPassenger(const Passenger &passenger);
    void removePassenger(const QModelIndex &index);
    Passenger getPassenger(const QModelIndex &index);
    void changePassenger(const QModelIndex &index, const Passenger &passenger);

signals:
    void sigRemovePassenger(const QString &passport);

private:
    QVector<QString /*passport*/> _passengerIndexes;
    QMap<QString, Passenger> _passengerMap;
};

#endif // MODELPASSENGERS_H
