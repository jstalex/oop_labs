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

// read file and return vector of cars/strings

std::vector<bus> Datareader::readAll(){
    // сначала csv считывается в строки, это было нужно раньше
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
    // тут уже идет заполнение самого рузультирующего вектора
    std::vector<bus> result;
    bus temp;
    // обработка исключений stoi
    try{
        int currentLine = 0;
        for (const auto &line: cars){
            // исключения по дате
            try {
                if (line.size() == 5){
                    temp.capacity = 0;
                    temp.number = stoi(line[0]);
                    temp.brand = QString::fromStdString(line[1]);
                    temp.model = QString::fromStdString(line[2]);
                    temp.color = static_cast<colors>(stoi(line[3]));
                    temp.year = stoi(line[4]);
                    if (temp.year > 2022 || temp.year < 1900){
                        throw CsvException(currentLine);
                    }
                } else {
                    temp.number = stoi(line[0]);
                    temp.brand = QString::fromStdString(line[1]);
                    temp.model = QString::fromStdString(line[2]);
                    temp.color = static_cast<colors>(stoi(line[3]));
                    temp.year = stoi(line[4]);
                    if (temp.year > 2022 || temp.year < 1900){
                        throw CsvException(currentLine);
                    }
                    temp.capacity = stoi(line[5]);
                }
                result.push_back(temp);
            } catch(const CsvException& err) {
                std::cout << "Incorrect year " << err.whatError() << std::endl;
                temp = {};
                result.clear();
                return result;
            }
            currentLine++;
        }
    } catch(const std::exception& err) {
        std::cout << "Error in " << err.what() << std::endl;
        result.clear();
        return result;
    }
    // sorting
    std::sort(result.begin(), result.end());
    return result;
}


Datareader& Datareader::operator >> (car &c){
    std::string line;
    std::vector<std::string> splitted;

    if (input.is_open() && !input.eof()){
        getline(input, line);

        try {
            if (!line.empty()) {
                splitted = split(line, ";");
                c.number = stoi(splitted[0]);
                c.brand = QString::fromStdString(splitted[1]);
                c.model = QString::fromStdString(splitted[2]);
                c.color = static_cast<colors>(stoi(splitted[3]));
                c.year = stoi(splitted[4]);
            }
        } catch(const std::exception& err) {
            std::cout << "Error in " << err.what() << std::endl;
        }
    }
    return *this;
}

Datareader::operator bool() const{
    return !(this->input.eof());
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
