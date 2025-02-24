#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void findSentence(ifstream fileInp) {
	auto start = fileInp.get();
	au
		while (fileInp) {
			if (static_cast<char>(fileInp.get()) == '.' || '!' || '?') {

			}
		}

}

pair<int, char*> getInfSentence(ifstream fileInp, start, finish) {
	int lenStr = 0;
	char* startSentence = 0
		for (int i = 0; ; ) {
			if ()
		}

	char* sentence = new char[lenStr];
	for (int i = ''; i < lenStr; i++) {

	}
	return pair<int, char*>();
}

void putSentence(ofstream fileOut, char* sentence, int len) {
	for (int i = 0; i < len; i++) {
		fileOut.put(sentence[i]);
	}
}

int main() {
	ifstream fileInp("input.txt", ios::in);
	ofstream fileOut("otput.txt", ios::out);

	if (!fileInp) {
		cout << "Error file!" << endl;
		return 1;
	}

	string line;
	while (getline(fileInp, line)) {
		std::cout << line << std::endl;
	}
	fileInp.close();

	return 0;
}