#ifndef DRIVER_H
#define DRIVER_H

#include <vector>

#include "../../Header Files/Models/Car.h"

struct Driver {
	int id;
	std::string driverName;
	std::string firstName;
	std::string lastName;
	int dateOfBirth[3];
	int drivingExperience;
	Car car;
	std::vector<int> orderHistory;
};

#endif