/// FirstTask
#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Time {
	int day, month, year;

	friend istream& operator>>(istream& in, Time& time) {
		cout << "Day: ";  in >> time.day;
		cout << "Month: ";  in >> time.month;
		cout << "Year: ";  in >> time.year;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Time& time) {
		return out << time.day << "/" << time.month << "/" << time.year;
	}
};

Time getCurrentTime() {
	time_t t = time(0);
	tm* now = localtime(&t);

	return {
		now->tm_mday,
		now->tm_mon + 1,
		now->tm_year + 1900,
	};
}

struct Worker {
	string lastName;
	string position;
	Time startTime;
	int contractYear;
	int salary;

	Time getTimeContractOut() const {
		return {
			startTime.day,
			startTime.month,
			startTime.year + contractYear
		};
	}

	friend istream& operator>>(istream& in, Worker& worker) {
		cout << "Enter last name: "; in >> worker.lastName;
		cout << "Enter position: "; in >> worker.position;
		cout << "Enter start time:\n"; in >> worker.startTime;
		cout << "Enter contract year: "; in >> worker.contractYear;
		cout << "Enter salary: "; cin >> worker.salary;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Worker& worker) {
		return out << "LastName: " << worker.lastName
			<< "\nPosition: " << worker.position
			<< "\nStartTime: " << worker.startTime
			<< "\nContractYear: " << worker.contractYear
			<< "\nSalary: " << worker.salary;
	}
};

void genereteVecWorkers(vector<Worker>& vecWorkers, int& countWorkers) {
	for (int i = 1; i <= countWorkers; i++) {
		vecWorkers.push_back({
			"LastNameTest" + to_string(i),
			"PositionTest" + to_string(i),
			{
				1 + rand() % 30,
				1 + rand() % 13,
				2015 + rand() % 11,
			},
			1 + rand() % 11,
			10000 + rand() % 100000
			});
	}
}

void enterVecWorkers(vector<Worker>& vecWorkers, int& countWorkers) {
	vecWorkers.resize(countWorkers);
	for (auto& worker : vecWorkers) {
		cin >> worker;
	}
}

void printVecWorkers(vector<Worker>& vecWorkers) {
	cout << "---------------------\n"
		<< "All Workers:\n";
	for (const auto& worker : vecWorkers) {
		cout << "----\n"
			<< worker << endl;
	}
	cout << "----\n"
		<< "---------------------" << endl;
}

void printVecWorkersContractSoonOut(vector<Worker>& vecWorkers, int timeOut) {
	cout << "---------------------\n"
		<< "Workers with contract out in " << timeOut << " days" << ":\n";
	for (const auto& worker : vecWorkers) {
		Time workerTimeOut = worker.getTimeContractOut();
		Time currentTime = getCurrentTime();

		if (workerTimeOut.year == currentTime.year &&
			workerTimeOut.month == currentTime.month &&
			(workerTimeOut.day - currentTime.day) <= timeOut &&
			(workerTimeOut.day - currentTime.day) >= 0) {

			cout << "----\n"
				<< worker << endl;
		}
	}
	cout << "----\n"
		<< "---------------------" << endl;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<Worker> vecWorkers;

	int countWorkers = 0; cout << "Enter count workers: "; cin >> countWorkers;
	//enterVecWorkers(vecWorkers, countWorkers);
	genereteVecWorkers(vecWorkers, countWorkers);

	//printVecWorkers(vecWorkers);
	printVecWorkersContractSoonOut(vecWorkers, 5);

	return 0;
}

/// SecondTask
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Date {
	int day, month, year;

	friend istream& operator>>(istream& in, Date& date) {
		cout << "Day: ";  in >> date.day;
		cout << "Month: ";  in >> date.month;
		cout << "Year: ";  in >> date.year;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Date& date) {
		return out << date.day << "/" << date.month << "/" << date.year;
	}
};

Date getCurrentTime() {
	time_t t = time(0);
	tm* now = localtime(&t);

	return {
		now->tm_mday,
		now->tm_mon + 1,
		now->tm_year + 1900,
	};
}

struct User {
	string lastName;
	string initials;
	long long phoneNumber;
	Date connectionDate;
	int tariffPrice;
	int balance;

	friend istream& operator>>(istream& in, User& user) {
		cout << "Enter Last Name: "; in >> user.lastName;
		cout << "Enter Initials: "; in >> user.initials;
		cout << "Enter Phone Number: "; in >> user.phoneNumber;
		cout << "Enter Connection Date: "; in >> user.connectionDate;
		cout << "Enter Tariff Price: "; in >> user.tariffPrice;
		cout << "Enter Balance: "; in >> user.balance;
		return in;
	}

