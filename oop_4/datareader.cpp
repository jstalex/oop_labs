#include "datareader.h"
#include <iostream>
#include <string>
#include <QString>
#include <vector>
#include <fstream>
#include<car.h>

std::vector<std::string> split(std::string str, std::string delim);

//constructor
Datareader::Datareader(const QString& filename){
    input.open(filename.toStdString());
}
//destructor
Datareader::~Datareader(){
    input.close();
}

// is open?
bool Datareader::isopen() const{return input.is_open();};

// read file and return vector of cars
std::vector<car> Datareader::readAll(){
    std::vector<car> cars;
    std::vector<std::string> splitted_input;
    std::string line;
    car tempcar;
    if (input.is_open()) {
        while (!input.eof()) {
            // reading...
            getline(input, line);
            if (line.empty()) {
                break;
            }
            splitted_input = split(line, ";");

            tempcar.number = stoi(splitted_input[0]);
            tempcar.brand = QString::fromStdString(splitted_input[1]);
            tempcar.model = QString::fromStdString(splitted_input[2]);
            tempcar.color = static_cast<colors>(stoi(splitted_input[3]));
            tempcar.year = stoi(splitted_input[4]);

            cars.push_back(tempcar);

            sort(cars.begin(), cars.end(), [](const car& c1, const car& c2) {
                return c1.year > c2.year;
                });
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
