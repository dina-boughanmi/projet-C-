#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emission.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_Ajouter_clicked();



    void on_pushButton_clicked();





    void on_pb_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Emission E;

};

#endif // MAINWINDOW_H
