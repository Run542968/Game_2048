#include "dialog_operationmode.h"
#include "ui_dialog_operationmode.h"

Dialog_OperationMode::Dialog_OperationMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_OperationMode)
{
    ui->setupUi(this);
}

Dialog_OperationMode::~Dialog_OperationMode()
{
    delete ui;
}

void Dialog_OperationMode::on_left_mode_button_clicked()
{
    emit this->left();
    this->hide();
}

void Dialog_OperationMode::on_right_mode_button_clicked()
{
    emit this->right();
    this->hide();
}
