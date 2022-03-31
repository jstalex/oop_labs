#ifndef DATAREADER_H
#define DATAREADER_H
#include<QString>
#include <fstream>
#include<vector>
#include<car.h>

class Datareader
{
    Datareader(const Datareader&) = delete;
    Datareader& operator=(const Datareader&) = delete;
public:
    std::ifstream input;
    Datareader( QString filename);
    ~Datareader();
    bool isopen() const;
    std::vector<std::vector<std::string>> readAll();
    //Оператор присваивания перемещением
    Datareader& operator= (Datareader&& orther);
    // Конструктор перемещения
    Datareader(Datareader&& orther);
};

#endif // DATAREADER_H
