#ifndef Dialog_stats_anim_H
#define Dialog_stats_anim_H
#include <QDialog>
#include "QtPrintSupport"

namespace Ui {
class Dialog_stats_anim;
}

class Dialog_stats_anim : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_stats_anim(QWidget *parent = nullptr);
    ~Dialog_stats_anim();

private:
    Ui::Dialog_stats_anim *ui;
    void MakeStat();
    void statistiques(QVector<double>* ticks,QVector<QString> *labels);
};

#endif // Dialog_stats_anim_H
