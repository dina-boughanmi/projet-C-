#include "gestion_studio.h"
#include "ui_gestion_studio.h"
#include"qdialog.h"
#include<stat2.h>
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

#include<QInputDialog>
#include<QApplication>

#include "statistique.h"

#include"menu.h"
#include <QtCharts>

  using namespace QtCharts;

Gestion_Studio::Gestion_Studio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_Studio)
{
    ui->setupUi(this);
    //controle de saisie
        ui->lineEdit_ajout_id->setValidator( new QIntValidator(0, 99999999, this));
        ui->le_modifer_id_studio->setValidator( new QIntValidator(0, 99999999, this));
        ui->lineEdit_ajout_capasiti->setValidator( new QIntValidator(0, 40, this));
        ui->le_modifer_capasi->setValidator(new QIntValidator(0,40,this));
        ui->lineEdit_recherche->setValidator(new QIntValidator(0,99999999,this));
        ui->lineEdit_supp->setValidator(new QIntValidator(0,99999999,this));


   // update affiche
    ui->tableView_2->setModel(STUDIO.afficher_studio());
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_6->setModel(STUDIO.afficher_studio());
    ui->tableView_6->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_6->setSelectionMode(QAbstractItemView::SingleSelection);
    //mail parte
    client_ = NULL;
      // Connect all signals and slots
    connect(ui->pushButtonSend_6, SIGNAL(clicked(bool)), this, SLOT(sendEmail()));
    connect(ui->pushButtonClear_6, SIGNAL(clicked(bool)), this, SLOT(clearFields()));//

    QMovie* movie = new QMovie("C:/Users/user/Desktop/IMG8RES FOR QT/icons8-communication-unscreen.gif");


if (!movie->isValid())
{

    qDebug()<<"not valed gif";
}

// Play GIF
QLabel *label_gif= ui->label_gif_mail;
label_gif->setMovie(movie);
movie->start();

QMovie* mov = new QMovie("C:/Users/user/Desktop/IMG8RES FOR QT/icons8-tools-unscreen.gif");


if (!movie->isValid())
{

qDebug()<<"not valed gif";
}

// Play GIF
QLabel *label_p= ui->label_param;
label_p->setMovie(mov);
mov->start();




}

Gestion_Studio::~Gestion_Studio()
{
      client_->deleteLater();
    delete ui;
}
 void Gestion_Studio::update()
{    ui->tableView_2->setModel(STUDIO.afficher_studio());
     ui->tableView_6->setModel(STUDIO.afficher_studio());
}

