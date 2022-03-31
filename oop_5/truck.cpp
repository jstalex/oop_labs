#include "truck.h"
#include "car.h"

QString truck::to_string(){
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year)+ ";" + QString::number(weight);
}
