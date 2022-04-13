#ifndef DATAREADER_H
#define DATAREADER_H
#include<QString>
#include <fstream>
#include<vector>
#include<car.h>
#include<abstractreader.h>
#include<bus.h>

class Datareader : public AbstractReader
{
    Datareader(const Datareader&) = delete;
    Datareader& operator=(const Datareader&) = delete;
public:
    // input stream
    std::ifstream input;
    // constructor/destructor
    Datareader( QString filename);
    ~Datareader();
    // наследованные
    bool isopen() const;
    std::vector<bus> readAll();
    //Оператор присваивания перемещением
    Datareader& operator= (Datareader&& orther);
    // Конструктор перемещения
    Datareader(Datareader&& orther);
    // >> operator
    Datareader& operator >> (car &c);
    // type bool operator
    operator bool();
};

#endif // DATAREADER_H
