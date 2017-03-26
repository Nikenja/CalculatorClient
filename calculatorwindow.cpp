#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <QRegExp>

CalculatorWindow::CalculatorWindow(QWidget *parent) : QWidget(parent), ui(new Ui::CalculatorWindow){
    ui->setupUi(this);
    connectSignalsAndSlots();
    setValidatorOnSpaceEdit();
}

CalculatorWindow::~CalculatorWindow(){
    delete ui;
}

void CalculatorWindow::connectSignalsAndSlots(){
    connect(ui->buttonZero, SIGNAL(clicked(bool)), this, SLOT(clickedButtonZero()));
    connect(ui->buttonOne, SIGNAL(clicked(bool)), this, SLOT(clickedButtonOne()));
    connect(ui->buttonTwo, SIGNAL(clicked(bool)), this, SLOT(clickedButtonTwo()));
    connect(ui->buttonThree, SIGNAL(clicked(bool)), this, SLOT(clickedButtonThree()));
    connect(ui->buttonFour, SIGNAL(clicked(bool)), this, SLOT(clickedButtonFour()));
    connect(ui->buttonFive, SIGNAL(clicked(bool)), this, SLOT(clickedButtonFive()));
    connect(ui->buttonSix, SIGNAL(clicked(bool)), this, SLOT(clickedButtonSix()));
    connect(ui->buttonSeven, SIGNAL(clicked(bool)), this, SLOT(clickedButtonSeven()));
    connect(ui->buttonEight, SIGNAL(clicked(bool)), this, SLOT(clickedButtonEight()));
    connect(ui->buttonNine, SIGNAL(clicked(bool)), this, SLOT(clickedButtonNine()));
    connect(ui->buttonDot, SIGNAL(clicked(bool)), this, SLOT(clickedButtonDot()));
    connect(ui->buttonAdd, SIGNAL(clicked(bool)), this, SLOT(clickedButtonAdd()));
    connect(ui->buttonSub, SIGNAL(clicked(bool)), this, SLOT(clickedButtonSub()));
    connect(ui->buttonMul, SIGNAL(clicked(bool)), this, SLOT(clickedButtonMul()));
    connect(ui->buttonDiv, SIGNAL(clicked(bool)), this, SLOT(clickedButtonDiv()));
    connect(ui->buttonDel, SIGNAL(clicked(bool)), this, SLOT(clickedButtonDel()));
}

void CalculatorWindow::setValidatorOnSpaceEdit(){
    QRegExp regExpOnSpaceEdid("^([\\d+\\-*/.]+)+$");
    ui->spaceEdit->setValidator(new QRegExpValidator(regExpOnSpaceEdid,this));
}

void CalculatorWindow::clickedButtonZero(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "0");
}

void CalculatorWindow::clickedButtonOne(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "1");
}

void CalculatorWindow::clickedButtonTwo(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "2");
}

void CalculatorWindow::clickedButtonThree(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "3");
}

void CalculatorWindow::clickedButtonFour(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "4");
}

void CalculatorWindow::clickedButtonFive(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "5");
}

void CalculatorWindow::clickedButtonSix(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "6");
}

void CalculatorWindow::clickedButtonSeven(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "7");
}

void CalculatorWindow::clickedButtonEight(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "8");
}

void CalculatorWindow::clickedButtonNine(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "9");
}

void CalculatorWindow::clickedButtonDot(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + ".");
}

void CalculatorWindow::clickedButtonAdd(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "+");
}

void CalculatorWindow::clickedButtonSub(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "-");
}

void CalculatorWindow::clickedButtonMul(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "*");
}

void CalculatorWindow::clickedButtonDiv(){
    ui->spaceEdit->setText(ui->spaceEdit->text() + "/");
}

void CalculatorWindow::clickedButtonDel(){
    if(ui->spaceEdit->text().isEmpty())
        return;
    ui->spaceEdit->setText(ui->spaceEdit->text().left(ui->spaceEdit->text().size()-1));
}
