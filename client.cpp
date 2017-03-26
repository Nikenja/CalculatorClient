#include "client.h"
#include <QByteArray>
#include <QTextStream>
#include <QString>

Client::Client(QObject *parent) : QObject(parent){}

void Client::tryConnect(QString address, int port){
    this->clientSocket = new QTcpSocket(this);
    this->clientSocket->connectToHost(address,port);
    connect(this->clientSocket, SIGNAL(connected()), this, SLOT(sockedConnected()));
    connect(this->clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(failConnect()));
    connect(this->clientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Client::sockedConnected(){
    emit connected();
}

void Client::failConnect(){
    emit socketErrorMsg(this->clientSocket->errorString());
}

void Client::sendToServer(const QString expression){
    QByteArray dataForSend(expression.toUtf8());
    this->clientSocket->write(dataForSend);
}

void Client::readyRead(){
    QTextStream inputStream(this->clientSocket);
    QStringList allInputData("");
    while(clientSocket->bytesAvailable())
         allInputData.append(inputStream.readAll());
    QString resultExression = allInputData.join("");
    emit printAnswerFromServer(resultExression);
}
