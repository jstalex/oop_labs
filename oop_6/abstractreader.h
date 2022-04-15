#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<string>
#include<vector>
#include<bus.h>
//#include<mainwindow.h>

class AbstractReader
{
public:
    virtual std::vector<bus> readAll() = 0;
    virtual bool isopen() const = 0;
    virtual AbstractReader& operator >> (car &c) = 0;
    virtual operator bool()const = 0;
};

#endif // ABSTRACTREADER_H
