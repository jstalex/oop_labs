#ifndef BUS_H
#define BUS_H
#include "car.h"
#include<QString>

class bus : public car {
public:
    int capacity;
    QString to_string();
};

#endif // BUS_H
