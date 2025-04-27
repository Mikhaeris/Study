#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Worker {
	int workerFree;
	int workerTime;
};

int main() {
	const int countWorkers = 2;
	const int pump = 4;
	const int timeDetail = 10;
	const int countHours = 60;

	vector<int> queueF;
	vector<Worker> vecWorkers(countWorkers, { 1, 0 });

	vector<int> timeInQueue(countHours / pump + 1, 0);
	int totalDetail = 0;

	int summTime = 0, countClients = 0;
	for (int hour = 1; hour <= countHours; hour++) {

		if (hour % pump == 1) {
			totalDetail++;
			queueF.push_back(0);
			countClients++;
		}

		for (auto& worker : vecWorkers) {
			if (worker.workerTime == timeDetail) {
				worker.workerFree = true;
				worker.workerTime = 0;
			}
		}

		for (auto& worker : vecWorkers) {
			if (!worker.workerFree) {
				worker.workerTime++;
			}
		}

		for (auto& worker : vecWorkers) {
			if (worker.workerFree && !queueF.empty()) {
				summTime += queueF[0];
				queueF.erase(queueF.begin());

				worker.workerFree = false;
				worker.workerTime = 1;
			}
		}

		for (auto& det : queueF) {
			det++;
		}

	}

	cout << "Count detail in queue: " << queueF.size() << endl;

	int summNow = 0;
	for (auto& det : queueF) {
		summNow += det;
	}

	cout << "Average time: " << static_cast<double>(summTime + summNow) / countClients << endl;

	return 0;
}