#ifndef MESSENGERCONNECTION_H
#define MESSENGERCONNECTION_H

#include <QDialog>

namespace Ui {
class MessengerConnection;
}

class MessengerConnection : public QDialog
{
    Q_OBJECT

public:
    explicit MessengerConnection(QWidget *parent = nullptr);
    ~MessengerConnection();
    QString hostname() const;
    quint16 port() const;

private slots:
    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::MessengerConnection *ui;
    QString mHostname;
    quint16 mPort;
};

inline QString MessengerConnection::hostname() const {
    return mHostname;
}

inline quint16 MessengerConnection::port() const {
    return mPort;
}

#endif // MESSENGERCONNECTION_H
