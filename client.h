#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
//    Client(const QString &address, int port, QObject *parent = 0);
private:
    QTcpSocket *clientSocket;
signals:
    void connected();
    void socketErrorMsg(QString msg);
public slots:
    void tryConnect(QString address, int port);
    void sockedConnected();
    void failConnect(QAbstractSocket::SocketError socketError);


public slots:
};

#endif // CLIENT_H
