#include "datareader.h"
#include <iostream>
#include <string>
#include <QString>
#include <vector>
#include <fstream>
#include<car.h>

std::vector<std::string> split(std::string str, std::string delim);

//constructor
Datareader::Datareader(QString filename){
    input.open(filename.toStdString());
}
//destructor
Datareader::~Datareader(){
    input.close();
}

Datareader& Datareader::operator=(Datareader&& orher){
    input = std::move(orher.input);
    return *this;
}

Datareader::Datareader(Datareader&& orther){
    input = std::move(orther.input);
}

// is open?
bool Datareader::isopen() const{return input.is_open();};

// read file and return vector of cars
std::vector<std::vector<std::string>> Datareader::readAll(){
    //std::vector<car> cars;
    std::vector<std::vector<std::string>>cars;

    std::vector<std::string> splitted_input;
    std::string line;
    //car tempcar;
    if (input.is_open()) {
        while (!input.eof()) {
            // reading...
            getline(input, line);
            if (line.empty()) {
                break;
            }
            splitted_input = split(line, ";");
            cars.push_back(splitted_input);
        }
    }
    return cars;
}
// splitter for csv
std::vector<std::string> split(std::string str, std::string delim)
{
    std::vector<std::string> arr;
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = str.find(delim, prev)) != std::string::npos) {
        arr.push_back(str.substr(prev, next - prev));
        prev = next + delta;
    }
    arr.push_back(str.substr(prev));
    return arr;
}
