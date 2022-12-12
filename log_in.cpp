#include "log_in.h"
#include "ui_log_in.h"
#include<QMainWindow>
#include<QMovie>
#include<QWidget>
#include <QLabel>
#include"log_param.h"
#include"Atelier_Arduino_v2/arduino.h"
#include"gestion_studio.h"
#include"menu.h"
log_in::log_in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
  //ardouino
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
    //DAate systeme
        QDateTime Date_p=QDateTime::currentDateTime();
        QString Date_txt=Date_p.toString("dddd dd MMMM yyyy");
        ui->label_date->setText(Date_txt);
    //gif
        QMovie* movie = new QMovie("C:/Users/user/Desktop/IMG8RES FOR QT/icons8-fingerprint-scan-unscreen.gif");
    if (!movie->isValid())
    {

        qDebug()<<"not valed gif";
    }
    // Play GIF
    QLabel *label_gif= ui->label_gif;
   label_gif->setMovie(movie);
    movie->start();
     qDebug()<<"valed gif selket ";
}

log_in::~log_in()
{
    delete ui;
}

void log_in::on_pushButton_clicked()
{

 menu  *w =new  menu  ;
    QString USERNAME(ui->lineEdit_loginusername->text());
     QString PWD(ui->lineEdit_loginpwd->text());
     bool verif_recherche=rechercher_user(USERNAME,PWD);

   if (verif_recherche )
   {
             A.write_to_arduino("0"); /*envoyer 0 à arduino*/
       qDebug()<<"write  to ardouino "<<A.write_to_arduino("0");
 QMessageBox::information(this,tr("Edit"),tr("welcome to on air"));

 QMessageBox::information(this, QObject::tr("database is open"),
             QObject::tr("connection successful.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

     w->show();
     A.close_arduino();
     //this->destroy();
     this->close();
   }else
   {   trys++;
       int re=3-trys;
 QString numbre =  QString::number(re);

       if(trys==3){
           qDebug() << "Hello arduino is working";
       A.write_to_arduino("1"); /*envoyer 1 à arduino*/

}
       QString rest=re!=0?"Failed to log in ! you have  "+numbre+"  tries to rentre correctly\n or the alarme will set ON ":"YOU HAVE 10 SECONDS TO ENTER THE RIGHT PASSWORD";

          QMessageBox::critical(this,tr("on Air"),rest);

}
}

void log_in::on_pushButton_2_clicked()
{
  log_param *log= new log_param ;
     log->show();

}
bool  log_in:: rechercher_user(QString  USERNAME ,QString PWD )

{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from ADMIN where USERNAME=:USERNAME AND PWD=:PWD");
    qry->bindValue(":USERNAME",USERNAME);
    qry->bindValue(":PWD",PWD);
    qry->exec();
    qDebug()<<"log in recherche"<<USERNAME<<PWD;
    qDebug()<<"qry:adress="<<qry;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    qDebug()<<"model:"<<model;
    if (model->rowCount()==0)
    {return false;}else {
        return true;
}
}
