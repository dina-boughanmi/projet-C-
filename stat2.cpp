#include "stat2.h"
#include<iostream>

#include<map>
#include<QtCharts>
#include<QChart>
#include<QChartGlobal>
#include<QChartView>
#include <QApplication>
#include <QStyleHints>
#include <QApplication>
#include <QPushButton>
#include <QGuiApplication>
#include<QString>
#include<QSqlQuery>
#include<QPieSeries>
#include<QMediaPlayer>
#include<QMediaPlaylist>


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QTime>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>

#include"piechartdrilldown/drilldownchart.h"
#include"piechartdrilldown/drilldownslice.h"
using namespace std;

stat2::stat2()
{


/*
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    QMainWindow *window  =new QMainWindow;

    DrilldownChart *chart = new DrilldownChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QPieSeries *yearSeries = new QPieSeries(window);
    yearSeries->setName("etat by year - All");

    const QStringList months = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    const QStringList names = {
        "Jane", "John", "Axel", "Mary", "Susan", "Bob"
    };

    for (const QString &name : names) {
        QPieSeries *series = new QPieSeries(window);
        series->setName("etat by month - " + name);

        for (const QString &month : months)
            *series << new DrilldownSlice(qrand() % 1000, month, yearSeries);

        QObject::connect(series, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

        *yearSeries << new DrilldownSlice(series->sum(), name, series);
    }

    QObject::connect(yearSeries, &QPieSeries::clicked, chart, &DrilldownChart::handleSliceClicked);

    chart->changeSeries(yearSeries);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    window->setCentralWidget(chartView);
    window->resize(800, 500);
    window->show();

*/
}
