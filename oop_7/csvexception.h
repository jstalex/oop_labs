#ifndef CSVEXCEPTION_H
#define CSVEXCEPTION_H

#include<exception>
#include<iostream>


class CsvException : std::exception
{
public:
    CsvException(int currentLine);
    int currentLine;
    std::string whatError() const;
};

#endif // CSVEXCEPTION_H
