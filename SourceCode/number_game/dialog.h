#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void restart();
    void exit();

private slots:
    void on_restart_clicked();

    void on_exit_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
