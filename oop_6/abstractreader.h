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
    AbstractReader& operator >> (car &c);
    operator bool();
};

#endif // ABSTRACTREADER_H
