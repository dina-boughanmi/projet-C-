#include "mainwindow.h"
#include "dialog_stats.h"
#include "ui_mainwindow.h"
#include "animateur.h"
#include "connexion.h"
#include "qcustomplot.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include <QIntValidator>
#include <QStringRef>
#include<QDebug>
#include <QTableView>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QtPrintSupport/QPrinter>
#include<QTextDocument>
#include<QPushButton>

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
    int id_anim=ui->l_id->text().toInt();
           QString nom=ui->nom_m->text();
           QString prenom=ui->prenom_m->text();
           int nbrenfant=ui->l_m_nbr->text().toInt();

           Animateur A(id_anim,nom,prenom,nbrenfant);
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
        int nbrenfant=ui->l_nbrenfant->text().toInt();

       Animateur A(id_anim,nom,prenom,nbrenfant); //instancier un objet de la classe animateur
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



void MainWindow::on_tri_clicked()
{

    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tab_animateur->setModel(A.tri_id());

}



void MainWindow::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/nidha/OneDrive/Desktop/annimateur/liste.pdf");

                     QPainter painter(&pdf);

                     int i = 4000;


                     painter.drawText(3000,1500,"LISTE DES ANIMATEUR");
                     painter.setPen(Qt::blue);
                     painter.setFont(QFont("Arial", 50));
                     painter.drawRect(2700,200,6300,2600);
                     painter.drawRect(0,3000,9600,500);
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Arial", 9));
                     painter.drawText(300,3300,"nom");
                     painter.drawText(2300,3300,"prenom");
                     painter.drawText(4300,3300,"id_anim");
                     painter.drawText(6000,3300,"nbrenfant");

                     QSqlQuery query;
                     query.prepare("select * from animateur");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(300,i,query.value(0).toString());
                         painter.drawText(2300,i,query.value(1).toString());
                         painter.drawText(4300,i,query.value(2).toString());
                         painter.drawText(6300,i,query.value(3).toString());
                         painter.drawText(8000,i,query.value(4).toString());
                         i = i +500;
                     }

                     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {
                         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/nidha/OneDrive/Desktop/annimateur/liste.pdf"));

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                         painter.end();
                     }
}


void MainWindow::on_chercher_clicked()
{
   Animateur A ;
           int id=ui->l_id->text().toInt();
           ui->tab_animateur->setModel(A.chercheID(id));

}




void MainWindow::on_planning_clicked()
{
    Animateur A ;
           QString nom=ui->l_nom_anim->text();
            ui->tab_plannig->setModel(A.planning(nom));
}


void MainWindow::on_details_clicked()
{
    Animateur A ;
            int id=ui->l_id_emiss->text().toInt();
            ui->tab_details->setModel(A.details(id));
}

void MainWindow::on_statistique_clicked()
{
    Dialog_stats s;
    s.setModal(true);
    s.exec();
}
