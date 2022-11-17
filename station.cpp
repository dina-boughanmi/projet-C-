#include "station.h"
#include<qsqlquery.h>
#include<QSqlQuery>
#include<QtDebug>
#include<QtCore>
#include<QString>
#include<QTableView>
#include<QtSql>
#include<QString>
station::station()
{
id=100 ; N_studio=1;adress="";
}

 station:: station(int id,int N_studio,QString adress)
 {
     this->id=id ;
     this->N_studio=N_studio ;
     this ->adress=adress;
 }
 int station::  getid()
 {return id;}
 int station :: getN_studio()
 {return N_studio;}
 QString station:: getadress()
 {return adress;}
 void station :: setid(int id)
 {this->id=id;}
 void station:: setN_studio(int N_studio)
 {this->N_studio=N_studio;}
 void station :: setadress(QString adress)
 {this->adress=adress;}


 bool station :: ajouter_station()
 {
  int ID(this->id);
  int N_STUDIO(this->N_studio);
  QString ADRESS(this->adress);

     QSqlQuery query;
     QString ID_string=QString ::number(ID);
     QString N_STUDIO_string= QString :: number(N_STUDIO);
             qDebug()<<ID_string<<N_STUDIO_string<<ADRESS;
           query.prepare("INSERT INTO STATION(ID, N_STUDIO, ADRESS) VALUES (:id,:n_studio,:adress)");
           query.bindValue(":id", ID);
           query.bindValue(":n_studio", N_STUDIO);
           query.bindValue(":adress", ADRESS);

           return query.exec();


 }
 bool station :: supprimer_station(int id)
 {
     QSqlQuery query;
        QString res= QString::number(id);
          query.prepare("DELETE FROM STATION WHERE ID= :id");
          query.bindValue(":id",res);

       return query.exec();

 }
 QSqlQueryModel * station ::afficher_station()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from STATION");
     model->setHeaderData(0,Qt::Horizontal,"ID");
     model->setHeaderData(1,Qt::Horizontal,"N_STUDIO");
     model->setHeaderData(2,Qt::Horizontal,"ADRESS");

    return model;

 }
 bool station::modifier_station()
 {


     QSqlQuery query;
        query.prepare ("update local" "SET id = :id, N_STUDIO = :N_STUDIO, ADRESS = :ADRESS" );
    return query.exec();

 }
