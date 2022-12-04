#ifndef Gestion_de_invite_H
#define Gestion_de_invite_H
#include"invite.h"
#include <QMainWindow>
#include"Atelier_Arduino_v2/arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_de_invite; }
QT_END_NAMESPACE

class Gestion_de_invite : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_de_invite(QWidget *parent = nullptr);
    ~Gestion_de_invite();
   // void update_label();


private slots:
    void on_pushButton_clicked();

    void on_pushbutton_supp_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();



    void on_pushButton_20_clicked();
    void updatestring();
void update_RFID();




void on_quittergestioninviter_clicked();

private:
    Ui::Gestion_de_invite *ui;
    invite etmp;
    Arduino A;
    QString RFID="";
        QByteArray data; // variable contenant les données reçues
       
};
#endif // Gestion_de_invite_H
