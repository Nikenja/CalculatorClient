#include "client.h"

Client::Client(QObject *parent) : QObject(parent){}

void Client::tryConnect(QString address, int port){
    this->clientSocket = new QTcpSocket(this);
    this->clientSocket->connectToHost(address,port);
    connect(this->clientSocket, SIGNAL(connected()), this, SLOT(sockedConnected()));
    connect(this->clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(failConnect(QAbstractSocket::SocketError)));
}

void Client::sockedConnected(){
    emit connected();
}

void Client::failConnect(QAbstractSocket::SocketError socketError){
    emit socketErrorMsg(this->clientSocket->errorString());
}