	friend ostream& operator<<(ostream& out, const User& user) {
		return out << "Last Name: " << user.lastName
			<< "\nInitials: " << user.initials
			<< "\nPhone Number: " << user.phoneNumber
			<< "\nConnection Date: " << user.connectionDate
			<< "\nTariff Price: " << user.tariffPrice
			<< "\nBalance: " << user.balance;
	}
};

// enter and generate data
vector<User> generateVecUsers() {
	vector<User> vecUsers;

	int countUsers = 0 + rand() % 100;
	for (int i = 1; i <= countUsers; i++) {
		vecUsers.push_back({
			"LastNameTest" + to_string(i),
			"InitialsTest" + to_string(i),
			70000000000 + rand() % 30000000000,
			{
				1 + rand() % 30,
				1 + rand() % 13,
				2015 + rand() % 11,
			},
			0 + rand() % 1500,
			0 + rand() % 3000
			});
	}
	return vecUsers;
}

vector<User> enterVecUsers() {
	vector<User> vecUsers(12);
	for (auto& user : vecUsers) {
		cin >> user;
	}
	return vecUsers;
}


// sort
string toLower(const string& str) {
	string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), tolower);
	return lowerStr;
}

bool compareByLastName(const User& a, const User& b) {
	string lowerLastNameA = toLower(a.lastName);
	string lowerLastNameB = toLower(b.lastName);

	if (lowerLastNameA == lowerLastNameB) {
		return toLower(a.initials) < toLower(b.initials);
	}
	return lowerLastNameA < b.lastName;
}

void sortVecUsers(vector<User>& vecUsers) {
	stable_sort(vecUsers.begin(), vecUsers.end(), compareByLastName);
}


// functions
void addBonus(vector<User>& vecUsers) {
	Date currentDate = getCurrentTime();
	for (auto& user : vecUsers) {
		if ((currentDate.year - user.connectionDate.year) > 10) {
			user.balance += 200;
		}
	}
}

void monthlyDebit(vector<User>& vecUsers) {
	for (auto& user : vecUsers) {
		user.balance -= user.tariffPrice;
	}
}

void printUserWithNegativeBalance(vector<User>& vecUsers) {
	cout << "---------------------\n"
		<< "Usres with negative balance:\n";
	for (auto& user : vecUsers) {
		if (user.balance < 0) {
			cout << "----\n"
				<< user << endl;
		}
	}
	cout << "----\n"
		<< "---------------------" << endl;
}


void printUserWithCurrentPhineNUmber(vector<User>& vecUsers) {
	long long currentPhoneNumber = 0; cout << "Enter phone number: "; cin >> currentPhoneNumber;

	cout << "---------------------\n"
		<< "User with " << currentPhoneNumber << " phoe number:\n";
	for (auto& user : vecUsers) {
		if (user.phoneNumber == currentPhoneNumber) {
			cout << "----\n"
				<< user << endl;
		}
	}
	cout << "----\n"
		<< "---------------------" << endl;
}

