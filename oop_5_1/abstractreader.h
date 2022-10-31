#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<string>
#include<vector>
#include<car.h>

class AbstractReader
{
public:
    virtual std::vector<car> readAll() = 0;
    virtual bool isopen() const = 0;
};

#endif // ABSTRACTREADER_H
