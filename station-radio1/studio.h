#ifndef STUDIO_H
#define STUDIO_H

#include<QDateTime>
#include<QDateTimeEdit>
#include<qsqlquery.h>
#include<QSqlQuery>
#include<QtDebug>
#include<QtCore>
#include<QString>
#include"connection.h"
#include<QtSql>
#include<QString>



class studio
{
public:
    studio();
    studio(int,int,int,QString,QString);

    bool ajouter_studio();
    bool  supprimer_studio(int,int);
    QSqlQueryModel * afficher_studio();
    bool modifier_studio();
private:

    int id_s,id,capacite;
    QString reservationfrom,reservationto;

};

#endif // STUDIO_H
