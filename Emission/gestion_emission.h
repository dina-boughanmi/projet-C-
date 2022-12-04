#ifndef Gestion_emission_H
#define Gestion_emission_H
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>

#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMainWindow>
#include "emission.h"
#include <QtCharts>
#include "Emission/d_stats.h"
#include"Atelier_Arduino_v2/arduino.h"

namespace Ui {
class Gestion_emission;
}

class Gestion_emission : public QMainWindow
{
    Q_OBJECT

public:

    explicit Gestion_emission(QWidget *parent = nullptr);


    ~Gestion_emission();

private slots:


    void on_pb_Ajouter_clicked();



    void on_pushButton_clicked();





    void on_pb_modifier_clicked();

    void on_pb_Ajouter_3_clicked();

    void on_pb_Ajouter_2_clicked();

    void on_pb_Ajouter_4_clicked();

    void on_pb_Ajouter_6_clicked();

    void on_pb_Ajouter_5_clicked();

    void on_pb_stats_clicked();

    void on_qrcode_clicked();

    void on_insertimg_clicked();

   // void on_tabWidget_currentChanged(int index);

   // void on_stats_clicked();
 void updatestring();
void update_label();
void on_pushButton_2_clicked();

private:

    Ui::Gestion_emission *ui;
    Emission E;
    D_stats *s;
    QString data ;
    Arduino A;


};

#endif // Gestion_emission_H
