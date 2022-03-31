#ifndef DATAWRITER_H
#define DATAWRITER_H
#include<QString>
#include <fstream>
#include<vector>
#include<car.h>


class datawriter
{
    std::ofstream output;

    datawriter(const datawriter&) = delete;
    datawriter& operator=(const datawriter&) = delete;
public:
    datawriter(const QString& filename);
    ~datawriter();
    bool isopen() const;
    void writecar( QString c);
    //Оператор присваивания перемещением
    datawriter& operator= (datawriter&& orther);
    // Конструктор перемещения
    datawriter(datawriter&& orther);
};


#endif // DATAWRITER_H
