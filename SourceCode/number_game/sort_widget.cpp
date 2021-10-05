#include "sort_widget.h"
#include "ui_sort_widget.h"


//文件操作-读取分数记录，用于制作排行榜
typedef struct
{
    int x;
    char name[30];
    char time[20];
}Record;


Sort_Widget::Sort_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sort_Widget)
{
    ui->setupUi(this);
}

Sort_Widget::~Sort_Widget()
{
    delete ui;
}
void Sort_Widget::computeSort(){//计算文件中积分顺序
    FILE* in;
    Record a[100];
    Record t;
    int n = 0;
    int c1=0;
    int c2=0;
    int c3=0;
    int c4=0;
    int c5=0;

    in = fopen("./2048_Score.txt", "r");//txt文件在构造后产生的build目录里，但是这样就可以读取信息
    while (fscanf(in, "%s   %s   %d,", a[n].time, a[n].name, &a[n].x) != EOF)
        n++;
    //根据分数进行从大到小排序
    for (int i = 1; i <n; i++)
    {
        for (int j = i - 1; j >= 0 && a[j+1].x > a[j].x; j--)
        {
            t = a[j];
            a[j] = a[j + 1];
            a[j + 1] = t;
        }
    }
    fclose(in);
    printf("%d",n);
    //label加内容
    QLabel *x1=nullptr;
    QLabel *x2=nullptr;
    QLabel *x3=nullptr;
    if(n>=5){
        c1=1;
        c2=1;
        c3=1;
        c4=1;
        c5=1;
    }else if(n==4){
        c1=1;
        c2=1;
        c3=1;
        c4=1;
    }else if(n==3){
        c1=1;
        c2=1;
        c3=1;
    }else if(n==2){
        c1=1;
        c2=1;
    }else if(n==1){
        c1=1;
    }
    if(c1){
    x1=ui->l1;
    x1->setText(a[0].name);
    x2=ui->l2;
    QString str = QString::number(a[0].x);
    x2->setText(str);
    x3=ui->l3;
    x3->setText(a[0].time);
    }
    if(c2){
    x1=ui->l4;
    x1->setText(a[1].name);
    x2=ui->l5;
    QString str = QString::number(a[1].x);
    x2->setText(str);
    x3=ui->l6;
    x3->setText(a[1].time);
    }
    if(c3){
    x1=ui->l7;
    x1->setText(a[2].name);
    x2=ui->l8;
    QString str = QString::number(a[2].x);
    x2->setText(str);
    x3=ui->l9;
    x3->setText(a[2].time);
    }
    if(c4){
    x1=ui->l10;
    x1->setText(a[3].name);
    x2=ui->l11;
    QString str = QString::number(a[3].x);
    x2->setText(str);
    x3=ui->l12;
    x3->setText(a[3].time);
    }
    if(c5){
    x1=ui->l13;
    x1->setText(a[4].name);
    x2=ui->l14;
    QString str = QString::number(a[4].x);
    x2->setText(str);
    x3=ui->l15;
    x3->setText(a[4].time);
    }
}

void Sort_Widget::on_pushButton_clicked()//点击返回主页按钮
{
    emit this->back();
    this->hide();
}
