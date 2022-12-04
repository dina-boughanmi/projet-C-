#include "gestion_studio.h"
#include <QApplication>
#include <QStyleHints>
#include <QDesktopWidget>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QApplication>
#include <QMessageBox>
#include<log_in.h>
#include "connection.h"

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     log_in log;
     Gestion_Studio w;
     connection c;
     QGuiApplication::setApplicationDisplayName(Gestion_Studio::tr("on air"));
     c.createconnect();
     log.show();
      /*  if (!QGuiApplication::styleHints()->showIsFullScreen() && !QGuiApplication::styleHints()->showIsMaximized()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(&w);
        w.resize(availableGeometry.width() / 3, availableGeometry.height() * 2 / 3);
        w.move((availableGeometry.width() - w.width()) / 2,
                    (availableGeometry.height() - w.height()) / 2);
    }
    if(test)
    {w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
     w.update();
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

*/

      return a.exec();
}
