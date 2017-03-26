#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QWidget>

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatorWindow(QWidget *parent = 0);
    ~CalculatorWindow();

private:
    Ui::CalculatorWindow *ui;
    void connectSignalsAndSlots();
    void setValidatorOnSpaceEdit();
signals:
    void sendExpression(const QString expression);
public slots:
    void clickedButtonZero();
    void clickedButtonOne();
    void clickedButtonTwo();
    void clickedButtonThree();
    void clickedButtonFour();
    void clickedButtonFive();
    void clickedButtonSix();
    void clickedButtonSeven();
    void clickedButtonEight();
    void clickedButtonNine();
    void clickedButtonDot();
    void clickedButtonAdd();
    void clickedButtonSub();
    void clickedButtonMul();
    void clickedButtonDiv();
    void clickedButtonDel();
    void clickedButtonEqual();
    void printAnswerFromServer(const QString answer);
    void enableButtonEqual();
};

#endif // CALCULATORWINDOW_H
