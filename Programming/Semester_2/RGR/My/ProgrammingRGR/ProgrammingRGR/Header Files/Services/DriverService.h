#ifndef DRIVERSERVICE_H
#define DRIVERSERVICE_H

#include "../../Header Files/Models/Driver.h"

Driver createDriverService(Driver);

Driver getDriverService(int);

Driver getDriverService(std::string);

void updateDriverService(Driver);

void deleteDriverService(int);

void deleteDriverService(std::string);

#endif