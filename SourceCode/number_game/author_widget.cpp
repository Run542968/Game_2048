#include "author_widget.h"
#include "ui_author_widget.h"

Author_Widget::Author_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Author_Widget)
{
    ui->setupUi(this);
}

Author_Widget::~Author_Widget()
{
    delete ui;
}

void Author_Widget::on_pushButton_clicked()
{
    emit this->back();
    this->hide();
}
