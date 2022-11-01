#ifndef ANIMATEUR_H
#define ANIMATEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Animateur
{
    QString nom,prenom;
    int id_anim,presence;

public:
    //constructeurs:
    Animateur();
    Animateur(int,QString,QString);
    //Getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    int  getid(){return id_anim;}
    int  getpresence(){return presence;}

    //setters;
    void setnom(QString n){ nom=n;}
    void setprenom(QString p){ prenom=p;}
    void  setid(int id1){id_anim=id1;}
    void setpresence(int presence1){ presence=presence1;}

    //fonctionalités de bases relatives à l'entite animateur
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier1(int i);
   bool chercher(int id);
   bool  modifier(int id ,QString modification);


};

#endif // ANIMATEUR_H
