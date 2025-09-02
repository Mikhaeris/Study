#include <fstream>
#include <sstream>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Client.h"

#include "../../Header Files/Repository/ClientRepository.h"

#include "../../Header Files/Repository/FileParser/FileParser.h"


Client saveClient(Client client) {
	std::ofstream clientsFile(CLIENTFILE, std::ios::app);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func saveClient - clientFile not found!");

	std::stringstream orderHistory;
	std::copy(client.orderHistory.begin(), client.orderHistory.end(), std::ostream_iterator<int>(orderHistory, ","));

	std::string data =
		std::to_string(client.id) + '\n' +
		client.clientName + '\n' +
		client.firstName + '\n' +
		client.lastName + '\n' +
		(client.dateOfBirth[0] < 10 ? "0" : "") + std::to_string(client.dateOfBirth[0]) +
		(client.dateOfBirth[1] < 10 ? "0" : "") + std::to_string(client.dateOfBirth[1]) +
		std::to_string(client.dateOfBirth[2]) + '\n' +
		orderHistory.str() + '\n' +
		"~~~\n";

	clientsFile << data;
	clientsFile.close();
	return client;
}

Client getClientById(int id) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func getClientById - clientFile not found!");

	std::string line; int currentLine = 0;
	while (std::getline(clientsFile, line)) {
		currentLine++;
		if (std::stoi(line) == id) {
			Client client;
			client.id = stoi(line);

			std::getline(clientsFile, client.clientName);
			std::getline(clientsFile, client.firstName);
			std::getline(clientsFile, client.lastName);

			std::getline(clientsFile, line);
			client.dateOfBirth[0] = std::stoi(line.substr(0, 2));
			client.dateOfBirth[1] = std::stoi(line.substr(2, 2));
			client.dateOfBirth[2] = std::stoi(line.substr(4, 4));
				
			std::getline(clientsFile, line);
			std::stringstream ss(line);
			std::string number;
			while (std::getline(ss, number, ',')) {
				if (!number.empty())
					client.orderHistory.push_back(stoi(number));
			}

			clientsFile.close();
			return client;
		}

		for (int i = 0; (i < 6) && !clientsFile.eof(); i++)
			std::getline(clientsFile, line);
	}
}

Client getClientByClientName(std::string clientName) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func getClientByClientName - clientFile not found!");

	std::string line; int currentLine = 0;
	std::getline(clientsFile, line);
	int currentId = stoi(line);
	while (std::getline(clientsFile, line)) {
		currentLine++;
		if (line == clientName) {
			Client client;
			client.id = currentId;

			client.clientName = line;
			std::getline(clientsFile, client.firstName);
			std::getline(clientsFile, client.lastName);

			std::getline(clientsFile, line);
			client.dateOfBirth[0] = std::stoi(line.substr(0, 2));
			client.dateOfBirth[1] = std::stoi(line.substr(2, 2));
			client.dateOfBirth[2] = std::stoi(line.substr(4, 4));

			std::getline(clientsFile, line);
			std::stringstream ss(line);
			std::string number;
			while (std::getline(ss, number, ',')) {
				if (!number.empty())
					client.orderHistory.push_back(stoi(number));
			}

			clientsFile.close();
			return client;
		}

		for (int i = 0; (i < 6) && !clientsFile.eof(); i++) {
			std::getline(clientsFile, line);
			if (i == 5) currentId = stoi(line);
		}
	}

	clientsFile.close();
	throw std::runtime_error("Error in ClientRepository: func getClientByClientName - The driver does not exist!");
}

void updateClient(Client client) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func updateClient - clientFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(clientsFile);

	clientsFile.close();

	for (int i = 0; i < tempData.size(); i += 7) {
		if (stoi(tempData[i]) == client.id) {
			tempData[i + 0] = std::to_string(client.id);
			tempData[i + 1] = client.clientName;
			tempData[i + 2] = client.firstName;
			tempData[i + 3] = client.lastName;
			tempData[i + 4] = (client.dateOfBirth[0] < 10 ? "0" : "") + std::to_string(client.dateOfBirth[0]) +
				(client.dateOfBirth[1] < 10 ? "0" : "") + std::to_string(client.dateOfBirth[1]) +
				std::to_string(client.dateOfBirth[2]);

			std::stringstream result;
			std::copy(client.orderHistory.begin(), client.orderHistory.end(), std::ostream_iterator<int>(result, ","));
			tempData[i + 5] = result.str();
			break;
		}
	}

	std::ofstream clientsOutFile(CLIENTFILE, std::ios::out);
	if (!clientsOutFile)
		throw std::runtime_error("Error in ClientRepository: func updateClient - clientFile not found!");

	writeDataInFile(clientsOutFile, tempData);

	clientsOutFile.close();
}

void deleteClientById(int id) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func deleteClientById - clientFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(clientsFile);
	clientsFile.close();

	for (int i = 0; i < tempData.size(); i+=7) {
		if (stoi(tempData[i]) == id) {
			for (int j = 0; j < 7; j++)
				tempData.erase(tempData.begin()+i);
			break;
		}
	}

	std::ofstream clientsOutFile(CLIENTFILE, std::ios::out);
	if (!clientsOutFile)
		throw std::runtime_error("Error in ClientRepository: func deleteClientById - clientFile not found!");

	writeDataInFile(clientsOutFile, tempData);

	clientsOutFile.close();
}

void deleteClientByClientName(std::string clientName) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func deleteClientById - clientFile not found!");

	std::vector<std::string> tempData = getAllDataFromFile(clientsFile);
	clientsFile.close();

	for (int i = 1; i < tempData.size(); i += 7) {
		if (tempData[i] == clientName) {
			for (int j = 0; j < 7; j++)
				tempData.erase(tempData.begin() + i - 1);
			break;
		}
	}

	std::ofstream clientsOutFile(CLIENTFILE, std::ios::out);
	if (!clientsOutFile)
		throw std::runtime_error("Error in ClientRepository: func deleteClientById - clientFile not found!");

	writeDataInFile(clientsOutFile, tempData);

	clientsOutFile.close();
}

bool checkByIdClientInDataBase(int id) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func checkClientInDataBase - clientFile not found!");

	try {
		bool answer = parsFieldInFile(clientsFile, id, 6);
		clientsFile.close();
		return answer;
	}
	catch (const std::exception& e) {
		clientsFile.close();
		throw std::runtime_error("Error in ClientRepository: func checkByIdClientInDataBase - bad parser! " + std::string(e.what()));
	}
}

bool checkByClientNameClientInDataBase(std::string clientName) {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func checkByUserNameClientInDataBase - clientFile not found!");

	try {
		bool answer = parsFieldInFile(clientsFile, clientName, 1, 6);
		clientsFile.close();
		return answer;
	}
	catch (const std::exception& e) {
		clientsFile.close();
		throw std::runtime_error("Error in ClientRepository: func checkByClientNameClientInDataBase - bad parser! Error: " + std::string(e.what()));
	}
}

int getLastClientId() {
	std::ifstream clientsFile(CLIENTFILE, std::ios::in);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientRepository: func getLastClientId - clientFile not found!");

	try {
		std::string line; int lastId = 0, i = 0;
		while (std::getline(clientsFile, line)) {
			i++;
			if (i == 1)
				lastId = stoi(line);
			if (i == 7)
				i = 0;
		}

		return lastId;
	}
	catch (const std::exception& e) {
		clientsFile.close();
		throw std::runtime_error("Error in ClientRepository: func getLastClientId - clientFile not found!" + std::string(e.what()));
	}
}
