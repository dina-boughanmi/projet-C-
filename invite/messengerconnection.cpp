#include "messengerconnection.h"
#include "ui_messengerconnection.h"

MessengerConnection::MessengerConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessengerConnection)
{
    ui->setupUi(this);
}

MessengerConnection::~MessengerConnection()
{
    delete ui;
}

void MessengerConnection::on_Ok_clicked()
{
    mHostname = ui->HostName->text();
    mPort = ui->Port->value();
    accept();
}

void MessengerConnection::on_Cancel_clicked()
{
    reject();
}
