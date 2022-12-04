#include "gestionanimateur/Dialog_stats_anim.h"
#include "ui_Dialog_stats_anim.h"
#include "qcustomplot.h"
#include "animateur.h"
#include "Gestion_animateur.h"

Dialog_stats_anim::Dialog_stats_anim(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_stats_anim)
{
    ui->setupUi(this);
    Dialog_stats_anim::MakeStat();
}

Dialog_stats_anim::~Dialog_stats_anim()
{
    delete ui;
}
void Dialog_stats_anim::statistiques(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery qry;
    int i=0;
    qry.exec("SELECT ID_ANIM FROM ANIMATEUR");
    while (qry.next())
    {
        QString ID_ANIM = qry.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<ID_ANIM;
    }
}
void Dialog_stats_anim::MakeStat()
{
    /***** Background *****/
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255, 170, 255));
    ui->plot->setBackground(QBrush(gradient));
    QCPBars *A = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
    A->setAntialiased(false);
    A->setStackingGap(1);
    /***** Couleurs*****/
    A->setName("Les nbr enfants selon les ID_ANIM");
    A->setPen(QPen(QColor(170, 85, 255).lighter(120)));
    A->setBrush(QColor(170, 85, 255));
    /***** Axe des abscisses *****/
    QVector<double> ticks;
    QVector<QString> labels;
    statistiques(&ticks,&labels);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->plot->xAxis->setTicker(textTicker);
    ui->plot->xAxis->setTickLabelRotation(60);
    ui->plot->xAxis->setSubTicks(false);
    ui->plot->xAxis->setLabel("ID_ANIM");
    ui->plot->xAxis->setTickLength(0, 4);
    ui->plot->xAxis->setRange(0, 8);
    ui->plot->xAxis->setBasePen(QPen(Qt::black));
    ui->plot->xAxis->setTickPen(QPen(Qt::black));
    ui->plot->xAxis->grid()->setVisible(true);
    ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->plot->xAxis->setTickLabelColor(Qt::black);
    ui->plot->xAxis->setLabelColor(Qt::black);
    /***** Axe des ordonnées *****/
    ui->plot->yAxis->setRange(0,5);
    ui->plot->yAxis->setPadding(1);
    ui->plot->yAxis->setLabel("NBRENFANT");
    ui->plot->yAxis->setBasePen(QPen(Qt::black));
    ui->plot->yAxis->setTickPen(QPen(Qt::black));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::black));
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->setTickLabelColor(Qt::black);
    ui->plot->yAxis->setLabelColor(Qt::black);
    ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    QVector<double> PlaceData;
    QSqlQuery q1("SELECT NBRENFANT FROM ANIMATEUR");
    while (q1.next())
    {
        int  nbr_fautee = q1.value(0).toInt();
        PlaceData<< nbr_fautee;
    }
    A->setData(ticks, PlaceData);
    ui->plot->legend->setVisible(true);
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->plot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(5);
    ui->plot->legend->setFont(legendFont);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
