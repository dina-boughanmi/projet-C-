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
   id=100;capacite=1;reservationfrom= "00/00/0000 00:00";reservationto="00/00/0000 00:00";
}
studio :: studio(int id,int capacite, QString reservationfrom, QString reservationto )
{
   // this->id_s=id_s ;
    this->id=id ;
    this ->capacite=capacite;
    this->reservationfrom=reservationfrom;
    this->reservationto=reservationto;
}

bool studio :: ajouter_studio()
{
 //int ID(this->id_s);
 int ID_STUDIO(this->id);
 int CAPACITE(this->capacite);
 QString RESERVATIONFROM(this->reservationfrom);
 QString RESERVATIONTO(this->reservationto);
    QSqlQuery query;
            //QString ID_string=QString ::number(ID);
           //QString ID_string= QString :: number(ID);
          //qDebug()<<ID_s<<ID_string<<ADRESS;
  qDebug()<<"ajouterstudio"<<ID_STUDIO<<CAPACITE<<RESERVATIONFROM<<RESERVATIONTO;

          query.prepare("INSERT INTO STUDIO(ID_STUDIO, CAPACITE,RESERVATIONFROM,RESERVATIONTO) VALUES (:id_studio,:capacite,:reservationfrom,:reservationto)");
       //   query.bindValue(":id_station", ID);
          query.bindValue(":id_studio", ID_STUDIO );
          query.bindValue(":capacite", CAPACITE);
          query.bindValue(":reservationfrom", RESERVATIONFROM);
          query.bindValue(":reservationto", RESERVATIONTO);
          return query.exec();


}
bool studio :: supprimer_studio(int id)
{
    QSqlQuery query;
     QString res= QString::number(id);
         QString ras= QString::number(id);
    qDebug()<<id;
        //  QSqlQueryModel * model= new QSqlQueryModel();
       //   model->setQuery("select * from STUDIO where  ID_STUDIO LIKE '"+ras+"%'  ");



         query.prepare("DELETE FROM STUDIO WHERE ID_STUDIO= :ID_STUDIO");
         query.bindValue(":ID_STUDIO",id);

      return query.exec();
}

QSqlQueryModel * studio ::afficher_studio()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from STUDIO");
    //model->setHeaderData(0,Qt::Horizontal,"ID_STATION");
    model->setHeaderData(0,Qt::Horizontal,"ID_STUDIO");
    model->setHeaderData(1,Qt::Horizontal,"CAPACITE");
    model->setHeaderData(2,Qt::Horizontal,"RESERVATION_FROM");
    model->setHeaderData(3,Qt::Horizontal,"RESERVATION_TO ");
   return model;

}
bool studio::modifier_studio( int ID_STUDIO,  int CAPACITE, QString RESERVATIONFROM,  QString RESERVATIONTO)
{


 QString CAPACITE_string =QString::number(CAPACITE);
QString ID_STUDIO_STRING =QString ::number(ID_STUDIO);

  qDebug()<<"modifer"<<ID_STUDIO<<CAPACITE<<RESERVATIONFROM<<RESERVATIONTO;
     QSqlQuery query;
     query.prepare ("update STUDIO set CAPACITE = '"+CAPACITE_string+"',RESERVATIONFROM = '"+RESERVATIONFROM+"',RESERVATIONTO = '"+RESERVATIONTO+"' where ID_STUDIO = '"+ID_STUDIO_STRING+"' " );
   return query.exec();

}
QSqlQueryModel * studio::afficherdown_id_studio()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM STUDIO ORDER BY ID_STUDIO DESC");
//model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STUDIO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("RESERVATIONFROM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVATIONTO"));
return model;
}

QSqlQueryModel * studio::afficherdown_capasite()
{ QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM STUDIO ORDER BY CAPACITE DESC");
//model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_STUDIO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("RESERVATIONFROM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("RESERVATIONTO"));
return model;
}
QSqlQueryModel * studio::rechercher_id_studio_or_capasite(QString texte)
{
        QSqlQuery *qry=new QSqlQuery();
        qry->prepare("select * from STUDIO where CAPACITE=:CAPACITE OR ID_STUDIO=:ID_STUDIO");
        qry->bindValue(":CAPACITE",texte);
        qry->bindValue(":ID_STUDIO",texte);
        qry->exec();

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(*qry);
        return model;
    }
