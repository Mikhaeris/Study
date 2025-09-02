#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int arr[10];


	int max_el_arr = 0;
	int max_el_arr_num = 0;

	int first_negative_element = 0;
	int first_negative_element_num = 0;

	for (int i = 0; i < end(arr) - begin(arr); i++) {
		arr[i] = -10 + rand() % 20;
		cout << arr[i] << ' ';

		if (arr[i] > max_el_arr) {
			max_el_arr = arr[i];
			max_el_arr_num = i;
		}

		if (arr[i] < 0) {
			if (first_negative_element == 0) {
				first_negative_element = arr[i];
				first_negative_element_num = i;
			}
		}
	}

	arr[max_el_arr_num] = first_negative_element;
	arr[first_negative_element_num] = max_el_arr;

	cout << "\n-------------------" << endl;

	for (int i = 0; i < end(arr) - begin(arr); i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}