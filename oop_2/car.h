#ifndef CAR_H
#define CAR_H
#include<QString>

enum colors {
    red,
    green,
    blue,
    purple
};

struct car {
    int number;
    QString brand;
    QString model;
    colors color;
    int year;
};

#endif // CAR_H
