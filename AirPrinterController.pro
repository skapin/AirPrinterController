#-------------------------------------------------
#
# Project created by QtCreator 2013-05-13T15:16:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirPrinterController

CONFIG += qwt


unix {
    INCLUDEPATH += /usr/local/qwt-6.0.3-svn/include
}
win32 {
    INCLUDEPATH += E:/qwt-6.0/src
}
LIBS += -L/usr/local/qwt-6.0.3-svn/lib -lqwt

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphtemp.cpp \
    uart.cpp \
    tempcontroller.cpp

HEADERS  += mainwindow.h \
    graphtemp.h \
    uart.h \
    tempcontroller.h

FORMS    += mainwindow.ui
