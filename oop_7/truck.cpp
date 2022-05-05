#include "truck.h"
#include "car.h"

QString truck::to_string() const{
    return QString::number(number) + ";" + brand + ";" + model + ";" + QString::number(color) + ";" + QString::number(year)+ ";" + QString::number(weight);
}

bool truck::operator<(const truck &t){
    return this->year < t.year;
}

std::ostream& operator << (std::ostream &os, const truck &t)
{
    return os << t.to_string().toStdString();
}
