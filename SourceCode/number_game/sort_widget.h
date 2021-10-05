#ifndef SORT_WIDGET_H
#define SORT_WIDGET_H

#include <QWidget>
#include<QLabel>

namespace Ui {
class Sort_Widget;
}

class Sort_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Sort_Widget(QWidget *parent = nullptr);
    ~Sort_Widget();
    void computeSort();//获取分数文件信息并排序
signals:
    void back();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Sort_Widget *ui;
};

#endif // SORT_WIDGET_H
