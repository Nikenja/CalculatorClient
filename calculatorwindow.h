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
    void setValidatorOnLineEdit();
public slots:
    void clickedToolButtonZero();
    void clickedToolButtonOne();
    void clickedToolButtonTwo();
    void clickedToolButtonThree();
    void clickedToolButtonFour();
    void clickedToolButtonFive();
    void clickedToolButtonSix();
    void clickedToolButtonSeven();
    void clickedToolButtonEight();
    void clickedToolButtonNine();
    void clickedToolButtonDot();
    void clickedToolButtonAdd();
    void clickedToolButtonSub();
    void clickedToolButtonMul();
    void clickedToolButtonDiv();
    void clickedToolButtonDel();
};

#endif // CALCULATORWINDOW_H
