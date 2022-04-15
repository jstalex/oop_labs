#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include<QString>
#include <fstream>
#include<json.hpp>

class jsonReader : public AbstractReader
{
    //std::ifstream input;

public:
    std::ifstream input;

    jsonReader(const QString& filename);

    std::vector<bus> readAll()override;
    bool isopen() const override {return input.is_open(); };

    jsonReader& operator >> (car &c);

    operator bool();

    nlohmann::json json;

    int index;
};

#endif // JSONREADER_H
