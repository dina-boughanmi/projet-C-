#ifndef STATION_H
#define STATION_H
#include<QtCore>
#include<QString>
#include<QtGui>
#include<QString>
#include<QtDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"connection.h"
#include<QDoubleValidator>
#include<QFile>

class station
{
public:

    station();
    station(int,int,QString);
    int getid();
    int getN_studio();
    QString  getadress();
    void setid(int);
    void setN_studio(int);
    void setadress(QString);


    bool ajouter_station();
    bool  supprimer_station(int );
    QSqlQueryModel * afficher_station();
    bool modifier_station();
private:
    int id ,N_studio;
    QString adress;


};

#endif // STATION_H
