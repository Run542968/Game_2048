#ifndef FALL_WIDGET_H
#define FALL_WIDGET_H

#include <QWidget>
#include"Game_2048.h"
#include<QKeyEvent>
#include"dialog.h"
#include<QLabel>
#include<dialog_stop.h>
#include <windows.h>
#include <ctime>
#include<fstream>
#include <iostream>
#include"dialog_operationmode.h"
#include<QMouseEvent>
#include"dialog_hammer.h"
#include"dialog_bar.h"

using namespace std;

namespace Ui {
class Game_Widget;
}

class Game_Widget : public QWidget
{
    Q_OBJECT

public:
    Game_2048 g2048;
    explicit Game_Widget(QWidget *parent = nullptr);
    ~Game_Widget();
    void SHOW();
    QString nickname;
    bool operationMode;
    bool input_nickname_dialog();
    QDialog *dialog2;//左右手模式选择弹窗
    Dialog_Hammer *dialog3;//点击锤子弹窗
    Dialog_Bar *dialog4;//点击魔法棒弹窗
    int row;//用于魔法棒弹窗点击的数字
    int col;

signals:
    void exit();//点击返回主页就发送这个信号

public slots:
   void Restart();//槽函数，继续游戏
   void Exit();//槽函数，退出游戏
   void Left();//左手模式
   void Right();//右手模式
   void on_random_button_clicked();
   void on_stop_button_clicked();

private slots:
   void on_hammer_button_clicked();//点击锤子
   void B1();
   void B2();
   void B3();
   void B4();
   void B5();
   void B6();
   void B7();
   void B8();
   void B9();
   void B10();
   void B11();
   void B12();
   void B13();
   void B14();
   void B15();
   void B16();
   void on_bar_button_clicked();//点击魔法棒
   void Bar1();
   void Bar2();
   void Bar3();
   void Bar4();
   void Bar5();
   void Bar6();
   void Bar7();
   void Bar8();
   void Bar9();
   void Bar10();
   void Bar11();
   void Bar12();
   void Bar13();
   void Bar14();
   void Bar15();
   void Bar16();
   void Bar_2();
   void Bar_4();
   void Bar_8();
   void Bar_16();
private:
    void keyPressEvent(QKeyEvent *event);//获取输入并执行相应操作
    Ui::Game_Widget *ui;
    QDialog *dialog;//游戏over弹窗
    QDialog *dialog1;//继续游戏弹窗
    QLabel *lab;
    QLabel *lab1;
    QLabel *lab2;

};

#endif // FALL_WIDGET_H
