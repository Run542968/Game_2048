#ifndef DIALOG_STOP_H
#define DIALOG_STOP_H

#include <QDialog>

namespace Ui {
class Dialog_Stop;
}

class Dialog_Stop : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Stop(QWidget *parent = nullptr);
    ~Dialog_Stop();
signals:
    void exit();//返回主界面信号
private slots:
    void on_exit_button_clicked();

    void on_continue_button_clicked();

private:
    Ui::Dialog_Stop *ui;
};

#endif // DIALOG_STOP_H
