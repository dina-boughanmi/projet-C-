#ifndef PUBLICITE1_H
#define PUBLICITE1_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>

class publicite1
{
public:
    publicite1();
    publicite1(int,QString,QString,QString);
    int getid_pub ();
    QString getnom_pub();
    QString getnom_sponsor();
     QString getcategorie();
    void setid_pub (int) ;
    void setnom_pub(QString);
    void setnom_sponsor(QString);
    void setcategorie(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer (int);
    bool modifier();
    //void chercheID(QTableView *table, int ID_A);
    QSqlQueryModel *Rechercherid(int id);
    QSqlQueryModel *tri();
    QSqlQueryModel * jeux_concour();
    void clearTable(QTableView *table);

private:
    QString nom_pub,nom_sponsor,categorie;
    int id_pub;

};

#endif // PUBLICITE1_H
