#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

//People
struct People {
	char lastName[40];
	char fullName[5];
	char zodiacSign[13];
	int dateBirth[3];
};

void generateData(People*& arrPeople, int n) {

	string arrZodiacSign[12] = {
		"Aries", "Taurus", "Twins", "Cancer", "Lion", "Virgo", "Scales", "Scorpion", "Sagittarius", "Capricorn", "Aquarius", "Fish"
	};

	for (int i = 0; i < n; i++) {
		memcpy(arrPeople[i].lastName, ("test" + to_string(i + 1)).c_str(), 40);
		memcpy(arrPeople[i].fullName, ("T" + to_string(i + 1)).c_str(), 5);
		memcpy(arrPeople[i].zodiacSign, arrZodiacSign[rand() % 12].c_str(), 13);
		arrPeople[i].dateBirth[0] = 1 + rand() % 31;
		arrPeople[i].dateBirth[1] = 1 + rand() % 12;
		arrPeople[i].dateBirth[2] = 2000 + rand() % 11;
	}
}

void inputData(People*& arrPeople, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter Last Name: "; cin.getline(arrPeople[i].lastName, 40);
		cout << "Enter Full Name: "; cin.getline(arrPeople[i].fullName, 3);
		cout << "Enter Zodiac Sign";  cin.getline(arrPeople[i].zodiacSign, 13);
		cout << "Enter Birth Date: " << endl;
		cout << "Enter day: ";  cin >> arrPeople[i].dateBirth[0];
		cout << "Enter month: ";  cin >> arrPeople[i].dateBirth[1];
		cout << "Enter year: ";  cin >> arrPeople[i].dateBirth[2];
		cin.ignore();
	}
}

void printPeople(People& people) {
	cout << "----------------------" << endl;
	cout << "Last Name: " << people.lastName << endl;
	cout << "Full Name: " << people.fullName << endl;
	cout << "Zodiac Sign: " << people.zodiacSign << endl;
	cout << "Birth Date: " << (people.dateBirth[0] < 10 ? "0" : "") << people.dateBirth[0] << "-"
		<< (people.dateBirth[1] < 10 ? "0" : "") << people.dateBirth[1] << "-"
		<< (people.dateBirth[2] < 10 ? "0" : "") << people.dateBirth[2] << endl;
}

//File
void createAndWriteArrPeopleInDatFile(People*& arrPeople, int n) {
	ofstream outputFile("peoples.dat", ios::binary);

	if (!outputFile.is_open()) {
		cout << "File Error!" << endl;
		throw runtime_error("Runtime error!");
	}

	outputFile.write((char*)arrPeople, n * sizeof(People));

	outputFile.close();
}

void mappingPeople(People* arrPeopleThisZodiacSign, int tempIndexPeople, People& people) {
	memcpy(arrPeopleThisZodiacSign[tempIndexPeople].lastName, people.lastName, 40);
	memcpy(arrPeopleThisZodiacSign[tempIndexPeople].fullName, people.fullName, 3);
	memcpy(arrPeopleThisZodiacSign[tempIndexPeople].zodiacSign, people.zodiacSign, 13);
	memcpy(arrPeopleThisZodiacSign[tempIndexPeople].dateBirth, people.dateBirth, 12);
}

pair<People*, int> findPeopleWithZodiacSign(string zodiacSign) {
	ifstream inputFile("peoples.dat", ios::binary);

	if (!inputFile.is_open()) {
		cout << "File Error!" << endl;
		throw runtime_error("Runtime error!");
	}

	People pl;
	int countThisZodiacSign = 0;

	while (inputFile.read((char*)&pl, sizeof(People))) {
		if (pl.zodiacSign == zodiacSign) {
			countThisZodiacSign++;
		}
	}

	People* arrPeopleThisZodiacSign = new People[countThisZodiacSign];

	inputFile.clear();
	inputFile.seekg(0, ios_base::end);
	int numberOfRecords = inputFile.tellg() / sizeof(People);
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int tempIndexPeople = 0;
	for (int i = 0; i < numberOfRecords; i++) {
		inputFile.read((char*)&pl, sizeof(People));
		if (pl.zodiacSign == zodiacSign) {
			mappingPeople(arrPeopleThisZodiacSign, tempIndexPeople, pl);
			tempIndexPeople++;
		}
	}

	inputFile.close();

	return pair<People*, int>(arrPeopleThisZodiacSign, countThisZodiacSign);
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0; cout << "Enter N: "; cin >> n;
	cin.ignore();

	People* arrPeople = new People[n];

	generateData(arrPeople, n);

	for (int i = 0; i < n; i++) {
		printPeople(arrPeople[i]);
	}
	cout << "----------------------" << endl;

	createAndWriteArrPeopleInDatFile(arrPeople, n);

	string zodiacSign = ""; cout << "\nZodiac Sign: "; cin >> zodiacSign; cout << endl;
	pair<People*, int> answer = findPeopleWithZodiacSign(zodiacSign);
	People* arrPeopleThisZodiacSign = answer.first;

	if (answer.second != 0) {
		for (int i = 0; i < answer.second; i++) {
			printPeople(arrPeopleThisZodiacSign[i]);
		}
		cout << "----------------------" << endl;
	}
	else {
		cout << "This zodiac sign is not in the data file!" << endl;
	}

	delete[] arrPeople;
	delete[] arrPeopleThisZodiacSign;
	return 0;
}