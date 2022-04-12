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
    bool operator<(const car &c);
    std::ostream& operator << (car &b);
};
#endif // CAR_H
