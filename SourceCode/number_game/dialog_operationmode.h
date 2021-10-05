#ifndef DIALOG_OPERATIONMODE_H
#define DIALOG_OPERATIONMODE_H

#include <QDialog>

namespace Ui {
class Dialog_OperationMode;
}

class Dialog_OperationMode : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_OperationMode(QWidget *parent = nullptr);
    ~Dialog_OperationMode();
signals:
    void left();
    void right();

private slots:
    void on_left_mode_button_clicked();

    void on_right_mode_button_clicked();

private:
    Ui::Dialog_OperationMode *ui;
};

#endif // DIALOG_OPERATIONMODE_H
