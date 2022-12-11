#include "Gestion_de_invite.h"
#include "ui_Gestion_de_invite.h"
#include"invite.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QDesktopServices>
#include<QFileDialog>
#include <QPushButton>
#include "connection.h"
#include<QtPrintSupport/QPrinter>
#include<QTextDocument>
#include<QPdfWriter>
#include<QPainter>
#include "dialog_stats.h"
#include "exportexcelobject.h"
#include "messengerclient.h"
#include<QDialog>
#include"Atelier_Arduino_v2/arduino.h"
#include"QDebug"
#include"menu.h"

Gestion_de_invite::Gestion_de_invite(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_de_invite)
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
     //ui->listView->setModel(etmp.afficherc());

     int ret=A.connect_arduino();
     switch(ret){
     case(0) :qDebug ()<<"arduino is avaible and connected to :" <<A.getarduino_port_name();
     break ;
     case(1) :qDebug() <<"arduino is available but not connected to :" <<A.getarduino_port_name();
         break ;
     case(-1):qDebug() <<"arduino is not available " ;
     }
     QObject ::connect(A.getserial(), SIGNAL (readyRead()) ,this,SLOT(update_RFID()));


}
void Gestion_de_invite::updatestring(){

    data=A.read_from_arduino();
    if(data=="v")
    {QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("authorization est valide\n ""click cancel"),QMessageBox::Cancel);
    //ui->label_14->setText("authorization est valide");
    qDebug()<<data;
    }
    if(data=="n")
    {
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("authorization est non valide\n ""click cancel"),QMessageBox::Cancel);
        //ui->label_14->setText("authorization est non valide");
         qDebug()<<data;
    }


}
Gestion_de_invite::~Gestion_de_invite()
{
    delete ui;
}


void Gestion_de_invite::on_pushButton_clicked()
{

    QString NOM=ui->lineEdit->text();
    QString PRENOM=ui->lineEdit_2->text();
    int CIN=ui->lineEdit_3->text().toInt();
    int AGE=ui->lineEdit_4->text().toInt();
    int NUM_TEL=ui->lineEdit_5->text().toInt();
    QString RFID=ui->eeee->text();
    invite i(NOM,PRENOM,CIN,AGE,NUM_TEL,RFID);

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



void Gestion_de_invite::on_pushbutton_supp_clicked()
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


void Gestion_de_invite::on_pushButton_15_clicked()
{
    QString NOM=ui->lineEdit_10->text();
    QString PRENOM=ui->lineEdit_6->text();
    int CIN=ui->lineEdit_mc->text().toInt();
    int AGE=ui->lineEdit_11->text().toInt();
    int NUM_TEL=ui->lineEdit_8->text().toInt();
    QString RFID=ui->eeee->text();

    invite i(NOM,PRENOM,CIN,AGE,NUM_TEL,RFID);



    bool test=i.modifier(CIN);
    if (test)
    { ui->tableView->setModel(etmp.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);

    }
    else
    {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);}



}


void Gestion_de_invite::on_pushButton_16_clicked()
{
    QPdfWriter pdf("C:/Users/user/Documents/projet-C-/Liste.pdf");

                 QPainter painter(&pdf);

                 int i = 4000;


                 painter.drawText(3000,1500,"LISTE DES INVITE");
                 painter.setPen(Qt::blue);
                 painter.setFont(QFont("Arial", 50));
                 painter.drawRect(2700,200,6300,2600);
                 painter.setPen(Qt::black);


                 QSqlQuery query;
                 query.prepare("select * from invite");
                 query.exec();
                 while (query.next())

                 {
                     painter.setPen(Qt::red);
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Arial", 9));
                     painter.drawRect(0,1000+i,3000,2000);
                     painter.drawText(0,1300+i,"NOM");
                     painter.drawText(0,1600+i,"PRENOM");
                     painter.drawText(0,1900+i,"CIN");
                     painter.drawText(0,2200+i,"age");
                     painter.drawText(0,2500+i,"NUM_TEL");
                     painter.drawText(1000,1300+i,query.value(0).toString());
                     painter.drawText(1000,1600+i,query.value(1).toString());
                     painter.drawText(1000,1900+i,query.value(2).toString());
                     painter.drawText(1000,2200+i,query.value(3).toString());
                     painter.drawText(1000,2500+i,query.value(4).toString());
                     i = i +3000;
                 }

                 int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                 if (reponse == QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/Documents/projet-C-/Liste.pdf"));

                     painter.end();
                 }
                 if (reponse == QMessageBox::No)
                 {
                     painter.end();
                 }
}

void Gestion_de_invite::on_pushButton_13_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(etmp.tri_age());
}

void Gestion_de_invite::on_pushButton_11_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(etmp.tri_cin());
}

void Gestion_de_invite::on_pushButton_12_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
         QObject::tr("tri effectué.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(etmp.tri_nom());
}

void Gestion_de_invite::on_pushButton_17_clicked()
{
    invite i;
    QString text;



        i.clearTable(ui->tableView);
            int CIN=ui->lineEdit_7->text().toInt();
            i.chercheID(ui->tableView,CIN);

}

void Gestion_de_invite::on_pushButton_18_clicked()
{
    Dialog_stats stats;
    stats.setModal(true);
    stats.exec();
}
//excel
void Gestion_de_invite::on_pushButton_19_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "INVITE", ui->tableView);

    //colums to export
    obj.addField(0, "NOM", "char(20)");
    obj.addField(1, "PRENOM", "char(20)");
    obj.addField(2, "CIN", "char(20)");
    obj.addField(3, "AGE", "char(20)");
    obj.addField(4, "NUM_TEL", "char(20)");
    obj.addField(5, "RFID", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}
void Gestion_de_invite::closeEvent(QCloseEvent *event)
{
        p.kill();
        qApp->exit();
}

void Gestion_de_invite::on_pushButton_20_clicked()
{

    MessengerClient MS;
    p.start("MessengerLANServer.exe");

MS.exec();}

void Gestion_de_invite::update_RFID()
{ 
    QSqlQuery query;
    QByteArray data="";
    data=A.read_from_arduino();
    qDebug() <<  " data is " <<data;
    RFID=RFID+data;
    qDebug() <<  " ch is " <<RFID;
    if(RFID!="" && RFID.length()==11)
    {
        query.prepare("select * from invite where RFID='"+RFID+"'");
        if(query.exec())
        {
            if (query.next())
            {
                ui->eeee->setText(RFID);
                qDebug() <<  " RFIDworking is " <<RFID;
                QString message ="1";

                QByteArray br = message.toUtf8();
                A.write_to_arduino(br);
                ui->eeee_2->setText("RFID Found");
            }
            else
            { ui->eeee->setText(RFID);
                QString message ="2";
                QByteArray br = message.toUtf8();

                A.write_to_arduino(br);
                ui->eeee_2->setText("RFID Failed");
            }
        }
    }
    if(RFID.length()==11)
    {

        RFID="";
    }

}




void Gestion_de_invite::on_quittergestioninviter_clicked()
{

    menu *w =new menu;
    w->show();
    this->hide();

}
