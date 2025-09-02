#include <stdexcept>
#include <vector>

#include "../../Header Files/Services/DriverService.h"
#include "../../Header Files/Repository/DriverRepository.h"


Driver createDriverService(Driver driver) {
	if (checkByIdDriverInDataBase(driver.id))
		throw std::runtime_error("Driver already in data base!");

	driver.id = getLastDriverId() + 1;
	return saveDriver(driver);
}

Driver getDriverService(int id) {
	if (!checkByIdDriverInDataBase(id))
		throw std::runtime_error("The driver does not exist!");

	return getDriverById(id);
}

Driver getDriverService(std::string driverName) {
	if (!checkByDriverNameInDataBase(driverName))
		throw std::runtime_error("The driver does not exist!");

	return getDriverByDriverName(driverName);
}

void updateDriverService(Driver driver) {
	Driver updateDriverInf;
	if (driver.id != 0) {
		if (!checkByIdDriverInDataBase(driver.id))
			throw std::runtime_error("The driver does not exist!");

		updateDriverInf = getDriverById(driver.id);
	}
	else {
		if (!checkByDriverNameInDataBase(driver.driverName))
			throw std::runtime_error("The driver does not exist!");

		updateDriverInf = getDriverByDriverName(driver.driverName);
	}

	if (!driver.driverName.empty()) updateDriverInf.driverName = driver.driverName;
	if (!driver.firstName.empty()) updateDriverInf.firstName = driver.firstName;
	if (!driver.lastName.empty()) updateDriverInf.lastName = driver.lastName;

	if (driver.dateOfBirth[0] != 0) updateDriverInf.dateOfBirth[0] = driver.dateOfBirth[0];
	if (driver.dateOfBirth[1] != 0) updateDriverInf.dateOfBirth[1] = driver.dateOfBirth[1];
	if (driver.dateOfBirth[2] != 0) updateDriverInf.dateOfBirth[2] = driver.dateOfBirth[2];

	if (driver.drivingExperience != 0) updateDriverInf.drivingExperience = driver.drivingExperience;

	if (!driver.car.brand.empty()) updateDriverInf.car.brand = driver.car.brand;
	if (!driver.car.model.empty()) updateDriverInf.car.model = driver.car.model;
	if (!driver.car.classC.empty()) updateDriverInf.car.classC = driver.car.classC;
	if (driver.car.year != 0) updateDriverInf.car.year = driver.car.year;

	if (!driver.orderHistory.empty()) {
		for (int i = 0; i < driver.orderHistory.size(); i++) {
			updateDriverInf.orderHistory.push_back(driver.orderHistory[i]);
		}
	}

	updateDriver(updateDriverInf);
}

void deleteDriverService(int id) {
	if (!checkByIdDriverInDataBase(id))
		throw std::runtime_error("The driver does not exist!");

	deleteDriverById(id);
}

void deleteDriverService(std::string driverName) {
	if (!checkByDriverNameInDataBase(driverName))
		throw std::runtime_error("The driver does not exist!");

	Driver driver = getDriverByDriverName(driverName);
	deleteDriverById(driver.id);
}
