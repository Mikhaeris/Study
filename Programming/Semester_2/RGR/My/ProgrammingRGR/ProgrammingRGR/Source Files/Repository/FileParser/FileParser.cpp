#include <fstream>
#include <vector>
#include <string>

#include "../../../Header Files/Repository/FileParser/FileParser.h"


bool parsFieldInFile(std::ifstream& file, int id, int jump) {
	std::string line;
	while (std::getline(file, line)) {
		if (std::stoi(line) == id)
			return true;

		for (int i = 0; (i < jump) && !file.eof(); i++)
			std::getline(file, line);
	}

	return false;
}

bool parsFieldInFile(std::ifstream& file, std::string str, int goToStartPosition, int jump) {
	std::string line;
	for (int i = 0; i < goToStartPosition; i++)
		std::getline(file, line);
	
	while (std::getline(file, line)) {
		std::string currentUserName = line;
		if (currentUserName == str)
			return true;

		for (int i = 0; (i < 11) && !file.eof(); i++)
			std::getline(file, line);
	}

	return false;
}


std::vector<std::string> getAllDataFromFile(std::ifstream& file) {
	std::vector<std::string> tempData;

	std::string line;
	while (std::getline(file, line)) {
		tempData.push_back(line);
	}

	return tempData;
}

void writeDataInFile(std::ofstream& file, std::vector<std::string> tempData) {
	for (int i = 0; i < tempData.size(); i++) {
		file << tempData[i];
		file << '\n';
	}
}
