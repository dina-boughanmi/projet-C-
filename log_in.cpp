#include "log_in.h"
#include "ui_log_in.h"
#include<QMainWindow>
#include<QMovie>
#include<QWidget>
#include <QLabel>
#include"log_param.h"

#include"mainwindow.h"
log_in::log_in(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);

    //Timer
//         QTimer *timer_p=new QTimer(ui->label_time);
  //       connect(timer_p, SIGNAL(timeout()), ui->label_time,SLOT(showTime()));
    //     timer_p->start(1000);
      //   ui->label_time->setText(timer_p);


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

  MainWindow *w =new MainWindow  ;
    QString USERNAME(ui->lineEdit_loginusername->text());
     QString PWD(ui->lineEdit_loginpwd->text());
     bool verif_recherche=rechercher_user(USERNAME,PWD);
   if (verif_recherche )
   {
 QMessageBox::information(this,tr("Edit"),tr("welcome to on air"));

 QMessageBox::information(this, QObject::tr("database is open"),
             QObject::tr("connection successful.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);

     w->show();
   }else {
QMessageBox::critical(this,tr("on Air"),tr(" Failed to log in !"));
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
