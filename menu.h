#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_gestionanimateurpushbutton_clicked();

    void on_gestioninvite_clicked();

    void on_gestionemission_clicked();

    void on_publisiter_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
