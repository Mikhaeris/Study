#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	double N, S, K;

	cout << "Введите колечиство акций: ";
	cin >> N;
	cout << "Введите стоимость одной акции: ";
	cin >> S ;
	cout << "Введите количество месяцев: ";
	cin >> K;


	int i = 0;
	while (K > i) {
		N = N + N * 0.1;
		i++;
	}

	cout << "Общая стоимоть акций: " << N * S << endl;
	return 0;
}