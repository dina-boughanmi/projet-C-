#ifndef CONNECTION_H
#define CONNECTION_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>

#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>


class connection
{
public:
    connection();
      bool createconnect();
      void closeconnection();
};

#endif // CONNECTION_H
