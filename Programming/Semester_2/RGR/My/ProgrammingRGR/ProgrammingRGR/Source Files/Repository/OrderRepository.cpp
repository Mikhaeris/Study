#define _CRT_SECURE_NO_WARNINGS

#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <time.h>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Address.h"
#include "../../Header Files/Models/Order.h"
#include "../../Header Files/Models/Client.h"
#include "../../Header Files/Models/Driver.h"

#include "../../Header Files/Repository/OrderRepository.h"
#include "../../Header Files/Repository/ClientRepository.h"
#include "../../Header Files/Repository/DriverRepository.h"
#include "../../Header Files/Repository/FileParser/FileParser.h"


Order saveOrder(Order order) {
	std::ofstream ordersFile(ORDERFILE, std::ios::app);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func saveOrder - orderFile not found!");
	
	char buff[20];
	strftime(buff, 20, "%F %T", localtime(&order.date));

	std::string data =
		std::to_string(order.id) + '\n' +
		std::to_string(order.clientId) + '\n' +
		std::to_string(order.driverId) + '\n' +
		order.shippingAddress.city + '\n' +
		order.shippingAddress.street + '\n' +
		order.shippingAddress.house + '\n' +
		order.shippingAddress.entrance + '\n' +
		order.shippingAddress.apartment + '\n' +
		order.recipientAddress.city + '\n' +
		order.recipientAddress.street + '\n' +
		order.recipientAddress.house + '\n' +
		order.recipientAddress.entrance + '\n' +
		order.recipientAddress.apartment + '\n' +
		std::to_string(order.routeLength) + '\n' +
		std::string(buff) + '\n' +
		"~~~\n";

	ordersFile << data;
	ordersFile.close();
	return order;
}

Order getOrderById(int id) {
	std::ifstream ordersFile(ORDERFILE, std::ios::in);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func getOrderById - orderFile not found!");

	std::string line;
	while (std::getline(ordersFile, line)) {
		if (std::stoi(line) == id) {
			Order order;
			order.id = stoi(line);

			std::getline(ordersFile, line); order.clientId = std::stoi(line);
			std::getline(ordersFile, line); order.driverId = std::stoi(line);

			std::getline(ordersFile, order.shippingAddress.city);
			std::getline(ordersFile, order.shippingAddress.street);
			std::getline(ordersFile, order.shippingAddress.house);
			std::getline(ordersFile, order.shippingAddress.entrance);
			std::getline(ordersFile, order.shippingAddress.apartment);

			std::getline(ordersFile, order.recipientAddress.city);
			std::getline(ordersFile, order.recipientAddress.street);
			std::getline(ordersFile, order.recipientAddress.house);
			std::getline(ordersFile, order.recipientAddress.entrance);
			std::getline(ordersFile, order.recipientAddress.apartment);

			std::getline(ordersFile, line); order.routeLength = std::stoi(line);

			std::getline(ordersFile, line);

			//1
			tm tm = {};
			std::istringstream ss(line);
			ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
			order.date = mktime(&tm);

			//2
			/*std::istringstream ss(line);
			std::chrono::system_clock::time_point tp;
			ss >> std::chrono::parse("%F %T", tp);
			order.date = std::chrono::system_clock::to_time_t(tp);*/

			ordersFile.close();
			return order;
		}

		for (int i = 0; (i < 15) && !ordersFile.eof(); i++)
			std::getline(ordersFile, line);
	}
}

void updateOrder(Order order) {
	std::ifstream ordersFile(ORDERFILE, std::ios::in);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func updateOrder - orderFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(ordersFile);
	ordersFile.close();

	for (int i = 0; i < tempData.size(); i += 16) {
		if (stoi(tempData[i]) == order.id) {
			tempData[i + 0] = std::to_string(order.id);
			tempData[i + 1] = std::to_string(order.clientId);
			tempData[i + 2] = std::to_string(order.driverId);

			tempData[i + 3] = order.shippingAddress.city;
			tempData[i + 4] = order.shippingAddress.street;
			tempData[i + 5] = order.shippingAddress.house;
			tempData[i + 6] = order.shippingAddress.entrance;
			tempData[i + 7] = order.shippingAddress.apartment;

			tempData[i + 8] = order.recipientAddress.city;
			tempData[i + 9] = order.recipientAddress.street;
			tempData[i + 10] = order.recipientAddress.house;
			tempData[i + 11] = order.recipientAddress.entrance;
			tempData[i + 12] = order.recipientAddress.apartment;

			tempData[i + 13] = std::to_string(order.routeLength);

			char buff[20];
			strftime(buff, 20, "%F %T", localtime(&order.date));
			tempData[i + 14] = std::string(buff);
			break;
		}
	}

	std::ofstream ordersOutFile(ORDERFILE, std::ios::out);
	if (!ordersOutFile)
		throw std::runtime_error("Error in OrderRepository: func updateOrder - orderFile not found!");


	writeDataInFile(ordersOutFile, tempData);

	ordersOutFile.close();
}

void deleteOrderById(int id) {
	std::ifstream ordersFile(ORDERFILE, std::ios::in);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func deleteOrderById - orderFile not found!");
	
	std::vector<std::string> tempData = getAllDataFromFile(ordersFile);
	ordersFile.close();

	for (int i = 0; i < tempData.size(); i += 16) {
		if (stoi(tempData[i]) == id) {
			for (int j = 0; j < 16; j++)
				tempData.erase(tempData.begin() + i);
			break;
		}
	}

	std::ofstream driversOutFile(ORDERFILE, std::ios::out);
	if (!driversOutFile)
		throw std::runtime_error("Error in OrderRepository: func deleteOrderById - clientFile not found!");

	writeDataInFile(driversOutFile, tempData);

	driversOutFile.close();
}

bool checkByIdOrderInDataBase(int id) {
	std::ifstream ordersFile(ORDERFILE, std::ios::in);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func checkByIdOrderInDataBase - orderFile not found!");

	try {
		bool answer = parsFieldInFile(ordersFile, id, 15);
		ordersFile.close();
		return answer;
	}
	catch (const std::exception& e) {
		ordersFile.close();
		throw std::runtime_error("Error in OrderRepository: func checkByIdOrderInDataBase - bad parser! Error: " + std::string(e.what()));
	}
}

int getLastOrderId() {
	std::ifstream ordersFile(ORDERFILE, std::ios::in);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderRepository: func getLastOrderId - orderFile not found!");

	try {
		std::string line; int lastId = 0, i = 0;
		while (std::getline(ordersFile, line)) {
			i++;
			if (i == 1)
				lastId = stoi(line);
			if (i == 16)
				i = 0;
		}

		return lastId;
	}
	catch (const std::exception& e) {
		ordersFile.close();
		throw std::runtime_error("Error in OrderRepository: func getLastOrderId - orderFile not found!" + std::string(e.what()));
	}
}
