#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qdialog.h"
#include "station.h"
#include <QLabel>
#include <QtCore>
#include <QString>
#include <QtGui>
#include <QLineEdit>
#include <QMessageBox>
#include <QApplication>
#include<QLineEdit>
#include<QPushButton>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QtDebug>
#include"studio.h"
#include<QFile>
#include<QPdfWriter>
 #include<QFileDialog>
#include<QPainter>
#include <QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QTextDocument>
#include<QTextStream>
#include <QPrinter>
#include<QWidget>
#include<QStackedWidget>
#include<QInputDialog>
#include<QApplication>
#include"QWizard"
#include"QWizardPage"
#include"qwizard.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_N_studio->setValidator( new QIntValidator(0, 99999999, this));

    ui->tableView->setModel(STATION.afficher_station());
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setModel(STUDIO.afficher_studio());
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_valider_station_clicked()
{
    int id=ui->le_id->text().toInt();
    int N_studio=ui->le_N_studio->text().toInt();
    QString adress=ui->le_adress->text();
    station STATION(id,N_studio,adress);
    bool TEST= STATION.ajouter_station();
    if(TEST)
 {
      ui->tableView->setModel(STATION.afficher_station());
       ui->tableView_2->setModel(STUDIO.afficher_studio());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout station successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
 {   QMessageBox::critical(nullptr, QObject::tr("ajout failed "),
                QObject::tr("connection failed :.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_clicked()//SUPPRISTION D'UNE STATION
{
     int id=ui->lineEdit_4->text().toInt();
     bool TEST=STATION.supprimer_station(id);


         if(TEST)
      {
           ui->tableView->setModel(STATION.afficher_station());
            ui->tableView_2->setModel(STUDIO.afficher_studio());
         QMessageBox::information(nullptr, QObject::tr("ok"),
                     QObject::tr("suppresstion station successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
      {   QMessageBox::critical(nullptr, QObject::tr("suppresstion failed "),
                     QObject::tr("connection failed :.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}
     }

void MainWindow::on_pushButton_2_clicked()
{
    int id_s=ui->lineEdit_12->text().toInt();
    int capacite=ui->lineEdit_9->text().toInt();
    int id  =ui->lineEdit_10->text().toInt();
    QString reservationfrom=ui->dateTimeEdit->text();
    QString reservationto = ui->dateTimeEdit_2->text();
    studio STUDIO (id_s,id,capacite,reservationfrom,reservationto);
    bool TEST= STUDIO.ajouter_studio();
    if(TEST)
 {

        ui->tableView->setModel(STATION.afficher_station());
        ui->tableView_2->setModel(STUDIO.afficher_studio());
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout  successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
 {   QMessageBox::critical(nullptr, QObject::tr("ajout failed "),
                QObject::tr("connection failed :.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_17->text().toInt();
    int id_s=ui->lineEdit->text().toInt();
    bool TEST=STUDIO.supprimer_studio(id,id_s);


        if(TEST)
     {
            ui->tableView->setModel(STATION.afficher_station());
            ui->tableView_2->setModel(STUDIO.afficher_studio());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppresstion  successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
     {   QMessageBox::critical(nullptr, QObject::tr("suppresstion failed "),
                    QObject::tr("connection failed :.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);



        QSqlQuery q;
        q.prepare("SELECT * FROM STATION ");
        q.exec();
        QString pdf="<br>   <h1  style='color:red'>LISTE DES STATION  <br></h1>\n <br> <table>  <tr>  <th>IDENTTIFIANT </th>  <th>NOMBRE DES STATION </th> <th> ADRESS </th>     </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>     <td>" + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"</td>      " ;

        }
        QTextDocument doc;
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);



        QSqlQuery q;
        q.prepare("SELECT * FROM STUDIO ");
        q.exec();
        QString pdf="<br>   <h1  style='color:red'>LISTE DES STUDIO  <br></h1>\n <br> <table>  <tr>  <th>IDENTTIFIANT_STATION </th> <th>IDENTTIFIANT_STUDIO </th> <th>NOMBRE DES STATION </th> <th> CAPACITE </th> <th> RESERVED_FROM </th>   <th> RESERVED_TO </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>     <td>" + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"</td>  <td>" +q.value(3).toString() +"</td>  <td>" +q.value(4).toString() +"</td>     " ;

        }
        QTextDocument doc;
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}



void MainWindow::on_pushButton_6_clicked()
{
  QString ID(ui->lineEdit_2->text());
   QString NEW_ID(ui->lineEdit_3->text());
   QString NEW_NSTUDIO(ui->lineEdit_5->text());
   QString ADRESS(ui->lineEdit_6->text());
qDebug()<<"modifer"<<ID<<NEW_ID<<NEW_NSTUDIO<<ADRESS;
   QSqlQuery query;
   query.prepare ("update STATION set ID='"+NEW_ID+"',N_STUDIO = '"+NEW_NSTUDIO+"',ADRESS = '"+ADRESS+"' where id = '"+ID+"'");

   if(query.exec())
   {

       ui->tableView->setModel(STATION.afficher_station());
       ui->tableView_2->setModel(STUDIO.afficher_studio());
       QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
   }
   else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));

}

void MainWindow::on_pushButton_7_clicked()
{
    QString ID_station(ui->le_m_old_studio->text());
     QString ID_STUDIO(ui->le_m_id_station->text());
     QString CAPACITE(ui->le_m_capasi->text());
     QString new_id(ui->le_mstudio_id_new->text());
     QString RESERVATIONFROM(ui->dateTimeEdit_3->text());
     QString RESERVATIONTO(ui->dateTimeEdit_4->text());
  qDebug()<<"modifer"<<ID_station<<ID_STUDIO<<CAPACITE<<new_id<<RESERVATIONFROM<<RESERVATIONTO;
     QSqlQuery query;
     query.prepare ("update STUDIO set ID='"+new_id+"', CAPACITE = '"+CAPACITE+"',RESERVATIONFROM = '"+RESERVATIONFROM+"',RESERVATIONTO = '"+RESERVATIONTO+"' where ID = '"+ID_STUDIO+"' AND ID_STUDIO='"+ID_station+"' " );

     if(query.exec())
     {

         ui->tableView->setModel(STATION.afficher_station());
         ui->tableView_2->setModel(STUDIO.afficher_studio());
         QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
     }
     else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->tableView->setModel(STATION.afficher_station());
    ui->tableView_2->setModel(STUDIO.afficher_studio());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tableView->setModel(STATION.afficher_station());
    ui->tableView_2->setModel(STUDIO.afficher_studio());
}
