#include<iostream>
#include<QString>
#include<car.h>

QString car::to_string(){
    return brand + " " + model + " " + QString::number(year);
}

QString truck::to_string(){
    return brand + " " + model + " " + QString::number(year) + " " + QString::number(weight);
}

QString bus::to_string(){
    return brand + " " + model + " " + QString::number(year) + " " + QString::number(capacity);
}

