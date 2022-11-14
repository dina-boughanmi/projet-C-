#include "messengerclient.h"
#include "ui_messengerclient.h"
#include "messengerconnection.h"
#include <QTcpSocket>
#include <QTextStream>

MessengerClient::MessengerClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessengerClient)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&]() {
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->textEdit->append(text);
    });
}

MessengerClient::~MessengerClient()
{
    delete ui;
}

void MessengerClient::on_Envoyer_clicked()
{
    QTextStream T(mSocket);
    T << ui ->NomAgent_2->text() << " : " << ui->Message->text();
    mSocket->flush();
    ui->Message->clear();
}

void MessengerClient::on_Bind_clicked()
{
    MessengerConnection D(this);
    if(D.exec() == QDialog::Rejected) {
        return;
    }
    mSocket->connectToHost(D.hostname(), D.port());
}
