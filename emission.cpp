#include "emission.h"
#include<QObject>
#include<QMessageBox>
#include <QSqlQuery>
#include <QtDebug>

Emission::Emission()
{
ID_Emission=0; Date_emission= 1/1/2000 ; Nom=""; Animateur=" ";

}
Emission::Emission (int ID_Emission ,int Date_emission  , QString Nom , QString Animateur )
{this->ID_Emission=ID_Emission; this->Date_emission=Date_emission; this->Nom=Nom; this->Animateur=Animateur; }

int Emission::getID_Emission(){return ID_Emission;}
int Emission::getDate(){return Date_emission ;}
QString Emission::getNom(){return Nom;}
QString Emission::getAnimateur(){return Animateur;}
void Emission::setID_Emission(int ID_Emission){this->ID_Emission=ID_Emission;}
void Emission::setDate(int Date_emission){this->Date_emission =Date_emission;}
void Emission::setNom(QString Nom){this->Nom=Nom;}
void Emission::setAnimateur(QString Animateur){this->Animateur=Animateur;}

bool Emission::ajouter()
{

    QSqlQuery query;

          query.prepare("INSERT INTO EMISSION (ID_EMISSION, ANIMATEUR, DATE_EMISSION,NOM) "
                        "VALUES (:ID_EMISSION, :ANIMATEUR, :DATE_EMISSION,:NOM)");
          query.bindValue(":ID_EMISSION",  ID_Emission );
          query.bindValue(":ANIMATEUR", Animateur);
          query.bindValue(":DATE_EMISSION", Date_emission);
          query.bindValue(":NOM", Nom);




   return query.exec();  ;

}



bool Emission::supprimer(int ID_Emission_string)
    {


        QSqlQuery query;
    QString res =QString::number(ID_Emission_string);
              query.prepare("Delete from Emission where ID_Emission=:id");
              query.bindValue(":id",res);


          return query.exec();




    }
QSqlQueryModel* Emission::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();



      model->setQuery("SELECT* FROM Emission");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Emission"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Animateur"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Emission"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

 return model ;
}
bool Emission::modifier()
{
    QSqlQuery query;

        query.prepare("UPDATE Emission SET ID_EMISSION=:ID_EMISSION,ANIMATEUR=:ANIMATEUR,DATE_EMISSION=:DATE_EMISSION, NOM=:NOM WHERE ID_EMISSION=:ID_EMISSION");
        query.bindValue(":ID_EMISSION",  ID_Emission );
        query.bindValue(":NOM", Nom);
        query.bindValue(":ANIMATEUR", Animateur);
        query.bindValue(":DATE_EMISSION", Date_emission);

    return query.exec();
}

void Emission::chercheID(QTableView *table, int id)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from emission where regexp_like(ID_Emission,:id);");
   query->bindValue(":id",id);
   if(id==0)
   {
       query->prepare("select * from emission;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
void Emission::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}
QSqlQueryModel * Emission::tri_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from emission order by ID_Emission");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Emission"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Animateur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Emission"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
QSqlQueryModel * Emission::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from emission order by Nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Emission"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Animateur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Emission"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
QSqlQueryModel * Emission::tri_animateur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from emission order by Animateur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_Emission"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Animateur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_Emission"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
