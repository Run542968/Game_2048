#ifndef DIALOG_BAR_H
#define DIALOG_BAR_H

#include <QDialog>
#include<Game_2048.h>

namespace Ui {
class Dialog_Bar;
}

class Dialog_Bar : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Bar(QWidget *parent = nullptr);
    ~Dialog_Bar();
    void SHOW(Game_2048 g2048);
signals:
    void b1();
    void b2();
    void b3();
    void b4();
    void b5();
    void b6();
    void b7();
    void b8();
    void b9();
    void b10();
    void b11();
    void b12();
    void b13();
    void b14();
    void b15();
    void b16();
    void b_2();
    void b_4();
    void b_8();
    void b_16();
private slots:
    void on_b1_clicked();

    void on_b_2_clicked();

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

    void on_b_4_clicked();

    void on_b_8_clicked();

    void on_b_16_clicked();

private:
    Ui::Dialog_Bar *ui;
};

#endif // DIALOG_BAR_H
