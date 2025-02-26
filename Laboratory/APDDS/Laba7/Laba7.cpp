#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//arr
void createArr(int**& arr, int sizeArr) {
	arr = new int* [sizeArr];
	for (int i = 0; i < sizeArr; i++)
		arr[i] = new int[2];
}

void deleteArr(int**& arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++)
		delete[] arr[i];
	delete[] arr;
}

void generateArr(int**& arr, int sizeArr) {
	srand(time(0));
	for (int i = 0; i < sizeArr; i++) {
		arr[i][0] = rand() % 1440;
		arr[i][1] = min(arr[i][0] + (rand() % 60), 1439);
	}
}

void sortArr(int**& arr, int sizeArr) {
	sort(arr, arr + sizeArr, [](int* a, int* b) { return a[0] < b[0]; });
}

void printArr(int** arr, int sizeArr) {
	cout << "------------------" << "\nBusy time: " << endl;
	for (int i = 0; i < sizeArr; i++) {
		int startHour = arr[i][0] / 60, startMinute = arr[i][0] % 60;
		int finishHour = arr[i][1] / 60, finishMinute = arr[i][1] % 60;

		cout << (startHour < 10 ? "0" : "") << startHour << ":"
			<< (startMinute < 10 ? "0" : "") << startMinute << " - "
			<< (finishHour < 10 ? "0" : "") << finishHour << ":"
			<< (finishMinute < 10 ? "0" : "") << finishMinute << endl;
	}
}

//logic 
void setBusyPeriod(bool*& timeInDay, int** arr, int sizeArr) {
	timeInDay = new bool[1440];
	for (int i = 0; i < 1440; i++) {
		timeInDay[i] = 0;
	}

	for (int i = 0; i < sizeArr; i++) {
		for (int j = arr[i][0]; j <= arr[i][1]; j++) {
			timeInDay[j] = 1;
		}
	}
}

void findFreePeriod(bool*& timeInDay, vector <pair<int, int>>& freePeriod) {
	int startPeriod = -1;
	for (int i = 0; i < 1440; i++) {
		if (timeInDay[i] == false && startPeriod == -1) {
			startPeriod = i;
		}

		if (timeInDay[i] == true && startPeriod != -1) {
			freePeriod.push_back(make_pair(startPeriod, i - 1));
			startPeriod = -1;
		}

		if (i == 1439 && startPeriod != -1) {
			freePeriod.push_back(make_pair(startPeriod, i));
			startPeriod = -1;
		}
	}
}

void printFreePeriod(vector <pair<int, int>>& freePeriod) {
	cout << "------------------" << endl;
	cout << "Free Period: " << endl;
	for (int i = 0; i < freePeriod.size(); i++) {
		int startHour = freePeriod[i].first / 60, startMinute = freePeriod[i].first % 60;
		int finishHour = freePeriod[i].second / 60, finishMinute = freePeriod[i].second % 60;

		cout << (startHour < 10 ? "0" : "") << startHour << ":"
			<< (startMinute < 10 ? "0" : "") << startMinute << " - "
			<< (finishHour < 10 ? "0" : "") << finishHour << ":"
			<< (finishMinute < 10 ? "0" : "") << finishMinute << endl;
	}
}

//main
int main() {
	int sizeArr = 0;
	cout << "Enter number of generations: "; cin >> sizeArr;

	int** arr = nullptr;
	createArr(arr, sizeArr);
	generateArr(arr, sizeArr);
	sortArr(arr, sizeArr);
	printArr(arr, sizeArr);

	bool* timeInDay = nullptr;
	vector <pair<int, int>> freePeriod;
	setBusyPeriod(timeInDay, arr, sizeArr);
	findFreePeriod(timeInDay, freePeriod);
	printFreePeriod(freePeriod);


	deleteArr(arr, sizeArr);
	delete[] timeInDay;
	return 0;
}