#include "game_widget.h"
#include "ui_game_widget.h"
#include<QGraphicsView>
#include<QInputDialog>
#include<QLCDNumber>
#include<QToolButton>

Game_Widget::Game_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game_Widget)
{
    ui->setupUi(this);
    this->setFocus();
    g2048.Begin();//初始化二维数组
    this->SHOW();
    /* 设置对话框 */
    dialog =new Dialog(this);
    dialog->setModal(true);//模态窗口模式
    dialog->setWindowTitle("游戏结束");
    dialog->hide();
    lab=new QLabel(dialog);
    lab->move(120,30);
    lab1=new QLabel(dialog);
    lab1->move(70,180);
    lab2=new QLabel(dialog);
    lab2->move(230,180);
    //游戏继续弹窗
    dialog1 =new Dialog_Stop(this);
    dialog1->setModal(true);//模态窗口模式
    dialog1->setWindowTitle("游戏暂停");
    dialog1->hide();
    //左右手选择弹窗
    dialog2 =new Dialog_OperationMode(this);
    dialog2->setModal(true);//模态窗口模式
    dialog2->setWindowTitle("模式选择");
    dialog2->hide();
    //锤子清除弹窗
    dialog3 =new Dialog_Hammer(this);
    dialog3->setModal(true);//模态窗口模式
    dialog3->setWindowTitle("使用道具");
    dialog3->hide();
    //魔法棒替换弹窗
    dialog4 =new Dialog_Bar(this);
    dialog4->setModal(true);//模态窗口模式
    dialog4->setWindowTitle("使用道具");
    dialog4->hide();
    //连接信号和槽
    //游戏结束dialog
    connect(dialog,SIGNAL(restart()),this,SLOT(Restart()));
    connect(dialog,SIGNAL(exit()),this,SLOT(Exit()));
    //游戏暂停dialog
    connect(dialog1,SIGNAL(exit()),this,SLOT(Exit()));
    //左右手模式dialog
    connect(dialog2,SIGNAL(left()),this,SLOT(Left()));
    connect(dialog2,SIGNAL(right()),this,SLOT(Right()));
    //锤子消除dialog
    connect(dialog3,SIGNAL(b1()),this,SLOT(B1()));
    connect(dialog3,SIGNAL(b2()),this,SLOT(B2()));
    connect(dialog3,SIGNAL(b3()),this,SLOT(B3()));
    connect(dialog3,SIGNAL(b4()),this,SLOT(B4()));
    connect(dialog3,SIGNAL(b5()),this,SLOT(B5()));
    connect(dialog3,SIGNAL(b6()),this,SLOT(B6()));
    connect(dialog3,SIGNAL(b7()),this,SLOT(B7()));
    connect(dialog3,SIGNAL(b8()),this,SLOT(B8()));
    connect(dialog3,SIGNAL(b9()),this,SLOT(B9()));
    connect(dialog3,SIGNAL(b10()),this,SLOT(B10()));
    connect(dialog3,SIGNAL(b11()),this,SLOT(B11()));
    connect(dialog3,SIGNAL(b12()),this,SLOT(B12()));
    connect(dialog3,SIGNAL(b13()),this,SLOT(B13()));
    connect(dialog3,SIGNAL(b14()),this,SLOT(B14()));
    connect(dialog3,SIGNAL(b15()),this,SLOT(B15()));
    connect(dialog3,SIGNAL(b16()),this,SLOT(B16()));
    //魔法棒替换dialog
    connect(dialog4,SIGNAL(b1()),this,SLOT(Bar1()));
    connect(dialog4,SIGNAL(b2()),this,SLOT(Bar2()));
    connect(dialog4,SIGNAL(b3()),this,SLOT(Bar3()));
    connect(dialog4,SIGNAL(b4()),this,SLOT(Bar4()));
    connect(dialog4,SIGNAL(b5()),this,SLOT(Bar5()));
    connect(dialog4,SIGNAL(b6()),this,SLOT(Bar6()));
    connect(dialog4,SIGNAL(b7()),this,SLOT(Bar7()));
    connect(dialog4,SIGNAL(b8()),this,SLOT(Bar8()));
    connect(dialog4,SIGNAL(b9()),this,SLOT(Bar9()));
    connect(dialog4,SIGNAL(b10()),this,SLOT(Bar10()));
    connect(dialog4,SIGNAL(b11()),this,SLOT(Bar11()));
    connect(dialog4,SIGNAL(b12()),this,SLOT(Bar12()));
    connect(dialog4,SIGNAL(b13()),this,SLOT(Bar16()));
    connect(dialog4,SIGNAL(b14()),this,SLOT(Bar14()));
    connect(dialog4,SIGNAL(b15()),this,SLOT(Bar15()));
    connect(dialog4,SIGNAL(b16()),this,SLOT(Bar16()));
    connect(dialog4,SIGNAL(b_2()),this,SLOT(Bar_2()));
    connect(dialog4,SIGNAL(b_4()),this,SLOT(Bar_4()));
    connect(dialog4,SIGNAL(b_8()),this,SLOT(Bar_8()));
    connect(dialog4,SIGNAL(b_16()),this,SLOT(Bar_16()));
}

