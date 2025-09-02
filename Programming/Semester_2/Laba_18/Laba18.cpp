#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

void generateVector(vector<double>& vectorRealNumbers, int n) {
	for (int i = 0; i < n; i++) {
		vectorRealNumbers.push_back(static_cast <double> (rand()) / static_cast <double> (RAND_MAX / 10));
	}
}

void printVector(vector<double>& vectorRealNumbers) {
	cout << "--------" << endl;
	for (int i = 0; i < vectorRealNumbers.size(); i++) {
		cout << vectorRealNumbers[i] << endl;
	}
	cout << "Vector size: " << vectorRealNumbers.size() << endl;
	cout << "--------" << endl;
}

void findAndDeleteNumbersMoreZeroPointFive(vector<double>& vectorRealNumbers) {
	for (int i = 0; i < vectorRealNumbers.size(); i++) {
		double fractionalPart = vectorRealNumbers[i] - (int)vectorRealNumbers[i];
		if (fractionalPart > 0.5) {
			vectorRealNumbers.erase(vectorRealNumbers.begin() + i);
		}
	}
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<double> vectorRealNumbers;

	int n = 0; cout << "Enter N: "; cin >> n;

	generateVector(vectorRealNumbers, n);
	printVector(vectorRealNumbers);
	findAndDeleteNumbersMoreZeroPointFive(vectorRealNumbers);
	cout << "Delete numbers more zero point five:" << endl;
	printVector(vectorRealNumbers);

	return 0;
}