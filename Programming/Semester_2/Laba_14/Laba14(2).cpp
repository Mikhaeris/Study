#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

using namespace std;

vector<string> processLine(string str) {
	int countSentences = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
			countSentences++;
		}
	}

	//string* arrOfStringSentence = new string[countSentences];
	vector<string> arrOfStringSentence;

	int startIndex = 0;
	string tempStr;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.' || str[i] == '?' || str[i] == '!') {
			tempStr =
				countSentences++;
			arrOfStringSentence.push_back(tempStr);
		}
		tempStr.push_back(str[i]);
	}

	for (int i = 0; i < arrOfStringSentence.size(); i++) {
		cout << arrOfStringSentence[i] << endl;
	}

	return arrOfStringSentence;
}

void processFile(ifstream& inputFile, ofstream& outputFile) {
	string str;
	while (getline(inputFile, str))
	{
		cout << str << endl;

		vector<string> str1 = processLine(str);
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	if (!inputFile || !outputFile) {
		cout << "Error" << endl;

	}

	processFile(inputFile, outputFile);

	inputFile.close();
	outputFile.close();
	return 0;
}