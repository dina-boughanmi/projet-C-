#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT       += core gui sql printsupport serialport
QT       += multimedia multimediawidgets
QT       += network
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = projet2A
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Gestion_de_invite.cpp \
    arduino.cpp \
    connection.cpp \
    dialog_stats.cpp \
    exportexcelobject.cpp \
    invite.cpp \
    main.cpp \
    messengerclient.cpp \
    messengerconnection.cpp \
    messengerserver.cpp \
    messengersocket.cpp \
    qcustomplot.cpp

HEADERS += \
    Gestion_de_invite.h \
    arduino.h \
    connection.h \
    dialog_stats.h \
    exportexcelobject.h \
    invite.h \
    messengerclient.h \
    messengerconnection.h \
    messengerserver.h \
    messengersocket.h \
    qcustomplot.h

FORMS += \
    Gestion_de_invite.ui \
    dialog_stats.ui \
    messengerclient.ui \
    messengerconnection.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
