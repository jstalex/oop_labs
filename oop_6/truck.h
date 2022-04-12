#ifndef TRUCK_H
#define TRUCK_H

#include "car.h"
#include<QString>

class truck : public car {
public:
    int weight;
    QString to_string();
};

#endif // TRUCK_H
