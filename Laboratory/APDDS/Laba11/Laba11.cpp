#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> characterNumber;

void addInVec(vector<vector<int>>& repeatingCharactersInf, char tempCharacter, int countTempCharacter) {
	int numberCharacterInMap = characterNumber[tempCharacter];
	if (repeatingCharactersInf[numberCharacterInMap].size() >= countTempCharacter) {
		repeatingCharactersInf[numberCharacterInMap][countTempCharacter - 1] += 1;
	}
	else if (repeatingCharactersInf[numberCharacterInMap].size() < countTempCharacter) {
		vector<int> tempVec = { 0, 0, 0, 0 };
		for (int i = repeatingCharactersInf.size(); i < countTempCharacter; i++) {
			repeatingCharactersInf.push_back(tempVec);
		}
		repeatingCharactersInf[numberCharacterInMap][countTempCharacter - 1] += 1;
	}
}

pair<char, int> goNextSpace(string& str, int index) {
	for (int i = index; i < str.size() - 1; i++) {
		if (str[i + 1] != ' ') {
			return pair<char, int>(str[i], i);
		}
	}
}

void countCharacters(vector<vector<int>>& repeatingCharactersInf, string& str) {
	char tempCharacter = str[0]; int countTempCharacter = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i + 1] != tempCharacter) {
			addInVec(repeatingCharactersInf, tempCharacter, countTempCharacter);
			if (str[i + 1] != ' ') {
				tempCharacter = str[i + 1];
			}
			else {
				auto infCharacterAndCountSpace = goNextSpace(str, i + 1);
				tempCharacter = infCharacterAndCountSpace.first;
				i = infCharacterAndCountSpace.second;
			}
			countTempCharacter = 0;
		}
		countTempCharacter++;
	}
}

int main() {
	characterNumber.insert(make_pair('A', 0));
	characterNumber.insert(make_pair('C', 1));
	characterNumber.insert(make_pair('G', 2));
	characterNumber.insert(make_pair('T', 3));

	vector<vector<int>> repeatingCharactersInf;

	string str; cout << "Enter str: "; cin.ignore(); getline(cin, str);
	int n = 0; cout << "Enter n: "; cin >> n;

	countCharacters(repeatingCharactersInf, str);

	for (int i = n; i < repeatingCharactersInf[n].size(); i++) {
		if (repeatingCharactersInf[n][i] == n) {
			cout << repeatingCharactersInf[n][i] << endl;
		}
	}
}