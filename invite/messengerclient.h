#ifndef MESSENGERCLIENT_H
#define MESSENGERCLIENT_H

#include <QDialog>

namespace Ui {
class MessengerClient;
}

class QTcpSocket;

class MessengerClient : public QDialog
{
    Q_OBJECT

public:
    explicit MessengerClient(QWidget *parent = nullptr);
    ~MessengerClient();

private slots:
    void on_Envoyer_clicked();

    void on_Bind_clicked();

private:
    Ui::MessengerClient *ui;
    QTcpSocket *mSocket;
};

#endif // MESSENGERCLIENT_H
