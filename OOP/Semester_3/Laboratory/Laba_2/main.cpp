#include "./include/precipitation.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

void generateData(Precipitation *_arr, const size_t _count);
Precipitation *createArrPrecipitation(const size_t _count);
void deleteArrPrecipitation(Precipitation *_arr, const size_t _count);
void printArrPrecipitation(Precipitation *const _arr, int _count);

int main() {
    srand(time({}));

    const int count = 10;
    Precipitation *arrPrecipitation = createArrPrecipitation(count);
    printArrPrecipitation(arrPrecipitation, count);
    deleteArrPrecipitation(arrPrecipitation, count);
    return 0;
}

/* Generate arr Precipitation */
void generateData(Precipitation *_arr, const size_t _count) {
    const std::string sedimentTypes[5] = {
        "rain",
        "snow",
        "hail",
        "sun",
        "acid rain"
    };
    const std::string seasonTypes[4] = {
        "winter",
        "spring",
        "summer",
        "autumn"
    };

    for (int i = 0; i < _count; ++i) {
        _arr[i].setSediment(sedimentTypes[rand() % 5]);
        _arr[i].setNumberDaysInYear(rand() % 90);
        _arr[i].setSeason(seasonTypes[rand() % 4]);
    }
}

Precipitation *createArrPrecipitation(const size_t _count) {
    Precipitation *arr = new Precipitation[_count];
    generateData(arr, _count);
    return arr;
}

void deleteArrPrecipitation(Precipitation *_arr, const size_t _count) {
    delete[](_arr);
}

/* Print arr Precipitation */
void printArrPrecipitation(Precipitation *const _arr, int _count) {
    void (Precipitation::*ptrPrintInf)() = &Precipitation::printInf;

    std::cout << std::endl;
    for (int i = 0; i < _count; ++i) {
        std::cout << "Num: " << i+1 << " ";
        (_arr[i].*ptrPrintInf)();
    }
    std::cout << std::endl;
}
