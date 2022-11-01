#ifndef MODIDER_STATION_H
#define MODIDER_STATION_H
#include"station.h"
//#include <QMainWindow>
#include"studio.h"
#include <QDialog>
#include<QSqlQuery>
namespace Ui {
class modider_station;
}

class modider_station : public QDialog
{
    Q_OBJECT

public:
    explicit modider_station(QWidget *parent = nullptr);
    ~modider_station();

private slots:




    void on_pushButton_clicked();

private:
    Ui::modider_station *ui;
    int id ,N_studio;
    QString adress;
    station STATION;
    studio STUDIO;
};

#endif // MODIDER_STATION_H
