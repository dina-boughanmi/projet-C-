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
    studio(int,int,QString,QString);

    bool ajouter_studio();
    bool  supprimer_studio(int);
    QSqlQueryModel * afficher_studio();
    bool modifier_studio( int,  int , QString ,  QString );

    QSqlQueryModel * afficherdown_id_studio();
   // QSqlQueryModel * afficherdown_id_station();
    QSqlQueryModel * afficherdown_capasite();
      QSqlQueryModel * rechercher_id_studio_or_capasite(QString );

private:

    int id,capacite;
    QString reservationfrom,reservationto;

};

#endif // STUDIO_H
