#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T19:20:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBExplorer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    databasemodel.cpp \
    zcompression.cpp \
    inspectiondialog.cpp \
    crccalculator.cpp \
    idlparser.cpp

HEADERS  += mainwindow.h \
    database.h \
    databasemodel.h \
    zcompression.h \
    inspectiondialog.h \
    crccalculator.h \
    idlparser.h

FORMS    += mainwindow.ui \
    inspectiondialog.ui

unix|win32: LIBS += -ldb_cxx -lz
