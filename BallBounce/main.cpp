#include "ballbounce.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BallBounce w;
    w.show();
    return a.exec();
}
