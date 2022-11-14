#include "animateur.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlTableModel>
#include <QTableView>
#include <QString>
#include<QPdfWriter>
#include<QPainter>
Animateur::Animateur()
{

}

Animateur::Animateur(int id_anim,QString nom,QString prenom,int nbrenfant)
{
  this->nom=nom;
  this->prenom=prenom;
  this->id_anim=id_anim;
  this->nbrenfant=nbrenfant;

}

bool Animateur:: ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_anim);
          query.prepare("INSERT INTO animateur (id_anim, nom, prenom,nbrenfant) "
                        "VALUES (:id, :forename, :surname ,:nbrenfant)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":nbrenfant", nbrenfant);
          return query.exec();
}
QSqlQueryModel *Animateur:: afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT *FROM animateur");
  model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_anim"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal,QObject::tr("nbrenfant"));
 return model;
}

bool Animateur:: supprimer(int id)
{

    QSqlQuery query;
          query.prepare("Delete from animateur where id_anim= :id");
          query.bindValue(0,id_anim);
          return query.exec();

}


bool Animateur::modifier1(int i)
{

    QSqlQuery query;
        QString id_string=QString::number(id_anim);
        query.prepare("UPDATE animateur SET prenom= :prenom ,nom= :nom,nbrenfant= :nbrenfant  WHERE id_anim= :id_anim");
        query.bindValue(":id_anim", id_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":nbrenfant",nbrenfant);
        return query.exec();
}




bool Animateur::chercher(int id)
 {
     QSqlQuery query ;
     QString id_string=QString::number(id);
     qDebug() << id;
    query.prepare("select * from animateur where id_anim=:id");
    return  query.exec();

 }

QSqlQueryModel * Animateur::chercheID( int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString id_string=QString::number(id);

     model->setQuery("select * from ANIMATEUR where upper(id_anim) LIKE upper('%"+id_string+"%')");
    return model;
}

void Animateur::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
     table->setModel(model);
    model->clear();

}

QSqlQueryModel * Animateur::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ANIMATEUR order by id_anim");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_anim"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("nbrenfant"));
return model;
}

QSqlQueryModel * Animateur::planning(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();


     model->setQuery("SELECT * FROM EMISSION LEFT JOIN ANIMATEUR ON ANIMATEUR.ID_ANIM = EMISSION.ID_EMISSION where upper(animateur) LIKE upper('%"+nom+"%')");

     return model;

}


QSqlQueryModel * Animateur::details(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
       QString id_string=QString::number(id);

     model->setQuery("SELECT * FROM DETAILS_EMISSION LEFT JOIN EMISSION ON DETAILS_EMISSION.ID_EMIS = EMISSION.ID_EMISSION where upper(ID_EMISSION) LIKE upper('%"+id_string+"%')");
    return model;

}
