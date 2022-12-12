QT  +=core gui sql  multimediawidgets svg
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
    Atelier_Arduino_v2/arduino.cpp \
    Emission/d_stats.cpp \
    Emission/emission.cpp \
    Emission/gestion_emission.cpp \
    Emission/qrcode.cpp \
    Emission/qrcodegeneratordemo.cpp \
    SMTPClient/email.cpp \
    SMTPClient/emailaddress.cpp \
    SMTPClient/smtpclient.cpp \
    connection.cpp \
    gestion_studio.cpp \
    gestionanimateur/animateur.cpp \
    gestionanimateur/dialog_stats_anim.cpp \
    gestionanimateur/gestion_animateur.cpp \
    gestionanimateur/statistique_c.cpp \
    invite/Gestion_de_invite.cpp \
    invite/dialog_stats.cpp \
    invite/exportexcelobject.cpp \
    invite/invite.cpp \
    invite/messengerclient.cpp \
    invite/messengerconnection.cpp \
    log_in.cpp \
    log_param.cpp \
    main.cpp \
    menu.cpp \
    piechartdrilldown/drilldownchart.cpp \
    piechartdrilldown/drilldownslice.cpp \
    publicitenew/gestion_pub.cpp \
    publicitenew/publicite1.cpp \
    qcustomplot.cpp \
    stat2.cpp \
    statistique.cpp \
    studio.cpp

HEADERS += \
    Atelier_Arduino_v2/arduino.h \
    Emission/d_stats.h \
    Emission/emission.h \
    Emission/gestion_emission.h \
    Emission/qrcode.h \
    SMTPClient/email.h \
    SMTPClient/emailaddress.h \
    SMTPClient/smtpclient.h \
    connection.h \
    gestion_studio.h \
    gestionanimateur/animateur.h \
    gestionanimateur/dialog_stats_anim.h \
    gestionanimateur/gestion_animateur.h \
    gestionanimateur/statistique_c.h \
    invite/DuMessengerSocket.h \
    invite/Gestion_de_invite.h \
    invite/dialog_stats.h \
    invite/exportexcelobject.h \
    invite/invite.h \
    invite/messengerclient.h \
    invite/messengerconnection.h \
    log_in.h \
    log_param.h \
    menu.h \
    piechartdrilldown/drilldownchart.h \
    piechartdrilldown/drilldownslice.h \
    publicitenew/gestion_pub.h \
    publicitenew/publicite1.h \
    qcustomplot.h \
    stat2.h \
    statistique.h \
    studio.h

FORMS += \
    Emission/Gestion_emission.ui \
    Emission/d_stats.ui \
    gestion_studio.ui \
    gestionanimateur/dialog_stats_anim.ui \
    gestionanimateur/gestion_animateur.ui \
    gestionanimateur/statistique_c.ui \
    invite/Gestion_de_invite.ui \
    invite/dialog_stats.ui \
    invite/messengerclient.ui \
    invite/messengerconnection.ui \
    log_in.ui \
    log_param.ui \
    menu.ui \
    publicitenew/gestion_pub.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_ICONS = on-air.ico
RESOURCES += \
    image/image2.qrc \
    invite/resource.qrc

DISTFILES += \
    ../../onair.png \
    Emission/03919e8ec0f64df6838277e33fe851ea.jpg \
    Emission/685258a59fe86509645caa9373bb5dea.jpg \
    Emission/8b5800b477da5272aeb1c2a599bd4027.jpg \
    Emission/Liste.pdf \
    Emission/ade1218ecd6c98294857f5aa14752c77.jpg \
    Emission/c9d5e5b2061c9d651d6d84a9fa633609.jpg \
    Emission/cb9e027338e35776f778214e78bfac8c.jpg \
    IMG8RES FOR QT/bar-chart.gif \
    IMG8RES FOR QT/icons8-communication-unscreen.gif \
    IMG8RES FOR QT/icons8-communication-unscreen.gif \
    IMG8RES FOR QT/icons8-fingerprint-scan-unscreen.gif \
    IMG8RES FOR QT/icons8-fingerprint-scan-unscreen.gif \
    IMG8RES FOR QT/icons8-private-wall-mount-camera-50.png \
    IMG8RES FOR QT/icons8-profit-unscreen.gif \
    IMG8RES FOR QT/icons8-shield-unscreen.gif \
    IMG8RES FOR QT/icons8-shield-unscreen.gif \
    IMG8RES FOR QT/icons8-speech-bubble-unscreen.gif \
    IMG8RES FOR QT/icons8-tools-unscreen.gif \
    IMG8RES FOR QT/icons8-tools-unscreen.gif \
    IMG8RES FOR QT/icons8-wall-mount-camera-error-50.png \
    IMG8RES FOR QT/modifier.png \
    IMG8RES FOR QT/modifier.png \
    IMG8RES FOR QT/on air.jpg \
    IMG8RES FOR QT/on air.jpg \
    IMG8RES FOR QT/on air.jpg \
    IMG8RES FOR QT/onair.png \
    IMG8RES FOR QT/onair.png \
    IMG8RES FOR QT/planner.gif \
    IMG8RES FOR QT/print.png \
    IMG8RES FOR QT/print.png \
    IMG8RES FOR QT/qr-code.gif \
    IMG8RES FOR QT/radio.gif \
    IMG8RES FOR QT/radio.gif \
    IMG8RES FOR QT/stat.png \
    IMG8RES FOR QT/stat.png \
    IMG8RES FOR QT/stats.png \
    IMG8RES FOR QT/stats.png \
    IMG8RES FOR QT/support-unscreen.gif \
    IMG8RES FOR QT/timeline.gif \
    IMG8RES FOR QT/trash.png \
    IMG8RES FOR QT/trash.png \
    IMG8RES FOR QT/valider.png \
    IMG8RES FOR QT/valider.png \
    SMTPClient/SMTPClient.pri \
    icons8-fingerprint-scan.gif \
    image/bar-chart.gif \
    image/icons8-communication-unscreen.gif \
    image/icons8-fingerprint-scan-unscreen.gif \
    image/icons8-private-wall-mount-camera-50.png \
    image/icons8-profit-unscreen.gif \
    image/icons8-shield-unscreen.gif \
    image/icons8-speech-bubble-unscreen.gif \
    image/icons8-tools-unscreen.gif \
    image/icons8-wall-mount-camera-error-50.png \
    image/modifier.png \
    image/on air.jpg \
    image/onair.png \
    image/planner.gif \
    image/print.png \
    image/qr-code.gif \
    image/radio.gif \
    image/stat.png \
    image/stats.png \
    image/support-unscreen.gif \
    image/timeline.gif \
    image/trash.png \
    image/valider.png

SUBDIRS += \
    annimateur - Copie - Copie (2)/annimateur.pro \
    annimateur - Copie - Copie (2)/annimateur.pro \
    annimateur - Copie - Copie (2)/annimateur.pro

