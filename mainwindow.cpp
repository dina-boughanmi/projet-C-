#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicite1.h"
#include<QString>
#include "connexion.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{


    int id_pub=ui->lineEdit->text().toInt();
    QString nom_pub= ui->lineEdit_2->text();
    QString nom_sponsor=ui->lineEdit_3->text();
    publicite1 P(id_pub,nom_pub,nom_sponsor);
    bool test=P.ajouter();
    if (test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok "),
        QObject::tr("ajout effectué\n"
                     "click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox:: critical(nullptr, QObject ::tr("not ok"),
                QObject::tr("ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox ::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    int id =ui->lineEdit->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)

  {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok "),
        QObject::tr("suppression  effectuée\n"
                     "click Cancel to exit."), QMessageBox::Cancel);

 }
 else
        QMessageBox:: critical(nullptr, QObject ::tr("not ok"),
                QObject::tr("suppression  non effectuée.\n"
                            "Click Cancel to exit."), QMessageBox ::Cancel);
}


