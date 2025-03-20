#include <iostream>
#include <vector>

using namespace std;

class Enterprise {
private:
	vector<vector<int>> masterWork;
	int workers;
	int speedProductAdd;
	int averageRepairTime;
	int numberDays;

public:
	Enterprise() = default;

	Enterprise(int workers, int speedProductAdd, int averageRepairTime, int numberDays) {
		this->workers = workers;
		this->speedProductAdd = speedProductAdd;
		this->averageRepairTime = averageRepairTime;
		this->numberDays = numberDays;
	}

	void enterStartParameters() {
		cout << "Enter count workers: "; cin >> workers;
		for (int i = 0; i < workers; i++) {
			masterWork.push_back(vector<int>(0));
		}

		cout << "Enter speed product add: "; cin >> speedProductAdd;
		cout << "Enter average repair time: "; cin >> averageRepairTime;
		cout << "Enter number days: "; cin >> numberDays;
	}

	void getQueue() {
		for ()
	}
};

int main() {
	Enterprise enterprise;

	enterprise.enterStartParameters();

}