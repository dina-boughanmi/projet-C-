#include "studio.h"
#include<QDateTime>
#include<QDateTimeEdit>
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

studio::studio()
{
   id_s=100;id=100;capacite=1;reservationfrom= "00/00/0000 00:00";reservationto="00/00/0000 00:00";
}
studio :: studio(int id_s,int id,int capacite, QString reservationfrom, QString reservationto )
{
    this->id_s=id_s ;
    this->id=id ;
    this ->capacite=capacite;
    this->reservationfrom=reservationfrom;
    this->reservationto=reservationto;
}

bool studio :: ajouter_studio()
{
 int ID(this->id_s);
 int ID_STUDIO(this->id);
 int CAPACITE(this->capacite);
 QString RESERVATIONFROM(this->reservationfrom);
 QString RESERVATIONTO(this->reservationto);
    QSqlQuery query;
            //QString ID_string=QString ::number(ID);
           //QString ID_string= QString :: number(ID);
          //qDebug()<<ID_s<<ID_string<<ADRESS;
  qDebug()<<"ajouterstudio"<<ID<<ID_STUDIO<<CAPACITE<<RESERVATIONFROM<<RESERVATIONTO;

          query.prepare("INSERT INTO STUDIO(ID,ID_STUDIO, CAPACITE,RESERVATIONFROM,RESERVATIONTO) VALUES (:id_station,:id_studio,:capacite,:reservationfrom,:reservationto)");
          query.bindValue(":id_station", ID);
          query.bindValue(":id_studio", ID_STUDIO );
          query.bindValue(":capacite", CAPACITE);
          query.bindValue(":reservationfrom", RESERVATIONFROM);
          query.bindValue(":reservationto", RESERVATIONTO);
          return query.exec();


}
bool studio :: supprimer_studio(int id_s,int id)
{
    QSqlQuery query;
       QString res= QString::number(id_s);
          QString ras= QString::number(id);
          QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery("select * from LOCATEURS where ( ID_S LIKE '"+res+"%' AND ID_STUDIO LIKE '"+ras+"%' ) ");



         query.prepare("DELETE FROM STUDIO WHERE ID= :id");
         query.bindValue(":id",res);

      return query.exec();
}

QSqlQueryModel * studio ::afficher_studio()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from STUDIO");
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"ID_STUDIO");
    model->setHeaderData(2,Qt::Horizontal,"CAPACITE");
    model->setHeaderData(2,Qt::Horizontal,"RESERVATIONFROM");
    model->setHeaderData(2,Qt::Horizontal,"RESERVATIONTO ");
   return model;

}
bool studio::modifier_studio()
{


    QSqlQuery query;
       query.prepare ("update STUDIO" "SET ID = :id, ID_STUDIO = :id_s, CAPACITE = :capacite , RESERVATIONTO = :reservationto ,RESERVATIONFROM= :reservationfrom" );
   return query.exec();

}
