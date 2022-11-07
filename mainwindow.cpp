#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animateur.h"
#include "connexion.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include <QIntValidator>
#include <QStringRef>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QIntValidator(0, 999999, this));
    ui->tab_animateur->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_supprimer_clicked()
{
    Animateur A;

    A.setid(ui->l_id->text().toInt());


         bool test=A.supprimer(A.getid());
        if(test)
        {
          QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n""click cancel to exit."),QMessageBox::Cancel);
          ui->tab_animateur->setModel(A.afficher());
        }

        else
        //si requete non effectuée
        QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("suppression non effectué\n""click cancel to exit."),QMessageBox::Cancel);



}





void MainWindow::on_modifier_clicked()
{
    int id_anim=ui->lineEdit_5->text().toInt();
           QString nom=ui->lineEdit_6->text();
           QString prenom=ui->lineEdit_9->text();

           Animateur A(id_anim,nom,prenom);
           bool test=A.modifier1(id_anim);
           if (test)
           {

           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);
            ui->tab_animateur->setModel(A.afficher());
           }
           else
           {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);
           }
}


void MainWindow::on_ajouter_clicked()
{
    bool test1;
        //recuperation des informations saisies dans laes 3 champs
        int id_anim=ui->lineEdit_id->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();

       Animateur A(id_anim,nom,prenom); //instancier un objet de la classe animateur
                                            //en utilisant les informations saisies dans l'interface

          test1 = A.ajouter(); //inserer l'objet animateur

          if(test1)
      {
         QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""click cancel to exit."),QMessageBox::Cancel);
         ui->tab_animateur->setModel(A.afficher());

          }
       else
              //si requete non effectuée
              QMessageBox::critical(nullptr,QObject::tr("ok"),QObject::tr("Ajout non effectué\n""click cancel to exit."),QMessageBox::Cancel);

}

//dina

void MainWindow::on_chercher_clicked()
{
    Animateur A;

 qDebug() << "fffffffffffffffffffff";
       int ID=ui->l_id->text().toInt();
        QString nom=ui->l_nom->text();
         bool test=A.chercher(ID);

        qDebug() << test;
        if(test)
        {
          QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("exist\n""click cancel to exit."),QMessageBox::Cancel);
          ui->tab_animateur->setModel(A.afficher());
        }

        else
        //si requete non effectuée
        QMessageBox::critical(nullptr,QObject::tr("no"),QObject::tr("non existant\n""click cancel to exit."),QMessageBox::Cancel);


}
