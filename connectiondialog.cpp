#include "connectiondialog.h"
#include "ui_connectiondialog.h"
#include <QRegExp>

ConnectionDialog::ConnectionDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ConnectionDialog){
    ui->setupUi(this);
    ui->labelMsgError->setHidden(true);
    ui->buttonConnect->setDisabled(true);
    setValidatorOnLineEditAddressPort();
    connectSignalsAndSlots();
}

ConnectionDialog::~ConnectionDialog(){
    delete ui;
}

void ConnectionDialog::connectSignalsAndSlots(){
    connect(ui->lineEditAddressPort, SIGNAL(textChanged(QString)), this, SLOT(enableButtonConnect()));
    connect(ui->lineEditAddressPort, SIGNAL(returnPressed()), this, SLOT(clickedButtonConnect()));
    connect(ui->buttonConnect, SIGNAL(clicked(bool)), this, SLOT(clickedButtonConnect()));
}

void ConnectionDialog::setValidatorOnLineEditAddressPort(){
    QRegExp regExpOnLineEdit("^((\\d{1,3}\\.){3,3}\\d{1,3}[:])\\d{1,5}$");
    ui->lineEditAddressPort->setValidator(new QRegExpValidator(regExpOnLineEdit,this));
}

void ConnectionDialog::clickedButtonConnect(){
    if(!isValidPort()){
        emit printErrorMsgInLabelMsgError(QString("Incorrect port"));
        return;
    }
    emit connectToServer(QString("127.0.0.1"),1428);
}

void ConnectionDialog::enableButtonConnect(){
    ui->buttonConnect->setEnabled(ui->lineEditAddressPort->hasAcceptableInput());
}

bool ConnectionDialog::isValidPort(){
    QString strAddressPort = ui->lineEditAddressPort->text();
    QString strPort = strAddressPort.right(strAddressPort.size() - strAddressPort.lastIndexOf(':') - 1);
    bool isIntValue = false;
    int port = strPort.toInt(&isIntValue);
    if(isIntValue)
        if(port >= 0 && port < 65536)
            return true;
    return false;
}

void ConnectionDialog::printErrorMsgInLabelMsgError(QString msg){
    ui->labelMsgError->setHidden(false);
    ui->labelMsgError->setText(msg);
}
