#include "dialog_stop.h"
#include "ui_dialog_stop.h"

Dialog_Stop::Dialog_Stop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Stop)
{
    ui->setupUi(this);
}

Dialog_Stop::~Dialog_Stop()
{
    delete ui;
}

void Dialog_Stop::on_exit_button_clicked()
{
    emit this->exit();
    this->hide();
}

void Dialog_Stop::on_continue_button_clicked()
{
    this->hide();
}
