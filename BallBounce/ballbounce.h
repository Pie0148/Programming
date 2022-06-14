#ifndef BALLBOUNCE_H
#define BALLBOUNCE_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QProgressBar>
#include <list>
#include <QMouseEvent>
#include <iostream>
#include <QRandomGenerator>

class BallBounce : public QMainWindow
{
    Q_OBJECT

public:

    BallBounce(QWidget *parent = nullptr);
    ~BallBounce();

private:

    QLabel *TapIt;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QTimer *timer;
   // QLabel *ball;

    std::list<QLabel*> circle;

    double vrtcl[800];
    double hrzntl[600];
    double gravity[500];
    double turnLoss[500];
    double horzloss = 0.2;
    void throwBalls(int);
   // int nBalls;
    int lastBounce[500];

private slots:

    void step();

};
#endif // BALLBOUNCE_H
