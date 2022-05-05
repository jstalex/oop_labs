#ifndef TRUCK_H
#define TRUCK_H

#include "car.h"
#include<QString>

class truck : public car {
public:
    int weight;
    QString to_string()const;
    bool operator<(const truck &t);
};

std::ostream& operator << (std::ostream &os, const truck &t);

#endif // TRUCK_H
