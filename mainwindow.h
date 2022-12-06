#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite1.h"
#include <QMainWindow>
#include <QtCharts>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include "arduino.h"
#include <QSerialPort>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
        int G_PVS1();
            int G_PVS2();
            int G_PVS3();
            int G_PVS4();
            int G_PVS5();
            int G_PVS6();
            int G_PVS7();
            int G_PVS8();
            int G_PVS9();
            int G_PVS10();
            int G_PVS11();
            int G_PVS12();
            int G_PVS13();

            QChartView* piechart();
    ~MainWindow();

private slots:

            void readSerial();
                void updateTemperature(QString);




    void on_supprimer_clicked();
    void on_ajouter_clicked();
    void on_pushButton_6_clicked();


    void on_tri_clicked();

    void on_RJC_clicked();

    void on_PDF_clicked();

    void update_label();

    void on_rechercher_clicked();

    void on_temperature_clicked();
    void on_pushPlay_clicked();
    void on_pushStop_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
     publicite1 Etmp;
     QMediaPlayer * player;
     QVideoWidget * vw;
      //Arduino A1;
     int selected=0;
     QStringList files;



     QSerialPort *arduino;
     Arduino A1;

         QString serialData="";
         QString serialBuffer;
         QString parsed_data;
         double temperature_value;

};
#endif // MAINWINDOW_H
