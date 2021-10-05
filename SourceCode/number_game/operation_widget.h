#ifndef OPERATION_WIDGET_H
#define OPERATION_WIDGET_H

#include <QWidget>

namespace Ui {
class Operation_Widget;
}

class Operation_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Operation_Widget(QWidget *parent = nullptr);
    ~Operation_Widget();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Operation_Widget *ui;
};

#endif // OPERATION_WIDGET_H
