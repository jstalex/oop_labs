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
    QString to_string()const;
    bool operator<(const car &c);
};

std::ostream& operator << (std::ostream &os, const car &c);

#endif // CAR_H
