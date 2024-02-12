/********************************************************************************
** Form generated from reading UI file 'flights.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTS_H
#define UI_FLIGHTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Flights
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *pushButton_add;
    QLabel *label;
    QPushButton *pushButton_delete;
    QCheckBox *checkBox_search;
    QPushButton *pushButton_change;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lineEdit_number;
    QLineEdit *lineEdit_airline;
    QLineEdit *lineEdit_arrival;
    QLineEdit *lineEdit_departure;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_total_places;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Flights)
    {
        if (Flights->objectName().isEmpty())
            Flights->setObjectName(QStringLiteral("Flights"));
        Flights->resize(464, 318);
        gridLayout = new QGridLayout(Flights);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(Flights);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 7, 0, 1, 4);

        pushButton_add = new QPushButton(Flights);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 6, 0, 1, 1);

        label = new QLabel(Flights);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_delete = new QPushButton(Flights);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 6, 1, 1, 1);

        checkBox_search = new QCheckBox(Flights);
        checkBox_search->setObjectName(QStringLiteral("checkBox_search"));

        gridLayout->addWidget(checkBox_search, 6, 3, 1, 1);

        pushButton_change = new QPushButton(Flights);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));

        gridLayout->addWidget(pushButton_change, 6, 2, 1, 1);

        label_6 = new QLabel(Flights);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 2);

        label_2 = new QLabel(Flights);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        lineEdit_number = new QLineEdit(Flights);
        lineEdit_number->setObjectName(QStringLiteral("lineEdit_number"));

        gridLayout->addWidget(lineEdit_number, 0, 2, 1, 2);

        lineEdit_airline = new QLineEdit(Flights);
        lineEdit_airline->setObjectName(QStringLiteral("lineEdit_airline"));

        gridLayout->addWidget(lineEdit_airline, 1, 2, 1, 2);

        lineEdit_arrival = new QLineEdit(Flights);
        lineEdit_arrival->setObjectName(QStringLiteral("lineEdit_arrival"));

        gridLayout->addWidget(lineEdit_arrival, 2, 2, 1, 2);

        lineEdit_departure = new QLineEdit(Flights);
        lineEdit_departure->setObjectName(QStringLiteral("lineEdit_departure"));

        gridLayout->addWidget(lineEdit_departure, 3, 2, 1, 2);

        dateTimeEdit = new QDateTimeEdit(Flights);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 4, 2, 1, 2);

        lineEdit_total_places = new QLineEdit(Flights);
        lineEdit_total_places->setObjectName(QStringLiteral("lineEdit_total_places"));

        gridLayout->addWidget(lineEdit_total_places, 5, 2, 1, 2);

        label_5 = new QLabel(Flights);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        label_3 = new QLabel(Flights);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 2);

        label_4 = new QLabel(Flights);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 2);


        retranslateUi(Flights);

        QMetaObject::connectSlotsByName(Flights);
    } // setupUi

    void retranslateUi(QWidget *Flights)
    {
        Flights->setWindowTitle(QApplication::translate("Flights", "\320\220\320\262\320\270\320\260\321\200\320\265\320\271\321\201\321\213", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("Flights", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\320\262\320\270\320\260\321\200\320\265\320\271\321\201", Q_NULLPTR));
        label->setText(QApplication::translate("Flights", "\320\220\320\262\320\270\320\260\320\272\320\276\320\274\320\277\320\260\320\275\320\270\321\217", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("Flights", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\265\320\271\321\201", Q_NULLPTR));
        checkBox_search->setText(QApplication::translate("Flights", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        pushButton_change->setText(QApplication::translate("Flights", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\265\320\271\321\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("Flights", "\320\235\320\276\320\274\320\265\321\200 \320\260\320\262\320\270\320\260\321\200\320\265\320\271\321\201\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("Flights", "\320\220\321\215\321\200\320\276\320\277\320\276\321\200\321\202 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("Flights", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("Flights", "\320\220\321\215\321\200\320\276\320\277\320\276\321\200\321\202 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("Flights", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\201\321\202 \320\262\321\201\320\265\320\263\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Flights: public Ui_Flights {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTS_H
