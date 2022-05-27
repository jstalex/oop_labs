#ifndef FIGURE_H
#define FIGURE_H

#include <QPoint>
#include <array>
#include <QPainter>
#include <QPolygon>
#include <vector>
#include <QVector>
#include <QRectF>

struct Figure
{
    virtual void draw(QPainter& painter) = 0;
    virtual ~Figure() {};
};

struct circle : public Figure
{
    circle(QPoint center, int radius) : center_(center), radius_(radius) {}

    void draw(QPainter &painter) override {
        painter.drawEllipse(center_, radius_, radius_);
    }
    QPoint center_;
    int radius_;
};

struct triangle : public Figure
{
    triangle(QPoint vert1, QPoint vert2, QPoint vert3) :  vert1_(vert1), vert2_(vert2), vert3_(vert3) {}

    void draw(QPainter &painter) override {
        painter.setPen(Qt::blue);
        painter.drawPolygon(verts);
    }
    QPoint vert1_, vert2_, vert3_;
    QVector<QPoint> verts = {vert1_, vert2_, vert3_};
    //std::array<QPoint, 3> verts_;

};

struct square : public Figure
{
    square(QRectF coord) : coord_(coord){};//, width_(width), height_(height) {}

    void draw(QPainter &painter) override {
        painter.setPen(Qt::red);
        painter.drawRect(coord_);
    }
    QRectF coord_;
    int width_;
    int height_;
    //QVector<QPoint> square = {coord_, width_, height_};
    //rectangle = (coord_, width_, height_);

};

#endif // FIGURE_H
