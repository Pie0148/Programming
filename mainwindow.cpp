#include "mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tank1->setValue(100);
    tank1->setGeometry(50,100,100,100);
    tank1->setOrientation(Qt::Vertical);
    tank1->setStyleSheet("border: 1px solid black;");
    tank1->show();

    tank2->setValue(0);
    tank2->setGeometry(250,100,100,100);
    tank2->setOrientation(Qt::Vertical);
    tank2->setStyleSheet("border: 1px solid black;");
    tank2->show();

    tank3->setValue(0);
    tank3->setGeometry(450,100,100,100);
    tank3->setOrientation(Qt::Vertical);
    tank3->setStyleSheet("border: 1px solid black;");
    tank3->show();

    b1->setText("Valve");
    connect(b1, SIGNAL(clicked()), this, SLOT(b1f()));
    b1->setGeometry(160,200,50, 50);
    b1->setStyleSheet("font-size: 15px;");
    b1->show();

    b2->setText("Valve");
    connect(b2, SIGNAL(clicked()), this, SLOT(b2f()));
    b2->setGeometry(370,200,50, 50);
    b2->setStyleSheet("font-size: 15px;");
    b2->show();

    t->setInterval(20);
    connect(t, SIGNAL(timeout()), this, SLOT(timertick()));
    t->start();
}

MainWindow::~MainWindow()
{
}

void MainWindow::timertick()
{
    if(open1==1 && open2==0 && tank1Value>tank2Value)
    {
        tank1Value = tank1Value - 0.8;
        tank1->setValue(tank1Value);
        tank2Value = tank2Value + 0.8;
        tank2->setValue(tank2Value);
    }

    if(open1==1 && open2==1 )
    {
        if(tank1Value>tank2Value)
        {
            tank1Value = tank1Value - 0.8;
            tank1->setValue(tank1Value);
            tank2Value = tank2Value + 0.4;
            tank2->setValue(tank2Value);
        }
        if(tank1Value>tank3Value)
        {
            tank1Value = tank1Value - 0.4;
            tank1->setValue(tank1Value);
            tank2Value = tank2Value - 0.4;
            tank2->setValue(tank2Value);
            tank3Value = tank3Value + 0.8;
            tank3->setValue(tank3Value);
        }
    }
}

void MainWindow::b1f()
{
    if(open1==0)
        open1=1;
    else
        open1=0;
}

void MainWindow::b2f()
{
    if(open2==0)
        open2=1;
    else
        open2=0;
}

