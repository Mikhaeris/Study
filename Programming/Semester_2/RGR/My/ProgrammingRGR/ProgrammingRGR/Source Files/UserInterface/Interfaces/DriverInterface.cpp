#include <iostream>
#include <vector>
#include <string>

#include "../../../Header Files/Models/Order.h"
#include "../../../Header Files/Models/Driver.h"
#include "../../../Header Files/Models/Car.h"

#include "../../../Header Files/Services/OrderService.h"
#include "../../../Header Files/Services/DriverService.h"

#include "../../../Header Files/UserInterface/Interfaces/DriverInterface.h"
#include "../../../Header Files/UserInterface/Utils/PrintModel.h"
#include "../../../Header Files/UserInterface/Utils/OtherUtils.h"

void addNewDriverInterface() {
	std::string input; std::cin.ignore();
	std::cout << "--------------------------\n"
	<< "Enter data:" << std::endl;

	Driver driver;
	driver.id = 0;

	std::cout << "Enter driverName: "; std::getline(std::cin, input);
	!input.empty() ? driver.driverName = input : throw std::runtime_error("Invalid input!");
	std::cout << "Enter firstName: "; std::getline(std::cin, input);
	!input.empty() ? driver.firstName = input : throw std::runtime_error("Invalid input!");
	std::cout << "Enter lastName: "; std::getline(std::cin, input);
	!input.empty() ? driver.lastName = input : throw std::runtime_error("Invalid input!");

	std::cout << "Enter dateOfBirth:" << std::endl;
	std::cout << "Enter day: "; std::getline(std::cin, input);
	int day = stoi(input); (day > 0 || day <= 31) ? driver.dateOfBirth[0] = day: throw std::runtime_error("Invalid date!");
	std::cout << "Enter month: "; std::getline(std::cin, input);
	int month = stoi(input); (month > 0 || month <= 12) ? driver.dateOfBirth[1] = month : throw std::runtime_error("Invalid date!");
	std::cout << "Enter year: "; std::getline(std::cin, input);
	int year = stoi(input); (year > 1925 || year <= 2025) ? driver.dateOfBirth[2] = year : throw std::runtime_error("Invalid date!");

	std::cout << "Enter year: "; std::getline(std::cin, input);
	int drivingExperience = stoi(input); drivingExperience > 0 ? driver.drivingExperience = drivingExperience : throw std::runtime_error("Invalid drivingExperience!");


	Car car;
	std::cout << "Enter car inf: " << std::endl;
	std::cout << "Enter car brand:"; std::getline(std::cin, driver.car.brand);
	std::cout << "Enter car model:"; std::getline(std::cin, driver.car.model);
	std::cout << "Enter car classC:"; std::getline(std::cin, driver.car.classC);
	std::cout << "Enter car year:"; std::getline(std::cin, input); driver.car.year = stoi(input);
	printDriver(createDriverService(driver));
}

void getDriverInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Get by id - 1\n"
	<< "Get by userName - 2\n"
	<< "Get order history by id driver - 3\n"
	<< "Enter command: "; std::getline(std::cin, input);

	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		printDriver(getDriverService(stoi(input)));
	}
	else if (stoi(input) == 2) {
		std::cout << "Enter clientName: "; std::getline(std::cin, input);
		printDriver(getDriverService(input));
	}
	else if (stoi(input) == 3) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		Driver answerDriver = getDriverService(stoi(input));
		for (int i = 0; i < answerDriver.orderHistory.size(); i++) {
			printOrder(getOrderByIdService(answerDriver.orderHistory[i]));
		}
	}
	else {
		throw std::runtime_error("Bad input!");
	}
}

void updateDriverInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Udate by id - 1\n"
	<< "Update by driverName - 2\n"
	<< "Enter command: "; std::getline(std::cin, input);

	Driver driver;
	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		driver.id = stoi(input);
	}
	else if (stoi(input) == 2) {
		driver.id = 0;
	}
	else {
		throw std::runtime_error("Bad input!");
	}

	updateDriverService(enterDriver(driver));
	std::cout << "Driver alreade update!" << std::endl;
}

void deleteDriverInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Delete by id - 1\n"
	<< "Delete by driverName - 2\n"
	<< "Enter command: "; std::getline(std::cin, input);

	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		deleteDriverService(stoi(input));
	}
	else if (stoi(input) == 2) {
		std::cout << "Enter clientName: "; std::getline(std::cin, input);
		deleteDriverService(input);
	}
	else {
		throw std::runtime_error("Bad input!");
	}
	std::cout << "Driver already deleted!" << std::endl;
}