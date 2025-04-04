#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

int main() {
	string str; cout << "Enter str: "; getline(cin, str);
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());

	//string str = "ACGTA";
	int strSize = str.size();

	int numberReps = 0; cout << "Enter numberReps: "; cin >> numberReps;

	map<string, int> mapSubString;

	int countCharacter = strSize; string tempStrS; int flag = false;
	while (countCharacter != 0) {
		for (int i = 0; i < strSize; i++) {

			if (i + countCharacter > strSize) continue;

			char* tempStr = new char[countCharacter + 1];
			str.copy(tempStr, countCharacter, i);
			tempStrS = string(tempStr, countCharacter);

			if (mapSubString.find(tempStrS) == mapSubString.end())
				mapSubString[tempStrS] = 1;
			else
				mapSubString[tempStrS] = mapSubString[tempStrS] + 1;

			if (mapSubString[tempStrS] == numberReps) {
				cout << tempStrS << endl;
				flag = true;
				break;
			}

			delete[] tempStr;
		}
		if (flag == true) break;
		countCharacter--;
	}

	if (!flag) cout << "Dont have" << endl;

	return 0;
}