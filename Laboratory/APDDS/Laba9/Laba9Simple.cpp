// First version
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void addDetailInQueue(int& hour, int& hoursToAdd, int& countDetailsQueue) {
//	if (hour % hoursToAdd == 0) {
//		countDetailsQueue++;
//	}
//}
//
//void minusOneHourInWorkers(vector<int>& workerBusy) {
//	for (auto& det : workerBusy) {
//		if (det > 0) {
//			det--;
//		}
//	}
//}
//
//void addDetailInWorkder(vector<int>& workerBusy, int& countDetailsQueue, int& speedProcessDetail) {
//	for (auto& det : workerBusy) {
//		if (det == 0) {
//			if (countDetailsQueue > 0) {
//				det = speedProcessDetail;
//				countDetailsQueue--;
//			}
//		}
//	}
//}
//
//int main() {
//	int countWorkers = 5; //cout << "Enter count workers: "; cin >> countWorkers;
//	int speedAddDetails = 12; //cout << "Enter speed add details: "; cin >> speedAddDetails;
//	int speedProcessDetail = 13; //cout << "Enter speed process details: "; cin >> speedProcessDetail;
//	int countDays = 3; //cout << "Enter count days: "; cin >> countDays;
//	int hoursToAdd = 24 / speedAddDetails;
//
//	vector<int> workerBusy(countWorkers);
//	int countDetailsQueue = 0;
//
//	for (int hour = 1; hour <= countDays * 24; hour++) {
//		addDetailInQueue(hour, hoursToAdd, countDetailsQueue);
//
//		minusOneHourInWorkers(workerBusy);
//
//		addDetailInWorkder(workerBusy, countDetailsQueue, speedProcessDetail);
//	}
//
//	cout << "Count details in queue: " << countDetailsQueue << endl;
//
//	return 0;
//}

// Second version
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Worker {
//	int numberDetail;
//	int timeToOut;
//};
//
//struct Detail {
//	int numberDetail;
//	int countHoursInQueue;
//	bool inQueue;
//};
//
//int getFirstDetailInQueue(vector<Detail>& queueDetails) {
//	for (auto& detail : queueDetails) {
//		if (detail.inQueue == true) {
//			detail.inQueue = false;
//			return detail.numberDetail;
//		}
//	}
//}
//
//int main() {
//	int countWorkers = 1; //cout << "Enter count workers: "; cin >> countWorkers;
//	int speedAddDetailsJump = 4; //cout << "Enter speed add details: "; cin >> speedAddDetails;
//	int speedProcessDetail = 10; //cout << "Enter speed process details: "; cin >> speedProcessDetail;
//	int countHours = 60; //cout << "Enter count days: "; cin >> countDays;
//
//	//int hoursToAdd = 24 / speedAddDetails;
//
//	vector<Worker> workerBusy(countWorkers);
//	vector<Detail> queueDetails(0);
//
//
//	for (int hour = 1; hour <= countHours; hour++) {
//		// add details in queue
//		if (hour % speedAddDetailsJump == 1) {
//			if (queueDetails.size() == 0) {
//				queueDetails.push_back({ 0, 0, true });
//			}
//			else {
//				queueDetails.push_back({ queueDetails[queueDetails.size() - 1].numberDetail + 1, 0, true });
//			}
//		}
//
//		// add time to details in queue
//		for (auto& detail : queueDetails) {
//			if (detail.inQueue == true) {
//				detail.countHoursInQueue++;
//			}
//		}
//
//		// worker details minus minus
//		for (auto& worker : workerBusy) {
//			if (worker.timeToOut > 0) {
//				worker.timeToOut--;
//			}
//		}
//
//		// if worker not bysu add detail
//		// and remove details in queue
//		// and add inf to queueOldInf
//		for (auto& worker : workerBusy) {
//			if (worker.timeToOut == 0) {
//				if (queueDetails.size() > 0) {
//					worker.numberDetail = getFirstDetailInQueue(queueDetails);
//					worker.timeToOut = speedProcessDetail;
//				}
//			}
//		}
//	}
//
//	int summTimeInQueueOld = 0, countDetailsInQueue = 0;
//	for (auto& detail : queueDetails) {
//		summTimeInQueueOld += detail.countHoursInQueue;
//	}
//
//	int detailsInQueue = 0;
//	for (auto& detail : queueDetails) {
//		if (detail.inQueue == true) {
//			detailsInQueue++;
//		}
//	}
//
//	cout << "Count details in queue: " << detailsInQueue << endl;
//	cout << "Average time in queue: " << static_cast<double>(summTimeInQueueOld) / queueDetails.size() << endl;
//
//	return 0;
//}