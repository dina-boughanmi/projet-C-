#include "statistique.h"
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

#include<QMediaPlayer>
#include<QMediaPlaylist>

QT_CHARTS_USE_NAMESPACE
statistique::statistique()
{

    QSqlQuery query;
    QString id_studio[5];
    int i(0);
    //int capa[5];
    int capasite[5];
    int capasitetot(0);


         query.prepare("SELECT * FROM STUDIO ORDER BY CAPACITE DESC  ");
         if(query.exec())
         {
             while (query.next())
             { if (i==5){break;}
                  id_studio[i]=query.value(0).toString() ;
                  //capasitetot=capasitetot+capa[i];
                  capasite[i]=query.value(1).toInt() ;
                   capasitetot=capasitetot+capasite[i];
                  qDebug()<< "fi stat::"<<query.value(0).toString()<<query.value(1).toInt()<<capasitetot;

                  i++;
             }
         }


   //![1]

        QBarSet *set0 = new QBarSet(" '"+id_studio[0]+"'");
        QBarSet *set1 = new QBarSet(" '"+id_studio[1]+"'");
        QBarSet *set2 = new QBarSet(" '"+id_studio[2]+"'");
        QBarSet *set3 = new QBarSet(" '"+id_studio[3]+"'");
        QBarSet *set4 = new QBarSet(" '"+id_studio[4]+"'");

        *set0 <<capasite[0]<< 0 << 0 << 0 << 0<< 0;
        *set1 << 0<< capasite[1]<< 0 << 0 << 0<< 0;
        *set2 << 0<< 0 <<capasite[2] << 0 << 0<< 0;
        *set3 << 0<< 0 << 0 << capasite[3]<< 0<< 0;
        *set4 << 0<< 0 << 0 << 0 <<capasite[4]<<0;
    //![1]

    //![2]
        QBarSeries *barseries = new QBarSeries();
        barseries->append(set0);
        barseries->append(set1);
        barseries->append(set2);
        barseries->append(set3);
        barseries->append(set4);
    //![2]



    //![3]
        QChart *chart = new QChart();
        chart->addSeries(barseries);

        chart->setTitle(" top 5 studio by  capacite ");
    //![3]

    //![4]
        QStringList categories;
        categories << id_studio[0] << id_studio[1] << id_studio[2]<< id_studio[3] <<id_studio[4];
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);

        chart->setAxisX(axisX, barseries);
        axisX->setRange(QString(id_studio[0]), QString(id_studio[4]));

        QValueAxis *axisY = new QValueAxis();

        chart->setAxisY(axisY, barseries);
        axisY->setRange(0, 50);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]




  //![7]
   QMainWindow *window =new QMainWindow;
    QPalette pal = window->palette();

    pal.setColor(QPalette::Window, QRgb(0x121218));
    pal.setColor(QPalette::WindowText, QRgb(0xd6d6d6));
      QChart::AnimationOptions options(QChart::AllAnimations);
      chartView->chart()->setAnimationOptions(options);
       window->windowTitle();
       window->setPalette(pal);
       window->setCentralWidget(chartView);

       window->resize(700, 700);

       window->show();
    //![7]

}
