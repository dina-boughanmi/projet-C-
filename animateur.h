#ifndef ANIMATEUR_H
#define ANIMATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Animateur
{
    QString nom,prenom;
    int id_anim,nbrenfant;

public:
    //constructeurs:
    Animateur();
    Animateur(int,QString,QString,int);
    //Getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int  getid(){return id_anim;}
    int  get_NBR(){return nbrenfant;}
    //setters;
    void setnom(QString n){ nom=n;}
    void setprenom(QString p){ prenom=p;}
    void  setid(int id1){id_anim=id1;}
    void  set_NBR(int nbr){nbrenfant=nbr;}

    //fonctionalités de bases relatives à l'entite animateur
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier1(int i);
   bool chercher(int id);
   QSqlQueryModel * chercheID(int id);
   void clearTable(QTableView *table);
   QSqlQueryModel * chercher2(int id);
   QSqlQueryModel * tri_id();
  QSqlQueryModel * planning(QString nom);
  QSqlQueryModel * details(int id);

};

#endif // ANIMATEUR_H
