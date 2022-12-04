#include "statistique_c.h"
#include "ui_statistique_c.h"
#include <QtSql>
#include<QMap>
#include <iostream>
#include <QString>
#include<time.h>
#include <QDialog>
#include <qdialog.h>
#include <ctime>
#include<vector>
#include <QLineEdit>
#include <cstring>
#include <QSharedPointer>
#include<QSharedDataPointer>
#include<qsharedpointer.h>
#include<gestionanimateur/qcustomplot.h>
statistique_c::statistique_c(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistique_c)
{
    ui->setupUi(this);
   statistique_c::MakeStat();
}

statistique_c::~statistique_c()
{
    delete ui;
}


void statistique_c::statistiques(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery qry;
    int i=0;
    qry.exec("SELECT GRADE FROM JUGE");
    while (qry.next())
    {
        QString CIN = qry.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<CIN;
    }
}
void statistique_c::MakeStat()
{
    // Background
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255, 255, 255));
    ui->widget->setBackground(QBrush(gradient));
    QCPBars *A = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    A->setAntialiased(false);
    A->setStackingGap(1);

    // Couleurs
    A->setName("Repartition des Juge selon Grade ");
    A->setPen(QPen(QColor(255, 0, 0).lighter(120)));
    A->setBrush(QColor(39, 39, 39));

    // Axe des abscisses
    QVector<double> ticks;
    QVector<QString> labels;
    statistiques(&ticks,&labels);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setTickLabelRotation(60);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setLabel("GRADE");
    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 8);
    ui->widget->xAxis->setBasePen(QPen(Qt::black));
    ui->widget->xAxis->setTickPen(QPen(Qt::black));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::black);
    ui->widget->xAxis->setLabelColor(Qt::black);

    // Axe des ordonnées
    ui->widget->yAxis->setRange(0,10);
    ui->widget->yAxis->setPadding(5);
    ui->widget->yAxis->setLabel("CIN");
    ui->widget->yAxis->setBasePen(QPen(Qt::black));
    ui->widget->yAxis->setTickPen(QPen(Qt::black));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::black));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::black);
    ui->widget->yAxis->setLabelColor(Qt::black);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Ajout des données (statistiques de la quantite)
    QVector<double> PlaceData;
    QSqlQuery q1("SELECT COUNT(*) FROM JUGE");
    while (q1.next())
    {
        int  nbr_fautee = q1.value(0).toInt();
        PlaceData<< nbr_fautee;
    }
    A->setData(ticks, PlaceData);
    ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(5);
    ui->widget->legend->setFont(legendFont);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

