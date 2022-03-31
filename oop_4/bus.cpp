#include "bus.h"

QString bus::to_string(){
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year)+ ";" + QString::number(capacity);
}
