#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

struct People {
	string lastName;
	string fullName;
	string zodiacSign;
	int* dateBirth = new int[3];
};

void generateData(People*& arrPeople, int n) {
	string* arrZodiacSign =
		for (int i = 0; i < n; i++) {
			arrPeople[i].lastName = "test" + to_string(i);
			arrPeople[i].fullName = "T" + to_string(i);
			arrPeople[i].zodiacSign =
		}
}

void inputData(People*& arrPeople, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter last name: "; cin >> arrPeople[i].lastName;
		cout << "Enter full name: "; cin >> arrPeople[i].fullName;
		cout << "Enter zodiac sign";  cin >> arrPeople[i].zodiacSign;
		cout << "Enter birth date: " << endl;
		cout << "Enter day: ";  cin >> arrPeople[i].dateBirth[0];
		cout << "Enter mounth: ";  cin >> arrPeople[i].dateBirth[1];
		cout << "Enter year: ";  cin >> arrPeople[i].dateBirth[2];
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	cin >> n;
	cin.ignore();

	People* arrPeople = new People[n];


	return 0;
}