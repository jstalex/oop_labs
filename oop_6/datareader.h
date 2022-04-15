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
    bool isopen()const override;
    std::vector<bus> readAll() override;
    //Оператор присваивания перемещением
    Datareader& operator= (Datareader&& orther);
    // Конструктор перемещения
    Datareader(Datareader&& orther);
    // >> operator
    Datareader& operator >> (car &c) override;
    // type bool operator
    operator bool()const override;
};

#endif // DATAREADER_H
