#ifndef DATAREADER_H
#define DATAREADER_H
#include<QString>
#include <fstream>
#include<vector>
#include<car.h>

class Datareader
{
    std::ifstream input;
public:
    Datareader(const QString& filename);
    ~Datareader();
    bool isopen() const;
    std::vector<car> readAll();
};

#endif // DATAREADER_H
