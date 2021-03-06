#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include<QString>
#include <fstream>
#include<json.hpp>
#include<exception>
#include <iostream>

class jsonReader : public AbstractReader
{
public:
    std::ifstream input;

    jsonReader(const QString& filename);

    std::vector<bus> readAll()override;
    bool isopen() const override {return input.is_open(); };

    jsonReader& operator >> (car &c) override;

    operator bool() const override;

    nlohmann::json json;
    // for while in mainwindow
    int index;
};

#endif // JSONREADER_H
