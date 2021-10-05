#include "operation_widget.h"
#include "ui_operation_widget.h"

Operation_Widget::Operation_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Operation_Widget)
{
    ui->setupUi(this);
}

Operation_Widget::~Operation_Widget()
{
    delete ui;
}

void Operation_Widget::on_pushButton_clicked()
{
    emit this->back();
    this->hide();
}
