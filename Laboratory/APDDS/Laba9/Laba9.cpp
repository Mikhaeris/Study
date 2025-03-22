#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Enterprise {
private:
	vector<vector<int>> masterWork;
	queue<int> queueProducts;
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

	int getQueue() {
		for (int i = 0; i < numberDays; i++) {
			for (int j = 0; j < speedProductAdd; j++) {
				queueProducts.push(i);
			}

			for (int j = 0; j < masterWork.size(); j++) {
				if (!masterWork[j].empty()) {
					masterWork[j].erase(masterWork[j].begin());
					if (masterWork[j].empty()) {
						if (!queueProducts.empty()) {
							masterWork[j].push_back(queueProducts.front());
							queueProducts.pop();
						}
					}
				}
				else {
					if (!queueProducts.empty()) {
						masterWork[j].push_back(queueProducts.front());
						queueProducts.pop();
					}
				}
			}

		}

		return queueProducts.size();
	}
};

int main() {
	Enterprise enterprise;
	enterprise.enterStartParameters();
	cout << enterprise.getQueue() << endl;

}