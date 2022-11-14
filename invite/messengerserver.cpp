#include "messengerserver.h"
#include "messengersocket.h"
#include <QDebug>
#include <QTextStream>

namespace DuarteCorporation {
    MessengerServer::MessengerServer(QObject *parent):QTcpServer(parent)
    {

    }

    bool MessengerServer::startServer(quint16 port) {
        return listen(QHostAddress::Any, port);
    }

    void MessengerServer::incomingConnection(qintptr handle) {
        qDebug() << "Agent est connecte avec HANDLE";
        auto socket = new MessengerSocket(handle, this);
        mSockets << socket;
        for(auto i : mSockets) {
            QTextStream T(i);
            T << "Un Agent Se Connecter avec le Port " << handle;
            i->flush();
        }
        connect (socket, &MessengerSocket::DuReadyRead, [&](MessengerSocket *S) {
            qDebug() << "ReadyRead";
            QTextStream T(S);
            auto text = T.readAll();
            for(auto i: mSockets) {
                QTextStream K(i);
                K << text;
                i->flush();
            }
        });
        connect(socket, &MessengerSocket::StateChanged, [&](MessengerSocket *S, int ST) {
            qDebug() << "StateChanged avec HANDLE : " << S->socketDescriptor();
            if(ST == QTcpSocket::UnconnectedState) {
                qDebug() << "Un Agent se Deconnecter : " << S->socketDescriptor();
                mSockets.removeOne(S);
                for(auto i : mSockets) {
                    QTextStream K(i);
                    K << "Server : L'agent " << S->socketDescriptor() << " est connecte";
                    i->flush();
                }
            }
        });
    }
}
