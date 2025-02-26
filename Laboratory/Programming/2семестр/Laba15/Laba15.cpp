#include <iostream>
#include <string>

using namespace std;

struct NOTE {
	string firstName;
	string lastName;
	int phoneNumber;
	int* dateOfBirth = new int[3];
};

void createNotes(NOTE*& arrOfNote) {
	arrOfNote = new NOTE[5];
}

void deleteNotes(NOTE*& arrOfNote) {
	delete[] arrOfNote;
}

void inputArrOfNotes(NOTE*& arrOfNote) {
	cout << "----------------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter FirstName: "; cin >> arrOfNote[i].firstName;
		cout << "Enter LastName: "; cin >> arrOfNote[i].lastName;
		cout << "Enter Phone Number: "; cin >> arrOfNote[i].phoneNumber;
		cout << "Enter Birth date: ";
		/*for (int j = 0; j < 3; j++) {
			cin >> arrOfNote[i].dateOfBirth[j];
		}*/
		cout << "Enter day: "; cin >> arrOfNote[i].dateOfBirth[0];
		cout << "Enter month: "; cin >> arrOfNote[i].dateOfBirth[1];
		cout << "Enter year: "; cin >> arrOfNote[i].dateOfBirth[2];
		cout << "----------------------------" << endl;
	}
}

void generateArrOfNotes(NOTE*& arrOfNote) {
	srand(time(0));
	int tempI = 0;
	for (int i = 0; i < 5; i++) {
		tempI = i++;
		arrOfNote[i].firstName = "test" + to_string(tempI);
		arrOfNote[i].lastName = "test" + to_string(tempI);
		arrOfNote[i].phoneNumber = tempI;
		arrOfNote[i].dateOfBirth[0] = 12 + rand() % 3;
		arrOfNote[i].dateOfBirth[1] = 9;
		arrOfNote[i].dateOfBirth[2] = 2006;
	}
}

void printNote(NOTE*& arrOfNotes, int number) {
	cout << "\n------------------------------------" << endl;
	cout << "Note: " << number + 1 << endl;
	cout << "FirstName: " << arrOfNotes[number].firstName << endl;
	cout << "LastName: " << arrOfNotes[number].lastName << endl;
	cout << "PhoneNumber: " << arrOfNotes[number].phoneNumber << endl;
	cout << "Birth day(day-month-year): ";
	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			cout << arrOfNotes[number].dateOfBirth[i];
		}
		else {
			cout << arrOfNotes[number].dateOfBirth[i] << '-';
		}
	}
	cout << "\n------------------------------------" << endl;
}

void findPeopleThisSameBirthsday(NOTE*& arrOfNote) {
	int* date = new int[3];
	cout << "Enter a date: ";
	cout << "\nEnter day: "; cin >> date[0];
	cout << "Enter month: "; cin >> date[1];
	cout << "Enter year: "; cin >> date[2];

	for (int i = 0; i < 5; i++) {
		if (arrOfNote[i].dateOfBirth[0] == date[0] &&
			arrOfNote[i].dateOfBirth[1] == date[1] &&
			arrOfNote[i].dateOfBirth[2] == date[2]) {
			printNote(arrOfNote, i);
		}
	}

	delete[] date;
}

int main() {

	NOTE* arrOfNote = nullptr;
	createNotes(arrOfNote);
	//inputArrOfNotes(arrOfNote);
	generateArrOfNotes(arrOfNote);
	/*for (int i = 0; i < 5; i++) {
		printNote(arrOfNote, i);
	}*/
	findPeopleThisSameBirthsday(arrOfNote);
	deleteNotes(arrOfNote);
	return 0;
}