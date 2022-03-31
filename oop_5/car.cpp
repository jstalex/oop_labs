#include<iostream>
#include<QString>
#include<car.h>

QString car::to_string(){
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year);
}


