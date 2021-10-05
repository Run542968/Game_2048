#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_restart_clicked()
{
    emit this->restart();
    this->hide();
}

void Dialog::on_exit_clicked()
{
    emit this->exit();
    this->hide();
}
