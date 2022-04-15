#include "bus.h"
#include<iostream>

QString bus::to_string() const {
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year)+ ";" + QString::number(capacity);
}

bool bus::operator<(const bus &b){
    return this->year < b.year;
}

std::ostream& operator << (std::ostream &os, const bus &b)
{
    return os << b.to_string().toStdString();
}

