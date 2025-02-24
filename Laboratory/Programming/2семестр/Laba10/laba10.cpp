#include<iostream>
#include<string>

using namespace std;

//прототипы функций
int DigitN(int K, int N);

int DigitN(string K, int N);

template <typename T>
T DigitN(T& K, int N);

//Рекурсивная функция
template <typename T>
T SumTo(T N);

int main() {
	setlocale(LC_ALL, "Russian");

	for (int i = 0; i < 5; i++) {

		cout << "N: " << i + 1 << endl;

		int Kint;
		cin >> Kint; cout << "int: " << DigitN(Kint, i) << endl;

		string Kstr;
		cin >> Kstr; cout << "stirng: " << DigitN(Kstr, i) << endl;

		long Klng;
		cin >> Klng; cout << "long: " << DigitN(Klng, i) << endl;

		long long Klnglng;
		cin >> Klnglng; cout << "long long: " << DigitN(Klnglng, i) << endl;

		short Ksht;
		cin >> Ksht; cout << "short: " << DigitN(Ksht, i) << endl;
	}

	while (true) {
		int N;
		cout << "Введите N: "; cin >> N;
		cout << "Сумма от 1 до " << N << ": " << SumTo(N) << endl;
	}

	return 0;
}

//реализация функций
int DigitN(int K, int N) {
	if (K < 0) return -1;
	string Kstr = to_string(K);
	if (Kstr.size() < N + 1) return -1;
	return Kstr[Kstr.size() - 1 - N] - '0';
}

int DigitN(string K, int N) {
	if (stoi(K) < 0) return -1;
	string Kstr = K;
	if (Kstr.size() < N + 1) return -1;
	return Kstr[Kstr.size() - 1 - N] - '0';
}

//функция с шаблоном
template <typename T>
T DigitN(T& K, int N) {
	if (K < 0) return -1;
	string Kstr = to_string(K);
	if (Kstr.size() < N + 1) return -1;
	return Kstr[Kstr.size() - 1 - N] - '0';
}

//Рекурсивная функция реализация
template <typename T>
T SumTo(T N) {
	return N == 1 ? 1 : N + SumTo(N - 1);
}