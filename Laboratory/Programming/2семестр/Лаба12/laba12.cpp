#include<iostream>

using namespace std;

void generateArr(int* arr, int N) {
	srand(time(0));
	for (int i = 0; i < N; i++) {
		arr[i] = -20 + rand() % 41;
		cout << arr[i] << " ";
	}
	cout << endl;
}

int findMaxElement(int* arr, int N) {
	int maxElement = arr[0];
	for (int i = 0; i < N; i++) {
		if (maxElement < arr[i])
			maxElement = arr[i];
	}
	return maxElement;
}

double calcMeanOddElems(int* arr, int N) {
	int sumOddElements = 0, numberOddElements = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] % 2 != 0) {
			sumOddElements += arr[i];
			numberOddElements++;
		}
	}

	return  numberOddElements != 0 ? static_cast<double>(sumOddElements) / numberOddElements : -1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int N = 0;
	cout << "Введите длину массива: "; cin >> N;

	int* arr = new int[N];

	generateArr(arr, N);
	cout << "------------------------" << endl;
	cout << "Максимальный элемент в массиве: " << findMaxElement(arr, N) << endl;
	cout << "Среднеарифметическое нечетных элементов массива: " << calcMeanOddElems(arr, N) << endl;
	delete[] arr;
	return 0;
}

//#include <utility>
//#include<iostream>
//
//using namespace std;
//
//void generateArr(int** arr, int N, int M) {
//	srand(time(0));
//	for (int i = 0; i < N; i++) {
//		arr[i] = new int[M];
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			arr[i][j] = -20 + rand() % 41;
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void deleteArr(int** arr, int N) {
//	for (int i = 0; i < N; i++)
//		delete[] (arr[i]);
//	delete[] arr;
//}
//
//void manualArrInput(int** arr, int N, int M) {
//	srand(time(0));
//	for (int i = 0; i < N; i++) {
//		arr[i] = new int[M];
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> arr[i][j];
//		}
//	}
//}
//
//pair<int, int> findRowWithMaxSum(int** arr, int N, int M) {
//	int* arrOfSumLine = new int[N];
//	int sumLine = 0;
//	for (int i = 0; i < N; i++) {
//		sumLine = 0;
//		for (int j = 0; j < M; j++) {
//			sumLine += arr[i][j];
//		}
//		arrOfSumLine[i] = sumLine;
//	}
//
//	int maxElInArrOfSumLine = arrOfSumLine[0], numberLineOfMax = 0;
//	for (int i = 0; i < N; i++) {
//		if (maxElInArrOfSumLine < arrOfSumLine[i]) {
//			maxElInArrOfSumLine = arrOfSumLine[i];
//			numberLineOfMax = i;
//		}
//	}
//
//	delete[] arrOfSumLine;
//	return pair<int, int>(numberLineOfMax+1, maxElInArrOfSumLine);
//}
//
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//
//	int N = 0, M = 0;
//
//	cout << "Введите количество строк: "; cin >> N;
//	cout << "Введите количество столбцов: "; cin >> M;
//
//	int** arr = new int* [N];
//
//	cout << "------------------------" << endl;
//	generateArr(arr, N, M);
//	//manualArrInput(arr, N, M);
//	cout << "------------------------" << endl;
//
//	auto result = findRowWithMaxSum(arr, N, M);
//	cout << "Номер строки с максимальной суммой: " << result.first << endl;
//	cout << "Максимальная сумма : " << result.second << endl;
//	deleteArr(arr, N);
//	return 0;
//}