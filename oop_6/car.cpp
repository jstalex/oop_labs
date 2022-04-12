#include<iostream>
#include<QString>
#include<car.h>

QString car::to_string(){
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year);
}
bool car::operator<(const car &c){
    return this->year < c.year;
}
std::ostream& car::operator << (car &b){
    std::cout << b.to_string().toStdString();
    return std::cout;
}
