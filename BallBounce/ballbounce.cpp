#include "ballbounce.h"

BallBounce::BallBounce(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(800,600);
    TapIt = new QLabel(this);
    TapIt->show();
    TapIt->setText(" TapIt ");
    TapIt->setFixedSize(45, 12);
    TapIt->move(0, this->height()-TapIt->height());
    setMouseTracking(true);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
    timer ->setInterval(20);
    timer->start();

    for(int i = 0; i < 400; i++)
    {
        hrzntl[i] = 4;
        vrtcl[i] = 0;
        gravity[i] = 0.1;
        lastBounce[i] = 0;
        turnLoss[i] = 1.5;
    }
}

BallBounce::~BallBounce()
{
}

void BallBounce::mouseMoveEvent(QMouseEvent *event)
{
    TapIt->move(event->x()-TapIt->width(),event->y()-TapIt->height());
    TapIt->show();
}

void BallBounce::mousePressEvent(QMouseEvent *event)
{



    QLabel* ball = new QLabel(this);
    ball->setText("ball");
    ball->setFixedSize(45, 12);
    ball->move(TapIt->x(), TapIt->y()-ball->height());
    ball->show();

    circle.push_back(ball);

}

void BallBounce::step()
{
    //Move da Balls
    int i = 0, j = 0;
    std::list<QLabel*>::iterator ball = circle.begin();  //Om die bal in die lys te vind
    while(ball != circle.end())
    {
        //vrtcl[i] = vrtcl[i] + gravity;
        (*ball) -> move((*ball)->x()+hrzntl[i], (*ball)->y()+vrtcl[i]);
        if((*ball)->x()+(*ball)->width() > width())
        {
            //(*ball) -> move((*ball)->x() - hrzntl[i]);
            hrzntl[i] = -hrzntl[i] + 0.2;
        }
        else if((*ball)->x() < 0)
        {
            //(*ball) -> move((*ball)->x() - hrzntl[i]);
            hrzntl[i] = -hrzntl[i] - 0.2;
        }

        if((*ball)->y()+(*ball)->height() > height())
        {
            (*ball) -> move((*ball)->x(), (*ball)->y() - vrtcl[i]);
            vrtcl[i] = -vrtcl[i] + turnLoss[i];

            if(((vrtcl[i]) == 0) && (((*ball)->y() + (*ball)->height()) == 650))
            {
               (*ball) -> move((*ball)->x(), 50);
                vrtcl[i] = 0;
                gravity[i] = 0;
                turnLoss[i] = 0;
                //(*ball) -> deleteLater();
                //ball = balls.erase(ball);

            }
            vrtcl[i] = vrtcl[i] + gravity[i];

        }
        /*else if((*ball)->y()+(*ball)->height() > height() && lastBounce[i] == 1)
        {
            (*ball) -> move((*ball)->x(), (*ball)->y() - 15 - (*ball)->height());
            vrtcl[i] = 0;
            gravity[i] = 0;
        }*/
        else
        {
            (*ball) -> move((*ball)->x()+hrzntl[i], (*ball)->y()+vrtcl[i]);
            vrtcl[i] = vrtcl[i] + gravity[i];
        }
        /*if(vrtcl[i] == 0 && (*ball)->y() == 500)
        {
            lastBounce[i] = 1;
        }*/
        std::list<QLabel*>::iterator ball2 = circle.begin();
        j = i + 1;
        ball2 = ball;
        ball2++;
        while(ball2 != circle.end())
        {
            if(((((*ball)->x() < (*ball2)->x()+(*ball2)->width()) &&
                ((*ball)->x()+(*ball)->width() > (*ball2)->x())) &&
                ((*ball)->y() < (*ball2)->y()+(*ball2)->height()) &&
                ((*ball)->y() + (*ball)->height() > (*ball2)->y())))
            {
                if(hrzntl[i] > 0)
                {
                    //horzloss = -horzloss;
                    (*ball2) -> move((*ball2)->x()+2, (*ball2)->y());
                    hrzntl[i] = -hrzntl[i] + horzloss;
                    hrzntl[j] = -hrzntl[j] - horzloss;
                }
                else if(hrzntl[i] < 0)
                {
                    //horzloss = -horzloss;
                    (*ball2) -> move((*ball2)->x()+2, (*ball2)->y());
                    hrzntl[i] = -hrzntl[i] - horzloss;
                    hrzntl[j] = -hrzntl[j] + horzloss;
                }


            }
            j++;
            ball2++;
        }
        i++;
        ball++;

    }

}

