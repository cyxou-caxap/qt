#-------------------------------------------------
#
# Project created by QtCreator 2023-04-21T11:00:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = course_project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    passengers.cpp \
    flights.cpp \
    Models/modelpassengers.cpp \
    structs.cpp \
    Models/modelflights.cpp \
    Models/modeltickets.cpp \
    ticketswidget.cpp \
    Controllers/ticketscontroller.cpp \
    Models/passengersortfilterproxymodel.cpp \
    Models/flightsortfilterproxymodel.cpp \
    Models/ticketsortfilterproxymodel.cpp

HEADERS  += mainwindow.h \
    passengers.h \
    flights.h \
    Models/modelpassengers.h \
    structs.h \
    Models/modelflights.h \
    Models/modeltickets.h \
    ticketswidget.h \
    Controllers/ticketscontroller.h \
    Models/passengersortfilterproxymodel.h \
    Models/flightsortfilterproxymodel.h \
    Models/ticketsortfilterproxymodel.h

FORMS    += mainwindow.ui \
    passengers.ui \
    flights.ui \
    tickets.ui

RESOURCES += \
    res.qrc

DISTFILES +=
