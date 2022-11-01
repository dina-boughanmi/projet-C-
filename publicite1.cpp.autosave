#include "publicite1.h"
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"
#include <QString>

publicite1::publicite1()
{
 id_pub  =0; nom_pub=""; nom_sponsor="";
}
publicite1::publicite1 (int id_pub,QString nom_pub,QString nom_sponsor)
{this->id_pub=id_pub;this->nom_pub=nom_pub;this->nom_sponsor =nom_sponsor;}
int publicite1 :: getid_pub () {return id_pub ;}
QString publicite1::getnom_pub() {return nom_pub ;}
QString publicite1::getnom_sponsor(){return nom_sponsor ;}
void publicite1:: setid_pub (int id_pub) {this->id_pub=id_pub;}
void publicite1:: setnom_pub(QString nom_pub){this->nom_pub=nom_pub;}
void publicite1:: setnom_sponsor(QString nom_sponsor){this->nom_sponsor =nom_sponsor; }

bool  publicite1::ajouter()
{

    QSqlQuery query;
    QString id   = QString ::number(id_pub);
    query.prepare("insert into publicite (Nom_pub,Nom_sponsor,ID_pub)" "VALUES(:Nom_pub,:Nom_sponsor,:ID_pub)");
    query.bindValue(":ID_pub",id);
    query.bindValue(":Nom_pub",nom_pub);
    query.bindValue(":Nom_sponsor",nom_sponsor);

    return  query.exec();
}

QSqlQueryModel *publicite1 ::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM publicite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom_pub"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_sponsor"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID_pub"));

    return model;
}


bool  publicite1::supprimer(int)
{
    QSqlQuery query;
    QString id=QString::number(id_pub);
    query.prepare("delete from etudiant where ID=:id");
    query.bindValue(":id",id);
    return  query.exec();
}
bool publicite1::modifier(int id )
{

    QSqlQuery query;
       QString id_string=QString::number(id_pub);
       query.prepare("UPDATE publicite1 SET id_pub= :id_pub,nom_pub= :nom_pub,nom_sponsor= :nom_sponsor WHERE id_pub= :id");
       query.bindValue(":id_pub", id_string);
       query.bindValue(":nom_pub", nom_pub);
       query.bindValue(":nom_sponsor", nom_sponsor);
       return query.exec();

   }
