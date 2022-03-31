#include "jsonreader.h"
#include <json.hpp>
#include <QString>

jsonReader::jsonReader(const QString& filename)
{
    input.open(filename.toLatin1().data());
}

std::vector<std::vector<std::string>> jsonReader::readAll(){

    std::vector<std::vector<std::string>> result;
    nlohmann::json json;

    input >> json;
    std::vector<std::string> line;
    for (auto& e: json){
        line.push_back(e.at("id"));
        line.push_back(e.at("brand"));
        line.push_back(e.at("model"));
        line.push_back(e.at("color"));
        line.push_back(e.at("year"));
        result.push_back(line);
        line.clear();
    }

    return result;
}
