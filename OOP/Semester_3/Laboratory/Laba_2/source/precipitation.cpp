#include "../include/precipitation.hpp"

#include <string>
#include <iostream>

/* Constructors */
Precipitation::Precipitation() {
    std::cout<< "Default constructor!" << std::endl;
}

Precipitation::Precipitation(const std::string _sediment, const int _numberDaysInYear, 
              const std::string _season) {
    sediment = _sediment;
    numberDaysInYear = _numberDaysInYear;
    season = _season;

    std::cout << "Constructor with arguments!" << std::endl;
}

Precipitation::Precipitation(const Precipitation& _prec) {
    sediment = _prec.sediment;
    numberDaysInYear = _prec.numberDaysInYear;
    season = _prec.season;

    std::cout << "Copy constructor" << std::endl;
}

/* Destructor */
Precipitation::~Precipitation() {
    std::cout << "Destructor!" << std::endl;
}

/* Getters */
std::string Precipitation::getSediment() { return sediment; }
int Precipitation::getNumberdaysInYear() { return numberDaysInYear; }
std::string Precipitation::getSeason() { return season; }

/* Setters */
void Precipitation::setSediment(std::string _sediment) { sediment = _sediment; }
void Precipitation::setNumberDaysInYear(int _numberDaysInYear) { numberDaysInYear = _numberDaysInYear; }
void Precipitation::setSeason(std::string _season) { season = _season; }

/* Additional functions */
void Precipitation::printInf() {
    std::cout << "Inf of Precipitation:" << std::endl;
    std::cout << " sediment: " << sediment
    << " numberDaysInYear: " << numberDaysInYear
    << " season: " << season << std::endl;
}
