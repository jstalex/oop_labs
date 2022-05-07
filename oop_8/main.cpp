#include <iostream>
#include<vector>


template<typename xType, typename yType>
class pointOnFlat {
public:
    xType x;
    yType y;
    pointOnFlat(xType xInput, yType yInput) : x(xInput), y(yInput) {}
};


template<typename vectorType>
double average(std::vector<vectorType> arr){
    vectorType sum(0);
    for (auto &value: arr){
        sum = sum + value;
    }
    double answer = static_cast<double>(sum) / arr.size();
    return answer;
}


int main()
{
    // int
    std::vector<int> intArray{1,2,3,4,5,6};
    auto intAverage = average(intArray);
    std::cout << "intAverage = " << intAverage << std::endl;

    // float
    std::vector<float> floatArray{12.6,2.4,7.7,4.4,5.7,9.5};
    auto floatAverage = average(floatArray);
    std::cout << "floatAverage = " << floatAverage << std::endl;

    // points on the flat
    std::vector<pointOnFlat<double, int>> points{{1.2, 3},{2.1, 4},{2.2, 5},{1.1, 1}};
    // получим отдельно векторы значений координат точки
    std::vector<double> xCoordinate;
    std::vector<int> yCoordinate;
    for(const auto &point: points){
        xCoordinate.push_back(point.x);
        yCoordinate.push_back(point.y);
    }
    auto xAverage = average(xCoordinate);
    auto yAverage = average(yCoordinate);
    std::cout << "xAverage = " << xAverage << " " << "yAverage = " << yAverage << std::endl;
    return 0;
}
