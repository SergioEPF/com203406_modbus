QT += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    modbuslib/modbusdevice.cpp \
    modbuslib/modbusrtumaster.cpp \
    modbuslib/modbuscrc.cpp

HEADERS += \
    mainwindow.h \
    modbuslib/modbusdevice.h \
    modbuslib/modbusrtumaster.h \
    modbuslib/modbuscrc.h

FORMS += \
    mainwindow.ui