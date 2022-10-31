#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <figure.h>
#include <vector>

class MyWidget: public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    std::vector<Figure*> figures;
};

#endif // MYWIDGET_H