void Gestion_Studio::on_pushButton_2_clicked() //ajout
{
   // int id_s=ui->lineEdit_12->text().toInt();
    int capacite=ui->lineEdit_ajout_capasiti->text().toInt();
    int id  =ui->lineEdit_ajout_id->text().toInt();
    QString reservationfrom=ui->dateTimeEdit_ajout1->text();
    QString reservationto = ui->dateTimeEdit_ajout2->text();
    studio STUDIO (id,capacite,reservationfrom,reservationto);
    bool TEST= STUDIO.ajouter_studio();
    if(TEST)
 {


        ui->tableView_6->setModel(STUDIO.afficher_studio());
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

void Gestion_Studio::on_pushButton_5_clicked()//suppresstion
{
    //int id=ui->lineEdit_17->text().toInt();
  int id=ui->lineEdit_supp->text().toInt();
    bool TEST=STUDIO.supprimer_studio(id);


        if(TEST)
     {

            ui->tableView_6->setModel(STUDIO.afficher_studio());
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


void Gestion_Studio::on_pushButton_3_clicked()//pdf
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);//pour traiter le ficher avant lecriteur
        printer.setOutputFormat(QPrinter::PdfFormat);//
        printer.setPaperSize(QPrinter::A4);//
        printer.setOutputFileName(fileName);



        QSqlQuery q;
        q.prepare("SELECT * FROM STUDIO ");
        q.exec();
        QString pdf="<br>   <img src='C:/Users/user/Desktop/IMG8RES FOR QT/onair.png' height='200' width='200'/> <h1  style='color:bleu'>LISTE DES STUDIO  <br></h1>\n <br> <table>  <tr>   <th>IDENTTIFIANT_STUDIO </th> <th>NOMBRE DES STATION </th> <th> CAPACITE </th> <th> RESERVED_FROM </th>   <th> RESERVED_TO </th>  </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"</td>    <td>" + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"</td>   <td>" +q.value(3).toString() +"</td>   <td>" +q.value(4).toString() +"</td>     " ;

        }
        QTextDocument doc;
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}


void Gestion_Studio::on_pushButton_7_clicked()//update
{
//    int ID_station(ui->le_m_old_studio->text().toInt());
     int ID_STUDIO(ui->le_modifer_id_studio->text().toInt());
     int CAPACITE(ui->le_modifer_capasi->text().toInt());

     QString RESERVATIONFROM(ui->dateTimeEdit_modifer1->text());
     QString RESERVATIONTO(ui->dateTimeEdit_modifer2->text());
  qDebug()<<"modifer on main   "<<ID_STUDIO<<CAPACITE<<RESERVATIONFROM<<RESERVATIONTO;
   bool TEST=STUDIO.modifier_studio(   ID_STUDIO,   CAPACITE,    RESERVATIONFROM,   RESERVATIONTO) ;
 qDebug()<<"modifer"<<TEST;
     if(TEST)
     {

          ui->tableView_6->setModel(STUDIO.afficher_studio());
         ui->tableView_2->setModel(STUDIO.afficher_studio());
         QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
     }
     else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}

void Gestion_Studio::on_pushButton_9_clicked()//affich
{

    ui->tableView_2->setModel(STUDIO.afficher_studio());
}

void Gestion_Studio::on_pushButton_8_clicked()//affich
{

    ui->tableView_2->setModel(STUDIO.afficher_studio());
}

void Gestion_Studio::on_tabwidget_currentChanged(int index)
{


    if (index==2)
    {
            ui->tableView_2->setModel(STUDIO.afficher_studio());
    }




}

Email Gestion_Studio::createEmail()
{
    // Create the credentials EmailAddress
    EmailAddress credentials(ui->lineEditEmailCredentials_6->text(),
                             ui->lineEditPasswordCredentials_6->text());

    // Create the from EmailAddress
    EmailAddress from(ui->lineEditEmailFrom_6->text());

    // Create the to EmailAddress
    EmailAddress to(ui->lineEditEmailTo_6->text());

    // Create the email
    Email email(credentials,
                from,
                to,
                ui->lineEditSubject_6->text(),
                ui->textEditContent_6->toPlainText());

    return email;
}
void Gestion_Studio::sendEmail()
{
    // Create the email object
    Email email = createEmail();

    // Create the SMTPClient
    client_ = new SMTPClient(ui->lineEditHost_6->text(),
                             ui->spinBoxPort_6->value());

    // Connection used to receive the results
    connect(client_, SIGNAL(status(Status::e, QString)),
            this, SLOT(onStatus(Status::e, QString)), Qt::UniqueConnection);

    // Try to send the email
    client_->sendEmail(email);
}
void Gestion_Studio::clearFields()//clearlineedit
{
    ui->lineEditEmailCredentials_6->clear();
    ui->lineEditPasswordCredentials_6->clear();
    ui->lineEditEmailFrom_6->clear();
    ui->lineEditEmailTo_6->clear();
    ui->lineEditSubject_6->clear();
    ui->textEditContent_6->clear();
}
void Gestion_Studio::onStatus(Status::e status, QString errorMessage)//mail status
{
    // Show a message based on the Status
    switch (status)
    {
    case Status::Success:
        QMessageBox::information(NULL, tr("SMTPClient"), tr("Message successfully sent!"));
        break;
    case Status::Failed:
    {
        QMessageBox::warning(NULL, tr("SMTPClient"), tr("Could not send the message!"));
        qCritical() << errorMessage;
    }
        break;
    default:
        break;
    }

    // Delete the client pointer
    client_->deleteLater();
}




void Gestion_Studio::on_checkBox_3_stateChanged(int arg1)//tri
{   //affichage desendant id_studio

   if(arg1)
{
    ui->tableView_2->setModel(STUDIO.afficherdown_id_studio());

   }
}

void Gestion_Studio::on_checkBox_2_stateChanged(int arg2)//tri
{
    //afficher  desendeant id station
    if (arg2){}
    //ui->tableView_2->setModel(STUDIO.afficherdown_id_station());}

}

void Gestion_Studio::on_checkBox_stateChanged(int arg3)//tri
{
    //afficher desendent par capasite
    if(arg3){
    ui->tableView_2->setModel(STUDIO.afficherdown_capasite());}
}

void Gestion_Studio::on_pushButton_clicked()//recherch
{
    QString texte=ui->lineEdit_recherche->text();
    QSqlQueryModel *verif_recherche=STUDIO.rechercher_id_studio_or_capasite(texte);
    if (verif_recherche !=nullptr){ui->tableView_2->setModel(verif_recherche);}
}


void Gestion_Studio::on_pushButton_4_clicked()
{

statistique();

}

void Gestion_Studio::on_modiferbotton_clicked()
{
    int ID_STUDIO(ui->le_modifer_id_studio->text().toInt());
    int CAPACITE(ui->le_modifer_capasi->text().toInt());

    QString RESERVATIONFROM(ui->dateTimeEdit_modifer1->text());
    QString RESERVATIONTO(ui->dateTimeEdit_modifer2->text());
 qDebug()<<"modifer on main   "<<ID_STUDIO<<CAPACITE<<RESERVATIONFROM<<RESERVATIONTO;
  bool TEST=STUDIO.modifier_studio(   ID_STUDIO,   CAPACITE,    RESERVATIONFROM,   RESERVATIONTO) ;
qDebug()<<"modifer"<<TEST;
    if(TEST)
    {


        ui->tableView_2->setModel(STUDIO.afficher_studio());
           ui->tableView_6->setModel(STUDIO.afficher_studio());
        QMessageBox::information(this,tr("Edit"),tr("Updated Successfully, Press 'Actualiser' to Apply changes !"));
    }
    else QMessageBox::critical(this,tr("Edit"),tr("Update Failed !"));
}

void Gestion_Studio::on_pushButton_29_clicked()
{
    //int id=ui->lineEdit_17->text().toInt();
  int id=ui->lineEdit_supp->text().toInt();
    bool TEST=STUDIO.supprimer_studio(id);


        if(TEST)
     {

            ui->tableView_2->setModel(STUDIO.afficher_studio());
              ui->tableView_6->setModel(STUDIO.afficher_studio());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("suppresstion  successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
     {   QMessageBox::critical(nullptr, QObject::tr("suppresstion failed "),
                    QObject::tr("connection failed :.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

void Gestion_Studio::on_pushButton_stat2_clicked()
{
 stat2();
}

void Gestion_Studio::on_quitter_pushbottn_clicked()
{
    menu *w =new menu;
    w->show();
    this->hide();
}
