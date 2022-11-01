#include "modider_station.h"
#include "ui_modider_station.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include<QLineEdit>
#include <QLabel>
#include <QtCore>
#include <QString>
#include <QtGui>
#include<QMessageBox>
#include<QObject>
#include<QObjectData>
#include"ui_mainwindow.h"
modider_station::modider_station(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modider_station)
{
    ui->setupUi(this);
}

modider_station::~modider_station()
{
    delete ui;
}


void modider_station::on_pushButton_clicked()
{

 /*  int oldid(this->)



        QSqlQuery query;
      //  query.prepare ("update employes set ID='"+ID+"',N_STUDIO = '"+N_STUDIO+"',ADRESS = '"+ADRESS+"' where id = '"+id_res+"'");

        if(query.exec())
        {
           modider_station::on_pushButton_clicked();
            QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
        }
        else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));*/
    }





