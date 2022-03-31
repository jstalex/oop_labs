#ifndef CAR_H
#define CAR_H
#include<QString>

enum colors {
    red,
    green,
    blue,
    purple
};

class car {
public:
    int number;
    QString brand;
    QString model;
    colors color;
    int year;
    QString to_string();
};
#endif // CAR_H
