#include "dialog_bar.h"
#include "ui_dialog_bar.h"

Dialog_Bar::Dialog_Bar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Bar)
{
    ui->setupUi(this);
}

Dialog_Bar::~Dialog_Bar()
{
    delete ui;
}
void Dialog_Bar::SHOW(Game_2048 g2048){
    QCursor cursor;
    //加载图片
    QPixmap pixmap("../number_game/image/bar.png");
    //定义大小
    QSize picSize(50, 50);
    //缩放图片，按比例
    QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio);
    //设置样式
    cursor = QCursor(scaledPixmap, -1, -1);
    //更改鼠标形状
    this->setCursor(cursor);

    //通过改变不同位置的样式表来显示不同的数字
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            int x=i*4+j;
            QPushButton *p=nullptr;
            //选择指针指向位置（第几行第几列）
            switch (x) {
            case 0: p=ui->b1;break;
            case 1: p=ui->b2;break;
            case 2: p=ui->b3;break;
            case 3: p=ui->b4;break;
            case 4: p=ui->b5;break;
            case 5: p=ui->b6;break;
            case 6: p=ui->b7;break;
            case 7: p=ui->b8;break;
            case 8: p=ui->b9;break;
            case 9: p=ui->b10;break;
            case 10: p=ui->b11;break;
            case 11: p=ui->b12;break;
            case 12: p=ui->b13;break;
            case 13: p=ui->b14;break;
            case 14: p=ui->b15;break;
            case 15: p=ui->b16;break;
            default:break;
            }
            //选择显示的数据
            switch(g2048.game[i][j])
            {
            case 0:p->setStyleSheet("border-image: url(:/new/prefix1/image/0.jpg)");break;
            case 2:p->setStyleSheet("border-image:url(:/new/prefix1/image/2.jpg)");break;
            case 4:p->setStyleSheet("border-image:url(:/new/prefix1/image/4.jpg)");break;
            case 8:p->setStyleSheet("border-image:url(:/new/prefix1/image/8.jpg)");break;
            case 16:p->setStyleSheet("border-image:url(:/new/prefix1/image/16.jpg)");break;
            case 32:p->setStyleSheet("border-image:url(:/new/prefix1/image/32.jpg)");break;
            case 64:p->setStyleSheet("border-image:url(:/new/prefix1/image/64.jpg)");break;
            case 128:p->setStyleSheet("border-image:url(:/new/prefix1/image/128.jpg)");break;
            case 256:p->setStyleSheet("border-image:url(:/new/prefix1/image/256.jpg)");break;
            case 512:p->setStyleSheet("border-image:url(:/new/prefix1/image/512.jpg)");break;
            case 1024:p->setStyleSheet("border-image:url(:/new/prefix1/image/1024.jpg)");break;
            case 2048:p->setStyleSheet("border-image:url(:/new/prefix1/image/2048.jpg)");break;
            default:break;
            }
        }
    }
    //未发生点击时，把b_2等隐藏
    QPushButton *b_2=ui->b_2;
    b_2->hide();
    QPushButton *b_4=ui->b_4;
    b_4->hide();
    QPushButton *b_8=ui->b_8;
    b_8->hide();
    QPushButton *b_16=ui->b_16;
    b_16->hide();
}

void Dialog_Bar::on_b1_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b1();
}

void Dialog_Bar::on_b2_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b2();
}

void Dialog_Bar::on_b3_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b3();
}

void Dialog_Bar::on_b4_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b4();
}

void Dialog_Bar::on_b5_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b5();
}

void Dialog_Bar::on_b6_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b6();
}

void Dialog_Bar::on_b7_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b7();
}

void Dialog_Bar::on_b8_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b8();
}

void Dialog_Bar::on_b9_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b9();
}

void Dialog_Bar::on_b10_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b10();
}

void Dialog_Bar::on_b11_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b11();
}

void Dialog_Bar::on_b12_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b12();
}

void Dialog_Bar::on_b13_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b13();
}

void Dialog_Bar::on_b14_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b14();
}

void Dialog_Bar::on_b15_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b15();
}

void Dialog_Bar::on_b16_clicked()
{
    //发生点击后，显示出b_2等
    QPushButton *b_2=ui->b_2;
    b_2->show();
    QPushButton *b_4=ui->b_4;
    b_4->show();
    QPushButton *b_8=ui->b_8;
    b_8->show();
    QPushButton *b_16=ui->b_16;
    b_16->show();
    emit this->b16();
}

void Dialog_Bar::on_b_2_clicked()
{
    emit this->b_2();
    this->hide();
}

void Dialog_Bar::on_b_4_clicked()
{
    emit this->b_4();
    this->hide();
}

void Dialog_Bar::on_b_8_clicked()
{
    emit this->b_8();
    this->hide();
}

void Dialog_Bar::on_b_16_clicked()
{
    emit this->b_16();
    this->hide();
}
