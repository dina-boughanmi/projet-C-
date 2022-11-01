#ifndef PUBLICITE1_H
#define PUBLICITE1_H
#include <QString>
#include <QSqlQueryModel>


class publicite1
{
public:
    publicite1();
    publicite1(int,QString,QString);
    int getid_pub ();
    QString getnom_pub();
    QString getnom_sponsor();
    void setid_pub (int) ;
    void setnom_pub(QString);
    void setnom_sponsor(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    bool modifier(int id);




private:
    QString nom_pub,nom_sponsor;
    int id_pub;
};

#endif // PUBLICITE1_H
