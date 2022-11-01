#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emission.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QDate>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_Emission->setModel(E.afficher());
     ui->le_ID_Emission->setValidator(new QIntValidator(100, 9999999, this));
     ui->lineEdit_2->setValidator(new QIntValidator(100, 9999999, this));
     ui->le_Nom->setInputMask("AAAAAAAAAAAAAAAAAAAA");
     ui->lineEdit->setInputMask("AAAAAAAAAAAAAAAAAAAA");
     ui->lenom_mod->setInputMask("AAAAAAAAAAAAAAAAAAAA");
     ui->leanimateur_mod->setInputMask("AAAAAAAAAAAAAAAAAAAA");
     ui->tab_Emission->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_Ajouter_clicked()
{
   int  ID_Emission=ui->le_ID_Emission->text().toInt();
   int Date_emission =ui->lineEdit_2->text().toInt();
    QString Nom=ui->le_Nom->text();
     QString Animateur=ui->lineEdit->text();
    Emission E(ID_Emission, Date_emission, Nom , Animateur );
    bool test=E.ajouter();

    if(test)
         {ui->tab_Emission->setModel(E.afficher());
             QMessageBox::information(nullptr, QObject::tr("Ok"),
                  QObject::tr("Ajout effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



         }
         else

             QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                  QObject::tr("Ajout non effectué.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


         }



void MainWindow::on_pushButton_clicked()
{
    int ID_Emission =ui->le_ID_Emission_supp->text().toInt();
    bool test=E.supprimer(ID_Emission);
    if(test)
    {ui->tab_Emission->setModel(E.afficher());
       QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("suppression effectuee \n"
                                            "click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                               QObject::tr("suppression non effectuee.\n"
                                      "click Cancel to exit."),QMessageBox::Cancel);
}




void MainWindow::on_pb_modifier_clicked()
{


    int ID_Emission=ui->leid_mod->text().toInt();
    int Date_emission=ui->ledate_mod->text().toInt();
    QString Nom=ui->lenom_mod->text();
    QString Animateur=ui->leanimateur_mod->text();


       Emission E(ID_Emission , Date_emission, Nom, Animateur );

       bool test=E.modifier();
       if(test)
       { ui->tab_Emission->setModel(E.afficher());
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("Modiffication effectué"),QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("Modiffication non effectué"),QMessageBox::Cancel);

}
