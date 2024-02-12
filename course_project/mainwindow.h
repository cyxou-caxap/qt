#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>

class ModelPassengers;
class ModelFlights;
class ModelTickets;
class TicketsController;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handlePassengerButtonClicked();
    void handleFlightButtonClicked();

private:
    Ui::MainWindow *ui;
    QSharedPointer<ModelPassengers> _modelPassenger;
    QSharedPointer<ModelFlights> _modelFlight;
    QSharedPointer<ModelTickets> _modelTicket;

    QSharedPointer<TicketsController> _ticController;
};

#endif // MAINWINDOW_H
