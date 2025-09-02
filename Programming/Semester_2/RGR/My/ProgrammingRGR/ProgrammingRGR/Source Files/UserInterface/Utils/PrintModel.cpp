#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>

#include "../../../Header Files/UserInterface/Utils/PrintModel.h"


void printOrder(const Order& order) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Order id: " << order.id << std::endl;
	std::cout << "Client id: " << order.clientId << std::endl;
	std::cout << "Driver id: " << order.driverId << std::endl;

	std::cout << "Shipping address: " << std::endl;
	std::cout << "City: " << order.shippingAddress.apartment << std::endl;
	std::cout << "Street: " << order.shippingAddress.street << std::endl;
	std::cout << "House: " << order.shippingAddress.house << std::endl;
	std::cout << "Entrance: " << order.shippingAddress.entrance << std::endl;
	std::cout << "Apartment: " << order.shippingAddress.apartment << std::endl;

	std::cout << "Recipient address: " << std::endl;
	std::cout << "City: " << order.recipientAddress.apartment << std::endl;
	std::cout << "Street: " << order.recipientAddress.street << std::endl;
	std::cout << "House: " << order.recipientAddress.house << std::endl;
	std::cout << "Entrance: " << order.recipientAddress.entrance << std::endl;
	std::cout << "Apartment: " << order.recipientAddress.apartment << std::endl;

	std::cout << "Route length: " << order.routeLength << std::endl;
	std::cout << "Date: " << std::put_time(std::localtime(&order.date), "%F %T") << std::endl;
}

void printClient(const Client& client) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Client id: " << client.id << std::endl;
	std::cout << "ClientName: " << client.clientName << std::endl;
	std::cout << "FirstName: " << client.firstName << std::endl;
	std::cout << "LastName: " << client.lastName << std::endl;

	std::cout << "DateOfBirth: ";
	for (int i = 0; i < 3; i++)
		std::cout << client.dateOfBirth[i] << (i < 2 ? "-" : "");
	std::cout << std::endl;

	std::cout << "OrderHistory: ";
	for (int i = 0; i < client.orderHistory.size(); i++)
		std::cout << client.orderHistory[i] << (i < client.orderHistory.size()-1 ? "," : "");
	std::cout << std::endl;
}

void printDriver(const Driver& driver) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Driver id: " << driver.id << std::endl;
	std::cout << "DriverName: " << driver.driverName << std::endl;
	std::cout << "FirstName: " << driver.firstName << std::endl;
	std::cout << "LastName: " << driver.lastName << std::endl;

	std::cout << "DateOfBirth: ";
	for (int i = 0; i < 3; i++)
		std::cout << driver.dateOfBirth[i] << (i < 2 ? "-" : "");
	std::cout << std::endl;

	std::cout << "DrivingExperience" << driver.drivingExperience << std::endl;

	std::cout << "Car:" << std::endl;
	std::cout << "Brand: " << driver.car.brand << std::endl;
	std::cout << "Model: " << driver.car.model << std::endl;
	std::cout << "Class: " << driver.car.classC << std::endl;
	std::cout << "Year: " << driver.car.year << std::endl;

	std::cout << "OrderHistory: ";
	for (int i = 0; i < driver.orderHistory.size(); i++)
		std::cout << driver.orderHistory[i] << (i < driver.orderHistory.size()-1 ? "," : "");
	std::cout << std::endl;
}
