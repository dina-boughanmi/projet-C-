#include "log_param.h"
#include "ui_log_param.h"
#include"connection.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QDebug>
#include<QtDebug>
#include<QtCore>
#include<QMovie>
#include<QWidget>
#include <QLabel>
log_param::log_param(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::log_param)
{
    ui->setupUi(this);
    QMovie* movie = new QMovie("C:/Users/user/Desktop/IMG8RES FOR QT/icons8-shield-unscreen.gif");


    if (!movie->isValid())
    {

        qDebug()<<"not valed gif";
    }

    // Play GIF
    QLabel *label_gif= ui->label_SHILD;
   label_gif->setMovie(movie);
    movie->start();
     qDebug()<<"valed gif selket ";
}

log_param::~log_param()
{
    delete ui;
}

/*
log_param :: log_param()

{
 username="";pwd="";pwd2="";
}
log_param:: log_param(QString username,QString pwd,QString pwd2)
{
    this->username=username;
    this->pwd=pwd;
    this->pwd2=pwd2;

}*/
bool log_param::   ajouter_user(QString PWD_ADMIN,QString USERNAME,  QString PWD)
{


   // PWD_ADMIN("ahmed");
    //USERNAME( ui->lineEdit_ajout_username_2->text());
     //PWD(ui->lineEdit_ajout_pwd->text());
    qDebug()<<"ajouter fonc"<<PWD_ADMIN<<USERNAME<<PWD;
       QSqlQuery query;


    query.prepare("INSERT INTO ADMIN (PWD_ADMIN, USERNAME,PWD) VALUES (:PWD_ADMIN,:USERNAME,:PWD)");
   query.bindValue(":PWD_ADMIN", PWD_ADMIN);
   query.bindValue(":USERNAME", USERNAME );
   query.bindValue(":PWD", PWD);
    return query.exec();
}
bool log_param:: supprimer_user(QString USERNAME )
{



        QSqlQuery query;
        query.prepare("DELETE FROM ADMIN WHERE USERNAME= :USERNAME");
             query.bindValue(":USERNAME",USERNAME);

          return query.exec();



}
bool  log_param:: modifier_user( QString USERNAME, QString PWD,  QString PWD2)
{



    QSqlQuery query;
    qDebug()<<"modifer  user "<<USERNAME<<PWD<<PWD2;
    query.prepare ("update ADMIN set PWD = '"+PWD2+"' where USERNAME = '"+USERNAME+"' AND  PWD = '"+PWD+"'   " );
    return query.exec();
}




void log_param::on_pushButton_ajout_user_clicked()
{



    QString PWD_ADMIN =ui->lineEdit_ajout_pwd_admin->text();
    QString USERNAME = ui->lineEdit_ajout_username_2->text();
   QString PWD = ui->lineEdit_ajout_pwd->text();
    if (PWD_ADMIN=="ahmed"){


 //  log_param   log_param(PWD_ADMIN,USERNAME,PWD);
    bool TEST= ajouter_user(PWD_ADMIN,USERNAME,PWD);
    if(TEST)
 {
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout  successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
 {   QMessageBox::critical(nullptr, QObject::tr("ajout failed "),
                QObject::tr("connection failed :.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}

}
}

void log_param::on_pushButton_supp_user_clicked()
{
    QString USERNAME =ui->lineEdit_supp_username->text();
    QString PWD_admin =ui->lineEdit_supp_pwdadmin->text();


    if (PWD_admin=="ahmed")
    {


    bool  TEST=supprimer_user(USERNAME);


    if(TEST)
 {


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppresstion  successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
 {   QMessageBox::critical(nullptr, QObject::tr("suppresstion failed "),
                QObject::tr("connection failed :.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
}
}








void log_param::on_pushButton_modiferuser_clicked()
{
    QString USERNAME(ui->lineEdit_modifer_username->text());
    QString PWD2(ui->lineEdit_modifer_newpwd->text());
    QString PWD (ui->lineEdit_modifer_oldpwd_admin->text());

  bool TEST=modifier_user(USERNAME,PWD,PWD2) ;
    if(TEST)
    {
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully"));
    }
    else{ QMessageBox::critical(this,tr("Edit"),tr("Update Failed !")); }
}
/*QSqlQueryModel *  log_param :: rechercher_user(QString  USERNAME   ,QString PWD )

{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("select * from ADMIN where USERNAME=:USERNAME OR PWD=:PWD");
    qry->bindValue(":USERNAME",USERNAME);
    qry->bindValue(":PWD",PWD);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

*/














