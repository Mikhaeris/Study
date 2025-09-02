#include <fstream>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Address.h"
#include "../../Header Files/Models/Order.h"
#include "../../Header Files/Models/Client.h"
#include "../../Header Files/Models/Driver.h"
#include "../../Header Files/InitData/OrderSeed.h"

#include "../../Header Files/Services/OrderService.h"
#include "../../Header Files/Services/ClientService.h"
#include "../../Header Files/Services/DriverService.h"

#include "../../Header Files/Repository/ClientRepository.h"
#include "../../Header Files/Repository/DriverRepository.h"


void deleteDataInOrderDataBase() {
	std::ofstream ordersFile(ORDERFILE, std::ofstream::out | std::ofstream::trunc);
	if (!ordersFile)
		throw std::runtime_error("Error in OrderSeed: func deleteDataInOrderDataBase - orderFile not found!");

	ordersFile.close();
}

void initializationOrderDataBase() {
	std::vector<Client> allClients;
	std::vector<Driver> allDrivers;

	int clintsLastId = getLastClientId();
	int driversLastId = getLastDriverId();

	for (int i = 1; i < clintsLastId + 1; i++) {
		Client tempClient = getClientById(i);
		allClients.push_back(tempClient);
	}

	for (int i = 1; i < driversLastId + 1; i++) {
		Driver tempDriver = getDriverById(i);
		allDrivers.push_back(tempDriver);
	}

	std::time_t lastTime = 1735689600;
	for (int i = 1; i < 101; i++) {
		int randomClient = 1 + rand() % allClients.size();
		int randomDriver = 1 + rand() % allDrivers.size();

		/*Client testClient;
		testClient.id = randomClient;
		testClient.dateOfBirth[0] = 0;
		testClient.dateOfBirth[1] = 0;
		testClient.dateOfBirth[2] = 0;
		testClient.orderHistory.push_back(i);
		updateClientService(testClient);

		Driver testDriver;
		testDriver.id = randomDriver;
		testDriver.dateOfBirth[0] = 0;
		testDriver.dateOfBirth[1] = 0;
		testDriver.dateOfBirth[2] = 0;
		testDriver.drivingExperience = 0;
		testDriver.car.year = 0;
		testDriver.orderHistory.push_back(i);
		updateDriverService(testDriver);*/

		Address shippingAddress = {
			"testCityShippingAddress" + std::to_string(i),
			"testStreetShippingAddress" + std::to_string(i),
			"testHouseShippingAddress" + std::to_string(i),
			"testEntranceShippingAddress" + std::to_string(i),
			"testApartmentShippingAddress" + std::to_string(i),
		};

		Address recipientAddress = {
			"testCityRecipientAddress" + std::to_string(i),
			"testStreetRecipientAddress" + std::to_string(i),
			"testHouseRecipientAddress" + std::to_string(i),
			"testEntranceRecipientAddress" + std::to_string(i),
			"testApartmentRecipientAddress" + std::to_string(i),
		};

		lastTime = (time_t)(lastTime + (rand() * rand()) % ((15 * 24 * 60 * 60) + 1));
		Order orderTest = {
			i,
			randomClient,
			randomDriver,
			shippingAddress,
			recipientAddress,
			0 + rand() % 300,
			lastTime
		};

		createOrderService(orderTest);
	}
}