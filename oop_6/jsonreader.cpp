#include "jsonreader.h"
#include <json.hpp>
#include <QString>
#include<truck.h>
#include<fstream>

jsonReader::jsonReader(const QString& filename)
{
    input.open(filename.toLatin1().data());
}

std::vector<bus> jsonReader::readAll(){
    std::vector<bus> result;
    bus temp;
    std::string tempStr;
    int tempColor;
    temp.capacity = 0;

    nlohmann::json json;

    input >> json;

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
    return result;
}