// print
void printVecUsers(vector<User>& vecUsers) {
	cout << "---------------------\n"
		<< "All Usres:\n";
	for (const auto& user : vecUsers) {
		cout << "----\n"
			<< user << endl;
	}
	cout << "----\n"
		<< "---------------------" << endl;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<User> vecUsers{
		{
			"jsfjshjdf",
			"ANF",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"werwer",
			"aGH",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"brewr",
			"TYH",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"hjhgfjg",
			"NRF",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"iluqaa",
			"TH",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"artertet",
			"EDR",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"abc",
			"a",
			23452525,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
		{
			"aBc",
			"ab",
			23452526,
			{
				12,
				4,
				2020
			},
			500,
			0
		},
	};

	//vecUsers = enterVecUsers();
	//vecUsers = generateVecUsers();


	printVecUsers(vecUsers);

	sortVecUsers(vecUsers);
	printVecUsers(vecUsers);

	addBonus(vecUsers);
	printVecUsers(vecUsers);

	monthlyDebit(vecUsers);
	printUserWithNegativeBalance(vecUsers);

	printUserWithCurrentPhineNUmber(vecUsers);

	return 0;
}


//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct VinylRecord {
//	string executor;
//	string genre;
//	string albumName;
//	int circulation;
//
//	friend std::ostream& operator<<(std::ostream& out, const VinylRecord& vinylRecord) {
//		return out << "Executor: " << vinylRecord.executor
//			<< "\nGenre: " << vinylRecord.genre
//			<< "\nAlbumName: " << vinylRecord.albumName
//			<< "\nCirculation: " << vinylRecord.circulation;
//	}
//};
//
//void generateVinylRecord(vector<VinylRecord>& vecVinylRecords, int& countRecords) {
//	for (int i = 1; i <= countRecords; i++) {
//		vecVinylRecords.push_back({
//			"ExecutorTest" + to_string(i),
//			"GenreTest" + to_string(i),
//			"AlbumNameTest" + to_string(i),
//			1 + rand() % 20001
//			});
//	}
//}
//
//void printVecVinylRecords(vector<VinylRecord>& vecVinylRecords) {
//	for (const auto& vinylRecord : vecVinylRecords) {
//		cout << "----\n" << vinylRecord << endl;
//	}
//}
//
//void printVecVinylRecordsMoreTenThousand(vector<VinylRecord>& vecVinylRecords) {
//	for (auto& vinylRecord : vecVinylRecords) {
//		if (vinylRecord.circulation > 10000)
//			cout << "----\n" << vinylRecord << endl;
//	}
//}
//
//int main() {
//	srand(static_cast<unsigned int>(time(nullptr)));
//
//	vector<VinylRecord> vecVinylRecords;
//	int countRecord = 0; cout << "Enter count record: "; cin >> countRecord;
//
//	generateVinylRecord(vecVinylRecords, countRecord);
//	cout << "------------------------" << endl;
//	printVecVinylRecords(vecVinylRecords);
//	cout << "------------------------\n" << "VinylRecordsMoreTenThousand:" << endl;
//	printVecVinylRecordsMoreTenThousand(vecVinylRecords);
//}

//#include <functional>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct VinylRecord {
//	string executor;
//	string genre;
//	string albumName;
//	int circulation;
//
//	friend std::ostream& operator<<(std::ostream& out, const VinylRecord& vinylRecord) {
//		return out << "Executor: " << vinylRecord.executor
//			<< "\nGenre: " << vinylRecord.genre
//			<< "\nAlbumName: " << vinylRecord.albumName
//			<< "\nCirculation: " << vinylRecord.circulation;
//	}
//};
//
//VinylRecord generateVinylRecord(int i) {
//	return {
//		"TestExecutor" + to_string(i+1),
//		"TestGenre" + to_string(i + 1),
//		"TestAlbumName" + to_string(i + 1),
//		1 + rand() % 100000
//	};
//}
//
//void generateVecVinylRecord(vector<VinylRecord>& vecVinylRecords, int countRecords) {
//	vecVinylRecords.resize(countRecords);
//	int i = 0;
//	for (auto& vinylRecord : vecVinylRecords) {
//		vinylRecord = generateVinylRecord(i);
//		i++;
//	}
//}
//
//void printVecVinylRecord(vector<VinylRecord>& vecVinylRecords) {
//	for (auto& vinylRecord : vecVinylRecords) {
//		cout << "----\n"
//		<< vinylRecord << endl;
//	}
//}
//
//bool comparisonCirculation(const int& firstFiled, const int& secondFiled) {
//	return firstFiled > secondFiled;
//}
//
//bool comparisonGenre(const string& firstFiled, const string& secondFiled) {
//	return firstFiled == secondFiled;
//}
//
//template <class T>
//void printVinylRecordWithParameters(vector<VinylRecord>& vecVinylRecords, T VinylRecord::* field, const T& parameter, std::function<bool(const T&, const T&)> comparison) {
//	cout << "VinylRecords with " << parameter << endl;
//	for (const auto& vinylRecord : vecVinylRecords) {
//		if (comparison(vinylRecord.*field, parameter)) {
//			cout << "----\n" << vinylRecord << endl;
//		}
//	}
//}
//
//int main() {
//	srand(static_cast<unsigned int>(time(nullptr)));
//
//	vector<VinylRecord> vecVinylRecords;
//
//	int countRecords = 0; cout << "Enter count records: "; cin >> countRecords;
//	generateVecVinylRecord(vecVinylRecords, countRecords);
//
//	cout << "-----------------" << endl;
//	printVecVinylRecord(vecVinylRecords);
//	cout << "-----------------" << endl;
//	printVinylRecordWithParameters(vecVinylRecords, &VinylRecord::circulation, 10000, std::function<bool(const int&, const int&)>(comparisonCirculation));
//	cout << "-----------------" << endl;
//	printVinylRecordWithParameters(vecVinylRecords, &VinylRecord::genre, string("TestGenre1"), std::function<bool(const string&, const string&)>(comparisonGenre));
//	cout << "-----------------" << endl;
//}
