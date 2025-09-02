#include <fstream>
#include <sstream>
#include <string>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Car.h"
#include "../../Header Files/Models/Driver.h"

#include "../../Header Files/Repository/ClientRepository.h"
#include "../../Header Files/Repository/FileParser/FileParser.h"


Driver saveDriver(Driver driver) {
	std::ofstream driversFile(DRIVERFILE, std::ios::app);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func saveDriver - driverFile not found!");

	std::stringstream orderHistory;
	std::copy(driver.orderHistory.begin(), driver.orderHistory.end(), std::ostream_iterator<int>(orderHistory, ","));

	std::string data =
		std::to_string(driver.id) + '\n' +
		driver.driverName + '\n' +
		driver.firstName + '\n' +
		driver.lastName + '\n' +
		(driver.dateOfBirth[0] < 10 ? "0" : "") + std::to_string(driver.dateOfBirth[0]) +
		(driver.dateOfBirth[1] < 10 ? "0" : "") + std::to_string(driver.dateOfBirth[1]) +
		std::to_string(driver.dateOfBirth[2]) + '\n' +
		std::to_string(driver.drivingExperience) + '\n' +
		driver.car.brand + '\n' +
		driver.car.model + '\n' +
		driver.car.classC + '\n' +
		std::to_string(driver.car.year) + '\n' +
		orderHistory.str() + '\n' +
		"~~~\n";

	driversFile << data;
	driversFile.close();
	return driver;
}

Driver getDriverById(int id) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func getDriver - driverFile not found!");

	std::string line; int currentLine = 0;
	while (std::getline(driversFile, line)) {
		currentLine++;
		if (std::stoi(line) == id) {
			Driver driver;
			driver.id = stoi(line);

			std::getline(driversFile, driver.driverName);
			std::getline(driversFile, driver.firstName);
			std::getline(driversFile, driver.lastName);

			std::getline(driversFile, line);
			driver.dateOfBirth[0] = std::stoi(line.substr(0, 2));
			driver.dateOfBirth[1] = std::stoi(line.substr(2, 2));
			driver.dateOfBirth[2] = std::stoi(line.substr(4, 4));

			std::getline(driversFile, line);
			driver.drivingExperience = stoi(line);

			std::getline(driversFile, driver.car.brand);
			std::getline(driversFile, driver.car.model);
			std::getline(driversFile, driver.car.classC);
			std::getline(driversFile, line);
			driver.car.year = stoi(line);

			std::getline(driversFile, line);
			std::stringstream ss(line);
			std::string number;
			while (std::getline(ss, number, ',')) {
				if (!number.empty())
					driver.orderHistory.push_back(stoi(number));
			}

			driversFile.close();
			return driver;

		}

		for (int i = 0; (i < 11) && !driversFile.eof(); i++)
			std::getline(driversFile, line);
	}

	driversFile.close();
	throw std::runtime_error("Error in DriverRepository: func getDriverById - The driver does not exist!");
}

Driver getDriverByDriverName(std::string driverName) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func getDriverByDriverName - driverFile not found!");

	std::string line; int currentLine = 0;
	std::getline(driversFile, line);
	int currentId = stoi(line);
	while (std::getline(driversFile, line)) {
		currentLine++;
		if (line == driverName) {
			Driver driver;
			driver.id = currentId;

			driver.driverName = line;
			std::getline(driversFile, driver.firstName);
			std::getline(driversFile, driver.lastName);

			std::getline(driversFile, line);
			driver.dateOfBirth[0] = std::stoi(line.substr(0, 2));
			driver.dateOfBirth[1] = std::stoi(line.substr(2, 2));
			driver.dateOfBirth[2] = std::stoi(line.substr(4, 4));

			std::getline(driversFile, line);
			driver.drivingExperience = stoi(line);

			std::getline(driversFile, driver.car.brand);
			std::getline(driversFile, driver.car.model);
			std::getline(driversFile, driver.car.classC);
			std::getline(driversFile, line);
			driver.car.year = stoi(line);

			std::getline(driversFile, line);
			std::stringstream ss(line);
			std::string number;
			while (std::getline(ss, number, ',')) {
				if (!number.empty())
					driver.orderHistory.push_back(stoi(number));
			}

			driversFile.close();
			return driver;
		}

		for (int i = 0; (i < 11) && !driversFile.eof(); i++) {
			std::getline(driversFile, line);
			if (i == 10) currentId = stoi(line);
		}
	}

	driversFile.close();
	throw std::runtime_error("Error in DriverRepository: func getDriverByDriverName - The driver does not exist!");
}

