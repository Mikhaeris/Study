#include <iostream>
#include <vector>
#include <string>

#include "../../../Header Files/Models/Order.h"
#include "../../../Header Files/Models/Client.h"

#include "../../../Header Files/Services/OrderService.h"
#include "../../../Header Files/Services/ClientService.h"

#include "../../../Header Files/UserInterface/Interfaces/ClientInterface.h"

#include "../../../Header Files/UserInterface/Utils/PrintModel.h"
#include "../../../Header Files/UserInterface/Utils/OtherUtils.h"

void addNewClientInterface() {
	std::string input; std::cin.ignore();
	std::cout << "--------------------------\n"
	<< "Enter data:" << std::endl;

	Client client;
	client.id = 0;

	std::cout << "Enter userName: "; std::getline(std::cin, client.clientName);
	if (client.clientName.empty()) throw std::runtime_error("Invalid input!");
	std::cout << "Enter firstName: "; std::getline(std::cin, client.firstName);
	if (client.firstName.empty()) throw std::runtime_error("Invalid input!");
	std::cout << "Enter lastName: "; std::getline(std::cin, client.lastName);
	if (client.lastName.empty()) throw std::runtime_error("Invalid input!");

	std::cout << "Enter dateOfBirth:" << std::endl;
	std::cout << "Enter day: "; std::getline(std::cin, input);
	int day = stoi(input); (day > 0 || day <= 31) ? client.dateOfBirth[0] = day : throw std::runtime_error("Invalid date");
	std::cout << "Enter month: "; std::getline(std::cin, input);
	int month = stoi(input); (month > 0 || month <= 31) ? client.dateOfBirth[1] = month : throw std::runtime_error("Invalid date");
	std::cout << "Enter year: "; std::getline(std::cin, input);
	int year = stoi(input); (year > 1925 || year <= 2025) ? client.dateOfBirth[2] = year : throw std::runtime_error("Invalid date");

	client.orderHistory = {};

	printClient(createClientService(client));
}

void getClientInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Get by id - 1\n"
	<< "Get by userName - 2\n"
	<< "Get order history by id client - 3\n"
	<< "Enter command: "; std::getline(std::cin, input);

	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin,input);
		printClient(getClientService(stoi(input)));
	}
	else if (stoi(input) == 2) {
		std::cout << "Enter clientName: "; std::getline(std::cin, input);
		printClient(getClientService(input));
	}
	else if (stoi(input) == 3) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		Client answerClient = getClientService(stoi(input));
		for (int i = 0; i < answerClient.orderHistory.size(); i++) {
			printOrder(getOrderByIdService(answerClient.orderHistory[i]));
		}
	}
	else {
		throw std::runtime_error("Bad input!");
	}
}

void updateClientInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Udate by id - 1\n"
	<< "Update by userName - 2\n"
	<< "Enter command: "; std::getline(std::cin, input);

	Client client;
	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin, input); client.id = stoi(input);
		std::cout << "Enter userName(or enter to not change): "; std::getline(std::cin, input); client.clientName = input;
	}
	else if (stoi(input) == 2) {
		std::cout << "Enter clientName: "; std::getline(std::cin, input);
		client.id = 0; client.clientName = input;
	}
	else {
		throw std::runtime_error("Bad input!");
	}

	updateClientService(enterClient(client));
	std::cout << "Client already updated!" << std::endl;
}

void deleteClientInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Command:\n"
	<< "Delete by id - 1\n"
	<< "Delete by clientName - 2\n"
	<< "Enter command: "; std::getline(std::cin, input);

	if (stoi(input) == 1) {
		std::cout << "Enter id: "; std::getline(std::cin, input);
		deleteClientService(stoi(input));
	}
	else if (stoi(input) == 2) {
		std::cout << "Enter clientName: "; std::getline(std::cin, input);
		deleteClientService(input);
	}
	else {
		throw std::runtime_error("Bad input!");
	}
	std::cout << "Client already deleted!" << std::endl;
}
