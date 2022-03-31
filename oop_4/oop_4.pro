QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bus.cpp \
    car.cpp \
    custombrowser.cpp \
    datareader.cpp \
    datawriter.cpp \
    main.cpp \
    mainwindow.cpp \
    truck.cpp

HEADERS += \
    bus.h \
    car.h \
    custombrowser.h \
    datareader.h \
    datawriter.h \
    mainwindow.h \
    truck.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
