#include <iostream>
#include <vector>
#include <string>

#include "../../../Header Files/Models/Address.h"
#include "../../../Header Files/Models/Client.h"
#include "../../../Header Files/Models/Driver.h"
#include "../../../Header Files/Models/Car.h"

Address enterAddress() {
	Address address; std::string input;
	std::cout << "Enter city: "; std::getline(std::cin, address.city);
	std::cout << "Enter street: "; std::getline(std::cin, address.street);
	std::cout << "Enter house: "; std::getline(std::cin, address.house);
	std::cout << "Enter entrance: "; std::getline(std::cin, address.entrance);
	std::cout << "Enter apartment: "; std::getline(std::cin, address.apartment);
	return address;
}

Client enterClient(Client client) {
	std::string input;
	std::cout << "Enter firstName(or enter to not change): ";  std::getline(std::cin, input); client.firstName = input;
	std::cout << "Enter lastName(or enter to not change): ";  std::getline(std::cin, input); client.lastName = input;

	std::cout << "Enter dateOfBirth(or enter to not change): " << std::endl;
	std::cout << "Enter day(or enter to not change): ";  std::getline(std::cin, input);
	if (!input.empty()) {
		int day = std::stoi(input);
		(day > 0 || day <= 31) ? client.dateOfBirth[0] = day : throw std::runtime_error("Invalid day");
	}
	else {
		client.dateOfBirth[0] = 0;
	}

	std::cout << "Enter month(or enter to not change): "; std::getline(std::cin, input);
	if (!input.empty()) {
		int month = std::stoi(input);
		(month > 0 || month <= 12) ? client.dateOfBirth[1] = month : throw std::runtime_error("Invalid month");
	}
	else {
		client.dateOfBirth[1] = 0;
	}

	std::cout << "Enter year(or enter to not change): ";  std::getline(std::cin, input);
	if (!input.empty()) {
		int year = std::stoi(input);
		(year > 1925 || year <= 2025) ? client.dateOfBirth[2] = year : throw std::runtime_error("Invalid month");
	}
	else {
		client.dateOfBirth[2] = 0;
	}

	std::cout << "Enter count orders(or enter to not change): "; std::getline(std::cin, input);
	if (!input.empty()) {
		for (int i = 0; i < stoi(input); i++) {
			std::getline(std::cin, input);
			client.orderHistory[i] = stoi(input);
		}
	}

	return client;
}

Driver enterDriver(Driver driver) {
	std::string input;
	std::cout << "Enter driverName: "; std::getline(std::cin, driver.driverName);
	std::cout << "Enter firstName(or enter to not change): ";  std::getline(std::cin, input); driver.firstName = input;
	std::cout << "Enter lastName(or enter to not change): ";  std::getline(std::cin, input); driver.lastName = input;

	std::cout << "Enter dateOfBirth(or enter to not change): " << std::endl;
	std::cout << "Enter day(or enter to not change): ";  std::getline(std::cin, input);
	if (!input.empty()) {
		int day = std::stoi(input);
		(day > 0 || day <= 31) ? driver.dateOfBirth[0] = day : throw std::runtime_error("Invalid day");
	}
	else {
		driver.dateOfBirth[0] = 0;
	}

	std::cout << "Enter month(or enter to not change): "; std::getline(std::cin, input);
	if (!input.empty()) {
		int month = std::stoi(input);
		(month > 0 || month <= 31) ? driver.dateOfBirth[1] = month : throw std::runtime_error("Invalid month");
	}
	else {
		driver.dateOfBirth[0] = 0;
	}

	std::cout << "Enter year(or enter to not change): ";  std::getline(std::cin, input);
	if (!input.empty()) {
		int year = std::stoi(input);
		(year > 1925 || year <= 2025) ? driver.dateOfBirth[2] = year : throw std::runtime_error("Invalid month");
	}
	else {
		driver.dateOfBirth[0] = 0;
	}

	std::cout << "Enter drivingExperience(or enter to not change): "; std::getline(std::cin, input);
	!input.empty() ? driver.drivingExperience = stoi(input) : driver.drivingExperience = 0;

	Car car;
	std::cout << "Enter car inf: " << std::endl;
	std::cout << "Enter car brand: "; std::getline(std::cin, car.brand);
	std::cout << "Enter car model: "; std::getline(std::cin, car.model);
	std::cout << "Enter car classC: "; std::getline(std::cin, car.classC);
	std::cout << "Enter car year: "; std::getline(std::cin, input);
	!input.empty() ? car.year = stoi(input) : car.year = 0;

	driver.car = car;

	return driver;
}
