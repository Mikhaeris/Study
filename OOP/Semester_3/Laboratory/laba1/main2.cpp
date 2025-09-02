#include <iostream>
#include <string>

class Precipitation {
public:
    std::string sediment;
    int numberDaysInYear;
    std::string season;

    void printInf();
};

inline void Precipitation::printInf() {
    std::cout << "Inf of Precipitation:" << std::endl;
    std::cout << "\tsediment: " << sediment << std::endl;
    std::cout << "\tnumberDaysInYear: " << numberDaysInYear << std::endl;
    std::cout << "\tseason: " << season << std::endl;
}

int main() {
    Precipitation *prec = new Precipitation();
    prec->sediment = "rain";
    prec->numberDaysInYear = 30;
    prec->season = "Autumn";
    prec->printInf();

    Precipitation *prec2 = new Precipitation();
    prec2->sediment = "snow";
    prec2->numberDaysInYear = 55;
    prec2->season = "Winter";
    prec2->printInf();
    return 0;
}
