#include "Gestion_animateur.h"
#include "dialog_stats_anim.h"
#include "Atelier_Arduino_v2/arduino.h"
#include "ui_gestion_animateur.h"
#include "animateur.h"
#include "connection.h"
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
#include"menu.h"
Gestion_animateur::Gestion_animateur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_animateur)
{
    ui->setupUi(this);
    int ret=A1.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A1.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A1.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";

            }

            QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
         // permet de lancer le slot update_label suite a la reception du signal readyRead (reception des données).

    ui->lineEdit_id->setValidator(new QIntValidator(0, 999999, this));
    ui->tab_animateur->setModel(A.afficher());



    //gif
        QMovie* movie = new QMovie("C:/Users/user/Documents/projet-C-/IMG8RES FOR QT/support-unscreen.gif");
    if (!movie->isValid())
    {

        qDebug()<<"not valed gif";
    }
    // Play GIFplantgif
    QLabel *label_gif= ui->animateurgif;
   label_gif->setMovie(movie);
    movie->start();
     qDebug()<<"valed gif selket ";

     //gif
         QMovie* mov = new QMovie("C:/Users/user/Documents/projet-C-/IMG8RES FOR QT/planner.gif");
     if (!movie->isValid())
     {

         qDebug()<<"not valed gif";
     }
     // Play GIFplantgif
     QLabel *label_gi= ui->plantgif;
    label_gi->setMovie(mov);
     mov->start();
      qDebug()<<"valed gif selket ";
}

Gestion_animateur::~Gestion_animateur()
{
    delete ui;
}



void Gestion_animateur::on_supprimer_clicked()
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





void Gestion_animateur::on_modifier_clicked()
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


void Gestion_animateur::on_ajouter_clicked()
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



void Gestion_animateur::on_tri_clicked()
{

    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

            ui->tab_animateur->setModel(A.tri_id());

}



void Gestion_animateur::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/user/Desktop/annimateur - Copie - Copie (2)/liste.pdf");

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
                         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Desktop/annimateur - Copie - Copie (2)/liste.pdf"));

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                         painter.end();
                     }
}


void Gestion_animateur::on_chercher_clicked()
{
   Animateur A ;
           int id=ui->l_id->text().toInt();
           ui->tab_animateur->setModel(A.chercheID(id));

}




void Gestion_animateur::on_planning_clicked()
{
    Animateur A ;
           QString nom=ui->l_nom_anim->text();
            ui->tab_plannig->setModel(A.planning(nom));
}


void Gestion_animateur::on_details_clicked()
{
    Animateur A ;
            int id=ui->l_id_emiss->text().toInt();
            ui->tab_details->setModel(A.details(id));
}

void Gestion_animateur::on_statistique_clicked()
{
    Dialog_stats_anim s;
    s.setModal(true);
    s.exec();
}

void Gestion_animateur::on_RJC_clicked()
{
    int id=ui->l_pub->text().toInt();
      QSqlQuery qry=A.select(id);

      int RJC=qry.value(3).toInt();
       qDebug() << RJC;
      QSqlQuery qry1=A.select_nom(RJC);

      QString nom=qry1.value(1).toString();
       qDebug() << nom;

     QString c;

    for (int i=0; i < nom.length(); i++)
          {
            c = nom.at(i);
            QByteArray m= c.toUtf8();
            A1.write_to_arduino(m);
          }
}

void Gestion_animateur::on_RJC1_clicked()
{
    int id = ui->l_pub->text().toUInt();

       QString h= A1.select(id);

       ui->pointage->setText(h);

       QString msg=ui->pointage->text();

       ui->pointage->setText(msg);
       if (msg=="")
           msg="-----ERREUR-----";
       QString c;

       for (int i=0; i < msg.length(); i++)
         {
           c = msg.at(i);
           QByteArray m= c.toUtf8();
            qDebug() << "dina";
           A1.write_to_arduino(m);
         }

}
void Gestion_animateur::on_quitter_pushbottn_clicked()
{
    menu *w =new menu;
    w->show();
    this->hide();
    A1.close_arduino();
}

