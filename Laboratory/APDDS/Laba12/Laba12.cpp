#include <iostream>
#include <vector>

using namespace std;

int main() {
	int countLine = 0; cout << "Enter N: "; cin >> countLine;

	vector<int> A(countLine), B(countLine);

	for (int i = 0; i < countLine; i++) {
		cin >> A[i] >> B[i];
	}

	int countPoint = 0;
	for (int i = 0; i < countLine; i++) {
		for (int j = 0; j < countLine; j++) {
			if (A[i] < A[j] && B[i] > B[j]) {
				countPoint++;
			}
		}
	}

	cout << countLine + countPoint + 1 << endl;
	return 0;
}