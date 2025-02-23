//#include <iostream>
//
//using namespace std;
//
//double f(double* x) {
//    double dfx = *x;
//    return sqrt(pow(dfx, 5) - pow(dfx, 4) + fabs(pow(dfx, 3)));
//}
//
//double f(double x) {
//    return sqrt(pow(x, 5) - pow(x, 4) + fabs(pow(x, 3)));
//}
//
//int main() {
//    double N;
//	double *ptrN = &N;
//    double &lnN = N;
//
//    cout << "Enter N: "; cin >> N;
//    cout << "Answer: " << f(ptrN) << endl;
//    cout << "Answer: " << f(lnN) << endl;
//    return 0;
//}

#include<iostream>
#include<vector>

using namespace std;

int main() {

	srand(time(0));

	int N = 0;

	cout << "Enter N: "; cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		arr[i] = -20 + rand() % 41;
		cout << arr[i] << " ";
	}


	int maxElement = arr[0];
	int sumOddElements = 0, numberOddElements = 0;
	vector<int> vecNegEl;

	for (int i = 0; i < N; i++) {

		//max elemant
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}

		//arithmetic mean of odd array elements (среднее арифметическое нечетных элементов массива)
		if (arr[i] % 2 != 0) {
			sumOddElements += arr[i];
			numberOddElements++;
		}

		//negative elements
		if (arr[i] < 0) {
			vecNegEl.push_back(arr[i]);
		}

	}

	cout << "\n----------------------------------------------" << endl;
	cout << "Max element: " << maxElement << endl;

	if (numberOddElements > 0) {
		/*cout << "Arithmetic mean of odd array elements: " << sumOddElements * 1.0 / numberOddElements << endl;
		cout << "Arithmetic mean of odd array elements: " << (double)sumOddElements / numberOddElements << endl;*/
		cout << "Arithmetic mean of odd array elements: " << static_cast<double>(sumOddElements) / numberOddElements << endl;
	}
	else cout << "There are no odd elements here." << endl;

	if (!vecNegEl.empty()) {
		cout << "Negative elements: ";
		for (int i = 0; i < vecNegEl.size(); i++) {
			cout << vecNegEl[i] << " ";
		}
	}
	else cout << "There are no negative elements" << endl;

	return 0;
}