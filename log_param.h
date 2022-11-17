#ifndef LOG_PARAM_H
#define LOG_PARAM_H

#include <QMainWindow>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
namespace Ui {
class log_param;
}

class log_param : public QMainWindow
{
    Q_OBJECT

public:
    explicit log_param(QWidget *parent = nullptr);
    ~log_param();

    bool ajouter_user(QString,QString,QString);
    bool  supprimer_user(QString);
    bool modifier_user( QString, QString ,  QString );


private slots:
    void on_pushButton_ajout_user_clicked();

    void on_pushButton_supp_user_clicked();

    void on_pushButton_modiferuser_clicked();

private:
    QString  username,pwd,pwd2 ;


private:
    Ui::log_param *ui;
};

#endif // LOG_PARAM_H