void updateDriver(Driver driver) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func updateClient - driverFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(driversFile);
	driversFile.close();

	for (int i = 0; i < tempData.size(); i += 12) {
		if (stoi(tempData[i]) == driver.id) {
			tempData[i + 0] = std::to_string(driver.id);

			tempData[i + 1] = driver.driverName;
			tempData[i + 2] = driver.firstName;
			tempData[i + 3] = driver.lastName;

			tempData[i + 4] = (driver.dateOfBirth[0] < 10 ? "0" : "") + std::to_string(driver.dateOfBirth[0]) +
				(driver.dateOfBirth[1] < 10 ? "0" : "") + std::to_string(driver.dateOfBirth[1]) +
				std::to_string(driver.dateOfBirth[2]);

			tempData[i + 5] = std::to_string(driver.drivingExperience);
			tempData[i + 6] = driver.car.brand;
			tempData[i + 7] = driver.car.model;
			tempData[i + 8] = driver.car.classC;
			tempData[i + 9] = std::to_string(driver.car.year);

			std::stringstream result;
			std::copy(driver.orderHistory.begin(), driver.orderHistory.end(), std::ostream_iterator<int>(result, ","));
			tempData[i + 10] = result.str();
			break;
		}
	}

	std::ofstream driversOutFile(DRIVERFILE, std::ios::out);
	if (!driversOutFile)
		throw std::runtime_error("Error in DriverRepository: func updateDriver - driverFile not found!");

	writeDataInFile(driversOutFile, tempData);

	driversOutFile.close();
}

void deleteDriverById(int id) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func deleteDriverById - driverFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(driversFile);
	driversFile.close();

	for (int i = 0; i < tempData.size(); i += 12) {
		if (stoi(tempData[i]) == id) {
			for (int j = 0; j < 12; j++)
				tempData.erase(tempData.begin() + i);
			break;
		}
	}

	std::ofstream driversOutFile(DRIVERFILE, std::ios::out);
	if (!driversOutFile)
		throw std::runtime_error("Error in DriverRepository: func deleteDriverById - driverFile not found!");

	writeDataInFile(driversOutFile, tempData);

	driversOutFile.close();
}

bool checkByIdDriverInDataBase(int id) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func checkByIdClientInDataBase - driverFile not found!");

	try {
		bool answer = parsFieldInFile(driversFile, id, 11);
		driversFile.close();
		return answer;
	}
	catch (const std::exception& e) {
		driversFile.close();
		throw std::runtime_error("Error in DriverRepository: func checkByIdDriverInDataBase - bad parser!" + std::string(e.what()));
	}
}

bool checkByDriverNameInDataBase(std::string driverName) {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func checkByDriverNameInDataBase - driverFile not found!");

	try {
		bool answer = parsFieldInFile(driversFile, driverName, 1, 11);
		driversFile.close();
		return answer;
	}
	catch (const std::exception& e) {
		driversFile.close();
		throw std::runtime_error("Error in DriverRepository: func checkByIdDriverInDataBase - bad parser!" + std::string(e.what()));
	}
}

int getLastDriverId() {
	std::ifstream driversFile(DRIVERFILE, std::ios::in);
	if (!driversFile)
		throw std::runtime_error("Error in DriverRepository: func checkByDriverNameInDataBase - driverFile not found!");

	try {
		std::string line; int lastId = 0, i = 0;
		while (std::getline(driversFile, line)) {
			i++;
			if (i == 1)
				lastId = stoi(line);
			if (i == 12)
				i = 0;
		}

		return lastId;
	}
	catch (const std::exception& e) {
		driversFile.close();
		throw std::runtime_error("Error in DriverRepository: func getLastDriverId - driverFile not found!" + std::string(e.what()));
	}
}
