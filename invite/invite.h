#ifndef INVITE_H
#define INVITE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDoubleValidator>
#include<QtDebug>
#include<QObject>
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>

class invite
{
public:
    invite();

        invite(QString,QString,int,int,int);


        int getcin();
        QString getnom();
        QString getprenom();
        int getage();
        int getnumero_tel();


        void setcin(int);
        void setnom(QString);
        void setprenom(QString);
        void setage(int);
        void setnumero_tel(int);


        bool ajouter();
        bool supprimer(int);
        QSqlQueryModel* afficher();
        bool modifier(int);



    private:

        QString NOM;
        QString PRENOM;
        int CIN;
        int AGE;
        int NUM_TEL;
};

#endif // INVITE_H
