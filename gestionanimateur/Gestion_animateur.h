#ifndef Gestion_animateur_H
#define Gestion_animateur_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "animateur.h"
#include "statistique_c.h"
#include"Atelier_Arduino_v2/arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_animateur; }
QT_END_NAMESPACE

class Gestion_animateur : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_animateur(QWidget *parent = nullptr);
    ~Gestion_animateur();
     void on_pushButton_ajouter_clicked();
private slots:


     void on_supprimer_clicked();
     void on_modifier_clicked();
     void  on_ajouter_clicked();

     void on_tri_clicked();



     void on_pdf_clicked();

     void on_chercher_clicked();

     void on_statistique_clicked();

     void on_planning_clicked();

     void on_details_clicked();

     void on_RJC_clicked();

     void on_RJC1_clicked();


     void on_quitter_pushbottn_clicked();
private:
    Ui::Gestion_animateur *ui;
     statistique_c * statistique_c;
    Animateur A;
    QByteArray data ; // variable contenant les données reçues
    Arduino A1;       // objet temporaire

};
#endif // Gestion_animateur_H
