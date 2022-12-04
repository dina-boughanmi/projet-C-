#include "Emission/d_stats.h"
#include "ui_d_stats.h"

D_stats::D_stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::D_stats)
{
    ui->setupUi(this);
}

D_stats::~D_stats()
{
    delete ui;
}
//pie chart
    void D_stats::choix_pie()
    {
    QSqlQuery q1,q2,q3,q4,q5;
    qreal tot=0,c1=0,c2=0,c3=0,c4=0;

    q1.prepare("SELECT * FROM EMISSION");
    q1.exec();

    q2.prepare("SELECT * FROM EMISSION WHERE ANIMATEUR='ali'");
    q2.exec();

    q3.prepare("SELECT * FROM EMISSION WHERE ANIMATEUR='ilyes'");
    q3.exec();

    q4.prepare("SELECT * FROM EMISSION WHERE ANIMATEUR='john' ");
    q4.exec();

    q5.prepare("SELECT * FROM EMISSION WHERE ANIMATEUR='wael' ");
    q5.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}
    while (q5.next()){c4++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
    c4=c4/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("ali",c1);
    series->append("ilyes",c2);
    series->append("john",c3);
    series->append("wael",c4);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }

