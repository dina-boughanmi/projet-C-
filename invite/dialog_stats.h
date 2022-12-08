#ifndef DIALOG_STATS_H
#define DIALOG_STATS_H

#include <QDialog>
#include "QtPrintSupport"

//#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

namespace Ui {
class Dialog_stats;
}

class Dialog_stats : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_stats(QWidget *parent = nullptr);
    ~Dialog_stats();

private slots:
    void on_pushButton_clicked();
    //void choix_bar();
    //void choix_pie();
private:
    Ui::Dialog_stats *ui;
    void MakeStat();
    void statistiques(QVector<double>* ticks,QVector<QString> *labels);
};

#endif // DIALOG_STATS_H
