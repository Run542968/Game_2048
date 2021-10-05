#include "mainwindow.h"
#include <QApplication>
#include<QSound>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //背景音乐
    QSound *startsound=new QSound(":/new/prefix1/image/11.wav");
    startsound->play();//
    startsound->setLoops(-1);//循环次数，-1代表一致循环
    //显示UI界面
    MainWindow w;
    w.show();
    return a.exec();
}
