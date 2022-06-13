#include "mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QtMath>

#define buttonSize 100

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: teal; border: 1px solid black;");  //sets the background style

    //created the display label
    QGridLayout *layout = new QGridLayout;
    display = new QLabel;
    display->setFixedSize(312, 100);
    display->setStyleSheet("background-color: #00cccc; border: 1px solid black; font-size: 40px;");
    layout->addWidget(display, 0, 0, 2, 3);

    //Create all the pushbuttons, set stylesheets and add them to the layout

    QPushButton *b = new QPushButton("0");
    connect(b, SIGNAL(clicked()), this, SLOT(b0()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 5, 0);

    b = new QPushButton(".");
    connect(b, SIGNAL(clicked()), this, SLOT(bdecimal()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 5, 1);

    b = new QPushButton("=");
    connect(b, SIGNAL(clicked()), this, SLOT(beq()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 5, 2);

    b = new QPushButton("+");
    connect(b, SIGNAL(clicked()), this, SLOT(bplus()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 5, 3);

    b = new QPushButton("1");
    connect(b, SIGNAL(clicked()), this, SLOT(b1()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 4, 0);

    b = new QPushButton("2");
    connect(b, SIGNAL(clicked()), this, SLOT(b2()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 4, 1);

    b = new QPushButton("3");
    connect(b, SIGNAL(clicked()), this, SLOT(b3()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 4, 2);

    b = new QPushButton("-");
    connect(b, SIGNAL(clicked()), this, SLOT(bminus()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 4, 3);

    b = new QPushButton("4");
    connect(b, SIGNAL(clicked()), this, SLOT(b4()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 3, 0);

    b = new QPushButton("5");
    connect(b, SIGNAL(clicked()), this, SLOT(b5()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 3, 1);

    b = new QPushButton("6");
    connect(b, SIGNAL(clicked()), this, SLOT(b6()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 3, 2);

    b = new QPushButton("x");
    connect(b, SIGNAL(clicked()), this, SLOT(bmultiply()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 3, 3);

    b = new QPushButton("7");
    connect(b, SIGNAL(clicked()), this, SLOT(b7()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 2, 0);

    b = new QPushButton("8");
    connect(b, SIGNAL(clicked()), this, SLOT(b8()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 2, 1);

    b = new QPushButton("9");
    connect(b, SIGNAL(clicked()), this, SLOT(b9()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 2, 2);

    b = new QPushButton("/");
    connect(b, SIGNAL(clicked()), this, SLOT(bdivide()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px;");
    layout->addWidget(b, 2, 3);

    b = new QPushButton("C");
    connect(b, SIGNAL(clicked()), this, SLOT(bclear()));
    b->setFixedSize(buttonSize, buttonSize);
    b->setStyleSheet("font-size: 40px; background-color: #ff4d4d;");
    layout->addWidget(b, 0, 3);

    setLayout(layout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::b1()
{
    numberPrint(1);
}

void MainWindow::b2()
{
    numberPrint(2);
}

void MainWindow::b3()
{
    numberPrint(3);
}

void MainWindow::b4()
{
    numberPrint(4);
}

void MainWindow::b5()
{
    numberPrint(5);
}

void MainWindow::b6()
{
    numberPrint(6);
}

void MainWindow::b7()
{
    numberPrint(7);
}

void MainWindow::b8()
{
    numberPrint(8);
}

void MainWindow::b9()
{
    numberPrint(9);
}

void MainWindow::b0()
{
    numberPrint(0);
}

void MainWindow::beq()  //function to do the arithmatic
{
    //if operator value representing each operator { 0 is + , 1 is -, 2 is x, 3 is / }
    if(operators == 0)
    {
        currentNum = prevNum + currentNum;
        display->setText("= " + QString::number(currentNum));
    }
    else if(operators == 1)
    {
        currentNum = prevNum - currentNum;
        display->setText("= " + QString::number(currentNum));
    }
    else if(operators == 2)
    {
        currentNum = prevNum*currentNum;
        display->setText("= " + QString::number(currentNum));
    }
    else if(operators == 3)
    {
        if(currentNum == 0) // logic to show that divide by zero is an error
        {
            display->setText("error");
        }
        else
        {
            currentNum = prevNum / currentNum;
            display->setText("= " + QString::number(currentNum));
        }
    }

    if(prevDecimal > decimal)
    {
        decimal = prevDecimal;
    }
    //decimal = 0;
    prevNum = 0;
}

void MainWindow::bplus()    //called for the add operator
{
    operators = 0;
    display->setText(display->text() + " +");
    prevNum = currentNum;
    currentNum = 0;
    prevDecimal = decimal;
    decimal = 0;
}

void MainWindow::bminus()   //called for the minus operator
{
    operators = 1;
    display->setText(display->text() + " -");
    prevNum = currentNum;
    currentNum = 0;
    prevDecimal = decimal;
    decimal = 0;
}

void MainWindow::bmultiply()    //called for the multiply operator
{
    operators = 2;
    display->setText(display->text() + " x");
    prevNum = currentNum;
    currentNum = 0;
    prevDecimal = decimal;
    decimal = 0;
}

void MainWindow::bdivide()  //called for the divide operator
{
    operators = 3;
    display->setText(display->text() + " /");
    prevNum = currentNum;
    currentNum = 0;
    prevDecimal = decimal;
    decimal = 0;
}

void MainWindow::bdecimal() //adds a decimal point to the value
{
    if(!decimal)
        decimal++;
}

void MainWindow::bclear()   //clears the display and registers
{
    decimal = 0;
    prevDecimal = 0;
    currentNum = 0;
    prevNum = 0;
    display->setText("");
}

void MainWindow::numberPrint(double num)
{
    if(!decimal)
    {
        currentNum = currentNum*10 + num;   //adds the digit to the end
    }
    else
    {
        currentNum = currentNum + num*pow(0.1,decimal); //adds the digit after a decimal value
        decimal++;
    }
    display->setText(QString::number(currentNum));
}
