#ifndef AUTHOR_WIDGET_H
#define AUTHOR_WIDGET_H

#include <QWidget>

namespace Ui {
class Author_Widget;
}

class Author_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Author_Widget(QWidget *parent = nullptr);
    ~Author_Widget();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Author_Widget *ui;
};

#endif // AUTHOR_WIDGET_H
