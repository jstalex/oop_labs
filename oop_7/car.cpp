#include<iostream>
#include<QString>
#include<car.h>

QString car::to_string() const{
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year);
}
bool car::operator<(const car &c){
    return this->year < c.year;
}

std::ostream& operator << (std::ostream &os, const car &c)
{
    return os << c.to_string().toStdString();
}
