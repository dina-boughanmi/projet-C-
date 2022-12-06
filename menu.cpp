#include "menu.h"
#include "ui_menu.h"
#include"gestion_studio.h"
#include"log_in.h";
#include"gestionanimateur/gestion_animateur.h"
#include"gestionanimateur/animateur.h"
#include"invite/Gestion_de_invite.h"
#include"Emission/gestion_emission.h"
#include"publicitenew/gestion_pub.h"
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    QMovie* movie = new QMovie("C:/Users/user/Documents/projet-C-/IMG8RES FOR QT/radio.gif");


    if (!movie->isValid())
    {

        qDebug()<<"not valed gif";
    }

    // Play GIF
    QLabel *label_gif= ui->radiolabel;
   label_gif->setMovie(movie);
    movie->start();
     qDebug()<<"valed gif selket ";
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    Gestion_Studio *gestien = new Gestion_Studio;
     gestien->show();
     this->hide();
}

void menu::on_pushButton_2_clicked()
{
  log_in *w = new log_in;
w->show();
this->hide();
}

void menu::on_gestionanimateurpushbutton_clicked()
{
    Gestion_animateur *w = new Gestion_animateur;
  w->show();
  this->hide();
}

void menu::on_gestioninvite_clicked()
{
    Gestion_de_invite *w=new Gestion_de_invite;
    w->show();
    this->hide();
}

void menu::on_gestionemission_clicked()
{
   Gestion_emission *w = new Gestion_emission;
   w->show();
   this->hide();
}

void menu::on_publisiter_clicked()
{

            gestion_pub *w = new gestion_pub;
            w->show();
            this->hide();
}
