/********************************************************************************
** Form generated from reading UI file 'tickets.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETS_H
#define UI_TICKETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_flight;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_ticket;
    QLineEdit *lineEdit_passport;
    QPushButton *pushButton_sell;
    QPushButton *pushButton_return;
    QCheckBox *checkBox_search;
    QTableView *tableView_tickets;
    QTableView *tableView_passengers;
    QTableView *tableView_flights;

    void setupUi(QWidget *TicketWidget)
    {
        if (TicketWidget->objectName().isEmpty())
            TicketWidget->setObjectName(QStringLiteral("TicketWidget"));
        TicketWidget->resize(835, 315);
        gridLayout = new QGridLayout(TicketWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_flight = new QLineEdit(TicketWidget);
        lineEdit_flight->setObjectName(QStringLiteral("lineEdit_flight"));

        gridLayout->addWidget(lineEdit_flight, 6, 3, 1, 1);

        label_2 = new QLabel(TicketWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 2, 1, 1);

        label = new QLabel(TicketWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 2, 1, 1);

        label_3 = new QLabel(TicketWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 2, 1, 1);

        lineEdit_ticket = new QLineEdit(TicketWidget);
        lineEdit_ticket->setObjectName(QStringLiteral("lineEdit_ticket"));

        gridLayout->addWidget(lineEdit_ticket, 4, 3, 1, 1);

        lineEdit_passport = new QLineEdit(TicketWidget);
        lineEdit_passport->setObjectName(QStringLiteral("lineEdit_passport"));

        gridLayout->addWidget(lineEdit_passport, 5, 3, 1, 1);

        pushButton_sell = new QPushButton(TicketWidget);
        pushButton_sell->setObjectName(QStringLiteral("pushButton_sell"));

        gridLayout->addWidget(pushButton_sell, 0, 2, 1, 1);

        pushButton_return = new QPushButton(TicketWidget);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));

        gridLayout->addWidget(pushButton_return, 1, 2, 1, 1);

        checkBox_search = new QCheckBox(TicketWidget);
        checkBox_search->setObjectName(QStringLiteral("checkBox_search"));

        gridLayout->addWidget(checkBox_search, 7, 3, 1, 1);

        tableView_tickets = new QTableView(TicketWidget);
        tableView_tickets->setObjectName(QStringLiteral("tableView_tickets"));

        gridLayout->addWidget(tableView_tickets, 0, 3, 4, 1);

        tableView_passengers = new QTableView(TicketWidget);
        tableView_passengers->setObjectName(QStringLiteral("tableView_passengers"));

        gridLayout->addWidget(tableView_passengers, 0, 0, 3, 1);

        tableView_flights = new QTableView(TicketWidget);
        tableView_flights->setObjectName(QStringLiteral("tableView_flights"));

        gridLayout->addWidget(tableView_flights, 3, 0, 5, 1);


        retranslateUi(TicketWidget);

        QMetaObject::connectSlotsByName(TicketWidget);
    } // setupUi

    void retranslateUi(QWidget *TicketWidget)
    {
        TicketWidget->setWindowTitle(QApplication::translate("TicketWidget", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260/\320\262\320\276\320\267\320\262\321\200\320\260\321\202 \320\261\320\270\320\273\320\265\321\202\320\276\320\262", Q_NULLPTR));
        label_2->setText(QApplication::translate("TicketWidget", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", Q_NULLPTR));
        label->setText(QApplication::translate("TicketWidget", "\320\235\320\276\320\274\320\265\321\200 \320\261\320\270\320\273\320\265\321\202\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("TicketWidget", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\262\320\270\320\260\321\200\320\265\320\271\321\201\320\260", Q_NULLPTR));
        pushButton_sell->setText(QApplication::translate("TicketWidget", "\320\237\321\200\320\276\320\264\320\260\321\202\321\214 \320\261\320\270\320\273\320\265\321\202", Q_NULLPTR));
        pushButton_return->setText(QApplication::translate("TicketWidget", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214 \320\261\320\270\320\273\320\265\321\202", Q_NULLPTR));
        checkBox_search->setText(QApplication::translate("TicketWidget", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TicketWidget: public Ui_TicketWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETS_H
