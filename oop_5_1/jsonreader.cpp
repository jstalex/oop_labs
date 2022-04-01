#include "jsonreader.h"
#include <json.hpp>
#include <QString>
#include<truck.h>
#include<fstream>

jsonReader::jsonReader(const QString& filename)
{
    input.open(filename.toLatin1().data());
}

std::vector<std::vector<std::string>> jsonReader::readAll(){

    std::vector<std::vector<std::string>> result;
    nlohmann::json json;

    input >> json;

    std::vector<std::string> line;

    int id, color, year;
    std::string brand, model, idS, colorS, yearS;


    for (auto& e: json){
        e.at("id").get_to(id);
        e.at("brand").get_to(brand);
        e.at("model").get_to(model);
        e.at("color").get_to(color);
        e.at("year").get_to(year);

        idS = std::to_string(id);
        colorS = std::to_string(color);
        yearS = std::to_string(year);

        line.push_back(idS);
        line.push_back(brand);
        line.push_back(model);
        line.push_back(colorS);
        line.push_back(yearS);

        result.push_back(line);
        line.clear();
    }

    return result;
}
