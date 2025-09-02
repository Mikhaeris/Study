#include <string>
#include <iostream>
#include <stack>
#include <windows.h>

using namespace std;

void generateStack(stack<pair<string, int>>& stackFilms, int n) {
	for (int i = 0; i < n; i++) {
		stackFilms.push(make_pair(("TestFilm" + to_string(i + 1)), (0 + rand() % 11)));
	}
}

void printStack(stack<pair<string, int>> stackFilms) {
	cout << "---------------------------" << endl;
	while (!stackFilms.empty()) {
		cout << "Film: " << stackFilms.top().first << " Rating: " << stackFilms.top().second << endl;
		stackFilms.pop();
	}
	cout << "---------------------------" << endl;
}

void printFilmsWithRatingMoreEight(stack<pair<string, int>> stackFilms) {
	cout << "---------------------------" << endl;
	while (!stackFilms.empty()) {
		if (stackFilms.top().second > 8) {
			cout << "Film: " << stackFilms.top().first << " Rating: " << stackFilms.top().second << endl;
		}
		stackFilms.pop();
	}
	cout << "---------------------------" << endl;
}

double countAverageFilmsRating(stack<pair<string, int>> stackFilms) {
	int sumFilmsRating = 0; int stackSize = stackFilms.size();
	while (!stackFilms.empty()) {
		sumFilmsRating += stackFilms.top().second;
		stackFilms.pop();
	}
	return static_cast<double>(sumFilmsRating) / stackSize;
}


int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	stack<pair<string, int>> stackFilms;

	int n = 0; cout << "Enter N: "; cin >> n;

	generateStack(stackFilms, n);
	printStack(stackFilms);
	double averageFilmsRating = countAverageFilmsRating(stackFilms);
	cout << "Average films rating: " << averageFilmsRating << endl;

	cout << "Films with rating more eight: " << endl;
	printFilmsWithRatingMoreEight(stackFilms);
	return 0;
}