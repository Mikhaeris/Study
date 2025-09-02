#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int all_candidates[9][8];

	int num_candidates[3] = { 0, 0, 0 };
	int value_candidates[3] = { 0, 0, 0 };

	for (int i = 0; i < 9; i++) {

		int summ = 0;
		cout << i + 1 << ": ";
		for (int j = 0; j < 8; j++) {

			all_candidates[i][j] = 1 + rand() % 10;
			summ += all_candidates[i][j];
			cout << all_candidates[i][j] << ' ';
		}

		cout << "| Рейтинг: " << summ << endl;

		for (int j = 0; j < 3; j++) {

			if (summ > value_candidates[j]) {

				for (int k = 2; k > j; k--) {

					value_candidates[k] = value_candidates[k - 1];
					num_candidates[k] = num_candidates[k - 1];
				}

				value_candidates[j] = summ;
				num_candidates[j] = i + 1;
				break;
			}
		}
	}

	cout << "Первое место: " << num_candidates[0] << endl;
	cout << "Второе место: " << num_candidates[1] << endl;
	cout << "Третье место: " << num_candidates[2] << endl;

	return 0;
}