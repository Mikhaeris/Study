#include <fstream>
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

int goToNextSentence(string str, int currentIndex) {
	currentIndex++;
	for (int i = currentIndex; i < str.size(); i++) {
		if (str[i] != ' ') {
			return i - 1;
		}
	}
	return str.size();
}

pair<string*, int> processLine(ifstream& inputFile, string line) {
	static string tempTail = " ";

	int countSentences = 0;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == '.' || line[i] == '?' || line[i] == '!' || line[i] == '\n') {
			countSentences++;
		}
	}

	string* sentences = new string[countSentences];

	string tempSentence = ""; int tempCountSentences = 0;
	for (int i = 0; i < line.size(); i++) {

		tempSentence.push_back(line[i]);
		if (line[i] == '.' || line[i] == '?' || line[i] == '!') {
			if (tempTail != " ") {
				tempTail += tempSentence;
				tempSentence = tempTail;
				sentences[tempCountSentences] = tempTail;
				tempTail = " ";
			}
			else {
				sentences[tempCountSentences] = tempSentence;
			}
			tempSentence = "";
			tempCountSentences++;
			i = goToNextSentence(line, i);
		}

		if (i == line.size() - 1) {
			tempTail = tempSentence;
		}
	}

	return pair<string*, int>(sentences, countSentences);
}

void putSentence(ofstream& outputFile, string str, char punctuationMark) {
	if (str.back() == punctuationMark) {
		outputFile << str;
		outputFile << ' ';
	}
}

void processFile(ifstream& inputFile, ofstream& outputFile, char punctuationMark) {
	string line;
	while (getline(inputFile, line)) {
		auto answerFunc = processLine(inputFile, line);
		string* arrSentence = answerFunc.first;
		int sizeArrSentence = answerFunc.second;

		for (int i = 0; i < sizeArrSentence; i++) {
			putSentence(outputFile, arrSentence[i], punctuationMark);
		}
	}
	outputFile << '\n';

	delete answerFunc;
	delete[] arrSentence;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	if (!inputFile || !outputFile) {
		cout << "Error" << endl;
		return 1;
	}
	else {
		cout << "Good" << endl;
	}

	processFile(inputFile, outputFile, '?');
	inputFile.clear();
	inputFile.seekg(0);

	processFile(inputFile, outputFile, '!');

	inputFile.close();
	outputFile.close();
	return 0;
}