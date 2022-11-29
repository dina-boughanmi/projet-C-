#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "animateur.h"
#include "statistique_c.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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

private:
    Ui::MainWindow *ui;
     statistique_c * statistique_c;
    Animateur A;
    QByteArray data ; // variable contenant les données reçues
    Arduino A1;       // objet temporaire

};
#endif // MAINWINDOW_H
