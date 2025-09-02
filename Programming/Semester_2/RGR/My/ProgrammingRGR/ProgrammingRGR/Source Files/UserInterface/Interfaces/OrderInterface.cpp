#include <chrono>
#include <iostream>
#include <string>

#include "../../../Header Files/Models/Order.h"
#include "../../../Header Files/Models/Address.h"

#include "../../../Header Files/Services/OrderService.h"

#include "../../../Header Files/UserInterface/Interfaces/OrderInterface.h"

#include "../../../Header Files/UserInterface/Utils/PrintModel.h"
#include "../../../Header Files/UserInterface/Utils/OtherUtils.h"

void addNewOrderInterface() {
	std::string input; std::cin.ignore();
	std::cout << "--------------------------\n"
	<< "Enter data:" << std::endl;

	Order order;
	order.id = 0;

	std::cout << "Enter clientId: "; std::getline(std::cin, input); order.clientId = stoi(input);
	std::cout << "Enter driverId: "; std::getline(std::cin, input); order.driverId = stoi(input);

	std::cout << "Enter shippingAddress:" << std::endl;
	order.shippingAddress = enterAddress();
	if (order.shippingAddress.city.empty()) throw std::runtime_error("Invalid input!");
	if (order.shippingAddress.street.empty()) throw std::runtime_error("Invalid input!");
	if (order.shippingAddress.house.empty()) throw std::runtime_error("Invalid input!");
	if (order.shippingAddress.entrance.empty()) throw std::runtime_error("Invalid input!");
	if (order.shippingAddress.apartment.empty()) throw std::runtime_error("Invalid input!");

	std::cout << "Enter recipientAddress:" << std::endl;
	order.recipientAddress = enterAddress();
	if (order.recipientAddress.city.empty()) throw std::runtime_error("Invalid input!");
	if (order.recipientAddress.street.empty()) throw std::runtime_error("Invalid input!");
	if (order.recipientAddress.house.empty()) throw std::runtime_error("Invalid input!");
	if (order.recipientAddress.entrance.empty()) throw std::runtime_error("Invalid input!");
	if (order.recipientAddress.apartment.empty()) throw std::runtime_error("Invalid input!");

	std::cout << "Enter routeLength: "; std::getline(std::cin, input); order.routeLength = stoi(input);

	order.date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	printOrder(createOrderService(order));
}

void getOrderInterface() {
	std::string input; std::cin.ignore();
	std::cout << "--------------------------\n"
	<< "Enter id: "; std::getline(std::cin, input);

	printOrder(getOrderByIdService(stoi(input)));
}

void updateOrderInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Enter id: "; std::getline(std::cin, input);

	Order order;
	order.id = std::stoi(input);
	std::cout << "Command:\n"
	<< "Update shippingAddress - 1\n"
	<< "Update recipientAddress - 2\n"
	<< "Enter command: "; std::getline(std::cin, input);
	
	if (std::stoi(input) == 1) {
		std::cout << "Enter data or enter to not change: " << std::endl;
		order.shippingAddress = enterAddress();
	}
	else if (std::stoi(input) == 2) {
		std::cout << "Enter data or enter to not change: " << std::endl;
		order.recipientAddress = enterAddress();
	}
	else {
		throw std::runtime_error("Bad input!");
	}

	updateOrderService(order);
	std::cout << "Order address already update!" << std::endl;
}

void deleteOrderInterface() {
	std::string input; std::cin.ignore();
	std::cout << "-----------------------------\n"
	<< "Enter id: "; std::getline(std::cin, input);

	deleteOrderService(stoi(input));
	std::cout << "Order already deleted!" << std::endl;
}
