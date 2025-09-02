#include <iostream>
#include <string>

#include "../Header Files/InitData/OrderSeed.h"
#include "../Header Files/InitData/ClientSeed.h"
#include "../Header Files/InitData/DriverSeed.h"

#include "../Header Files/UserInterface/UserInterface.h"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	std::string mode;
	std::cout << "Press \"Enter\" to continue..."; std::getline(std::cin, mode);

	if (mode.empty()) {
		menu();
	}
	else if (mode == "seedDataBase") {
		deleteDataInClientDataBase();
		initializationClientDataBase();

		deleteDataInDriverDataBase();
		initializationDriverDataBase();


		deleteDataInOrderDataBase();
		initializationOrderDataBase();
	}
	else {
		std::cout << "Error!" << std::endl;
	}

	return 0;
}
