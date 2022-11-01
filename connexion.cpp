
#include "connexion.h"


connexion::connexion(){}

bool connexion::createconnection()
{
    bool test=false;
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
 db.setDatabaseName("proj");
 db.setUserName("mrabet");
 db.setPassword("linda2022");

 if (db.open())
     test=true;
 return test ;
}



