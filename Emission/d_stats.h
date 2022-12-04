#ifndef DIALOG_STATS_H
#define DIALOG_STATS_H

#include <QDialog>

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

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class D_stats;
}

class D_stats : public QDialog
{
    Q_OBJECT

public:
    explicit D_stats(QWidget *parent = nullptr);
    ~D_stats();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();

private:
    Ui::D_stats *ui;
};

#endif // DIALOG_STATS_H
