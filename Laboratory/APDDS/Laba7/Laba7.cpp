#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//arr
void generateArr(vector <pair<int, int>>& busyPeriod, int sizeArr) {
	srand(time(0));
	for (int i = 0; i < sizeArr; i++) {
		int startBusy = rand() % 1440;
		int finishBusy = min(startBusy + (rand() % 60), 1439);
		busyPeriod.push_back(make_pair(startBusy, finishBusy));
	}
}

void sortArr(vector <pair<int, int>>& busyPeriod) {
	sort(busyPeriod.begin(), busyPeriod.end());
}

void printArr(vector <pair<int, int>>& busyPeriod) {
	cout << "------------------" << "\nBusy time: " << endl;
	for (int i = 0; i < busyPeriod.size(); i++) {
		int startHour = busyPeriod[i].first / 60, startMinute = busyPeriod[i].first % 60;
		int finishHour = busyPeriod[i].second / 60, finishMinute = busyPeriod[i].second % 60;

		cout << (startHour < 10 ? "0" : "") << startHour << ":"
			<< (startMinute < 10 ? "0" : "") << startMinute << " - "
			<< (finishHour < 10 ? "0" : "") << finishHour << ":"
			<< (finishMinute < 10 ? "0" : "") << finishMinute << endl;
	}
}

//logic 
void setBusyPeriod(bool*& timeInDay, vector <pair<int, int>>& busyPeriod, int sizeArr) {
	for (int i = 0; i < 1440; i++) {
		timeInDay[i] = 0;
	}

	for (int i = 0; i < sizeArr; i++) {
		for (int j = busyPeriod[i].first; j <= busyPeriod[i].second; j++) {
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

	vector <pair<int, int>> busyPeriod;
	generateArr(busyPeriod, sizeArr);
	sortArr(busyPeriod);
	printArr(busyPeriod);

	bool* timeInDay = new bool[1440];
	vector <pair<int, int>> freePeriod;
	setBusyPeriod(timeInDay, busyPeriod, sizeArr);
	findFreePeriod(timeInDay, freePeriod);
	printFreePeriod(freePeriod);

	delete[] timeInDay;
	return 0;
}