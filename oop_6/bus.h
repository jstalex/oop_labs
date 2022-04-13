#ifndef BUS_H
#define BUS_H
#include "car.h"
#include<QString>
#include<fstream>

class bus : public car {
public:
    int capacity;
    const QString to_string() const;
    // for sorting
    bool operator<(const bus &b);
    // for writing in stream
    //std::ostream& operator << (bus &b);
};

std::ostream& operator << (std::ostream &os, const bus &b);

#endif // BUS_H
