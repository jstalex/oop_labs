#include "jsonreader.h"
#include <json.hpp>
#include <QString>
#include<truck.h>
#include<fstream>

jsonReader::jsonReader(const QString& filename)
{
    input.open(filename.toLatin1().data());
    input >> json;
    index = 0;
}

std::vector<bus> jsonReader::readAll(){
    std::vector<bus> result;
    bus temp;
    std::string tempStr;
    int tempColor;
    temp.capacity = 0;

    for (auto& e: json){
        e.at("id").get_to(temp.number);
        e.at("brand").get_to(tempStr);
        temp.brand = QString::fromStdString(tempStr);
        e.at("model").get_to(tempStr);
        temp.model = QString::fromStdString(tempStr);
        e.at("color").get_to(tempColor);
        temp.color = static_cast<colors>(tempColor);
        e.at("year").get_to(temp.year);

        result.push_back(temp);
    }
    // sorting
    std::sort(result.begin(), result.end());
    return result;
}

jsonReader& jsonReader::operator >> (car &c){
    if (!(this->json[index].empty())){
        std::string tempStr;
        int tempColor;

        json[index].at("id").get_to(c.number);
        json[index].at("brand").get_to(tempStr);
        c.brand = QString::fromStdString(tempStr);
        json[index].at("model").get_to(tempStr);
        c.model = QString::fromStdString(tempStr);
        json[index].at("color").get_to(tempColor);
        c.color = static_cast<colors>(tempColor);
        json[index].at("year").get_to(c.year);

        index++;
    }else {
        input.close();
    }

    return *this;
}

jsonReader::operator bool() const{
    return this->isopen();
}







