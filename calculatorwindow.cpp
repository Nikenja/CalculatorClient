#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <QRegExp>

CalculatorWindow::CalculatorWindow(QWidget *parent) : QWidget(parent), ui(new Ui::CalculatorWindow){
    ui->setupUi(this);
    connectSignalsAndSlots();
    setValidatorOnLineEdit();
}

CalculatorWindow::~CalculatorWindow(){
    delete ui;
}

void CalculatorWindow::connectSignalsAndSlots(){
    connect(ui->toolButtonZero, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonZero()));
    connect(ui->toolButtonOne, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonOne()));
    connect(ui->toolButtonTwo, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonTwo()));
    connect(ui->toolButtonThree, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonThree()));
    connect(ui->toolButtonFour, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonFour()));
    connect(ui->toolButtonFive, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonFive()));
    connect(ui->toolButtonSix, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonSix()));
    connect(ui->toolButtonSeven, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonSeven()));
    connect(ui->toolButtonEight, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonEight()));
    connect(ui->toolButtonNine, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonNine()));
    connect(ui->toolButtonDot, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonDot()));
    connect(ui->toolButtonAdd, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonAdd()));
    connect(ui->toolButtonSub, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonSub()));
    connect(ui->toolButtonMul, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonMul()));
    connect(ui->toolButtonDiv, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonDiv()));
    connect(ui->toolButtonDel, SIGNAL(clicked(bool)), this, SLOT(clickedToolButtonDel()));
}

void CalculatorWindow::setValidatorOnLineEdit(){
    QRegExp regExpOnLineEdid("^([\\d+\\-*/.]+)+$");
    ui->lineEdit->setValidator(new QRegExpValidator(regExpOnLineEdid,this));
}

void CalculatorWindow::clickedToolButtonZero(){
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void CalculatorWindow::clickedToolButtonOne(){
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void CalculatorWindow::clickedToolButtonTwo(){
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void CalculatorWindow::clickedToolButtonThree(){
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void CalculatorWindow::clickedToolButtonFour(){
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void CalculatorWindow::clickedToolButtonFive(){
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void CalculatorWindow::clickedToolButtonSix(){
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void CalculatorWindow::clickedToolButtonSeven(){
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void CalculatorWindow::clickedToolButtonEight(){
    ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void CalculatorWindow::clickedToolButtonNine(){
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void CalculatorWindow::clickedToolButtonDot(){
    ui->lineEdit->setText(ui->lineEdit->text() + ".");
}

void CalculatorWindow::clickedToolButtonAdd(){
    ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void CalculatorWindow::clickedToolButtonSub(){
    ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void CalculatorWindow::clickedToolButtonMul(){
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void CalculatorWindow::clickedToolButtonDiv(){
    ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void CalculatorWindow::clickedToolButtonDel(){
    if(ui->lineEdit->text().isEmpty())
        return;
    ui->lineEdit->setText(ui->lineEdit->text().left(ui->lineEdit->text().size()-1));
}