Game_Widget::~Game_Widget()
{
    delete ui;
}

void Game_Widget::SHOW()
{
    g2048.computeScore();//计算分数用于显示
    g2048.computeRandom_chance();//计算重置次数
    g2048.computeHammer_chance();//计算锤子次数
    g2048.computeBar_chance();//计算魔法棒次数
    //通过改变不同位置的样式表来显示不同的数字
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            int x=i*4+j;
            QGraphicsView *p=nullptr;
            //选择指针指向位置（第几行第几列）
            switch (x) {
            case 0: p=ui->graphicsView_1;break;
            case 1: p=ui->graphicsView_2;break;
            case 2: p=ui->graphicsView_3;break;
            case 3: p=ui->graphicsView_4;break;
            case 4: p=ui->graphicsView_5;break;
            case 5: p=ui->graphicsView_6;break;
            case 6: p=ui->graphicsView_7;break;
            case 7: p=ui->graphicsView_8;break;
            case 8: p=ui->graphicsView_9;break;
            case 9: p=ui->graphicsView_10;break;
            case 10: p=ui->graphicsView_11;break;
            case 11: p=ui->graphicsView_12;break;
            case 12: p=ui->graphicsView_13;break;
            case 13: p=ui->graphicsView_14;break;
            case 14: p=ui->graphicsView_15;break;
            case 15: p=ui->graphicsView_16;break;
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

    //显示当前分数
    QLCDNumber *r1=nullptr;
    r1=ui->record;
    r1->display(g2048.score);
    //显示最高分
    QLCDNumber *r2=nullptr;
    r2=ui->best_record;
    r2->display(g2048.FirstOrder());
    //重置机会按钮显示
    QToolButton *b=nullptr;
    b=ui->random_button;
    b->setFocusPolicy(Qt::NoFocus);
    if(g2048.random_chance>0){
    b->setStyleSheet("border-image:url(:/new/prefix1/image/random.png)");
    }else{
    b->setStyleSheet("border-image:url(:/new/prefix1/image/random1.png)");
    }
    //锤子按钮显示
    QPushButton *h=nullptr;
    h=ui->hammer_button;
    h->setFocusPolicy(Qt::NoFocus);
    if(g2048.hammer_chance>0){
    h->setStyleSheet("border-image:url(:/new/prefix1/image/hammer.png)");
    }else{
    h->setStyleSheet("border-image:url(:/new/prefix1/image/hammer1.png)");
    }
    //魔法棒按钮显示
    QPushButton *bar=nullptr;
    bar=ui->bar_button;
    bar->setFocusPolicy(Qt::NoFocus);
    if(g2048.bar_chance>0){
    bar->setStyleSheet("border-image:url(:/new/prefix1/image/bar.png)");
    }else{
    bar->setStyleSheet("border-image:url(:/new/prefix1/image/bar1.png)");
    }
}

void Game_Widget::keyPressEvent(QKeyEvent *event){
    this->setFocusPolicy(Qt::StrongFocus);
    //右手模式
    if(this->operationMode){
        //根据按键执行相应的函数
        if(g2048.Judge()==3){
            if(event->key()==Qt::Key_Up)
            {
                g2048.Process(1);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_Down)
            {
                g2048.Process(2);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_Left)
            {
                g2048.Process(3);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_Right)
            {
                g2048.Process(4);
                g2048.CreateNumber();
            }
            this->SHOW();
        }else if(g2048.Judge()==1){
            lab->setText("你输了，是否继续？");
            lab1->setText("再来一局");
            lab2->setText("返回主页");
            dialog->show();
        }else if(g2048.Judge()==2){
            lab->setText("你赢了，是否继续？");
            lab1->setText("再来一局");
            lab2->setText("返回主页");
            dialog->show();
        }
    }else{
        //根据按键执行相应的函数
        if(g2048.Judge()==3){
            if(event->key()==Qt::Key_W)
            {
                g2048.Process(1);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_S)
            {
                g2048.Process(2);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_A)
            {
                g2048.Process(3);
                g2048.CreateNumber();
            }
            if(event->key()==Qt::Key_D)
            {
                g2048.Process(4);
                g2048.CreateNumber();
            }
            this->SHOW();
        }else if(g2048.Judge()==1){
            lab->setText("你输了，是否继续？");
            lab1->setText("再来一局");
            lab2->setText("返回主页");
            dialog->show();
        }else if(g2048.Judge()==2){
            lab->setText("你赢了，是否继续？");
            lab1->setText("再来一局");
            lab2->setText("返回主页");
            dialog->show();
        }
    }
}
void Game_Widget::Restart(){//再来一局
    //再点击再来一局后，先保存积分
    SYSTEMTIME sys;
    GetLocalTime(&sys);//获取当前系统时间戳
    char *ch;
    ch=nickname.toLatin1().data();
    ofstream file;//需要用到using namespace std
    file.open("2048_Score.txt", ios::app);//添加ios::app后，就会在文件后面追加信息，而不是覆盖原有信息
    file << sys.wYear << '/' << sys.wMonth << '/' << sys.wDay << '-' <<
        sys.wHour << ':' << sys.wMinute << "   " <<ch<<"   "<<g2048.score << endl;              //将时间记-最终分数-昵称录进入文件
    file.close();
    g2048.Begin();
    this->SHOW();
}
void Game_Widget::Exit(){//返回主页面
    if(nickname.size()){//如果存在nickname说明正常结束游戏，记录分数
        SYSTEMTIME sys;
        GetLocalTime(&sys);//获取当前系统时间戳
        char *ch;
        ch=nickname.toLatin1().data();
        ofstream file;//需要用到using namespace std
        file.open("2048_Score.txt", ios::app);//添加ios::app后，就会在文件后面追加信息，而不是覆盖原有信息
        file << sys.wYear << '/' << sys.wMonth << '/' << sys.wDay << '-' <<
            sys.wHour << ':' << sys.wMinute << "   " <<ch<<"   "<<g2048.score << endl;              //将时间记-最终分数-昵称录进入文件
        file.close();
        emit this->exit();
        g2048.Begin();
        this->SHOW();
        this->close();
    }else{//说明在输入昵称时点击了取消，不记录分数
        emit this->exit();
        g2048.Begin();
        this->SHOW();
        this->close();
    }
}

void Game_Widget::on_random_button_clicked()//重置数字块
{
    g2048.Random();
    this->SHOW();
}

void Game_Widget::on_stop_button_clicked()//暂停
{
    dialog1->show();
}

bool Game_Widget::input_nickname_dialog(){//输入昵称弹窗
     this->hide();
     bool ok;
     QString text = QInputDialog::getText(this, tr("输入昵称"),tr("请输入您的昵称"), QLineEdit::Normal,"Your Nickname", &ok);
     if (ok && !text.isEmpty())
     {
         this->nickname=text;
         this->show();
         return true;
     }else{
         this->Exit();
         return false;
     }
}
void Game_Widget::Left(){//左手模式槽函数
    this->operationMode=false;
    dialog2->hide();
    this->input_nickname_dialog();
}
void Game_Widget::Right(){//右手模式槽函数
    this->operationMode=true;
    dialog2->hide();
    this->input_nickname_dialog();
}

void Game_Widget::on_hammer_button_clicked()//点击锤子按钮后，打开dialog
{
    if(g2048.hammer_chance>0){
    dialog3->show();
    dialog3->SHOW(g2048);
    //this->setCursor(Qt::ArrowCursor);鼠标变为箭头
    }
}

void Game_Widget::B1(){//锤子消除的槽函数
    g2048.game[0][0]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B2(){
    g2048.game[0][1]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B3(){
    g2048.game[0][2]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B4(){
    g2048.game[0][3]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B5(){
    g2048.game[1][0]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B6(){
    g2048.game[1][1]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B7(){
    g2048.game[1][2]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B8(){
    g2048.game[1][3]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B9(){
    g2048.game[2][0]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B10(){
    g2048.game[2][1]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B11(){
    g2048.game[2][2]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B12(){
    g2048.game[2][3]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B13(){
    g2048.game[3][0]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B14(){
    g2048.game[3][1]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B15(){
    g2048.game[3][2]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}
void Game_Widget::B16(){
    g2048.game[3][3]=0;
    g2048.Hammer();//把锤子次数减一
    this->SHOW();
}

void Game_Widget::on_bar_button_clicked()//点击魔法棒后，打开dialog
{
    dialog4->show();
    dialog4->SHOW(g2048);
}
void Game_Widget::Bar1(){
    this->row=0;
    this->col=0;
    g2048.Bar();
}
void Game_Widget::Bar2(){
    this->row=0;
    this->col=1;
    g2048.Bar();
}
void Game_Widget::Bar3(){
    this->row=0;
    this->col=2;
    g2048.Bar();
}
void Game_Widget::Bar4(){
    this->row=0;
    this->col=3;
    g2048.Bar();
}
void Game_Widget::Bar5(){
    this->row=1;
    this->col=0;
    g2048.Bar();
}
void Game_Widget::Bar6(){
    this->row=1;
    this->col=1;
    g2048.Bar();
}
void Game_Widget::Bar7(){
    this->row=1;
    this->col=2;
    g2048.Bar();
}
void Game_Widget::Bar8(){
    this->row=1;
    this->col=3;
    g2048.Bar();
}
void Game_Widget::Bar9(){
    this->row=2;
    this->col=0;
    g2048.Bar();
}
void Game_Widget::Bar10(){
    this->row=2;
    this->col=1;
    g2048.Bar();
}
void Game_Widget::Bar11(){
    this->row=2;
    this->col=2;
    g2048.Bar();
}
void Game_Widget::Bar12(){
    this->row=2;
    this->col=3;
    g2048.Bar();
}
void Game_Widget::Bar13(){
    this->row=3;
    this->col=0;
    g2048.Bar();
}
void Game_Widget::Bar14(){
    this->row=3;
    this->col=1;
    g2048.Bar();
}
void Game_Widget::Bar15(){
    this->row=3;
    this->col=2;
    g2048.Bar();
}
void Game_Widget::Bar16(){
    this->row=3;
    this->col=3;
    g2048.Bar();
}
void Game_Widget::Bar_2(){
    g2048.game[this->row][this->col]=2;
    this->SHOW();
}
void Game_Widget::Bar_4(){
    g2048.game[this->row][this->col]=4;
    this->SHOW();
}
void Game_Widget::Bar_8(){
    g2048.game[this->row][this->col]=8;
    this->SHOW();
}
void Game_Widget::Bar_16(){
    g2048.game[this->row][this->col]=16;
    this->SHOW();
}
