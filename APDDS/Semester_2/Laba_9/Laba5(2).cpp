#include <iostream>

using namespace std;

int main() {
	int m = 5, V = 10, t = 25, T0 = 30, hoursInDay = 24;

	int SpeedOneMaster = hoursInDay / t;
	int SpeedAllMaster = m * SpeedOneMaster;
	int notProcessed = V - SpeedAllMaster;
	int queue = (notProcessed > 0) ? queue = notProcessed * T0 : 0;

	cout << queue << endl;

	return 0;
}