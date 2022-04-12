#ifndef JSONREADER_H
#define JSONREADER_H
#include "abstractreader.h"
#include<QString>
#include <fstream>

class jsonReader : public AbstractReader
{
    std::ifstream input;

public:
    jsonReader(const QString& filename);

    std::vector<bus> readAll()override;
    bool isopen() const override {return input.is_open(); };
};

#endif // JSONREADER_H
