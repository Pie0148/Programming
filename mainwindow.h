#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *t = new QTimer(this);

private:
    QProgressBar *tank1 = new QProgressBar(this);
    QProgressBar *tank2 = new QProgressBar(this);
    QProgressBar *tank3 = new QProgressBar(this);

    float tank1Value = 100;
    float tank2Value = 0;
    float tank3Value = 0;

    QPushButton *b1 = new QPushButton(this);
    QPushButton *b2 = new QPushButton(this);

    int open1 = 0;
    int open2 = 0;

private slots:
    void timertick();
    void b1f();
    void b2f();
};
#endif // MAINWINDOW_H
