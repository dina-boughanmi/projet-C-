#ifndef EMISSION_H
#define EMISSION_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDoubleValidator>
#include<QtDebug>
#include<QObject>
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>

#include <QSqlQuery>


class Emission
{
public:
    Emission();
    Emission (int ,int , QString , QString );
    int getID_Emission();
    int getDate();
    QString getNom();
    QString getAnimateur();
    void setID_Emission(int);
    void setDate(int);
    void setNom(QString);
    void setAnimateur(QString);
    bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer (int);
     bool modifier();



private:
    int ID_Emission , Date_emission ;
    QString Nom , Animateur ;

};

#endif // EMISSION_H
