#include <fstream>
#include <string>

#include "../../Header Files/config.h"

#include "../../Header Files/Models/Client.h"
#include "../../Header Files/InitData/ClientSeed.h"
#include "../../Header Files/Services/ClientService.h"


void deleteDataInClientDataBase() {
	std::ofstream clientsFile(CLIENTFILE, std::ofstream::out | std::ofstream::trunc);
	if (!clientsFile)
		throw std::runtime_error("Error in ClientSeed: func deleteDataInClientDataBase - clientFile not found!");

	clientsFile.close();
}

void initializationClientDataBase() {
	for (int i = 0; i < 10; i++) {
		Client clientTest = {
		i + 1,
		"test" + std::to_string(i+1),
		"testFirstName" + std::to_string(i+1),
		"testLastName" + std::to_string(i+1),
		{0 + rand() % 32, 0 + rand() % 13, 2000 + rand() % 25},
		{}
		};
		createClientService(clientTest);
	}
}
