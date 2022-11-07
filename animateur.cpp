#include "animateur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlTableModel>
#include <QString>
Animateur::Animateur()
{

}

Animateur::Animateur(int id_anim,QString nom,QString prenom)
{
  this->nom=nom;
  this->prenom=prenom;
  this->id_anim=id_anim;

}

bool Animateur:: ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_anim);
          query.prepare("INSERT INTO animateur (id_anim, nom, prenom) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id",id_string);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);

          return query.exec();
}
QSqlQueryModel *Animateur:: afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("SELECT *FROM animateur");
  model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_anim"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));

 return model;
}

bool Animateur:: supprimer(int id)
{
    Animateur A;

    QSqlQuery query;
    bool test1=A.chercher(A.getid()); //appel de la fonction chercher

   if(test1)
   {
          query.prepare("Delete from animateur where id_anim= :id");
          query.bindValue(0,id_anim);
          return query.exec();
    }
   else
       return test1=false;
}


bool Animateur::modifier1(int i)
{

    QSqlQuery query;
        QString id_string=QString::number(id_anim);
        query.prepare("UPDATE animateur SET prenom= :prenom ,nom= :nom  WHERE id_anim= :id_anim");
        query.bindValue(":id_anim", id_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
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
