#include "bus.h"
#include<iostream>

QString bus::to_string(){
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year)+ ";" + QString::number(capacity);
}

bool bus::operator<(const bus &b){
    return this->year < b.year;
}
std::ostream& bus::operator << (bus &b){
    std::cout << b.to_string().toStdString();
    return std::cout;
}
