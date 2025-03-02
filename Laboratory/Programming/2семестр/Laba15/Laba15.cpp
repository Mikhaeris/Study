#include <iostream>
#include <string>

using namespace std;

struct NOTE {
	string firstName;
	string lastName;
	int phoneNumber;
	int dateOfBirth[3];
};

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
	for (int i = 0; i < 5; i++) {
		arrOfNote[i].firstName = "test" + to_string(i + 1);
		arrOfNote[i].lastName = "test" + to_string(i + 1);
		arrOfNote[i].phoneNumber = i + 1;
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
	cout << "Birth day(day-month-year): " << (arrOfNotes[number].dateOfBirth[0] < 10 ? "0" : "") << arrOfNotes[number].dateOfBirth[0] << "-"
		<< (arrOfNotes[number].dateOfBirth[1] < 10 ? "0" : "") << arrOfNotes[number].dateOfBirth[1] << "-"
		<< arrOfNotes[number].dateOfBirth[2] << endl;
	cout << "\n------------------------------------" << endl;
}

void findPeopleThisSameBirthsday(NOTE*& arrOfNote) {
	int date[3];
	cout << "Enter a date: ";
	cout << "\nEnter day: "; cin >> date[0];
	cout << "Enter month: "; cin >> date[1];
	cout << "Enter year: "; cin >> date[2];

	cout << "\nPeople with similar birthday(" << (date[0] < 10 ? "0" : "") << date[0] << "-"
		<< (date[1] < 10 ? "0" : "") << date[1] << "-"
		<< date[2] << "): " << endl;
	for (int i = 0; i < 5; i++) {
		if (arrOfNote[i].dateOfBirth[0] == date[0] &&
			arrOfNote[i].dateOfBirth[1] == date[1] &&
			arrOfNote[i].dateOfBirth[2] == date[2]) {
			printNote(arrOfNote, i);
		}
	}
}

int main() {

	NOTE* arrOfNote = new NOTE[5];
	//inputArrOfNotes(arrOfNote);
	generateArrOfNotes(arrOfNote);
	/*for (int i = 0; i < 5; i++) {
		printNote(arrOfNote, i);
	}*/
	findPeopleThisSameBirthsday(arrOfNote);

	delete[] arrOfNote;
	return 0;
}

#include <iostream>

using namespace std;

struct ComplexNumber {
	double real;
	double imaginary;
};

ComplexNumber createComplexNumber() {
	cout << "Enter: " << endl;
	double re = 0; cout << "Re: "; cin >> re;
	double im = 0; cout << "Im: "; cin >> im;
	ComplexNumber complexNumber{ re, im };
	return complexNumber;
}

ComplexNumber divisionComplexNumbers(ComplexNumber numberOne, ComplexNumber numberTwo) {
	double denominator = numberTwo.real * numberTwo.real + numberTwo.imaginary * numberTwo.imaginary;
	if (denominator == 0) {
		//throw new runtime_error("You can't divide by zero!");
		ComplexNumber newComplexNumber{ 0, 0 };
		return newComplexNumber;
	}
	double newReal = (numberOne.real * numberTwo.real + numberOne.imaginary * numberTwo.imaginary) / denominator;
	double newImaginary = (numberOne.imaginary * numberTwo.real - numberOne.real * numberTwo.imaginary) / denominator;;
	ComplexNumber newComplexNumber{ newReal, newImaginary };
	return newComplexNumber;
}

void printComplexNumber(ComplexNumber& complexNumber) {
	cout << "z = " << complexNumber.real << " + " << complexNumber.imaginary << "i" << endl;
}

int main() {

	ComplexNumber numberOne = createComplexNumber();
	printComplexNumber(numberOne);

	ComplexNumber numberTwo = createComplexNumber();
	printComplexNumber(numberTwo);

	ComplexNumber numberDivision = divisionComplexNumbers(numberOne, numberTwo);
	if (numberDivision.real == 0 && numberDivision.imaginary == 0) {
		cout << "You can't divide by zero!" << endl;
	}
	else {
		cout << "Number after division: ";
		printComplexNumber(numberDivision);
	}

	return 0;
}