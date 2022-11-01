#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"invite.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushbutton_supp_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::MainWindow *ui;
    invite etmp;
};
#endif // MAINWINDOW_H
