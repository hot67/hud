#-------------------------------------------------
#
# Project created by QtCreator 2015-04-18T18:33:08
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HUD
TEMPLATE = app


SOURCES += main.cpp\
        hotdashboard.cpp \
        robotviewer.cpp \
        robotnetwork.cpp

HEADERS  += hotdashboard.h\
         robotviewer.h \
         robotnetwork.h

FORMS    += hotdashboard.ui
