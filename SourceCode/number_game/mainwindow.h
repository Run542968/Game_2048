#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"game_widget.h"
#include <QMainWindow>
#include<sort_widget.h>
#include"operation_widget.h"
#include"author_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Game_Widget gw ;
    Sort_Widget sw;
    Operation_Widget ow;
    Author_Widget aw;

private slots:
    void receive_exit_singnals();//接收到返回主页信号
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
