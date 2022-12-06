#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicite1.h"
//#include "arduino.h"
#include<QString>
#include "connexion.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QtDebug>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include <QPrinter>
#include <QSqlQueryModel>
#include <QPixmap>
#include<QDirModel>
#include <QtSvg/QSvgRenderer>
#include <QFile>
#include <QFileDialog>
#include <fstream>
#include <QTextStream>
#include <QtCharts>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDesktopWidget>
#include <QSettings>
#include <QDataStream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
     , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcd->display("-------");


       /* bool arduino_is_available = false;
            QString arduino_uno_port_name;
            //
            //  For each available serial port
            foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
                //  check if the serialport has both a product identifier and a vendor identifier
                if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
                    //  check if the product ID and the vendor ID match those of the arduino uno
                    if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                            && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                        arduino_is_available = true; //    arduino uno is available on this port
                        arduino_uno_port_name = serialPortInfo.portName();
                    }
                }
            }


             *  Open and configure the arduino port if available

            if(arduino_is_available){
                qDebug() << "Found the arduino port...\n";
                arduino->setPortName(arduino_uno_port_name);
                arduino->open(QSerialPort::ReadOnly);
                arduino->setBaudRate(QSerialPort::Baud9600);
                arduino->setDataBits(QSerialPort::Data8);
                arduino->setFlowControl(QSerialPort::NoFlowControl);
                arduino->setParity(QSerialPort::NoParity);
                arduino->setStopBits(QSerialPort::OneStop);
                QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
            }else{
                qDebug() << "Couldn't find the correct port for the arduino.\n";
                QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
            }*/

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

    ui->lineEdit_2->setInputMask("AAAAAAAAAAAAAAAAAAAAAAA");
    ui->lineEdit_3->setInputMask("AAAAAAAAAAAAAAAAAAAAAAA");
    ui->linda->setModel(Etmp.afficher());

}

MainWindow::~MainWindow()
{
    /*if(arduino->isOpen()){
            arduino->close(); //    Close the serial port if it's open.
        }*/
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{

    int id_pub=ui->lineEdit->text().toInt();
    QString nom_pub= ui->lineEdit_2->text();
    QString nom_sponsor=ui->lineEdit_3->text();
    QString categorie=ui->l_categorie->text();
    publicite1 p(id_pub,nom_pub,nom_sponsor,categorie);

       bool test=p.ajouter();

      ui->linda->setModel(p.afficher());

    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok "),
        QObject::tr("ajout effectué\n"
                     "click Cancel to exit."), QMessageBox::Cancel);

 }
    else
        QMessageBox:: critical(nullptr, QObject ::tr("not ok"),
                QObject::tr("ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox ::Cancel);
}

void MainWindow::readSerial()
{

     //readyRead() doesn't guarantee that the entire message will be received all at once.
     //The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature value.


    QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator

    //  Check to see if there less than 3 tokens in buffer_split.
    //  If there are at least 3 then this means there were 2 commas,
    //  means there is a parsed temperature value as the second token (between 2 commas)
    if(buffer_split.length() < 3){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        // the second element of buffer_split is parsed correctly, update the temperature value on temp_lcdNumber
        serialBuffer = "";
        qDebug() << buffer_split << "\n";
        parsed_data = buffer_split[1];
        temperature_value = (9/5.0) * (parsed_data.toDouble()) + 32; // convert to fahrenheit
        qDebug() << "Temperature: " << temperature_value << "\n";
        parsed_data = QString::number(temperature_value, 'g', 4); // format precision of temperature_value to 4 digits or fewer
        MainWindow::updateTemperature(parsed_data);
    }

}

void MainWindow::updateTemperature(QString sensor_reading)
{
    //  update the value displayed on the lcdNumber
    ui->lcd->display(sensor_reading);
}




void MainWindow::on_supprimer_clicked()
{
    int id =ui->lineEdit_13->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)

  {
        ui->linda->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok "),
        QObject::tr("suppression  effectuée\n"
                     "click Cancel to exit."), QMessageBox::Cancel);

 }
 else
        QMessageBox:: critical(nullptr, QObject ::tr("not ok"),
                QObject::tr("suppression  non effectuée.\n"
                            "Click Cancel to exit."), QMessageBox ::Cancel);
}



