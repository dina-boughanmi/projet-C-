#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studio.h"
#include <QLabel>
#include "SMTPClient/email.h"
#include "SMTPClient/smtpclient.h"
#include "SMTPClient/emailaddress.h"
#include <QtCharts/QChartGlobal>
#include <QMessageBox>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui
{
class QCheckBox;
class QLabel;
class QErrorMessage;
class MainWindow;
class QChart;
}
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

 void update();

private slots:


 void sendEmail();
 void clearFields();

 void onStatus(Status::e status, QString errorMessage);




    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_tabwidget_currentChanged(int index);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg2);

    void on_checkBox_stateChanged(int arg3);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_modiferbotton_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_stat2_clicked();

private:
     Email createEmail();


private:

    Ui::MainWindow *ui;
    studio STUDIO;
    QLabel *adressLabel;
    SMTPClient *client_;
};
#endif // MAINWINDOW_H
