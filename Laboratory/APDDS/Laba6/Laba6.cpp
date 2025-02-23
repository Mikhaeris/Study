#include <iostream>

using namespace std;

double f(int N) {
	double answer = 0;
	for (int k = 1; k <= N; k++) {
		answer += pow((2 * k), k - 1);
	}

	return answer;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int N = 0;
	cout << "Введите до какого числа считать(N): "; cin >> N;
	cout << "Ответ: " << f(N) << endl;
	return 0;
}