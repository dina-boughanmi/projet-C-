#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
class connexion
{
    QSqlDatabase db;
public:
    connexion();
    bool createconnection();
    void closeconnection();

};

#endif // CONNEXION_H
