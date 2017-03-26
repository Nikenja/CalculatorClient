#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog{
    Q_OBJECT
public:
    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();
private:
    Ui::ConnectionDialog *ui;
    void connectSignalsAndSlots();
    void setValidatorOnLineEditAddressPort();
    bool isValidPort();
signals:
    void connectToServer(QString address, int port);
public slots:
    void clickedButtonConnect();
    void enableButtonConnect();
    void printErrorMsgInLabelMsgError(QString msg);
};

#endif // CONNECTIONDIALOG_H
