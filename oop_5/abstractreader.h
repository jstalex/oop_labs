#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<string>
#include<vector>

class AbstractReader
{
public:
    virtual std::vector<std::vector<std::string>> readAll() = 0;
    virtual bool isopen() const = 0;
};

#endif // ABSTRACTREADER_H
