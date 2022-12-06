#include "gestion_pub.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;
    bool test=c.createconnection();
    gestion_pub w;


    w.setWindowTitle("Temperature Sensor Reading");
        //w.setFixedSize(400,112);
        w.show();

    if (test)
    {
        w.show();
        QMessageBox::information(nullptr,QObject::tr("database is open "),
        QObject::tr("connexion succesful.\n"
                     "click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox:: critical(nullptr, QObject ::tr("database is not open"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox ::Cancel);


    return a.exec();
}
