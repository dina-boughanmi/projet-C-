#ifndef M_MODIFER_H
#define M_MODIFER_H
#include <QDialog>

#include <QObject>

namespace Ui {
class m_station;
}

class m_station : public QDialog
{
    Q_OBJECT

public:
    explicit m_station(QWidget *parent = nullptr);
    ~m_station();

private:
    Ui:: m_station *ui;
};
#endif // MODIFER_H
