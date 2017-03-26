#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
private:
    QTcpSocket *clientSocket;
signals:
    void connected();
    void socketErrorMsg(QString msg);
    void printAnswerFromServer(const QString answer);
public slots:
    void tryConnect(QString address, int port);
    void sockedConnected();
    void failConnect();
    void sendToServer(const QString expression);
    void readyRead();
};

#endif // CLIENT_H
