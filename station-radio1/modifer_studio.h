#ifndef MODIFER_STUDIO_H
#define MODIFER_STUDIO_H

#include <QDialog>
#include<QSqlQuery>
namespace Ui {
class modifer_studio;
}

class modifer_studio : public QDialog
{
    Q_OBJECT

public:
    explicit modifer_studio(QWidget *parent = nullptr);
    ~modifer_studio();

private:
    Ui::modifer_studio *ui;
    int id ,N_studio;
    QString adress;
};

#endif // MODIFER_STUDIO_H
