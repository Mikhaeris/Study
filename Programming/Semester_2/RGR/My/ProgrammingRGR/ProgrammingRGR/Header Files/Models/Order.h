#ifndef ORDER_H
#define ORDER_H

#include <ctime>

#include "../../Header Files/Models/Address.h"

struct Order {
	int id;
	int clientId;
	int driverId;
	Address shippingAddress;
	Address recipientAddress;
	int routeLength;
	std::time_t date;
};

#endif