QT  +=core gui sql
QT +=network
QT +=printsupport
QT +=charts
QT +=multimedia
QT +=serialport
QT +=widgets
QTPLUGIN += gif

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Source_Projet2A
#TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CONFIG += c++11


SOURCES += \
    SMTPClient/email.cpp \
    SMTPClient/emailaddress.cpp \
    SMTPClient/smtpclient.cpp \
    connection.cpp \
    log_in.cpp \
    log_param.cpp \
    main.cpp \
    mainwindow.cpp \
    piechartdrilldown/drilldownchart.cpp \
    piechartdrilldown/drilldownslice.cpp \
    stat2.cpp \
    statistique.cpp \
    studio.cpp

HEADERS += \
    SMTPClient/email.h \
    SMTPClient/emailaddress.h \
    SMTPClient/smtpclient.h \
    connection.h \
    log_in.h \
    log_param.h \
    mainwindow.h \
    piechartdrilldown/drilldownchart.h \
    piechartdrilldown/drilldownslice.h \
    stat2.h \
    statistique.h \
    studio.h

FORMS += \
    log_in.ui \
    log_param.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imag.qrc

DISTFILES += \
    ../../onair.png \
    SMTPClient/SMTPClient.pri \
    icons8-fingerprint-scan.gif

