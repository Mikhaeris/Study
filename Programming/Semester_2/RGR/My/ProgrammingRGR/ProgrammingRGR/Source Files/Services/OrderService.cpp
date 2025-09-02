#include <stdexcept>

#include "../../Header Files/Models/Address.h"
#include "../../Header Files/Models/Order.h"
#include "../../Header Files/Models/Client.h"
#include "../../Header Files/Models/Driver.h"

#include "../../Header Files/Services/OrderService.h"

#include "../../Header Files/Repository/OrderRepository.h"
#include "../../Header Files/Repository/ClientRepository.h"
#include "../../Header Files/Repository/DriverRepository.h"


Order createOrderService(Order order) {
	if (!checkByIdClientInDataBase(order.clientId))
		throw std::runtime_error("The client does not exist!");

	if (!checkByIdDriverInDataBase(order.driverId))
		throw std::runtime_error("The driver does not exist!");

	order.id = getLastOrderId() + 1;

	Client client = getClientById(order.clientId);
	client.orderHistory.push_back(order.id);
	updateClient(client);

	Driver driver = getDriverById(order.driverId);
	driver.orderHistory.push_back(order.id);
	updateDriver(driver);


	return saveOrder(order);
}

Order getOrderByIdService(int id) {
	if (!checkByIdOrderInDataBase(id))
		throw std::runtime_error("The order does not exist!");

	return getOrderById(id);
}

void updateOrderService(Order order) {
	if (!checkByIdOrderInDataBase(order.id))
		throw std::runtime_error("The order does not exist!");

	Order updateOrderInf = getOrderById(order.id);

	if (!order.shippingAddress.city.empty()) updateOrderInf.shippingAddress.city = order.shippingAddress.city;
	if (!order.shippingAddress.street.empty()) updateOrderInf.shippingAddress.street = order.shippingAddress.street;
	if (!order.shippingAddress.house.empty()) updateOrderInf.shippingAddress.house = order.shippingAddress.house;
	if (!order.shippingAddress.entrance.empty()) updateOrderInf.shippingAddress.entrance = order.shippingAddress.entrance;
	if (!order.shippingAddress.apartment.empty()) updateOrderInf.shippingAddress.apartment = order.shippingAddress.apartment;

	if (!order.recipientAddress.city.empty()) updateOrderInf.recipientAddress.city = order.recipientAddress.city;
	if (!order.recipientAddress.street.empty()) updateOrderInf.recipientAddress.street = order.recipientAddress.street;
	if (!order.recipientAddress.house.empty()) updateOrderInf.recipientAddress.house = order.recipientAddress.house;
	if (!order.recipientAddress.entrance.empty()) updateOrderInf.recipientAddress.entrance = order.recipientAddress.entrance;
	if (!order.recipientAddress.apartment.empty()) updateOrderInf.recipientAddress.apartment = order.recipientAddress.apartment;

	updateOrder(updateOrderInf);
}

void deleteOrderService(int id) {
	if (!checkByIdOrderInDataBase(id))
		throw std::runtime_error("The order does not exist!");

	Order order = getOrderById(id);

	Client client = getClientById(order.clientId);
	for (int i = 0; i < client.orderHistory.size(); i++) {
		if (client.orderHistory[i] == id) {
			client.orderHistory.erase(client.orderHistory.begin() + i);
			break;
		}
	}
	updateClient(client);

	Driver driver = getDriverById(order.driverId);
	for (int i = 0; i < driver.orderHistory.size(); i++) {
		if (driver.orderHistory[i] == id) {
			driver.orderHistory.erase(driver.orderHistory.begin() + i);
			break;
		}
	}
	updateDriver(driver);

	deleteOrderById(id);
}