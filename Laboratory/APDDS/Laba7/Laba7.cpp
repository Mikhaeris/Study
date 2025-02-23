#include <iostream>

using namespace std;

void createArr(int**& arr, int sizeArr) {
	arr = new int* [sizeArr];
	for (int i = 0; i < sizeArr; i++)
		arr[i] = new int[2];
}

void generateArr(int** arr, int sizeArr) {
	srand(time(0));
	for (int i = 0; i < sizeArr; i++) {
		arr[i][0] = rand() % 1440;
		arr[i][1] = min(arr[i][0] + (rand() % 60), 1439);
	}
}

void deleteArr(int** arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++)
		delete[] arr[i];
	delete[] arr;
}

void printArr(int** arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++)
		cout << arr[i][0] << " " << arr[i][1] << endl;
}

int main() {
	int sizeArr = 0;
	cin >> sizeArr;

	int** arr = nullptr;

	createArr(arr, sizeArr);
	generateArr(arr, sizeArr);
	printArr(arr, sizeArr);
	deleteArr(arr, sizeArr);

	return 0;
}