#include <iostream>
#include<vector>


template<typename xType, typename yType>
class pointOnFlat {
public:
    xType x;
    yType y;
    pointOnFlat(xType xInput, yType yInput) : x(xInput), y(yInput) {}
    // инициализация нулем по умолчанию
    pointOnFlat() : x(0), y(0) {}
    pointOnFlat<xType, yType> operator + (pointOnFlat p){
        return pointOnFlat<xType, yType>(this->x + p.x, this->y + p.y);
    }
    pointOnFlat<xType, yType> operator / (int count){
        return pointOnFlat<xType, yType>(this->x / count, this->y / count);
    }
};


template<typename vectorType>
vectorType average(std::vector<vectorType> arr){
    vectorType sum{};
    for (auto &value: arr){
        sum = sum + value;
    }
    vectorType answer = sum / arr.size();
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
    std::vector<pointOnFlat<int, int>> points{{1, 3},{2, 6},{3, 5},{7, 9}};
    // получим отдельно векторы значений координат точки
    auto pointAverage = average(points);
    std::cout << "pointAverage = " << "x:" << pointAverage.x << " " << "y:" << pointAverage.y << std::endl;
    return 0;
}
