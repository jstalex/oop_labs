#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

enum colors {
    red,
    green,
    blue,
    purple
};

struct car {
    int number;
    string model;
    colors color;
    int year;
};

vector<string> split(string str, string delim);

int main() {
    vector<car> cars;
    vector<string> splitted_input;
    string line;
    car tempcar;
    fstream input("D:\\cars.csv");

    if (input.is_open()) {
        while (!input.eof()) {
            // построчное чтение автомобилей
            getline(input, line);
            if (line.empty()) {
                break;
            }

            splitted_input = split(line, ";");

            tempcar.number = stoi(splitted_input[0]);
            tempcar.model = splitted_input[1];
            tempcar.color = static_cast<colors>(stoi(splitted_input[2]));
            tempcar.year = stoi(splitted_input[3]);

            cars.push_back(tempcar);
        }
    }
    else {
        cout << "file opening error" << endl;
        return 0;
    }
    input.close();

    for (const auto& c : cars) {
        cout << c.number << ", " << c.model << ", " << c.color << ", " << c.year << endl;
    }

    sort(cars.begin(), cars.end(), [](const car& c1, const car& c2) {
        return c1.year > c2.year;
        });

    fstream output;
    output.open("D:\\sorted_cars.csv");
    if (output.is_open()) {
        for (const auto& c : cars) {
            output << c.number << ", " << c.model << ", " << c.color << ", " << c.year << endl;
        }
    }
    output.close();
    return 0;
}

vector<string> split(string str, string delim)
{
    vector<string> arr;
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = str.find(delim, prev)) != string::npos) {
        arr.push_back(str.substr(prev, next - prev));
        prev = next + delta;
    }
    arr.push_back(str.substr(prev));
    return arr;
}






