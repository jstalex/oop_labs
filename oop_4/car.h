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

class truck : public car {
public:
    int weight;
    QString to_string();
};

class bus : public car {
public:
    int capacity;
    QString to_string();
};

#endif // CAR_H
