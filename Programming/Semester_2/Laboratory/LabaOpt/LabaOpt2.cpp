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


//ThirdTask
//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct Matrix {
//	vector<vector<int>> vecMatrix;
//};
//
//void putMatrixInFile(fstream& outFileMatrix, vector<Matrix>& vecMatrix, int countMatrix) {
//	for (int i = vecMatrix.size() - countMatrix; i < vecMatrix.size(); i++) {
//		for (int j = 0; j < vecMatrix[i].vecMatrix.size(); j++) {
//			for (int k = 0; k < vecMatrix[i].vecMatrix[j].size(); k++) {
//				outFileMatrix << vecMatrix[i].vecMatrix[j][k] << " ";
//			}
//			outFileMatrix << "\n";
//		}
//		outFileMatrix << "\n";
//	}
//}
//
//void getAllMatrixFromFile(fstream& inFileMatrix, vector<Matrix>& vecMatrix) {
//	Matrix tempMatrix; string line;
//	while (getline(inFileMatrix, line)) {
//
//		if (line == "") {
//			vecMatrix.push_back(tempMatrix);
//			tempMatrix.vecMatrix = {};
//			continue;
//		}
//
//		vector<int> matrixRow;
//		string number; int countNumber = 0;
//		for (auto& character : line) {
//
//			if (character != ' ') {
//				number.push_back(character);
//			}
//			else {
//				matrixRow.push_back(stoi(number));
//				number = ""; countNumber++;
//			}
//		}
//		tempMatrix.vecMatrix.push_back(matrixRow);
//	}
//	vecMatrix.push_back(tempMatrix);
//}
//
//void deleteMatrixInFile(string filename, vector<Matrix>& vecMatrix, int countMatrix) {
//	ofstream outFileMatrix(filename, std::ios::trunc); int tempCount = 0;
//	for (auto& matrix : vecMatrix) {
//		for (int i = 0; i < matrix.vecMatrix.size(); i++) {
//			for (int j = 0; j < matrix.vecMatrix[i].size(); j++) {
//				outFileMatrix << matrix.vecMatrix[i][j] << " ";
//			}
//			outFileMatrix << '\n';
//		}
//		outFileMatrix << '\n';
//		tempCount++;
//		if (vecMatrix.size() - countMatrix == tempCount)
//			break;
//	}
//	outFileMatrix.close();
//}
//
//void printFile(string filename) {
//	ifstream inFileMatrix(filename);
//	string line;
//	while (getline(inFileMatrix, line)) {
//		cout << line << endl;
//	}
//	inFileMatrix.close();
//}
//
//int main() {
//	cout << "Start:" << endl;
//	cout << "File1:" << endl;
//	printFile("file1Matrix.txt");
//	cout << "--------------" << endl;
//	cout << "File2:" << endl;
//	printFile("file2Matrix.txt");
//	cout << "--------------" << endl;
//	cout << "File3:" << endl;
//	printFile("file3Matrix.txt");
//	cout << "--------------" << endl;
//	cout << "--------------" << endl;
//
//	fstream inFile1Matrix("file1Matrix.txt");
//	if (!inFile1Matrix) return 1;
//	vector<Matrix> vec1Matrix;
//	getAllMatrixFromFile(inFile1Matrix, vec1Matrix);
//	inFile1Matrix.close();
//
//	fstream inFile2Matrix("file2Matrix.txt");
//	if (!inFile2Matrix) return 1;
//	vector<Matrix> vec2Matrix;
//	getAllMatrixFromFile(inFile2Matrix, vec2Matrix);
//	inFile2Matrix.close();
//
//	fstream inFile3Matrix("file3Matrix.txt");
//	if (!inFile3Matrix) return 1;
//
//	if (vec1Matrix.size() > vec2Matrix.size()) {
//		deleteMatrixInFile("file1Matrix.txt", vec1Matrix, vec1Matrix.size() - vec2Matrix.size());
//		putMatrixInFile(inFile3Matrix, vec1Matrix, vec1Matrix.size() - vec2Matrix.size());
//	}
//	else {
//		deleteMatrixInFile("file2Matrix.txt", vec2Matrix, vec2Matrix.size() - vec1Matrix.size());
//		putMatrixInFile(inFile3Matrix, vec2Matrix, vec2Matrix.size() - vec1Matrix.size());
//	}
//	inFile3Matrix.close();
//
//	cout << "End:" << endl;
//	cout << "File1:" << endl;
//	printFile("file1Matrix.txt");
//	cout << "--------------" << endl;
//	cout << "File2:" << endl;
//	printFile("file2Matrix.txt");
//	cout << "--------------" << endl;
//	cout << "File3:" << endl;
//	printFile("file3Matrix.txt");
//	cout << "--------------" << endl;
//}