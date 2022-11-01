#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite1.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_supprimer_clicked();
    void on_ajouter_clicked();


private:
    Ui::MainWindow *ui;
     publicite1 Etmp;
};
#endif // MAINWINDOW_H
