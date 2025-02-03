TEMPLATE = app
TARGET = Installer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

SOURCES += \
    filedownloader.cpp \
    main.cpp \
    window.cpp

HEADERS += \
    filedownloader.h \
    window.h
