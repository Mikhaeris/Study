//#include <utility>
//#include <cstring>
//#include <iostream>
//
//using namespace std;
//
//pair<int, int> numCharactersBeforeAndAfter(char* str) {
//	int numCharacterBefore = 0, numCharacterAfter = 0;
//	int sizeStr = strlen(str);
//
//	bool tempCharacterInStr = false;
//	for (int i = 0; i < sizeStr; i++) {
//		if (str[i] == '$') {
//			tempCharacterInStr = true;
//			break;
//		}
//		numCharacterBefore++;
//		//cout << "C: " << numCharacterBefore << "str[i]: " << str[i]  << i << endl;
//	}
//
//	numCharacterAfter = sizeStr - numCharacterBefore - 1;
//	//cout << numCharacterBefore << " " << numCharacterAfter << " " << sizeStr << endl;
//	
//	return tempCharacterInStr ? pair<int, int>(numCharacterBefore, numCharacterAfter) : pair<int, int>(0,0);
//}
//
//int main() {
//	int sizeStr = 0;
//	cout << "Enter size str: ";  cin >> sizeStr;
//
//	char* str = new char[sizeStr+1];
//	cout << "Enter str this $: "; cin >> str;
//
//	auto answer = numCharactersBeforeAndAfter(str);
//	cout << "Before: " << answer.first << "\nAfter: " << answer.second << endl;
//	delete[] str;
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//char* substringBetweenSpaces(char* str) {
//
//	char* firstSpace = strchr(str, ' ');
//	char* secondSpace = strchr(firstSpace + 1, ' ');
//
//	if (secondSpace != nullptr) {
//		int numCharactersBetweenSpaces = secondSpace - firstSpace - 1;
//
//		char* strBetweenSpaces = new char[numCharactersBetweenSpaces + 1];
//
//		memcpy(strBetweenSpaces, firstSpace + 1, numCharactersBetweenSpaces);
//		strBetweenSpaces[numCharactersBetweenSpaces] = '\0';
//
//		return strBetweenSpaces;
//	}
//	else {
//		char* emptyStr = nullptr;
//		return emptyStr;
//	}	
//}
//
//int main() {
//	int sizeStr = 0;
//
//	cout << "Enter size str:"; cin >> sizeStr;
//	cin.ignore();
//	sizeStr++;
//
//	char* str = new char[sizeStr];
//	cout << "Enter str this space: "; cin.getline(str, sizeStr);
//
//	char* strBetweenSpaces = substringBetweenSpaces(str);
//	cout << "Word between spaces: " << strBetweenSpaces << endl;
//	
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//bool checkEndOfWord(char character) {
//	return (character == ' ' || character == '\0' || character == '.' || character == ',') ? true : false;
//}
//
//char* findLongestWord(char* str) {
//	int maxLen = 0, currentLen = 0;
//	char* startMax = &str[0];
//	char* finishMax = &str[0];
//	char* currentStart = &str[0];
//
//	int len = strlen(str) + 1;
//	for (int i = 0; i < len; i++) {
//		if (checkEndOfWord(str[i])) {
//			if (currentLen > maxLen) {
//				maxLen = currentLen;
//
//				startMax = currentStart;
//				finishMax = &str[i];
//			}
//			currentLen = 0;
//			currentStart = &str[i + 1];
//		}
//		else {
//			currentLen++;
//		}
//	}
//	char* longestWord = new char[maxLen + 1];
//
//	memcpy(longestWord, startMax, maxLen);
//	longestWord[maxLen] = '\0';
//	return longestWord;
//}
//
//int main() {
//	int sizeStr = 0;
//	cout << "Enter size str: "; cin >> sizeStr;
//	cin.ignore();
//
//	char* str = new char[sizeStr + 1];
//	cout << "Enter sentence: "; cin.getline(str, sizeStr + 1);
//
//	char* longestWord = findLongestWord(str);
//	cout << "The longest word in sentence: " << longestWord << endl;
//
//	delete[] str;
//	delete[] longestWord;
//	return 0;
//}