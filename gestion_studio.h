#ifndef Gestion_Studio_H
#define Gestion_Studio_H

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
class Gestion_Studio;
class QChart;
}
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

class Gestion_Studio : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_Studio(QWidget *parent = nullptr);
    ~Gestion_Studio();

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

    void on_checkBox_stateChanged(int arg3);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_modiferbotton_clicked();

    void on_pushButton_29_clicked();



    void on_quitter_pushbottn_clicked();

private:
     Email createEmail();
private:

    Ui::Gestion_Studio *ui;
    studio STUDIO;
    QLabel *adressLabel;
    SMTPClient *client_;
};
#endif // Gestion_Studio_H
