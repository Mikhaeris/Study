#include <fstream>
#include <string>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Car.h"
#include "../../Header Files/Models/Driver.h"

#include "../../Header Files/InitData/DriverSeed.h" 
#include "../../Header Files/Services/DriverService.h"


void deleteDataInDriverDataBase() {
	std::ofstream driversFile(DRIVERFILE, std::ofstream::out | std::ofstream::trunc);
	if (!driversFile)
		throw std::runtime_error("Error in DriverSeed: func deleteDataInDriverDataBase - driverFile not found!");

	driversFile.close();
}

void initializationDriverDataBase() {
	for (int i = 0; i < 10; i++) {
		Car car = {
			"testBrand" + std::to_string(i + 1),
			"testModel" + std::to_string(i + 1),
			"testClass" + std::to_string(i + 1),
			2000 + rand() % 25
		};

		Driver driverTest = {
		i + 1,
		"testDriver" + std::to_string(i + 1),
		"testDriverFirstName" + std::to_string(i + 1),
		"testDriverLastName" + std::to_string(i + 1),
		{0 + rand() % 32, 0 + rand() % 13, 2000 + rand() % 25},
		(2 + rand() % 12),
		car,
		{}
		};
		createDriverService(driverTest);
	}
}
