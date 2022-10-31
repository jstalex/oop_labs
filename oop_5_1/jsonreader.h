#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include<QString>
#include <fstream>
#include<car.h>

class jsonReader : public AbstractReader
{
    std::ifstream input;

public:
    jsonReader(const QString& filename);

    std::vector<car> readAll()override;
    bool isopen() const override {return input.is_open(); };
};

#endif // JSONREADER_H
