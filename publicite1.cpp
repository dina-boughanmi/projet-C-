#include "publicite1.h"
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"
#include <QString>

publicite1::publicite1()
{
 id_pub  =0; nom_pub=""; nom_sponsor="";categorie="";
}
publicite1::publicite1 (int id_pub,QString nom_pub,QString nom_sponsor,QString categorie)
{this->id_pub=id_pub;this->nom_pub=nom_pub;this->nom_sponsor =nom_sponsor;this->categorie =categorie;}
int publicite1 :: getid_pub () {return id_pub ;}
QString publicite1::getnom_pub() {return nom_pub ;}
QString publicite1::getnom_sponsor(){return nom_sponsor ;}
QString publicite1::getcategorie(){return categorie ;}
void publicite1:: setid_pub (int id_pub) {this->id_pub=id_pub;}
void publicite1:: setnom_pub(QString nom_pub){this->nom_pub=nom_pub;}
void publicite1:: setnom_sponsor(QString nom_sponsor){this->nom_sponsor =nom_sponsor; }
void publicite1:: setcategorie(QString categorie){this->categorie = categorie; }

bool  publicite1::ajouter()
{

    QSqlQuery query;
    QString id   = QString ::number(id_pub);
    query.prepare("insert into publicite (Nom_pub,Nom_sponsor,ID_pub,categorie)" "VALUES(:Nom_pub,:Nom_sponsor,:ID_pub,:categorie)");
    query.bindValue(":ID_pub",id);
    query.bindValue(":Nom_pub",nom_pub);
    query.bindValue(":Nom_sponsor",nom_sponsor);
    query.bindValue(":categorie",categorie);
    return  query.exec();
}

QSqlQueryModel *publicite1 ::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM publicite");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom_pub"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_sponsor"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("id_pub"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("categorie"));

    return model;
}


bool  publicite1::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("delete from publicite where id_pub=:id");
    query.bindValue(0,id);
    return  query.exec();
}
bool publicite1::modifier()
{

    QSqlQuery query;

       query.prepare("UPDATE publicite SET id_pub= :id_pub,nom_pub= :nom_pub,nom_sponsor= :nom_sponsor WHERE id_pub= :id_pub");
       query.bindValue(":id_pub", id_pub);
       query.bindValue(":nom_pub", nom_pub);
       query.bindValue(":nom_sponsor", nom_sponsor);
       query.bindValue(":categorie", categorie);

       return query.exec();

   }



QSqlQueryModel * publicite1::Rechercherid(int id)

     {
    QSqlQuery query;

             query.prepare("SELECT *  FROM publicite where ID_PUB=:ID_PUB");

               query.bindValue(":ID_PUB",id);
               query.exec();

          QSqlQueryModel* model= new QSqlQueryModel;
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_PUB"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_PUB"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("CATEGORIE"));
                //model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_P"));

              model->setQuery(query);
            return model;
}

QSqlQueryModel * publicite1::tri()  //tri_par_ID
    {
        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT * FROM PUBLICITE ORDER BY ID_PUB ASC");
            return model;
    }

QSqlQueryModel * publicite1::jeux_concour()
{
     int nombre;
    nombre = rand() % (100 + 1);
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM INVITE WHERE ID_I=:nombre");
        return model;
}

/*void publicite1::chercheID(QTableView *table, int ID_A)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from PUBLICITE where regexp_like(ID_PUB,:ID_A);");
   query->bindValue(":ID_PUB",ID_A);
   if(ID_A==0)
   {
       query->prepare("select * from PUBLICITE;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}*/
void publicite1::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
