#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

int main() {
	string str; cout << "Enter str: "; getline(cin, str);
	//string str = "ACGTA";
	int strSize = str.size();

	map<string, int> mapSubString;

	int countCharacter = 1; string tempStrS;
	while (countCharacter != strSize + 1) {
		for (int i = 0; i < strSize; i++) {

			if (i + countCharacter > strSize) continue;

			char* tempStr = new char[countCharacter + 1];
			str.copy(tempStr, countCharacter, i);
			tempStrS = string(tempStr, countCharacter);

			if (mapSubString.find(tempStrS) == mapSubString.end())
				mapSubString[tempStrS] = 1;
			else
				mapSubString[tempStrS] = mapSubString[tempStrS] + 1;

			delete[] tempStr;
		}
		countCharacter++;
	}

	int numberReps = 0; cout << "Enter numberReps: "; cin >> numberReps;

	string bestSubStr = "";
	for (const auto& elem : mapSubString) {
		if (elem.second == numberReps) {
			if (bestSubStr.size() < elem.first.size()) {
				bestSubStr = elem.first;
			}
		}
	}

	if (!bestSubStr.empty()) cout << bestSubStr << endl;
	else cout << "That's not" << endl;

	return 0;
}