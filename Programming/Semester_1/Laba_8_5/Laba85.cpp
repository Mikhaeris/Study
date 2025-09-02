#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int initial_arr[10];

	for (int i = 0; i < 10; i++) {

		initial_arr[i] = 0 + rand() % 20;
		cout << initial_arr[i] << endl;
	}

	cout << "-----------------" << endl;

	long long transformed_arr[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			transformed_arr[i][j] = pow(initial_arr[i], j);
			cout << transformed_arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}