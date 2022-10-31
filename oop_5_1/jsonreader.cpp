#include "jsonreader.h"
#include <json.hpp>
#include <QString>
#include<truck.h>
#include<fstream>

jsonReader::jsonReader(const QString& filename)
{
    input.open(filename.toLatin1().data());
}

std::vector<car> jsonReader::readAll(){

    std::vector<car> result;
    car tempcar;
    nlohmann::json json;

    input >> json;

    std::string brand, model;


    for (auto& e: json){
        e.at("id").get_to(tempcar.number);
        e.at("brand").get_to(brand);
        e.at("model").get_to(model);
        tempcar.brand = QString::fromStdString(brand);
        tempcar.model = QString::fromStdString(model);
        e.at("color").get_to(tempcar.color);
        e.at("year").get_to(tempcar.year);
        result.push_back(tempcar);
    }

    return result;
}