void MainWindow::on_pushButton_6_clicked() //modifier
{

    int id_pub=ui->lineEdit->text().toInt();
    QString nom_pub= ui->lineEdit_2->text();
    QString nom_sponsor=ui->lineEdit_3->text();
    QString categorie=ui->label_6->text();

    publicite1 P(id_pub,nom_pub,nom_sponsor,categorie);
    bool test=P.modifier();
    if (test)
     { ui->linda->setModel(Etmp.afficher());
     QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectue\n ""click cancel"),QMessageBox::Cancel);

     }
     else
     {QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non fonctional\n""click to cancel"),QMessageBox::Cancel);}
}



/*publicite1 a;
        QString text;
            a.clearTable(ui->linda);
                int ID_A=ui->leid_pub->text().toInt();
                a.chercheID(ui->linda,ID_A);*/  //CHERCHERID



void MainWindow::on_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/lenovo/Desktop/publicite/Liste.pdf");

            QPainter painter(&pdf);

            int i = 4000;

            painter.drawText(3000,1500,"LISTE DES publicités");
            painter.setPen(Qt::blue);
            painter.setFont(QFont("Arial", 50));
            painter.drawRect(2700,200,6300,2600);
            painter.drawRect(0,3000,9600,500);
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(300,3300,"id_pub");
            painter.drawText(2300,3300,"nom_pub");
            painter.drawText(4300,3300,"nom_sponsor");
            painter.drawText(6000,3300,"categorie");
            QSqlQuery query;

            query.prepare("select * from publicite");
            query.exec();
            while (query.next())
            {
                painter.drawText(300,i,query.value(0).toString());
                painter.drawText(2300,i,query.value(1).toString());
                painter.drawText(4300,i,query.value(2).toString());
                painter.drawText(6000,i,query.value(3).toString());
                i = i +500;
            }
            int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/lenovo/Desktop/publicite/Liste.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }
}


void MainWindow::on_tri_clicked()
{
    publicite1 p;
    ui->linda->setModel(p.tri());
}

void MainWindow::on_RJC_clicked()
{
     publicite1 p;
    ui->tab_ga->setModel(p.jeux_concour());

}



void MainWindow::on_rechercher_clicked()
{
    publicite1 p;
        int id ;
        id= ui->leid_pub->text().toInt();
        ui->linda->setModel(p.Rechercherid(id));
}

void MainWindow::on_temperature_clicked()
{
   // readSerial();
    //serialData=A1.read_from_arduino();

    ui->lcd->display(serialData);
}

void MainWindow::update_label()
{
    if (serialData.length()>=6)
        serialData="";
    serialData+=A1.read_from_arduino();
qDebug() << serialData;

}
 void MainWindow::on_pushPlay_clicked()
{
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);

    if (ui->RadB_Pack1->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/lenovo/Downloads/test.mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }
    if (ui->RadB_Pack2->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/lenovo/Downloads/test.mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }
    if (ui->RadB_Pack3->isChecked())
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/lenovo/Downloads/test.mp4"));
        player->setVideoOutput(ui->VideoInterface);
    }

    vw->show();
    player->play();
}

 void MainWindow::on_pushStop_clicked()
{
    player->stop();
    vw->close();
}


void MainWindow::on_stat_clicked()

{
    int regio;
   int non_regio;
   int total;
   QString regionale;
   QString non_regionale;
   QSqlQuery q;

   q.prepare("SELECT COUNT(*) FROM PUBLICITE where CATEGORIE='nourriture'");
   q.exec();
   q.first() ;
   regio=(q.value(0).toInt());

  q.prepare("SELECT COUNT(*) FROM PUBLICITE where CATEGORIE='sport'");
   q.exec();
   q.first() ;
   non_regio=(q.value(0).toInt());

   q.prepare("SELECT COUNT(*) FROM PUBLICITE ");
   q.exec();
   q.first() ;
   total=(q.value(0).toInt());

   regio=((double)regio/(double)total)*100;
   non_regio=100-regio;

   regionale= QString::number(regio);
   non_regionale=QString::number(non_regio);
   QString tot=QString::number(total);

   QPieSeries *series;
    series= new  QPieSeries();
    series->append("Nourriture"+regionale+"%",regio);
    series->append("Sport"+non_regionale+"%",non_regio);
    series->append("Total"+tot+"",total);

    QPieSlice *slice0 = series->slices().at(0);
     slice0->setLabelVisible();

     QPieSlice *slice1 = series->slices().at(1);
        slice1->setExploded();
        slice1->setLabelVisible();
        slice1->setPen(QPen(Qt::green, 3));
        slice1->setBrush(Qt::darkYellow);

         QChart *chart = new QChart();
         chart->addSeries(series);
         chart->setTitle("Statistique des publicites ");
         chart->legend()->show();
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         ui->verticalLayout_2->addWidget(chartView);
    show();

    ui->verticalLayout_2->removeWidget(chartView);

}




