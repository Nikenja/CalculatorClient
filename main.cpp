#include "connectiondialog.h"
#include <QApplication>
#include <calculatorwindow.h>
#include <client.h>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client;
    ConnectionDialog connectionDialog;
    connectionDialog.setFixedSize(300,100);
    connectionDialog.move(QApplication::desktop()->screen()->rect().center() - connectionDialog.rect().center());
    CalculatorWindow calculatorWindow;
    calculatorWindow.setFixedSize(243,315);
    calculatorWindow.move(QApplication::desktop()->screen()->rect().center() - calculatorWindow.rect().center());

    QObject::connect(&connectionDialog, SIGNAL(connectToServer(QString,int)), &client, SLOT(tryConnect(QString,int)));
    QObject::connect(&client, SIGNAL(socketErrorMsg(QString)), &connectionDialog, SLOT(printErrorMsgInLabelMsgError(QString)));
    QObject::connect(&client, SIGNAL(connected()), &connectionDialog, SLOT(close()));
    QObject::connect(&client, SIGNAL(connected()), &calculatorWindow, SLOT(show()));
    QObject::connect(&calculatorWindow, SIGNAL(sendExpression(QString)), &client, SLOT(sendToServer(QString)));
    QObject::connect(&client, SIGNAL(printAnswerFromServer(QString)), &calculatorWindow, SLOT(printAnswerFromServer(QString)));
    connectionDialog.show();

    return a.exec();
}
