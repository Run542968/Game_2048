#ifndef DIALOG_HAMMER_H
#define DIALOG_HAMMER_H

#include <QDialog>
#include<Game_2048.h>

namespace Ui {
class Dialog_Hammer;
}

class Dialog_Hammer : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Hammer(QWidget *parent = nullptr);
    ~Dialog_Hammer();
    void SHOW(Game_2048 g2048);
signals:
    void b1();//b1被锤子点击
    void b2();
    void b3();
    void b4();
    void b5();
    void b6();
    void b7();
    void b8();
    void b9();//b9被锤子点击
    void b10();
    void b11();
    void b12();
    void b13();
    void b14();
    void b15();
    void b16();
private slots:
    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_b10_clicked();

    void on_b11_clicked();

    void on_b12_clicked();

    void on_b13_clicked();

    void on_b14_clicked();

    void on_b15_clicked();

    void on_b16_clicked();

private:
    Ui::Dialog_Hammer *ui;
};

#endif // DIALOG_HAMMER_H
