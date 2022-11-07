#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "animateur.h"


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

   // void on_tri_clicked();

    void on_chercher_clicked();

private:
    Ui::MainWindow *ui;
    Animateur A;
};
#endif // MAINWINDOW_H
