#include "Gestion_emission.h"
#include "ui_Gestion_emission.h"
#include "emission.h"
#include "dialog_stats.h"
#include "qrcode.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QDate>
#include<QPushButton>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include <iostream>
#include <fstream>
#include <string>
#include<QtCharts>
#include<QDialog>
#include"arduino.h"
#include"QDebug"

Gestion_emission::Gestion_emission(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gestion_emission)
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

     int ret=A.connect_arduino();
     switch(ret){
     case(0) :qDebug ()<<"arduino is avaible and connected to :" <<A.getarduino_port_name();
     break ;
     case(1) :qDebug() <<"aduino is available but not connected to :" <<A.getarduino_port_name();
         break ;
     case(-1):qDebug() <<"arduino is not available " ;
     }
     QObject ::connect(A.getserial(), SIGNAL (readyRead()) ,this,SLOT(update_label()));
}

void Gestion_emission::updatestring(){}
/*
    data=A.read_from_arduino();
    if(data=="v")
    {//QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("authorization est valide\n ""click cancel"),QMessageBox::Cancel);
         ui->label_14->setText("authorization est valide");

    qDebug()<<data;
    }
    if(data=="n")
    {
    //QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("authorization est non valide\n ""click cancel"),QMessageBox::Cancel);
     ui->label_14->setText("authorization est non valide");
         qDebug()<<data ;
    }
}
*/

Gestion_emission::~Gestion_emission()
{
    delete ui;
}


void Gestion_emission::on_pb_Ajouter_clicked()
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



void Gestion_emission::on_pushButton_clicked()
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




void Gestion_emission::on_pb_modifier_clicked()
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



void Gestion_emission::on_pb_Ajouter_3_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_Emission->setModel(E.tri_id());
}

void Gestion_emission::on_pb_Ajouter_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_Emission->setModel(E.tri_nom());
}

void Gestion_emission::on_pb_Ajouter_4_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectué.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_Emission->setModel(E.tri_animateur());
}

void Gestion_emission::on_pb_Ajouter_6_clicked()
{
    QPdfWriter pdf("C:/Users/CBE/Desktop/Atelier_Connexion/Liste.pdf");

                     QPainter painter(&pdf);

                     int i = 4000;


                     painter.drawText(3000,1500,"LISTE DES EMISSION");
                     painter.setPen(Qt::blue);
                     painter.setFont(QFont("Arial", 50));
                     painter.drawRect(2700,200,6300,2600);
                     painter.drawRect(0,3000,9600,500);
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Arial", 9));
                     painter.drawText(300,3300,"ID_EMISSION");
                     painter.drawText(2300,3300,"NOM");
                     painter.drawText(4300,3300,"DATE_EMISSION");
                     painter.drawText(6000,3300,"ANIMATEUR");

                     QSqlQuery query;
                     query.prepare("select * from emission");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(300,i,query.value(0).toString());
                         painter.drawText(2300,i,query.value(1).toString());
                         painter.drawText(4300,i,query.value(2).toString());
                         painter.drawText(6300,i,query.value(3).toString());

                         i = i +500;
                     }

                     int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                     if (reponse == QMessageBox::Yes)
                     {
                         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/CBE/Desktop/Atelier_Connexion/Liste.pdf"));

                         painter.end();
                     }
                     if (reponse == QMessageBox::No)
                     {
                         painter.end();
                     }
}

void Gestion_emission::on_pb_Ajouter_5_clicked()
{
    Emission E;
        QString text;



            E.clearTable(ui->tab_Emission);
                int id=ui->le_ID_Emission_2->text().toInt();
                E.chercheID(ui->tab_Emission,id);
}

/*void Gestion_emission::on_pb_stats_clicked()
{
    Dialog_stats stats;
    stats.setModal(true);
    stats.exec();
}*/

void Gestion_emission::on_qrcode_clicked()
{
    QDesktopServices::openUrl(QUrl("https://app.qr-code-generator.com/manage/?aftercreate=1&count=1"));
        QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png )"));
        if (QString::compare(filename,QString()) !=0)
        {
            QImage image;
            bool valid = image.load(filename);
            if(valid)
            {
                image=image.scaledToWidth(ui->lbl_image_2->width(), Qt::SmoothTransformation);
                        ui->lbl_image_2->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                //ERROR HANDLING
            }
        }

}

void Gestion_emission::on_insertimg_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
    QSqlQuery query;
          query.prepare("INSERT INTO IMAGE (IMG) "
                        "VALUES (:LOAD_FILE(filename))");
          query.bindValue(":LOAD_FILE(filename)",  filename);
          //QLabel* x = ui->imagee;
          //x->text();
          //x->(filename);


      if (QString::compare(filename,QString()) !=0)
      {
          QImage image;
          bool valid = image.load(filename);
          if(valid)
          {
              image=image.scaledToWidth(ui->imagee->width(), Qt::SmoothTransformation);
                      ui->imagee->setPixmap(QPixmap::fromImage(image));
                      query.exec();
          }
          else
          {
              //ERROR HANDLING
          }
      }
}
/*
void Gestion_emission::on_pb_stats_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}
*/

void Gestion_emission::on_pb_stats_clicked()
{
    s = new Dialog_stats();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}

QString ch="";
void Gestion_emission::update_label()  { //label arduino

    QSqlQuery query;
     QByteArray data="";
     QString mdp="";

    data=A.read_from_arduino();

     qDebug() <<  " data is " <<*data;
     if(ch.length()<11)


   {  ch=ch+data;}
     qDebug() <<  " ch is " <<ch;


    if(ch!="")
       {
        query.prepare("select * from EMISSION where ID_EMISSION='"+ch+"'");
        if(query.exec())
        {mdp=ch;
           ui->eeee->setText(ch);

         QString message ="Bienvenue ";
         QByteArray br = message.toUtf8();
         A.write_to_arduino(br);
         if(ch.length()==12)
         {
         ch=""; }
         }
        else
        {
            QString message ="donne inaccessible";
            QByteArray br = message.toUtf8();
            A.write_to_arduino(br);
            QMessageBox::critical(nullptr,QObject::tr("login failed"),
                                    QObject::tr("FAILED TO connected ..........  \n"
                                                 "acces denied \n"

                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }

       }

   /* if(ch.length()>10)
     {
     ch="";
     }
*/
    }

void Gestion_emission::on_pushButton_2_clicked()
{
    
}
