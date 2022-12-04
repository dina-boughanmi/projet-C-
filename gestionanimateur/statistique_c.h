#pragma once
#ifndef STATISTIQUE_C_H
#define STATISTIQUE_C_H

#include <QMainWindow>


namespace Ui {
class statistique_c;
}

class statistique_c : public QMainWindow
{
    Q_OBJECT

public:
    explicit statistique_c(QWidget *parent = nullptr);
    ~statistique_c();



private slots:
    void on_pushButton_clicked();

private:
    Ui::statistique_c *ui;
   void statistiques(QVector<double>* ticks,QVector<QString> *labels);
   void MakeStat();
};

#endif // STATISTIQUE_C_H
