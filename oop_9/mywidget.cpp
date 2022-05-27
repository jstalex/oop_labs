#include <QPainter>
#include "mywidget.h"
#include <figure.h>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    figures.push_back(new circle({200, 100}, 60)); //left eye
    figures.push_back(new circle({500, 100}, 60)); //right eye

    figures.push_back(new circle({200, 100}, 10)); //left pupil
    figures.push_back(new circle({500, 100}, 100)); //right pupil (...10)

    figures.push_back(new triangle({270, 200}, {430, 200}, {350, 450}));
    figures.push_back(new square({300, 500, 100, 100}));
}

MyWidget::~MyWidget()
{
    for (auto& f: figures)
        delete f;
}
void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::magenta);

    for (const auto& f: figures)
    {
        f->draw(painter);
    }
    //painter.drawLine(30, 40, 200, 300);
    //painter.drawEllipse(250, 250, 100, 100);
}
