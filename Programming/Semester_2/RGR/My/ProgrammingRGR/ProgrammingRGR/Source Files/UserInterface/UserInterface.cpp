#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>

#include "../../Header Files/Services/ClientService.h"
#include "../../Header Files/Services/DriverService.h"

#include "../../Header Files/UserInterface/UserInterface.h"
#include "../../Header Files/UserInterface/Interfaces/OrderInterface.h"
#include "../../Header Files/UserInterface/Interfaces/ClientInterface.h"
#include "../../Header Files/UserInterface/Interfaces/DriverInterface.h"
#include "../../Header Files/UserInterface/Utils/PrintModel.h"


void orderMenu() {
	std::map<int, std::function<void()>> menuOrder;
	menuOrder[1] = addNewOrderInterface;
	menuOrder[2] = getOrderInterface;
	menuOrder[3] = updateOrderInterface;
	menuOrder[4] = deleteOrderInterface;
	menuOrder[5] = menu;

	while (true) {
		std::cout << "--------------------------\n"
		<< "Command:\n"
		<< "Add new order - 1\n"
		<< "Get order - 2\n"
		<< "Update order - 3\n"
		<< "Delete order - 4\n"
		<< "Exit (go to up) - 5\n"
		<< "Enter command: ";

		std::string input; std::cin >> input;

		try {
			int command = stoi(input);
			if (menuOrder.count(command))
				menuOrder[command]();
			else
				std::cout << "Invalid input, please try again!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void clientMenu() {
	std::map<int, std::function<void()>> menuClient;
	menuClient[1] = addNewClientInterface;
	menuClient[2] = getClientInterface;
	menuClient[3] = updateClientInterface;
	menuClient[4] = deleteClientInterface;
	menuClient[5] = menu;

	while (true) {
		std::cout << "--------------------------\n"
		<< "Command:\n"
		<< "Add new client - 1\n"
		<< "Get client - 2\n"
		<< "Update client - 3\n"
		<< "Delete client - 4\n"
		<< "Exit (go to up) - 5\n"
		<< "Enter command: ";

		std::string input; std::cin >> input;

		try {
			int command = stoi(input);
			if (menuClient.count(command))
				menuClient[command]();
			else
				std::cout << "Invalid input, please try again!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void driverMenu() {
	std::map<int, std::function<void()>> menuDriver;
	menuDriver[1] = addNewDriverInterface;
	menuDriver[2] = getDriverInterface;
	menuDriver[3] = updateDriverInterface;
	menuDriver[4] = deleteDriverInterface;
	menuDriver[5] = menu;

	while (true) {
		std::cout << "--------------------------\n"
		<< "Command:\n"
		<< "Add new driver - 1\n"
		<< "Get driver - 2\n"
		<< "Update driver - 3\n"
		<< "Delete driver - 4\n"
		<< "Exit (go to up) - 5\n"
		<< "Enter command: ";

		std::string input; std::cin >> input;

		try {
			int command = stoi(input);
			if (menuDriver.count(command))
				menuDriver[command]();
			else
				std::cout << "Invalid input, please try again!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void exitMenu() {
	exit(0);
}

void menu() {
	std::map<int, std::function<void()>> menuActions;
	menuActions[1] = orderMenu;
	menuActions[2] = clientMenu;
	menuActions[3] = driverMenu;
	menuActions[4] = exitMenu;

	while (true) {
		std::cout << "--------------------------\n"
		<< "Command:\n"
		<< "Order data base - 1\n"
		<< "Client data base - 2\n"
		<< "Driver data base - 3\n"
		<< "Exit from program - 4\n"
		<< "Enter command: ";
		
		std::string input; std::cin >> input;

		try {
			int command = stoi(input);
			if (menuActions.count(command))
				menuActions[command]();
			else
				std::cout << "Invalid input, please try again!" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}
