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
// добавляем одну строку в конец файла
void datawriter::writecar( QString c){
    if (output.is_open())
    {
        output << c.toStdString() << std::endl;
    }
    output.close();
}
