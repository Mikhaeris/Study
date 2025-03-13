#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> characterNumber = { {'A',0}, {'C',1}, {'G',2}, {'T',3} };
map<int, char> characterNumberRev = { {0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'} };

void addInVec(vector<vector<int>>& repeatingCharactersInf, char tempCharacter, int countTempCharacter) {
	int numberCharacterInMap = characterNumber[tempCharacter];
	if (repeatingCharactersInf.size() >= countTempCharacter) {
		repeatingCharactersInf[countTempCharacter - 1][numberCharacterInMap] += 1;
	}
	else if (repeatingCharactersInf.size() < countTempCharacter) {
		vector<int> tempVec = { 0, 0, 0, 0 };
		for (int i = repeatingCharactersInf.size(); i < countTempCharacter; i++) {
			repeatingCharactersInf.push_back(tempVec);
		}
		repeatingCharactersInf[countTempCharacter - 1][numberCharacterInMap] += 1;
	}
}

pair<char, int> goNextSpace(string& str, int index) {
	for (int i = index; i < str.size() - 1; i++) {
		if (str[i + 1] != ' ') {
			return pair<char, int>(str[i + 1], i);
		}
	}
	return pair<char, int>(str[0], str.size());
}

void countCharacters(vector<vector<int>>& repeatingCharactersInf, string& str) {
	char tempCharacter = str[0]; int countTempCharacter = 0;
	for (int i = 0; i < str.size() - 1; i++) {
		countTempCharacter++;
		if (str[i + 1] != tempCharacter) {
			addInVec(repeatingCharactersInf, tempCharacter, countTempCharacter);
			if (str[i + 1] != ' ') {
				tempCharacter = str[i + 1];
			}
			else {
				auto infCharacterAndCountSpace = goNextSpace(str, i);
				tempCharacter = infCharacterAndCountSpace.first;
				i = infCharacterAndCountSpace.second;
			}
			countTempCharacter = 0;
		}
	}
}

int main() {
	vector<vector<int>> repeatingCharactersInf(0, vector<int>(4));

	string str; cout << "Enter str: "; getline(cin, str); str.push_back(' ');
	int n = 0; cout << "Enter n: "; cin >> n;

	countCharacters(repeatingCharactersInf, str);

	bool tempBreak = 0;
	for (int i = repeatingCharactersInf.size() - 1; i > 1; i--) {
		for (int j = 0; j < 4; j++) {
			if (repeatingCharactersInf[i][j] == n) {
				char character = characterNumberRev[j];
				for (int k = 0; k < i + 1; k++) {
					cout << character;
				}
				cout << endl;
				cout << "Count character: " << n << "\nWhat character(0-A...): " << character << "\nSize character: " << i + 1 << endl;
				tempBreak = 1;
				break;
			}
		}
		if (tempBreak == 1) {
			break;
		}
	}
}