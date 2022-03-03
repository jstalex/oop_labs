#include "datawriter.h"
#include <iostream>
#include <string>
#include <QString>
#include <vector>
#include <fstream>
#include<car.h>

datawriter::datawriter(const QString& filename)
{
    output.open(filename.toStdString(), std::ios::app);
}

datawriter::~datawriter(){
    output.close();
}

bool datawriter::isopen() const{return output.is_open();};

void datawriter::writecar( car c){
    if (output.is_open())
    {
        output << std::to_string(c.number) + ";" + c.brand.toStdString() + ";" + c.model.toStdString() + ";" + std::to_string(c.color) + ";" + std::to_string(c.year) << std::endl;
    }
    output.close();
}
