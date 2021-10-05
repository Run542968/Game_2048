#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QInputDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //来自game_widget的返回主页信号
    connect(&gw,SIGNAL(exit()),this,SLOT(receive_exit_singnals()));
    //来自sort_widget的返回主页信号
    connect(&sw,SIGNAL(back()),this,SLOT(receive_exit_singnals()));
    //来自operation_widget的返回主页信号
    connect(&ow,SIGNAL(back()),this,SLOT(receive_exit_singnals()));
    //来自author_widget的返回主页信号
    connect(&aw,SIGNAL(back()),this,SLOT(receive_exit_singnals()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()//开始游戏按钮点击
{
    gw.dialog2->show();
    this->hide();
}

void MainWindow::receive_exit_singnals(){//接收到返回主页信号
    this->show();
}


void MainWindow::on_pushButton_2_clicked()//排行榜按钮点击
{
    this->hide();
    sw.computeSort();
    sw.show();
}

void MainWindow::on_pushButton_3_clicked()//操作说明点击
{
    this->hide();
    ow.show();
}

void MainWindow::on_pushButton_4_clicked()//关于作者点击
{
    this->hide();
    aw.show();
}
