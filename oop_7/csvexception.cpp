#include "csvexception.h"

CsvException::CsvException(int currentLine)
{
    this->currentLine = currentLine;
}
std::string CsvException::whatError() const{
    return ("Error in line number: " + std::to_string(this->currentLine));
}
