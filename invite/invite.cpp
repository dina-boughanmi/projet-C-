#include "invite.h"
#include<QtDebug>
#include<QObject>
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include"connection.h"
invite::invite()
{
    CIN=0;
      NOM=" ";
      PRENOM=" ";
      AGE=0;
      NUM_TEL=0;
}
invite::invite( QString NOM, QString PRENOM ,int CIN,int AGE , int NUM_TEL)
{

    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->CIN=CIN;
    this->AGE=AGE;
    this->NUM_TEL=NUM_TEL;
}
int invite::getcin()
{
    return CIN;
}
QString invite::getnom()
{
    return NOM;
}
QString invite::getprenom()
{
    return PRENOM;
}
int invite::getage()
{
    return AGE;
}
int invite::getnumero_tel()
{
    return NUM_TEL;
}



void invite::setcin(int CIN)
{
    this->CIN=CIN;

}
void invite::setnom(QString NOM)
{
    this->NOM=NOM;

}
void invite::setprenom(QString PRENOM)
{
    this->PRENOM=PRENOM;

}
void invite::setage(int AGE)
{
    this->AGE=AGE;

}


void invite::setnumero_tel(int NUM_TEL)
{
    this->NUM_TEL=NUM_TEL;

}



bool invite::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(CIN);
    QString age_string=QString::number(AGE);
    QString numero_tel_string=QString::number(NUM_TEL);
         query.prepare("INSERT INTO invite(NOM,PRENOM,CIN,AGE,NUM_TEL)" "VALUES (:NOM,:PRENOM,:CIN,:AGE,:NUM_TEL)");
         query.bindValue(":NOM", NOM);
         query.bindValue(":PRENOM", PRENOM);
         query.bindValue(":CIN", id_string);
         query.bindValue(":AGE", age_string);
         query.bindValue(":NUM_TEL", numero_tel_string);


               return query.exec();


}


bool invite::supprimer(int CIN)
{
    QSqlQuery query;

         query.prepare("DELETE FROM invite where CIN= :CIN");
         query.bindValue(0, CIN);

return query.exec();

}


QSqlQueryModel *invite::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM invite");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_TEL"));

          return  model;
}
bool invite::modifier(int CIN)
{
    QSqlQuery query;
    QString A=QString::number(AGE);
    QString C=QString::number(CIN);
     QString N=QString::number(NUM_TEL);


    query.prepare("UPDATE invite set NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE,CIN=:CIN,NUM_TEL=:NUM_TEL WHERE CIN=:CIN ");



    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":CIN",CIN);
    query.bindValue(":AGE",AGE);
    query.bindValue(":NUM_TEL",NUM_TEL);


    return query.exec();


}
