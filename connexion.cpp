#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");


    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de donneés ODBC
    db.setUserName("dina");//inserer nom de l'utilisateur
    db.setPassword("dina");//inserer mot de passede cet utilisateur
    if(db.open())
        return true;
    else
    return false;
}

void connexion:: closeconnection(){db.close();}
