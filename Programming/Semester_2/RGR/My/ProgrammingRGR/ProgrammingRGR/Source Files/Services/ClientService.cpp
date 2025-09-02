#include <stdexcept>
#include <vector>

#include "../../Header Files/Models/Client.h"
#include "../../Header Files/Services/ClientService.h"
#include "../../Header Files/Repository/ClientRepository.h"


Client createClientService(Client client) {
	if (checkByClientNameClientInDataBase(client.clientName))
		throw std::runtime_error("This clientName is already taken!");

	client.id = getLastClientId() + 1;
	return saveClient(client);
}

Client getClientService(int id) {
	if (!checkByIdClientInDataBase(id))
		throw std::runtime_error("The client does not exist!");

	return getClientById(id);
}

Client getClientService(std::string clientName) {
	if (!checkByClientNameClientInDataBase(clientName))
		throw std::runtime_error("The client does not exist!");

	return getClientByClientName(clientName);
}

void updateClientService(Client client) {
	Client updateClientInf;
	if (client.id != 0) {
		if (!checkByIdClientInDataBase(client.id))
			throw std::runtime_error("The client does not exist!");

		updateClientInf = getClientById(client.id);
	}
	else {
		if (!checkByClientNameClientInDataBase(client.clientName))
			throw std::runtime_error("The client does not exist!");

		updateClientInf = getClientByClientName(client.clientName);
	}

	if (!client.clientName.empty()) updateClientInf.clientName = client.clientName;
	if (!client.firstName.empty()) updateClientInf.firstName = client.firstName;
	if (!client.lastName.empty()) updateClientInf.lastName = client.lastName;

	if (client.dateOfBirth[0] != 0) updateClientInf.dateOfBirth[0] = client.dateOfBirth[0];
	if (client.dateOfBirth[1] != 0) updateClientInf.dateOfBirth[1] = client.dateOfBirth[1];
	if (client.dateOfBirth[2] != 0) updateClientInf.dateOfBirth[2] = client.dateOfBirth[2];

	if (!client.orderHistory.empty()) {
		for (int i = 0; i < client.orderHistory.size(); i++) {
			updateClientInf.orderHistory.push_back(client.orderHistory[i]);
		}
	}

	updateClient(updateClientInf);
}

void deleteClientService(int id) {
	if (!checkByIdClientInDataBase(id))
		throw std::runtime_error("The client does not exist!");

	deleteClientById(id);
}

void deleteClientService(std::string clientName) {
	Client client = getClientByClientName(clientName);
	if (!checkByIdClientInDataBase(client.id))
		throw std::runtime_error("The client does not exist!");

	deleteClientById(client.id);
}
