//Y = ((3) + (4)) / (11)
#include<iostream>

using namespace std;

//Функция вычисления суммы частного косинуса на синус
double F3(double N) {
	double temp = 0, tempCos = 0, tempSin = 0;
	for (int i = 1; i <= N; i++) {
		tempCos += cos(i);
		tempSin += sin(i);
		temp += tempCos / tempSin;
	}
	return temp;
}

//Функция четыре
double F4(double N) {
	double temp = 1;
	for (int i = 1; i <= N; i++) {
		temp *= (1 + (1 / pow(i, i)));
	}
	return temp;
}

//Функция одинадцать
double F11(double N) {
	double temp = 1, tempSin = 0;
	for (int i = 1; i <= N; i++) {
		tempSin += sin(i);
		temp *= i / tempSin;
	}
	return temp;
}

//Основная программа
int main() {
	
	double Y = 0, N = 0;

	cout << "Enter N: "; cin >> N;
	cout << "F3: " << F3(N) << endl;
	cout << "F4: " << F4(N) << endl;
	cout << "F11: " << F11(N) << endl;

	Y = (F3(N) + F4(N)) / F11(N);

	cout << "Answer: " << Y << endl;
	return 0;
}