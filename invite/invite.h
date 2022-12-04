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
#include <QTableView>

class invite
{
public:
    invite();

        invite(QString,QString,int,int,int);
        invite(QString);

        int getcin();
        QString getnom();
        QString getprenom();
        QString getchat();
        int getage();
        int getnumero_tel();


        void setcin(int);
        void setnom(QString);
        void setchat(QString);
        void setprenom(QString);
        void setage(int);
        void setnumero_tel(int);


        bool ajouter();
        bool supprimer(int);
        bool supprimerc();
        QSqlQueryModel* afficher();
        bool modifier(int);
    QSqlQueryModel* tri_cin();
    QSqlQueryModel* tri_age();
    QSqlQueryModel* tri_nom();
    QSqlQueryModel *afficherc();
     void chercheID(QTableView *table, int CIN);
void clearTable(QTableView * table);
bool chatbox();
    private:

        QString NOM;
        QString PRENOM;
          QString CHAT;
        int CIN;
        int AGE;
        int NUM_TEL;
};

#endif // INVITE_H
