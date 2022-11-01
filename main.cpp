#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c ;//une seule instance de la classe connexion
    bool test=true;
           test =c.createconnection();//etablir la connection

    MainWindow w; // puis ouvrir une variable MainWindow

    if(test==true) //si la connexion est etablie
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open "),QObject::tr("connection successful.\n""click cannel to exit."),QMessageBox::Cancel);

    }
    else //si la connexion a échoué
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n""click cancelto exit"),QMessageBox::Cancel);


    return a.exec();
}
