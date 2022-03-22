#ifndef DATAWRITER_H
#define DATAWRITER_H
#include<QString>
#include <fstream>
#include<vector>
#include<car.h>


class datawriter
{
    std::ofstream output;
public:
    datawriter(const QString& filename);
    ~datawriter();
    bool isopen() const;
    void writecar( car c);
};


#endif // DATAWRITER_H
