#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include <string>

class Precipitation {
public:
    /* Constructors */
    Precipitation();

    Precipitation(const std::string _sediment,
                  const int _numberDaysInYear, 
                  const std::string _season);

    Precipitation(const Precipitation& _prec);

    /* Destructor */
    ~Precipitation();

    /* Getters */
    std::string getSediment();
    int getNumberdaysInYear();
    std::string getSeason();

    /* Setters */
    void setSediment(std::string _sediment);
    void setNumberDaysInYear(int _numberDaysInYear);
    void setSeason(std::string _season);

    /* Additional functions */
    void printInf();

private:
    std::string sediment;
    int numberDaysInYear;
    std::string season;
};

#endif
