/********************************************************************************
** Form generated from reading UI file 'passengers.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERS_H
#define UI_PASSENGERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Passengers
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *pushButton_add;
    QLabel *label;
    QPushButton *pushButton_delete;
    QCheckBox *checkBox_search;
    QPushButton *pushButton_change;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLineEdit *lineEdit_number;
    QLabel *label_3;
    QDateEdit *dateEdit_date;

    void setupUi(QWidget *Passengers)
    {
        if (Passengers->objectName().isEmpty())
            Passengers->setObjectName(QStringLiteral("Passengers"));
        Passengers->resize(470, 231);
        gridLayout = new QGridLayout(Passengers);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(Passengers);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 4, 0, 1, 4);

        pushButton_add = new QPushButton(Passengers);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 3, 0, 1, 1);

        label = new QLabel(Passengers);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_delete = new QPushButton(Passengers);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 3, 1, 1, 1);

        checkBox_search = new QCheckBox(Passengers);
        checkBox_search->setObjectName(QStringLiteral("checkBox_search"));

        gridLayout->addWidget(checkBox_search, 3, 3, 1, 1);

        pushButton_change = new QPushButton(Passengers);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));

        gridLayout->addWidget(pushButton_change, 3, 2, 1, 1);

        lineEdit_name = new QLineEdit(Passengers);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 2, 1, 2);

        label_2 = new QLabel(Passengers);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        lineEdit_number = new QLineEdit(Passengers);
        lineEdit_number->setObjectName(QStringLiteral("lineEdit_number"));

        gridLayout->addWidget(lineEdit_number, 1, 2, 1, 2);

        label_3 = new QLabel(Passengers);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        dateEdit_date = new QDateEdit(Passengers);
        dateEdit_date->setObjectName(QStringLiteral("dateEdit_date"));

        gridLayout->addWidget(dateEdit_date, 2, 2, 1, 2);


        retranslateUi(Passengers);

        QMetaObject::connectSlotsByName(Passengers);
    } // setupUi

    void retranslateUi(QWidget *Passengers)
    {
        Passengers->setWindowTitle(QApplication::translate("Passengers", "\320\237\320\260\321\201\321\201\320\260\320\266\320\270\321\200\321\213", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("Passengers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\320\260", Q_NULLPTR));
        label->setText(QApplication::translate("Passengers", "\320\244\320\230\320\236", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("Passengers", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\320\260", Q_NULLPTR));
        checkBox_search->setText(QApplication::translate("Passengers", "\320\236\321\202\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        pushButton_change->setText(QApplication::translate("Passengers", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\201\321\201\320\260\320\266\320\270\321\200\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("Passengers", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("Passengers", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Passengers: public Ui_Passengers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERS_H
