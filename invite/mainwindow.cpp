#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"invite.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_3->setValidator( new QIntValidator(00000001, 99999999, this));
    ui->lineEdit_4->setValidator( new QIntValidator(00, 99, this));
    ui->lineEdit_5->setValidator( new QIntValidator(00000001, 99999999, this));
    ui->lineEdit->setInputMask("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    ui->lineEdit_2->setInputMask("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    ui->lineEdit_10->setInputMask("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    ui->lineEdit_6->setInputMask("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
     ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString NOM=ui->lineEdit->text();
    QString PRENOM=ui->lineEdit_2->text();
    int CIN=ui->lineEdit_3->text().toInt();
    int AGE=ui->lineEdit_4->text().toInt();
    int NUM_TEL=ui->lineEdit_5->text().toInt();
    invite i(NOM,PRENOM,CIN,AGE,NUM_TEL);

    bool test=i.ajouter();

     if(test)
     {ui->tableView->setModel(etmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ok"),
              QObject::tr("Ajout effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);



     }
     else

         QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
              QObject::tr("Ajout non effectué.\n"
                          "Click Cancel to exit."), QMessageBox::Cancel);



}



void MainWindow::on_pushbutton_supp_clicked()
{

   int CIN=(ui->lineEdit_9->text().toInt());
    bool test=etmp.supprimer(CIN);
    if(test)
    {ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("Suppression effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else

        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
             QObject::tr("Suppression non effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);



}


void MainWindow::on_pushButton_15_clicked()
{
    QString NOM=ui->lineEdit_10->text();
    QString PRENOM=ui->lineEdit_6->text();
    int CIN=ui->lineEdit_mc->text().toInt();
    int AGE=ui->lineEdit_11->text().toInt();
    int NUM_TEL=ui->lineEdit_8->text().toInt();

    invite i(NOM,PRENOM,CIN,AGE,NUM_TEL);



    bool test=i.modifier(CIN);
    if (test)
    { ui->tableView->setModel(etmp.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);

    }
    else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);}



}

