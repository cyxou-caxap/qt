#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QDate>

struct Passenger
{
    Passenger() = default;

    QString name;
    QString passport;
    QDate birthday;
};

struct Flight
{
    Flight() = default;

    QString number;
    QString airline;
    QString arrival;
    QString departure;
    QDateTime date;
    int total_places;
    int free_places;
};

struct Ticket
{
    Ticket() = default;

    QString passport;
    QString flight;
    QString number;
};

#endif // STRUCTS_H
