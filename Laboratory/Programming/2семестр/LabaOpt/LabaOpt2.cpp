// FirstVersionOfSecondTask
//#include <fstream>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void goToPrevPosition(ifstream& fileF) {
//	fileF.seekg(static_cast<int>(fileF.tellg()) - 1);
//}
//
//void skipSpaces(ifstream& fileF) {
//	char character = ' ';
//	while (character == ' ') {
//		character = fileF.get();
//	}
//
//	goToPrevPosition(fileF);
//}
//
//int getNumber(ifstream& fileF) {
//	string number = "N";
//	while (number.back() != ' ' && !fileF.eof())
//		number.push_back(fileF.get());
//
//	if (!fileF.eof()) goToPrevPosition(fileF);
//
//	number.erase(number.begin());
//	if (number[0] == '-') number.erase(number.begin());
//	number.pop_back();
//	return stoi(number);
//}
//
//int findMaxModuleNumberInOddPosition(ifstream& fileF) {
//	int number = 0, maxNumber = 0;
//	for (int i = 0; !fileF.eof(); i++) {
//		number = getNumber(fileF);
//		if ((i % 2 != 0) && (number > maxNumber))
//			maxNumber = number;
//
//		if (fileF.eof()) break;
//		skipSpaces(fileF);
//	}
//	return maxNumber;
//}
//
//int main() {
//	ifstream fileF("fileF.txt");
//
//	if (!fileF) return 1;
//
//	cout << "MaxNumber in Odd Position in module: "
//	<< findMaxModuleNumberInOddPosition(fileF) << endl;
//
//	return 0;
//}

//SecondVersionOfSecondTask
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <utility>
//
//using namespace std;
//
//pair<int, int> getNumber(string& line, int currentPosition) {
//	string numberPos; int indexPos = currentPosition, lineSize = line.size();
//	for (int i = currentPosition; i != lineSize && line[i] != ' '; i++) {
//		numberPos.push_back(line[i]);
//		indexPos++;
//	}
//
//	if (numberPos.front() == '-')
//		numberPos.erase(numberPos.begin());
//
//	return { stoi(numberPos), indexPos - 1 };
//}
//
//int processLine(string& line) {
//	static int currentIndex = 1;
//	int maxNumberLine = 0;
//
//	int lineSize = line.size();
//	for (int i = 0; i < lineSize; i++) {
//		if (line[i] != ' ') {
//			auto numberAndIndexLine = getNumber(line, i);
//			if ((currentIndex % 2 != 0) && (numberAndIndexLine.first > maxNumberLine))
//				maxNumberLine = numberAndIndexLine.first;
//			i = numberAndIndexLine.second;
//			currentIndex++;
//		}
//
//	}
//
//	return maxNumberLine;
//}
//
//int findMaxModuleNumberInOddPosition(ifstream& fileF) {
//	int maxNumber = 0, number = 0;
//
//	string line;
//	while (getline(fileF, line)) {
//		number = processLine(line);
//		if (number > maxNumber) {
//			maxNumber = number;
//		}
//	}
//
//	return maxNumber;
//}
//
//int main() {
//
//	ifstream fileF("fileF.txt");
//
//	if (!fileF) return 1;
//
//	cout << "MaxNumber in Odd Position in module: "
//		<< findMaxModuleNumberInOddPosition(fileF) << endl;
//
//	return 0;
//}


