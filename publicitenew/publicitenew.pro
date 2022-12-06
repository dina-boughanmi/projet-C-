QT       += core gui sql
QT+=charts
QT += multimedia
QT += multimediawidgets
QT += printsupport
QT       += core gui serialport multimedia multimediawidgets

QT +=network
QT +=svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    arduino.cpp \
    connexion.cpp \
    gestion_pub.cpp \
    main.cpp \
    publicite1.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    gestion_pub.h \
    publicite1.h

FORMS += \
    gestion_pub.ui

TRANSLATIONS += \
    publicitenew_fr_TN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc

DISTFILES += \
    image/256435690_413123583782544_8328845905630176541_n.jpg

QT+=serialport
