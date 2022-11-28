#ifndef LOG_IN_H
#define LOG_IN_H
#include"Atelier_Arduino_v2/arduino.h"
#include <QMainWindow>
#include<QSqlQueryModel>
namespace Ui {
class log_in;
}

class log_in : public QMainWindow
{
    Q_OBJECT

public:
    explicit log_in(QWidget *parent = nullptr);
    ~log_in();


    bool  rechercher_user(QString ,QString );
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::log_in *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
int trys=0;
};

#endif // LOG_IN_H
